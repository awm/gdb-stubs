/**
 *  @file       gdbstub.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Public interface to the GDB stub from application code.
 */
#ifndef GDBSTUB_H_
#define GDBSTUB_H_

/// Possible error codes.
enum gdbs_error
{
    GDBS_ERR_OK = 0, ///< No error.
};

/**
 * Initialize the debugger hooks.  This must be called early in the application startup to register
 * the necessary exception handlers and initialize data structures prior to beginning a debug
 * session.
 *
 * @retval  0 Initialization was successful.
 * @retval <0 An initialization error occurred.  The exact value will be a negative
 *            enum gdbs_error entry indicating what went wrong.
 */
int gdbs_initialize(void);

/**
 * Insert a software breakpoint.  This may be used anywhere in the code after gdbs_initialize() has
 * been called to force execution into the debugger.
 */
void gdbs_breakpoint(void);

#endif /* end GDBSTUB_H_ */
