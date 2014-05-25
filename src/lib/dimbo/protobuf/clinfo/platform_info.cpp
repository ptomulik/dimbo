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

/** // doc: dimbo/protobuf/clinfo/platform_info.cpp {{{
 * \file dimbo/protobuf/clinfo/platform_info.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/protobuf/clinfo/platform_info.hpp>

namespace Dimbo {
namespace Protobuf {

/* ------------------------------------------------------------------------ */
void write(Dimbo::Protobuf::Clinfo::Platform_Info& buf,
           Dimbo::Clinfo::Platform_Info const& obj)
{
  buf.Clear();
  if(obj.has_id()) buf.set_id(obj.id());
  if(obj.has_profile()) buf.set_profile(obj.profile());
  if(obj.has_version()) buf.set_version(obj.version());
  if(obj.has_name()) buf.set_name(obj.name());
  if(obj.has_vendor()) buf.set_vendor(obj.vendor());
  if(obj.has_extensions()) buf.set_extensions(obj.extensions());
}
/* ------------------------------------------------------------------------ */
void read(Dimbo::Protobuf::Clinfo::Platform_Info const& buf,
          Dimbo::Clinfo::Platform_Info& obj)
{
  obj.clear();
  if(buf.has_id()) obj.set_id(buf.id());
  if(buf.has_profile()) obj.set_profile(buf.profile());
  if(buf.has_version()) obj.set_version(buf.version());
  if(buf.has_name()) obj.set_name(buf.name());
  if(buf.has_vendor()) obj.set_vendor(buf.vendor());
  if(buf.has_extensions()) obj.set_extensions(buf.extensions());
}
/* ------------------------------------------------------------------------ */

} /* namesapce Protobuf */
} /* namespace Dimbo */

/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Platform_Info&
operator<<(Dimbo::Protobuf::Clinfo::Platform_Info& buf,
           Dimbo::Clinfo::Platform_Info const& obj)
{
  Dimbo::Protobuf::write(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Platform_Info const&
operator>>(Dimbo::Protobuf::Clinfo::Platform_Info const& buf,
           Dimbo::Clinfo::Platform_Info& obj)
{
  Dimbo::Protobuf::read(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
