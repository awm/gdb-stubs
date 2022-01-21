/**
 *  @file       core.h
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Entry point and event processing for stub implementation.
 */
#ifndef CORE_H_
#define CORE_H_

/// Environmental properties of the stub.
struct environment
{
    int              ack_enabled;   ///< Boolean indicating if ACK/NACK support is enabled.
    unsigned char   *packet_buffer; ///< Buffer for receiving packets.
    void            *comm;          ///< Arbitrary parameter to communications functions.
    void            *except_state;  ///< Arbitrary exception registration data.
};

/**
 * Obtain the current stub environment.
 *
 * @return The active environment instance.
 */
struct environment *core_get_environment(void);

#endif /* end CORE_H_ */
