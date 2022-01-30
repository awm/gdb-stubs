/**
 *  @file       null.h
 *  @copyright  2022 Andrew MacIsaac
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
/// NULL pointer value definition.
#   define NULL ((void *) 0x0)
#endif

#endif /* end NULL_H_ */
