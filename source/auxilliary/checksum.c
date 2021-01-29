/**
 *  @file       checksum.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Simple checksum algorithm used by GDB protocol.
 */
#include "checksum.h"

#include "debug/debug.h"

/**
 * Calculate a simple modulo-256 checksum of a data buffer.
 *
 * @return The calculated checksum.
 */
unsigned char calculate_checksum
(
    const void      *buffer, ///< Buffer to calculate checksum over.
    unsigned long    size    ///< Buffer size.
)
{
    const unsigned char *bytes = (const unsigned char *) buffer;
    unsigned char        result = 0;
    unsigned long        i;

    assert(bytes != NULL);

    for (i = 0; i < size; ++i)
    {
        accumulate_checksum(&result, bytes[i]);
    }
    return result;
}
