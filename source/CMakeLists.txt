#
# @file      CMakeLists.txt
# @copyright 2022 Andrew MacIsaac
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Build file for stub library.
#

# Stub library source files.
set(SRCS
    auxiliary/binary.c
    auxiliary/checksum.c
    auxiliary/hex.c
    auxiliary/packet.c
    auxiliary/rle.c
    core.c
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/source
)

# Add missing C library routines, if applicable.
if(NOT HAVE_MEMCMP)
    list(APPEND SRCS stdc/memcmp.c)
endif()
if(NOT HAVE_MEMCPY)
    list(APPEND SRCS stdc/memcpy.c)
endif()
if(NOT HAVE_MEMSET)
    list(APPEND SRCS stdc/memset.c)
endif()
if(NOT HAVE_STRLEN)
    list(APPEND SRCS stdc/strlen.c)
endif()
if(NOT HAVE_STRNCMP)
    list(APPEND SRCS stdc/strncmp.c)
endif()

# Set defines for detected features.
if(HAVE_NULL)
    add_compile_definitions(HAVE_NULL)
endif()
if(HAVE_ASSERT)
    add_compile_definitions(HAVE_ASSERT)
endif()
if(HAVE_MEMSET)
    add_compile_definitions(HAVE_MEMSET)
endif()

# Generate library of GDB stub code.
add_library(gdbstub STATIC ${SRCS})
