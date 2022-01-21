/**
 *  @file       test_core.c
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for core event handling and initialization functions.
 */
#include "core.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

//                                      TGETS TGIC TCGE TGE
static const unsigned long TEST_COUNT =    10 + 16 +  1 + 2;

void test_gdbs_error_to_string(void)
{
    const char *str;

    TAP_DIAG("In %s", __func__);

    TAP_OK(strlen(str = gdbs_error_to_string(0)) > 0, "0: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(GDBS_ERROR_OK)) > 0, "GDBS_ERROR_OK: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(GDBS_ERROR_INVALID)) > 0,
        "GDBS_ERROR_INVALID: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(GDBS_ERROR_CHECKSUM)) > 0,
        "GDBS_ERROR_CHECKSUM: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(GDBS_ERROR_EOB)) > 0, "GDBS_ERROR_EOB: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(GDBS_ERROR_NOT_FOUND)) > 0,
        "GDBS_ERROR_NOT_FOUND: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(GDBS_ERROR_NOT_FOUND + 1)) == 0,
        "GDBS_ERROR_NOT_FOUND + 1: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(-1)) == 0, "-1: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(7000)) == 0, "7000: '%s'", str);
    TAP_OK(strlen(str = gdbs_error_to_string(-9999999)) == 0, "-9999999: '%s'", str);
}

void proto_set_ack_mode
(
    int enable
)
{
    TAP_OK(enable, "Enable ack mode: %d", enable);
}

struct data
{
    int error;
};

static struct data   test_data;
static struct data  *data = &test_data;

int gdbs_open_comm
(
    void *comm
)
{
    TAP_OK(comm == data, "Open comm: %p", comm);
    return test_data.error;
}

int gdbs_register_exceptions
(
    void **state
)
{
    TAP_ASSERT(state != NULL, "Register exceptions: %p", state);
    *state = data;
    return test_data.error;
}

void gdbs_deregister_exceptions
(
    void *state
)
{
    TAP_OK(state == data, "Exception state: %p", state);
}

void gdbs_close_comm
(
    void *comm
)
{
    TAP_OK(comm == data, "Comm data: %p", comm);
}

static void test_gdbs_initialize_cleanup(void)
{
    int result;

    TAP_DIAG("In %s", __func__);

    test_data.error = GDBS_ERROR_INVALID;
    result = gdbs_initialize(&test_data);
    TAP_OK(result == GDBS_ERROR_INVALID, "Invalid result: %d", result);

    test_data.error = GDBS_ERROR_OK;
    result = gdbs_initialize(&test_data);
    TAP_OK(result == GDBS_ERROR_OK, "Valid result: %d", result);
    gdbs_cleanup();

    test_data.error = GDBS_ERROR_OK;
    data = NULL;
    result = gdbs_initialize(NULL);
    TAP_OK(result == GDBS_ERROR_OK, "NULL comm: %d", result);
    gdbs_cleanup();
}

void test_core_get_environment(void)
{
    TAP_DIAG("In %s", __func__);
    TAP_OK(core_get_environment() == &env, "Get environment");
}

void proto_process
(
    int send_stop_reply
)
{
    TAP_OK(send_stop_reply == 1, "Send stop reply: %d", send_stop_reply);
    TAP_OK(env.packet_buffer != NULL, "Packet buffer: %p", env.packet_buffer);
}

void test_gdbs_enter(void)
{
    TAP_DIAG("In %s", __func__);
    gdbs_enter();
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_gdbs_error_to_string();
    test_gdbs_initialize_cleanup();
    test_core_get_environment();
    test_gdbs_enter();

    TAP_END_PLAN();
}
