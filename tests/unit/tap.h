/**
 *  @file       tap.h
 * 
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 * 
 *  @brief      Test Anything Protocol output macros.
 */
#ifndef TAP_H_
#define TAP_H_

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Value indicating the number of tests is not known in advance. */
#define TAP_NO_PLAN ULONG_MAX

/** Begin a test plan.
 *  This must be the first TAP call in a test run.
 *
 *  @param n Number of tests that will be run, or TAP_NO_PLAN if the number is not known in advance.
 */
#define TAP_PLAN(n)                                   \
    do                                                \
    {                                                 \
        memset(&s_tap_state, 0, sizeof(s_tap_state)); \
        s_tap_state.plan = (n);                       \
        if (s_tap_state.plan != TAP_NO_PLAN)          \
        {                                             \
            printf("1..%lu\n", s_tap_state.plan);     \
        }                                             \
        TAP_DIAG("Running tests from %s", __FILE__);  \
    } while (0)

/** End a test plan.
 *  This must be called after the last test case is finished, and will terminate the process.
 */
#define TAP_END_PLAN()                                                              \
    do                                                                              \
    {                                                                               \
        if (s_tap_state.plan == TAP_NO_PLAN)                                        \
        {                                                                           \
            s_tap_state.plan = s_tap_state.test;                                    \
            printf("1..%lu\n", s_tap_state.plan);                                   \
        }                                                                           \
        TAP_DIAG("%lu/%lu tests passed",                                            \
                 (unsigned long) s_tap_state.passed,                                \
                 (unsigned long) s_tap_state.plan);                                 \
        exit(s_tap_state.failed == 0 && s_tap_state.passed >= s_tap_state.plan  ?   \
             EXIT_SUCCESS                                                       :   \
             EXIT_FAILURE);                                                         \
    } while (0)

/** Evaluate a test condition.
 *  The test results are output to stdout.
 *
 *  @param  condition   The boolean expression to evaluate for the test.  The test is considered to
 *                      have passed if this evaluates to true.
 *  @param  format      The format string for the message to append to the test results.
 *  @param  ...         Positional parameters to the format string.
 */
#define TAP_OK(condition, /* format, */ ...)                                                    \
    do                                                                                          \
    {                                                                                           \
        const char *response = "not ok";                                                        \
        ++s_tap_state.test;                                                                     \
        if (condition)                                                                          \
        {                                                                                       \
            response = "ok";                                                                    \
        }                                                                                       \
                                                                                                \
        printf("%-6s %4lu [%4u] %-52s :: ", response, s_tap_state.test, __LINE__, #condition);  \
        printf(__VA_ARGS__);                                                                    \
                                                                                                \
        if (s_tap_state.skip != NULL)                                                           \
        {                                                                                       \
            printf(" # SKIP %s", s_tap_state.skip);                                             \
            ++s_tap_state.passed;                                                               \
        }                                                                                       \
        else if (s_tap_state.todo != NULL)                                                      \
        {                                                                                       \
            printf(" # TODO %s", s_tap_state.todo);                                             \
            ++s_tap_state.passed;                                                               \
        }                                                                                       \
        else if (response[0] == 'o')                                                            \
        {                                                                                       \
            ++s_tap_state.passed;                                                               \
        }                                                                                       \
        else                                                                                    \
        {                                                                                       \
            ++s_tap_state.failed;                                                               \
        }                                                                                       \
        printf("\n");                                                                           \
    } while (0)

/** Evaluate a test condition and abort the test run if it fails.
 *  The test results are output to stdout.
 *
 *  @param  condition   The boolean expression to evaluate for the test.  The test is considered to
 *                      have passed if this evaluates to true.
 *  @param  format      The format string for the message to append to the test results.
 *  @param  ...         Positional parameters to the format string.
 */
#define TAP_ASSERT(condition, /* format, */ ...)                                                \
    do                                                                                          \
    {                                                                                           \
        bool terminate = false;                                                                 \
        const char *response = "ok";                                                            \
                                                                                                \
        ++s_tap_state.test;                                                                     \
        if (condition)                                                                          \
        {                                                                                       \
            ++s_tap_state.passed;                                                               \
        }                                                                                       \
        else                                                                                    \
        {                                                                                       \
            if (s_tap_state.skip == NULL && s_tap_state.todo == NULL)                           \
            {                                                                                   \
                response = "Bail out!";                                                         \
                terminate = true;                                                               \
            }                                                                                   \
            else                                                                                \
            {                                                                                   \
                response = "not ok";                                                            \
                ++s_tap_state.passed;                                                           \
            }                                                                                   \
        }                                                                                       \
        printf("%-6s %4lu [%4u] %-52s :: ", response, s_tap_state.test, __LINE__, #condition);  \
        printf(__VA_ARGS__);                                                                    \
                                                                                                \
        if (s_tap_state.skip != NULL)                                                           \
        {                                                                                       \
            printf(" # SKIP %s", s_tap_state.skip);                                             \
        }                                                                                       \
        else if (s_tap_state.todo != NULL)                                                      \
        {                                                                                       \
            printf(" # TODO %s", s_tap_state.todo);                                             \
        }                                                                                       \
        printf("\n");                                                                           \
                                                                                                \
        if (terminate)                                                                          \
        {                                                                                       \
            exit(EXIT_FAILURE);                                                                 \
        }                                                                                       \
    } while (0)

/** Print a diagnostic message.
 *
 *  @param  format      The format string for the diagnostic message to display.
 *  @param  ...         Positional parameters to the format string.
 */
#define TAP_DIAG(/* format, */ ...) \
    do                              \
    {                               \
        printf("# ");               \
        printf(__VA_ARGS__);        \
        printf("\n");               \
    } while (0)

/** Start skipping tests.
 *  Failures in skipped tests will be ignored.
 *
 *  @param  message A string describing the reason for skipping the next test(s).
 */
#define TAP_SKIP(message)   s_tap_state.skip = (message)

/** Stop skipping tests. */
#define TAP_END_SKIP()      s_tap_state.skip = NULL

/** Mark subsequent tests as "TODO."
 *  Failures in TODO tests will be ignored.
 *
 *  @param  message A string describing the action that needs to be taken to enable the next
 *                  test(s).
 */
#define TAP_TODO(message)   s_tap_state.todo = (message)

/** Stop marking tests as "TODO." */
#define TAP_END_TODO()      s_tap_state.todo = NULL

/** Container for TAP execution state. */
struct tap_state
{
    /** Current skip message.  If this is NULL then tests are not being skipped. */
    const char *skip;
    /** Current TODO message.  If this is NULL then tests are not being marked as "TODO." */
    const char *todo;
    /** Number of tests in the plan, if provided; otherwise TAP_NO_PLAN. */
    unsigned long plan;
    /** Test counter. */
    unsigned long test;
    /** Pass counter. */
    unsigned long passed;
    /** Failure counter. */
    unsigned long failed;
};

/** Instance of TAP state for current unit test file. */
static struct tap_state s_tap_state;

#endif /* end TAP_H_ */
