/**
 *  @file       test_auxiliary_hex.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for hexadecimal conversion functions.
 */
#include "auxiliary/hex.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

static const unsigned long TEST_COUNT = 256 + 22 + 16 + 256;

static void test_hex_digit_to_byte(void)
{
    TAP_DIAG("In %s", __func__);

    TAP_DIAG("Test all valid hex_digit_to_byte inputs");
    TAP_OK(hex_digit_to_byte('0') == 0x0, "Test '0'");
    TAP_OK(hex_digit_to_byte('1') == 0x1, "Test '1'");
    TAP_OK(hex_digit_to_byte('2') == 0x2, "Test '2'");
    TAP_OK(hex_digit_to_byte('3') == 0x3, "Test '3'");
    TAP_OK(hex_digit_to_byte('4') == 0x4, "Test '4'");
    TAP_OK(hex_digit_to_byte('5') == 0x5, "Test '5'");
    TAP_OK(hex_digit_to_byte('6') == 0x6, "Test '6'");
    TAP_OK(hex_digit_to_byte('7') == 0x7, "Test '7'");
    TAP_OK(hex_digit_to_byte('8') == 0x8, "Test '8'");
    TAP_OK(hex_digit_to_byte('9') == 0x9, "Test '9'");
    TAP_OK(hex_digit_to_byte('a') == 0xA, "Test 'a'");
    TAP_OK(hex_digit_to_byte('b') == 0xB, "Test 'b'");
    TAP_OK(hex_digit_to_byte('c') == 0xC, "Test 'c'");
    TAP_OK(hex_digit_to_byte('d') == 0xD, "Test 'd'");
    TAP_OK(hex_digit_to_byte('e') == 0xE, "Test 'e'");
    TAP_OK(hex_digit_to_byte('f') == 0xF, "Test 'f'");
    TAP_OK(hex_digit_to_byte('A') == 0xA, "Test 'A'");
    TAP_OK(hex_digit_to_byte('B') == 0xB, "Test 'B'");
    TAP_OK(hex_digit_to_byte('C') == 0xC, "Test 'C'");
    TAP_OK(hex_digit_to_byte('D') == 0xD, "Test 'D'");
    TAP_OK(hex_digit_to_byte('E') == 0xE, "Test 'E'");
    TAP_OK(hex_digit_to_byte('F') == 0xF, "Test 'F'");

    TAP_DIAG("Test all invalid hex_digit_to_byte inputs");
    TAP_OK(hex_digit_to_byte(0x00) > 0xF, "Test 0x00");
    TAP_OK(hex_digit_to_byte(0x01) > 0xF, "Test 0x01");
    TAP_OK(hex_digit_to_byte(0x02) > 0xF, "Test 0x02");
    TAP_OK(hex_digit_to_byte(0x03) > 0xF, "Test 0x03");
    TAP_OK(hex_digit_to_byte(0x04) > 0xF, "Test 0x04");
    TAP_OK(hex_digit_to_byte(0x05) > 0xF, "Test 0x05");
    TAP_OK(hex_digit_to_byte(0x06) > 0xF, "Test 0x06");
    TAP_OK(hex_digit_to_byte(0x07) > 0xF, "Test 0x07");
    TAP_OK(hex_digit_to_byte(0x08) > 0xF, "Test 0x08");
    TAP_OK(hex_digit_to_byte(0x09) > 0xF, "Test 0x09");
    TAP_OK(hex_digit_to_byte(0x0A) > 0xF, "Test 0x0A");
    TAP_OK(hex_digit_to_byte(0x0B) > 0xF, "Test 0x0B");
    TAP_OK(hex_digit_to_byte(0x0C) > 0xF, "Test 0x0C");
    TAP_OK(hex_digit_to_byte(0x0D) > 0xF, "Test 0x0D");
    TAP_OK(hex_digit_to_byte(0x0E) > 0xF, "Test 0x0E");
    TAP_OK(hex_digit_to_byte(0x0F) > 0xF, "Test 0x0F");
    TAP_OK(hex_digit_to_byte(0x10) > 0xF, "Test 0x10");
    TAP_OK(hex_digit_to_byte(0x11) > 0xF, "Test 0x11");
    TAP_OK(hex_digit_to_byte(0x12) > 0xF, "Test 0x12");
    TAP_OK(hex_digit_to_byte(0x13) > 0xF, "Test 0x13");
    TAP_OK(hex_digit_to_byte(0x14) > 0xF, "Test 0x14");
    TAP_OK(hex_digit_to_byte(0x15) > 0xF, "Test 0x15");
    TAP_OK(hex_digit_to_byte(0x16) > 0xF, "Test 0x16");
    TAP_OK(hex_digit_to_byte(0x17) > 0xF, "Test 0x17");
    TAP_OK(hex_digit_to_byte(0x18) > 0xF, "Test 0x18");
    TAP_OK(hex_digit_to_byte(0x19) > 0xF, "Test 0x19");
    TAP_OK(hex_digit_to_byte(0x1A) > 0xF, "Test 0x1A");
    TAP_OK(hex_digit_to_byte(0x1B) > 0xF, "Test 0x1B");
    TAP_OK(hex_digit_to_byte(0x1C) > 0xF, "Test 0x1C");
    TAP_OK(hex_digit_to_byte(0x1D) > 0xF, "Test 0x1D");
    TAP_OK(hex_digit_to_byte(0x1E) > 0xF, "Test 0x1E");
    TAP_OK(hex_digit_to_byte(0x1F) > 0xF, "Test 0x1F");
    TAP_OK(hex_digit_to_byte(0x20) > 0xF, "Test 0x20");
    TAP_OK(hex_digit_to_byte(0x21) > 0xF, "Test 0x21");
    TAP_OK(hex_digit_to_byte(0x22) > 0xF, "Test 0x22");
    TAP_OK(hex_digit_to_byte(0x23) > 0xF, "Test 0x23");
    TAP_OK(hex_digit_to_byte(0x24) > 0xF, "Test 0x24");
    TAP_OK(hex_digit_to_byte(0x25) > 0xF, "Test 0x25");
    TAP_OK(hex_digit_to_byte(0x26) > 0xF, "Test 0x26");
    TAP_OK(hex_digit_to_byte(0x27) > 0xF, "Test 0x27");
    TAP_OK(hex_digit_to_byte(0x28) > 0xF, "Test 0x28");
    TAP_OK(hex_digit_to_byte(0x29) > 0xF, "Test 0x29");
    TAP_OK(hex_digit_to_byte(0x2A) > 0xF, "Test 0x2A");
    TAP_OK(hex_digit_to_byte(0x2B) > 0xF, "Test 0x2B");
    TAP_OK(hex_digit_to_byte(0x2C) > 0xF, "Test 0x2C");
    TAP_OK(hex_digit_to_byte(0x2D) > 0xF, "Test 0x2D");
    TAP_OK(hex_digit_to_byte(0x2E) > 0xF, "Test 0x2E");
    TAP_OK(hex_digit_to_byte(0x2F) > 0xF, "Test 0x2F");

    TAP_OK(hex_digit_to_byte(0x3A) > 0xF, "Test 0x3A");
    TAP_OK(hex_digit_to_byte(0x3B) > 0xF, "Test 0x3B");
    TAP_OK(hex_digit_to_byte(0x3C) > 0xF, "Test 0x3C");
    TAP_OK(hex_digit_to_byte(0x3D) > 0xF, "Test 0x3D");
    TAP_OK(hex_digit_to_byte(0x3E) > 0xF, "Test 0x3E");
    TAP_OK(hex_digit_to_byte(0x3F) > 0xF, "Test 0x3F");
    TAP_OK(hex_digit_to_byte(0x40) > 0xF, "Test 0x40");

    TAP_OK(hex_digit_to_byte(0x47) > 0xF, "Test 0x47");
    TAP_OK(hex_digit_to_byte(0x48) > 0xF, "Test 0x48");
    TAP_OK(hex_digit_to_byte(0x49) > 0xF, "Test 0x49");
    TAP_OK(hex_digit_to_byte(0x4A) > 0xF, "Test 0x4A");
    TAP_OK(hex_digit_to_byte(0x4B) > 0xF, "Test 0x4B");
    TAP_OK(hex_digit_to_byte(0x4C) > 0xF, "Test 0x4C");
    TAP_OK(hex_digit_to_byte(0x4D) > 0xF, "Test 0x4D");
    TAP_OK(hex_digit_to_byte(0x4E) > 0xF, "Test 0x4E");
    TAP_OK(hex_digit_to_byte(0x4F) > 0xF, "Test 0x4F");
    TAP_OK(hex_digit_to_byte(0x50) > 0xF, "Test 0x50");
    TAP_OK(hex_digit_to_byte(0x51) > 0xF, "Test 0x51");
    TAP_OK(hex_digit_to_byte(0x52) > 0xF, "Test 0x52");
    TAP_OK(hex_digit_to_byte(0x53) > 0xF, "Test 0x53");
    TAP_OK(hex_digit_to_byte(0x54) > 0xF, "Test 0x54");
    TAP_OK(hex_digit_to_byte(0x55) > 0xF, "Test 0x55");
    TAP_OK(hex_digit_to_byte(0x56) > 0xF, "Test 0x56");
    TAP_OK(hex_digit_to_byte(0x57) > 0xF, "Test 0x57");
    TAP_OK(hex_digit_to_byte(0x58) > 0xF, "Test 0x58");
    TAP_OK(hex_digit_to_byte(0x59) > 0xF, "Test 0x59");
    TAP_OK(hex_digit_to_byte(0x5A) > 0xF, "Test 0x5A");
    TAP_OK(hex_digit_to_byte(0x5B) > 0xF, "Test 0x5B");
    TAP_OK(hex_digit_to_byte(0x5C) > 0xF, "Test 0x5C");
    TAP_OK(hex_digit_to_byte(0x5D) > 0xF, "Test 0x5D");
    TAP_OK(hex_digit_to_byte(0x5E) > 0xF, "Test 0x5E");
    TAP_OK(hex_digit_to_byte(0x5F) > 0xF, "Test 0x5F");
    TAP_OK(hex_digit_to_byte(0x60) > 0xF, "Test 0x60");

    TAP_OK(hex_digit_to_byte(0x67) > 0xF, "Test 0x67");
    TAP_OK(hex_digit_to_byte(0x68) > 0xF, "Test 0x68");
    TAP_OK(hex_digit_to_byte(0x69) > 0xF, "Test 0x69");
    TAP_OK(hex_digit_to_byte(0x6A) > 0xF, "Test 0x6A");
    TAP_OK(hex_digit_to_byte(0x6B) > 0xF, "Test 0x6B");
    TAP_OK(hex_digit_to_byte(0x6C) > 0xF, "Test 0x6C");
    TAP_OK(hex_digit_to_byte(0x6D) > 0xF, "Test 0x6D");
    TAP_OK(hex_digit_to_byte(0x6E) > 0xF, "Test 0x6E");
    TAP_OK(hex_digit_to_byte(0x6F) > 0xF, "Test 0x6F");
    TAP_OK(hex_digit_to_byte(0x70) > 0xF, "Test 0x70");
    TAP_OK(hex_digit_to_byte(0x71) > 0xF, "Test 0x71");
    TAP_OK(hex_digit_to_byte(0x72) > 0xF, "Test 0x72");
    TAP_OK(hex_digit_to_byte(0x73) > 0xF, "Test 0x73");
    TAP_OK(hex_digit_to_byte(0x74) > 0xF, "Test 0x74");
    TAP_OK(hex_digit_to_byte(0x75) > 0xF, "Test 0x75");
    TAP_OK(hex_digit_to_byte(0x76) > 0xF, "Test 0x76");
    TAP_OK(hex_digit_to_byte(0x77) > 0xF, "Test 0x77");
    TAP_OK(hex_digit_to_byte(0x78) > 0xF, "Test 0x78");
    TAP_OK(hex_digit_to_byte(0x79) > 0xF, "Test 0x79");
    TAP_OK(hex_digit_to_byte(0x7A) > 0xF, "Test 0x7A");
    TAP_OK(hex_digit_to_byte(0x7B) > 0xF, "Test 0x7B");
    TAP_OK(hex_digit_to_byte(0x7C) > 0xF, "Test 0x7C");
    TAP_OK(hex_digit_to_byte(0x7D) > 0xF, "Test 0x7D");
    TAP_OK(hex_digit_to_byte(0x7E) > 0xF, "Test 0x7E");
    TAP_OK(hex_digit_to_byte(0x7F) > 0xF, "Test 0x7F");
    TAP_OK(hex_digit_to_byte(0x80) > 0xF, "Test 0x80");
    TAP_OK(hex_digit_to_byte(0x81) > 0xF, "Test 0x81");
    TAP_OK(hex_digit_to_byte(0x82) > 0xF, "Test 0x82");
    TAP_OK(hex_digit_to_byte(0x83) > 0xF, "Test 0x83");
    TAP_OK(hex_digit_to_byte(0x84) > 0xF, "Test 0x84");
    TAP_OK(hex_digit_to_byte(0x85) > 0xF, "Test 0x85");
    TAP_OK(hex_digit_to_byte(0x86) > 0xF, "Test 0x86");
    TAP_OK(hex_digit_to_byte(0x87) > 0xF, "Test 0x87");
    TAP_OK(hex_digit_to_byte(0x88) > 0xF, "Test 0x88");
    TAP_OK(hex_digit_to_byte(0x89) > 0xF, "Test 0x89");
    TAP_OK(hex_digit_to_byte(0x8A) > 0xF, "Test 0x8A");
    TAP_OK(hex_digit_to_byte(0x8B) > 0xF, "Test 0x8B");
    TAP_OK(hex_digit_to_byte(0x8C) > 0xF, "Test 0x8C");
    TAP_OK(hex_digit_to_byte(0x8D) > 0xF, "Test 0x8D");
    TAP_OK(hex_digit_to_byte(0x8E) > 0xF, "Test 0x8E");
    TAP_OK(hex_digit_to_byte(0x8F) > 0xF, "Test 0x8F");
    TAP_OK(hex_digit_to_byte(0x90) > 0xF, "Test 0x90");
    TAP_OK(hex_digit_to_byte(0x91) > 0xF, "Test 0x91");
    TAP_OK(hex_digit_to_byte(0x92) > 0xF, "Test 0x92");
    TAP_OK(hex_digit_to_byte(0x93) > 0xF, "Test 0x93");
    TAP_OK(hex_digit_to_byte(0x94) > 0xF, "Test 0x94");
    TAP_OK(hex_digit_to_byte(0x95) > 0xF, "Test 0x95");
    TAP_OK(hex_digit_to_byte(0x96) > 0xF, "Test 0x96");
    TAP_OK(hex_digit_to_byte(0x97) > 0xF, "Test 0x97");
    TAP_OK(hex_digit_to_byte(0x98) > 0xF, "Test 0x98");
    TAP_OK(hex_digit_to_byte(0x99) > 0xF, "Test 0x99");
    TAP_OK(hex_digit_to_byte(0x9A) > 0xF, "Test 0x9A");
    TAP_OK(hex_digit_to_byte(0x9B) > 0xF, "Test 0x9B");
    TAP_OK(hex_digit_to_byte(0x9C) > 0xF, "Test 0x9C");
    TAP_OK(hex_digit_to_byte(0x9D) > 0xF, "Test 0x9D");
    TAP_OK(hex_digit_to_byte(0x9E) > 0xF, "Test 0x9E");
    TAP_OK(hex_digit_to_byte(0x9F) > 0xF, "Test 0x9F");
    TAP_OK(hex_digit_to_byte(0xA0) > 0xF, "Test 0xA0");
    TAP_OK(hex_digit_to_byte(0xA1) > 0xF, "Test 0xA1");
    TAP_OK(hex_digit_to_byte(0xA2) > 0xF, "Test 0xA2");
    TAP_OK(hex_digit_to_byte(0xA3) > 0xF, "Test 0xA3");
    TAP_OK(hex_digit_to_byte(0xA4) > 0xF, "Test 0xA4");
    TAP_OK(hex_digit_to_byte(0xA5) > 0xF, "Test 0xA5");
    TAP_OK(hex_digit_to_byte(0xA6) > 0xF, "Test 0xA6");
    TAP_OK(hex_digit_to_byte(0xA7) > 0xF, "Test 0xA7");
    TAP_OK(hex_digit_to_byte(0xA8) > 0xF, "Test 0xA8");
    TAP_OK(hex_digit_to_byte(0xA9) > 0xF, "Test 0xA9");
    TAP_OK(hex_digit_to_byte(0xAA) > 0xF, "Test 0xAA");
    TAP_OK(hex_digit_to_byte(0xAB) > 0xF, "Test 0xAB");
    TAP_OK(hex_digit_to_byte(0xAC) > 0xF, "Test 0xAC");
    TAP_OK(hex_digit_to_byte(0xAD) > 0xF, "Test 0xAD");
    TAP_OK(hex_digit_to_byte(0xAE) > 0xF, "Test 0xAE");
    TAP_OK(hex_digit_to_byte(0xAF) > 0xF, "Test 0xAF");
    TAP_OK(hex_digit_to_byte(0xB0) > 0xF, "Test 0xB0");
    TAP_OK(hex_digit_to_byte(0xB1) > 0xF, "Test 0xB1");
    TAP_OK(hex_digit_to_byte(0xB2) > 0xF, "Test 0xB2");
    TAP_OK(hex_digit_to_byte(0xB3) > 0xF, "Test 0xB3");
    TAP_OK(hex_digit_to_byte(0xB4) > 0xF, "Test 0xB4");
    TAP_OK(hex_digit_to_byte(0xB5) > 0xF, "Test 0xB5");
    TAP_OK(hex_digit_to_byte(0xB6) > 0xF, "Test 0xB6");
    TAP_OK(hex_digit_to_byte(0xB7) > 0xF, "Test 0xB7");
    TAP_OK(hex_digit_to_byte(0xB8) > 0xF, "Test 0xB8");
    TAP_OK(hex_digit_to_byte(0xB9) > 0xF, "Test 0xB9");
    TAP_OK(hex_digit_to_byte(0xBA) > 0xF, "Test 0xBA");
    TAP_OK(hex_digit_to_byte(0xBB) > 0xF, "Test 0xBB");
    TAP_OK(hex_digit_to_byte(0xBC) > 0xF, "Test 0xBC");
    TAP_OK(hex_digit_to_byte(0xBD) > 0xF, "Test 0xBD");
    TAP_OK(hex_digit_to_byte(0xBE) > 0xF, "Test 0xBE");
    TAP_OK(hex_digit_to_byte(0xBF) > 0xF, "Test 0xBF");
    TAP_OK(hex_digit_to_byte(0xC0) > 0xF, "Test 0xC0");
    TAP_OK(hex_digit_to_byte(0xC1) > 0xF, "Test 0xC1");
    TAP_OK(hex_digit_to_byte(0xC2) > 0xF, "Test 0xC2");
    TAP_OK(hex_digit_to_byte(0xC3) > 0xF, "Test 0xC3");
    TAP_OK(hex_digit_to_byte(0xC4) > 0xF, "Test 0xC4");
    TAP_OK(hex_digit_to_byte(0xC5) > 0xF, "Test 0xC5");
    TAP_OK(hex_digit_to_byte(0xC6) > 0xF, "Test 0xC6");
    TAP_OK(hex_digit_to_byte(0xC7) > 0xF, "Test 0xC7");
    TAP_OK(hex_digit_to_byte(0xC8) > 0xF, "Test 0xC8");
    TAP_OK(hex_digit_to_byte(0xC9) > 0xF, "Test 0xC9");
    TAP_OK(hex_digit_to_byte(0xCA) > 0xF, "Test 0xCA");
    TAP_OK(hex_digit_to_byte(0xCB) > 0xF, "Test 0xCB");
    TAP_OK(hex_digit_to_byte(0xCC) > 0xF, "Test 0xCC");
    TAP_OK(hex_digit_to_byte(0xCD) > 0xF, "Test 0xCD");
    TAP_OK(hex_digit_to_byte(0xCE) > 0xF, "Test 0xCE");
    TAP_OK(hex_digit_to_byte(0xCF) > 0xF, "Test 0xCF");
    TAP_OK(hex_digit_to_byte(0xD0) > 0xF, "Test 0xD0");
    TAP_OK(hex_digit_to_byte(0xD1) > 0xF, "Test 0xD1");
    TAP_OK(hex_digit_to_byte(0xD2) > 0xF, "Test 0xD2");
    TAP_OK(hex_digit_to_byte(0xD3) > 0xF, "Test 0xD3");
    TAP_OK(hex_digit_to_byte(0xD4) > 0xF, "Test 0xD4");
    TAP_OK(hex_digit_to_byte(0xD5) > 0xF, "Test 0xD5");
    TAP_OK(hex_digit_to_byte(0xD6) > 0xF, "Test 0xD6");
    TAP_OK(hex_digit_to_byte(0xD7) > 0xF, "Test 0xD7");
    TAP_OK(hex_digit_to_byte(0xD8) > 0xF, "Test 0xD8");
    TAP_OK(hex_digit_to_byte(0xD9) > 0xF, "Test 0xD9");
    TAP_OK(hex_digit_to_byte(0xDA) > 0xF, "Test 0xDA");
    TAP_OK(hex_digit_to_byte(0xDB) > 0xF, "Test 0xDB");
    TAP_OK(hex_digit_to_byte(0xDC) > 0xF, "Test 0xDC");
    TAP_OK(hex_digit_to_byte(0xDD) > 0xF, "Test 0xDD");
    TAP_OK(hex_digit_to_byte(0xDE) > 0xF, "Test 0xDE");
    TAP_OK(hex_digit_to_byte(0xDF) > 0xF, "Test 0xDF");
    TAP_OK(hex_digit_to_byte(0xE0) > 0xF, "Test 0xE0");
    TAP_OK(hex_digit_to_byte(0xE1) > 0xF, "Test 0xE1");
    TAP_OK(hex_digit_to_byte(0xE2) > 0xF, "Test 0xE2");
    TAP_OK(hex_digit_to_byte(0xE3) > 0xF, "Test 0xE3");
    TAP_OK(hex_digit_to_byte(0xE4) > 0xF, "Test 0xE4");
    TAP_OK(hex_digit_to_byte(0xE5) > 0xF, "Test 0xE5");
    TAP_OK(hex_digit_to_byte(0xE6) > 0xF, "Test 0xE6");
    TAP_OK(hex_digit_to_byte(0xE7) > 0xF, "Test 0xE7");
    TAP_OK(hex_digit_to_byte(0xE8) > 0xF, "Test 0xE8");
    TAP_OK(hex_digit_to_byte(0xE9) > 0xF, "Test 0xE9");
    TAP_OK(hex_digit_to_byte(0xEA) > 0xF, "Test 0xEA");
    TAP_OK(hex_digit_to_byte(0xEB) > 0xF, "Test 0xEB");
    TAP_OK(hex_digit_to_byte(0xEC) > 0xF, "Test 0xEC");
    TAP_OK(hex_digit_to_byte(0xED) > 0xF, "Test 0xED");
    TAP_OK(hex_digit_to_byte(0xEE) > 0xF, "Test 0xEE");
    TAP_OK(hex_digit_to_byte(0xEF) > 0xF, "Test 0xEF");
    TAP_OK(hex_digit_to_byte(0xF0) > 0xF, "Test 0xF0");
    TAP_OK(hex_digit_to_byte(0xF1) > 0xF, "Test 0xF1");
    TAP_OK(hex_digit_to_byte(0xF2) > 0xF, "Test 0xF2");
    TAP_OK(hex_digit_to_byte(0xF3) > 0xF, "Test 0xF3");
    TAP_OK(hex_digit_to_byte(0xF4) > 0xF, "Test 0xF4");
    TAP_OK(hex_digit_to_byte(0xF5) > 0xF, "Test 0xF5");
    TAP_OK(hex_digit_to_byte(0xF6) > 0xF, "Test 0xF6");
    TAP_OK(hex_digit_to_byte(0xF7) > 0xF, "Test 0xF7");
    TAP_OK(hex_digit_to_byte(0xF8) > 0xF, "Test 0xF8");
    TAP_OK(hex_digit_to_byte(0xF9) > 0xF, "Test 0xF9");
    TAP_OK(hex_digit_to_byte(0xFA) > 0xF, "Test 0xFA");
    TAP_OK(hex_digit_to_byte(0xFB) > 0xF, "Test 0xFB");
    TAP_OK(hex_digit_to_byte(0xFC) > 0xF, "Test 0xFC");
    TAP_OK(hex_digit_to_byte(0xFD) > 0xF, "Test 0xFD");
    TAP_OK(hex_digit_to_byte(0xFE) > 0xF, "Test 0xFE");
    TAP_OK(hex_digit_to_byte(0xFF) > 0xF, "Test 0xFF");
}

static void test_hex_octet_to_byte(void)
{
    unsigned char byte;

    TAP_DIAG("In %s", __func__);

    TAP_DIAG("Test some invalid hex_octet_to_byte inputs");
    TAP_OK(hex_octet_to_byte("", &byte) == -GDBS_ERROR_INVALID, "Empty string");
    TAP_OK(hex_octet_to_byte("1", &byte) == -GDBS_ERROR_INVALID, "Truncated string");
    TAP_OK(hex_octet_to_byte("hi", &byte) == -GDBS_ERROR_INVALID, "Invalid string");
    TAP_OK(hex_octet_to_byte("5i", &byte) == -GDBS_ERROR_INVALID, "Another invalid string");

    TAP_DIAG("Test some valid hex_octet_to_byte inputs");
    TAP_OK(hex_octet_to_byte("ab", &byte) == GDBS_ERROR_OK && byte == 0xAB, "Lower case string");
    TAP_OK(hex_octet_to_byte("AB", &byte) == GDBS_ERROR_OK && byte == 0xAB, "Upper case string");
    TAP_OK(hex_octet_to_byte("aB", &byte) == GDBS_ERROR_OK && byte == 0xAB, "Mixed case string");
    TAP_OK(hex_octet_to_byte("1254", &byte) == GDBS_ERROR_OK && byte == 0x12, "Longer string");
    TAP_OK(hex_octet_to_byte("71z", &byte) == GDBS_ERROR_OK && byte == 0x71,
           "Another longer string");
    TAP_OK(hex_octet_to_byte("7AZ5", &byte) == GDBS_ERROR_OK && byte == 0x7A,
           "Third longer string");
    TAP_OK(hex_octet_to_byte("00", &byte) == GDBS_ERROR_OK && byte == 0x00, "Test 00");
    TAP_OK(hex_octet_to_byte("01", &byte) == GDBS_ERROR_OK && byte == 0x01, "Test 01");
    TAP_OK(hex_octet_to_byte("10", &byte) == GDBS_ERROR_OK && byte == 0x10, "Test 10");
    TAP_OK(hex_octet_to_byte("a7", &byte) == GDBS_ERROR_OK && byte == 0xA7, "Test a7");
    TAP_OK(hex_octet_to_byte("FF", &byte) == GDBS_ERROR_OK && byte == 0xFF, "Test FF");
    TAP_OK(hex_octet_to_byte("50", &byte) == GDBS_ERROR_OK && byte == 0x50, "Test 50");
    TAP_OK(hex_octet_to_byte("80", &byte) == GDBS_ERROR_OK && byte == 0x80, "Test 80");
    TAP_OK(hex_octet_to_byte("08", &byte) == GDBS_ERROR_OK && byte == 0x08, "Test 08");
    TAP_OK(hex_octet_to_byte("F0", &byte) == GDBS_ERROR_OK && byte == 0xF0, "Test F0");
    TAP_OK(hex_octet_to_byte("0F", &byte) == GDBS_ERROR_OK && byte == 0x0F, "Test 0F");
    TAP_OK(hex_octet_to_byte("93", &byte) == GDBS_ERROR_OK && byte == 0x93, "Test 93");
    TAP_OK(hex_octet_to_byte("44", &byte) == GDBS_ERROR_OK && byte == 0x44, "Test 44");
}

static void test_nibble_to_hex_digit(void)
{
    TAP_DIAG("In %s", __func__);

    TAP_OK(nibble_to_hex_digit(0x00) == '0', "Test 0x00");
    TAP_OK(nibble_to_hex_digit(0x01) == '1', "Test 0x01");
    TAP_OK(nibble_to_hex_digit(0x02) == '2', "Test 0x02");
    TAP_OK(nibble_to_hex_digit(0x03) == '3', "Test 0x03");
    TAP_OK(nibble_to_hex_digit(0x04) == '4', "Test 0x04");
    TAP_OK(nibble_to_hex_digit(0x05) == '5', "Test 0x05");
    TAP_OK(nibble_to_hex_digit(0x06) == '6', "Test 0x06");
    TAP_OK(nibble_to_hex_digit(0x07) == '7', "Test 0x07");
    TAP_OK(nibble_to_hex_digit(0x08) == '8', "Test 0x08");
    TAP_OK(nibble_to_hex_digit(0x09) == '9', "Test 0x09");
    TAP_OK(nibble_to_hex_digit(0x0A) == 'A', "Test 0x0A");
    TAP_OK(nibble_to_hex_digit(0x0B) == 'B', "Test 0x0B");
    TAP_OK(nibble_to_hex_digit(0x0C) == 'C', "Test 0x0C");
    TAP_OK(nibble_to_hex_digit(0x0D) == 'D', "Test 0x0D");
    TAP_OK(nibble_to_hex_digit(0x0E) == 'E', "Test 0x0E");
    TAP_OK(nibble_to_hex_digit(0x0F) == 'F', "Test 0x0F");
}

static void test_byte_to_hex_octet(void)
{
    char buffer[4];

#define TBTHO(b, e, d)                                                          \
    do                                                                          \
    {                                                                           \
        buffer[0] = '\0';                                                       \
        buffer[1] = '\0';                                                       \
        buffer[2] = '#';                                                        \
        buffer[3] = '\0';                                                       \
        byte_to_hex_octet((b), buffer);                                         \
        TAP_OK(strncmp(buffer, e "#", sizeof(buffer)) == 0, d " '%s'", buffer); \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TBTHO(0x00, "00", "Test 0x00");
    TBTHO(0x01, "01", "Test 0x01");
    TBTHO(0x02, "02", "Test 0x02");
    TBTHO(0x03, "03", "Test 0x03");
    TBTHO(0x04, "04", "Test 0x04");
    TBTHO(0x05, "05", "Test 0x05");
    TBTHO(0x06, "06", "Test 0x06");
    TBTHO(0x07, "07", "Test 0x07");
    TBTHO(0x08, "08", "Test 0x08");
    TBTHO(0x09, "09", "Test 0x09");
    TBTHO(0x0A, "0A", "Test 0x0A");
    TBTHO(0x0B, "0B", "Test 0x0B");
    TBTHO(0x0C, "0C", "Test 0x0C");
    TBTHO(0x0D, "0D", "Test 0x0D");
    TBTHO(0x0E, "0E", "Test 0x0E");
    TBTHO(0x0F, "0F", "Test 0x0F");
    TBTHO(0x10, "10", "Test 0x10");
    TBTHO(0x11, "11", "Test 0x11");
    TBTHO(0x12, "12", "Test 0x12");
    TBTHO(0x13, "13", "Test 0x13");
    TBTHO(0x14, "14", "Test 0x14");
    TBTHO(0x15, "15", "Test 0x15");
    TBTHO(0x16, "16", "Test 0x16");
    TBTHO(0x17, "17", "Test 0x17");
    TBTHO(0x18, "18", "Test 0x18");
    TBTHO(0x19, "19", "Test 0x19");
    TBTHO(0x1A, "1A", "Test 0x1A");
    TBTHO(0x1B, "1B", "Test 0x1B");
    TBTHO(0x1C, "1C", "Test 0x1C");
    TBTHO(0x1D, "1D", "Test 0x1D");
    TBTHO(0x1E, "1E", "Test 0x1E");
    TBTHO(0x1F, "1F", "Test 0x1F");
    TBTHO(0x20, "20", "Test 0x20");
    TBTHO(0x21, "21", "Test 0x21");
    TBTHO(0x22, "22", "Test 0x22");
    TBTHO(0x23, "23", "Test 0x23");
    TBTHO(0x24, "24", "Test 0x24");
    TBTHO(0x25, "25", "Test 0x25");
    TBTHO(0x26, "26", "Test 0x26");
    TBTHO(0x27, "27", "Test 0x27");
    TBTHO(0x28, "28", "Test 0x28");
    TBTHO(0x29, "29", "Test 0x29");
    TBTHO(0x2A, "2A", "Test 0x2A");
    TBTHO(0x2B, "2B", "Test 0x2B");
    TBTHO(0x2C, "2C", "Test 0x2C");
    TBTHO(0x2D, "2D", "Test 0x2D");
    TBTHO(0x2E, "2E", "Test 0x2E");
    TBTHO(0x2F, "2F", "Test 0x2F");
    TBTHO(0x30, "30", "Test 0x30");
    TBTHO(0x31, "31", "Test 0x31");
    TBTHO(0x32, "32", "Test 0x32");
    TBTHO(0x33, "33", "Test 0x33");
    TBTHO(0x34, "34", "Test 0x34");
    TBTHO(0x35, "35", "Test 0x35");
    TBTHO(0x36, "36", "Test 0x36");
    TBTHO(0x37, "37", "Test 0x37");
    TBTHO(0x38, "38", "Test 0x38");
    TBTHO(0x39, "39", "Test 0x39");
    TBTHO(0x3A, "3A", "Test 0x3A");
    TBTHO(0x3B, "3B", "Test 0x3B");
    TBTHO(0x3C, "3C", "Test 0x3C");
    TBTHO(0x3D, "3D", "Test 0x3D");
    TBTHO(0x3E, "3E", "Test 0x3E");
    TBTHO(0x3F, "3F", "Test 0x3F");
    TBTHO(0x40, "40", "Test 0x40");
    TBTHO(0x41, "41", "Test 0x41");
    TBTHO(0x42, "42", "Test 0x42");
    TBTHO(0x43, "43", "Test 0x43");
    TBTHO(0x44, "44", "Test 0x44");
    TBTHO(0x45, "45", "Test 0x45");
    TBTHO(0x46, "46", "Test 0x46");
    TBTHO(0x47, "47", "Test 0x47");
    TBTHO(0x48, "48", "Test 0x48");
    TBTHO(0x49, "49", "Test 0x49");
    TBTHO(0x4A, "4A", "Test 0x4A");
    TBTHO(0x4B, "4B", "Test 0x4B");
    TBTHO(0x4C, "4C", "Test 0x4C");
    TBTHO(0x4D, "4D", "Test 0x4D");
    TBTHO(0x4E, "4E", "Test 0x4E");
    TBTHO(0x4F, "4F", "Test 0x4F");
    TBTHO(0x50, "50", "Test 0x50");
    TBTHO(0x51, "51", "Test 0x51");
    TBTHO(0x52, "52", "Test 0x52");
    TBTHO(0x53, "53", "Test 0x53");
    TBTHO(0x54, "54", "Test 0x54");
    TBTHO(0x55, "55", "Test 0x55");
    TBTHO(0x56, "56", "Test 0x56");
    TBTHO(0x57, "57", "Test 0x57");
    TBTHO(0x58, "58", "Test 0x58");
    TBTHO(0x59, "59", "Test 0x59");
    TBTHO(0x5A, "5A", "Test 0x5A");
    TBTHO(0x5B, "5B", "Test 0x5B");
    TBTHO(0x5C, "5C", "Test 0x5C");
    TBTHO(0x5D, "5D", "Test 0x5D");
    TBTHO(0x5E, "5E", "Test 0x5E");
    TBTHO(0x5F, "5F", "Test 0x5F");
    TBTHO(0x60, "60", "Test 0x60");
    TBTHO(0x61, "61", "Test 0x61");
    TBTHO(0x62, "62", "Test 0x62");
    TBTHO(0x63, "63", "Test 0x63");
    TBTHO(0x64, "64", "Test 0x64");
    TBTHO(0x65, "65", "Test 0x65");
    TBTHO(0x66, "66", "Test 0x66");
    TBTHO(0x67, "67", "Test 0x67");
    TBTHO(0x68, "68", "Test 0x68");
    TBTHO(0x69, "69", "Test 0x69");
    TBTHO(0x6A, "6A", "Test 0x6A");
    TBTHO(0x6B, "6B", "Test 0x6B");
    TBTHO(0x6C, "6C", "Test 0x6C");
    TBTHO(0x6D, "6D", "Test 0x6D");
    TBTHO(0x6E, "6E", "Test 0x6E");
    TBTHO(0x6F, "6F", "Test 0x6F");
    TBTHO(0x70, "70", "Test 0x70");
    TBTHO(0x71, "71", "Test 0x71");
    TBTHO(0x72, "72", "Test 0x72");
    TBTHO(0x73, "73", "Test 0x73");
    TBTHO(0x74, "74", "Test 0x74");
    TBTHO(0x75, "75", "Test 0x75");
    TBTHO(0x76, "76", "Test 0x76");
    TBTHO(0x77, "77", "Test 0x77");
    TBTHO(0x78, "78", "Test 0x78");
    TBTHO(0x79, "79", "Test 0x79");
    TBTHO(0x7A, "7A", "Test 0x7A");
    TBTHO(0x7B, "7B", "Test 0x7B");
    TBTHO(0x7C, "7C", "Test 0x7C");
    TBTHO(0x7D, "7D", "Test 0x7D");
    TBTHO(0x7E, "7E", "Test 0x7E");
    TBTHO(0x7F, "7F", "Test 0x7F");
    TBTHO(0x80, "80", "Test 0x80");
    TBTHO(0x81, "81", "Test 0x81");
    TBTHO(0x82, "82", "Test 0x82");
    TBTHO(0x83, "83", "Test 0x83");
    TBTHO(0x84, "84", "Test 0x84");
    TBTHO(0x85, "85", "Test 0x85");
    TBTHO(0x86, "86", "Test 0x86");
    TBTHO(0x87, "87", "Test 0x87");
    TBTHO(0x88, "88", "Test 0x88");
    TBTHO(0x89, "89", "Test 0x89");
    TBTHO(0x8A, "8A", "Test 0x8A");
    TBTHO(0x8B, "8B", "Test 0x8B");
    TBTHO(0x8C, "8C", "Test 0x8C");
    TBTHO(0x8D, "8D", "Test 0x8D");
    TBTHO(0x8E, "8E", "Test 0x8E");
    TBTHO(0x8F, "8F", "Test 0x8F");
    TBTHO(0x90, "90", "Test 0x90");
    TBTHO(0x91, "91", "Test 0x91");
    TBTHO(0x92, "92", "Test 0x92");
    TBTHO(0x93, "93", "Test 0x93");
    TBTHO(0x94, "94", "Test 0x94");
    TBTHO(0x95, "95", "Test 0x95");
    TBTHO(0x96, "96", "Test 0x96");
    TBTHO(0x97, "97", "Test 0x97");
    TBTHO(0x98, "98", "Test 0x98");
    TBTHO(0x99, "99", "Test 0x99");
    TBTHO(0x9A, "9A", "Test 0x9A");
    TBTHO(0x9B, "9B", "Test 0x9B");
    TBTHO(0x9C, "9C", "Test 0x9C");
    TBTHO(0x9D, "9D", "Test 0x9D");
    TBTHO(0x9E, "9E", "Test 0x9E");
    TBTHO(0x9F, "9F", "Test 0x9F");
    TBTHO(0xA0, "A0", "Test 0xA0");
    TBTHO(0xA1, "A1", "Test 0xA1");
    TBTHO(0xA2, "A2", "Test 0xA2");
    TBTHO(0xA3, "A3", "Test 0xA3");
    TBTHO(0xA4, "A4", "Test 0xA4");
    TBTHO(0xA5, "A5", "Test 0xA5");
    TBTHO(0xA6, "A6", "Test 0xA6");
    TBTHO(0xA7, "A7", "Test 0xA7");
    TBTHO(0xA8, "A8", "Test 0xA8");
    TBTHO(0xA9, "A9", "Test 0xA9");
    TBTHO(0xAA, "AA", "Test 0xAA");
    TBTHO(0xAB, "AB", "Test 0xAB");
    TBTHO(0xAC, "AC", "Test 0xAC");
    TBTHO(0xAD, "AD", "Test 0xAD");
    TBTHO(0xAE, "AE", "Test 0xAE");
    TBTHO(0xAF, "AF", "Test 0xAF");
    TBTHO(0xB0, "B0", "Test 0xB0");
    TBTHO(0xB1, "B1", "Test 0xB1");
    TBTHO(0xB2, "B2", "Test 0xB2");
    TBTHO(0xB3, "B3", "Test 0xB3");
    TBTHO(0xB4, "B4", "Test 0xB4");
    TBTHO(0xB5, "B5", "Test 0xB5");
    TBTHO(0xB6, "B6", "Test 0xB6");
    TBTHO(0xB7, "B7", "Test 0xB7");
    TBTHO(0xB8, "B8", "Test 0xB8");
    TBTHO(0xB9, "B9", "Test 0xB9");
    TBTHO(0xBA, "BA", "Test 0xBA");
    TBTHO(0xBB, "BB", "Test 0xBB");
    TBTHO(0xBC, "BC", "Test 0xBC");
    TBTHO(0xBD, "BD", "Test 0xBD");
    TBTHO(0xBE, "BE", "Test 0xBE");
    TBTHO(0xBF, "BF", "Test 0xBF");
    TBTHO(0xC0, "C0", "Test 0xC0");
    TBTHO(0xC1, "C1", "Test 0xC1");
    TBTHO(0xC2, "C2", "Test 0xC2");
    TBTHO(0xC3, "C3", "Test 0xC3");
    TBTHO(0xC4, "C4", "Test 0xC4");
    TBTHO(0xC5, "C5", "Test 0xC5");
    TBTHO(0xC6, "C6", "Test 0xC6");
    TBTHO(0xC7, "C7", "Test 0xC7");
    TBTHO(0xC8, "C8", "Test 0xC8");
    TBTHO(0xC9, "C9", "Test 0xC9");
    TBTHO(0xCA, "CA", "Test 0xCA");
    TBTHO(0xCB, "CB", "Test 0xCB");
    TBTHO(0xCC, "CC", "Test 0xCC");
    TBTHO(0xCD, "CD", "Test 0xCD");
    TBTHO(0xCE, "CE", "Test 0xCE");
    TBTHO(0xCF, "CF", "Test 0xCF");
    TBTHO(0xD0, "D0", "Test 0xD0");
    TBTHO(0xD1, "D1", "Test 0xD1");
    TBTHO(0xD2, "D2", "Test 0xD2");
    TBTHO(0xD3, "D3", "Test 0xD3");
    TBTHO(0xD4, "D4", "Test 0xD4");
    TBTHO(0xD5, "D5", "Test 0xD5");
    TBTHO(0xD6, "D6", "Test 0xD6");
    TBTHO(0xD7, "D7", "Test 0xD7");
    TBTHO(0xD8, "D8", "Test 0xD8");
    TBTHO(0xD9, "D9", "Test 0xD9");
    TBTHO(0xDA, "DA", "Test 0xDA");
    TBTHO(0xDB, "DB", "Test 0xDB");
    TBTHO(0xDC, "DC", "Test 0xDC");
    TBTHO(0xDD, "DD", "Test 0xDD");
    TBTHO(0xDE, "DE", "Test 0xDE");
    TBTHO(0xDF, "DF", "Test 0xDF");
    TBTHO(0xE0, "E0", "Test 0xE0");
    TBTHO(0xE1, "E1", "Test 0xE1");
    TBTHO(0xE2, "E2", "Test 0xE2");
    TBTHO(0xE3, "E3", "Test 0xE3");
    TBTHO(0xE4, "E4", "Test 0xE4");
    TBTHO(0xE5, "E5", "Test 0xE5");
    TBTHO(0xE6, "E6", "Test 0xE6");
    TBTHO(0xE7, "E7", "Test 0xE7");
    TBTHO(0xE8, "E8", "Test 0xE8");
    TBTHO(0xE9, "E9", "Test 0xE9");
    TBTHO(0xEA, "EA", "Test 0xEA");
    TBTHO(0xEB, "EB", "Test 0xEB");
    TBTHO(0xEC, "EC", "Test 0xEC");
    TBTHO(0xED, "ED", "Test 0xED");
    TBTHO(0xEE, "EE", "Test 0xEE");
    TBTHO(0xEF, "EF", "Test 0xEF");
    TBTHO(0xF0, "F0", "Test 0xF0");
    TBTHO(0xF1, "F1", "Test 0xF1");
    TBTHO(0xF2, "F2", "Test 0xF2");
    TBTHO(0xF3, "F3", "Test 0xF3");
    TBTHO(0xF4, "F4", "Test 0xF4");
    TBTHO(0xF5, "F5", "Test 0xF5");
    TBTHO(0xF6, "F6", "Test 0xF6");
    TBTHO(0xF7, "F7", "Test 0xF7");
    TBTHO(0xF8, "F8", "Test 0xF8");
    TBTHO(0xF9, "F9", "Test 0xF9");
    TBTHO(0xFA, "FA", "Test 0xFA");
    TBTHO(0xFB, "FB", "Test 0xFB");
    TBTHO(0xFC, "FC", "Test 0xFC");
    TBTHO(0xFD, "FD", "Test 0xFD");
    TBTHO(0xFE, "FE", "Test 0xFE");
    TBTHO(0xFF, "FF", "Test 0xFF");
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_hex_digit_to_byte();
    test_hex_octet_to_byte();
    test_nibble_to_hex_digit();
    test_byte_to_hex_octet();

    TAP_END_PLAN();
}