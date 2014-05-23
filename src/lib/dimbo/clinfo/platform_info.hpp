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

// dimbo/clinfo/platform_info.hpp

/** // doc: dimbo/clinfo/platform_info.hpp {{{
 * \file dimbo/clinfo/platform_info.hpp
 *
 * This file contains definition of Dimbo::Clinfo::Platform_Info class, which
 * encapsulates several parameters retrieved from OpenCL platfrom.
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_INFO_HPP_INCLUDED
#define DIMBO_CLINFO_PLATFORM_INFO_HPP_INCLUDED

#include <dimbo/protobuf/clinfo/platform_info.pb.h>
#include <string>
#include <boost/optional.hpp>

namespace Dimbo {
namespace Clinfo {

/** // doc: class Platform_Info {{{
 * \ingroup Dimbo_Clinfo_Platform
 * \brief Encapsulates parameters retrieved from OpenCL platfrom.
 *
 * An object of type Platform_Info keeps the result of composite query to
 * a single OpenCL platform. It may be used, for example, to pass that
 * information between comuters, serialize it or write it to a stream.
 * It also keeps a copy of recently used Platform_Query object to remember
 * which parameters were obtained from OpenCL platform and are actually valid.
 */ // }}}
class Platform_Info
{
public:
  /** // doc: Platform_Info() {{{
   * \brief Default constructor.
   */ // }}}
  Platform_Info();
  /** // doc: ~Platform_Info() {{{
   * \brief Destructor.
   */ // }}}
  virtual ~Platform_Info() { }
  /** // doc: id() {{{
   * \brief Identifier of the recently queried OpenCL platform.
   * \return The \c cl_platform_id identifier of an OpenCL platform, whose
   *    parameters are keeps in this object.
   */ // }}}
  inline unsigned long id() const
  {
    return this->_id.get();
  }
  /** // doc: profile() {{{
   * \brief Platform profile string retrieved with Platform::get_profile().
   * \todo Refine documentation
   */ // }}}
  inline std::string const& profile() const
  {
    return this->_profile.get();
  }
  /** // doc: version() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  inline std::string const& version() const
  {
    return this->_version.get();
  }
  /** // doc: name() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  inline std::string const& name() const
  {
    return this->_name.get();
  }
  /** // doc: vendor() {{{
   * \todo Refine documentation
   * \brief Platform vendor string retrieved with Platform::get_vendor().
   */ // }}}
  inline std::string const& vendor() const
  {
    return this->_vendor.get();
  }
  /** // doc: extensions() {{{
   * \todo Refine documentation
   * \brief Platform extensions string retrieved with
   *        Platform::get_extensions().
   */ // }}}
  inline std::string const& extensions() const
  {
    return this->_extensions.get();
  }
  /** doc: set_id() {{{
   * \todo Write documentation
   */ // }}}
  void set_id(unsigned long val)
  {
    this->_id = val;
  }
  /** doc: set_profile() {{{
   * \todo Write documentation
   */ // }}}
  void set_profile(std::string const& val)
  {
    this->_profile = val;
  }
  /** doc: set_version() {{{
   * \todo Write documentation
   */ // }}}
  void set_version(std::string const& val)
  {
    this->_version = val;
  }
  /** doc: set_name() {{{
   * \todo Write documentation
   */ // }}}
  void set_name(std::string const& val)
  {
    this->_name = val;
  }
  /** doc: set_vendor() {{{
   * \todo Write documentation
   */ // }}}
  void set_vendor(std::string const& val)
  {
    this->_vendor = val;
  }
  /** doc: set_extensions() {{{
   * \todo Write documentation
   */ // }}}
  void set_extensions(std::string const& val) throw
  {
    this->_extensions = val;
  }
  /** doc: has_id() {{{
   * \todo Write documentation
   */ // }}}
  inline void has_id() const throw()
  {
    return this->_id.is_initialized();
  }
  /** doc: has_profile() {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_profile() const throw()
  {
    return this->_profile.is_initialized();
  }
  /** doc: has_version() {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_version() const throw()
  {
    return this->_version.is_initialized();
  }
  /** doc: has_name() {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_name() const throw()
  {
    return this->_name.is_initialized();
  }
  /** doc: has_vendor() {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_vendor() const throw()
  {
    return this->_vendor.is_initialized();
  }
  /** doc: has_extensions() {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_extensions() const throw()
  {
    return this->_extensions.is_initialized();
  }
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear();
private:
  void _init();
  void _clear();
  boost::optional<unsigned long> _id;
  boost::optional<std::string> _profile;
  boost::optional<std::string> _version;
  boost::optional<std::string> _name;
  boost::optional<std::string> _vendor;
  boost::optional<std::string> _extensions;
};

bool operator== (Platform_Info const&, Platform_Info const&);
inline bool operator!= (Platform_Info const& a, Platform_Info const& b)
{ return !(a == b); }

} /* namespace Dimbo */
} /* namespace Clinfo */

// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
BOOST_CLASS_VERSION( Dimbo::Clinfo::Platform_Info
                   , Dimbo::Clinfo::Platform_Info::class_version )
#endif

#endif /* DIMBO_CLINFO_PLATFORM_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
