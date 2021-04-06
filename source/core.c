/**
 *  @file       core.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Entry point and event processing for stub implementation.
 */
#include "gdbsconfig.h"
#include "gdbsdevice.h"
#include "gdbstub.h"

#include "core.h"

#include "auxiliary/packet.h"
#include "protocol/ack.h"
#include "protocol/receive.h"
#include "stdc/memset.h"
#include "stdc/null.h"

/// Active stub environment.
static struct environment env;

/**
 * Convert an enum gdbs_error value to a short descriptive string.
 *
 * @return  Corresponding string, which may be empty if the error value does not map to a valid enum
 *          entry.
 */
const char *gdbs_error_to_string
(
    int error ///< Error code to convert.
)
{
    switch (error)
    {
        case GDBS_ERROR_OK:
            return "OK";
        case GDBS_ERROR_INVALID:
            return "invalid data or parameter";
        case GDBS_ERROR_CHECKSUM:
            return "invalid checksum";
        case GDBS_ERROR_EOB:
            return "end of buffer";
        case GDBS_ERROR_NOT_FOUND:
            return "item or value not found";
    }

    return "";
}

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
)
{
    int result;

    // Set up the stub environment.
    memset(&env, 0, sizeof(env));
    env.comm = comm;

    // Acks must always be turned on initially.
    proto_set_ack_mode(1);

    // Start the communications interface.
    result = gdbs_open_comm(comm);
    if (result < 0)
    {
        GDBS_LOG("Failed to initialize communications interface: %s\n",
                 gdbs_error_to_string(-result));
        return result;
    }

    // Install the exception hooks to call into the debugger.
    result = gdbs_register_exceptions(&env.except_state);
    if (result < 0)
    {
        GDBS_LOG("Failed to register exceptions: %s\n", gdbs_error_to_string(-result));
    }
    return result;
}

/**
 * Clean up the debugger hooks.  This will return the system exception handling state to what it was
 * before the stub was initialized.  Another call to gdbs_initialize() will be required to use the
 * stub again.
 */
void gdbs_cleanup(void)
{
    gdbs_deregister_exceptions(env.except_state);
    gdbs_close_comm(env.comm);
}

/**
 * Obtain the current stub environment.
 *
 * @return The active environment instance.
 */
struct environment *core_get_environment(void)
{
    return &env;
}

/**
 * Entry point for the stub event handler.  In most cases this will be called from specific
 * interrupt or exception handlers in response to system aborts or breakpoints.
 */
void gdbs_enter(void)
{
    GDBS_PACKET_BUFFER_DECL unsigned char buffer[GDBS_PACKET_BUFFER_LENGTH];

    env.packet_buffer = buffer;
    proto_process(1);
    env.packet_buffer = NULL;
}
