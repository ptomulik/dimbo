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

// dimbo/app/clinfo/common_options_description.hpp

/** // doc: dimbo/app/clinfo/common_options_description.hpp {{{
 * \file dimbo/app/clinfo/common_options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define DIMBO_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <dimbo/app/common_options_description.hpp>

namespace Dimbo {
namespace App {
namespace Clinfo {
/** // doc: class Common_Options_Description {{{
 * \todo Write documentation
 */ // }}}
class Common_Options_Description
  : public Dimbo::App::Common_Options_Description
{
  /** // doc: Common_Options_Description::_init_options_description() {{{
   * \todo Write documentation
   */ // }}}
  void _init_options_description( ) ;
public:
  /** // doc: Common_Options_Description::~Common_Options_Description() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~Common_Options_Description();
  /** // doc: Common_Options_Description(...) {{{
   * \todo Write documentation
   */ // }}}
  Common_Options_Description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: Common_Options_Description(...) {{{
   * \todo Write documentation
   */ // }}}
  Common_Options_Description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} /* namespace Clinfo*/
} /* namespace App*/
} /* namespace Dimbo*/

#endif /* DIMBO_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
