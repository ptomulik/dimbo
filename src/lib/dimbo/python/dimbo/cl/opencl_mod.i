/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

/** // doc: dimbo/cl/opencl_mod.i {{{
 * \file dimbo/cl/opencl_mod.i
 * \todo Write documentation
 */ // }}}

%module(package="dimbo_.cl") opencl_mod
%feature("autodoc","3");
%include <dimbo/cl/opencl_mod.swg>
%pythoncode %{

# Attempt to load wrapper for a most recent available OpenCL version. This is
# best we can do. The other option would be to find actual version of the
# OpenCL API, but for that we had to query platform info. This initializes
# OpenCL platform which usually takes few seconds. We can't wait so long to
# just get a version number. Here we recognize enemy with fire and take first
# succesfull shot as a result.
DIMBO_OPENCL_VERSION = None
if (DIMBO_OPENCL_VERSION is None) and (DIMBO_OPENCL_CL_H_VERSION_2_0 == 1):
  try:
    from dimbo_.cl.opencl2_0 import *
    DIMBO_OPENCL_VERSION = "2.0"
  except ImportError:
    pass

if (DIMBO_OPENCL_VERSION is None) and (DIMBO_OPENCL_CL_H_VERSION_1_2 == 1):
  try:
    from dimbo_.cl.opencl1_2 import *
    DIMBO_OPENCL_VERSION = "1.2"
  except ImportError:
    pass

if (DIMBO_OPENCL_VERSION is None) and (DIMBO_OPENCL_CL_H_VERSION_1_1 == 1):
  try:
    from dimbo_.cl.opencl1_1 import *
    DIMBO_OPENCL_VERSION = "1.1"
  except ImportError:
    pass

if (DIMBO_OPENCL_VERSION is None) and (DIMBO_OPENCL_CL_H_VERSION_1_0 == 1):
  from dimbo_.cl.opencl1_1 import *
  DIMBO_OPENCL_VERSION = "1.0"

%}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
