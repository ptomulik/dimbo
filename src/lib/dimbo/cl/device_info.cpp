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
#include <boost/regex.hpp>
#include <string>

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
  this -> _max_clock_frequency = 0;
  this -> _address_bits = 0;
  this -> _max_read_image_args = 0;
  this -> _max_write_image_args = 0;
  this -> _max_mem_alloc_size = 0;
  this -> _image2d_max_width = 0;
  this -> _image2d_max_height = 0;
  this -> _image3d_max_width = 0;
  this -> _image3d_max_height = 0;
  this -> _image3d_max_depth = 0;
  this -> _image_support = 0;
  this -> _max_parameter_size = 0;
  this -> _max_samplers = 0;
  this -> _mem_base_addr_align = 0;
  this -> _min_data_type_align_size = 0;
  this -> _single_fp_config = 0;
  this -> _global_mem_cache_type = 0;
  this -> _global_mem_cacheline_size = 0;
  this -> _global_mem_cache_size = 0;
  this -> _global_mem_size = 0;
  this -> _max_constant_buffer_size = 0;
  this -> _max_constant_args = 0;
  this -> _local_mem_type = 0;
  this -> _local_mem_size = 0;
  this -> _error_correction_support = 0;
  this -> _profiling_timer_resolution = 0;
  this -> _endian_little = 0;
  this -> _available = 0;
  this -> _compiler_available = 0;
  this -> _execution_capabilities = 0;
  this -> _queue_properties = 0;
  this -> _name.clear();
  this -> _vendor.clear();
  this -> _driver_version.clear();
  this -> _profile.clear();
  this -> _version.clear();
  this -> _extensions.clear();
  this -> _platform_id = 0;
  this -> _double_fp_config = 0;
  this -> _preferred_vector_width_half = 0;
  this -> _host_unified_memory = 0;
  this -> _native_vector_width_char = 0;
  this -> _native_vector_width_short = 0;
  this -> _native_vector_width_int = 0;
  this -> _native_vector_width_long = 0;
  this -> _native_vector_width_float = 0;
  this -> _native_vector_width_double = 0;
  this -> _native_vector_width_half = 0;
  this -> _opencl_c_version.clear();
  this -> _linker_available = 0;
  this -> _built_in_kernels.clear();
  this -> _image_max_buffer_size = 0;
  this -> _image_max_array_size = 0;
  this -> _parent_device_id = 0;
  this -> _partition_max_sub_devices = 0;
  this -> _partition_properties.clear();
  this -> _partition_affinity_domain = 0;
  this -> _partition_type.clear();
  this -> _reference_count = 0;
  this -> _preferred_interop_user_sync = 0;
  this -> _printf_buffer_size = 0;
  this -> _image_pitch_alignment = 0;
  this -> _image_base_address_alignment = 0;
  // }}}
  this->_last_query.select_none();
  return *this;
}

Device_Info& Device_Info::
query(Device const& device, Device_Query const& query)
{
  std::string vs(device.get_version());
  boost::regex re("OpenCL ([0-9]+)\\.([0-9]+).*");
  boost::smatch sm;
  int ver[2];

  if(boost::regex_match(vs, sm, re))
    {
      ver[0] = std::stoi(sm[1]);
      ver[1] = std::stoi(sm[2]);
    }
  else
    {
      ver[0] = 1;
      ver[1] = 0;
    }

  this->_last_query = query;

  if(ver[0] == 1 && ver[1] < 1)
    {
      // ver < 1.1
      this->_last_query.select_preferred_vector_width_half(false);
      this->_last_query.select_host_unified_memory(false);
      this->_last_query.select_native_vector_width_char(false);
      this->_last_query.select_native_vector_width_short(false);
      this->_last_query.select_native_vector_width_int(false);
      this->_last_query.select_native_vector_width_long(false);
      this->_last_query.select_native_vector_width_float(false);
      this->_last_query.select_native_vector_width_double(false);
      this->_last_query.select_native_vector_width_half(false);
      this->_last_query.select_opencl_c_version(false);
    }
  if(ver[0] == 1 && ver[1] < 2)
    {
      // ver < 1.2
      this->_last_query.select_double_fp_config(false);
      this->_last_query.select_linker_available(false);
      this->_last_query.select_built_in_kernels(false);
      this->_last_query.select_image_max_buffer_size(false);
      this->_last_query.select_image_max_array_size(false);
      this->_last_query.select_parent_device_id(false);
      this->_last_query.select_partition_max_sub_devices(false);
      this->_last_query.select_partition_properties(false);
      this->_last_query.select_partition_affinity_domain(false);
      this->_last_query.select_partition_type(false);
      this->_last_query.select_reference_count(false);
      this->_last_query.select_preferred_interop_user_sync(false);
      this->_last_query.select_printf_buffer_size(false);
      this->_last_query.select_image_pitch_alignment(false);
      this->_last_query.select_image_base_address_alignment(false);
    }

  // A lot of "scalar" queries {{{
  if(this->_last_query.id_selected()) {
    this->_id = (unsigned long)device.id();
  }
  if(this->_last_query.type_selected()) {
    this->_type = device.get_type();
  }
  if(this->_last_query.vendor_id_selected()) {
    this->_vendor_id = device.get_vendor_id();
  }
  if(this->_last_query.max_compute_units_selected()) {
    this->_max_compute_units = device.get_max_compute_units();
  }
  if(this->_last_query.max_work_item_dimensions_selected()) {
    this->_max_work_item_dimensions = device.get_max_work_item_dimensions();
  }
  if(this->_last_query.max_work_item_sizes_selected()) {
    this->_max_work_item_sizes = device.get_max_work_item_sizes();
  }
  if(this->_last_query.max_work_group_size_selected()) {
    this->_max_work_group_size = device.get_max_work_group_size();
  }
  if(this->_last_query.preferred_vector_width_char_selected()) {
    this->_preferred_vector_width_char = device.get_preferred_vector_width_char();
  }
  if(this->_last_query.preferred_vector_width_short_selected()) {
    this->_preferred_vector_width_short = device.get_preferred_vector_width_short();
  }
  if(this->_last_query.preferred_vector_width_int_selected()) {
    this->_preferred_vector_width_int = device.get_preferred_vector_width_int();
  }
  if(this->_last_query.preferred_vector_width_long_selected()) {
    this->_preferred_vector_width_long = device.get_preferred_vector_width_long();
  }
  if(this->_last_query.preferred_vector_width_float_selected()) {
    this->_preferred_vector_width_float = device.get_preferred_vector_width_float();
  }
  if(this->_last_query.preferred_vector_width_double_selected()) {
    this->_preferred_vector_width_double = device.get_preferred_vector_width_double();
  }
  if(this->_last_query.max_clock_frequency_selected()) {
    this->_max_clock_frequency = device.get_max_clock_frequency();
  }
  if(this->_last_query.address_bits_selected()) {
    this->_address_bits = device.get_address_bits();
  }
  if(this->_last_query.max_read_image_args_selected()) {
    this->_max_read_image_args = device.get_max_read_image_args();
  }
  if(this->_last_query.max_write_image_args_selected()) {
    this->_max_write_image_args = device.get_max_write_image_args();
  }
  if(this->_last_query.max_mem_alloc_size_selected()) {
    this->_max_mem_alloc_size = device.get_max_mem_alloc_size();
  }
  if(this->_last_query.image2d_max_width_selected()) {
    this->_image2d_max_width = device.get_image2d_max_width();
  }
  if(this->_last_query.image2d_max_height_selected()) {
    this->_image2d_max_height = device.get_image2d_max_height();
  }
  if(this->_last_query.image3d_max_width_selected()) {
    this->_image3d_max_width = device.get_image3d_max_width();
  }
  if(this->_last_query.image3d_max_height_selected()) {
    this->_image3d_max_height = device.get_image3d_max_height();
  }
  if(this->_last_query.image3d_max_depth_selected()) {
    this->_image3d_max_depth = device.get_image3d_max_depth();
  }
  if(this->_last_query.image_support_selected()) {
    this->_image_support = device.get_image_support();
  }
  if(this->_last_query.max_parameter_size_selected()) {
    this->_max_parameter_size = device.get_max_parameter_size();
  }
  if(this->_last_query.max_samplers_selected()) {
    this->_max_samplers = device.get_max_samplers();
  }
  if(this->_last_query.mem_base_addr_align_selected()) {
    this->_mem_base_addr_align = device.get_mem_base_addr_align();
  }
  if(this->_last_query.min_data_type_align_size_selected()) {
    this->_min_data_type_align_size = device.get_min_data_type_align_size();
  }
  if(this->_last_query.single_fp_config_selected()) {
    this->_single_fp_config = device.get_single_fp_config();
  }
  if(this->_last_query.global_mem_cache_type_selected()) {
    this->_global_mem_cache_type = device.get_global_mem_cache_type();
  }
  if(this->_last_query.global_mem_cacheline_size_selected()) {
    this->_global_mem_cacheline_size = device.get_global_mem_cacheline_size();
  }
  if(this->_last_query.global_mem_cache_size_selected()) {
    this->_global_mem_cache_size = device.get_global_mem_cache_size();
  }
  if(this->_last_query.global_mem_size_selected()) {
    this->_global_mem_size = device.get_global_mem_size();
  }
  if(this->_last_query.max_constant_buffer_size_selected()) {
    this->_max_constant_buffer_size = device.get_max_constant_buffer_size();
  }
  if(this->_last_query.max_constant_args_selected()) {
    this->_max_constant_args = device.get_max_constant_args();
  }
  if(this->_last_query.local_mem_type_selected()) {
    this->_local_mem_type = device.get_local_mem_type();
  }
  if(this->_last_query.local_mem_size_selected()) {
    this->_local_mem_size = device.get_local_mem_size();
  }
  if(this->_last_query.error_correction_support_selected()) {
    this->_error_correction_support = device.get_error_correction_support();
  }
  if(this->_last_query.profiling_timer_resolution_selected()) {
    this->_profiling_timer_resolution = device.get_profiling_timer_resolution();
  }
  if(this->_last_query.endian_little_selected()) {
    this->_endian_little = device.get_endian_little();
  }
  if(this->_last_query.available_selected()) {
    this->_available = device.get_available();
  }
  if(this->_last_query.compiler_available_selected()) {
    this->_compiler_available = device.get_compiler_available();
  }
  if(this->_last_query.execution_capabilities_selected()) {
    this->_execution_capabilities = device.get_execution_capabilities();
  }
  if(this->_last_query.queue_properties_selected()) {
    this->_queue_properties = device.get_queue_properties();
  }
  if(this->_last_query.name_selected()) {
    this->_name = device.get_name();
  }
  if(this->_last_query.vendor_selected()) {
    this->_vendor = device.get_vendor();
  }
  if(this->_last_query.driver_version_selected()) {
    this->_driver_version = device.get_driver_version();
  }
  if(this->_last_query.profile_selected()) {
    this->_profile = device.get_profile();
  }
  if(this->_last_query.version_selected()) {
    this->_version = vs;
  }
  if(this->_last_query.extensions_selected()) {
    this->_extensions = device.get_extensions();
  }
  if(this->_last_query.platform_id_selected()) {
    this->_platform_id = (unsigned long)device.get_platform_id();
  }
  if(this->_last_query.double_fp_config_selected()) {
    this->_double_fp_config = (unsigned long)device.get_double_fp_config();
  }
  if(this->_last_query.preferred_vector_width_half_selected()) {
    this->_preferred_vector_width_half = device.get_preferred_vector_width_half();
  }
  if(this->_last_query.host_unified_memory_selected()) {
    this->_host_unified_memory = device.get_host_unified_memory();
  }
  if(this->_last_query.native_vector_width_char_selected()) {
    this->_native_vector_width_char = device.get_native_vector_width_char();
  }
  if(this->_last_query.native_vector_width_short_selected()) {
    this->_native_vector_width_short = device.get_native_vector_width_short();
  }
  if(this->_last_query.native_vector_width_int_selected()) {
    this->_native_vector_width_int = device.get_native_vector_width_int();
  }
  if(this->_last_query.native_vector_width_long_selected()) {
    this->_native_vector_width_long = device.get_native_vector_width_long();
  }
  if(this->_last_query.native_vector_width_float_selected()) {
    this->_native_vector_width_float = device.get_native_vector_width_float();
  }
  if(this->_last_query.native_vector_width_double_selected()) {
    this->_native_vector_width_double = device.get_native_vector_width_double();
  }
  if(this->_last_query.native_vector_width_half_selected()) {
    this->_native_vector_width_half = device.get_native_vector_width_half();
  }
  if(this->_last_query.opencl_c_version_selected()) {
    this->_opencl_c_version = device.get_opencl_c_version();
  }
  if(this->_last_query.linker_available_selected()) {
    this->_linker_available = device.get_linker_available();
  }
  if(this->_last_query.built_in_kernels_selected()) {
    this->_built_in_kernels = device.get_built_in_kernels();
  }
  if(this->_last_query.image_max_buffer_size_selected()) {
    this->_image_max_buffer_size = device.get_image_max_buffer_size();
  }
  if(this->_last_query.image_max_array_size_selected()) {
    this->_image_max_array_size = device.get_image_max_array_size();
  }
  if(this->_last_query.parent_device_id_selected()) {
    this->_parent_device_id = reinterpret_cast<unsigned long>(device.get_parent_device_id());
  }
  if(this->_last_query.partition_max_sub_devices_selected()) {
    this->_partition_max_sub_devices = device.get_partition_max_sub_devices();
  }
  if(this->_last_query.partition_properties_selected()) {
    this->_partition_properties = device.get_partition_properties();
  }
  if(this->_last_query.partition_affinity_domain_selected()) {
    this->_partition_affinity_domain = device.get_partition_affinity_domain();
  }
  if(this->_last_query.partition_type_selected()) {
    this->_partition_type = device.get_partition_type();
  }
  if(this->_last_query.reference_count_selected()) {
    this->_reference_count = device.get_reference_count();
  }
  if(this->_last_query.preferred_interop_user_sync_selected()) {
    this->_preferred_interop_user_sync = device.get_preferred_interop_user_sync();
  }
  if(this->_last_query.printf_buffer_size_selected()) {
    this->_printf_buffer_size = device.get_printf_buffer_size();
  }
  if(this->_last_query.image_pitch_alignment_selected()) {
    this->_image_pitch_alignment = device.get_image_pitch_alignment();
  }
  if(this->_last_query.image_base_address_alignment_selected()) {
    this->_image_base_address_alignment = device.get_image_base_address_alignment();
  }
  // }}}
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
