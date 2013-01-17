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

// dimbo/cl/device_info.cpp 

/** // doc: dimbo/cl/device_info.cpp {{{
 * @file dimbo/cl/device_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/device_info.hpp>

namespace Dimbo {
namespace Cl {

Device_Info::
Device_Info()
{
  _init_device_info();
}

Device_Info::
Device_Info(Device const& device, Device_Query const& query)
{
  this->query(device, query);
}

Device_Info::
~Device_Info()
{
}

Device_Info& Device_Info::
clear()
{
  // A lot of commands {{{
  this -> _id = 0;
  this -> _type = 0;
  this -> _vendor_id = 0;
  this -> _max_compute_units = 0;
  this -> _max_work_item_dimensions = 0;
  this -> _max_work_item_sizes.clear();
  this -> _max_work_group_size = 0;
  this -> _preferred_vector_width_char = 0;
  this -> _preferred_vector_width_short = 0;
  this -> _preferred_vector_width_int = 0;
  this -> _preferred_vector_width_long = 0;
  this -> _preferred_vector_width_float = 0;
  this -> _preferred_vector_width_double = 0;
  this -> _preferred_vector_width_half = 0;
  this -> _native_vector_width_char = 0;
  this -> _native_vector_width_short = 0;
  this -> _native_vector_width_int = 0;
  this -> _native_vector_width_long = 0;
  this -> _native_vector_width_float = 0;
  this -> _native_vector_width_double = 0;
  this -> _native_vector_width_half = 0;
  this -> _max_clock_frequency = 0;
  this -> _address_bits = 0;
  this -> _max_mem_alloc_size = 0;
  this -> _image_support = 0;
  this -> _max_read_image_args = 0;
  this -> _max_write_image_args = 0;
  this -> _image2d_max_width = 0;
  this -> _image2d_max_height = 0;
  this -> _image3d_max_width = 0;
  this -> _image3d_max_height = 0;
  this -> _image3d_max_depth = 0;
  this -> _max_samplers = 0;
  this -> _max_parameter_size = 0;
  this -> _mem_base_addr_align = 0;
  this -> _min_data_type_align_size = 0;
  this -> _single_fp_config = 0;
  this -> _global_mem_cache_type = 0;
  this -> _global_mem_cacheline_size = 0;
  this -> _global_mem_cache_size = 0;
  this -> _global_mem_size = 0;
  this -> _max_constant_args = 0;
  this -> _local_mem_type = 0;
  this -> _local_mem_size = 0;
  this -> _error_correction_support = 0;
  this -> _host_unified_memory = 0;
  this -> _profiling_timer_resolution = 0;
  this -> _endian_little = 0;
  this -> _available = 0;
  this -> _compiler_available = 0;
  this -> _execution_capabilities = 0;
  this -> _queue_properties = 0;
  this -> _platform_id = 0;
  this -> _name.clear();
  this -> _vendor.clear();
  this -> _driver_version.clear();
  this -> _profile.clear();
  this -> _version.clear();
  this -> _opencl_c_version.clear();
  this -> _extensions.clear();
  // }}}
  this->_last_query.select_none();
  return *this;
}

Device_Info& Device_Info::
query(Device const& device, Device_Query const& query)
{
  // A lot of "scalar" queries {{{
  if(query.id_selected()) {
    this->_id = (unsigned long)device.id();
  }
  if(query.type_selected()) {
    this->_type = device.get_type();
  }
  if(query.vendor_id_selected()) {
    this->_vendor_id = device.get_vendor_id();
  }
  if(query.max_compute_units_selected()) {
    this->_max_compute_units = device.get_max_compute_units();
  }
  if(query.max_work_item_dimensions_selected()) {
    this->_max_work_item_dimensions = device.get_max_work_item_dimensions();
  }
  if(query.max_work_item_sizes_selected()) {
    this->_max_work_item_sizes = device.get_max_work_item_sizes();
  }
  if(query.max_work_group_size_selected()) {
    this->_max_work_group_size = device.get_max_work_group_size();
  }
  if(query.preferred_vector_width_char_selected()) {
    this->_preferred_vector_width_char = device.get_preferred_vector_width_char();
  }
  if(query.preferred_vector_width_short_selected()) {
    this->_preferred_vector_width_short = device.get_preferred_vector_width_short();
  }
  if(query.preferred_vector_width_int_selected()) {
    this->_preferred_vector_width_int = device.get_preferred_vector_width_int();
  }
  if(query.preferred_vector_width_long_selected()) {
    this->_preferred_vector_width_long = device.get_preferred_vector_width_long();
  }
  if(query.preferred_vector_width_float_selected()) {
    this->_preferred_vector_width_float = device.get_preferred_vector_width_float();
  }
  if(query.preferred_vector_width_double_selected()) {
    this->_preferred_vector_width_double = device.get_preferred_vector_width_double();
  }
  if(query.preferred_vector_width_half_selected()) {
    this->_preferred_vector_width_half = device.get_preferred_vector_width_half();
  }
  if(query.native_vector_width_char_selected()) {
    this->_native_vector_width_char = device.get_native_vector_width_char();
  }
  if(query.native_vector_width_short_selected()) {
    this->_native_vector_width_short = device.get_native_vector_width_short();
  }
  if(query.native_vector_width_int_selected()) {
    this->_native_vector_width_int = device.get_native_vector_width_int();
  }
  if(query.native_vector_width_long_selected()) {
    this->_native_vector_width_long = device.get_native_vector_width_long();
  }
  if(query.native_vector_width_float_selected()) {
    this->_native_vector_width_float = device.get_native_vector_width_float();
  }
  if(query.native_vector_width_double_selected()) {
    this->_native_vector_width_double = device.get_native_vector_width_double();
  }
  if(query.native_vector_width_half_selected()) {
    this->_native_vector_width_half = device.get_native_vector_width_half();
  }
  if(query.max_clock_frequency_selected()) {
    this->_max_clock_frequency = device.get_max_clock_frequency();
  }
  if(query.address_bits_selected()) {
    this->_address_bits = device.get_address_bits();
  }
  if(query.max_mem_alloc_size_selected()) {
    this->_max_mem_alloc_size = device.get_max_mem_alloc_size();
  }
  if(query.image_support_selected()) {
    this->_image_support = device.get_image_support();
  }
  if(query.max_read_image_args_selected()) {
    this->_max_read_image_args = device.get_max_read_image_args();
  }
  if(query.max_write_image_args_selected()) {
    this->_max_write_image_args = device.get_max_write_image_args();
  }
  if(query.image2d_max_width_selected()) {
    this->_image2d_max_width = device.get_image2d_max_width();
  }
  if(query.image2d_max_height_selected()) {
    this->_image2d_max_height = device.get_image2d_max_height();
  }
  if(query.image3d_max_width_selected()) {
    this->_image3d_max_width = device.get_image3d_max_width();
  }
  if(query.image3d_max_height_selected()) {
    this->_image3d_max_height = device.get_image3d_max_height();
  }
  if(query.image3d_max_depth_selected()) {
    this->_image3d_max_depth = device.get_image3d_max_depth();
  }
  if(query.max_samplers_selected()) {
    this->_max_samplers = device.get_max_samplers();
  }
  if(query.max_parameter_size_selected()) {
    this->_max_parameter_size = device.get_max_parameter_size();
  }
  if(query.mem_base_addr_align_selected()) {
    this->_mem_base_addr_align = device.get_mem_base_addr_align();
  }
  if(query.min_data_type_align_size_selected()) {
    this->_min_data_type_align_size = device.get_min_data_type_align_size();
  }
  if(query.single_fp_config_selected()) {
    this->_single_fp_config = device.get_single_fp_config();
  }
  if(query.global_mem_cache_type_selected()) {
    this->_global_mem_cache_type = device.get_global_mem_cache_type();
  }
  if(query.global_mem_cacheline_size_selected()) {
    this->_global_mem_cacheline_size = device.get_global_mem_cacheline_size();
  }
  if(query.global_mem_cache_size_selected()) {
    this->_global_mem_cache_size = device.get_global_mem_cache_size();
  }
  if(query.global_mem_size_selected()) {
    this->_global_mem_size = device.get_global_mem_size();
  }
  if(query.max_constant_args_selected()) {
    this->_max_constant_args = device.get_max_constant_args();
  }
  if(query.local_mem_type_selected()) {
    this->_local_mem_type = device.get_local_mem_type();
  }
  if(query.local_mem_size_selected()) {
    this->_local_mem_size = device.get_local_mem_size();
  }
  if(query.error_correction_support_selected()) {
    this->_error_correction_support = device.get_error_correction_support();
  }
  if(query.host_unified_memory_selected()) {
    this->_host_unified_memory = device.get_host_unified_memory();
  }
  if(query.profiling_timer_resolution_selected()) {
    this->_profiling_timer_resolution = device.get_profiling_timer_resolution();
  }
  if(query.endian_little_selected()) {
    this->_endian_little = device.get_endian_little();
  }
  if(query.available_selected()) {
    this->_available = device.get_available();
  }
  if(query.compiler_available_selected()) {
    this->_compiler_available = device.get_compiler_available();
  }
  if(query.execution_capabilities_selected()) {
    this->_execution_capabilities = device.get_execution_capabilities();
  }
  if(query.queue_properties_selected()) {
    this->_queue_properties = device.get_queue_properties();
  }
  if(query.platform_id_selected()) {
    this->_platform_id = (unsigned long)device.get_platform_id();
  }
  if(query.name_selected()) {
    this->_name = device.get_name();
  }
  if(query.vendor_selected()) {
    this->_vendor = device.get_vendor();
  }
  if(query.driver_version_selected()) {
    this->_driver_version = device.get_driver_version();
  }
  if(query.profile_selected()) {
    this->_profile = device.get_profile();
  }
  if(query.version_selected()) {
    this->_version = device.get_version();
  }
  if(query.opencl_c_version_selected()) {
    this->_opencl_c_version = device.get_opencl_c_version();
  }
  if(query.extensions_selected()) {
    this->_extensions = device.get_extensions();
  }
  // }}}
  this->_last_query = query;
  return *this;
}

void Device_Info::
_init_device_info()
{
  this->clear();
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
