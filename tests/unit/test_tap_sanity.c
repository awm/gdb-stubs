/**
 *  @file       test_tap_sanity.c
 *  @copyright  2022 Andrew MacIsaac
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Test Anything Protocol header sanity test.
 */

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

static const unsigned long TEST_COUNT = 7;

static void test_tap_diag(void)
{
    TAP_DIAG("A diagnostic message");
    TAP_DIAG("A %d%s diagnostic message", 2, "nd");
}

static void test_tap_ok(void)
{
    TAP_OK(true, "A success");
    TAP_OK(TEST_COUNT > 0, "Another success (%lu)", TEST_COUNT);
}

static void test_tap_assert(void)
{
    TAP_ASSERT(true, "Assertion passed");
    TAP_ASSERT(TEST_COUNT > 0, "Another assertion (%lu)", TEST_COUNT);
}

static void test_tap_skip(void)
{
    TAP_SKIP("Skipping guaranteed failures");
    TAP_OK(false, "A failure");
    TAP_OK(TEST_COUNT == 0, "Failing assertion (%lu)", TEST_COUNT);
    TAP_END_SKIP();
}

static void test_tap_todo(void)
{
    TAP_TODO("Never enable this test");
    TAP_OK(false, "Never enabled");
    TAP_END_TODO();
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_tap_diag();
    test_tap_ok();
    test_tap_assert();
    test_tap_skip();
    test_tap_todo();

    TAP_END_PLAN();
}
