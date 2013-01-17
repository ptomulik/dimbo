src/lib/dimbo/swig/
```````````````````

This subtree contains swig_ library of ``.swg`` interface files used to generate
wrappers for *target languages* other than C/C++. The typical library use is to
``%include`` appropriate ``.swg`` files into target-language-specific ``.i``
interface files. 

By wrapping our C++ code, most of the functionality implemented here in C++ is
available also in other languages. The list of target languages may be further
extended with relatively low effort.

This is the top level ``swig`` library directory for dimbo project. The
sub-directory ``dimbo/`` starts a hierarchy which corresponds to the core part
of ``#/src/lib/dimbo/`` hierarchy (the hash ``#`` denotes top-level source
directory). For example, we have following correspondence:

- ``#/src/lib/dimbo/ ->  dimbo/``
- ``#/src/lib/dimbo/cl/ -> dimbo/cl/``
- ``[...]``

There are some extra directories:

==================== ========================================================
Subdirectory          Description
==================== ========================================================
``dimbo/std``         contains modules that wrap things from standard C++
                      library, such as exceptions, strings and so on
==================== ========================================================

When generating wrappers with swig, the top-level directory of this subtree, i.e
``#/src/lib/dimbo/swig`` must be in swig's include path (the ``-I`` flag). 

files that enter bindings: the ``.swg`` files
:::::::::::::::::::::::::::::::::::::::::::::

This subtree provides one ``.swg`` file for each ``.hpp``, whose interfaces may
be potentially wrapped with swig. For example, we have following
correspondence:

- ``#/src/lib/dimbo/exception.hpp -> dimbo/exception.swg``
- ``#/src/lib/dimbo/cl/exception.hpp -> dimbo/cl/exception.swg``
- ``#/src/lib/dimbo/cl/device.hpp -> dimbo/cl/device.swg``
- ``[...]``

target subtree(s) with bindings definition(s)
:::::::::::::::::::::::::::::::::::::::::::::

Bindings for particular languages are compiled from separate subtrees of dimbo
source tree. For example, bindings for python are defined under
``#/src/lib/dimbo/python/``. We'll call them  *target subtrees*. 

A target subtree contains ``SConscript`` files which drive the compilation of
swig ``.i`` interfaces located under the target subtree. Usually, these target
``.i`` files define modules for target language and just ``%include``
appropriate ``.swg`` files from this swig library to make-up the body of the
wrapper.

When generating wrappers with swig, the top-level directory of the target
tree (``#/src/lib/dimbo/python``, for example) must be in swig's include path
(the ``-I`` flag). The same applies to it's corresponding directory in variant
dir (``#/build/lib/dimbo/python`` for example).

files that define modules: the ``_mod.swg`` and ``.i`` files
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

There are several files in this subtree that end with ``_mod.swg``. These are
"module files". A ``_mod.swg`` file usually includes all the contents of a
module located in other ``.swg`` files (mentioned previously). It, however, has
no ``%module`` directive. 

The ``_mod.swg`` files are designated for %inclusion in target ``.i`` files.
It is responsibility of the target subtree to define module names and location of
``.i`` files (target subtree layout don't have to be same as the swig
subtree). For python language, for example, we have such a correspondence:

- ``#/build/lib/dimbo/python/Dimbo/Exception_Mod.i`` %includes 
  ``dimbo/exception_mod.swg``
- ``#/build/lib/dimbo/python/Dimbo/Cl/Exception_Mod.i`` %includes 
  ``dimbo/cl/exception_mod.swg``
- ``#/build/lib/dimbo/python/Dimbo/Cl/Platform_Mod.i`` %includes 
  ``dimbo/cl/platform_mod.swg``

``modules.i``
:::::::::::::

The target subtree which defines bindings for particular language, for
example ``#/src/lib/dimbo/python/``, must have ``modules.i`` file at its top
level. This file gets included by several ``_mod.swg`` files present here. This
way we provide feedback information from target subtree to the swig subtree.
For example, the ``modules.i`` provides definition of ``*_MOD_I`` constants
(see below).

``*_MOD_I`` constants defining module names
:::::::::::::::::::::::::::::::::::::::::::

For each ``_mod.swg`` file in ``#/src/lib/dimbo/swig/`` subtree, there should
be defined corresponding ``*_MOD_I`` constant in ``modules.i``. The constant
defines the target interface ``.i`` file which %includes the ``_mod.swg``. For
example, if ``#/build/lib/dimbo/python/Dimbo/Exception_Mod.i`` %includes
``dimbo/exception_mod.swg``, then ``modules.i`` must provide a constant
``DIMBO_EXCEPTION_MOD_I`` with value ``<Dimbo/Exception_Mod.i>`` as follows

    #define DIMBO_EXCEPTION_MOD_I <Dimbo/Exception_Mod.i>

The constant name ``DIMBO_EXCEPTION_MOD_I`` above is created as follows:

#. strip ``.swg`` suffix from ``dimbo/exception_mod.swg`` file name,
#. replace all slashes ``/`` with underscore ``_``, 
#. convert the result to uppercase,
#. append ``_I`` suffix

In practice (in ``python`` case, for example) such definitions are generated
automatically by SConscripts.

.. _swig: https://swig.org

.. <!--- vim: set expandtab tabstop=2 shiftwidth=2 syntax=rst: -->
