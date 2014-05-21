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

// dimbo/app/clinfo/common_options_description.cpp

/** // doc: dimbo/app/clinfo/common_options_description.cpp {{{
 * \file dimbo/app/clinfo/common_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/app/clinfo/common_options_description.hpp>
#include <dimbo/app/options/option_value.hpp>
#include <dimbo/config.h>
#define DIMBO_GETTEXT_DOMAIN LIBDIMBO_CLINFO_GETTEXT_DOMAIN
#include <dimbo/gettext.hpp>
#include <vector>
#include <string>

namespace Dimbo {
namespace App {
namespace Clinfo {

Common_Options_Description::
~Common_Options_Description()

{ // {{{
} // }}}
Common_Options_Description::
Common_Options_Description( unsigned line_length
                          , unsigned min_description_length )
  : Dimbo::App::Common_Options_Description(line_length, min_description_length)
{
  this->_init_options_description();
}

Common_Options_Description::
Common_Options_Description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : Dimbo::App::Common_Options_Description( caption, line_length
                                          , min_description_length)
{
  this->_init_options_description();
}

void Common_Options_Description::
_init_options_description()
{
  using std::vector;
  using std::string;
  using Dimbo::App::Options::value;
  using Dimbo::App::Options::bool_switch;
  this->add_options()
    ("help-detail", _("display detailed options"))
    ("help-platform", _("display detailed platform options"))
    ("help-device", _("display detailed device options"))
    ("config,c", value<string>()->value_name("file"),
      _("read options from `file' (not implemented yet)"))
    ("indent", value<int>()->value_name("num")->default_value(2),
      _("indent each level of output by `num' spaces"))
    ("short,s", bool_switch()->default_value(false),
      _("short listing (no details)"))
  ;
}

} /* namespace Clinfo*/
} /* namespace App*/
} /* namespace Dimbo*/
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:

