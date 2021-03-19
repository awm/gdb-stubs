/**
 *  @file       packet.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Formatting and parsing routines for GDB packets.
 */
#ifndef PACKET_H_
#define PACKET_H_

#define DATA_PACKET_START_CHAR          '$' ///< Character indicating start of a data packet.
#define NOTIFICATION_PACKET_START_CHAR  '%' ///< Character indicating start of a notification.
#define PAYLOAD_END_CHAR                '#' ///< Character indicating end of packet payload and
                                            ///< start of checksum field.
#define ACK_CHAR                        '+' ///< Acknowledgement character.
#define NACK_CHAR                       '-' ///< Negative acknowledgement character.

/// Delimiter value used to indicate that the next packet token should be a single character.
#define TOKEN_SINGLE_CHAR -1
/// Delimiter value used to indicate that the next packet token should be delimited by the end of
/// the buffer.
#define TOKEN_EOB         -2

/// Major packet types.
enum packet_type
{
    PT_MESSAGE,      ///< A command received from GDB, or a synchronous response sent to GDB.
    PT_NOTIFICATION, ///< An asynchronous notification sent to GDB.
    PT_ACK           ///< An ack or nack to a previous packet, sent in either direction.
};

/// Packet tokenizer state.
struct packet_tokenizer
{
    const unsigned char *packet;        ///< Packet data.
    unsigned long        length;        ///< Length of packet data.

    const unsigned char *start;         ///< Start of current token.
    const unsigned char *end;           ///< Character after the end of the current token.
    unsigned long        skip;          ///< Number of characters to skip before searching for the
                                        ///< next delimiter.

    const unsigned char *prev_start;    ///< Start of previous token.
    const unsigned char *prev_end;      ///< Character after the end of the previous token.
    unsigned long        prev_skip;     ///< Number of characters to skip before searching for the
                                        ///< previous delimiter.
};

/**
 * Callback type for writing packet data out.
 *
 * @retval 0                    Byte successfully written.
 * @retval <0                   Sending failed.  The exact value will be a negative enum gdbs_error
 *                              entry indicating what went wrong.
 */
typedef int (*packet_sink_function)
(
    unsigned char    byte, ///< Byte to write out.
    void            *param ///< User parameter associated with the packet writer.
);

/// State container for packet assembly.
struct packet_writer
{
    enum packet_type         type;      ///< Packet type.
    unsigned char            buffer[4]; ///< Scratch buffer for packet data.
    unsigned long            buffered;  ///< Number of buffered bytes.
    unsigned char            checksum;  ///< Running checksum of packet payload.
    int                      finished;  ///< Boolean flag indicating remaining bytes are buffered.

    packet_sink_function     sink;      ///< Function to call to output packet bytes.
    void                    *param;     ///< Arbitrary parameter for sink function.
};

/**
 * Callback type for reading in packet data.  This function will block until a byte is received.
 *
 * @retval >=0  Received data byte.
 * @retval <0   Receive failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
typedef int (*packet_source_function)
(
    void *param ///< User parameter associated provided to the packet_receive call.
);

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
);

/**
 * Initialize a tokenizer instance to process a buffered packet.
 */
void packet_tokenizer_init
(
    struct packet_tokenizer *tokenizer, ///< [out] Tokenizer instance to initialize.
    const unsigned char     *packet,    ///< [in]  Packet data.
    unsigned long            length     ///< [in]  Length of packet data.
);

/**
 * Advance to the next token in the packet.  The end of the token is determined by the delimiter
 * character or the end of the packet data, whichever comes first.  The tokenizer is aware of the
 * binary encoding format escape sequences in order to avoid accidentally recognizing escaped
 * delimiters, however it does not translate these sequences in the returned token.
 *
 * @retval 0                Next token is available.
 * @retval -GDBS_ERROR_EOB  The end of the packet buffer has been reached.
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
);

/**
 * Rewind the tokenizer by one item.  Only the last advance can be rewound.
 */
void packet_tokenizer_rewind
(
    struct packet_tokenizer *tokenizer ///< Tokenizer instance.
);

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
);

/**
 * Push an ack packet.  Only valid for ack type packets.  Once this function succeeds no further
 * data may be sent and packet_writer_finish should be called.
 *
 * @retval 0                    Ack successfully written.
 * @retval <0                   Sending failed.  The exact value will be a negative enum gdbs_error
 *                              entry indicating what went wrong.
 */
int packet_writer_push_ack
(
    struct packet_writer *packet ///< Packet writer instance.
);

/**
 * Push a negative ack packet.  Only valid for ack type packets.  Once this function succeeds no
 * further data may be sent and packet_writer_finish should be called.
 *
 * @retval 0                    Nack successfully written.
 * @retval <0                   Sending failed.  The exact value will be a negative enum gdbs_error
 *                              entry indicating what went wrong.
 */
int packet_writer_push_nack
(
    struct packet_writer *packet ///< Packet writer instance.
);

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
);

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
);

#endif /* end PACKET_H_ */