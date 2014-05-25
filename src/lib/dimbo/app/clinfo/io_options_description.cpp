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

// dimbo/app/clinfo/io_options_description.cpp

/** // doc: dimbo/app/clinfo/io_options_description.cpp {{{
 * \file dimbo/app/clinfo/io_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/app/clinfo/io_options_description.hpp>
#include <dimbo/app/options/option_value.hpp>
#include <dimbo/config.h>
#define DIMBO_GETTEXT_DOMAIN LIBDIMBO_APP_CLINFO_GETTEXT_DOMAIN
#include <dimbo/gettext.hpp>
#include <vector>
#include <string>

namespace Dimbo {
namespace App {
namespace Clinfo {
IO_Options_Description::
IO_Options_Description( unsigned line_length
                          , unsigned min_description_length )
  : Dimbo::App::Options::Options_Description(_("Output Options"), line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
IO_Options_Description::
IO_Options_Description( const std::string & caption
                          , unsigned line_length
                          , unsigned min_description_length )
  : Dimbo::App::Options::Options_Description( caption, line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
IO_Options_Description::
~IO_Options_Description()
{ 
}
void IO_Options_Description::
_init_options_description()
{
  using std::vector;
  using std::string;
  using Dimbo::App::Options::value;
  this->add_options()
    ("output-format,O", value<string>()->value_name("fmt")->default_value("human"),
      _("output format (human/xml/text/bin)"))
    ("input-format,I", value<string>()->value_name("fmt")->default_value("xml"),
      _("input format (xml/text/bin), relevant only with --input"))
    ("input,i", value<string>()->value_name("file"),
      _("read previously saved data from file, see also --input-format"))
    ("output,o", value<string>()->value_name("file"),
      _("save the output to file instead of stdout, see also --output-format"))
  ;
}
} /* namespace Clinfo*/
} /* namespace App*/
} /* namespace Dimbo*/
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
