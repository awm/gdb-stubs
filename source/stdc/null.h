/**
 *  @file       null.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Definition of NULL.
 */
#ifndef NULL_H_
#define NULL_H_

#if HAVE_NULL
#   include <stdlib.h>
#else
#   define NULL ((void *) 0x0)
#endif

#endif /* end NULL_H_ */
