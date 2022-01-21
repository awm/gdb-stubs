/**
 *  @file       gdbsdevice.h
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Internal interface for the application code to provide I/O and debug hooks to the
 *              GDB stub.
 */
#ifndef GDBSDEVICE_H_
#define GDBSDEVICE_H_

/**
 * Flush the device's instruction cache.  If the platform has no instruction cache then this
 * function can be implemented as a no-op.
 */
void gdbs_flush_icache(void);

/**
 * Register the exception handlers that are necessary for triggering debugger events.  Preserve the
 * previously registered values so that they can be restored later.
 *
 * @retval  0 Exception registration was successful.
 * @retval <0 An error occurred.  The exact value will be a negative enum gdbs_error entry
 *            indicating what went wrong.
 */
int gdbs_register_exceptions
(
    void **state ///< [out] Arbitrary exception state to be retained and passed to
                 ///<       gdbs_deregister_exceptions().
);

/**
 * Deregister the exception handlers that are necessary for triggering debugger events, and restore
 * the previous values.
 */
void gdbs_deregister_exceptions
(
    void *state ///< Exception state data from gdbs_register_exceptions().
);

/**
 * Initialize a communications port.
 *
 * @retval  0 Port setup was successful.
 * @retval <0 An error occurred.  The exact value will be a negative enum gdbs_error entry
 *            indicating what went wrong.
 */
int gdbs_open_comm
(
    void *comm ///< Communication parameter that was passed to gdbs_initialize().
);

/**
 * Close the active communications port and return control of it to the application.
 */
void gdbs_close_comm
(
    void *comm ///< Communication parameter that was passed to gdbs_initialize().
);

/**
 * Send one character to the open communication port.
 *
 * @retval  0   Character was sent successfully.
 * @retval <0   Sending failed.  The exact value will be a negative enum gdbs_error entry indicating
 *              what went wrong.
 */
int gdbs_send
(
    void *comm, ///< Communication parameter that was passed to gdbs_initialize().
    int   c     ///< The character to send.
);

/**
 * Read one character from the open communication port.
 *
 * @retval >=0 The actual received character value
 * @retval  <0 An error occurred.  The exact value will be a negative enum gdbs_error entry
 *             indicating what went wrong.
 */
int gdbs_receive
(
    void *comm ///< Communication parameter that was passed to gdbs_initialize().
);

#endif /* end GDBSDEVICE_H_ */
