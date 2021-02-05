#
# @file      CMakeLists.txt
# @copyright 2021 Sierra Wireless Inc.
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Unit tests for GDB stub implementation.
#
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/source
)

# First, a basic sanity of tap.h itself.
add_executable(test_tap_sanity test_tap_sanity.c)
add_test(test_tap_sanity test_tap_sanity)

# Test the auxiliary functions.
add_executable(test_auxiliary_checksum test_auxiliary_checksum.c)
add_test(test_auxiliary_checksum test_auxiliary_checksum)
add_executable(test_auxiliary_hex test_auxiliary_hex.c)
add_test(test_auxiliary_hex test_auxiliary_hex)
add_executable(test_auxiliary_rle test_auxiliary_rle.c)
add_test(test_auxiliary_rle test_auxiliary_rle)
add_executable(test_auxiliary_binary test_auxiliary_binary.c)
add_test(test_auxiliary_binary test_auxiliary_binary)
