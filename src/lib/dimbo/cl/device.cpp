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
#include <boost/regex.hpp>
#include <string>

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
size_t Device::
get_max_work_group_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_MAX_WORK_GROUP_SIZE);
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
cl_ulong Device::
get_max_mem_alloc_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_ulong>(*this, CL_DEVICE_MAX_MEM_ALLOC_SIZE);
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
cl_bool Device::
get_image_support() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_IMAGE_SUPPORT);
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
get_max_samplers() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_MAX_SAMPLERS);
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
cl_ulong Device::
get_max_constant_buffer_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_ulong>(*this, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
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
get_extensions() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_EXTENSIONS);
}
/* ------------------------------------------------------------------------ */
cl_platform_id Device::
get_platform_id() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_platform_id>(*this, CL_DEVICE_PLATFORM);
}
/* ------------------------------------------------------------------------ */
cl_device_fp_config Device::
get_double_fp_config() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_fp_config>(*this, CL_DEVICE_DOUBLE_FP_CONFIG);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_preferred_vector_width_half() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_host_unified_memory() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_HOST_UNIFIED_MEMORY);
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
std::string Device::
get_opencl_c_version() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_OPENCL_C_VERSION);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_linker_available() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_LINKER_AVAILABLE);
}
/* ------------------------------------------------------------------------ */
std::string Device::
get_built_in_kernels() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_DEVICE_BUILT_IN_KERNELS);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image_max_buffer_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE_MAX_BUFFER_SIZE);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_image_max_array_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_IMAGE_MAX_ARRAY_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_device_id Device::
get_parent_device_id() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_id>(*this, CL_DEVICE_PARENT_DEVICE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_partition_max_sub_devices() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_PARTITION_MAX_SUB_DEVICES);
}
/* ------------------------------------------------------------------------ */
std::vector<cl_device_partition_property> Device::
get_partition_properties() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_vec_info<cl_device_partition_property>(*this, CL_DEVICE_PARTITION_PROPERTIES);
}
/* ------------------------------------------------------------------------ */
cl_device_affinity_domain Device::
get_partition_affinity_domain() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_device_affinity_domain>(*this, CL_DEVICE_PARTITION_AFFINITY_DOMAIN);
}
/* ------------------------------------------------------------------------ */
std::vector<cl_device_partition_property> Device::
get_partition_type() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_vec_info<cl_device_partition_property>(*this, CL_DEVICE_PARTITION_TYPE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_reference_count() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_REFERENCE_COUNT);
}
/* ------------------------------------------------------------------------ */
cl_bool Device::
get_preferred_interop_user_sync() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_bool>(*this, CL_DEVICE_PREFERRED_INTEROP_USER_SYNC);
}
/* ------------------------------------------------------------------------ */
size_t Device::
get_printf_buffer_size() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<size_t>(*this, CL_DEVICE_PRINTF_BUFFER_SIZE);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_image_pitch_alignment() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_IMAGE_PITCH_ALIGNMENT);
}
/* ------------------------------------------------------------------------ */
cl_uint Device::
get_image_base_address_alignment() const
  throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
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
  cl_int err = T::clGetDeviceInfo(device, param_name, param_value_size,
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
Dimbo::Clinfo::Device_Info
query_device_info( Device const& device,
                   Dimbo::Clinfo::Device_Query const& query)
{
  std::string vs(device.get_version());
  boost::regex re("OpenCL ([0-9]+)\\.([0-9]+).*");
  boost::smatch sm;
  int major, minor;

  if(boost::regex_match(vs, sm, re))
    {
      major = std::stoi(sm[1]);
      minor = std::stoi(sm[2]);
    }
  else
    {
      major = 1;
      minor = 0;
    }

  Dimbo::Clinfo::Device_Query query2(query);
  query2.restrict_to(major, minor);

  Dimbo::Clinfo::Device_Info info;

  // A lot of "scalar" queries {{{
  if(query2.id_selected()) {
    info.set_id(reinterpret_cast<unsigned long>(device.id()));
  }
  if(query2.type_selected()) {
    info.set_type(device.get_type());
  }
  if(query2.vendor_id_selected()) {
    info.set_vendor_id(device.get_vendor_id());
  }
  if(query2.max_compute_units_selected()) {
    info.set_max_compute_units(device.get_max_compute_units());
  }
  if(query2.max_work_item_dimensions_selected()) {
    info.set_max_work_item_dimensions(device.get_max_work_item_dimensions());
  }
  if(query2.max_work_item_sizes_selected()) {
    info.set_max_work_item_sizes(device.get_max_work_item_sizes());
  }
  if(query2.max_work_group_size_selected()) {
    info.set_max_work_group_size(device.get_max_work_group_size());
  }
  if(query2.preferred_vector_width_char_selected()) {
    info.set_preferred_vector_width_char(device.get_preferred_vector_width_char());
  }
  if(query2.preferred_vector_width_short_selected()) {
    info.set_preferred_vector_width_short(device.get_preferred_vector_width_short());
  }
  if(query2.preferred_vector_width_int_selected()) {
    info.set_preferred_vector_width_int(device.get_preferred_vector_width_int());
  }
  if(query2.preferred_vector_width_long_selected()) {
    info.set_preferred_vector_width_long(device.get_preferred_vector_width_long());
  }
  if(query2.preferred_vector_width_float_selected()) {
    info.set_preferred_vector_width_float(device.get_preferred_vector_width_float());
  }
  if(query2.preferred_vector_width_double_selected()) {
    info.set_preferred_vector_width_double(device.get_preferred_vector_width_double());
  }
  if(query2.max_clock_frequency_selected()) {
    info.set_max_clock_frequency(device.get_max_clock_frequency());
  }
  if(query2.address_bits_selected()) {
    info.set_address_bits(device.get_address_bits());
  }
  if(query2.max_read_image_args_selected()) {
    info.set_max_read_image_args(device.get_max_read_image_args());
  }
  if(query2.max_write_image_args_selected()) {
    info.set_max_write_image_args(device.get_max_write_image_args());
  }
  if(query2.max_mem_alloc_size_selected()) {
    info.set_max_mem_alloc_size(device.get_max_mem_alloc_size());
  }
  if(query2.image2d_max_width_selected()) {
    info.set_image2d_max_width(device.get_image2d_max_width());
  }
  if(query2.image2d_max_height_selected()) {
    info.set_image2d_max_height(device.get_image2d_max_height());
  }
  if(query2.image3d_max_width_selected()) {
    info.set_image3d_max_width(device.get_image3d_max_width());
  }
  if(query2.image3d_max_height_selected()) {
    info.set_image3d_max_height(device.get_image3d_max_height());
  }
  if(query2.image3d_max_depth_selected()) {
    info.set_image3d_max_depth(device.get_image3d_max_depth());
  }
  if(query2.image_support_selected()) {
    info.set_image_support(device.get_image_support());
  }
  if(query2.max_parameter_size_selected()) {
    info.set_max_parameter_size(device.get_max_parameter_size());
  }
  if(query2.max_samplers_selected()) {
    info.set_max_samplers(device.get_max_samplers());
  }
  if(query2.mem_base_addr_align_selected()) {
    info.set_mem_base_addr_align(device.get_mem_base_addr_align());
  }
  if(query2.min_data_type_align_size_selected()) {
    info.set_min_data_type_align_size(device.get_min_data_type_align_size());
  }
  if(query2.single_fp_config_selected()) {
    info.set_single_fp_config(device.get_single_fp_config());
  }
  if(query2.global_mem_cache_type_selected()) {
    info.set_global_mem_cache_type(device.get_global_mem_cache_type());
  }
  if(query2.global_mem_cacheline_size_selected()) {
    info.set_global_mem_cacheline_size(device.get_global_mem_cacheline_size());
  }
  if(query2.global_mem_cache_size_selected()) {
    info.set_global_mem_cache_size(device.get_global_mem_cache_size());
  }
  if(query2.global_mem_size_selected()) {
    info.set_global_mem_size(device.get_global_mem_size());
  }
  if(query2.max_constant_buffer_size_selected()) {
    info.set_max_constant_buffer_size(device.get_max_constant_buffer_size());
  }
  if(query2.max_constant_args_selected()) {
    info.set_max_constant_args(device.get_max_constant_args());
  }
  if(query2.local_mem_type_selected()) {
    info.set_local_mem_type(device.get_local_mem_type());
  }
  if(query2.local_mem_size_selected()) {
    info.set_local_mem_size(device.get_local_mem_size());
  }
  if(query2.error_correction_support_selected()) {
    info.set_error_correction_support(device.get_error_correction_support());
  }
  if(query2.profiling_timer_resolution_selected()) {
    info.set_profiling_timer_resolution(device.get_profiling_timer_resolution());
  }
  if(query2.endian_little_selected()) {
    info.set_endian_little(device.get_endian_little());
  }
  if(query2.available_selected()) {
    info.set_available(device.get_available());
  }
  if(query2.compiler_available_selected()) {
    info.set_compiler_available(device.get_compiler_available());
  }
  if(query2.execution_capabilities_selected()) {
    info.set_execution_capabilities(device.get_execution_capabilities());
  }
  if(query2.queue_properties_selected()) {
    info.set_queue_properties(device.get_queue_properties());
  }
  if(query2.name_selected()) {
    info.set_name(device.get_name());
  }
  if(query2.vendor_selected()) {
    info.set_vendor(device.get_vendor());
  }
  if(query2.driver_version_selected()) {
    info.set_driver_version(device.get_driver_version());
  }
  if(query2.profile_selected()) {
    info.set_profile(device.get_profile());
  }
  if(query2.version_selected()) {
    info.set_version(vs);
  }
  if(query2.extensions_selected()) {
    info.set_extensions(device.get_extensions());
  }
  if(query2.platform_id_selected()) {
    info.set_platform_id(reinterpret_cast<unsigned long>(device.get_platform_id()));
  }
  if(query2.double_fp_config_selected()) {
    info.set_double_fp_config(reinterpret_cast<unsigned long>(device.get_double_fp_config()));
  }
  if(query2.preferred_vector_width_half_selected()) {
    info.set_preferred_vector_width_half(device.get_preferred_vector_width_half());
  }
  if(query2.host_unified_memory_selected()) {
    info.set_host_unified_memory(device.get_host_unified_memory());
  }
  if(query2.native_vector_width_char_selected()) {
    info.set_native_vector_width_char(device.get_native_vector_width_char());
  }
  if(query2.native_vector_width_short_selected()) {
    info.set_native_vector_width_short(device.get_native_vector_width_short());
  }
  if(query2.native_vector_width_int_selected()) {
    info.set_native_vector_width_int(device.get_native_vector_width_int());
  }
  if(query2.native_vector_width_long_selected()) {
    info.set_native_vector_width_long(device.get_native_vector_width_long());
  }
  if(query2.native_vector_width_float_selected()) {
    info.set_native_vector_width_float(device.get_native_vector_width_float());
  }
  if(query2.native_vector_width_double_selected()) {
    info.set_native_vector_width_double(device.get_native_vector_width_double());
  }
  if(query2.native_vector_width_half_selected()) {
    info.set_native_vector_width_half(device.get_native_vector_width_half());
  }
  if(query2.opencl_c_version_selected()) {
    info.set_opencl_c_version(device.get_opencl_c_version());
  }
  if(query2.linker_available_selected()) {
    info.set_linker_available(device.get_linker_available());
  }
  if(query2.built_in_kernels_selected()) {
    info.set_built_in_kernels(device.get_built_in_kernels());
  }
  if(query2.image_max_buffer_size_selected()) {
    info.set_image_max_buffer_size(device.get_image_max_buffer_size());
  }
  if(query2.image_max_array_size_selected()) {
    info.set_image_max_array_size(device.get_image_max_array_size());
  }
  if(query2.parent_device_id_selected()) {
    info.set_parent_device_id(reinterpret_cast<unsigned long>(device.get_parent_device_id()));
  }
  if(query2.partition_max_sub_devices_selected()) {
    info.set_partition_max_sub_devices(device.get_partition_max_sub_devices());
  }
  if(query2.partition_properties_selected()) {
    info.set_partition_properties(device.get_partition_properties());
  }
  if(query2.partition_affinity_domain_selected()) {
    info.set_partition_affinity_domain(device.get_partition_affinity_domain());
  }
  if(query2.partition_type_selected()) {
    info.set_partition_type(device.get_partition_type());
  }
  if(query2.reference_count_selected()) {
    info.set_reference_count(device.get_reference_count());
  }
  if(query2.preferred_interop_user_sync_selected()) {
    info.set_preferred_interop_user_sync(device.get_preferred_interop_user_sync());
  }
  if(query2.printf_buffer_size_selected()) {
    info.set_printf_buffer_size(device.get_printf_buffer_size());
  }
  if(query2.image_pitch_alignment_selected()) {
    info.set_image_pitch_alignment(device.get_image_pitch_alignment());
  }
  if(query2.image_base_address_alignment_selected()) {
    info.set_image_base_address_alignment(device.get_image_base_address_alignment());
  }
  // }}}

  return info;
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
