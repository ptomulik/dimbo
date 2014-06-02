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

// dimbo/cl/exceptions/bad_alloc.hpp

/** // doc: dimbo/cl/exceptions/bad_alloc.hpp {{{
 * \file dimbo/cl/exceptions/bad_alloc.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_EXCEPTIONS_BAD_ALLOC_HPP_INCLUDED
#define DIMBO_CL_EXCEPTIONS_BAD_ALLOC_HPP_INCLUDED

#include <dimbo/cl/exception.hpp>
#include <dimbo/exceptions/decl_bad_alloc.hpp>
#include <dimbo/cl/exceptions/common.hpp>

namespace Dimbo {
namespace Cl {

DIMBO_DECL_BAD_ALLOC(Dimbo::Cl::Exception, Bad_Alloc,"Memory allocation failed");

} // namespace Cl
} // namespace Dimbo

#endif /* DIMBO_CL_EXCEPTIONS_BAD_ALLOC_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
