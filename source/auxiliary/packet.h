/**
 *  @file       packet.h
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Formatting and parsing routines for GDB packets.
 */
#ifndef PACKET_H_
#define PACKET_H_

#define DATA_PACKET_START_CHAR          '$' ///< Character indicating start of a data packet.
#define NOTIFICATION_PACKET_START_CHAR  '%' ///< Character indicating start of a notification.
#define PAYLOAD_END_CHAR                '#' ///< Character indicating end of packet payload and
                                            ///< start of checksum field.

#endif /* end PACKET_H_ */
