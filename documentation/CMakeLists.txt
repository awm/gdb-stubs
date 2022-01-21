#
# @file      CMakeLists.txt
#
# @remark
#     SPDX-License-Identifier: MPL-2.0
#
# @brief     Generate documentation for GDB stubs.
#
# @note      Documentation generation based on
#            https://eb2.co/blog/2012/03/sphinx-and-cmake-beautiful-documentation-for-c-projects/.
#            API documentation generation based on
#            https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/.
#
find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)

### Doxygen Configuration ###

# Find all the public headers.
get_target_property(GDBS_PUBLIC_HEADER_DIR gdbstub INTERFACE_INCLUDE_DIRECTORIES)
file(GLOB_RECURSE GDBS_PUBLIC_HEADERS ${GDBS_PUBLIC_HEADER_DIR}/*.h)

# Set Doxygen inputs and outputs.
set(DOXYGEN_INPUT_DIR   ${PROJECT_SOURCE_DIR}/include)
set(DOXYGEN_OUTPUT_DIR  ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
set(DOXYGEN_INDEX_FILE  ${DOXYGEN_OUTPUT_DIR}/xml/index.xml)
set(DOXYFILE_IN         ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT        ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# Control Doxygen build verbosity.
if(VERBOSE)
    set(DOXYGEN_QUIET NO)
else()
    set(DOXYGEN_QUIET YES)
endif()

# Replace variables inside @@ with the current values.
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

# Doxygen command.
add_custom_command(OUTPUT          ${DOXYGEN_INDEX_FILE}
                   DEPENDS         ${GDBS_PUBLIC_HEADERS}
                   COMMAND         ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                   MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                   COMMENT         "Generating API documentation")
file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})
add_custom_target(Doxygen ALL DEPENDS ${DOXYGEN_INDEX_FILE})

### Sphinx Configuration ###

# Set Sphinx inputs and outputs.
set(SPHINX_CACHE_DIR  ${CMAKE_CURRENT_BINARY_DIR}/sphinx-cache)
set(SPHINX_SOURCE     ${CMAKE_CURRENT_SOURCE_DIR})
set(SPHINX_BUILD      ${CMAKE_CURRENT_BINARY_DIR}/sphinx)
set(SPHINX_INDEX_FILE ${SPHINX_BUILD}/index.html)

# Find all the reStructuredText files.
file(GLOB_RECURSE RST_FILES ${SPHINX_SOURCE}/*.rst)

# Control Sphinx build verbosity.
if(VERBOSE)
    set(SPHINX_QUIET "")
else()
    set(SPHINX_QUIET "-q")
endif()

# Generate Sphinx documentation.
add_custom_command(OUTPUT            ${SPHINX_INDEX_FILE}
                   COMMAND           ${SPHINX_EXECUTABLE}
                                        -b html
                                        ${SPHINX_QUIET}
                                        -d ${SPHINX_CACHE_DIR}
                                        # Tell Breathe where to find the Doxygen output
                                        -Dbreathe_projects.gdb_stubs=${DOXYGEN_OUTPUT_DIR}/xml
                                        ${SPHINX_SOURCE}
                                        ${SPHINX_BUILD}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   DEPENDS           ${RST_FILES} ${DOXYGEN_INDEX_FILE}
                   MAIN_DEPENDENCY   ${SPHINX_SOURCE}/conf.py
                   COMMENT           "Generating documentation with Sphinx")
add_custom_target(Sphinx ALL DEPENDS ${SPHINX_INDEX_FILE})
