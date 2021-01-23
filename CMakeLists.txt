#
# @file      CMakeLists.txt
# @copyright 2021 Sierra Wireless Inc.
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Top-level CMake file for GDB Stubs.
#
cmake_minimum_required(VERSION 3.5)
enable_testing()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_C_STANDARD 99)

project(gdb-stubs VERSION 0.1.0 LANGUAGES C)

include(CTest)
include(CheckSymbolExists)

# Test for platform features.
check_symbol_exists(memcpy  "string.h"  HAVE_MEMCPY)
check_symbol_exists(memset  "string.h"  HAVE_MEMSET)
check_symbol_exists(strncmp "string.h"  HAVE_STRNCMP)

# Turn on all warnings and treat all warnings as errors.
set(GNU_LIKE GNU Clang AppleClang)
if (CMAKE_C_COMPILER_ID IN_LIST GNU_LIKE)
    add_compile_options(-Wall -Wextra -Werror)
elseif (MSVC)
    add_compile_options(/W4 /WX)
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# Subdirectories
add_subdirectory(source)
add_subdirectory(documentation)
if (NOT CMAKE_CROSSCOMPILING)
    add_subdirectory(tests/unit)
endif()
