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

// dimbo/cl/exceptions/decl_bad_alloc.hpp

/** // doc: dimbo/cl/exceptions/decl_bad_alloc.hpp {{{
 * \file dimbo/cl/exceptions/decl_bad_alloc.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_DECL_BAD_ALLOC_HPP_INCLUDED
#define DIMBO_CL_DECL_BAD_ALLOC_HPP_INCLUDED

#include <dimbo/cl/exceptions/decl_exception_const_what.hpp>
#include <new> // std::bad_alloc

#define DIMBO_CL_DECL_BAD_ALLOC(__name,__what) \
  DIMBO_CL_DECL_EXCEPTION_CONST_WHAT(__name,__what,std::bad_alloc)

#endif /* DIMBO_CL_DECL_BAD_ALLOC_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
