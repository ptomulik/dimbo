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

// dimbo/app/options/option_value.hpp

/** // doc: dimbo/app/options/option_value.hpp {{{ 
 * \file dimbo/app/options/option_value.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_OPTIONS_OPTION_VALUE_HPP_INCLUDED
#define DIMBO_APP_OPTIONS_OPTION_VALUE_HPP_INCLUDED

#include <boost/program_options/value_semantic.hpp>

/** // doc: BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX {{{
 * \todo Write documentation
 */ // }}}
#define BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX 1
// FIXME: I'm not sure, in which version of Boost.ProgramOptions the member
// function boost::program_options::typed_value<T,charT>::value_name()'
// will be implemented (it's already in svn, but ...). When it will be clear,
// just uncomment following lines (replacing 2 with correct version number):
/* #include <boost/program_options/version.hpp>
 * #define BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX \
 *   (BOOST_PROGRAM_OPTIONS_VERSION <= 2) */


#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX 
namespace boost { namespace program_options {
extern BOOST_PROGRAM_OPTIONS_DECL std::string arg;
}}
#endif

namespace Dimbo {
namespace App {
namespace Options {

/** // doc: class Option_Value {{{
 * \todo Write documentation
 */ // }}}
template <class T, class charT = char>
class Option_Value 
  : public boost::program_options::typed_value<T, charT>
{
public:
  /** // doc: ~Option_Value() {{{
   * \todo Write documentation for class Option_Value
   */ // }}}
  virtual ~Option_Value()
  { // {{{
  } // }}}

  /** // doc: Option_Value(...) {{{
   * \todo Write documentation
   */ // }}}
  Option_Value(T* store_to)
    : boost::program_options::typed_value<T,charT>(store_to)
  { // {{{
  } // }}}

#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
  /** // doc: foo() {{{
   * \todo Write documentation
   */ // }}}
  std::string name( ) const;

  /** // doc: value_name(n) {{{
   * \todo Write documentation
   */ // }}}
  Option_Value* value_name(std::string const& n)
  { // {{{
    this->_value_name = n;
    return this;
  } // }}}
#endif

private:
#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
  std::string _value_name;
#endif
};

/** // doc: value(v) {{{
 * \todo Write documentation
 */ // }}}
template<class T>
Option_Value<T>* 
value(T* v)
{ // {{{
  Option_Value<T> *r = new Option_Value<T>(v);
  return r;
} // }}}

/** // doc: value() {{{
 * \todo Write documentation
 */ // }}}
template<class T>
Option_Value<T>* 
value()
{ // {{{
  return Dimbo::App::Options::value<T>(0);
} // }}}

/** // doc: wvalue(v) {{{
 * \todo Write documentation
 */ // }}}
template<class T>
Option_Value<T, wchar_t>* 
wvalue(T* v)
{ // {{{
  Option_Value<T,wchar_t>* r = new Option_Value<T,wchar_t>(v);
  return r;
} // }}}

/** // doc: wvalue() {{{
 * \todo Write documentation
 */ // }}}
template<class T>
Option_Value<T, wchar_t>* 
wvalue()
{ // {{{
  return Dimbo::App::Options::wvalue<T>(0);
} // }}}

/** // doc: bool_switch(v) {{{
 * \todo Write documentation
 */ // }}}
BOOST_PROGRAM_OPTIONS_DECL inline Option_Value<bool>*
bool_switch(bool* v)
{ // {{{
  Option_Value<bool>* r = new Option_Value<bool>(v);
  r->default_value(0);
  r->zero_tokens();

  return r;
} // }}}

/** // doc: bool_switch() {{{
 * \todo Write documentation
 */ // }}}
BOOST_PROGRAM_OPTIONS_DECL inline Option_Value<bool>*
bool_switch()
{ // {{{
  return bool_switch(0);
} // }}}

#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
template<class T, class charT>
std::string Option_Value<T, charT>::
name() const
{ // {{{
  using std::string;
  string my_name(boost::program_options::typed_value<T,charT>::name());
  if(!this->_value_name.empty())
    {
      // Ugly fix. I hope, that BOOST > 1.49 will implement "value_name" on its
      // own. The code is based on reverse engineering of name() implementation
      // found in boost/program_options/detail/value_semantic.hpp (ver. 1.49).
      size_t pos;
      using boost::program_options::arg;
      string pattern("[=arg(=");
      pos = my_name.find(pattern);
      if(pos != string::npos)
        {
          string replacement(string("[=") + this->_value_name + string("(="));
          my_name.replace(pos,pattern.length(),replacement);
        }
      pos = my_name.find(arg);
      if(pos != string::npos)
        {
          my_name.replace(pos,arg.length(),this->_value_name);
        }
    }
  return my_name;
} // }}}
#endif
} /* namespace Options */
} /* namespace App */
} /* namespace Dimbo */
#endif /* DIMBO_APP_OPTIONS_OPTION_VALUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
