/**
 *  @file       test_protocol_ack.c
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for protocol ack functions.
 */
#include "protocol/ack.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

//                                      TPSAM   TS   TPA   TPN
static const unsigned long TEST_COUNT =     2 +  3 +   2 +   2;

static struct environment env;

struct environment *core_get_environment(void)
{
    return &env;
}

// Assertion count: 1 + 1 = 2
static void test_proto_set_ack_mode(void)
{
    TAP_DIAG("In %s", __func__);

    proto_set_ack_mode(1);
    TAP_OK(env.ack_enabled, "Ack enabled: %d", env.ack_enabled);

    proto_set_ack_mode(0);
    TAP_OK(!env.ack_enabled, "Ack disabled: %d", env.ack_enabled);
}

struct testbuf
{
    size_t           i;
    size_t           length;
    unsigned char   *data;
};
#define TB_INIT(p) ((struct testbuf) { 0, sizeof(p), (unsigned char *) (p) })

int gdbs_send
(
    void *comm,
    int   c
)
{
    struct testbuf *buf = comm;

    assert(buf->i < buf->length - 1);
    buf->data[buf->i]   = (unsigned char) c;
    buf->data[++buf->i] = '\0';

    return 0;
}

int gdbs_receive
(
    void *comm
)
{
    (void) comm;
    return 0;
}

// Assertion count: 1 + 1 + 1 = 3
static void test_send(void)
{
    char            packet[128] = "";
    struct testbuf  buf;

    TAP_DIAG("In %s", __func__);
    env.comm = &buf;

    env.ack_enabled = 0;
    buf             = TB_INIT(packet);
    send("ACK");
    TAP_OK(strncmp(packet, "", sizeof(packet)) == 0, "Composed packet: '%s'", packet);

    env.ack_enabled = 1;
    buf             = TB_INIT(packet);
    send("ACK");
    TAP_OK(strncmp(packet, "+", sizeof(packet)) == 0, "Composed packet: '%s'", packet);

    env.ack_enabled = 1;
    buf             = TB_INIT(packet);
    send("NACK");
    TAP_OK(strncmp(packet, "-", sizeof(packet)) == 0, "Composed packet: '%s'", packet);
}

// Assertion count: 1 + 1 = 2
static void test_proto_ack(void)
{
    TAP_DIAG("In %s", __func__);

    char            packet[128] = "";
    struct testbuf  buf;

    TAP_DIAG("In %s", __func__);
    env.comm = &buf;

    env.ack_enabled = 0;
    buf             = TB_INIT(packet);
    proto_ack();
    TAP_OK(strncmp(packet, "", sizeof(packet)) == 0, "Composed packet: '%s'", packet);

    env.ack_enabled = 1;
    buf             = TB_INIT(packet);
    proto_ack();
    TAP_OK(strncmp(packet, "+", sizeof(packet)) == 0, "Composed packet: '%s'", packet);
}

// Assertion count: 1 + 1 = 2
static void test_proto_nack(void)
{
    TAP_DIAG("In %s", __func__);

    char            packet[128] = "";
    struct testbuf  buf;

    TAP_DIAG("In %s", __func__);
    env.comm = &buf;

    env.ack_enabled = 0;
    buf             = TB_INIT(packet);
    proto_nack();
    TAP_OK(strncmp(packet, "", sizeof(packet)) == 0, "Composed packet: '%s'", packet);

    env.ack_enabled = 1;
    buf             = TB_INIT(packet);
    proto_nack();
    TAP_OK(strncmp(packet, "-", sizeof(packet)) == 0, "Composed packet: '%s'", packet);
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_proto_set_ack_mode();
    test_send();
    test_proto_ack();
    test_proto_nack();

    TAP_END_PLAN();
}
