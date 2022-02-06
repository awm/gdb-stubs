/**
 *  @file       checksum.c
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Simple checksum algorithm used by GDB protocol.
 */
#include "checksum.h"

#include "stdc/assert.h"
#include "stdc/null.h"

/**
 * Calculate a simple modulo-256 checksum of a data buffer.
 *
 * @return The calculated checksum.
 */
unsigned char calculate_checksum
(
    const void  *buffer, ///< Buffer to calculate checksum over.
    size_t       size    ///< Buffer size.
)
{
    const unsigned char *bytes = (const unsigned char *) buffer;
    size_t               i;
    unsigned char        result = 0;

    assert(bytes != NULL);

    for (i = 0; i < size; ++i)
    {
        accumulate_checksum(&result, bytes[i]);
    }
    return result;
}
