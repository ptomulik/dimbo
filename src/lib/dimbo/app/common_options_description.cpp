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

// dimbo/app/common_options_description.cpp

/** // doc: dimbo/app/common_options_description.cpp {{{
 * \file dimbo/app/common_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/app/common_options_description.hpp>
#include <dimbo/config.h>
#define DIMBO_GETTEXT_DOMAIN LIBDIMBO_APP_GETTEXT_DOMAIN
#include <dimbo/gettext.hpp>

namespace Dimbo {
namespace App {
Common_Options_Description::
~Common_Options_Description()
{
}
Common_Options_Description::
Common_Options_Description( unsigned line_length
                          , unsigned min_description_length )
  : Options::Options_Description(line_length, min_description_length)
{
  this->_init_options_description();
}
Common_Options_Description::
Common_Options_Description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : Options::Options_Description(caption, line_length, min_description_length)
{
  this->_init_options_description();
}
void Common_Options_Description::
_init_options_description()
{
  this->add_options()
    /* TRANSLATORS: This is for --help option of any dimbo application */
    ("help,h",_("print help"))
    /* TRANSLATORS: This is for --version option of any dimbo application */
    ("version,v",_("print program version"))
  ;
}
} /* namespace App*/
} /* namespace Dimbo*/
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
