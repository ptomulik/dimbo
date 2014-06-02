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

// dimbo/app/options/exception.hpp

/** // doc:  dimbo/app/options/exception.hpp {{{
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_OPTIONS_EXCEPTION_HPP_INCLUDED
#define DIMBO_APP_OPTIONS_EXCEPTION_HPP_INCLUDED


/* Dimbo includes */
#include <dimbo/app/exception.hpp>

namespace Dimbo {
namespace App {
namespace Options {
class Exception
  : public Dimbo::App::Exception
  {
  public:
    /** // doc: Exception (...) {{{
     * \todo Write documentation
     */ // }}}
    explicit Exception(Exception const& e)
      : Dimbo::App::Exception(e) { }
    /** // {{{
     * \brief Constructor
     *
     * This constructor stores into Dimbo::Exception the reference to exception
     * source in source code.
     */ // }}}
    explicit Exception(Debug_Info const& debug_info) throw()
      : Dimbo::App::Exception(debug_info) { }
    /** // doc: ~Exception () {{{
     * \todo Write documentation
     */ // }}}
    virtual ~Exception() throw() { }
  };
} /* namespace Options */
} /* namespace App */
} /* namespace Dimbo */

#endif
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
