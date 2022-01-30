/**
 *  @file       binary.c
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Binary encoding scheme used by some GDB messages.
 *
 *  Older messages often use plain hexadecimal encoding, while newer ones may use this encoding
 *  scheme.
 */
#include "binary.h"

#include "auxiliary/packet.h"
#include "auxiliary/rle.h"
#include "stdc/assert.h"
#include "stdc/null.h"

/**
 * Encode a byte as an escaped binary value (if applicable).
 *
 * @return Number of characters written to the output buffer (1 or 2).
 */
unsigned long binary_encode
(
    char            *buffer, ///< Buffer to write encoded value to.  Must have space for at least
                             ///< two characters.
    unsigned char    byte    ///< Byte to encode.
)
{
    assert(buffer != NULL);

    if (byte < ' '                              ||
        byte == DATA_PACKET_START_CHAR          ||
        byte == NOTIFICATION_PACKET_START_CHAR  ||
        byte == PAYLOAD_END_CHAR                ||
        byte == RLE_CHAR                        ||
        byte == BINARY_ESCAPE_CHAR              ||
        byte > '~')
    {
        buffer[0] = BINARY_ESCAPE_CHAR;
        buffer[1] = (char) (byte ^ 0x20);
        return 2;
    }
    else
    {
        buffer[0] = (char) byte;
        return 1;
    }
}

/**
 * Unconditionally decode an encoded binary value.  This function is intended to be used after the
 * escape character has already been identified.
 *
 * @return Decoded binary value.
 */
unsigned char binary_decode
(
    char encoded ///< Encoded binary value.
)
{
    return (unsigned char) (encoded ^ 0x20);
}
