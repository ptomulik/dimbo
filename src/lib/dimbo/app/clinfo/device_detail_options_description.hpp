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

// dimbo/app/clinfo/device_detail_options_description.hpp

/** // doc: dimbo/app/clinfo/device_detail_options_description.hpp {{{
 * \file dimbo/app/clinfo/device_detail_options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_CLINFO_DEVICE_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define DIMBO_APP_CLINFO_DEVICE_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <dimbo/app/options/options_description.hpp>

namespace Dimbo {
namespace App {
namespace Clinfo {
/** // doc: class Device_Detail_Options_Description {{{
 * \todo Write documentation
 */ // }}}
class Device_Detail_Options_Description
  : public Dimbo::App::Options::Options_Description
{
private:
  void _init_options_description();
public:
  /** // doc: ~Device_Detail_Options_Description() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~Device_Detail_Options_Description();
  /** // {{{
   * \todo Write documetation
   */ // }}}
  Device_Detail_Options_Description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // {{{
   * \todo Write documetation
   */ // }}}
  Device_Detail_Options_Description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} /* namespace Clinfo*/
} /* namespace App*/
} /* namespace Dimbo*/

#endif /* DIMBO_APP_CLINFO_DEVICE_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
