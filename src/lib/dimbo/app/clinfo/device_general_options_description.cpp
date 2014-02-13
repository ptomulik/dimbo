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

// dimbo/app/clinfo/device_general_options_description.cpp

/** // doc: dimbo/app/clinfo/device_general_options_description.cpp {{{
 * \file dimbo/app/clinfo/device_general_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/app/clinfo/device_general_options_description.hpp>
#include <dimbo/app/options/option_value.hpp>
#include <dimbo/config.h>
#define DIMBO_GETTEXT_DOMAIN LIBDIMBO_CLINFO_GETTEXT_DOMAIN
#include <dimbo/gettext.hpp>
#include <vector>
#include <string>

namespace Dimbo {
namespace App {
namespace Clinfo {

Device_General_Options_Description::
Device_General_Options_Description( unsigned line_length
                                  , unsigned min_description_length )
  : Dimbo::App::Options::Options_Description(_("Device General Options")
                                            , line_length
                                            , min_description_length)
{
  this->_init_options_description();
}

Device_General_Options_Description::
Device_General_Options_Description( const std::string & caption
                                  , unsigned line_length
                                  , unsigned min_description_length)
  : Dimbo::App::Options::Options_Description( caption, line_length
                                            , min_description_length)
{
  this->_init_options_description();
}

Device_General_Options_Description::
~Device_General_Options_Description()
{
}

void Device_General_Options_Description::
_init_options_description()
{
  using Dimbo::App::Options::value;
  using Dimbo::App::Options::bool_switch;
  using std::vector;
  using std::string;
  this->add_options()
    ("no-devices,D"
    , bool_switch()->default_value(false)
      /* TRANSLATORS: this is for --no-devices option */
    , _("do not list devices"))
  ;
}

} /* namespace Clinfo*/
} /* namespace App*/
} /* namespace Dimbo*/
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
