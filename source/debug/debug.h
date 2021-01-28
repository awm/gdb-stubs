/**
 *  @file       debug.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Basic debugging routines for developing stubs.
 */
#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef NDEBUG
#   define assert(x)
#else
#   include <assert.h>
#   include <stdio.h>
#   include <stdlib.h>
#endif

#endif /* end DEBUG_H_ */
