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

// dimbo/cl/platform_info.hpp

/** // doc: dimbo/cl/platform_info.hpp {{{
 * \file dimbo/cl/platform_info.hpp
 *
 * This file contains definition of Dimbo::Cl::Platform_Info class, which
 * encapsulates several parameters retrieved from OpenCL platfrom.
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_INFO_HPP_INCLUDED
#define DIMBO_CL_PLATFORM_INFO_HPP_INCLUDED

#include <dimbo/cl/platform.hpp>
#include <dimbo/cl/platform_query.hpp>
// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
#include <boost/serialization/version.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#endif
//#include <dimbo/cl/cl.hpp>

#include <dimbo/protobuf/cl/platform_info.pb.h>

namespace Dimbo {
namespace Cl {

/** // doc: class Platform_Info {{{
 * \ingroup Dimbo_Cl_Platform
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
// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
  BOOST_STATIC_CONSTANT(unsigned int,  class_version = 1 );
#endif
public:
  /** // doc: Platform_Info() {{{
   * \brief Default constructor.
   */ // }}}
  Platform_Info();
  /** // doc: Platform_Info() {{{
   * \brief Constructor with custom Platform and Platform_Query.
   *
   * \param platform
   *    Platform proxy object to be used to query target OpenCL platform.
   * \param query
   *    Platform_Query object which defines what parameters should be
   *    retrieved.
   *
   * This constructor creates Platform_Info object querying the OpenCL \c
   * platform for parameters. The optional \c query parameter defines which
   * parameters should be retrieved from OpenCL. The copy of the \c query
   * object is retained in this Platform_Info object and may be retrieved with
   * last_query().
   */ // }}}
  Platform_Info( Platform const& platform
               , Platform_Query const& query = Platform_Query());
  /** // doc: ~Platform_Info() {{{
   * \brief Destructor.
   */ // }}}
  virtual ~Platform_Info() { }
  /** // {{{
   * \brief Make a composite query to OpenCL platform and store its result
   *        here.
   * \param platform
   *    Platform proxy object to be used to query target OpenCL platform.
   * \param query
   *    Platform_Query object which defines what parameters should be
   *    retrieved.
   * \return Reference to this object.
   *
   * This function performs a composite query to OpenCL platform and stores its
   * result in an internl attributes of this Platform_Info object. The optional
   * \c query parameter says, which parameters should be retrieved from OpenCL.
   * The copy of the \c query object is retained in this Platform_Info object
   * and may be retrieved with last_query().
   */ // }}}
  Platform_Info& query( Platform const& platform
                      , Platform_Query const& query = Platform_Query());
  /** // {{{
   * \brief Identifier of the recently queried OpenCL platform.
   * \return The \c cl_platform_id identifier of an OpenCL platform, whose
   *    parameters are keeps in this object.
   */ // }}}
  inline unsigned long id() const
  {
    return this->_id;
  }
  /** // {{{
   * \brief Platform profile string retrieved with Platform::get_profile().
   * \todo Refine documentation
   */ // }}}
  inline std::string const& profile() const
  {
    return this->_profile;
  }
  /** // {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  inline std::string const& version() const
  {
    return this->_version;
  }
  /** // {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  inline std::string const& name() const
  {
    return this->_name;
  }
  /** // {{{
   * \todo Refine documentation
   * \brief Platform vendor string retrieved with Platform::get_vendor().
   */ // }}}
  inline std::string const& vendor() const
  {
    return this->_vendor;
  }
  /** // {{{
   * \todo Refine documentation
   * \brief Platform extensions string retrieved with
   *        Platform::get_extensions().
   */ // }}}
  inline std::string const& extensions() const
  {
    return this->_extensions;
  }
  /** // {{{
   * \todo Refine documentation
   * \brief Copy of the recently used query object.
   */ // }}}
  inline Platform_Query const& last_query() const
  {
    return this->_last_query;
  }
protected:
  Platform_Info& clear();
private:
// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
  friend class boost::serialization::access;
  /** // {{{
   * \todo Write documentatio
   */ // }}}
  template <class Archive>
  void serialize(Archive& ar, const unsigned int /* version */)
  {
    using boost::serialization::make_nvp;
    ar & make_nvp("last_query", _last_query);
    ar & make_nvp("id", _id);
    ar & make_nvp("profile", _profile);
    ar & make_nvp("version", _version);
    ar & make_nvp("name", _name);
    ar & make_nvp("vendor", _vendor);
    ar & make_nvp("extensions", _extensions);
  }
#endif
private:
  void _init_platform_info();
  // Full copy (not reference) because extenal objects are changing.
  Platform_Query _last_query;
  unsigned long _id;
  std::string _profile;
  std::string _version;
  std::string _name;
  std::string _vendor;
  std::string _extensions;
};

bool operator== (Platform_Info const&, Platform_Info const&);
inline bool operator!= (Platform_Info const& a, Platform_Info const& b)
{ return !(a == b); }

} /* namespace Dimbo */
} /* namespace Cl */

// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
BOOST_CLASS_VERSION( Dimbo::Cl::Platform_Info
                   , Dimbo::Cl::Platform_Info::class_version )
#endif

#endif /* DIMBO_CL_PLATFORM_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
