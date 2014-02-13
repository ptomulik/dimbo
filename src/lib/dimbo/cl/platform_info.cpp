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

// dimbo/cl/platform_info.cpp

/** // doc: dimbo/cl/platform_info.cpp {{{
 * @file dimbo/cl/platform_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/platform_info.hpp>

namespace Dimbo {
namespace Cl {


Platform_Info::
Platform_Info()
{
  _init_platform_info();
}

Platform_Info::
Platform_Info(Platform const& platform,
              Platform_Query const& query)
{
  this->query(platform, query);
}

Platform_Info& Platform_Info::
clear()
{
  this->_id = 0;
  this->_profile.clear();
  this->_version.clear();
  this->_name.clear();
  this->_vendor.clear();
  this->_extensions.clear();
  this->_last_query.select_none();
  return *this;
}

Platform_Info& Platform_Info::
query(Platform const& platform, Platform_Query const& query)
{
  this->clear();
  if(query.id_selected()) {
    this->_id = (unsigned long)platform.id();
  }
  if(query.profile_selected()) {
    this->_profile = platform.get_profile();
  }
  if(query.version_selected()) {
    this->_version = platform.get_version();
  }
  if(query.name_selected()) {
    this->_name = platform.get_name();
  }
  if(query.vendor_selected()) {
    this->_vendor = platform.get_vendor();
  }
  if(query.extensions_selected()) {
    this->_extensions = platform.get_extensions();
  }
  this->_last_query = query;
  return *this;
}

void Platform_Info::
_init_platform_info()
{
  this->clear();
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
