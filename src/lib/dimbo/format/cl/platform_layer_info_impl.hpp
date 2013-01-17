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

// dimbo/format/cl/platform_layer_info_impl.hpp

/** // doc: dimbo/format/cl/platform_layer_info_impl.hpp {{{ 
 * @file dimbo/format/cl/platform_layer_info_impl.hpp
 * @todo Write documentation
 */ // }}}
#ifndef DIMBO_FORMAT_CL_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED
#define DIMBO_FORMAT_CL_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED

/** // doc: dimbo/format/cl/platform_info_impl.hpp {{{
 * @file dimbo/format/cl/platform_info_impl.hpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/format/cl/platform_layer_info.hpp>
#include <dimbo/format/cl/platform_info.hpp>
#include <dimbo/format/cl/device_info.hpp>
#include <dimbo/format/autosep.hpp>
#include <ostream>
#include <string>

namespace Dimbo {
namespace Format {

template <class Ostream> Ostream& 
write(Ostream& os, Dimbo::Cl::Platform_Layer_Info const& info, int ind)
{
  using Dimbo::Cl::Platform_Layer_Info;
  typedef Platform_Layer_Info::Platform_Info_Ptr Platform_Info_Ptr;
  typedef Platform_Layer_Info::Device_Info_Ptr Device_Info_Ptr;
  std::string pre(ind, ' ');

  std::vector<Platform_Info_Ptr> pinfos(info.platforms());
  std::vector<Platform_Info_Ptr>::const_iterator pend(pinfos.end());
  std::vector<Platform_Info_Ptr>::const_iterator pbeg(pinfos.begin());
  std::vector<Platform_Info_Ptr>::const_iterator pcur(pbeg);
  for(;pcur != pend; ++ pcur)
    {
      os << "Platform " << (pcur - pbeg) << ":\n";
      Dimbo::Format::write(os, **pcur, ind) << "\n";
      os << "\n";
      std::vector<Device_Info_Ptr> dinfos(info.devices(*pcur));
      std::vector<Device_Info_Ptr>::const_iterator dend(dinfos.end());
      std::vector<Device_Info_Ptr>::const_iterator dbeg(dinfos.begin());
      std::vector<Device_Info_Ptr>::const_iterator dcur(dbeg);
      for(;dcur != dend; ++dcur)
        {
           os << pre << "Device " << (dcur - dbeg) << ":\n";
           Dimbo::Format::write(os, **dcur, 2*ind ) << "\n";
           os << "\n";
        }
    }
  return os;
}

template <class Ostream> Ostream& 
write(Ostream& os, Dimbo::Cl::Platform_Layer_Info const& info)
{
  return write(os, info, 0);
}

} /* namespace Format */
} /* namespace Dimbo */


#endif /* DIMBO_FORMAT_CL_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
