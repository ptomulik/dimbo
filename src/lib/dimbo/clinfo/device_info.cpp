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

// dimbo/clinfo/device_info.cpp

/** // doc: dimbo/clinfo/device_info.cpp {{{
 * @file dimbo/clinfo/device_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/clinfo/device_info.hpp>
#include <boost/regex.hpp>
#include <string>

namespace Dimbo {
namespace Clinfo {

/* ----------------------------------------------------------------------- */
Device_Info::
Device_Info()
{
  _init();
}
/* ----------------------------------------------------------------------- */
Device_Info::
~Device_Info()
{
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear()
{
  this->_clear();
  return *this;
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
cmp(Device_Info const& rhs) const
  throw()
{
  return (this->_id == rhs._id)
      && (this->_type == rhs._type)
      && (this->_vendor_id == rhs._vendor_id)
      && (this->_max_compute_units == rhs._max_compute_units)
      && (this->_max_work_item_dimensions == rhs._max_work_item_dimensions)
      && (this->_max_work_group_size == rhs._max_work_group_size)
      && (this->_max_work_item_sizes == rhs._max_work_item_sizes)
      && (this->_preferred_vector_width_char == rhs._preferred_vector_width_char)
      && (this->_preferred_vector_width_short == rhs._preferred_vector_width_short)
      && (this->_preferred_vector_width_int == rhs._preferred_vector_width_int)
      && (this->_preferred_vector_width_long == rhs._preferred_vector_width_long)
      && (this->_preferred_vector_width_float == rhs._preferred_vector_width_float)
      && (this->_preferred_vector_width_double == rhs._preferred_vector_width_double)
      && (this->_max_clock_frequency == rhs._max_clock_frequency)
      && (this->_address_bits == rhs._address_bits)
      && (this->_max_read_image_args == rhs._max_read_image_args)
      && (this->_max_write_image_args == rhs._max_write_image_args)
      && (this->_max_mem_alloc_size == rhs._max_mem_alloc_size)
      && (this->_image2d_max_width == rhs._image2d_max_width)
      && (this->_image2d_max_height == rhs._image2d_max_height)
      && (this->_image3d_max_width == rhs._image3d_max_width)
      && (this->_image3d_max_height == rhs._image3d_max_height)
      && (this->_image3d_max_depth == rhs._image3d_max_depth)
      && (this->_image_support == rhs._image_support)
      && (this->_max_parameter_size == rhs._max_parameter_size)
      && (this->_max_samplers == rhs._max_samplers)
      && (this->_mem_base_addr_align == rhs._mem_base_addr_align)
      && (this->_min_data_type_align_size == rhs._min_data_type_align_size)
      && (this->_single_fp_config == rhs._single_fp_config)
      && (this->_global_mem_cache_type == rhs._global_mem_cache_type)
      && (this->_global_mem_cacheline_size == rhs._global_mem_cacheline_size)
      && (this->_global_mem_cache_size == rhs._global_mem_cache_size)
      && (this->_global_mem_size == rhs._global_mem_size)
      && (this->_max_constant_buffer_size == rhs._max_constant_buffer_size)
      && (this->_max_constant_args == rhs._max_constant_args)
      && (this->_local_mem_type == rhs._local_mem_type)
      && (this->_local_mem_size == rhs._local_mem_size)
      && (this->_error_correction_support == rhs._error_correction_support)
      && (this->_profiling_timer_resolution == rhs._profiling_timer_resolution)
      && (this->_endian_little == rhs._endian_little)
      && (this->_available == rhs._available)
      && (this->_compiler_available == rhs._compiler_available)
      && (this->_execution_capabilities == rhs._execution_capabilities)
      && (this->_queue_properties == rhs._queue_properties)
      && (this->_name == rhs._name)
      && (this->_vendor == rhs._vendor)
      && (this->_driver_version == rhs._driver_version)
      && (this->_profile == rhs._profile)
      && (this->_version == rhs._version)
      && (this->_extensions == rhs._extensions)
      && (this->_platform_id == rhs._platform_id)
      && (this->_double_fp_config == rhs._double_fp_config)
      && (this->_preferred_vector_width_half == rhs._preferred_vector_width_half)
      && (this->_host_unified_memory == rhs._host_unified_memory)
      && (this->_native_vector_width_char == rhs._native_vector_width_char)
      && (this->_native_vector_width_short == rhs._native_vector_width_short)
      && (this->_native_vector_width_int == rhs._native_vector_width_int)
      && (this->_native_vector_width_long == rhs._native_vector_width_long)
      && (this->_native_vector_width_float == rhs._native_vector_width_float)
      && (this->_native_vector_width_double == rhs._native_vector_width_double)
      && (this->_native_vector_width_half == rhs._native_vector_width_half)
      && (this->_opencl_c_version == rhs._opencl_c_version)
      && (this->_linker_available == rhs._linker_available)
      && (this->_built_in_kernels == rhs._built_in_kernels)
      && (this->_image_max_buffer_size == rhs._image_max_buffer_size)
      && (this->_image_max_array_size == rhs._image_max_array_size)
      && (this->_parent_device_id == rhs._parent_device_id)
      && (this->_partition_max_sub_devices == rhs._partition_max_sub_devices)
      && (this->_partition_properties == rhs._partition_properties)
      && (this->_partition_affinity_domain == rhs._partition_affinity_domain)
      && (this->_partition_type == rhs._partition_type)
      && (this->_reference_count == rhs._reference_count)
      && (this->_preferred_interop_user_sync == rhs._preferred_interop_user_sync)
      && (this->_printf_buffer_size == rhs._printf_buffer_size)
      && (this->_image_pitch_alignment == rhs._image_pitch_alignment)
      && (this->_image_base_address_alignment == rhs._image_base_address_alignment);
}
// getters {{{
/* ----------------------------------------------------------------------- */
unsigned long Device_Info::
id() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_id.get();
}
/* ----------------------------------------------------------------------- */
cl_device_type Device_Info::
type() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_type.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
vendor_id() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_vendor_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_vendor_id.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_compute_units() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_compute_units()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_compute_units.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_work_item_dimensions() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_work_item_dimensions()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_work_item_dimensions.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
max_work_group_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_work_group_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_work_group_size.get();
}
/* ----------------------------------------------------------------------- */
std::vector<size_t> Device_Info::
max_work_item_sizes() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_work_item_sizes()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_work_item_sizes.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_char() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_char()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_char.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_short() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_short()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_short.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_int() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_int()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_int.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_long() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_long()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_long.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_float() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_float()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_float.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_double() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_double()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_double.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_clock_frequency() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_clock_frequency()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_clock_frequency.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
address_bits() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_address_bits()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_address_bits.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_read_image_args() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_read_image_args()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_read_image_args.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_write_image_args() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_write_image_args()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_write_image_args.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong Device_Info::
max_mem_alloc_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_mem_alloc_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_mem_alloc_size.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image2d_max_width() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image2d_max_width()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image2d_max_width.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image2d_max_height() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image2d_max_height()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image2d_max_height.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image3d_max_width() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image3d_max_width()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image3d_max_width.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image3d_max_height() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image3d_max_height()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image3d_max_height.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image3d_max_depth() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image3d_max_depth()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image3d_max_depth.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
image_support() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image_support()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image_support.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
max_parameter_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_parameter_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_parameter_size.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_samplers() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_samplers()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_samplers.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
mem_base_addr_align() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_mem_base_addr_align()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_mem_base_addr_align.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
min_data_type_align_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_min_data_type_align_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_min_data_type_align_size.get();
}
/* ----------------------------------------------------------------------- */
cl_device_fp_config Device_Info::
single_fp_config() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_single_fp_config()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_single_fp_config.get();
}
/* ----------------------------------------------------------------------- */
cl_device_mem_cache_type Device_Info::
global_mem_cache_type() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_global_mem_cache_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_global_mem_cache_type.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
global_mem_cacheline_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_global_mem_cacheline_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_global_mem_cacheline_size.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong Device_Info::
global_mem_cache_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_global_mem_cache_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_global_mem_cache_size.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong Device_Info::
global_mem_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_global_mem_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_global_mem_size.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong Device_Info::
max_constant_buffer_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_constant_buffer_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_constant_buffer_size.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
max_constant_args() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_max_constant_args()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_max_constant_args.get();
}
/* ----------------------------------------------------------------------- */
cl_device_local_mem_type Device_Info::
local_mem_type() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_local_mem_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_local_mem_type.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong Device_Info::
local_mem_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_local_mem_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_local_mem_size.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
error_correction_support() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_error_correction_support()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_error_correction_support.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
profiling_timer_resolution() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_profiling_timer_resolution()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_profiling_timer_resolution.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
endian_little() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_endian_little()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_endian_little.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
available() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_available()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_available.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
compiler_available() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_compiler_available()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_compiler_available.get();
}
/* ----------------------------------------------------------------------- */
cl_device_exec_capabilities Device_Info::
execution_capabilities() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_execution_capabilities()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_execution_capabilities.get();
}
/* ----------------------------------------------------------------------- */
cl_command_queue_properties Device_Info::
queue_properties() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_queue_properties()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_queue_properties.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
name() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_name()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_name.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
vendor() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_vendor()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_vendor.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
driver_version() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_driver_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_driver_version.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
profile() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_profile()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_profile.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
version() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_version.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
extensions() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_extensions()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_extensions.get();
}
/* ----------------------------------------------------------------------- */
unsigned long Device_Info::
platform_id() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_platform_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_platform_id.get();
}
/* ----------------------------------------------------------------------- */
cl_device_fp_config Device_Info::
double_fp_config() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_double_fp_config()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_double_fp_config.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
preferred_vector_width_half() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_vector_width_half()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_vector_width_half.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
host_unified_memory() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_host_unified_memory()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_host_unified_memory.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_char() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_char()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_char.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_short() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_short()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_short.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_int() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_int()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_int.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_long() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_long()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_long.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_float() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_float()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_float.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_double() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_double()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_double.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
native_vector_width_half() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_native_vector_width_half()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_native_vector_width_half.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
opencl_c_version() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_opencl_c_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_opencl_c_version.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
linker_available() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_linker_available()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_linker_available.get();
}
/* ----------------------------------------------------------------------- */
std::string const& Device_Info::
built_in_kernels() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_built_in_kernels()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_built_in_kernels.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image_max_buffer_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image_max_buffer_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image_max_buffer_size.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
image_max_array_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image_max_array_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image_max_array_size.get();
}
/* ----------------------------------------------------------------------- */
unsigned long Device_Info::
parent_device_id() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_parent_device_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_parent_device_id.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
partition_max_sub_devices() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_partition_max_sub_devices()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_partition_max_sub_devices.get();
}
/* ----------------------------------------------------------------------- */
std::vector<cl_device_partition_property> Device_Info::
partition_properties() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_partition_properties()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_partition_properties.get();
}
/* ----------------------------------------------------------------------- */
cl_device_affinity_domain Device_Info::
partition_affinity_domain() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_partition_affinity_domain()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_partition_affinity_domain.get();
}
/* ----------------------------------------------------------------------- */
std::vector<cl_device_partition_property> Device_Info::
partition_type() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_partition_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_partition_type.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
reference_count() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_reference_count()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_reference_count.get();
}
/* ----------------------------------------------------------------------- */
cl_bool Device_Info::
preferred_interop_user_sync() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_preferred_interop_user_sync()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_preferred_interop_user_sync.get();
}
/* ----------------------------------------------------------------------- */
size_t Device_Info::
printf_buffer_size() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_printf_buffer_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_printf_buffer_size.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
image_pitch_alignment() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image_pitch_alignment()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image_pitch_alignment.get();
}
/* ----------------------------------------------------------------------- */
cl_uint Device_Info::
image_base_address_alignment() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_image_base_address_alignment()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_image_base_address_alignment.get();
}
// }}}
// setters {{{
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_id(unsigned long val) throw()
{
  this->_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_type(cl_device_type val) throw()
{
  this->_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_vendor_id(cl_uint val) throw()
{
  this->_vendor_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_compute_units(cl_uint val) throw()
{
  this->_max_compute_units = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_work_item_dimensions(cl_uint val) throw()
{
  this->_max_work_item_dimensions = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_work_group_size(size_t val) throw()
{
  this->_max_work_group_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_work_item_sizes(std::vector<size_t> const& val)
{
  this->_max_work_item_sizes = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_char(cl_uint val) throw()
{
  this->_preferred_vector_width_char = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_short(cl_uint val) throw()
{
  this->_preferred_vector_width_short = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_int(cl_uint val) throw()
{
  this->_preferred_vector_width_int = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_long(cl_uint val) throw()
{
  this->_preferred_vector_width_long = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_float(cl_uint val) throw()
{
  this->_preferred_vector_width_float = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_double(cl_uint val) throw()
{
  this->_preferred_vector_width_double = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_clock_frequency(cl_uint val) throw()
{
  this->_max_clock_frequency = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_address_bits(cl_uint val) throw()
{
  this->_address_bits = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_read_image_args(cl_uint val) throw()
{
  this->_max_read_image_args = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_write_image_args(cl_uint val) throw()
{
  this->_max_write_image_args = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_mem_alloc_size(cl_ulong val) throw()
{
  this->_max_mem_alloc_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image2d_max_width(size_t val) throw()
{
  this->_image2d_max_width = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image2d_max_height(size_t val) throw()
{
  this->_image2d_max_height = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image3d_max_width(size_t val) throw()
{
  this->_image3d_max_width = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image3d_max_height(size_t val) throw()
{
  this->_image3d_max_height = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image3d_max_depth(size_t val) throw()
{
  this->_image3d_max_depth = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image_support(cl_bool val) throw()
{
  this->_image_support = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_parameter_size(size_t val) throw()
{
  this->_max_parameter_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_samplers(cl_uint val) throw()
{
  this->_max_samplers = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_mem_base_addr_align(cl_uint val) throw()
{
  this->_mem_base_addr_align = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_min_data_type_align_size(cl_uint val) throw()
{
  this->_min_data_type_align_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_single_fp_config(cl_device_fp_config val) throw()
{
  this->_single_fp_config = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_global_mem_cache_type(cl_device_mem_cache_type val) throw()
{
  this->_global_mem_cache_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_global_mem_cacheline_size(cl_uint val) throw()
{
  this->_global_mem_cacheline_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_global_mem_cache_size(cl_ulong val) throw()
{
  this->_global_mem_cache_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_global_mem_size(cl_ulong val) throw()
{
  this->_global_mem_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_constant_buffer_size(cl_uint val) throw()
{
  this->_max_constant_buffer_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_max_constant_args(cl_uint val) throw()
{
  this->_max_constant_args = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_local_mem_type(cl_device_local_mem_type val) throw()
{
  this->_local_mem_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_local_mem_size(cl_ulong val) throw()
{
  this->_local_mem_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_error_correction_support(cl_bool val) throw()
{
  this->_error_correction_support = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_profiling_timer_resolution(size_t val) throw()
{
  this->_profiling_timer_resolution = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_endian_little(cl_bool val) throw()
{
  this->_endian_little = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_available(cl_bool val) throw()
{
  this->_available = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_compiler_available(cl_bool val) throw()
{
  this->_compiler_available = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_execution_capabilities(cl_device_exec_capabilities val) throw()
{
  this->_execution_capabilities = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_queue_properties(cl_command_queue_properties val) throw()
{
  this->_queue_properties = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_name(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_name = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_vendor(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_vendor = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_driver_version(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_driver_version = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_profile(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_profile = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_version(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_version = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_extensions(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_extensions = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_platform_id(unsigned long val) throw()
{
  this->_platform_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_double_fp_config(cl_device_fp_config val) throw()
{
  this->_double_fp_config = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_vector_width_half(cl_uint val) throw()
{
  this->_preferred_vector_width_half = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_host_unified_memory(cl_bool val) throw()
{
  this->_host_unified_memory = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_char(cl_uint val) throw()
{
  this->_native_vector_width_char = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_short(cl_uint val) throw()
{
  this->_native_vector_width_short = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_int(cl_uint val) throw()
{
  this->_native_vector_width_int = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_long(cl_uint val) throw()
{
  this->_native_vector_width_long = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_float(cl_uint val) throw()
{
  this->_native_vector_width_float = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_double(cl_uint val) throw()
{
  this->_native_vector_width_double = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_native_vector_width_half(cl_uint val) throw()
{
  this->_native_vector_width_half = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_opencl_c_version(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_opencl_c_version = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_linker_available(cl_bool val) throw()
{
  this->_linker_available = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_built_in_kernels(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_built_in_kernels = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image_max_buffer_size(size_t val) throw()
{
  this->_image_max_buffer_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image_max_array_size(size_t val) throw()
{
  this->_image_max_array_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_parent_device_id(unsigned long val) throw()
{
  this->_parent_device_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_partition_max_sub_devices(cl_uint val) throw()
{
  this->_partition_max_sub_devices = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_partition_properties(std::vector<cl_device_partition_property> const& val)
{
  this->_partition_properties = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_partition_affinity_domain(cl_device_affinity_domain val) throw()
{
  this->_partition_affinity_domain = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_partition_type(std::vector<cl_device_partition_property> const& val)
{
  this->_partition_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_reference_count(cl_uint val) throw()
{
  this->_reference_count = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_preferred_interop_user_sync(cl_bool val) throw()
{
  this->_preferred_interop_user_sync = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_printf_buffer_size(size_t val) throw()
{
  this->_printf_buffer_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image_pitch_alignment(cl_uint val) throw()
{
  this->_image_pitch_alignment = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
set_image_base_address_alignment(cl_uint val) throw()
{
  this->_image_base_address_alignment = val;
  return *this;
}
// }}}
// cleaners {{{
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_id() throw()
{
  this->_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_type() throw()
{
  this->_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_vendor_id() throw()
{
  this->_vendor_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_compute_units() throw()
{
  this->_max_compute_units = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_work_item_dimensions() throw()
{
  this->_max_work_item_dimensions = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_work_group_size() throw()
{
  this->_max_work_group_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_work_item_sizes() throw()
{
  this->_max_work_item_sizes = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_char() throw()
{
  this->_preferred_vector_width_char = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_short() throw()
{
  this->_preferred_vector_width_short = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_int() throw()
{
  this->_preferred_vector_width_int = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_long() throw()
{
  this->_preferred_vector_width_long = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_float() throw()
{
  this->_preferred_vector_width_float = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_double() throw()
{
  this->_preferred_vector_width_double = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_clock_frequency() throw()
{
  this->_max_clock_frequency = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_address_bits() throw()
{
  this->_address_bits = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_read_image_args() throw()
{
  this->_max_read_image_args = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_write_image_args() throw()
{
  this->_max_write_image_args = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_mem_alloc_size() throw()
{
  this->_max_mem_alloc_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image2d_max_width() throw()
{
  this->_image2d_max_width = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image2d_max_height() throw()
{
  this->_image2d_max_height = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image3d_max_width() throw()
{
  this->_image3d_max_width = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image3d_max_height() throw()
{
  this->_image3d_max_height = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image3d_max_depth() throw()
{
  this->_image3d_max_depth = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image_support() throw()
{
  this->_image_support = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_parameter_size() throw()
{
  this->_max_parameter_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_samplers() throw()
{
  this->_max_samplers = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_mem_base_addr_align() throw()
{
  this->_mem_base_addr_align = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_min_data_type_align_size() throw()
{
  this->_min_data_type_align_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_single_fp_config() throw()
{
  this->_single_fp_config = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_global_mem_cache_type() throw()
{
  this->_global_mem_cache_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_global_mem_cacheline_size() throw()
{
  this->_global_mem_cacheline_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_global_mem_cache_size() throw()
{
  this->_global_mem_cache_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_global_mem_size() throw()
{
  this->_global_mem_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_constant_buffer_size() throw()
{
  this->_max_constant_buffer_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_max_constant_args() throw()
{
  this->_max_constant_args = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_local_mem_type() throw()
{
  this->_local_mem_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_local_mem_size() throw()
{
  this->_local_mem_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_error_correction_support() throw()
{
  this->_error_correction_support = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_profiling_timer_resolution() throw()
{
  this->_profiling_timer_resolution = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_endian_little() throw()
{
  this->_endian_little = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_available() throw()
{
  this->_available = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_compiler_available() throw()
{
  this->_compiler_available = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_execution_capabilities() throw()
{
  this->_execution_capabilities = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_queue_properties() throw()
{
  this->_queue_properties = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_name() throw()
{
  this->_name = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_vendor() throw()
{
  this->_vendor = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_driver_version() throw()
{
  this->_driver_version = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_profile() throw()
{
  this->_profile = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_version() throw()
{
  this->_version = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_extensions() throw()
{
  this->_extensions = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_platform_id() throw()
{
  this->_platform_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_double_fp_config() throw()
{
  this->_double_fp_config = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_vector_width_half() throw()
{
  this->_preferred_vector_width_half = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_host_unified_memory() throw()
{
  this->_host_unified_memory = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_char() throw()
{
  this->_native_vector_width_char = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_short() throw()
{
  this->_native_vector_width_short = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_int() throw()
{
  this->_native_vector_width_int = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_long() throw()
{
  this->_native_vector_width_long = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_float() throw()
{
  this->_native_vector_width_float = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_double() throw()
{
  this->_native_vector_width_double = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_native_vector_width_half() throw()
{
  this->_native_vector_width_half = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_opencl_c_version() throw()
{
  this->_opencl_c_version = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_linker_available() throw()
{
  this->_linker_available = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_built_in_kernels() throw()
{
  this->_built_in_kernels = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image_max_buffer_size() throw()
{
  this->_image_max_buffer_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image_max_array_size() throw()
{
  this->_image_max_array_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_parent_device_id() throw()
{
  this->_parent_device_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_partition_max_sub_devices() throw()
{
  this->_partition_max_sub_devices = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_partition_properties() throw()
{
  this->_partition_properties = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_partition_affinity_domain() throw()
{
  this->_partition_affinity_domain = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_partition_type() throw()
{
  this->_partition_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_reference_count() throw()
{
  this->_reference_count = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_preferred_interop_user_sync() throw()
{
  this->_preferred_interop_user_sync = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_printf_buffer_size() throw()
{
  this->_printf_buffer_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image_pitch_alignment() throw()
{
  this->_image_pitch_alignment = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
Device_Info& Device_Info::
clear_image_base_address_alignment() throw()
{
  this->_image_base_address_alignment = boost::none;
  return *this;
}
// }}}
// presence {{{
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_id() const throw()
{
  return this->_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_type() const throw()
{
  return this->_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_vendor_id() const throw()
{
  return this->_vendor_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_compute_units() const throw()
{
  return this->_max_compute_units.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_work_item_dimensions() const throw()
{
  return this->_max_work_item_dimensions.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_work_group_size() const throw()
{
  return this->_max_work_group_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_work_item_sizes() const throw()
{
  return this->_max_work_item_sizes.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_char() const throw()
{
  return this->_preferred_vector_width_char.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_short() const throw()
{
  return this->_preferred_vector_width_short.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_int() const throw()
{
  return this->_preferred_vector_width_int.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_long() const throw()
{
  return this->_preferred_vector_width_long.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_float() const throw()
{
  return this->_preferred_vector_width_float.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_double() const throw()
{
  return this->_preferred_vector_width_double.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_clock_frequency() const throw()
{
  return this->_max_clock_frequency.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_address_bits() const throw()
{
  return this->_address_bits.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_read_image_args() const throw()
{
  return this->_max_read_image_args.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_write_image_args() const throw()
{
  return this->_max_write_image_args.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_mem_alloc_size() const throw()
{
  return this->_max_mem_alloc_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image2d_max_width() const throw()
{
  return this->_image2d_max_width.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image2d_max_height() const throw()
{
  return this->_image2d_max_height.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image3d_max_width() const throw()
{
  return this->_image3d_max_width.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image3d_max_height() const throw()
{
  return this->_image3d_max_height.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image3d_max_depth() const throw()
{
  return this->_image3d_max_depth.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image_support() const throw()
{
  return this->_image_support.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_parameter_size() const throw()
{
  return this->_max_parameter_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_samplers() const throw()
{
  return this->_max_samplers.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_mem_base_addr_align() const throw()
{
  return this->_mem_base_addr_align.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_min_data_type_align_size() const throw()
{
  return this->_min_data_type_align_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_single_fp_config() const throw()
{
  return this->_single_fp_config.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_global_mem_cache_type() const throw()
{
  return this->_global_mem_cache_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_global_mem_cacheline_size() const throw()
{
  return this->_global_mem_cacheline_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_global_mem_cache_size() const throw()
{
  return this->_global_mem_cache_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_global_mem_size() const throw()
{
  return this->_global_mem_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_constant_buffer_size() const throw()
{
  return this->_max_constant_buffer_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_max_constant_args() const throw()
{
  return this->_max_constant_args.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_local_mem_type() const throw()
{
  return this->_local_mem_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_local_mem_size() const throw()
{
  return this->_local_mem_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_error_correction_support() const throw()
{
  return this->_error_correction_support.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_profiling_timer_resolution() const throw()
{
  return this->_profiling_timer_resolution.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_endian_little() const throw()
{
  return this->_endian_little.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_available() const throw()
{
  return this->_available.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_compiler_available() const throw()
{
  return this->_compiler_available.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_execution_capabilities() const throw()
{
  return this->_execution_capabilities.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_queue_properties() const throw()
{
  return this->_queue_properties.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_name() const throw()
{
  return this->_name.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_vendor() const throw()
{
  return this->_vendor.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_driver_version() const throw()
{
  return this->_driver_version.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_profile() const throw()
{
  return this->_profile.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_version() const throw()
{
  return this->_version.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_extensions() const throw()
{
  return this->_extensions.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_platform_id() const throw()
{
  return this->_platform_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_double_fp_config() const throw()
{
  return this->_double_fp_config.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_vector_width_half() const throw()
{
  return this->_preferred_vector_width_half.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_host_unified_memory() const throw()
{
  return this->_host_unified_memory.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_char() const throw()
{
  return this->_native_vector_width_char.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_short() const throw()
{
  return this->_native_vector_width_short.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_int() const throw()
{
  return this->_native_vector_width_int.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_long() const throw()
{
  return this->_native_vector_width_long.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_float() const throw()
{
  return this->_native_vector_width_float.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_double() const throw()
{
  return this->_native_vector_width_double.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_native_vector_width_half() const throw()
{
  return this->_native_vector_width_half.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_opencl_c_version() const throw()
{
  return this->_opencl_c_version.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_linker_available() const throw()
{
  return this->_linker_available.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_built_in_kernels() const throw()
{
  return this->_built_in_kernels.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image_max_buffer_size() const throw()
{
  return this->_image_max_buffer_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image_max_array_size() const throw()
{
  return this->_image_max_array_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_parent_device_id() const throw()
{
  return this->_parent_device_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_partition_max_sub_devices() const throw()
{
  return this->_partition_max_sub_devices.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_partition_properties() const throw()
{
  return this->_partition_properties.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_partition_affinity_domain() const throw()
{
  return this->_partition_affinity_domain.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_partition_type() const throw()
{
  return this->_partition_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_reference_count() const throw()
{
  return this->_reference_count.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_preferred_interop_user_sync() const throw()
{
  return this->_preferred_interop_user_sync.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_printf_buffer_size() const throw()
{
  return this->_printf_buffer_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image_pitch_alignment() const throw()
{
  return this->_image_pitch_alignment.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool Device_Info::
has_image_base_address_alignment() const throw()
{
  return this->_image_base_address_alignment.is_initialized();
}
// }}}
/* ----------------------------------------------------------------------- */
void Device_Info::
_init()
{
  this->_clear();
}
/* ----------------------------------------------------------------------- */
void Device_Info::
_clear()
{
  this -> _id = boost::none;
  this -> _type = boost::none;
  this -> _vendor_id = boost::none;
  this -> _max_compute_units = boost::none;
  this -> _max_work_item_dimensions = boost::none;
  this -> _max_work_item_sizes = boost::none;
  this -> _max_work_group_size = boost::none;
  this -> _preferred_vector_width_char = boost::none;
  this -> _preferred_vector_width_short = boost::none;
  this -> _preferred_vector_width_int = boost::none;
  this -> _preferred_vector_width_long = boost::none;
  this -> _preferred_vector_width_float = boost::none;
  this -> _preferred_vector_width_double = boost::none;
  this -> _max_clock_frequency = boost::none;
  this -> _address_bits = boost::none;
  this -> _max_read_image_args = boost::none;
  this -> _max_write_image_args = boost::none;
  this -> _max_mem_alloc_size = boost::none;
  this -> _image2d_max_width = boost::none;
  this -> _image2d_max_height = boost::none;
  this -> _image3d_max_width = boost::none;
  this -> _image3d_max_height = boost::none;
  this -> _image3d_max_depth = boost::none;
  this -> _image_support = boost::none;
  this -> _max_parameter_size = boost::none;
  this -> _max_samplers = boost::none;
  this -> _mem_base_addr_align = boost::none;
  this -> _min_data_type_align_size = boost::none;
  this -> _single_fp_config = boost::none;
  this -> _global_mem_cache_type = boost::none;
  this -> _global_mem_cacheline_size = boost::none;
  this -> _global_mem_cache_size = boost::none;
  this -> _global_mem_size = boost::none;
  this -> _max_constant_buffer_size = boost::none;
  this -> _max_constant_args = boost::none;
  this -> _local_mem_type = boost::none;
  this -> _local_mem_size = boost::none;
  this -> _error_correction_support = boost::none;
  this -> _profiling_timer_resolution = boost::none;
  this -> _endian_little = boost::none;
  this -> _available = boost::none;
  this -> _compiler_available = boost::none;
  this -> _execution_capabilities = boost::none;
  this -> _queue_properties = boost::none;
  this -> _name = boost::none;
  this -> _vendor = boost::none;
  this -> _driver_version = boost::none;
  this -> _profile = boost::none;
  this -> _version = boost::none;
  this -> _extensions = boost::none;
  this -> _platform_id = boost::none;
  this -> _double_fp_config = boost::none;
  this -> _preferred_vector_width_half = boost::none;
  this -> _host_unified_memory = boost::none;
  this -> _native_vector_width_char = boost::none;
  this -> _native_vector_width_short = boost::none;
  this -> _native_vector_width_int = boost::none;
  this -> _native_vector_width_long = boost::none;
  this -> _native_vector_width_float = boost::none;
  this -> _native_vector_width_double = boost::none;
  this -> _native_vector_width_half = boost::none;
  this -> _opencl_c_version = boost::none;
  this -> _linker_available = boost::none;
  this -> _built_in_kernels = boost::none;
  this -> _image_max_buffer_size = boost::none;
  this -> _image_max_array_size = boost::none;
  this -> _parent_device_id = boost::none;
  this -> _partition_max_sub_devices = boost::none;
  this -> _partition_properties = boost::none;
  this -> _partition_affinity_domain = boost::none;
  this -> _partition_type = boost::none;
  this -> _reference_count = boost::none;
  this -> _preferred_interop_user_sync = boost::none;
  this -> _printf_buffer_size = boost::none;
  this -> _image_pitch_alignment = boost::none;
  this -> _image_base_address_alignment = boost::none;
}

} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
