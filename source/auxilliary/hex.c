/**
 *  @file       hex.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Hexadecimal conversion routines.
 */
#include "hex.h"

#include "gdbstub.h"

#include "debug/debug.h"

/**
 * Convert a single hexadecimal digit to an integer value.
 *
 * @retval 0x0-0xF The converted value.
 * @retval    >0xF Conversion error.
 */
static unsigned char hex_digit_to_byte
(
    char digit ///< Textual hex digit to convert.
)
{
    if ('0' <= digit && digit <= '9')
    {
        return (unsigned char) (digit - '0');
    }
    else if ('A' <= digit && digit <= 'F')
    {
        return (unsigned char) (digit - 'A' + 0x0A);
    }
    else if ('a' <= digit && digit <= 'f')
    {
        return (unsigned char) (digit - 'a' + 0x0A);
    }
    else
    {
        return 0xFF;
    }
}

/**
 * Convert a single text hexadecimal value to an unsigned byte.
 *
 * @retval  0 Conversion successful.
 * @retval <0 Conversion failed.  The exact value will be a negative enum gdbs_error entry
 *            indicating what went wrong.
 */
int hex_octet_to_byte
(
    const char      *string, ///< [in]  Input string.  Must be at least two characters long.  Only
                             ///<       the leading pair of characters will be converted.
    unsigned char   *byte    ///< [out] Byte to write the conversion value to.
)
{
    unsigned char low;
    unsigned char high;

    assert(string != NULL);
    assert(byte != NULL);

    if (string[0] == '\0')
    {
        return -GDBS_ERROR_INVALID;
    }

    high = hex_digit_to_byte(string[0]);
    if (high > 0x0F)
    {
        return -GDBS_ERROR_INVALID;
    }
    low = hex_digit_to_byte(string[1]);
    if (low > 0x0F)
    {
        return -GDBS_ERROR_INVALID;
    }

    *byte = (high << 4) | low;
    return GDBS_ERROR_OK;
}

/**
 * Convert a 4-bit nibble to a single hexadecimal digit.
 *
 * @return The converted hexadecimal digit [0-9A-F].
 */
static char nibble_to_hex_digit
(
    unsigned char nibble ///< Nibble to convert.  Only the 4 low-order bits are used.
)
{
    assert(nibble <= 0xF);

    if (nibble <= 0x9)
    {
        return '0' + (char) nibble;
    }
    else
    {
        return 'A' + (char) nibble - 10;
    }
}

/**
 * Convert a byte to a single text hexadecimal value.
 */
void byte_to_hex_octet
(
    unsigned char    byte,  ///< [in]  Byte to convert.
    char            *buffer ///< [out] Buffer to write the hex value to.  Note that the result will
                            ///<       NOT be automatically NUL-terminated.  The buffer is assumed
                            ///<       to have space for two characters.
)
{
    assert(buffer != NULL);

    buffer[0] = nibble_to_hex_digit(byte >> 4);
    buffer[1] = nibble_to_hex_digit(byte & 0xF);
}
