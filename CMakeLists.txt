#
# @file      CMakeLists.txt
# @copyright 2022 Andrew MacIsaac
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Top-level CMake file for GDB Stubs.
#
cmake_minimum_required(VERSION 3.19)
enable_testing()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_C_STANDARD 99)

project(gdb-stubs VERSION 0.1.0 LANGUAGES C)

include(CTest)
include(CheckSymbolExists)

# Test for platform features.
check_symbol_exists(NULL    "stdlib.h" HAVE_NULL)
check_symbol_exists(assert  "assert.h" HAVE_ASSERT)
check_symbol_exists(memcmp  "string.h" HAVE_MEMCMP)
check_symbol_exists(memcpy  "string.h" HAVE_MEMCPY)
check_symbol_exists(memset  "string.h" HAVE_MEMSET)
check_symbol_exists(strlen  "string.h" HAVE_STRLEN)
check_symbol_exists(strncmp "string.h" HAVE_STRNCMP)

# Turn on all warnings and treat all warnings as errors.
set(GNU_LIKE GNU Clang AppleClang)
if (CMAKE_C_COMPILER_ID IN_LIST GNU_LIKE)
    add_compile_options(-Wall -Wextra -Werror)
elseif (MSVC)
    add_compile_options(/W4 /WX)
endif()

# Subdirectories
add_subdirectory(source)
if (BUILD_DOCUMENTATION)
    add_subdirectory(documentation)
endif()
if (NOT CMAKE_CROSSCOMPILING)
    add_subdirectory(tests/unit)
endif()
