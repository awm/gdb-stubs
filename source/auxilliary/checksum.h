/**
 *  @file       checksum.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Simple checksum algorithm used by GDB protocol.
 */
#ifndef CHECKSUM_H_
#define CHECKSUM_H_

/**
 * Calculate a simple modulo-256 checksum of a data buffer.
 *
 * @return The calculated checksum.
 */
unsigned char calculate_checksum
(
    const void    *buffer, ///< Buffer to calculate checksum over.
    unsigned long  size    ///< Buffer size.
);

#endif /* end CHECKSUM_H_ */
