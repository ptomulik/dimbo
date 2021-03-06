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

/** // doc: dimbo/swig/dimbo/cl/exceptions/decl_exceptions.swg {{{
 * \file dimbo/swig/dimbo/cl/exceptions/decl_exceptions.swg
 * \todo Write documentation
 */ // }}}

%{
#include <dimbo/exceptions/decl_exception_const_what.hpp>
#include <dimbo/exceptions/decl_exception_ctor_what.hpp>
#include <dimbo/exceptions/decl_bad_alloc.hpp>
#include <dimbo/exceptions/decl_domain_error.hpp>
#include <dimbo/exceptions/decl_exception.hpp>
#include <dimbo/exceptions/decl_invalid_arg.hpp>
#include <dimbo/exceptions/decl_length_error.hpp>
#include <dimbo/exceptions/decl_logic_error.hpp>
#include <dimbo/exceptions/decl_out_of_range.hpp>
#include <dimbo/exceptions/decl_overflow_error.hpp>
#include <dimbo/exceptions/decl_range_error.hpp>
#include <dimbo/exceptions/decl_runtime_error.hpp>
#include <dimbo/exceptions/decl_underflow_error.hpp>
%}

//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::bad_alloc>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::domain_error>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::exception>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::invalid_argument>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::length_error>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::logic_error>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::out_of_range>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::overflow_error>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::range_error>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::runtime_error>;
//%exceptionclass
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::underflow_error>;

%include <dimbo/exceptions/decl_exception_const_what.hpp>
%include <dimbo/exceptions/decl_exception_ctor_what.hpp>
%include <dimbo/exceptions/decl_bad_alloc.hpp>
%include <dimbo/exceptions/decl_domain_error.hpp>
%include <dimbo/exceptions/decl_exception.hpp>
%include <dimbo/exceptions/decl_invalid_arg.hpp>
%include <dimbo/exceptions/decl_length_error.hpp>
%include <dimbo/exceptions/decl_logic_error.hpp>
%include <dimbo/exceptions/decl_out_of_range.hpp>
%include <dimbo/exceptions/decl_overflow_error.hpp>
%include <dimbo/exceptions/decl_range_error.hpp>
%include <dimbo/exceptions/decl_runtime_error.hpp>
%include <dimbo/exceptions/decl_underflow_error.hpp>


//%template(DimboStandardizedException_T_DimboClException_StdBadAlloc)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::bad_alloc>;
//%template(DimboStandardizedException_T_DimboClException_StdDomainError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::domain_error>;
//%template(DimboStandardizedException_T_DimboClException_StdException)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::exception>;
//%template(DimboStandardizedException_T_DimboClException_StdInvalidArg)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::invalid_argument>;
//%template(DimboStandardizedException_T_DimboClException_StdLengthError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::length_error>;
//%template(DimboStandardizedException_T_DimboClException_StdLogicError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::logic_error>;
//%template(DimboStandardizedException_T_DimboClException_StdOutOfRange)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::out_of_range>;
//%template(DimboStandardizedException_T_DimboClException_StdOverflowError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::overflow_error>;
//%template(DimboStandardizedException_T_DimboClException_StdRangeError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::range_error>;
//%template(DimboStandardizedException_T_DimboClException_StdRuntimeError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::runtime_error>;
//%template(DimboStandardizedException_T_DimboClException_StdUnderflowError)
//  Dimbo::Standardized_Exception<Dimbo::Cl::Exception, std::underflow_error>;


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
