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

// dimbo/standardized_exception.hpp

/** // doc: dimbo/standardized_exception.hpp {{{
 * \file dimbo/standardized_exception.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_STANDARDIZED_EXCEPTION_HPP_INCLUDED
#define DIMBO_STANDARDIZED_EXCEPTION_HPP_INCLUDED

#include <dimbo/util/std_except_ctor_arg.hpp>
#include <dimbo/src_at.hpp>
#include <exception>

namespace Dimbo {

/**
 * \ingroup Dimbo_Exception
 * @{
 */

/** // {{{
 * \class Dimbo::Standardized_Exception
 * \brief Template class for %Dimbo exceptions generation.
 *
 * This template class helps to generate %Dimbo exception classes which are
 * based on both Dimbo::Exception and one of the standard exception classes
 * (e.g. std::exception).
 *
 * \tparam StdClass
 *         Name of a standard exception base class, from which this exception
 *         will derive.
 * \tparam StdCtorArg
 *         If the StdClass has only the non-default argument with
 *         obligatory argument, its type must be passed via StdCtorArg.
 *
 * Some standard exception classes such as std::runtime_error or
 * std::logic_error have only non-default constructor which takes std::string
 * as an argument. Others have only default and copy constructors. To generate
 * %Dimbo exception class based on one of these classes, it must be known if
 * default constructor in base class is available and, if not, what type of
 * argument must be provided to a constructor. In case there is only
 * non-default constructor, it must be called with an argument provided by
 * class generated from Standardized_Exception. In this case the generated class
 * should also have no default constructor and their constructors should
 * provide an argument to standard exception's constructor. To enable this
 * mechanism, the StdCtorArg provides information about what type of the
 * argument is.
 *
 * If StdCtorArg is the std_except_no_ctor_arg_tag type, then it is assumed
 * than the base standard exception class has default constructor and have no
 * constructor taking any arguments (other than copy-constructor).
 *
 * @note
 * In most situations, the template parameter StdCtorArg may be left
 * unassigned, in which case it will be computed.
 *
 * Example usage:
 * @code
 *   class My_Dimbo_Exception
 *     : public Dimbo::Standardized_Exception<std::exception>
 *   {
 *     My_Dimbo_Exception()
 *      : Standardized_Exception()
 *     {
 *     }
 *     My_Dimbo_Exception(const Src_At& at)
 *      : Standardized_Exception(at)
 *     {
 *     }
 *     const char* what() const throw()
 *     {
 *       return "This is my exception";
 *     }
 *   }
 * @endcode
 *
 * \todo Finish documentation for class Dimbo::Standardized_Exception
 */ // }}}
template <
  class ExceptionBase
, class StdClass
, class StdCtorArg = typename std_except_ctor_arg<StdClass>::type
> class Standardized_Exception
    : public ExceptionBase,
      public StdClass
  {
  public:
    /** // {{{
     *
     * \brief Copy constructor
     *
     * \param e
     * A reference to another instance of Standardized_Exception that will be copied
     * to this object.
     */ // }}}
    explicit Standardized_Exception(Standardized_Exception const& e) throw ()
      : ExceptionBase(e), StdClass(e) { }
    /** // {{{
     * \brief Constructor
     *
     * \param stdArg
     * An argument, that gets passed to the constructor of StdClass. In normal
     * use it is the string that will be returned by the what() method.
     * The method what() is assumed to be implemented in StdClass.
     * \param at
     * A reference to Src_At object that points to the source point of this
     * exception in the source code.
     */ // }}}
    Standardized_Exception(Src_At const& at, StdCtorArg const& arg) throw ()
      :  ExceptionBase(at), StdClass(arg) { }
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual ~Standardized_Exception() throw() {}
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual std::exception const& std_except() const throw()
    {
      return *this;
    }
  };

/** // {{{
 * This is partial specialization of Standardized_Exception class for the cases
 * when StdCtorArg equals to void.
 *
 * \todo Finish documentation for class Dimbo::Standardized_Exception
 */ // }}}
template <class ExceptionBase, class StdClass>
  class Standardized_Exception<ExceptionBase, StdClass,
                               std_except_no_ctor_arg_tag>
    : public ExceptionBase,
      public StdClass
  {
  public:
    /** // {{{
     * \brief Copy constructor
     */ // }}}
    explicit Standardized_Exception(Standardized_Exception const& e) throw ()
      : ExceptionBase(e), StdClass(e) { }
    /** // {{{
     * \brief Constructor
     *
     * \param at
     * A reference to Src_At object that points to the source point of this
     * exception in the source code.
     */ // }}}
    Standardized_Exception(Src_At const& at) throw ()
      : ExceptionBase(at), StdClass() { }
    /** // {{{
     * \todo Write documetation
     */ // }}}
    virtual ~Standardized_Exception() throw() {}
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual std::exception const& std_except() const throw()
    {
      return *this;
    }
  };

/** @} */

} /* namespace Dimbo */

#endif /* DIMBO_STANDARDIZED_EXCEPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
