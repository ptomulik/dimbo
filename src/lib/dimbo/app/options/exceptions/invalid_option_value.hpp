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

// dimbo/app/options/exceptions/invalid_option_value.hpp

/** // doc: dimbo/app/options/exceptions/invalid_option_value.hpp {{{
 * \file dimbo/app/options/exceptions/invalid_option_value.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_OPTIONS_EXCEPTIONS_INVALID_OPTION_VALUE_HPP_INCLUDED
#define DIMBO_APP_OPTIONS_EXCEPTIONS_INVALID_OPTION_VALUE_HPP_INCLUDED

#include <dimbo/app/options/exception.hpp>
#include <dimbo/exceptions/decl_wrapped_exception.hpp>
#include <boost/program_options/errors.hpp>

namespace Dimbo {
template<>
struct std_except_ctor_arg< boost::program_options::invalid_option_value>
  { typedef boost::program_options::invalid_option_value type; };
} /* namespace Dimbo */

namespace Dimbo {
namespace App {
namespace Options {

DIMBO_DECL_WRAPPED_EXCEPTION(
    Dimbo::App::Options::Exception,
    Invalid_Option_Value,
    boost::program_options::invalid_option_value
);

} /* namespace Options */
} /* namesapce App */
} /* namespace Dimbo */

#endif /* DIMBO_APP_OPTIONS_EXCEPTIONS_INVALID_OPTION_VALUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
