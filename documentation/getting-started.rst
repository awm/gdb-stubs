..  Introductory and getting started material.
    Copyright: 2022 Andrew MacIsaac
    SPDX-License-Identifier: MPL-2.0

Getting Started
===============

Dependencies
------------

The following tools are required or recommended for building the framework:

* **Required, for target build:**

 + A C99-compliant C compiler for your target platform.

* **Recommended, for host build and unit tests:**

 + A C99-compliant C compiler and linker for your development host.
 + CMake >= 3.16.
 + Ninja >= 1.8.

* **Optional, for documentation generation:**

 + Sphinx >= 3.4.
 + Read the Docs Sphinx Theme >= 0.5.
 + Doxygen >= 1.8.
 + Breathe >= 4.26.

Building
--------

For convenience and unit testing a CMake project is available.  The standard
process for the target is to create a build directory, generate Ninja build files, and then build
the library:

.. code-block:: bash

    # Create a build directory
    mkdir build-${target}
    cd build-${target}

    # Generate Ninja files
    cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/${target}.cmake -G Ninja ..

    # Build the library
    ninja

The resulting static library will be located in ``build-${target}/source``.

Use of the CMake project is not mandatory, and if necessary the required stub code source files may
be directly incorporated into your own project's build mechanism.

Unit Tests
----------

To run unit tests on the local development host, first create a local build directory, generate
Ninja build files, and then build and run the tests:

.. code-block:: bash

    # Create a build directory
    mkdir build
    cd build

    # Generate Ninja files
    cmake -DBUILD_DOCUMENTATION=1 -G Ninja ..

    # Build the tests (and documentation)
    ninja

    # Run the tests
    ctest -V
