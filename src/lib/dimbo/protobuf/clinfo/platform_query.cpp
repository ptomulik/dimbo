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

/** // doc: dimbo/protobuf/clinfo/platform_query.cpp {{{
 * \file dimbo/protobuf/clinfo/platform_query.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/protobuf/clinfo/platform_query.hpp>

namespace Dimbo {
namespace Protobuf {

/* ------------------------------------------------------------------------ */
void write(Dimbo::Protobuf::Clinfo::Platform_Query& buf,
           Dimbo::Clinfo::Platform_Query const& obj)
{
  buf.Clear();
  // Put to buffer only fields that differ from their defaults.
  if(!obj.id_selected()) buf.set_id_selected(false);
  if(!obj.profile_selected()) buf.set_profile_selected(false);
  if(!obj.version_selected()) buf.set_version_selected(false);
  if(!obj.name_selected()) buf.set_name_selected(false);
  if(!obj.vendor_selected()) buf.set_vendor_selected(false);
  if(!obj.extensions_selected()) buf.set_extensions_selected(false);
}
/* ------------------------------------------------------------------------ */
void read(Dimbo::Protobuf::Clinfo::Platform_Query const& buf,
          Dimbo::Clinfo::Platform_Query& obj)
{
  obj.select_default();
  if(buf.has_id_selected()) obj.select_id(buf.id_selected());
  if(buf.has_profile_selected()) obj.select_profile(buf.profile_selected());
  if(buf.has_version_selected()) obj.select_version(buf.version_selected());
  if(buf.has_name_selected()) obj.select_name(buf.name_selected());
  if(buf.has_vendor_selected()) obj.select_vendor(buf.vendor_selected());
  if(buf.has_extensions_selected()) obj.select_extensions(buf.extensions_selected());
}
/* ------------------------------------------------------------------------ */

} /* namesapce Protobuf */
} /* namespace Dimbo */

/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Platform_Query&
operator<<(Dimbo::Protobuf::Clinfo::Platform_Query& buf,
           Dimbo::Clinfo::Platform_Query const& obj)
{
  Dimbo::Protobuf::write(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Platform_Query const&
operator>>(Dimbo::Protobuf::Clinfo::Platform_Query const& buf,
           Dimbo::Clinfo::Platform_Query& obj)
{
  Dimbo::Protobuf::read(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
