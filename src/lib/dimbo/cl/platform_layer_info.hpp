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

// dimbo/cl/platform_layer_info.hpp

/** // doc: dimbo/cl/platform_layer_info.hpp {{{ 
 * \file dimbo/cl/platform_layer_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define DIMBO_CL_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <dimbo/cl/platform_info.hpp>
#include <dimbo/cl/device_info.hpp>
#include <dimbo/cl/platform_layer.hpp>
#include <boost/shared_ptr.hpp>
#ifndef SWIG // FIXME: provide more verbose constant name
# include <boost/serialization/version.hpp>
# include <boost/serialization/access.hpp>
# include <boost/serialization/nvp.hpp>
# include <boost/serialization/set.hpp>
# include <boost/serialization/map.hpp>
# include <boost/serialization/shared_ptr.hpp>
#endif
#include <map>
#include <vector>

namespace Dimbo {
namespace Cl {

/** // doc: class Platform_Layer_Info {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
class Platform_Layer_Info 
{
public:
#ifndef SWIG // FIXME: provide more verbose constant name
  BOOST_STATIC_CONSTANT(unsigned int, class_version = 1);
#endif
public:
  typedef boost::shared_ptr<Platform_Info> Platform_Info_Ptr;
  typedef boost::shared_ptr<Device_Info> Device_Info_Ptr;
  typedef boost::shared_ptr<const Platform_Info> Const_Platform_Info_Ptr;
  typedef boost::shared_ptr<const Device_Info> Const_Device_Info_Ptr;
  typedef std::vector<Platform_Info_Ptr> Platform_Infos;
  typedef std::vector<Device_Info_Ptr> Device_Infos;
  typedef std::map<Const_Device_Info_Ptr,Platform_Info_Ptr> Device_Platform_Map;
  typedef std::map<Const_Platform_Info_Ptr,Device_Infos> Platform_Devices_Map;
public:
  /** // doc: Platform_Layer_Info() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Layer_Info();
  /** // doc: Platform_Layer_Info(layer, pquery, dquery) {{{
   * \todo Write documentation
   */ // }}}
  Platform_Layer_Info(Platform_Layer const& layer, 
                      Platform_Query const& pquery = Platform_Query(),
                      Device_Query const& dquery = Device_Query());
  /** // doc: ~Platform_Layer_Info() {{{
   * \todo Write documentation for class Platform_Layer_Info
   */ // }}}
  virtual ~Platform_Layer_Info();
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  void clear();
  /** // doc: query() {{{
   * \todo Write documentation
   */ // }}}
  void query( Platform_Layer const& layer
            , Platform_Query const& pquery
            , Device_Query const& dquery );
  /** // doc: platforms () {{{
   * \todo Write documentation
   */ // }}}
  //std::vector<Platform_Info_Ptr> platforms() const;
  Platform_Infos platforms() const;
  /** // doc: devices () {{{
   * \todo Write documentation
   */ // }}}
  //std::vector<Device_Info_Ptr> devices() const;
  Device_Infos devices() const;
  /** // doc: devices (plat) {{{
   * \todo Write documentation
   */ // }}}
  Device_Infos devices(Const_Platform_Info_Ptr p) const;
private:
#ifndef SWIG // FIXME: provide more verbose constant name
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive & ar, const unsigned int  /* version */ )
  {
    using boost::serialization::make_nvp;
    ar & make_nvp("platform_devices_map", _platform_devices_map);
    //ar & make_nvp("platform_infos", _platform_infos);
    //ar & make_nvp("device_infos", _device_infos);
  }
#endif
private:
  void _insert(Platform_Info_Ptr platform);
  void _insert(Platform_Info_Ptr platform, Device_Info_Ptr device);
  Platform_Infos _platform_infos;
  Device_Infos _device_infos;
  Device_Platform_Map _device_platform_map;
  Platform_Devices_Map _platform_devices_map;
};

} /* namespace Cl */
} /* namespace Dimbo */

#ifndef SWIG // FIXME: provide more verbose constant name
BOOST_CLASS_VERSION( Dimbo::Cl::Platform_Layer_Info
                   , Dimbo::Cl::Platform_Layer_Info::class_version )
#endif

#endif /* DIMBO_CL_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
