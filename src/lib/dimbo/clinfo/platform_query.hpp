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

// dimbo/clinfo/platform_query.hpp

/** // doc: dimbo/clinfo/platform_query.hpp {{{
 * \file dimbo/clinfo/platform_query.hpp
 *
 * This file contains definition of Dimbo::Clinfo::Platform_Query class, which
 * configures queries to OpenCL platforms.
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_INFO_QUERY_HPP_INCLUDED
#define DIMBO_CLINFO_PLATFORM_INFO_QUERY_HPP_INCLUDED

namespace Dimbo {
namespace Clinfo {

/** // doc: class Platform_Query {{{
 * \ingroup Dimbo_Clinfo_Platform
 * \brief Set of boolean flags that define parameters to be retrieved from
 *        OpenCL platform.
 *
 * This class encapsulates several boolean flags which tell what information
 * should be retrieved from an OpenCL platform. Objects of type Platform_Query
 * are used together with Platform_Info to query several parmeters describing
 * local OpenCL platform(s) at once.
 */ // }}}
class Platform_Query
{
  template <class Archive>
  friend void _serialize(Archive&, Platform_Query&, const unsigned int);
public:
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: ~Platform_Query() {{{
   * \todo Write documentation for class Platform_Query
   */ // }}}
  virtual ~Platform_Query();
  /** // doc: Platform_Query() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Query();
  /** // doc: Platform_Query(flag) {{{
   * \todo Write documentation
   */ // }}}
  Platform_Query(bool flag);
  /** // doc: select_all() {{{
  * \todo Write documentation
  */ // }}}
  Platform_Query& select_all();
  /** // doc: select_none() {{{
  * \todo Write documentation
  */ // }}}
  Platform_Query& select_none();
  /** // doc: select_default() {{{
  * \todo Write documentation
  */ // }}}
  Platform_Query& select_default();
  // getters {{{
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool id_selected() const
  {
    return this->_id;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool profile_selected() const
  {
    return this->_profile;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool version_selected() const
  {
    return this->_version;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool name_selected() const
  {
    return this->_name;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool vendor_selected() const
  {
    return this->_vendor;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool extensions_selected() const
  {
    return this->_extensions;
  }
  // }}}
  // selectors {{{
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_id(bool flag = true)
  {
    this->_id = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_profile(bool flag = true)
  {
    this->_profile = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_version(bool flag = true)
  {
    this->_version = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_name(bool flag = true)
  {
    this->_name = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_vendor(bool flag = true)
  {
    this->_vendor = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_extensions(bool flag = true)
  {
    this->_extensions = flag;
    return *this;
  }
  // }}}
private:
  void _select(bool flag);
  void _init(bool flag);
  // Attributes {{{
  bool _id;
  bool _profile;
  bool _version;
  bool _name;
  bool _vendor;
  bool _extensions;
  // }}}
};

bool operator==(Platform_Query const&, Platform_Query const&);
inline bool operator!=(Platform_Query const& a, Platform_Query const& b)
{ return !(a == b); }

} /* namespace Clinfo */
} /* namespace Dimbo */

#endif /* DIMBO_CLINFO_PLATFORM_INFO_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
