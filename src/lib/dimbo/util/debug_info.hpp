/*
 * @COPYRIGHT@
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

//  dimbo/util/debug_info.hpp

/** // doc: dimbo/util/debug_info.hpp {{{
 * \file dimbo/util/debug_info.hpp
 * \todo Write documentation
 *
 * This file provides the class Dimbo::Debug_Info which defines single point in
 * source code (including source file name, line number and function). It also
 * provides a \ref DIMBO_HERE helper macro to simplify object creation.
 */ //  }}}
#ifndef DIMBO_UTIL_DEBUG_INFO_HPP_INCLUDED
#define DIMBO_UTIL_DEBUG_INFO_HPP_INCLUDED

#include <cstring>
#include <algorithm>
#include <boost/current_function.hpp>

/** // {{{
 * \def DIMBO_HERE
 * \hideinitializer
 * This macro returns encapsulated information about current line in source
 * code. It simply creates an object of type Dimbo::Debug_Info. Example usage:
 * \code
 *   throw Dimbo::Cl::Exception_Uninitialized_Device(DIMBO_HERE)
 * \endcode
 *
 * \see Dimbo::Debug_Info
 */ // }}}
#ifdef SOURCE_DIR
// FIXME: I'm not sure if __FILE_ + sth is safe
#  define DIMBO_HERE Dimbo::Debug_Info(BOOST_CURRENT_FUNCTION, \
                                 __FILE__ + std::strlen(SOURCE_DIR) + 1, \
                                 __LINE__)
#else
#  define DIMBO_HERE Dimbo::Debug_Info(BOOST_CURRENT_FUNCTION, \
                                 __FILE__, \
                                 __LINE__)
#endif

namespace Dimbo {
/** // {{{
 * \brief Representation of single point within source code.
 *
 * This class represents single point within source code. The information
 * stored by Std_At object consists of
 * - function name
 * - file name
 * - line number
 *
 *
 * The class is designated to hold the source point for exception thrown
 * from within the DIMBO (see the Dimbo::Exception::debug_info() method).
 */ // }}}
class Debug_Info
{
protected:
  /** \brief  Maximum length of function name stored in this class. */
  static const size_t _function_len_max = 160;
  /** \brief Maximum length of file name stored in this class. */
  static const size_t _file_len_max = 160;
private:
  char _function[_function_len_max+1];
  char _file[_file_len_max+1];
  int  _line;
public:
  virtual ~Debug_Info() throw() { }
  /** // {{{
   * \brief Default constructor.
   *
   * Initializes the class to default values:
   * - function = ""
   * - file = ""
   * - line = 0
   */ // }}}
  Debug_Info() throw()
  {
    this->set_function("");
    this->set_file("");
    this->set_line(0);
  }
  /** // {{{
   * \brief Copy constructor
   * \param debug_info
   *        Source object.
   * \see Debug_Info::operator=()
   */ // }}}
  Debug_Info(Debug_Info const& debug_info)
  {
    this->assign(debug_info);
  }
  /** // {{{
   * \brief Constructor with single argument, sets function name.
   * \param fcn
   *        Name of the function, to which this object points.
   * Other values are set to defaults (see default constructor
   * Debug_Info::Debug_Info()).
   */ // }}}
  Debug_Info(char const* fcn) throw()
  {
    this->set_function(fcn);
    this->set_file("");
    this->set_line(0);
  }
  /** // {{{
   * \brief Constructor with three arguments
   * \param fcn
   *        Function within the source file poited to by this object.
   * \param file
   *        Name of source code file to which this object points.
   * \param line
   *        Line number of the source code within the source file.
   */ // }}}
  Debug_Info(char const* fcn, char const* file, int line)
  {
    this->set_function(fcn);
    this->set_file(file);
    this->set_line(line);
  }
  /** // {{{
   * \brief Define the name of the function pointed to by this object
   * \param f
   *        The name of the function
   * \note Too long function names are truncated to the lenth determined by
   *       Debug_Info::_function_len_max.
   */ // }}}
  void set_function(char const* f) throw()
  {
    std::strncpy(this->_function, f, _function_len_max);
    this->_function[_function_len_max] = '\x0';
  }
  /** // {{{
   * \brief Define the name of the file pointed to by this object
   * \param f
   *        The name of the file.
   * \note Too long file names are truncated to the lenth determined by
   *       Debug_Info::_file_len_max.
   */ // }}}
  void set_file(char const* f) throw()
  {
    std::strncpy(this->_file, f, _file_len_max);
    this->_file[_file_len_max] = '\x0';
  }
  /** // {{{
   * \brief Define the line number within the file pointed to by this object.
   * \param l
   *        The line number.
   */ // }}}
  void set_line(int l) throw()
  {
    this->_line = l;
  }
  /** // {{{
   * \brief Get the function name of the function pointed to by this object.
   * \return The function name.
   */ // }}}
  virtual char const* function() const throw()
  {
    return this->_function;
  }
  /** // {{{
   * \brief Get the file name of the source file pointed to by this object.
   * \return The file name
   */ // }}}
  virtual char const* file() const throw()
  {
    return this->_file;
  }
  /** // {{{
   * \brief Get the line of the the source line pointed to by this object.
   * \todo Finish documentation
   */ // }}}
  virtual int line() const throw()
  {
    return this->_line;
  }
/* FIXME: develop more verbose constant name */
#ifndef SWIG
  /** // {{{
   * \brief Assignment operator.
   * \param rhs
   *        An another object, which will be copied to this object.
   * \return
   *        The reference to this object.
   */ // }}}
  Debug_Info& operator=(Debug_Info const& rhs)
  {
    this->assign(rhs);
    return *this;
  }
#endif
  /** // {{{
   * \brief Assignment function.
   * \param rhs
   *        An another object, which will be copied to this object.
   */ // }}}
  void assign(Debug_Info const& rhs)
  {
    if(&rhs != this)
      {
        this->set_function(rhs.function());
        this->set_file(rhs.file());
        this->set_line(rhs.line());
      }
  }
};
} /* namespace Dimbo */

#endif /* DIMBO_UTIL_DEBUG_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
