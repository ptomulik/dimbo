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

// dimbo/clinfo/platform_layer_info.cpp

/** // doc: dimbo/clinfo/platform_layer_info.cpp {{{
 * @file dimbo/clinfo/platform_layer_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/clinfo/platform_layer_info.hpp>
#include <set>

namespace Dimbo {
namespace Clinfo {

/* ------------------------------------------------------------------------ */

Platform_Layer_Info::Platform_Layer_Info()
{
}
/* ------------------------------------------------------------------------ */

Platform_Layer_Info::~Platform_Layer_Info()
{
}
/* ------------------------------------------------------------------------ */
void Platform_Layer_Info::
clear()
{
  this->_bimap.clear();
}
/* ------------------------------------------------------------------------ */
Platform_Info_Ptrs Platform_Layer_Info::
platforms()
{
  typedef Bimap::left_const_iterator It;
  std::set<Const_Platform_Info_Ptr> seen;
  Platform_Info_Ptrs platforms;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    {
      if(seen.find(cur->first) == seen.end())
        {
          platforms.push_back(boost::const_pointer_cast<Platform_Info>(cur->first));
          seen.insert(cur->first);
        }
    }
  return platforms;
}
/* ------------------------------------------------------------------------ */
Const_Platform_Info_Ptrs Platform_Layer_Info::
platforms() const
{
  typedef Bimap::left_const_iterator It;
  std::set<Const_Platform_Info_Ptr> seen;
  Const_Platform_Info_Ptrs platforms;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    {
      if(seen.find(cur->first) == seen.end())
        {
          platforms.push_back(cur->first);
          seen.insert(cur->first);
        }
    }
  return platforms;
}
/* ------------------------------------------------------------------------ */
Platform_Info_Ptr Platform_Layer_Info::
platform(Const_Device_Info_Ptr device)
{
  // NOTE: this throws an exception if device is an invalid key
  return boost::const_pointer_cast<Platform_Info>(this->_bimap.right.at(device));
}
/* ------------------------------------------------------------------------ */
Const_Platform_Info_Ptr Platform_Layer_Info::
platform(Const_Device_Info_Ptr device) const
{
  // NOTE: this throws an exception if device is an invalid key
  return this->_bimap.right.at(device);
}
/* ------------------------------------------------------------------------ */
Device_Info_Ptrs Platform_Layer_Info::
devices()
{
  typedef Bimap::left_const_iterator It;
  Device_Info_Ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    devices.push_back(boost::const_pointer_cast<Device_Info>(cur->second));
  return devices;
}
/* ------------------------------------------------------------------------ */
Const_Device_Info_Ptrs Platform_Layer_Info::
devices() const
{
  typedef Bimap::left_const_iterator It;
  Const_Device_Info_Ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    devices.push_back(cur->second);
  return devices;
}
/* ------------------------------------------------------------------------ */
Device_Info_Ptrs Platform_Layer_Info::
devices(Const_Platform_Info_Ptr platform)
{
  typedef Bimap::left_const_iterator It;
  Device_Info_Ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = _bimap.left.begin(); cur != end; ++cur)
    if(cur->first == platform)
      devices.push_back(boost::const_pointer_cast<Device_Info>(cur->second));
  return devices;
}
/* ------------------------------------------------------------------------ */
Const_Device_Info_Ptrs Platform_Layer_Info::
devices(Const_Platform_Info_Ptr platform) const
{
  typedef Bimap::left_const_iterator It;
  Const_Device_Info_Ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = _bimap.left.begin(); cur != end; ++cur)
    if(cur->first == platform)
      devices.push_back(cur->second);
  return devices;
}
/* ------------------------------------------------------------------------ */
void Platform_Layer_Info::
push_back(Device_Info_Ptr device, Platform_Info_Ptr platform)
{
  this->_bimap.left.push_back(Bimap::left_value_type(platform, device));
}
/* ------------------------------------------------------------------------ */
void Platform_Layer_Info::
remove(Const_Platform_Info_Ptr platform)
{
  typedef Bimap::left_iterator It;
  for(It cur = this->_bimap.left.begin(); cur != this->_bimap.left.end();)
    if(cur->first == platform)
      cur = this->_bimap.left.erase(cur);
    else
      ++cur;
}
/* ------------------------------------------------------------------------ */
void Platform_Layer_Info::
remove(Const_Device_Info_Ptr device)
{
  this->_bimap.right.erase(device);
}
/* ------------------------------------------------------------------------ */
bool Platform_Layer_Info::
empty() const
{
  return this->_bimap.empty();
}

} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
