/**
 *  @file       receive.h
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Packet reception implementation for GDB protocol.
 */
#ifndef RECEIVE_H_
#define RECEIVE_H_

/**
 * Enter the packet receive and process loop.
 */
void proto_process
(
    int send_stop_reply ///< Boolean indicating to send an initial stop reply with information about
                        ///< the signal that triggered entry into the debugger.
);

#endif /* end RECEIVE_H_ */
