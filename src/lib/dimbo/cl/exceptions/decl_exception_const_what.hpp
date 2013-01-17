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

// dimbo/cl/exceptions/decl_exception_const_what.hpp

/** // doc: dimbo/cl/exceptions/decl_exception_const_what.hpp {{{ 
 * \file dimbo/cl/exceptions/decl_exception_const_what.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_DECL_EXCEPTION_CONST_WHAT_HPP_INCLUDED
#define DIMBO_CL_DECL_EXCEPTION_CONST_WHAT_HPP_INCLUDED

#include <dimbo/src_at.hpp>
#include <dimbo/cl/exception.hpp>
#include <dimbo/standardized_exception.hpp>

#define DIMBO_CL_DECL_EXCEPTION_CONST_WHAT(__name,__what,__stdexcpt) \
class Exception_##__name \
  : public Dimbo::Standardized_Exception<Dimbo::Cl::Exception,__stdexcpt> \
{ \
public: \
  Exception_##__name(Dimbo::Src_At const& at) throw() \
    : Standardized_Exception(at) { } \
  Exception_##__name(Exception_##__name const& e) throw() \
    : Standardized_Exception(e) { } \
  virtual ~Exception_##__name() throw() { } \
  virtual char const* what() const throw() \
  { return "Dimbo.Cl: " __what;  } \
};


#endif /* DIMBO_CL_DECL_EXCEPTION_CONST_WHAT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
