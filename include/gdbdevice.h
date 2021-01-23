/**
 *  @file       gdbdevice.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Internal interface for the application code to provide I/O and debug hooks to the
 *              GDB stub.
 */
#ifndef GDBDEVICE_H_
#define GDBDEVICE_H_

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
int gdbs_register_exceptions(void);

/**
 * Deregister the exception handlers that are necessary for triggering debugger events, and restore
 * the previous values.
 */
void gdbs_deregister_exceptions(void);

/**
 * Initialize communications using a serial port.  Perform any setup that is required to initialize
 * the selected port.
 */
int gdbs_open_comms_serial
(
    const char       *port,  ///< Identifier indicating the serial port to use.
    unsigned int      baud,  ///< Selected baud rate.
    enum gdbs_parity  parity ///< Selected parity mode.
);

/**
 * Close the active communications port and return control of it to the application.
 */
void gdbs_close_comms(void);

/**
 * Send one character to the open communication port.
 *
 * @retval  0 Character was sent successfully.
 * @retval <0 An error occurred.  The exact value will be a negative enum gdbs_error entry
 *            indicating what went wrong.
 */
int gdbs_send
(
    int c ///< The character to send.
);

/**
 * Read one character from the open communication port.
 *
 * @retval >=0 The actual received character value
 * @retval  <0 An error occurred.  The exact value will be a negative enum gdbs_error entry
 *             indicating what went wrong.
 */
int gdbs_receive(void);

#endif /* end GDBDEVICE_H_ */
