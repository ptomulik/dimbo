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

// dimbo/app/options/options_description.hpp

/** // doc: dimbo/app/options/options_description.hpp {{{
 * \file dimbo/app/options/options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define DIMBO_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <boost/program_options/options_description.hpp>

namespace Dimbo {
namespace App {
namespace Options {
/** // doc: Options_Description {{{
 * \todo Write documentation
 */ // }}}
class Options_Description
  : public boost::program_options::options_description
{
public:
  /** // doc: Option_Description {{{
   * \todo Write documentation
   */ // }}}
  typedef boost::program_options::option_description Option_Description;
public:
  /** // doc: ~Options_Description() {{{
   * \todo Write documentation
   */ // }}}
  ~Options_Description();
  /** // doc: Options_Description(...) {{{
   * \todo Write documentation
   */ // }}}
  Options_Description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: Options_Description(...) {{{
   * \todo Write documentation
   */ // }}}
  Options_Description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} /* Options */
} /* namespace App*/
} /* namespace Dimbo*/

#endif /* DIMBO_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
