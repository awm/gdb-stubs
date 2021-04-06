/**
 *  @file       ack.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      ACK handling for the GDB protocol.
 */
#ifndef ACK_H_
#define ACK_H_

/**
 * Control whether ACK and NACK packets are sent and received after regular data packets.
 */
void proto_set_ack_mode
(
    int enable ///< Boolean value to enable or disable ACK support.
);

/**
 * Send an ACK response, if ack support is enabled.
 */
void proto_ack(void);

/**
 * Send a NACK response, if ack support is enabled.
 */
void proto_nack(void);

#endif /* end ACK_H_ */
