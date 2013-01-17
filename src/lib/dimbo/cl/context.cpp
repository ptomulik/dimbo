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

// dimbo/cl/context.cpp 

/** // doc: dimbo/cl/context.cpp {{{
 * \file dimbo/cl/context.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/context.hpp>
#include <boost/shared_array.hpp>

#include <dimbo/cl/throw.hpp>
#include <dimbo/cl/throw_cl.hpp>
#include <dimbo/cl/throw_other_cl.hpp>

namespace Dimbo {
namespace Cl {
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(Context const& ctx, cl_context_info name)
  throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  T value;
  ctx.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
template<typename T> static std::vector<T>
_get_vec_info(Context const& ctx, cl_context_info name) 
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  size_t size;
  ctx.get_info(name,0,NULL,&size);
  try {
    std::vector<T> values(size/sizeof(T));
    ctx.get_info(name,values.size()*sizeof(T),&values.front(),NULL);
    return values;
  } catch(std::bad_alloc const& e) {
    DIMBO_CL_THROW(Bad_Alloc);
  }
}
/* ------------------------------------------------------------------------ */
void Context::
_set_id(cl_context ctx, bool retain_new, bool release_old)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) )
{
  if(ctx != this->_ctx) // Avoid unintended deletion by clReleaseContext()
    { 
      if(release_old)
        {
          cl_int err = clReleaseContext(this->get_valid_ctx());
          switch(err)
            {
              case CL_SUCCESS: break;
              case CL_INVALID_CONTEXT: DIMBO_CL_THROW_CL(CL_INVALID_CONTEXT);
              default: DIMBO_CL_THROW_OTHER_CL(err);
            }
        }
      this->_ctx = ctx;
      if(retain_new)
        {
          cl_int err = clRetainContext(this->_ctx);
          switch(err)
            {
              case CL_SUCCESS: break;
              case CL_INVALID_CONTEXT: DIMBO_CL_THROW_CL(CL_INVALID_CONTEXT);
              default: DIMBO_CL_THROW_OTHER_CL(err);
            }
        }
    }
}
/* ------------------------------------------------------------------------ */
Context::
Context(Context_Properties const& props, Devices const& devs,
        void(*pfn_notify)(const char* errinfo,
                          const void* private_info, size_t cb,
                          void* user_data),
        void* user_data)
  throw( DIMBO_CL_CONTEXT_CREATE_EXCEPTIONS  )
{
  // FIXME: handle DIMBO_CL_EXCEPTION(Invalid_Argument)?
  // FIXME: handle DIMBO_CL_EXCEPTION(Not_Enough_Space)?
  cl_context_properties props_array[DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE];
  props.fill_array(props_array, DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE);
  cl_context ctx = create_context(props_array, devs.size(), &devs.ids()[0],
                                  pfn_notify, user_data);
  this->_set_id(ctx, false, false);
}
/* ------------------------------------------------------------------------ */
Context::
Context(const Context_Properties& props,
        cl_device_type device_type, 
        void(*pfn_notify)(const char* errinfo,
                          const void* private_info,
                          size_t cb,
                          void* user_data), 
        void* user_data)
  throw( DIMBO_CL_CONTEXT_CREATE_FROM_TYPE_EXCEPTIONS )
{
  // FIXME: handle DIMBO_CL_EXCEPTION(Invalid_Argument)?
  // FIXME: handle DIMBO_CL_EXCEPTION(Not_Enough_Space)?
  cl_context_properties props_array[DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE];
  props.fill_array(props_array, DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE);
  cl_context ctx = create_context_from_type(props_array, device_type,
                                            pfn_notify, user_data);
  this->_set_id(ctx, false, false);
}
/* ------------------------------------------------------------------------ */
Context::
Context(const Context& rhs) 
  throw( DIMBO_CL_EXCEPTION(Uninitialized_Context)
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) )
{
  this->_set_id(rhs.get_valid_ctx(), true, false);
}
/* ------------------------------------------------------------------------ */
Context::
~Context() throw()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) const& ){ }
      // NOTE: _set_id() also throws DIMBO_CL_EXCEPTION(Uninitialized_Context)
      // but it shouldn't happen here (we have checked, that context is
      // initialized); if it happens anyway, then there is a bug somewhere.
    }
}
/* ------------------------------------------------------------------------ */
void Context::
get_info(cl_context_info name, size_t value_size,
         void* value, size_t* value_size_ret) const
  throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  get_context_info(this->get_valid_ctx(), name, value_size, value, value_size_ret);
}
/* ------------------------------------------------------------------------ */
cl_context Context::
ctx() const
  throw( )
{
  return this->_ctx;
}
/* ------------------------------------------------------------------------ */
cl_context Context::
get_valid_ctx() const
  throw( DIMBO_CL_EXCEPTION(Uninitialized_Context) )
{
  if(!this->is_initialized())
    DIMBO_CL_THROW(Uninitialized_Context);
  return this->_ctx;
}
/* ------------------------------------------------------------------------ */
Context& Context::
operator=(Context const& rhs)
  throw( DIMBO_CL_EXCEPTION(Uninitialized_Context)
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) )
{
  this->assign(rhs);
  return *this;
}
/* ------------------------------------------------------------------------ */
bool Context::
operator == (Context const& rhs) const 
  throw()
{
  return this->_ctx == rhs._ctx;
}
/* ------------------------------------------------------------------------ */
bool Context::
operator != (Context const& rhs) const
  throw()
{
  return ! (*this == rhs);
}
/* ------------------------------------------------------------------------ */
void Context::
assign(Context const& rhs)
  throw( DIMBO_CL_EXCEPTION(Uninitialized_Context) 
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) )
{
  if(&rhs != this)
    {
      this->_set_id(rhs.get_valid_ctx(), true, true);
    }
}
/* ------------------------------------------------------------------------ */
cl_uint Context::
get_reference_count() const
  throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_CONTEXT_REFERENCE_COUNT);
}
/* ------------------------------------------------------------------------ */
cl_uint Context::
get_num_devices() const
  throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_CONTEXT_NUM_DEVICES);
}
/* ------------------------------------------------------------------------ */
Devices Context::
get_devices() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  return Devices(_get_vec_info<cl_device_id>(*this, CL_CONTEXT_DEVICES));
}
/* ------------------------------------------------------------------------ */
Context_Properties Context::
get_properties() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS )
{
  // FIXME: handle DIMBO_CL_EXCEPTION(Invalid_Argument)?
  // FIXME: handle DIMBO_CL_EXCEPTION(Length_Error)?
  typedef cl_context_properties T;
  std::vector<T> props(_get_vec_info<T>(*this, CL_CONTEXT_PROPERTIES));
  return Context_Properties(props);
}
/* ------------------------------------------------------------------------ */
void 
get_context_info(cl_context ctx, cl_context_info name,
                 size_t value_size, void *value,
                 size_t* value_size_ret)
  throw( DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS )
{
  cl_int err = clGetContextInfo(ctx, name, value_size, value, value_size_ret);
  switch(err)
    {
      case CL_SUCCESS:          break;
      case CL_INVALID_VALUE:    DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_INVALID_CONTEXT:  DIMBO_CL_THROW_CL(CL_INVALID_CONTEXT);
      default:                  DIMBO_CL_THROW_OTHER_CL(err);
    }
}
/* ------------------------------------------------------------------------ */
cl_context
create_context(const cl_context_properties* properties,
               cl_uint num_devices,
               const cl_device_id* devices, 
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data), 
               void* user_data)
  throw( DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS )
{
  cl_int err;
  cl_context ctx;
  ctx = clCreateContext(properties, num_devices, devices, pfn_notify,
                        user_data, &err);
  switch(err)
    {
      case CL_SUCCESS:              break;
      case CL_INVALID_PLATFORM:     DIMBO_CL_THROW_CL(CL_INVALID_PLATFORM);
      case CL_INVALID_VALUE:        DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_INVALID_DEVICE:       DIMBO_CL_THROW_CL(CL_INVALID_DEVICE);
      case CL_DEVICE_NOT_AVAILABLE: DIMBO_CL_THROW_CL(CL_DEVICE_NOT_AVAILABLE);
      case CL_OUT_OF_HOST_MEMORY:   DIMBO_CL_THROW_CL(CL_OUT_OF_HOST_MEMORY);
      default:                      DIMBO_CL_THROW_OTHER_CL(err);
    }

  return ctx;
}
/* ------------------------------------------------------------------------ */
cl_context
create_context_from_type(const cl_context_properties* properties,
               cl_device_type device_type,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data), 
               void* user_data)
  throw( DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS )
{
  cl_int err;
  cl_context ctx;
  ctx = clCreateContextFromType(properties, device_type, pfn_notify, user_data,
                                &err);
  switch(err)
    {
      case CL_SUCCESS:              break;
      case CL_INVALID_PLATFORM:     DIMBO_CL_THROW_CL(CL_INVALID_PLATFORM);
      case CL_INVALID_VALUE:        DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_INVALID_DEVICE_TYPE:  DIMBO_CL_THROW_CL(CL_INVALID_DEVICE_TYPE);
      case CL_DEVICE_NOT_AVAILABLE: DIMBO_CL_THROW_CL(CL_DEVICE_NOT_AVAILABLE);
      case CL_DEVICE_NOT_FOUND:     DIMBO_CL_THROW_CL(CL_DEVICE_NOT_FOUND);
      case CL_OUT_OF_HOST_MEMORY:   DIMBO_CL_THROW_CL(CL_OUT_OF_HOST_MEMORY);
      default:                      DIMBO_CL_THROW_OTHER_CL(err);
    }

  return ctx;
}
/* ------------------------------------------------------------------------ */

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
