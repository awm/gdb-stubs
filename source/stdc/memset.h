/**
 *  @file       memset.h
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Implementation of memset() function.
 */
#ifndef MEMSET_H_
#define MEMSET_H_

#if HAVE_MEMSET
#   include <string.h>
#else
#   include "size.h"
/**
 * Fill a memory region with a byte value.
 *
 * @return The parameter s.
 */
void *memset
(
    void    *s, ///< Memory region to fill.
    int      c, ///< Value to fill with.  Only the low byte is relevant.
    size_t   n  ///< Number of bytes of s to fill.
);
#endif

#endif /* end MEMSET_H_ */
