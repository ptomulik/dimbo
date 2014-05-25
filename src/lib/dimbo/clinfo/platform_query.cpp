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

// dimbo/clinfo/platform_query.cpp

/** // doc: dimbo/clinfo/platform_query.cpp {{{
 * @file dimbo/clinfo/platform_query.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/clinfo/platform_query.hpp>

namespace Dimbo {
namespace Clinfo {

/* ------------------------------------------------------------------------ */
Platform_Query::
Platform_Query()
{
  this->_init(true);
}
/* ------------------------------------------------------------------------ */
Platform_Query::
Platform_Query(bool flag)
{
  this->_init(flag);
}
/* ------------------------------------------------------------------------ */
Platform_Query::
~Platform_Query()
{
}
/* ------------------------------------------------------------------------ */
void Platform_Query::
_init(bool flag)
{
  this->_select(flag);
}
/* ------------------------------------------------------------------------ */
void Platform_Query::
_select(bool flag)
{
  this -> select_id(flag);
  this -> select_profile(flag);
  this -> select_version(flag);
  this -> select_name(flag);
  this -> select_vendor(flag);
  this -> select_extensions(flag);
}
/* ------------------------------------------------------------------------ */
Platform_Query& Platform_Query::
select_all()
{
  this->_select(true);
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Query& Platform_Query::
select_none()
{
  this->_select(false);
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Query& Platform_Query::
select_default()
{
  return this->select_all();
}
/* ------------------------------------------------------------------------ */
bool operator== (Platform_Query const& a, Platform_Query const& b)
{
  return  (a.id_selected() == b.id_selected()) &&
          (a.profile_selected() == b.profile_selected()) &&
          (a.version_selected() == b.version_selected()) &&
          (a.name_selected() == b.name_selected()) &&
          (a.vendor_selected() == b.vendor_selected()) &&
          (a.extensions_selected() == b.extensions_selected());
}
/* ------------------------------------------------------------------------ */

} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
