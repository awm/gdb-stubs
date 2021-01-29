/**
 *  @file       test_auxilliary_checksum.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for checksum implementation.
 */
#include "auxilliary/checksum.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

static const unsigned long TEST_COUNT = 5 + 5;

static void test_accumulate_checksum(void)
{
    unsigned char checksum = 0;

    TAP_DIAG("In %s", __func__);

    accumulate_checksum(&checksum, 0x05);
    TAP_OK(checksum == 0x05, "Test 0x05");

    accumulate_checksum(&checksum, 0x8A);
    TAP_OK(checksum == 0x8F, "Test 0x8F");

    accumulate_checksum(&checksum, 0xB0);
    TAP_OK(checksum == 0x3F, "Test 0x3F");

    accumulate_checksum(&checksum, 0x01);
    TAP_OK(checksum == 0x40, "Test 0x40");

    accumulate_checksum(&checksum, 0xFF);
    TAP_OK(checksum == 0x3F, "Test 0x3F (again)");
}

static void test_calculate_checksum(void)
{
    TAP_DIAG("In %s", __func__);

    TAP_OK(calculate_checksum("", 0) == 0x00, "Empty string");
    TAP_OK(calculate_checksum("+", 1) == '+', "Single character");
    TAP_OK(calculate_checksum("This is a test.", strlen("This is a test.")) == 0x23, "Test string");
    TAP_OK(calculate_checksum("T001:1234123412341234", strlen("T001:1234123412341234")) == 0x47,
           "Payload example");
    TAP_OK(calculate_checksum("@@@@", strlen("@@@@")) == 0x00, "Zero checksum");
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_accumulate_checksum();
    test_calculate_checksum();

    TAP_END_PLAN();
}
