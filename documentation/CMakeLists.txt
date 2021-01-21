#
# @file      CMakeLists.txt
# @copyright 2021 Sierra Wireless Inc.
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Generate documentation for GDB stubs.
#
# @note      Documentation generation based on
#            https://eb2.co/blog/2012/03/sphinx-and-cmake-beautiful-documentation-for-c-projects/.
#
find_package(Sphinx REQUIRED)

# Configured documentation tools and intermediate build results.
set(BINARY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/_docbuild")

# Sphinx cache with pickled ReST documents.
set(SPHINX_CACHE_DIR "${CMAKE_CURRENT_BINARY_DIR}/_doctrees")

# HTML output directory.
set(SPHINX_HTML_DIR "${CMAKE_CURRENT_BINARY_DIR}/html")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/conf.py.in"
    "${BINARY_BUILD_DIR}/conf.py"
    @ONLY
)

add_custom_target(gdbstubs_docs ALL
    ${SPHINX_EXECUTABLE}
        -q -b html
        -c "${BINARY_BUILD_DIR}"
        -d "${SPHINX_CACHE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${SPHINX_HTML_DIR}"
    COMMENT "Building HTML documentation with Sphinx"
)
