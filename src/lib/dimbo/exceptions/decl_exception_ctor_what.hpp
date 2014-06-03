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

// dimbo/exceptions/decl_exception_ctor_what.hpp

/** // doc: dimbo/exceptions/decl_exception_ctor_what.hpp {{{
 * \file dimbo/exceptions/decl_exception_ctor_what.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_DECL_EXCEPTION_CTOR_WHAT_HPP_INCLUDED
#define DIMBO_DECL_EXCEPTION_CTOR_WHAT_HPP_INCLUDED

#include <dimbo/standardized_exception.hpp>
#include <dimbo/util/debug_info.hpp>
#include <string>

#define DIMBO_DECL_EXCEPTION_CTOR_WHAT(__base,__name,__what,__stdexcpt) \
class Exception_##__name \
  : public Dimbo::Standardized_Exception<__base,__stdexcpt> \
{ \
public: \
  Exception_##__name(Dimbo::Debug_Info const& debug_info) throw() \
    : Standardized_Exception(debug_info, std::string(__what)) { } \
  Exception_##__name(Exception_##__name const& e) throw() \
    : Standardized_Exception(e) { } \
  virtual ~Exception_##__name() throw() { } \
}

#endif /* DIMBO_DECL_EXCEPTION_CTOR_WHAT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
