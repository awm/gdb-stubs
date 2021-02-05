/**
 *  @file       hex.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Hexadecimal conversion routines.
 */
#ifndef HEX_H_
#define HEX_H_

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
);

/**
 * Convert a byte to a single text hexadecimal value.
 */
void byte_to_hex_octet
(
    unsigned char    byte,  ///< [in]  Byte to convert.
    char            *buffer ///< [out] Buffer to write the hex value to.  Note that the result will
                            ///<       NOT be automatically NUL-terminated.  The buffer is assumed
                            ///<       to have space for two characters.
);

#endif /* end HEX_H_ */
