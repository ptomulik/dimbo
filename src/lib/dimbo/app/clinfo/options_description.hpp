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

// dimbo/app/clinfo/options_description.hpp

/** // doc: dimbo/app/clinfo/options_description.hpp {{{
 * \file dimbo/app/clinfo/options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_CLINFO_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define DIMBO_APP_CLINFO_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <dimbo/app/options/options_description.hpp>
#include <dimbo/app/clinfo/common_options_description.hpp>
#include <dimbo/app/clinfo/platform_general_options_description.hpp>
#include <dimbo/app/clinfo/platform_detail_options_description.hpp>
#include <dimbo/app/clinfo/device_general_options_description.hpp>
#include <dimbo/app/clinfo/device_detail_options_description.hpp>
#include <dimbo/app/clinfo/output_options_description.hpp>

namespace Dimbo {
namespace App {
namespace Clinfo {
/** // {{{
 * \todo Write documentation
 */ // }}}
class Options_Description
  : public Dimbo::App::Options::Options_Description
{
public:
  /** // doc: ~Options_Description() {{{
   * \todo Write documetation
   */ // }}}
  virtual ~Options_Description();
  /** // doc: Options_Description(...) {{{
   * \todo Write documetation
   */ // }}}
  Options_Description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: Options_Description(...) {{{
   * \todo Write documetation
   */ // }}}
  Options_Description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // {{{
   * \todo Write documentation
   */ // }}}
  Common_Options_Description const& common_options() const
    { // {{{
      return this->_common_options;
    } // }}}
  /** // {{{
   * \todo Write documentation
   */ // }}}
  Platform_General_Options_Description const& platform_general_options() const
    { // {{{
      return this->_platform_general_options;
    } // }}}
  /** // {{{
   * \todo Write documentation
   */ // }}}
  Platform_Detail_Options_Description const& platform_detail_options() const
    { // {{{
      return this->_platform_detail_options;
    } // }}}
  /** // {{{
   * \todo Write documentation
   */ // }}}
  Device_General_Options_Description const& device_general_options() const
    { // {{{
      return this->_device_general_options;
    } // }}}
  /** // {{{
   * \todo Write documentation
   */ // }}}
  Device_Detail_Options_Description const& device_detail_options() const
    { // {{{
      return this->_device_detail_options;
    } // }}}
  /** // {{{
   * \todo Write documentation
   */ // }}}
  Output_Options_Description const& output_options() const
    { // {{{
      return this->_output_options;
    } // }}}
private:
  /** // doc _init_options_description() {{{
   * \todo Write documetation
   */ // }}}
  void _init_options_description( );
private:
  Common_Options_Description _common_options;
  Platform_General_Options_Description _platform_general_options;
  Platform_Detail_Options_Description _platform_detail_options;
  Device_General_Options_Description _device_general_options;
  Device_Detail_Options_Description _device_detail_options;
  Output_Options_Description _output_options;
};

} /* namespace Clinfo */
} /* namespace Apps */
} /* namespace Dimbo */
#endif /* DIMBO_APP_CLINFO_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
