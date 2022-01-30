/**
 *  @file       binary.h
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
#ifndef BINARY_H_
#define BINARY_H_

/// Character used to begin a binary escape sequence.
#define BINARY_ESCAPE_CHAR '}'

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
);

/**
 * Unconditionally decode an encoded binary value.  This function is intended to be used after the
 * escape character has already been identified.
 *
 * @return Decoded binary value.
 */
unsigned char binary_decode
(
    char encoded ///< Encoded binary value.
);

#endif /* end BINARY_H_ */
