/**
 *  @file       ack.c
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      ACK handling for the GDB protocol.
 */
#include "gdbsconfig.h"

#include "ack.h"

#include "auxiliary/packet.h"
#include "core.h"
#include "stdc/assert.h"
#include "stdc/null.h"

/**
 * Control whether ACK and NACK packets are sent and received after regular data packets.
 */
void proto_set_ack_mode
(
    int enable ///< Boolean value to enable or disable ACK support.
)
{
    core_get_environment()->ack_enabled = enable;
}

/**
 * Prepare and send the requested ack packet.  If ack support is disabled, then no action is taken.
 */
static void send
(
    const char *type ///< Type of ack message, either "ACK" or "NACK" is expected.
)
{
    int                     result;
    struct packet_writer    packet;

    assert(type != NULL);
    assert(type[0] == 'N' || type[0] == 'A');

    if (core_get_environment()->ack_enabled)
    {
        packet_writer_init(&packet, PT_ACK, core_get_environment()->comm);

        result = packet_writer_push_ack(&packet, (type[0] == 'A'));
        if (result == 0)
        {
            result = packet_writer_finish(&packet);
        }
        if (result < 0)
        {
            GDBS_LOG("Failed to send %s: %s\n", type, gdbs_error_to_string(-result));
        }
    }
}

/**
 * Send an ACK response, if ack support is enabled.
 */
void proto_ack(void)
{
    send("ACK");
}

/**
 * Send an NACK response, if ack support is enabled.
 */
void proto_nack(void)
{
    send("NACK");
}
