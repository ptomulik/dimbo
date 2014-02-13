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

// dimbo/cl/platform_layer_info.cpp

/** // doc: dimbo/cl/platform_layer_info.cpp {{{
 * @file dimbo/cl/platform_layer_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/platform_layer_info.hpp>
#include <dimbo/cl/devices.hpp>

namespace Dimbo {
namespace Cl {

Platform_Layer_Info::
Platform_Layer_Info()
{
}
Platform_Layer_Info::
Platform_Layer_Info( Platform_Layer const& layer, Platform_Query const& pquery
                   , Device_Query const& dquery )
{
  this->query(layer, pquery, dquery);
}

Platform_Layer_Info::
~Platform_Layer_Info()
{
}

void Platform_Layer_Info::
clear()
{
  this->_platform_infos.clear();
  this->_device_infos.clear();
  this->_device_platform_map.clear();
  this->_platform_devices_map.clear();
}

void Platform_Layer_Info::
query( Platform_Layer const& layer, Platform_Query const& pquery
     , Device_Query const& dquery )
{
  this->clear();
  Platforms platforms(layer.platforms());
  Platforms::const_iterator pend(platforms.end());
  Platforms::const_iterator pcur(platforms.begin());

  for(;pcur != pend; ++pcur)
    {
      Platform_Info_Ptr pinfo(new Platform_Info(Platform(*pcur), pquery));
      Devices devices(layer.devices(*pcur));
      Devices::const_iterator dend(devices.end());
      Devices::const_iterator dcur(devices.begin());
      for(;dcur != dend; ++dcur)
        {
          this->_insert(
            pinfo,
            Device_Info_Ptr(
              new Device_Info(
                Device(*dcur),
                dquery)
            )
          );
        }
    }
}

Platform_Layer_Info::Platform_Infos Platform_Layer_Info::
platforms() const
{
  return Platform_Infos(this->_platform_infos);
}

Platform_Layer_Info::Device_Infos Platform_Layer_Info::
devices() const
{
  return Device_Infos(this->_device_infos);
}

Platform_Layer_Info::Device_Infos Platform_Layer_Info::
devices(Const_Platform_Info_Ptr platform) const
{
  typedef Platform_Devices_Map::const_iterator map_iterator;
  map_iterator found = this->_platform_devices_map.find(platform);
  if(found == this->_platform_devices_map.end())
    // FIXME: throw an exception?
    return Device_Infos();
  else
    return found->second;
}

void Platform_Layer_Info::
_insert(Platform_Info_Ptr platform)
{
  if(this->_platform_devices_map.count(platform) == 0)
    {
      this->_platform_infos.push_back(platform);
      this->_platform_devices_map.insert(
        std::make_pair(platform,Device_Infos())
      );
    }
}

void Platform_Layer_Info::
_insert(Platform_Info_Ptr platform, Device_Info_Ptr device)
{
  this->_insert(platform);
  if(this->_device_platform_map.count(device) == 0)
    {
      this->_device_infos.push_back(device);
      this->_platform_devices_map[platform].push_back(device);
      this->_device_platform_map[device] = platform;
    }
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
