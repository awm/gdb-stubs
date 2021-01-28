/**
 *  @file       test_auxilliary_hex.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for hexadecimal conversion functions.
 */
#include "auxilliary/hex.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

static const unsigned long TEST_COUNT = 255 + 22;

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

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_hex_digit_to_byte();
    test_hex_octet_to_byte();

    TAP_END_PLAN();
}
