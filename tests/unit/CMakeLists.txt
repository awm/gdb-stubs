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

# Test the auxilliary functions.
add_executable(test_auxilliary_checksum test_auxilliary_checksum.c)
add_test(test_auxilliary_checksum test_auxilliary_checksum)
add_executable(test_auxilliary_hex test_auxilliary_hex.c)
add_test(test_auxilliary_hex test_auxilliary_hex)
add_executable(test_auxilliary_rle test_auxilliary_rle.c)
add_test(test_auxilliary_rle test_auxilliary_rle)
add_executable(test_auxilliary_binary test_auxilliary_binary.c)
add_test(test_auxilliary_binary test_auxilliary_binary)
