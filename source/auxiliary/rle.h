/**
 *  @file       rle.h
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Run-length encoding functions for GDB protocol.
 */
#ifndef RLE_H_
#define RLE_H_

#include "stdc/size.h"

#define RLE_CHAR '*' ///< Character used to denote an RLE value.

/**
 * Run-length encode a buffer using the GDB protocol RLE scheme.
 */
void run_length_encode
(
    char    *buffer, ///< [in,out] Buffer of data to be encoded.  This data is encoded in-place, as
                     ///<          the result will always be the same length or shorter.
    size_t  *size    ///< [in,out] As input, the length of the incoming data buffer.  As output, the
                     ///<           length of the encoded data now occupying the buffer.
);

#endif /* end RLE_H_ */
