---
layout: post
title: "Support for clang compiler"
description: ""
category: 
tags: []
sidenav: "home"
---
{% include JB/setup %}

From now on the DIMBO may be compiled with either [gcc](http://gcc.gnu.org/) or
the [clang](http://clang.llvm.org/) compiler. I've also implemented a mapping
of several OS environment variables to SCons construction variables so OS
environment variables such as `CC`, `CXX`, `CFLAGS`, etc., affect the build
process.

To build DIMBO with **clang**, one have to just set the `CC` and `CXX`
environment variables:

```console
ptomulik@tea:$ CC=clang CXX=clang++ scons 
```

More details about compilation may be found in
[HOWTO/compile.rst](https://github.com/ptomulik/dimbo/blob/master/HOWTO/compile.rst)
file.

<!-- vim: set syntax=markdown: -->
