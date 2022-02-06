/**
 *  @file       receive.c
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Packet reception implementation for GDB protocol.
 */
#include "gdbsconfig.h"

#include "receive.h"

#include "core.h"

// void proto_receive_packet
// (
//     struct packet_tokenizer *tokenizer
// )
// {
//     const char      *token = NULL;
//     int              result = 0;
//     unsigned long    length = 0;

//     // Extract the first token of the packet, which indicates the type of command.
//     result = packet_tokenizer_advance(tokenizer, TOKEN_SINGLE_CHAR, &token, &length);
//     if (result < 0)
//     {
//         GDBS_LOG("Packet tokenization failed: %s", gdbs_error_to_string(-result));
//         return 0;
//     }
//     else if (length == 0)
//     {
//         GDBS_LOG("Ignoring zero-length packet token");
//         return 0;
//     }

//     // Dispatch packet to appropriate handler based on initial character.
//     switch (token[0])
//     {
//         case '?':
//             result = proto_stop_reply();
//             break;
//         case 'c':
//             result = proto_continue(tokenizer);
//             break;
//         case 'g':
//             result = proto_read_general_registers(tokenizer);
//             break;
//         case 'G':
//             result = proto_write_general_registers(tokenizer);
//             break;
//         case 'k':
//             result = proto_kill();
//             break;
//         case 'm':
//             result = proto_read_memory(tokenizer);
//             break;
//         case 'M':
//             result = proto_write_memory(tokenizer);
//             break;
//         case 'q':
//             result = proto_general_query(tokenizer);
//             break;
//         case 's':
//             result = proto_single_step(tokenizer);
//             break;
//         case 'v':
//             result = proto_extended_command(tokenizer);
//             break;
//         default:
//             GDBS_LOG("Unrecognized command prefix: '%c'\n", token[0]);
//             break;
//     }

//     return result;
// }


/**
 * Enter the packet receive and process loop.
 */
void proto_process
(
    int send_stop_reply ///< Boolean indicating to send an initial stop reply with information about
                        ///< the signal that triggered entry into the debugger.
)
{
    int                      result;
    size_t                   length;
    struct environment      *env = core_get_environment();
    struct packet_tokenizer  tokenizer;

    if (send_stop_reply)
    {
        // Send information regarding the signal that caused control to pass the stub.
        proto_send_stop_reply();
    }

    for (;;)
    {
        // Wait for the next packet to arrive.
        length = GDBS_PACKET_BUFFER_LENGTH;
        result = packet_receive(buffer, &length, PT_MESSAGE, env.comm);
        if (result == 0)
        {
            proto_send_ack(1);
        }
        {
            GDBS_LOG("Receive error: %s", gdbs_error_to_string(-result));
            proto_send_ack(0);
            continue;
        }

        // Begin parsing the packet.
        packet_tokenizer_init(&tokenizer, buffer, length);

        // Try to dispatch the packet to a handler.
        if (proto_receive_packet(&tokenizer))
        {
            // Exit from the processing handler, if requested.
            break;
        }
    }
}
