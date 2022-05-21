/**
 *  @file       gdbstub.h
 *  @copyright  2022 Andrew MacIsaac
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
    GDBS_ERROR_OK = 0,    ///< No error.
    GDBS_ERROR_INVALID,   ///< Invalid function input.
    GDBS_ERROR_CHECKSUM,  ///< Invalid packet checksum.
    GDBS_ERROR_EOB,       ///< At the end of the buffer.
    GDBS_ERROR_NOT_FOUND, ///< Requested item was not found.

    GDBS_ERROR_COUNT      ///< Number of error codes.  Not itself a valid error code.
};

/**
 * Convert an enum gdbs_error value to a short descriptive string.
 *
 * @return  Corresponding string, which may be empty if the error value does not map to a valid enum
 *          entry.
 */
const char *gdbs_error_to_string
(
    int error ///< Error code to convert.
);

/**
 * Initialize the debugger hooks.  This must be called early in the application startup to register
 * the necessary exception handlers and initialize data structures prior to beginning a debug
 * session.
 *
 * @retval  0 Initialization was successful.
 * @retval <0 An initialization error occurred.  The exact value will be a negative
 *            enum gdbs_error entry indicating what went wrong.
 */
int gdbs_initialize
(
    void *comm  ///< Arbitrary parameter for the communications interface to use.  This is passed to
                ///< all communications functions.
);

/**
 * Clean up the debugger hooks.  This will return the system exception handling state to what it was
 * before the stub was initialized.  Another call to gdbs_initialize() will be required to use the
 * stub again.
 */
void gdbs_cleanup(void);

/**
 * Insert a software breakpoint.  This may be used anywhere in the code after gdbs_initialize() has
 * been called to force execution into the debugger.
 */
void gdbs_breakpoint(void);

/**
 * Entry point for the stub event handler.  In most cases this will be called from specific
 * interrupt or exception handlers in response to system aborts or breakpoints.
 */
void gdbs_enter(void);

#endif /* end GDBSTUB_H_ */
