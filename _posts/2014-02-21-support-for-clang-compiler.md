---
layout: post
title: "Support for clang compiler"
description: ""
category: 
tags: []
sidenav: "home"
---
{% include JB/setup %}

From now on DIMBO may be compiled with either [gcc](http://gcc.gnu.org/) or
[clang](http://clang.llvm.org/) compiler. I've also mapped several OS
environment variables to SCons construction variables so variables such as
`CC`, `CXX`, `CFLAGS`, etc., affect the build process.

To build DIMBO with **clang**, one have to just set the `CC` and `CXX`
environment variables:

```console
CC=clang CXX=clang++ scons 
```

More details about compilation may be found in
[HOWTO/compile.rst](https://github.com/ptomulik/dimbo/blob/master/HOWTO/compile.rst)
file.

<!-- vim: set syntax=markdown: -->
