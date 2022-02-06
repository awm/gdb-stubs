/**
 *  @file       size.h
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Definition of size_t.
 */
#ifndef SIZE_H_
#define SIZE_H_

#if HAVE_SIZE_T
#   include <stddef.h>
#else
/// size_t type definition.
typedef unsigned long size_t;
#endif

#endif /* end SIZE_H_ */
