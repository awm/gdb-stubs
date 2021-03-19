/**
 *  @file       test_auxiliary_binary.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for binary escaping implementation.
 */
#include "auxiliary/binary.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

static const unsigned long TEST_COUNT = 256 + 166;

static void test_binary_encode(void)
{
    char buffer[2];
    char expected[4];

#define TBE(v, e)                                                           \
    do                                                                      \
    {                                                                       \
        if (e)                                                              \
        {                                                                   \
            snprintf(expected, sizeof(expected), "}%c", (v) ^ 0x20);        \
        }                                                                   \
        else                                                                \
        {                                                                   \
            expected[0] = (v);                                              \
            expected[1] = '\0';                                             \
        }                                                                   \
        TAP_OK(binary_encode(buffer, (v)) == strlen(expected) &&            \
                        memcmp(buffer, expected, strlen(expected)) == 0,    \
                    "Test 0x%02X", (v));                                    \
    } while (0)

    TAP_DIAG("In %s", __func__);

/*
Python commands to help simplify generation:

for i in range(0, 256):
    print("    TBE(0x{:02X}, 1);".format(i))
*/

    TBE(0x00, 1);
    TBE(0x01, 1);
    TBE(0x02, 1);
    TBE(0x03, 1);
    TBE(0x04, 1);
    TBE(0x05, 1);
    TBE(0x06, 1);
    TBE(0x07, 1);
    TBE(0x08, 1);
    TBE(0x09, 1);
    TBE(0x0A, 1);
    TBE(0x0B, 1);
    TBE(0x0C, 1);
    TBE(0x0D, 1);
    TBE(0x0E, 1);
    TBE(0x0F, 1);
    TBE(0x10, 1);
    TBE(0x11, 1);
    TBE(0x12, 1);
    TBE(0x13, 1);
    TBE(0x14, 1);
    TBE(0x15, 1);
    TBE(0x16, 1);
    TBE(0x17, 1);
    TBE(0x18, 1);
    TBE(0x19, 1);
    TBE(0x1A, 1);
    TBE(0x1B, 1);
    TBE(0x1C, 1);
    TBE(0x1D, 1);
    TBE(0x1E, 1);
    TBE(0x1F, 1);

    TBE(0x20, 0);
    TBE(0x21, 0);
    TBE(0x22, 0);

    TBE(0x23, 1);
    TBE(0x24, 1);
    TBE(0x25, 1);

    TBE(0x26, 0);
    TBE(0x27, 0);
    TBE(0x28, 0);
    TBE(0x29, 0);

    TBE(0x2A, 1);

    TBE(0x2B, 0);
    TBE(0x2C, 0);
    TBE(0x2D, 0);
    TBE(0x2E, 0);
    TBE(0x2F, 0);
    TBE(0x30, 0);
    TBE(0x31, 0);
    TBE(0x32, 0);
    TBE(0x33, 0);
    TBE(0x34, 0);
    TBE(0x35, 0);
    TBE(0x36, 0);
    TBE(0x37, 0);
    TBE(0x38, 0);
    TBE(0x39, 0);
    TBE(0x3A, 0);
    TBE(0x3B, 0);
    TBE(0x3C, 0);
    TBE(0x3D, 0);
    TBE(0x3E, 0);
    TBE(0x3F, 0);
    TBE(0x40, 0);
    TBE(0x41, 0);
    TBE(0x42, 0);
    TBE(0x43, 0);
    TBE(0x44, 0);
    TBE(0x45, 0);
    TBE(0x46, 0);
    TBE(0x47, 0);
    TBE(0x48, 0);
    TBE(0x49, 0);
    TBE(0x4A, 0);
    TBE(0x4B, 0);
    TBE(0x4C, 0);
    TBE(0x4D, 0);
    TBE(0x4E, 0);
    TBE(0x4F, 0);
    TBE(0x50, 0);
    TBE(0x51, 0);
    TBE(0x52, 0);
    TBE(0x53, 0);
    TBE(0x54, 0);
    TBE(0x55, 0);
    TBE(0x56, 0);
    TBE(0x57, 0);
    TBE(0x58, 0);
    TBE(0x59, 0);
    TBE(0x5A, 0);
    TBE(0x5B, 0);
    TBE(0x5C, 0);
    TBE(0x5D, 0);
    TBE(0x5E, 0);
    TBE(0x5F, 0);
    TBE(0x60, 0);
    TBE(0x61, 0);
    TBE(0x62, 0);
    TBE(0x63, 0);
    TBE(0x64, 0);
    TBE(0x65, 0);
    TBE(0x66, 0);
    TBE(0x67, 0);
    TBE(0x68, 0);
    TBE(0x69, 0);
    TBE(0x6A, 0);
    TBE(0x6B, 0);
    TBE(0x6C, 0);
    TBE(0x6D, 0);
    TBE(0x6E, 0);
    TBE(0x6F, 0);
    TBE(0x70, 0);
    TBE(0x71, 0);
    TBE(0x72, 0);
    TBE(0x73, 0);
    TBE(0x74, 0);
    TBE(0x75, 0);
    TBE(0x76, 0);
    TBE(0x77, 0);
    TBE(0x78, 0);
    TBE(0x79, 0);
    TBE(0x7A, 0);
    TBE(0x7B, 0);
    TBE(0x7C, 0);

    TBE(0x7D, 1);

    TBE(0x7E, 0);

    TBE(0x7F, 1);
    TBE(0x80, 1);
    TBE(0x81, 1);
    TBE(0x82, 1);
    TBE(0x83, 1);
    TBE(0x84, 1);
    TBE(0x85, 1);
    TBE(0x86, 1);
    TBE(0x87, 1);
    TBE(0x88, 1);
    TBE(0x89, 1);
    TBE(0x8A, 1);
    TBE(0x8B, 1);
    TBE(0x8C, 1);
    TBE(0x8D, 1);
    TBE(0x8E, 1);
    TBE(0x8F, 1);
    TBE(0x90, 1);
    TBE(0x91, 1);
    TBE(0x92, 1);
    TBE(0x93, 1);
    TBE(0x94, 1);
    TBE(0x95, 1);
    TBE(0x96, 1);
    TBE(0x97, 1);
    TBE(0x98, 1);
    TBE(0x99, 1);
    TBE(0x9A, 1);
    TBE(0x9B, 1);
    TBE(0x9C, 1);
    TBE(0x9D, 1);
    TBE(0x9E, 1);
    TBE(0x9F, 1);
    TBE(0xA0, 1);
    TBE(0xA1, 1);
    TBE(0xA2, 1);
    TBE(0xA3, 1);
    TBE(0xA4, 1);
    TBE(0xA5, 1);
    TBE(0xA6, 1);
    TBE(0xA7, 1);
    TBE(0xA8, 1);
    TBE(0xA9, 1);
    TBE(0xAA, 1);
    TBE(0xAB, 1);
    TBE(0xAC, 1);
    TBE(0xAD, 1);
    TBE(0xAE, 1);
    TBE(0xAF, 1);
    TBE(0xB0, 1);
    TBE(0xB1, 1);
    TBE(0xB2, 1);
    TBE(0xB3, 1);
    TBE(0xB4, 1);
    TBE(0xB5, 1);
    TBE(0xB6, 1);
    TBE(0xB7, 1);
    TBE(0xB8, 1);
    TBE(0xB9, 1);
    TBE(0xBA, 1);
    TBE(0xBB, 1);
    TBE(0xBC, 1);
    TBE(0xBD, 1);
    TBE(0xBE, 1);
    TBE(0xBF, 1);
    TBE(0xC0, 1);
    TBE(0xC1, 1);
    TBE(0xC2, 1);
    TBE(0xC3, 1);
    TBE(0xC4, 1);
    TBE(0xC5, 1);
    TBE(0xC6, 1);
    TBE(0xC7, 1);
    TBE(0xC8, 1);
    TBE(0xC9, 1);
    TBE(0xCA, 1);
    TBE(0xCB, 1);
    TBE(0xCC, 1);
    TBE(0xCD, 1);
    TBE(0xCE, 1);
    TBE(0xCF, 1);
    TBE(0xD0, 1);
    TBE(0xD1, 1);
    TBE(0xD2, 1);
    TBE(0xD3, 1);
    TBE(0xD4, 1);
    TBE(0xD5, 1);
    TBE(0xD6, 1);
    TBE(0xD7, 1);
    TBE(0xD8, 1);
    TBE(0xD9, 1);
    TBE(0xDA, 1);
    TBE(0xDB, 1);
    TBE(0xDC, 1);
    TBE(0xDD, 1);
    TBE(0xDE, 1);
    TBE(0xDF, 1);
    TBE(0xE0, 1);
    TBE(0xE1, 1);
    TBE(0xE2, 1);
    TBE(0xE3, 1);
    TBE(0xE4, 1);
    TBE(0xE5, 1);
    TBE(0xE6, 1);
    TBE(0xE7, 1);
    TBE(0xE8, 1);
    TBE(0xE9, 1);
    TBE(0xEA, 1);
    TBE(0xEB, 1);
    TBE(0xEC, 1);
    TBE(0xED, 1);
    TBE(0xEE, 1);
    TBE(0xEF, 1);
    TBE(0xF0, 1);
    TBE(0xF1, 1);
    TBE(0xF2, 1);
    TBE(0xF3, 1);
    TBE(0xF4, 1);
    TBE(0xF5, 1);
    TBE(0xF6, 1);
    TBE(0xF7, 1);
    TBE(0xF8, 1);
    TBE(0xF9, 1);
    TBE(0xFA, 1);
    TBE(0xFB, 1);
    TBE(0xFC, 1);
    TBE(0xFD, 1);
    TBE(0xFE, 1);
    TBE(0xFF, 1);
}

static void test_binary_decode(void)
{
#define TBD(v) TAP_OK(binary_decode((v)) == ((v) ^ 0x20), "Test 0x%02X", (v))

    TAP_DIAG("In %s", __func__);

/*
Python commands to help simplify generation:

for i in range(0, 256):
    print("    TBD(0x{:02X}, 1);".format(i))
*/

    TBD(0x00);
    TBD(0x01);
    TBD(0x02);
    TBD(0x03);
    TBD(0x04);
    TBD(0x05);
    TBD(0x06);
    TBD(0x07);
    TBD(0x08);
    TBD(0x09);
    TBD(0x0A);
    TBD(0x0B);
    TBD(0x0C);
    TBD(0x0D);
    TBD(0x0E);
    TBD(0x0F);
    TBD(0x10);
    TBD(0x11);
    TBD(0x12);
    TBD(0x13);
    TBD(0x14);
    TBD(0x15);
    TBD(0x16);
    TBD(0x17);
    TBD(0x18);
    TBD(0x19);
    TBD(0x1A);
    TBD(0x1B);
    TBD(0x1C);
    TBD(0x1D);
    TBD(0x1E);
    TBD(0x1F);

    TBD(0x23);
    TBD(0x24);
    TBD(0x25);

    TBD(0x2A);

    TBD(0x7D);

    TBD(0x7F);
    TBD(0x80);
    TBD(0x81);
    TBD(0x82);
    TBD(0x83);
    TBD(0x84);
    TBD(0x85);
    TBD(0x86);
    TBD(0x87);
    TBD(0x88);
    TBD(0x89);
    TBD(0x8A);
    TBD(0x8B);
    TBD(0x8C);
    TBD(0x8D);
    TBD(0x8E);
    TBD(0x8F);
    TBD(0x90);
    TBD(0x91);
    TBD(0x92);
    TBD(0x93);
    TBD(0x94);
    TBD(0x95);
    TBD(0x96);
    TBD(0x97);
    TBD(0x98);
    TBD(0x99);
    TBD(0x9A);
    TBD(0x9B);
    TBD(0x9C);
    TBD(0x9D);
    TBD(0x9E);
    TBD(0x9F);
    TBD(0xA0);
    TBD(0xA1);
    TBD(0xA2);
    TBD(0xA3);
    TBD(0xA4);
    TBD(0xA5);
    TBD(0xA6);
    TBD(0xA7);
    TBD(0xA8);
    TBD(0xA9);
    TBD(0xAA);
    TBD(0xAB);
    TBD(0xAC);
    TBD(0xAD);
    TBD(0xAE);
    TBD(0xAF);
    TBD(0xB0);
    TBD(0xB1);
    TBD(0xB2);
    TBD(0xB3);
    TBD(0xB4);
    TBD(0xB5);
    TBD(0xB6);
    TBD(0xB7);
    TBD(0xB8);
    TBD(0xB9);
    TBD(0xBA);
    TBD(0xBB);
    TBD(0xBC);
    TBD(0xBD);
    TBD(0xBE);
    TBD(0xBF);
    TBD(0xC0);
    TBD(0xC1);
    TBD(0xC2);
    TBD(0xC3);
    TBD(0xC4);
    TBD(0xC5);
    TBD(0xC6);
    TBD(0xC7);
    TBD(0xC8);
    TBD(0xC9);
    TBD(0xCA);
    TBD(0xCB);
    TBD(0xCC);
    TBD(0xCD);
    TBD(0xCE);
    TBD(0xCF);
    TBD(0xD0);
    TBD(0xD1);
    TBD(0xD2);
    TBD(0xD3);
    TBD(0xD4);
    TBD(0xD5);
    TBD(0xD6);
    TBD(0xD7);
    TBD(0xD8);
    TBD(0xD9);
    TBD(0xDA);
    TBD(0xDB);
    TBD(0xDC);
    TBD(0xDD);
    TBD(0xDE);
    TBD(0xDF);
    TBD(0xE0);
    TBD(0xE1);
    TBD(0xE2);
    TBD(0xE3);
    TBD(0xE4);
    TBD(0xE5);
    TBD(0xE6);
    TBD(0xE7);
    TBD(0xE8);
    TBD(0xE9);
    TBD(0xEA);
    TBD(0xEB);
    TBD(0xEC);
    TBD(0xED);
    TBD(0xEE);
    TBD(0xEF);
    TBD(0xF0);
    TBD(0xF1);
    TBD(0xF2);
    TBD(0xF3);
    TBD(0xF4);
    TBD(0xF5);
    TBD(0xF6);
    TBD(0xF7);
    TBD(0xF8);
    TBD(0xF9);
    TBD(0xFA);
    TBD(0xFB);
    TBD(0xFC);
    TBD(0xFD);
    TBD(0xFE);
    TBD(0xFF);
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_binary_encode();
    test_binary_decode();

    TAP_END_PLAN();
}
