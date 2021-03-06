/**
 *  @file       assert.h
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Implementation of assert() macro.
 */
#ifndef ASSERT_H_
#define ASSERT_H_

#if HAVE_ASSERT
#   include <assert.h>
#else
/// Empty assert implementation if none is provided.
#   define assert(cond)
#endif

#endif /* end ASSERT_H_ */
