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

/** // // doc: dimbo/clinfo/platform_info.hpp {{{
 * \file dimbo/clinfo/platform_info.hpp
 *
 * This file contains definition of Dimbo::Clinfo::Platform_Info class, which
 * encapsulates several parameters retrieved from OpenCL platfrom.
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_INFO_HPP_INCLUDED
#define DIMBO_CLINFO_PLATFORM_INFO_HPP_INCLUDED

#include <string>
#include <boost/optional.hpp>

#include <dimbo/clinfo/exceptions/common.hpp>
#include <dimbo/clinfo/exceptions/bad_alloc.hpp>
#include <dimbo/clinfo/exceptions/length_error.hpp>
#include <dimbo/clinfo/exceptions/uninitialized_value.hpp>

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
  template <class Archive>
  friend void serialize(Archive&, Platform_Info&, const unsigned int);
public:
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: Platform_Info() {{{
   * \brief Default constructor.
   */ // }}}
  Platform_Info();
  /** // doc: ~Platform_Info() {{{
   * \brief Destructor.
   */ // }}}
  virtual ~Platform_Info() { }
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear();
  /** // doc: cmp() {{{
   * \todo Write documentation
   */ // }}}
  bool cmp(Platform_Info const&) const throw();
  // getters {{{
  /** // // doc: id() {{{
   * \brief Identifier of the recently queried OpenCL platform.
   * \return The \c cl_platform_id identifier of an OpenCL platform, whose
   *    parameters are keeps in this object.
   */ // }}}
  unsigned long id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // // doc: profile() {{{
   * \brief Platform profile string retrieved with Platform::get_profile().
   * \todo Refine documentation
   */ // }}}
  std::string const& profile() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // // doc: version() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  std::string const& version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // // doc: name() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  std::string const& name() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // // doc: vendor() {{{
   * \todo Refine documentation
   * \brief Platform vendor string retrieved with Platform::get_vendor().
   */ // }}}
  std::string const& vendor() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // // doc: extensions() {{{
   * \todo Refine documentation
   * \brief Platform extensions string retrieved with
   *        Platform::get_extensions().
   */ // }}}
  std::string const& extensions() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  // }}}
  // setters {{{
  /** // doc: set_id() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& set_id(unsigned long val) throw();
  /** // doc: set_profile() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& set_profile(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** // doc: set_version() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& set_version(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** // doc: set_name() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& set_name(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** // doc: set_vendor() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& set_vendor(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** // doc: set_extensions() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& set_extensions(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  // }}}
  // cleaners {{{
  /** // doc: clear_id() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear_id() throw();
  /** // doc: clear_profile() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear_profile() throw();
  /** // doc: clear_version() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear_version() throw();
  /** // doc: clear_name() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear_name() throw();
  /** // doc: clear_vendor() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear_vendor() throw();
  /** // doc: clear_extensions() {{{
   * \todo Write documentation
   */ // }}}
  Platform_Info& clear_extensions() throw();
  // }}}
  // presence {{{
  /** // doc: has_id() {{{
   * \todo Write documentation
   */ // }}}
  bool has_id() const throw();
  /** // doc: has_profile() {{{
   * \todo Write documentation
   */ // }}}
  bool has_profile() const throw();
  /** // doc: has_version() {{{
   * \todo Write documentation
   */ // }}}
  bool has_version() const throw();
  /** // doc: has_name() {{{
   * \todo Write documentation
   */ // }}}
  bool has_name() const throw();
  /** // doc: has_vendor() {{{
   * \todo Write documentation
   */ // }}}
  bool has_vendor() const throw();
  /** // doc: has_extensions() {{{
   * \todo Write documentation
   */ // }}}
  bool has_extensions() const throw();
  // }}}
private:
  void _init();
  void _clear();
  // attributes {{{
  boost::optional<unsigned long> _id;
  boost::optional<std::string> _profile;
  boost::optional<std::string> _version;
  boost::optional<std::string> _name;
  boost::optional<std::string> _vendor;
  boost::optional<std::string> _extensions;
  // }}}
};

/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator== (Platform_Info const& a, Platform_Info const& b)
  throw()
{ return a.cmp(b); }
/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!= (Platform_Info const& a, Platform_Info const& b)
  throw()
{ return !(a == b); }

} /* namespace Dimbo */
} /* namespace Clinfo */

#endif /* DIMBO_CLINFO_PLATFORM_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
