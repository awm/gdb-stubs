Source Code Organization
========================

The project code is structured as follows:

cmake
    Module and toolchain definition files for CMake.

documentation
    Sphinx build configuration and reStructuredText sources for this documentation.

include
    C header files defining the two main interfaces which are used by a GDB stub:

        * The externally facing API (:ref:`api-functions`) which must be called from the user's
          embedded application in order to initialize and run the stub.
        * The internal API (:ref:`api-hooks`) which must be implemented by the user's application in
          order to hook the stub into the appropriate I/O and debug hardware for the device.

source
    Platform-agnostic C source code implementing all of the GDB protocol, command handling and
    packet formatting.  This is further divided into:

    auxilliary
        Buffer manipulation and checksum routines.

    debug
        Bare-bones debugging features for the stub code itself.

    io/serial
        Platform-agnostic portions of the I/O interface for serial connections.

    protocol
        Implementation of the GDB protocol itself.

    stdc
        Minimal implementations of the required standard C functions for platforms which do not
        provide them.

tests/unit
    Unit testing infrastructure and test source files.
