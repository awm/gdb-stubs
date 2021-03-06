/**
 *  @file       checksum.h
 * @copyright   2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Simple checksum algorithm used by GDB protocol.
 */
#ifndef CHECKSUM_H_
#define CHECKSUM_H_

#include "stdc/size.h"

/**
 * Accumulate one more byte into a checksum value.
 */
static inline void accumulate_checksum
(
    unsigned char *checksum, ///< [in,out] Accumulating checksum value.
    unsigned char  byte      ///< [in]     Value to add to the checksum.
)
{
    *checksum += byte;
}

/**
 * Calculate a simple modulo-256 checksum of a data buffer.
 *
 * @return The calculated checksum.
 */
unsigned char calculate_checksum
(
    const void  *buffer, ///< Buffer to calculate checksum over.
    size_t       size    ///< Buffer size.
);

#endif /* end CHECKSUM_H_ */
