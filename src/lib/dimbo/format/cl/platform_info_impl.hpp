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

// dimbo/format/cl/platform_info_impl.hpp

#ifndef DIMBO_FORMAT_CL_PLATFORM_INFO_IMPL
#define DIMBO_FORMAT_CL_PLATFORM_INFO_IMPL

/** // doc: dimbo/format/cl/platform_info_impl.hpp {{{
 * @file dimbo/format/cl/platform_info_impl.hpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/format/cl/platform_info.hpp>
#include <dimbo/format/autosep.hpp>
#include <ostream>
#include <string>
#include <sstream>

namespace Dimbo {
namespace Format {

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Cl::Platform_Info const& info, int ind)
{
  Dimbo::Cl::Platform_Query const& query = info.last_query();
  Autosep<const char*>  as("\n");
  std::string pre(ind, ' ');
  std::ostringstream id;
  id << "0x" << std::hex << info.id();

  if(query.id_selected())
    os << as << pre << "Id (within current process) ....: " << id.str();
  if(query.profile_selected())
    os << as << pre << "Profile ........................: " << info.profile();
  if(query.version_selected())
    os << as << pre << "Version ........................: " << info.version();
  if(query.name_selected())
    os << as << pre << "Name ...........................: " << info.name();
  if(query.vendor_selected())
    os << as << pre << "Vendor .........................: " << info.vendor();
  if(query.extensions_selected())
    os << as << pre << "Extensions .....................: " << info.extensions();

  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Cl::Platform_Info const& info)
{
  return write(os, info, 0);
}

} /* namespace Format */
} /* namespace Dimbo */

#endif /* DIMBO_FORMAT_CL_PLATFORM_INFO_IMPL */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
