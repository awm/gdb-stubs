/**
 *  @file       test_auxiliary_packet.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for packet processing implementation.
 */
#include "auxiliary/packet.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

//                                      TTT TEPC   TV  TPT TPWPA TPWP  TPR
static const unsigned long TEST_COUNT = 256 +  7 + 17 + 69 +   6 + 87 + 36;

static void test_to_type(void)
{
#define TTT(c, e)                                                   \
    do                                                              \
    {                                                               \
        int result = to_type(c);                                    \
        TAP_OK(result == (e), "Type of 0x%02X: %d", (c), result);   \
    } while (0)

    TAP_DIAG("In %s", __func__);

/*
Python commands to help simplify generation:

for i in range(0, 256):
    print("    TTT(0x{:02X}, 0);".format(i))
*/

    TTT(0x00, -1);
    TTT(0x01, -1);
    TTT(0x02, -1);
    TTT(0x03, -1);
    TTT(0x04, -1);
    TTT(0x05, -1);
    TTT(0x06, -1);
    TTT(0x07, -1);
    TTT(0x08, -1);
    TTT(0x09, -1);
    TTT(0x0A, -1);
    TTT(0x0B, -1);
    TTT(0x0C, -1);
    TTT(0x0D, -1);
    TTT(0x0E, -1);
    TTT(0x0F, -1);
    TTT(0x10, -1);
    TTT(0x11, -1);
    TTT(0x12, -1);
    TTT(0x13, -1);
    TTT(0x14, -1);
    TTT(0x15, -1);
    TTT(0x16, -1);
    TTT(0x17, -1);
    TTT(0x18, -1);
    TTT(0x19, -1);
    TTT(0x1A, -1);
    TTT(0x1B, -1);
    TTT(0x1C, -1);
    TTT(0x1D, -1);
    TTT(0x1E, -1);
    TTT(0x1F, -1);
    TTT(0x20, -1);
    TTT(0x21, -1);
    TTT(0x22, -1);
    TTT(0x23, -1);
    TTT(0x24, PT_MESSAGE);      // Message start of packet.
    TTT(0x25, PT_NOTIFICATION); // Notification start of packet.
    TTT(0x26, -1);
    TTT(0x27, -1);
    TTT(0x28, -1);
    TTT(0x29, -1);
    TTT(0x2A, -1);
    TTT(0x2B, PT_ACK);          // Ack packet.
    TTT(0x2C, -1);
    TTT(0x2D, PT_ACK);          // Nack packet.
    TTT(0x2E, -1);
    TTT(0x2F, -1);
    TTT(0x30, -1);
    TTT(0x31, -1);
    TTT(0x32, -1);
    TTT(0x33, -1);
    TTT(0x34, -1);
    TTT(0x35, -1);
    TTT(0x36, -1);
    TTT(0x37, -1);
    TTT(0x38, -1);
    TTT(0x39, -1);
    TTT(0x3A, -1);
    TTT(0x3B, -1);
    TTT(0x3C, -1);
    TTT(0x3D, -1);
    TTT(0x3E, -1);
    TTT(0x3F, -1);
    TTT(0x40, -1);
    TTT(0x41, -1);
    TTT(0x42, -1);
    TTT(0x43, -1);
    TTT(0x44, -1);
    TTT(0x45, -1);
    TTT(0x46, -1);
    TTT(0x47, -1);
    TTT(0x48, -1);
    TTT(0x49, -1);
    TTT(0x4A, -1);
    TTT(0x4B, -1);
    TTT(0x4C, -1);
    TTT(0x4D, -1);
    TTT(0x4E, -1);
    TTT(0x4F, -1);
    TTT(0x50, -1);
    TTT(0x51, -1);
    TTT(0x52, -1);
    TTT(0x53, -1);
    TTT(0x54, -1);
    TTT(0x55, -1);
    TTT(0x56, -1);
    TTT(0x57, -1);
    TTT(0x58, -1);
    TTT(0x59, -1);
    TTT(0x5A, -1);
    TTT(0x5B, -1);
    TTT(0x5C, -1);
    TTT(0x5D, -1);
    TTT(0x5E, -1);
    TTT(0x5F, -1);
    TTT(0x60, -1);
    TTT(0x61, -1);
    TTT(0x62, -1);
    TTT(0x63, -1);
    TTT(0x64, -1);
    TTT(0x65, -1);
    TTT(0x66, -1);
    TTT(0x67, -1);
    TTT(0x68, -1);
    TTT(0x69, -1);
    TTT(0x6A, -1);
    TTT(0x6B, -1);
    TTT(0x6C, -1);
    TTT(0x6D, -1);
    TTT(0x6E, -1);
    TTT(0x6F, -1);
    TTT(0x70, -1);
    TTT(0x71, -1);
    TTT(0x72, -1);
    TTT(0x73, -1);
    TTT(0x74, -1);
    TTT(0x75, -1);
    TTT(0x76, -1);
    TTT(0x77, -1);
    TTT(0x78, -1);
    TTT(0x79, -1);
    TTT(0x7A, -1);
    TTT(0x7B, -1);
    TTT(0x7C, -1);
    TTT(0x7D, -1);
    TTT(0x7E, -1);
    TTT(0x7F, -1);
    TTT(0x80, -1);
    TTT(0x81, -1);
    TTT(0x82, -1);
    TTT(0x83, -1);
    TTT(0x84, -1);
    TTT(0x85, -1);
    TTT(0x86, -1);
    TTT(0x87, -1);
    TTT(0x88, -1);
    TTT(0x89, -1);
    TTT(0x8A, -1);
    TTT(0x8B, -1);
    TTT(0x8C, -1);
    TTT(0x8D, -1);
    TTT(0x8E, -1);
    TTT(0x8F, -1);
    TTT(0x90, -1);
    TTT(0x91, -1);
    TTT(0x92, -1);
    TTT(0x93, -1);
    TTT(0x94, -1);
    TTT(0x95, -1);
    TTT(0x96, -1);
    TTT(0x97, -1);
    TTT(0x98, -1);
    TTT(0x99, -1);
    TTT(0x9A, -1);
    TTT(0x9B, -1);
    TTT(0x9C, -1);
    TTT(0x9D, -1);
    TTT(0x9E, -1);
    TTT(0x9F, -1);
    TTT(0xA0, -1);
    TTT(0xA1, -1);
    TTT(0xA2, -1);
    TTT(0xA3, -1);
    TTT(0xA4, -1);
    TTT(0xA5, -1);
    TTT(0xA6, -1);
    TTT(0xA7, -1);
    TTT(0xA8, -1);
    TTT(0xA9, -1);
    TTT(0xAA, -1);
    TTT(0xAB, -1);
    TTT(0xAC, -1);
    TTT(0xAD, -1);
    TTT(0xAE, -1);
    TTT(0xAF, -1);
    TTT(0xB0, -1);
    TTT(0xB1, -1);
    TTT(0xB2, -1);
    TTT(0xB3, -1);
    TTT(0xB4, -1);
    TTT(0xB5, -1);
    TTT(0xB6, -1);
    TTT(0xB7, -1);
    TTT(0xB8, -1);
    TTT(0xB9, -1);
    TTT(0xBA, -1);
    TTT(0xBB, -1);
    TTT(0xBC, -1);
    TTT(0xBD, -1);
    TTT(0xBE, -1);
    TTT(0xBF, -1);
    TTT(0xC0, -1);
    TTT(0xC1, -1);
    TTT(0xC2, -1);
    TTT(0xC3, -1);
    TTT(0xC4, -1);
    TTT(0xC5, -1);
    TTT(0xC6, -1);
    TTT(0xC7, -1);
    TTT(0xC8, -1);
    TTT(0xC9, -1);
    TTT(0xCA, -1);
    TTT(0xCB, -1);
    TTT(0xCC, -1);
    TTT(0xCD, -1);
    TTT(0xCE, -1);
    TTT(0xCF, -1);
    TTT(0xD0, -1);
    TTT(0xD1, -1);
    TTT(0xD2, -1);
    TTT(0xD3, -1);
    TTT(0xD4, -1);
    TTT(0xD5, -1);
    TTT(0xD6, -1);
    TTT(0xD7, -1);
    TTT(0xD8, -1);
    TTT(0xD9, -1);
    TTT(0xDA, -1);
    TTT(0xDB, -1);
    TTT(0xDC, -1);
    TTT(0xDD, -1);
    TTT(0xDE, -1);
    TTT(0xDF, -1);
    TTT(0xE0, -1);
    TTT(0xE1, -1);
    TTT(0xE2, -1);
    TTT(0xE3, -1);
    TTT(0xE4, -1);
    TTT(0xE5, -1);
    TTT(0xE6, -1);
    TTT(0xE7, -1);
    TTT(0xE8, -1);
    TTT(0xE9, -1);
    TTT(0xEA, -1);
    TTT(0xEB, -1);
    TTT(0xEC, -1);
    TTT(0xED, -1);
    TTT(0xEE, -1);
    TTT(0xEF, -1);
    TTT(0xF0, -1);
    TTT(0xF1, -1);
    TTT(0xF2, -1);
    TTT(0xF3, -1);
    TTT(0xF4, -1);
    TTT(0xF5, -1);
    TTT(0xF6, -1);
    TTT(0xF7, -1);
    TTT(0xF8, -1);
    TTT(0xF9, -1);
    TTT(0xFA, -1);
    TTT(0xFB, -1);
    TTT(0xFC, -1);
    TTT(0xFD, -1);
    TTT(0xFE, -1);
    TTT(0xFF, -1);
}

static void test_extract_packet_checksum(void)
{
#define TEPC(p, c, r)                                                                   \
    do                                                                                  \
    {                                                                                   \
        unsigned char   checksum = 0;                                                   \
        int             result = extract_packet_checksum((const unsigned char *) (p),   \
                            strlen(p), &checksum);                                      \
        TAP_OK(result == (r) && checksum == (c),                                        \
            "Extract checksum: '%s' -> 0x%02X", (p), checksum);                         \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TEPC("$#00",    0x00, 0);
    TEPC("$foo#.X", 0x00, -GDBS_ERROR_INVALID);
    TEPC("$foo?00", 0x00, -GDBS_ERROR_INVALID);
    TEPC("$foo#44", 0x44, 0);
    TEPC("%bar#4!", 0x00, -GDBS_ERROR_INVALID);
    TEPC("%bar#35", 0x35, 0);
    TEPC("%bar35",  0x00, -GDBS_ERROR_INVALID);
}

static void test_verify(void)
{
#define TV(p, r)                                                        \
    do                                                                  \
    {                                                                   \
        int result = verify((const unsigned char *) (p), strlen(p));    \
        TAP_OK(result == (r), "Verify packet '%s': %d", (p), result);   \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TV("+",    -GDBS_ERROR_INVALID);
    TV("-",    -GDBS_ERROR_INVALID);
    TV("?",    -GDBS_ERROR_INVALID);
    TV("",     -GDBS_ERROR_INVALID);
    TV("+foo", -GDBS_ERROR_INVALID);
    TV("foo",  -GDBS_ERROR_INVALID);

    TV("$#00",    0);
    TV("$foo#.X", -GDBS_ERROR_INVALID);
    TV("$foo?00", -GDBS_ERROR_INVALID);
    TV("$foo#44", 0);
    TV("$foo#3F", -GDBS_ERROR_CHECKSUM);
    TV("$blarg",  -GDBS_ERROR_INVALID);

    TV("%bar#4!", -GDBS_ERROR_INVALID);
    TV("%bar#35", 0);
    TV("%bar35",  -GDBS_ERROR_INVALID);
    TV("%foo#3F", -GDBS_ERROR_CHECKSUM);
    TV("%blarg",  -GDBS_ERROR_INVALID);
}

void test_packet_tokenizer(void)
{
    const char              *packet;
    struct packet_tokenizer  tokenizer;

#define TPT(z, d, t, r)                                                 \
    do                                                                  \
    {                                                                   \
        char                 buffer[128];                               \
        const unsigned char *token = NULL;                              \
        int                  result;                                    \
        unsigned long        length = 0;                                \
        memset(buffer, 0, sizeof(buffer));                              \
        result = packet_tokenizer_advance((z), (d), &token, &length);   \
        if (length > 0 && token != NULL)                                \
        {                                                               \
            assert(length < sizeof(buffer));                            \
            memcpy(buffer, token, length);                              \
        }                                                               \
        TAP_OK(result == (r), "Advance result: %d", result);            \
        TAP_OK(length == strlen(t), "Token length: %lu", length);       \
        TAP_OK(strcmp(buffer, (t)) == 0, "Token: '%s'", buffer);        \
    } while (0)

    TAP_DIAG("In %s", __func__);

    packet = "+";
    packet_tokenizer_init(&tokenizer, (const unsigned char *) packet, strlen(packet));
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "+", 0);
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "", -GDBS_ERROR_EOB);
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "", -GDBS_ERROR_EOB);

    packet = "-";
    packet_tokenizer_init(&tokenizer, (const unsigned char *) packet, strlen(packet));
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "-", 0);
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "", -GDBS_ERROR_EOB);

    packet = "$?#3F";
    packet_tokenizer_init(&tokenizer, (const unsigned char *) packet, strlen(packet));
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "?", 0);
    TPT(&tokenizer, TOKEN_SINGLE_CHAR, "", -GDBS_ERROR_EOB);

    packet = "$vCont?#49";
    packet_tokenizer_init(&tokenizer, (const unsigned char *) packet, strlen(packet));
    TPT(&tokenizer, TOKEN_SINGLE_CHAR,  "v",        0);
    TPT(&tokenizer, ';',                "Cont?",    -GDBS_ERROR_NOT_FOUND);
    packet_tokenizer_rewind(&tokenizer);
    TPT(&tokenizer, '?',                "Cont", 0);
    TPT(&tokenizer, '?',                "",     -GDBS_ERROR_NOT_FOUND);
    TPT(&tokenizer, '?',                "",     -GDBS_ERROR_EOB);

    packet = "$Z1,189D67D8,3#E5";
    packet_tokenizer_init(&tokenizer, (const unsigned char *) packet, strlen(packet));
    TPT(&tokenizer, TOKEN_SINGLE_CHAR,  "Z",        0);
    TPT(&tokenizer, ',',                "1",        0);
    TPT(&tokenizer, ',',                "189D67D8", 0);
    TPT(&tokenizer, ',',                "3",        -GDBS_ERROR_NOT_FOUND);
    packet_tokenizer_rewind(&tokenizer);
    TPT(&tokenizer, TOKEN_EOB,          "3",        0);
    TPT(&tokenizer, TOKEN_EOB,          "",         -GDBS_ERROR_EOB);

    packet = "$X1000,8,}!hello*}\x03#05";
    packet_tokenizer_init(&tokenizer, (const unsigned char *) packet, strlen(packet));
    TPT(&tokenizer, TOKEN_SINGLE_CHAR,  "X",                0);
    TPT(&tokenizer, ',',                "1000",             0);
    TPT(&tokenizer, ',',                "8",                0);
    TPT(&tokenizer, TOKEN_EOB,          "}!hello*}\x03",    0);
    TPT(&tokenizer, TOKEN_EOB,          "",                 -GDBS_ERROR_EOB);
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

    return GDBS_ERROR_OK;
}

static void test_packet_writer_push_ack(void)
{
    char                    packet[128];
    struct packet_writer    writer;
    struct testbuf          buf = TB_INIT(packet);

    TAP_DIAG("In %s", __func__);

    packet_writer_init(&writer, PT_ACK, &buf);
    TAP_OK(packet_writer_push_ack(&writer, 1) == 0,     "Push ack");
    TAP_OK(packet_writer_finish(&writer) == 0,          "Complete ack");
    TAP_OK(strncmp(packet, "+", sizeof(packet)) == 0,   "Composed packet: '%s'", packet);

    buf = TB_INIT(packet);
    packet_writer_init(&writer, PT_ACK, &buf);
    TAP_OK(packet_writer_push_ack(&writer, 0) == 0,     "Push nack");
    TAP_OK(packet_writer_finish(&writer) == 0,          "Complete nack");
    TAP_OK(strncmp(packet, "-", sizeof(packet)) == 0,   "Composed packet: '%s'", packet);
}

static void test_packet_writer_push(void)
{
    char                    packet[128];
    struct packet_writer    writer;
    struct testbuf          buf = TB_INIT(packet);

    TAP_DIAG("In %s", __func__);

    packet_writer_init(&writer, PT_MESSAGE, &buf);
    TAP_OK(packet_writer_push(&writer, '?') == 0,           "Push byte");
    TAP_OK(packet_writer_finish(&writer) == 0,              "Complete packet");
    TAP_OK(strncmp(packet, "$?#3F", sizeof(packet)) == 0,   "Composed packet: '%s'", packet);

    buf = TB_INIT(packet);
    packet_writer_init(&writer, PT_MESSAGE, &buf);
    TAP_OK(packet_writer_push(&writer, 'v') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'C') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'o') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'n') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 't') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'c') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 's') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 't') == 0,   "Push byte");
    TAP_OK(packet_writer_finish(&writer) == 0,      "Complete packet");
    TAP_OK(strncmp(packet, "$vCont;c;s;t#05", sizeof(packet)) == 0, "Composed packet: '%s'",
                                                                    packet);

    buf = TB_INIT(packet);
    packet_writer_init(&writer, PT_NOTIFICATION, &buf);
    TAP_OK(packet_writer_push(&writer, 'S') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 't') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'o') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'p') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ':') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'T') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '0') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '5') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '0') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '5') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ':') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '9') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '8') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'e') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '7') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'f') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'f') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'b') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'f') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '0') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '4') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ':') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '4') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'c') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'e') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '6') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'f') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'f') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'b') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'f') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '0') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '8') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ':') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'b') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '1') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'b') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '6') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'e') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '5') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '4') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'c') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 't') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'h') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'r') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'e') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'a') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'd') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ':') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'p') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '7') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '5') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '2') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '6') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '.') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '7') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '5') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '2') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '6') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'c') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'o') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'r') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, 'e') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ':') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, '0') == 0,   "Push byte");
    TAP_OK(packet_writer_push(&writer, ';') == 0,   "Push byte");
    TAP_OK(packet_writer_finish(&writer) == 0,      "Complete packet");
    TAP_OK(
        strncmp(packet,
                "%Stop:T0505:98e7ffbf;04:4ce6ffbf;08:b1b6e54c;thread:p7526.7526;core:0;#6D",
                sizeof(packet)) == 0,
        "Composed packet: '%s'",
        packet);
}

int gdbs_receive
(
    void *comm
)
{
    struct testbuf *buf = comm;

    if (buf->i >= buf->length)
    {
        return -GDBS_ERROR_EOB;
    }
    else
    {
        return buf->data[buf->i++];
    }
}

static void test_packet_receive(void)
{
#define TPR(p, t, r)                                                                \
    do                                                                              \
    {                                                                               \
        char            buffer[] = (p);                                             \
        int             result;                                                     \
        struct testbuf  buf = TB_INIT(buffer);                                      \
        unsigned char   packet[64];                                                 \
        unsigned long   length = sizeof(packet);                                    \
        result = packet_receive(packet, &length, (t), &buf);                        \
        TAP_OK(result == (r), "Receive result: %d", result);                        \
        TAP_OK(result < 0 || length == strlen(p), "Packet length: %lu", length);    \
        TAP_OK(result < 0 || memcmp(buffer, packet, length) == 0, "Packet match");  \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TPR("+",    PT_ACK, 0);
    TPR("-",    PT_ACK, 0);
    TPR("",     PT_ACK, -GDBS_ERROR_EOB);

    TPR("$?#3F",                        PT_MESSAGE, 0);
    TPR("$vCont;c;s;t#05",              PT_MESSAGE, 0);
    TPR("$vCont;c;s;t#A5",              PT_MESSAGE, -GDBS_ERROR_CHECKSUM);
    TPR("$Z1,189D67D8,3#E5",            PT_MESSAGE, 0);
    TPR("$X1000,8,}!hello*}\x03#05",    PT_MESSAGE, 0);
    TPR("$X1000,8,}#hello*}##27",       PT_MESSAGE, 0);

    TPR("%Stop:T0505:98e7ffbf;04:4ce6ffbf;08:b1b6e54c;thread:p7526.7526;core:0;#6D",
        PT_NOTIFICATION,
        -GDBS_ERROR_EOB);
    TPR("%bar#35",  PT_NOTIFICATION, 0);
    TPR("",         PT_NOTIFICATION, -GDBS_ERROR_EOB);
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_to_type();
    test_extract_packet_checksum();
    test_verify();
    test_packet_tokenizer();
    test_packet_writer_push_ack();
    test_packet_writer_push();
    test_packet_receive();

    TAP_END_PLAN();
}
