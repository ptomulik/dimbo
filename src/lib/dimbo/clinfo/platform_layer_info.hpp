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

// dimbo/clinfo/platform_layer_info.hpp

/** // doc: dimbo/clinfo/platform_layer_info.hpp {{{
 * \file dimbo/clinfo/platform_layer_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define DIMBO_CLINFO_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <dimbo/clinfo/platform_info_ptrs.hpp>
#include <dimbo/clinfo/device_info_ptrs.hpp>

#include <boost/bimap/bimap.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/bimap/set_of.hpp>
#include <vector>

namespace Dimbo {
namespace Clinfo {

/** // doc: class Platform_Layer_Info {{{
 * \ingroup Dimbo_Clinfo_Platform
 * \todo Write documentation
 */ // }}}
class Platform_Layer_Info
{
  template <class Archive>
  friend void serialize(Archive&, Platform_Layer_Info&, const unsigned int);
public:
  static constexpr unsigned int class_version = 0x000001;
private:
  typedef boost::bimaps::vector_of<Const_Platform_Info_Ptr> Left_Set;
  typedef boost::bimaps::set_of<Const_Device_Info_Ptr> Right_Set;
  typedef boost::bimaps::bimap<Left_Set, Right_Set> Bimap;

public:
  /** // doc: Platform_Layer_Info() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Layer_Info();
  /** // doc: ~Platform_Layer_Info() {{{
   * \todo Write documentation for class Platform_Layer_Info
   */ // }}}
  virtual ~Platform_Layer_Info();
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  void clear();
  /** // doc: platforms () {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info_Ptrs platforms();
  /** // doc: platforms () {{{
   * \todo Write documentation
   */ // }}}
  Const_Platform_Info_Ptrs platforms() const;
  /** // doc: platform () {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info_Ptr platform(Const_Device_Info_Ptr device);
  /** // doc: platform () {{{
   * \todo Write documentation
   */ // }}}
  Const_Platform_Info_Ptr platform(Const_Device_Info_Ptr device) const;
  /** // doc: devices () {{{
   * \todo Write documentation
   */ // }}}
  Device_Info_Ptrs devices();
  /** // doc: devices () {{{
   * \todo Write documentation
   */ // }}}
  Const_Device_Info_Ptrs devices() const;
  /** // doc: devices (plat) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info_Ptrs devices(Const_Platform_Info_Ptr platform);
  /** // doc: devices (plat) {{{
   * \todo Write documentation
   */ // }}}
  Const_Device_Info_Ptrs devices(Const_Platform_Info_Ptr platform) const;
  /** // doc: push_back (device) {{{
   * \todo Write documentation
   */ // }}}
  void push_back(Device_Info_Ptr device, Platform_Info_Ptr platform);
  /** // doc: remove (device) {{{
   * \todo Write documentation
   */ // }}}
  void remove(Const_Platform_Info_Ptr platform);
  /** // doc: remove (device) {{{
   * \todo Write documentation
   */ // }}}
  void remove(Const_Device_Info_Ptr device);
  /** // doc: empty() {{{
   * \todo Write documentation
   */ // }}}
  bool empty() const;
  /** // doc: cmp(p) {{{
   * \todo Write documentation
   */ // }}}
  bool cmp(Platform_Layer_Info const& p) const;
  /** // doc: indices() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<int> indices() const;
private:
  Bimap _bimap;
};

/** // doc: operator==(l,r) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator==(Platform_Layer_Info const& a, Platform_Layer_Info const& b)
{
  return a.cmp(b);
}
/** // doc: operator!=(l,r) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!=(Platform_Layer_Info const& a, Platform_Layer_Info const& b)
{
  return !a.cmp(b);
}

} /* namespace Clinfo */
} /* namespace Dimbo */

#endif /* DIMBO_CLINFO_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
