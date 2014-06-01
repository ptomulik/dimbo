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

// dimbo/exceptions/decl_domain_error.hpp

/** // doc: dimbo/exceptions/decl_domain_error.hpp {{{
 * \file dimbo/exceptions/decl_domain_error.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_DECL_DOMAIN_ERROR_HPP_INCLUDED
#define DIMBO_DECL_DOMAIN_ERROR_HPP_INCLUDED

#include <dimbo/exceptions/decl_exception_ctor_what.hpp>
#include <stdexcept>

#define DIMBO_DECL_DOMAIN_ERROR(__klass,__name,__what) \
  DIMBO_DECL_EXCEPTION_CTOR_WHAT(__klass,__name,__what,std::domain_error)

#endif /* DIMBO_DECL_DOMAIN_ERROR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
