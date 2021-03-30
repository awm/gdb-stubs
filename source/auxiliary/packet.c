/**
 *  @file       packet.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Formatting and parsing routines for GDB packets.
 */
#include "packet.h"

#include "gdbstub.h"

#include "auxiliary/binary.h"
#include "auxiliary/checksum.h"
#include "auxiliary/hex.h"
#include "stdc/assert.h"
#include "stdc/null.h"

/// Value indicating no prefix character on a pushed packet.
#define NO_PREFIX '\0'

/**
 * Infer packet type from the lead character.
 *
 * @retval >=0  The enum packet_type value.
 * @retval <0   Character does not match a packet type.
 */
static int to_type
(
    unsigned char lead_character ///< Lead character of the packet.
)
{
    switch (lead_character)
    {
        case DATA_PACKET_START_CHAR:
            return PT_MESSAGE;
        case NOTIFICATION_PACKET_START_CHAR:
            return PT_NOTIFICATION;
        case ACK_CHAR:
        case NACK_CHAR:
            return PT_ACK;
        default:
            return -1;
    }
}

/**
 * Decode the checksum from the end of a packet.
 *
 * @retval  0 Checksum extracted.
 * @retval <0 Extraction failed.  The exact value will be a negative enum gdbs_error entry
 *            indicating what went wrong.
 */
static int extract_packet_checksum
(
    const unsigned char *packet,  ///< [in]  Packet data.
    unsigned long        length,  ///< [in]  Packet length.
    unsigned char       *checksum ///< [out] Decoded checksum.
)
{
    char checksum_string[3];

    assert(checksum != NULL);
    assert(length > 3);
    assert(packet != NULL);

    if (packet[length - 3] != PAYLOAD_END_CHAR)
    {
        return -GDBS_ERROR_INVALID;
    }
    checksum_string[0] = packet[length - 2];
    checksum_string[1] = packet[length - 1];
    checksum_string[2] = '\0';

    return hex_octet_to_byte(checksum_string, checksum);
}

/**
 * Verify the integrity of a buffered message or notification packet, ensuring that it has the
 * correct formatting and checksum.
 *
 * @retval  0 Packet is valid.
 * @retval <0 Packet is invalid.  The exact value will be a negative enum gdbs_error entry
 *            indicating what went wrong.
 */
static int verify
(
    const unsigned char *packet, ///< Packet data.
    unsigned long        length  ///< Length of packet data.
)
{
    int             result;
    unsigned char   checksum;
    unsigned char   expected_checksum = 0;

    assert(packet != NULL);
    if (length < 4)
    {
        // A non-ack packet must have at least 4 characters (type, #, and checksum digits).
        result = -GDBS_ERROR_INVALID;
        goto end;
    }

    result = extract_packet_checksum(packet, length, &expected_checksum);
    if (result != GDBS_ERROR_OK)
    {
        goto end;
    }

    checksum = calculate_checksum(&packet[1], length - 4);
    if (checksum != expected_checksum)
    {
        result = -GDBS_ERROR_CHECKSUM;
        goto end;
    }

end:
    return result;
}

/**
 * Receive a complete packet from a data source.  This function will block until a verified packet
 * of the indicated type is received.
 *
 * @retval 0    A valid packet has been received into the buffer.
 * @retval <0   An error occured while receiving.  The exact value will be a negative
 *              enum gdbs_error entry indicating what went wrong.
 */
int packet_receive
(
    unsigned char           *buffer,        ///< [out]    Buffer into which to receive packet data.
    unsigned long           *length,        ///< [in,out] Size of the buffer as input, length of the
                                            ///<          packet as output.
    enum packet_type         expected_type, ///< [in]     Type of packet expected.
    packet_source_function   source,        ///< [in]     Callback to invoke to read in a byte of
                                            ///<          data.
    void                    *param          ///< [in]     Arbitrary data to pass to the source
                                            ///<          callback.
)
{
    enum packet_state
    {
        PREFIX,
        BODY,
        SUFFIX,
        DONE
    };

    enum packet_state   state = PREFIX;
    int                 received;
    unsigned long       i;
    unsigned long       remaining = *length;

    for (i = 0; i < *length; ++i)
    {
        received = source(param);
        if (received < 0)
        {
            return received;
        }
        buffer[i] = (unsigned char) received;

        if (state == PREFIX && to_type(buffer[i]) == (int) expected_type)
        {
            if (expected_type == PT_ACK)
            {
                state = DONE;
                break;
            }
            else
            {
                state = BODY;
            }
        }
        else if (state == BODY                  &&
                 buffer[i] == PAYLOAD_END_CHAR  &&
                 buffer[i - 1] != BINARY_ESCAPE_CHAR)
        {
            state = SUFFIX;
            remaining = 2; // Two hex digits remain for the checksum.
        }
        else if (state == SUFFIX)
        {
            if (--remaining == 0)
            {
                state = DONE;
                break;
            }
        }
    }

    if (state == DONE)
    {
        *length = i + 1;
        return (expected_type == PT_ACK ? GDBS_ERROR_OK : verify(buffer, *length));
    }
    else
    {
        return -GDBS_ERROR_EOB;
    }
}

/**
 * Initialize a tokenizer instance to process a buffered packet.
 */
void packet_tokenizer_init
(
    struct packet_tokenizer *tokenizer, ///< [out] Tokenizer instance to initialize.
    const unsigned char     *packet,    ///< [in]  Packet data.
    unsigned long            length     ///< [in]  Length of packet data.
)
{
    assert(length > 0);
    assert(packet != NULL);
    assert(tokenizer != NULL);

    tokenizer->packet = packet;
    tokenizer->start = tokenizer->packet;
    tokenizer->end = tokenizer->packet;

    if (to_type(packet[0]) == PT_ACK)
    {
        tokenizer->length = length;
        tokenizer->skip = 0;
    }
    else
    {
        // For non-ack packets, exclude the final # and checksum from the considered data.
        tokenizer->length = length - 3;

        // For non-ack packets, skip the start of packet character.
        tokenizer->skip = 1;
    }

    assert(tokenizer->start >= tokenizer->packet);
    assert(tokenizer->end >= tokenizer->start);
    assert(tokenizer->end <= tokenizer->packet + tokenizer->length);

    tokenizer->prev_start = tokenizer->start;
    tokenizer->prev_end = tokenizer->end;
    tokenizer->prev_skip = tokenizer->skip;
}

/**
 * Advance to the next token in the packet.  The end of the token is determined by the delimiter
 * character or the end of the packet data, whichever comes first.  The tokenizer is aware of the
 * binary encoding format escape sequences in order to avoid accidentally recognizing escaped
 * delimiters, however it does not translate these sequences in the returned token.
 *
 * @retval 0                     Next token is available.
 * @retval -GDBS_ERROR_EOB       The end of the packet buffer has been reached.
 * @retval -GDBS_ERROR_NOT_FOUND Delimiter was not found.  Returned token is the remainder of the
 *                               packet.
 */
int packet_tokenizer_advance
(
    struct packet_tokenizer *tokenizer, ///< [in]  Tokenizer instance.
    int                      delimiter, ///< [in]  Delimiter character for next token. Cannot be
                                        ///<       BINARY_ESCAPE_CHAR.  Set to TOKEN_SINGLE_CHAR to
                                        ///<       retrieve a single character token.  Set to
                                        ///<       TOKEN_EOB to indicate that the end of the buffer
                                        ///<       should be considered the next delimiter.
    const unsigned char     **token,    ///< [out] Pointer to start of token in the packet buffer.
    unsigned long            *length    ///< [out] Length of the token.
)
{
    int escaped;

    assert(tokenizer != NULL);
    assert(token != NULL);
    assert(length != NULL);
    assert(tokenizer->packet != NULL);
    assert(tokenizer->length > 0);
    assert(delimiter != BINARY_ESCAPE_CHAR);

    // Record where we are for potential rewind call.
    tokenizer->prev_start = tokenizer->start;
    tokenizer->prev_end = tokenizer->end;
    tokenizer->prev_skip = tokenizer->skip;

    // Skip a previous delimiter, if any.
    tokenizer->end += tokenizer->skip;
    tokenizer->skip = 0;

    for (tokenizer->start = tokenizer->end;
         tokenizer->end < tokenizer->packet + tokenizer->length;
         ++tokenizer->end)
    {
        if (escaped)
        {
            escaped = 0;
        }
        else if (*tokenizer->end == BINARY_ESCAPE_CHAR)
        {
            // Skip over escape sequences.
            escaped = 1;
        }
        else if (*tokenizer->end == delimiter)
        {
            // Make sure we move past this delimiter for the next token.
            tokenizer->skip = 1;
            break;
        }
        else if (delimiter == TOKEN_SINGLE_CHAR && tokenizer->end == tokenizer->start + 1)
        {
            break;
        }
    }

    assert(tokenizer->start >= tokenizer->packet);
    assert(tokenizer->end >= tokenizer->start);
    assert(tokenizer->end <= tokenizer->packet + tokenizer->length);

    *token = tokenizer->start;
    *length = tokenizer->end - tokenizer->start;

    if (tokenizer->end == tokenizer->prev_end)
    {
        // Didn't advance at all, which can only happen if we are at the end of the packet.
        return -GDBS_ERROR_EOB;
    }
    else if (delimiter != TOKEN_SINGLE_CHAR &&
             tokenizer->end == tokenizer->packet + tokenizer->length)
    {
        // Advanced, but hit the end of the string without finding a delimiter.
        return (delimiter == TOKEN_EOB ? GDBS_ERROR_OK : -GDBS_ERROR_NOT_FOUND);
    }
    else
    {
        // Found a delimited token.
        return GDBS_ERROR_OK;
    }
}

/**
 * Rewind the tokenizer by one item.  Only the last advance can be rewound.  This enables
 * inexpensive probing of the packet using different delimiters.
 */
void packet_tokenizer_rewind
(
    struct packet_tokenizer *tokenizer ///< Tokenizer instance.
)
{
    assert(tokenizer != NULL);
    assert(tokenizer->packet != NULL);
    assert(tokenizer->length > 0);

    // Revert back to the previous token.
    tokenizer->start = tokenizer->prev_start;
    tokenizer->end = tokenizer->prev_end;
    tokenizer->skip = tokenizer->prev_skip;
}

/**
 * Initialize a packet writer for handling the sending of packet data.  Data is only sent when the
 * packet_writer_push\* or packet_writer_finish functions are called.
 */
void packet_writer_init
(
    struct packet_writer    *packet, ///< [out] Packet writer instance to initialize.
    enum packet_type         type,   ///< [in]  Packet type to be sent.
    packet_sink_function     sink,   ///< [in]  Callback to invoke to send packet data.
    void                    *param   ///< [in]  Optional parameter to pass to the sink function.
)
{
    assert(packet != NULL);
    assert(sink != NULL);

    packet->type = type;
    packet->sink = sink;
    packet->param = param;
    packet->checksum = 0;
    packet->finished = 0;

    if (packet->type == PT_MESSAGE)
    {
        packet->buffer[0] = DATA_PACKET_START_CHAR;
        packet->buffered = 1;
    }
    else if (packet->type == PT_NOTIFICATION)
    {
        packet->buffer[0] = NOTIFICATION_PACKET_START_CHAR;
        packet->buffered = 1;
    }
    else
    {
        packet->buffered = 0;
    }
}

/**
 * Push an ack packet.  Only valid for ack type packets.  Once this function succeeds no further
 * data may be sent and packet_writer_finish should be called.
 *
 * @retval 0    Ack successfully written.
 * @retval <0   Sending failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
int packet_writer_push_ack
(
    struct packet_writer *packet ///< Packet writer instance.
)
{
    int result;

    assert(packet != NULL);
    assert(packet->type == PT_ACK);
    assert(packet->sink != NULL);
    assert(!packet->finished);

    result = packet->sink(ACK_CHAR, packet->param);
    if (result == GDBS_ERROR_OK)
    {
        packet->finished = 1;
    }
    return result;
}

/**
 * Push a negative ack packet.  Only valid for ack type packets.  Once this function succeeds no
 * further data may be sent and packet_writer_finish should be called.
 *
 * @retval 0    Nack successfully written.
 * @retval <0   Sending failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
int packet_writer_push_nack
(
    struct packet_writer *packet ///< Packet writer instance.
)
{
    int result;

    assert(packet != NULL);
    assert(packet->type == PT_ACK);
    assert(packet->sink != NULL);
    assert(!packet->finished);

    result = packet->sink(NACK_CHAR, packet->param);
    if (result == GDBS_ERROR_OK)
    {
        packet->finished = 1;
    }
    return result;
}

/**
 * Flush the internal buffer out via the sink function.
 *
 * @retval 0    Buffered data written successfully.
 * @retval <0   Sending failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
static int sink_buffered_data
(
    struct packet_writer *packet ///< Packet writer instance.
)
{
    int result = GDBS_ERROR_OK;

    while (packet->buffered > 0)
    {
        result = packet->sink(packet->buffer[0], packet->param);
        if (result != GDBS_ERROR_OK)
        {
            break;
        }

        // Shuffle the items along in the buffer.  Since the buffer is so small it doesn't
        // really make sense to do anything more complicated than shift the bytes down.
        packet->buffer[0] = packet->buffer[1];
        packet->buffer[1] = packet->buffer[2];
        packet->buffer[2] = packet->buffer[3];
        --packet->buffered;
    }

    return result;
}

/**
 * Push a byte to the packet payload.  Only applicable for non-ack type packets.
 *
 * @retval 0    Byte successfully written.
 * @retval <0   Sending failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
int packet_writer_push
(
    struct packet_writer *packet, ///< Packet writer instance.
    unsigned char         byte    ///< Byte to write out.
)
{
    int result;

    assert(packet != NULL);
    assert(packet->type != PT_ACK);
    assert(packet->sink != NULL);
    assert(!packet->finished);

    result = sink_buffered_data(packet);
    if (result == GDBS_ERROR_OK)
    {
        result = packet->sink(byte, packet->param);
        if (result == GDBS_ERROR_OK)
        {
            accumulate_checksum(&packet->checksum, byte);
        }
    }

    return result;
}

/**
 * Finish writing out a packet.
 *
 * @retval 0    Packet completely written out successfully.
 * @retval <0   Sending failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
int packet_writer_finish
(
    struct packet_writer *packet ///< Packet writer instance.
)
{
    int result;

    assert(packet != NULL);
    assert(packet->sink != NULL);

    if (packet->type == PT_ACK)
    {
        assert(packet->finished);
        return GDBS_ERROR_OK;
    }

    result = sink_buffered_data(packet);
    if (result == GDBS_ERROR_OK && !packet->finished)
    {
        packet->buffer[0] = PAYLOAD_END_CHAR;
        byte_to_hex_octet(packet->checksum, (char *) &packet->buffer[1]);
        packet->buffered = 3;
        packet->finished = 1;
        result = sink_buffered_data(packet);
    }

    return result;
}
