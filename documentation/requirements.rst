..  Software requirements.
    Copyright: 2022 Andrew MacIsaac
    SPDX-License-Identifier: MPL-2.0

Requirements
============

System Overview
---------------

The product of the proposed stub architecture will be a static library which may be linked into an
executable to provide the debugging access.

Historically, GDB stubs have been implemented with all of the architecture and platform specific
code combined with the protocol state machine within a single C file, however this approach has a
number of drawbacks.  In particular, it limits code re-use and imposes a lot of copying and pasting
for each new stub port.  In addition, it makes platform support harder because the platform-specific
code is interwoven with the generic code.

The proposal described here intends to make use of software development best practices to provide a
standard implementation of the core, platform agnostic parts of the stub architecture, and then at
build time select the architecture and system interfaces appropriate for the target.

Analysis
--------

GDB provides the stub capability for scenarios where the gdb or gdbserver applications cannot be
used directly.  The GDB source code includes stubs for the i386, ia64, m32r, m68k, sh, and sparc
architectures, however because of the ubiquity of hardware debug solutions, newer platforms such as
various ARM flavours are not included in the sample stubs.  Many of the existing stubs are decades
old and do not follow the greatest coding practices.  Each existing stub typically combines all of
the command processing and platform-specific code in a single C file of between 800 and 2500 lines.
The general approach for implementing new stubs appears to have been to copy an existing one
wholesale and then modify it until it works on the new platform, which results in lots of duplicated
code as well and the repeated propagation of some arbitrary design decisions by the first stub
writer.

Overall, an arbitrary stub is not particularly long, and the necessary components are well described
in the GDB documentation.  The main complexity in writing a stub derives from the necessity of
ensuring that it hooks correctly into the interrupt/exception handling architecture of the system.
It must correctly intercept various types of events, such as hardware breakpoints, bus errors, and
serial interrupts without itself disrupting the flow of normal execution.

Design Overview
---------------

At a high level, the proposed design is as follows.  A library of common code will be created to
provide the platform independent GDB protocol handling and utilities, and this will be coupled to a
platform specific component which will supply the implementation for a given target.  A well-defined
API will be created to define the boundary between the two sides, which the command code will call
into in order to perform platform specific operations.

Technical Requirements
----------------------

In the following requirements, the term **"must"** indicates an essential feature which is necessary
to the completion and operation of the minimum viable product (a minimal stub).  The term **"must
not"** indicates a case that it is necessary to avoid in order to consider complete the minimum
viable product.  The term **"should"** indicates a feature which is strongly recommended for the
completed product, but not essential and could be implemented in a later phase once the minimum
viable product is achieved.  The term **"may"** indicates a discretionary or nice-to-have feature
which will enhance the product, but is not necessary for it to be considered fully complete and
usable.

These requirements are denoted with the prefix **"T"** in ticket descriptions.

  1. A GDB stub must have configurable build-time options to select features of the target system
     and optional functionality.

    1. The supported I/O interface types must be configurable.
    2. The targeted processor and system architecture must be selectable.
    3. Support for additional protocol message types beyond the essential functionality must be
       configurable, if the system/port supports the necessary features.  *For example, enabling
       shell passthrough features must be a selectable option if shell support has been added to the
       stub feature set, and if the target supports a shell or CLI.*

  2. A GDB stub must implement a platform-agnostic core of protocol handling routines for creating
     and interpreting GDB messages.

    1. A stub must support the GDB protocol message format and signalling described in section E.1
       of the GDB manual.

      1. A stub must implement the packet format and checksum.
      2. A stub must implement packet acknowledgements.
      3. A stub must support the packet run-length encoding feature.

    2. At a minimum, a stub must support the GDB protocol commands described in section E.1 of the
       GDB manual.

      1. A stub must implement the ``?`` command.
      2. A stub must implement the ``g`` and ``G`` commands.
      3. A stub must implement the ``m`` and ``M`` commands.
      4. A stub must implement the ``c`` command.
      5. A stub must implement the ``s`` command, if hardware single stepping is supported by the
         platform.
      6. A stub must implement the ``vCont`` command if the target is multi-threaded.

        1. The ``vCont?`` command must be supported.
        2. The ``vCont;c`` command must be supported.
        3. The ``vCont;s`` command must be supported, if hardware single stepping is supported by
           the platform.
        4. The ``vCont;t`` command must be supported.

      7. A stub must support the ``k`` command.

        1. The k command must have the effect of restarting the target.

      8. A stub must support the ``qSupported`` command.

        1. The PacketSize reply to the ``qSupported`` command must be supported.

    3. A stub must support a subset of the stop reply packets described in section E.3 of the GDB
       manual.

      1. A stub must implement the ``S`` reply.
      2. A stub must implement the ``T`` reply.

    4. A stub should support some additional commands as part of the core command set.

      1. A stub should implement the ``qC`` command if the target is multi-threaded.
      2. A stub should support the ``D`` command.
      3. A stub should support the ``qOffsets`` command.
      4. A stub should support the ``X`` command.
      5. A stub should support the ``qSymbol`` command.

        1. A minimal (always OK) implementation of the ``qSymbol`` command may be provided.

    5. A stub may provide support for additional commands as described in Appendix E of the GDB
       manual.

      1. Additional commands must be implemented as part of the core command implementation, to make
         them available for other platforms which might benefit from them.

        1. Additional commands must be conditionally enabled/disabled depending on the target
           properties and configuration.

  3. A GDB stub must provide at least one interface implementation for remote connections.

    1. A stub may provide an interface for remote debugging over a serial UART.

      1. The serial UART selected for debugging must be configurable to the extent allowed by the
         platform.
      2. If a UART is to be shared with an existing feature, it may try to coexist to the extent
         allowed by the feature.  *For example, if it coexists on a CLI port, the shell passthrough
         features of GDB may be used to allow CLI access from within the debugging session.*

    2. A stub may provide an interface for remote debugging over the standard C library's stdio.

      1. A stub may take complete ownership of stdin and stdout if this feature is enabled.

    3. A stub may provide an interface for remote debugging over TCP.
    4. A stub must ensure that GDB message sending or receiving is still possible when the system is
       halted for breakpoints or exceptions.
    5. The provided interface(s) must permit receiving one character at a time into the core
       protocol implementation for incoming protocol packets.
    6. The provided interface(s) must permit sending one character at a time from the core protocol
       implementation for outgoing protocol packets.

  4. The GDB stub code base must be structured so that it can easily be incorporated into the native
     build system of the target.

    1. A stub must not impose a build system choice on a target, other than the general requirement
       of a compatible C compiler and linker.
    2. A stub must provide an entry point to be called as early as possible in the target
       initialization process.  This will set up the necessary hooks for the debugger.
    3. A stub may call various target-specific functions to set up the debugging environment and
       perform I/O operations.
    4. A stub must provide a function which can be called from the application to explicitly trigger
       a breakpoint.
    5. A stub must provide a function to flush the instruction cache.

      1. If no instruction cache is present then the flush operation must be a no-op.

    6. A stub must not use third-party libraries (other than libc) for common portions of the code.
    7. A stub may use the target's standard C library for basic C functions, if available.

      1. A stub must provide minimal implementations of required standard functions if they are not
         available on the target.

Expected Output Documentation
-----------------------------

These requirements are denoted with the prefix **"D"** in ticket descriptions.

  1. The structure of the stub project code base must be documented.
  2. Instructions for expanding platform support must be provided.
  3. Instructions for expanding GDB command support should be provided.

Test Considerations
-------------------

As much as possible, features of the platform-agnostic portion of the code base should be
accompanied by unit tests to ensure that the individual functions and command handling routines work
as expected.

Testing of the stub as a whole will likely be done in-situ with a live GDB session on a known
target.  At a minimum, such tests should verify the following:

  * Connecting to the target.
  * Running the target.
  * Adding, removing, and stopping on breakpoints.
  * Adding, removing, and stopping on watchpoints.
  * Single stepping.
  * Printing the contents of variables.
  * Printing the contents of registers.
  * Displaying a backtrace.
  * Listing the threads and switching thread contexts while stopped (only if multi-threading is
    supported).
  * Resetting the target.

References
----------

* `Implementing a Remote Stub <https://sourceware.org/gdb/onlinedocs/gdb/Remote-Stub.html>`_.
* `Howto: GDB Remote Serial Protocol <https://www.embecosm.com/appnotes/ean4/embecosm-howto-rsp-server-ean4-issue-2.html>`_.
* `avatar-gdbstub <https://github.com/avatarone/avatar-gdbstub>`_.
* `GDB Remote Serial Protocol <https://sourceware.org/gdb/onlinedocs/gdb/Remote-Protocol.html>`_.
