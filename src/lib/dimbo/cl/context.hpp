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

// dimbo/cl/context.hpp

/** // doc: dimbo/cl/context.hpp {{{ 
 * \file dimbo/cl/context.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CONTEXT_HPP_INCLUDED
#define DIMBO_CL_CONTEXT_HPP_INCLUDED

#include <dimbo/cl/context_properties.hpp>
#include <dimbo/cl/devices.hpp>

#include <dimbo/cl/exceptions/decl_logic_error.hpp>
#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/exceptions/context_uninitialized.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_available.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_found.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_context.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device_type.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_platform.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>

#include <vector>

namespace Dimbo {
namespace Cl {

/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS \
            DIMBO_CL_EXCEPTION(Context_Uninitialized) \
          , DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_PLATFORM) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_DEVICE) \
          , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_AVAILABLE) \
          , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_PLATFORM) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_DEVICE_TYPE) \
          , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_AVAILABLE) \
          , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_FOUND) \
          , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_CONTEXT_CREATE_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) \
          , DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_CONTEXT_CREATE_FROM_TYPE_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) \
          , DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS

/**
 * \ingroup Dimbo_Cl_Platform
 * \brief Proxy to OpenCL context.
 *
 * This class represents OpenCL context and proxies operations on OpenCL
 * context. 
 */
class Context
{
private:
  cl_context  _id;
  Context();
protected:
  cl_context id() const
    throw( DIMBO_CL_EXCEPTION(Context_Uninitialized) );
  /** // doc: _set_id() {{{
   * \todo Write documentation 
   */ // }}}
  void _set_id(cl_context id, bool retain_new, bool release_old)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
  Context(cl_context id, bool retain)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
public:
  /** // doc: Context() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~Context() throw();
  /** // doc: ~Context() {{{
   * \todo Write documentation 
   */ // }}}
  Context(Context_Properties const& props, Devices const& devs,
          void(*pfn_notify)(const char* errinfo,
                            const void* private_info, size_t cb,
                            void* user_data) = NULL,
          void* user_data = NULL)
    throw( DIMBO_CL_CONTEXT_CREATE_EXCEPTIONS );
  /** // doc: Context() {{{
   * \todo Write documentation 
   */ // }}}
  Context(Context_Properties const& properties,
          cl_device_type device_type, 
          void(*pfn_notify)(const char* errinfo,
                            const void* private_info,
                            size_t cb,
                            void* user_data) = NULL, 
          void* user_data = NULL)
    throw( DIMBO_CL_CONTEXT_CREATE_FROM_TYPE_EXCEPTIONS );
  /** // doc: ~Context() {{{
   * \todo Write documentation
   */ // }}}
  Context(Context const& rhs) 
    throw( DIMBO_CL_EXCEPTION(Context_Uninitialized)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
/* FIXME: develop more verbose constant name */
#ifndef SWIG
  /** // {{{
   * \brief Assignment operator
   * \todo Finish documentation
   */ // }}}
  Context& operator=(Context const& rhs)
    throw( DIMBO_CL_EXCEPTION(Context_Uninitialized)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
#endif
  /** // {{{
   * \brief operator == () 
   * \todo Finish documentation
   */ // }}}
  bool operator == (Context const& rhs) const;
  /** // {{{
   * \brief operator != () 
   * \todo Finish documentation
   */ // }}}
  bool operator != (Context const& rhs) const;
  /** // {{{
   * \brief Assignment 
   * \todo Finish documentation
   */ // }}}
  void assign(Context const& rhs)
    throw( DIMBO_CL_EXCEPTION(Context_Uninitialized)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
  /** // {{{
   * \todo Finish documentation
   */ // }}}
  bool is_initialized() const
  {
    return (this->_id != NULL);
  }
  /** // doc: get_info() {{{
   * \todo Write documentation
   */ // }}}
  void get_info(cl_context_info name, size_t value_size,
                void* value, size_t* value_size_ret) const
    throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_reference_count() {{{
   * \todo Write documentation 
   */ // }}}
  cl_uint get_reference_count() const
    throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_devices() {{{
   * \todo Write documentation 
   */ // }}}
  Devices get_devices() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_properties() {{{
   * \todo Write documentation 
   */ // }}}
  Context_Properties get_properties() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
};
/** // {{{
 * \todo Write documentation
 */ // }}}
void 
get_context_info(cl_context context, cl_context_info name,
                 size_t value_size, void *value,
                 size_t* value_size_ret)
  throw( DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS );
/** // {{{
 * \todo Write documentation
 */ // }}}
cl_context
create_context(const cl_context_properties* properties,
               cl_uint num_devices,
               const cl_device_id* devices, 
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data), 
               void* user_data)
  throw( DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS );
/** // {{{
 * \todo Write documentation
 */ // }}}
cl_context
create_context_from_type(const cl_context_properties* properties,
               cl_device_type device_type,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data), 
               void* user_data)
  throw( DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS );
} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_CONTEXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
