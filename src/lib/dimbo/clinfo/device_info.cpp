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

} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
