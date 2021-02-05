..  GDB Stub Framework documentation entry point.
    Copyright: 2021 Sierra Wireless Inc.
    SPDX-License-Identifier: MPL-2.0

GDB Stub Framework
==================

This project aims to provide a framework for developing GDB stubs in order to facilitate debugging
of embedded devices without hardware debug interfaces, such as JTAG or SWD.  This can have value
even on devices with hardware debug ports, if the port is inaccessible or the appropriate probe is
not available.

Individual GDB stubs are composed of a library of platform-agnostic code which implements the GDB
protocol and command handling, and a platform-specific library which holds the initialization of the
debug environment, and hooks for debugging actions and I/O operations.

License
-------

**Copyright 2021 Sierra Wireless Inc.**

Distributed under the terms of the :doc:`license`.

.. toctree::
   :maxdepth: 2
   :caption: Contents

   getting-started
   layout
   api
   license

Indices and Tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
