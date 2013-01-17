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

// dimbo/cl/platform.hpp

/** // doc: dimbo/cl/platform.hpp {{{
 * \file dimbo/cl/platform.hpp
 *
 * This file contains Dimbo::Cl::Platform class (OpenCL platform proxy object),
 * which provides access to OpenCL platform information.
 *
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_HPP_INCLUDED
#define DIMBO_CL_PLATFORM_HPP_INCLUDED

#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/exceptions/platform_uninitialized.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_platform.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>

#include <vector>

/* OpenCL header */
#include <CL/cl.h>

namespace Dimbo {
namespace Cl {

/** // {{{
 * \ingroup Dimbo_Cl_Platform
 *
 * List of exceptions thrown by Dimbo::Cl::get_platform_info() function.
 * The list includes exceptions corresponding to the OpenCL errors returned
 * by \c clGetPlatformInfo():
 * 
 * - \c CL_INVALID_PLATFORM,
 * - \c CL_INVALID_VALUE,
 * - \c CL_OUT_OF_HOST_MEMORY (first mentioned by OpenCL v1.1).
 *
 */ // }}}
#define DIMBO_CL_GET_PLATFORM_INFO_EXCEPTIONS \
         DIMBO_CL_CL_ERROR_NO(CL_INVALID_PLATFORM) \
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
       , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
       , DIMBO_CL_OTHER_CL_ERROR
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 *
 * List of exceptions thrown by Dimbo::Cl::Platform::get_info() method.
 * In addition to the exceptions defined by
 * \ref DIMBO_CL_GET_PLATFORM_INFO_EXCEPTIONS, this method may also throw
 * exception if the platform proxy object is uninitialized.
 */ // }}}
#define DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS \
         DIMBO_CL_EXCEPTION(Platform_Uninitialized) \
       , DIMBO_CL_GET_PLATFORM_INFO_EXCEPTIONS

/** // {{{ doc: Platform
 * \ingroup Dimbo_Cl_Platform
 * \brief Proxy object to access OpenCL platform information.
 *
 * This class provides access to OpenCL platform information equivalent to
 * that offered by OpenCL's \c clGetPlatformInfo() function. Compared to \c
 * clGetPlatformInfo() it has simplified usage and replaces error codes
 * returned by OpenCL calls with exceptions defined within DIMBO library
 * (see Dimbo::Cl::Cl_Error). It also uses std::string instead of raw \c char*
 * buffers.
 *
 * This is lightweight object, in fact it carries only \c cl_platform_id
 * identifier.
 *
 * \note The class has no virtual destructor to not bloat the objects with
 *       virtual tables.
 *
 */ // }}}
class Platform 
{
private:
  cl_platform_id _platform_id;
public:
  /** // {{{
   * \brief Defalt constructor
   *
   * Sets underlying platform ID to NULL, so the proxy object is regarder
   * uninitialized (is_initialized() returns \c false).
   */ // }}}
  Platform() throw()
    : _platform_id(NULL)
  {
  }
  /** // {{{
   * \brief Copy constructor
   *
   * Initializes this object with the platform ID of another one (\c rhs).
   */ // }}}
  Platform(Platform const& rhs) throw()
    : _platform_id(rhs.id())
  {
  }
  /** // {{{
   * \brief Constructor with explicit conversion.
   *
   * Initializes this object with platform ID provided by caller.
   */ // }}}
  explicit Platform(cl_platform_id platid) throw()
    : _platform_id(platid)
  {
  }
  /** // {{{
   * \brief Desctructor
   */ // }}}
  ~Platform() throw() { }
/* FIXME: develop more verbose constant name */
#ifndef SWIG
  /** // {{{
   * \brief Assignment operator.
   * \return Reference to this object.
   */ // }}}
  Platform& operator=(Platform const& rhs) throw()
  {
    this->assign(rhs);
    return *this;
  }
  /** // {{{
   * \brief Conversion operator.
   * \return %Platform ID keept by this proxy object.
   *
   * Casts Platform object to \c cl_platform_id.
   */ // }}}
  explicit operator cl_platform_id () const
  {
    return this->id();
  }
#endif
  /** // {{{
   * \brief Assignment 
   *
   * Assign new platform ID to this proxy object (start proxying to another 
   * OpenCL platform).
   */ // }}}
  void assign(Platform const& rhs) throw()
  {
    if(&rhs != this)
      {
        this->_platform_id = rhs.id();
      }
  }
  /** // {{{
   * \brief Tell whether this object is initialised or not
   * \return \c true if object is initialised or \c false otherwise
   */ // }}}
  bool is_initialized() const throw()
  {
    return (this->_platform_id != NULL);
  }
  /** // {{{
   * \brief Get the OpenCL platform ID of this platform.
   * \return The platform ID of this platform
   */ // }}}
  cl_platform_id id() const
  {
    return this->_platform_id;
  }
  /** // {{{
   * \brief Get the OpenCL platform ID of this platform
   * \return The platform ID of this platform
   *
   * This function also checks, if the platform ID is not NULL (proxy
   * initialized). If it is NULL, then the exception
   * DIMBO_CL_EXCEPTION(Platform_Uninitialized) is thrown.
   */ // }}}
  cl_platform_id get_valid_id() const 
    throw(DIMBO_CL_EXCEPTION(Platform_Uninitialized));
  /** // {{{
   * \brief Query OpenCL platform for certain information.
   *
   * \param name 
   *    An enumeration constant that identifies the platform information being
   *    queried. It may be \c CL_PLATFORM_PROFILE, \c CL_PLATFORM_VERSION, and
   *    so on. See OpenCL specification (\c clGetPlatformInfo()) for details.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by param_value. This
   *    size in bytes must be ≥ size of return type specified in the OpenCL
   *    specification (\c clGetPlatformInfo()).
   * \param value
   *    A pointer to memory location where appropriate values for a given
   *    param_value will be returned. Possible param_value values returned are
   *    described in the OpenCL specification (\c clGetPlatformInfo()). If
   *    param_value is NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by param_value.
   *    If param_value_size_ret is NULL, it is ignored.
   *
   * This function maps directly to \c clGetGetPlatformInfo(). The platform ID
   * encapsulated by this proxy object is used as first argument to \c
   * clGetPlatformInfo(). 
   *
   * If this object holds uninitialized platform ID, then the method throws
   * exception DIMBO_CL_EXCEPTION(Platform_Uninitialized).
   * 
   */ // }}}
  void get_info(cl_platform_info name, size_t value_size, void* value, 
                size_t* value_size_ret) const
    throw( DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Query the OpenCL for platform profile string.
   *
   * \return The profile name for this platform.
   *
   * This method returns the profile name supported by the implementation.
   * The profile name returned can be one of the following strings:
   * - \c FULL_PROFILE, if the implementation supports the OpenCL
   *   specification (functionality defined as part of the core specification
   *   and does not require any extensions to be supported)
   * - \c EMBEDDED_PROFILE, if the implementation supports the OpenCL 
   *   embedded profile. The embedded profile is defined to be a subset
   *   for each version of OpenCL.
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS.
   */ // }}}
  std::string get_profile() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Query the OpenCL for platform version string
   * \return OpenCL platform version string.
   *
   * This method returns the OpenCL version supported by the implementation.
   * The returned string is same as that returned by 
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_VERSION,...)
   * According to OpenCL specification, this version string has the
   * following format:
     \verbatim OpenCL<space><major_version.minor_version><space><platform-specific information> \endverbatim
   * For example, in OpenCL 1.2 the \c major_version.minor_version value
   * returned will be \c 1.2.
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * DIMBO_CL_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_version() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc) 
         , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Query the OpenCL for platform name string.
   * \return The platform name string.
   *
   * This method returns the name of this OpenCL platform.
   * The returned string is same as that returned by 
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_NAME,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * DIMBO_CL_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_name() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Query the OpenCL for platform vendor string
   * \return The platform vendor string.
   *
   * This method returns vendor string shown by this OpenCL platform.
   * The returned string is same as that returned by 
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_VENDOR,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * DIMBO_CL_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_vendor() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Query the OpenCL for platform extensions string
   * \return Space separated list of platform extension names
   *
   * This method returns a space separated list of extension names (the 
   * extension names themselves do not contain any spaces) supported by
   * the platform. Extensions defined here must be supported by all devices
   * associated with this platform.
   *
   * The returned string is same as that returned by 
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_EXTENSIONS,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * DIMBO_CL_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_extensions() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS );
};
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 *
 * \brief Query OpenCL platform for certain information.
 *
 * \param platform
 *    The platform ID - one of these returned by Dimbo::Cl::get_platform_ids(),
 *    or can be NULL. If platform is NULL, the behavior is
 *    implementation-defined.
 * \param name 
 *    An enumeration constant that identifies the platform information being
 *    queried. It may be \c CL_PLATFORM_PROFILE, \c CL_PLATFORM_VERSION, and
 *    so on. See OpenCL specification (\c clGetPlatformInfo()) for details.
 * \param value_size
 *    Specifies the size in bytes of memory pointed to by param_value. This
 *    size in bytes must be ≥ size of return type specified in the OpenCL
 *    specification (\c clGetPlatformInfo()).
 * \param value
 *    A pointer to memory location where appropriate values for a given
 *    param_value will be returned. Possible param_value values returned are
 *    described in the OpenCL specification (\c clGetPlatformInfo()). If
 *    param_value is NULL, it is ignored.
 * \param value_size_ret
 *    Returns the actual size in bytes of data being queried by param_value.
 *    If param_value_size_ret is NULL, it is ignored.
 *
 * This function maps directly to \c clGetGetPlatformInfo(). The platform ID
 * encapsulated by this proxy object is used as first argument to \c
 * clGetPlatformInfo(). 
 *
 * In case of error, this function throws one of the exceptions mentioned in
 * DIMBO_CL_GET_PLATFORM_INFO_EXCEPTIONS.
 */ // }}}
void 
get_platform_info(  cl_platform_id platform, 
                    cl_platform_info param_name,
                    size_t param_value_size,
                    void* param_value,
                    size_t* param_value_size_ret )
  throw( DIMBO_CL_GET_PLATFORM_INFO_EXCEPTIONS );

} /* namespace Cl */
} /* namespace Dimbo */

#include <dimbo/util/obid_id.hpp>

namespace Dimbo {
template <> struct obid_id<Dimbo::Cl::Platform> 
{
  typedef cl_platform_id type;
};
} /* namespace Dimbo */

#endif /* DIMBO_CL_PLATFORM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
