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

/** // doc: dimbo/s11n/clinfo/platform_info.swg {{{
 * \file dimbo/s11n/clinfo/platform_info.swg
 * \todo Write documentation
 */ // }}}

%{
#include <dimbo/s11n/clinfo/platform_info.hpp>
#include <dimbo/s11n/boost_archives.hpp>
#include <dimbo/s11n/shared_ptr.hpp>
%}

%include <dimbo/s11n/clinfo/platform_info.hpp>
%import <dimbo/s11n/boost_archives.swg>
%import <dimbo/shared_ptr.swg>
DIMBO_EXTEND_BOOST_ARCHIVES(Dimbo::Clinfo::Platform_Info);
DIMBO_EXTEND_BOOST_ARCHIVES(DIMBO_SHARED_PTR(Dimbo::Clinfo::Platform_Info));

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
