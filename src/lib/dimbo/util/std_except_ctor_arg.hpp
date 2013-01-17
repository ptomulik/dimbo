
/* @COPYRIGHT@
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */
// dimbo/util/std_except_ctor_arg.hpp

/** // doc: dimbo/util/std_except_ctor_arg.hpp {{{
 * \file dimbo/util/std_except_ctor_arg.hpp
 * \todo Write documentation for
 */ // }}}
#ifndef DIMBO_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED
#define DIMBO_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED

#include <exception>
#include <stdexcept>
#include <new>

namespace Dimbo {
/** // {{{
 * \ingroup Dimbo_Exception
 * \brief A tag denoting that certain standard exception class has only default
 *        (and perhaps copy) constructor and no other unary constructors.
 */ // }}}
struct std_except_no_ctor_arg_tag {};

/** // {{{
 * \ingroup Dimbo_Exception
 * \brief Metafunction to determine argument type for standard exception's
 *        non-default (and not the copy-) constructor.
 *
 * Some standard exception classes such as \c std::runtime_error or \c
 * std::logic_error have only non-default constructor which takes \c
 * std::string as an argument. Others have only default and copy constructors
 * and no other constructors taking an argument. This metafunction determines
 * the type of argument to constructors of well defined standard exceptions. In
 * case a given exception has only default (and copy) constructor, the
 * metafunction returns  std_except_no_ctor_arg_tag.
 */ // }}}
template<class ExcpClass>
struct std_except_ctor_arg 
  {
  };
template<>
struct std_except_ctor_arg< std::exception >
  {
    typedef std_except_no_ctor_arg_tag type;
  };
template<>
struct std_except_ctor_arg< std::bad_exception >
  {
    typedef std_except_no_ctor_arg_tag type;
  };
template<>
struct std_except_ctor_arg< std::logic_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::domain_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::invalid_argument >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::length_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::out_of_range >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::runtime_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::range_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::overflow_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::underflow_error >
  {
    typedef std::string type;
  };
template<>
struct std_except_ctor_arg< std::bad_alloc>
  {
    typedef std_except_no_ctor_arg_tag type;
  };
} /* namespace Dimbo */

#endif /* DIMBO_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
