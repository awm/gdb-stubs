/**
 *  @file       gdbsconfig.h
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Default configuration values for GDB stubs.
 */
#ifndef GDBSCONFIG_H_
#define GDBSCONFIG_H_

/// Buffer size for receiving GDB packets.  Must be at least 32 bytes.
#ifndef GDBS_PACKET_BUFFER_LENGTH
#   define GDBS_PACKET_BUFFER_LENGTH 1024
#endif
#if GDBS_PACKET_BUFFER_LENGTH < 32
#   error GDBS_PACKET_BUFFER_LENGTH must be >= 32
#endif

/// Extra declaration for packet buffer.  Set to *static* to move the packet buffer from the stack
/// to BSS.
#ifndef GDBS_PACKET_BUFFER_DECL
#   define GDBS_PACKET_BUFFER_DECL
#endif

/// If the log implementation requires an include file, define GDBS_LOG_INCLUDE to the necessary
/// include pattern.
#ifdef GDBS_LOG_INCLUDE
#   include GDBS_LOG_INCLUDE
#endif

/// Disable logging by default.  To enable logging, define GDBS_LOG to a printf-like function.
#ifndef GDBS_LOG
#   define GDBS_LOG(...)
#endif

#endif /* end GDBSCONFIG_H_ */
