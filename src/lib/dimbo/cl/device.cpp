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

// dimbo/cl/device.cpp

/** // doc: dimbo/cl/device.cpp {{{
 * \file dimbo/cl/device.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/device.hpp>
#include <boost/shared_array.hpp>
#include <dimbo/cl/throw.hpp>
#include <dimbo/cl/throw_cl.hpp>
#include <dimbo/cl/throw_other_cl.hpp>

namespace Dimbo {
namespace Cl {
static std::string
_get_string_info(Device const& dev, cl_device_info name)
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  size_t size;
  dev.get_info(name, 0, NULL, &size);

  boost::shared_array<char> str;
  try { str = boost::shared_array<char>(new char[size]); }
  catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
  dev.get_info(name, size, str.get(), &size);
  try { return std::string(str.get()); }
  catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
}
template<typename T> static T
_get_pod_info(Device const& dev, cl_device_info name)
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  T value;
  dev.get_info(name,sizeof(value),&value,NULL);
  return value;
}
template<typename T> static std::vector<T>
_get_vec_info(Device const& dev, cl_device_info name)
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  size_t size;
  dev.get_info(name,0,NULL,&size);
  try {
    std::vector<T> values(size/sizeof(T));
    dev.get_info(name,values.size()*sizeof(T),&values.front(),NULL);
    return values;
  } catch(std::bad_alloc const& e) {
    DIMBO_CL_THROW(Bad_Alloc);
  }
}
/* ------------------------------------------------------------------------ */
cl_device_id Device::
get_valid_id() const
  throw(DIMBO_CL_EXCEPTION(Uninitialized_Device))
{
  if(!this->is_initialized())
    DIMBO_CL_THROW(Uninitialized_Device);
  return this->_device_id;
}
/* ------------------------------------------------------------------------ */
void Device::
get_info( cl_device_info name, size_t value_size, void* value,
          size_t* value_size_ret) const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  get_device_info(this->get_valid_id(),name,value_size,value,value_size_ret);
}
/* ------------------------------------------------------------------------ */
cl_device_type Device::
get_type() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_type>(*this, CL_DEVICE_TYPE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_vendor_id() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_VENDOR_ID);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_compute_units() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_COMPUTE_UNITS);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_work_item_dimensions() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
}
/* ------------------------------------------------------------------------ */
std::vector<size_t> Device::
get_max_work_item_sizes() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_vec_info<size_t>(*this, CL_DEVICE_MAX_WORK_ITEM_SIZES);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_max_work_group_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_MAX_WORK_GROUP_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_char() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_short() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_int() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_long() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_float() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_double() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_half() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_char() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_short() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_int() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_INT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_long() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_float() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_double() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_native_vector_width_half() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_clock_frequency() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_CLOCK_FREQUENCY);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_address_bits() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_ADDRESS_BITS);
}
/* ------------------------------------------------------------------------ */
cl_ulong Device::
get_max_mem_alloc_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_ulong>(*this, CL_DEVICE_MAX_MEM_ALLOC_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_image_support() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_IMAGE_SUPPORT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_read_image_args() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_READ_IMAGE_ARGS);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_write_image_args() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image2d_max_width() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE2D_MAX_WIDTH);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image2d_max_height() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE2D_MAX_HEIGHT);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image3d_max_width() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE3D_MAX_WIDTH);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image3d_max_height() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE3D_MAX_HEIGHT);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image3d_max_depth() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE3D_MAX_DEPTH);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_samplers() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_SAMPLERS);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_max_parameter_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_MAX_PARAMETER_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_mem_base_addr_align() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MEM_BASE_ADDR_ALIGN);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_min_data_type_align_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_device_fp_config Device::
get_single_fp_config() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_fp_config >(*this, CL_DEVICE_SINGLE_FP_CONFIG);
}
/* ------------------------------------------------------------------------ */
cl_device_mem_cache_type Device::
get_global_mem_cache_type() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_mem_cache_type>(*this,
    CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_global_mem_cacheline_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_ulong Device::
get_global_mem_cache_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_ulong>(*this, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_ulong Device::
get_global_mem_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_ulong>(*this, CL_DEVICE_GLOBAL_MEM_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_max_constant_args() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_int>(*this, CL_DEVICE_MAX_CONSTANT_ARGS);
}
/* ------------------------------------------------------------------------ */
cl_device_local_mem_type Device::
get_local_mem_type() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_local_mem_type>(*this,
    CL_DEVICE_LOCAL_MEM_TYPE);
}
/* ------------------------------------------------------------------------ */
cl_ulong Device::
get_local_mem_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_ulong>(*this, CL_DEVICE_LOCAL_MEM_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_error_correction_support() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_ERROR_CORRECTION_SUPPORT);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_host_unified_memory() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_HOST_UNIFIED_MEMORY);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_profiling_timer_resolution() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_PROFILING_TIMER_RESOLUTION);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_endian_little() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_ENDIAN_LITTLE);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_available() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_AVAILABLE);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_compiler_available() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_COMPILER_AVAILABLE);
}
/* ------------------------------------------------------------------------ */
cl_device_exec_capabilities Device::
get_execution_capabilities() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_exec_capabilities>(*this,
    CL_DEVICE_EXECUTION_CAPABILITIES);
}
/* ------------------------------------------------------------------------ */
cl_command_queue_properties Device::
get_queue_properties() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_command_queue_properties>(*this,
    CL_DEVICE_QUEUE_PROPERTIES);
}
/* ------------------------------------------------------------------------ */
cl_platform_id Device::
get_platform_id() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_platform_id>(*this, CL_DEVICE_PLATFORM);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_name() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_NAME);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_vendor() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_VENDOR);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_driver_version() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DRIVER_VERSION);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_profile() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_PROFILE);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_version() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_VERSION);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_opencl_c_version() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_OPENCL_C_VERSION);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_extensions() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_EXTENSIONS);
}
/* ------------------------------------------------------------------------ */
} /* namespace Cl */
} /* namespace Dimbo */

namespace Dimbo {
namespace Cl {
/* ------------------------------------------------------------------------ */
void
get_device_info(  cl_device_id device,
                  cl_device_info param_name,
                  size_t param_value_size,
                  void* param_value,
                  size_t* param_value_size_ret)
  throw( DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS )
{
  cl_int err = clGetDeviceInfo(device, param_name, param_value_size,
                               param_value, param_value_size_ret);
  switch(err)
    {
      case CL_SUCCESS:            break;
      case CL_INVALID_DEVICE:     DIMBO_CL_THROW_CL(CL_INVALID_DEVICE);
      case CL_INVALID_VALUE:      DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_OUT_OF_RESOURCES:   DIMBO_CL_THROW_CL(CL_OUT_OF_RESOURCES);
      case CL_OUT_OF_HOST_MEMORY: DIMBO_CL_THROW_CL(CL_OUT_OF_HOST_MEMORY);
      default:                    DIMBO_CL_THROW_OTHER_CL(err);
    }
}
/* ------------------------------------------------------------------------ */
} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
