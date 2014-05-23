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

// dimbo/clinfo/platform_info.cpp

/** // doc: dimbo/clinfo/platform_info.cpp {{{
 * @file dimbo/clinfo/platform_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/clinfo/platform_info.hpp>

namespace Dimbo {
namespace Clinfo {

/* ------------------------------------------------------------------------ */
Platform_Info::
Platform_Info()
{
  _init();
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear()
{
  this->_clear_flags();
  this->_clear_values();
  return *this;
}
/* ------------------------------------------------------------------------ */
void Platform_Info::
_init()
{
  this->_clear();
}
/* ------------------------------------------------------------------------ */
void Platform_Info::
_clear()
{
  using boost::detail::none_t;
  this->_id = none_t;
  this->_profile = none_t;
  this->_version = none_t;
  this->_name = none_t;
  this->_vendor = none_t;
  this->_extensions = none_t;
}
/* ------------------------------------------------------------------------ */
bool operator==(Platform_Info const& a, Platform_Info const& b)
{
  if(((a.id() != b.id()))
  || ((a.profile() != b.profile()))
  || ((a.version() != b.version()))
  || ((a.name() != b.name()))
  || ((a.vendor() != b.vendor()))
  || ((a.extensions() != b.extensions())))
    return false;
  return true;
}
/* ------------------------------------------------------------------------ */
} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
