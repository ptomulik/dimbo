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

// dimbo/cl/platform_layer.hpp

/** // doc: dimbo/cl/platform_layer.hpp {{{
 * \file dimbo/cl/platform_layer.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_LAYER_HPP_INCLUDED
#define DIMBO_CL_PLATFORM_LAYER_HPP_INCLUDED

#include <dimbo/cl/platforms.hpp>
#include <dimbo/cl/devices.hpp>
#include <dimbo/cl/cl.hpp>

#include <dimbo/clinfo/platform_layer_info.hpp>
#include <dimbo/clinfo/platform_query.hpp>
#include <dimbo/clinfo/device_query.hpp>

#include <set>
#include <map>
#include <vector>

namespace Dimbo {
namespace Cl {

/** // doc: class Platform_Layer {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
class Platform_Layer
{
public:
  //typedef std::vector<Platform> Platforms;
  //typedef std::vector<Device> Devices;
  typedef std::vector<cl_platform_id> Platform_IDs;
  typedef std::vector<cl_device_id> Device_IDs;
  typedef std::map<cl_device_id, cl_platform_id> Device_Platform_Map;
  typedef std::map<cl_platform_id, Device_IDs > Platform_Devices_Map;
public:
  /** // doc: Platform_Layer() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Layer();
  /** // doc: ~Platform_Layer() {{{
   * \todo Write documentation for class Platform_Layer
   */ // }}}
  virtual ~Platform_Layer();
  /** // doc: plaforms() {{{
   * \todo Write documentation
   */ // }}}
  Platforms platforms() const;
  Devices devices() const;
  Devices devices(Platform const& platform) const;
  Platform platform(Device const& device) const;
private:
  void _init();
  void _insert(cl_platform_id id);
  void _insert(cl_platform_id platform_id, cl_device_id id);
  void _insert(cl_platform_id platform_id, Device_IDs const& ids);
  Platform_IDs _platform_ids;
  Device_IDs _device_ids;
  Device_Platform_Map _device_platform_map;
  Platform_Devices_Map _platform_devices_map;
};

/** // doc: query_platform_layer_info(layer,pquery,dquery) {{{
 * \todo Write documentation
 */ // }}}
Dimbo::Clinfo::Platform_Layer_Info
query_platform_layer_info(
    Platform_Layer const& layer = Platform_Layer(),
    Dimbo::Clinfo::Platform_Query const& pquery = Dimbo::Clinfo::Platform_Query(),
    Dimbo::Clinfo::Device_Query const& dquery = Dimbo::Clinfo::Device_Query()
);
} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_PLATFORM_LAYER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
