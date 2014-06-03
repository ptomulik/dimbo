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

// dimbo/exception.hpp

/** // doc: dimbo/exception.hpp {{{
 * \file dimbo/exception.hpp
 * This file provides base classes for %Dimbo exceptions.
 */ // }}}

#ifndef DIMBO_EXCEPTION_HPP_INCLUDED
#define DIMBO_EXCEPTION_HPP_INCLUDED

#include <dimbo/util/debug_info.hpp>
#include <exception>


namespace Dimbo {

/** // {{{
 * \ingroup Dimbo_Exception
 * \brief Base class for all %Dimbo exceptions.
 *
 * All %Dimbo exceptions shall be descendants of Dimbo::Exception. Note, that
 * the class is not designated to derive directly from it. For your own
 * exceptions use Dimbo::Standardized_Exception or its descendants.
 *
 * @attention
 * Do not derive from this class directly. Use Dimbo::Standardized_Exception template
 * class instead.
 *
 * \note
 * This is dummy class, concrete exceptions should derive also from concrete
 * standard exception(s) using multiple inheritance.
 *
 * \todo Write documentation for class Dimbo::Exception.
 *
 * \todo Develop some code to discourage developers to derive classes
 *       directly from this Dimbo::Exception.
 */ // }}}
class Exception
  {
  public:
    /** // {{{
     * \brief Constructor
     *
     * This constructor stores into Dimbo::Exception the reference to exception
     * source in source code.
     */ // }}}
    Exception(Debug_Info const& debug_info) throw()
    {
      this->set_debug_info(debug_info);
    }
    /** // {{{
     * \brief Copy constructor.
     * \todo Write documentation
     */ // }}}
    explicit Exception(Exception const& e) throw()
    {
      this->set_debug_info(e.debug_info());
    }
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual ~Exception() throw() {}
    /** // {{{
     * \brief Get reference to the instance of std::exception bound to this
     *        object.
     *
     * \return Reference to the std::exception instance bound to this object.
     */ // }}}
    virtual std::exception const& std_except() const throw() = 0;
    /** // {{{
     * \brief Define the source of this exception
     *
     * \param debug_info
     * An object of type Debug_Info defining the source of this exception within
     * the source code.
     */ // }}}
    void set_debug_info(Dimbo::Debug_Info const& debug_info) throw()
    {
      this->_debug_info = debug_info;
    }
    /** // {{{
     * \brief Get the source of this exception
     * \return A reference to Debug_Info object defining the source of this
     *         exception.
     */ // }}}
    Dimbo::Debug_Info const& debug_info() const throw()
    {
      return this->_debug_info;
    }
  private:
    Debug_Info _debug_info;
    std::exception const* _std_except;
    /** // {{{
     * \todo Write documentation
     */ // }}}
    Exception& operator=(Exception const&) throw();
    /** // {{{
     * \brief Default constructor (denied).
     * \todo Write documentation
     */ // }}}
    Exception();
  };


} /* namespace Dimbo */


#endif /* DIMBO_EXCEPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
