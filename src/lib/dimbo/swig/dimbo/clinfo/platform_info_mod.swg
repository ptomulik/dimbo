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

/** // doc: dimbo/clinfo/platform_mod.swg {{{
 * \file dimbo/clinfo/platform_mod.swg
 * \todo Write documentation
 */ // }}}

%include <dimbo/swig_config.swg>

//%include <boost_shared_ptr.i>
//%shared_ptr(Dimbo::Clinfo::Platform_Info)
//%shared_ptr(Dimbo::Clinfo::Device_Info)
%include <std_vector.i>

%import <dimbo/clinfo/exception_mod.i>
%{
#include <dimbo/clinfo/exception_mod.hpp>
%}

//%include <dimbo/clinfo/device_query.swg>
%include <dimbo/clinfo/device_info.swg>
//%include <dimbo/clinfo/platform_query.swg>
%include <dimbo/clinfo/platform_info.swg>
//%include <dimbo/clinfo/platform_layer_info.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
