#
# @file      FindSphinx.cmake
# @copyright 2022 Andrew MacIsaac
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Sphinx documentation generator module for CMake.
#
include(FindPackageHandleStandardArgs)

# Find the sphinx-build tool for documentation generation.
find_program(SPHINX_EXECUTABLE NAMES sphinx-build
    HINTS $ENV{SPHINX_DIR}
    PATH_SUFFIXES bin
    DOC "Sphinx documentation generator"
)
find_package_handle_standard_args(Sphinx DEFAULT_MSG SPHINX_EXECUTABLE)
mark_as_advanced(SPHINX_EXECUTABLE)
