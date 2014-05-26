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

/** // doc: dimbo/protobuf/clinfo/platform_layer_info.cpp {{{
 * \file dimbo/protobuf/clinfo/platform_layer_info.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/protobuf/clinfo/platform_layer_info.hpp>
#include <dimbo/protobuf/clinfo/platform_info.hpp>
#include <dimbo/protobuf/clinfo/device_info.hpp>
#include <algorithm>

namespace Dimbo {
namespace Protobuf {

/* ------------------------------------------------------------------------ */
void write(Dimbo::Protobuf::Clinfo::Platform_Layer_Info& buf,
           Dimbo::Clinfo::Platform_Layer_Info const& obj)
{
  using Dimbo::Clinfo::Const_Platform_Info_Ptr;
  using Dimbo::Clinfo::Const_Platform_Info_Ptrs;
  using Dimbo::Clinfo::Const_Device_Info_Ptrs;


  buf.Clear();

  std::vector<int> indices(obj.indices());
  Const_Device_Info_Ptrs devices(obj.devices());
  Const_Platform_Info_Ptrs platforms(obj.platforms());
  for(size_t i = 0; i < indices.size(); ++i)
    {
      if(indices[i] >= 0 && static_cast<size_t>(indices[i]) < platforms.size())
        {
          buf.add_device_platform_index(indices[i]);
          write(*(buf.add_device()),*(devices[i]));
        }
      // else
      //   {
      //      FIXME: throw an exception here? this is likely an internal error
      //   }
    }
  for(size_t j = 0; j < platforms.size(); ++j)
    {
      write(*(buf.add_platform()), *(platforms[j]));
    }
}
/* ------------------------------------------------------------------------ */
void read(Dimbo::Protobuf::Clinfo::Platform_Layer_Info const& buf,
          Dimbo::Clinfo::Platform_Layer_Info& obj)
{
  using Dimbo::Clinfo::Platform_Info_Ptr;
  using Dimbo::Clinfo::Platform_Info_Ptrs;
  using Dimbo::Clinfo::Device_Info_Ptr;
  using Dimbo::Clinfo::Platform_Info;
  using Dimbo::Clinfo::Device_Info;

  obj.clear();

  int i, j;

  Platform_Info_Ptrs platforms; 
  for(i = 0; i < buf.platform_size(); ++i)
    {
      Platform_Info_Ptr platform(new Platform_Info());
      read(buf.platform(i), *platform);
      platforms.push_back(platform);
    }

  for(i = 0; i < buf.device_size(); ++i)
    {
      j = buf.device_platform_index(i);
      if(j >= 0 && static_cast<size_t>(j) < platforms.size())
        {
          Device_Info_Ptr device(new Device_Info());
          read(buf.device(i), *device);
          obj.push_back(device, platforms[j]);
        }
      // else
      //   {
      //      FIXME: shouldn't we throw an exception here?
      //             if this happen it means we have malformed message
      //   }
    }
}
/* ------------------------------------------------------------------------ */

} /* namesapce Protobuf */
} /* namespace Dimbo */

/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Platform_Layer_Info&
operator<<(Dimbo::Protobuf::Clinfo::Platform_Layer_Info& buf,
           Dimbo::Clinfo::Platform_Layer_Info const& obj)
{
  Dimbo::Protobuf::write(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Platform_Layer_Info const&
operator>>(Dimbo::Protobuf::Clinfo::Platform_Layer_Info const& buf,
           Dimbo::Clinfo::Platform_Layer_Info& obj)
{
  Dimbo::Protobuf::read(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
