Framework API
=============

The API is split into two parts.  The first part declares the functions which may be called from the
user application code.  The second part declares the functions which must be implemented by the user
application code for the stub to operate.

.. _api-functions:

Functions
---------

*What the stub provides to you.*

.. doxygenfile:: gdbstub.h
    :sections: briefdescription define enum typedef var func

.. _api-hooks:

Hooks
-----

*What you provide to the stub.*

.. doxygenfile:: gdbdevice.h
    :sections: briefdescription define enum typedef var func
