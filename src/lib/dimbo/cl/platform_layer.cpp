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

// dimbo/cl/platform_layer.cpp

/** // doc: dimbo/cl/platform_layer.cpp {{{
 * @file dimbo/cl/platform_layer.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/platform_layer.hpp>
#include <dimbo/cl/platform.hpp>
#include <dimbo/cl/device.hpp>
#include <algorithm>

namespace Dimbo {
namespace Cl {

Platform_Layer::
Platform_Layer()
{
  _init();
}

Platform_Layer::
~Platform_Layer()
{
}

Platforms Platform_Layer::
platforms() const
{
  return Platforms(this->_platform_ids.begin(), this->_platform_ids.end());
}

Devices Platform_Layer::
devices() const
{
  return Devices(this->_device_ids.begin(), this->_device_ids.end());
}

Devices Platform_Layer::
devices(Platform const& platform) const
{
  typedef Platform_Devices_Map::const_iterator map_iterator;
  map_iterator found = this->_platform_devices_map.find(platform.id());
  if(found == this->_platform_devices_map.end())
    // FIXME: throw an exception (platform with no devices)???
    return Devices();
  return Devices(found->second.begin(), found->second.end());
}

Platform Platform_Layer::
platform(Device const& device) const
{
  typedef std::map<cl_device_id,cl_platform_id>::const_iterator iterator;
  iterator found = this->_device_platform_map.find(device.id());
  // FIXME: assert device in _device_platform_map ?
  //if(found == this->_device_platform_map.end())
  //  throw ???;
  return Platform(found->second);
}

void Platform_Layer::
_insert(cl_platform_id id)
{
  if(this->_platform_devices_map.count(id) == 0)
    {
      this->_platform_ids.push_back(id);
      this->_platform_devices_map.insert(std::make_pair(id, Device_IDs()));
    }
}

void Platform_Layer::
_insert(cl_platform_id platform_id, cl_device_id id)
{
  if(this->_device_platform_map.count(id) == 0)
    {
      this->_device_ids.push_back(id);
      this->_device_platform_map.insert(std::make_pair(id, platform_id));
      this->_insert(platform_id);
      this->_platform_devices_map[platform_id].push_back(id);
    }
}

void Platform_Layer::
_insert(cl_platform_id platform_id, Device_IDs const& ids)
{
  typedef Device_IDs::const_iterator iterator;
  iterator end(ids.end());
  for(iterator cur(ids.begin()); cur != end; ++cur)
    this->_insert(platform_id, *cur);
}

void Platform_Layer::
_init()
{
  typedef std::vector<cl_platform_id>::const_iterator iterator;
  std::vector<cl_platform_id> platform_ids(get_platform_ids());
  iterator end( platform_ids.end() );
  for(iterator cur( platform_ids.begin() ); cur != end; ++cur)
    this->_insert(*cur, get_device_ids(*cur));
}

Dimbo::Clinfo::Platform_Layer_Info
query_platform_layer_info(Platform_Layer const& layer,
                          Dimbo::Clinfo::Platform_Query const& pquery,
                          Dimbo::Clinfo::Device_Query const& dquery)
{
  Platforms platforms(layer.platforms());
  Platforms::const_iterator pend(platforms.end());
  Platforms::const_iterator pcur(platforms.begin());

  Dimbo::Clinfo::Platform_Layer_Info info;

  for(;pcur != pend; ++pcur)
    {
      Dimbo::Clinfo::Platform_Info_Ptr pinfo(
          new Dimbo::Clinfo::Platform_Info(
            query_platform_info(*pcur, pquery)
          )
      );
      Devices devices(layer.devices(*pcur));
      Devices::const_iterator dend(devices.end());
      Devices::const_iterator dcur(devices.begin());
      for(;dcur != dend; ++dcur)
        {
          info.push_back(
            Dimbo::Clinfo::Device_Info_Ptr(
              new Dimbo::Clinfo::Device_Info(
                query_device_info(*dcur, dquery)
              )
            ),
            pinfo
          );
        }
    }
  return info;
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
