---
layout: post
title: "OpenCL python bindings and OpenCL versions"
description: ""
category: 
tags: []
sidenav: home
---
{% include JB/setup %}

I've just faced a situation where the API versions indicated by OpenCL header
**CL/cl.h** differ from what is really provided by **OpenCL.so** library. On my
Debian the **CL/cl.h** had `CL_VERSION_1_2` set to one but the **OpenCL.so**
provided only `1.1`. This caused my OpenCL wrapper to stop working as some of
the wrapped OpenCL functions were simply missing. It appeared that it's not
only me having this problem, see for example 
[this thread on StackOverflow](http://stackoverflow.com/questions/21215024/).

As soon as I tried to load OpenCL module in my python interpreter it raised

```console
ImportError: .../_opencl1_2.so: undefined symbol: clCreateSubDevices
```

This is correct as this function is not available in **OpenCL 1.1** and we
have wrapped everything that was available in **CL/cl.h** which covers also
**1.2**.

I've managed to fix it. In current version DIMBO generates wrappers for all
OpenCL versions from **1.0** through **1.2** available in **CL/cl.h** and saves
them as python modules named `opencl1_0`, `opencl1_1` and `opencl1_2`. The
module `opencl_mod` tries to load in sequence the `opencl1_2`, `opencl1_1` and
`opencl1_0`. The first successfully loaded module wins, so we load a wrapper
for the most most recent API version provided by the **OpenCL.so** used.

For simple diagnostics I've defined a `DIMBO_OPENCL_VERSION` variable which
indicates the OpenCL API version provided by `opencl_mod` module. The following
short python session shows how one may use it

```console
ptomulik@tea:$ scons
ptomulik@tea:$ cd preinst/usr
ptomulik@tea:$ LD_LIBRARY_PATH=lib PYTHONPATH=lib/python/dist-packages/ python -i
>>> from dimbo.cl.opencl_mod import *
>>> DIMBO_OPENCL_VERSION
>>> '1.1'
```

As you see, on my system the **OpenCL.so** provides API version `1.1`. It's
also possible to verify what versions of **OpenCL** were supported at compile
time by the **CL/cl.h** header:

```console
>>> DIMBO_OPENCL_CL_H_VERSION_1_0
1
>>> DIMBO_OPENCL_CL_H_VERSION_1_1
1
>>> DIMBO_OPENCL_CL_H_VERSION_1_2
1
>>> DIMBO_OPENCL_CL_H_VERSION_2_0
0
```

As you see, the supported versions were **1.0**, **1.1** and **1.2**.

<!-- vim: set syntax=markdown: -->
