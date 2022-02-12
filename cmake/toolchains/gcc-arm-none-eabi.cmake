#
# @file         gcc-arm-none-eabi.cmake
# @copyright    2022 Andrew MacIsaac
#
# @remark
#   SPDX-License-Identifier: MPL-2.0
#
# @brief        Toolchain definition for default Ubuntu arm-none-eabi bare-metal cross compiler.
#               Installed via the "gcc-arm-none-eabi" APT package.
#

# Set the name of the target operating system.
set(CMAKE_SYSTEM_NAME Generic)

# Set which compilers to use for C and C++.
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

# Use "nosys" specs for bare-metal build.
set(CMAKE_EXE_LINKER_FLAGS_INIT "--specs=nosys.specs")
