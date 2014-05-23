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

#ifndef SWIG // FIXME: provide more verbose constant
#  include <boost/serialization/version.hpp>
#  include <boost/serialization/access.hpp>
#  include <boost/serialization/nvp.hpp>
#endif

#include <dimbo/protobuf/clinfo/platform_query.pb.h>

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
public:
#ifndef SWIG // FIXME: provide more verbose constant
  BOOST_STATIC_CONSTANT(unsigned int, class_version = 1 );
#endif
public:
  /** // doc: ~Platform_Query() {{{
   * \todo Write documentation for class Platform_Query
   */ // }}}
  virtual ~Platform_Query();
  /** // doc: Platform_Query() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Query();
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_id(bool flag = true)
  {
    this->_select_id = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool id_selected() const
  {
    return this->_select_id;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_profile(bool flag = true)
  {
    this->_select_profile = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool profile_selected() const
  {
    return this->_select_profile;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_version(bool flag = true)
  {
    this->_select_version = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool version_selected() const
  {
    return this->_select_version;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_name(bool flag = true)
  {
    this->_select_name = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool name_selected() const
  {
    return this->_select_name;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_vendor(bool flag = true)
  {
    this->_select_vendor = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool vendor_selected() const
  {
    return this->_select_vendor;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline Platform_Query& select_extensions(bool flag = true)
  {
    this->_select_extensions = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool extensions_selected() const
  {
    return this->_select_extensions;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  void select_all();
  /** // {{{
  * \todo Write documentation
  */ // }}}
  void select_none();
  /** // {{{
  * \todo Write documentation
  */ // }}}
  void read(Dimbo::Protobuf::Clinfo::Platform_Query const& buff);
  /** // {{{
  * \todo Write documentation
  */ // }}}
  void write(Dimbo::Protobuf::Clinfo::Platform_Query& buff) const;
private:
#ifndef SWIG // FIXME: provide more verbose constant
  friend class boost::serialization::access;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  template <class Archive>
  void serialize(Archive & ar, const unsigned int /* version */)
  {
    // {{{
    using boost::serialization::make_nvp;
    ar & make_nvp("select_id", _select_id);
    ar & make_nvp("select_profile", _select_profile);
    ar & make_nvp("select_version", _select_version);
    ar & make_nvp("select_name", _select_name);
    ar & make_nvp("select_vendor", _select_vendor);
    ar & make_nvp("select_extensions", _select_extensions);
    // }}}
  }
#endif
private:
  void _init_query();
  // Attributes {{{
  bool _select_id;
  bool _select_profile;
  bool _select_version;
  bool _select_name;
  bool _select_vendor;
  bool _select_extensions;
  // }}}
};

bool operator==(Platform_Query const&, Platform_Query const&);
inline bool operator!=(Platform_Query const& a, Platform_Query const& b)
{ return !(a == b); }

} /* namespace Clinfo */
} /* namespace Dimbo */

#ifndef SWIG // FIXME: provide more verbose constant
BOOST_CLASS_VERSION( Dimbo::Clinfo::Platform_Query
                   , Dimbo::Clinfo::Platform_Query::class_version)
#endif

#endif /* DIMBO_CLINFO_PLATFORM_INFO_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
