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

Device_Info::
Device_Info()
{
  _init_device_info();
}
#if 0
Device_Info::
Device_Info(Device const& device, Device_Query const& query)
{
  this->query(device, query);
}
#endif
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
#if 0
Device_Info& Device_Info::
query(Device const& device, Device_Query const& query)
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

  this->_last_query = query;
  this->_last_query.restrict_to(major, minor);

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
#endif
void Device_Info::
_init_device_info()
{
  this->clear();
}

void Device_Info::
write(Dimbo::Protobuf::Clinfo::Device_Info& buff) const
{
  buff.Clear();
  if(this->_last_query.id_selected())
    buff.set_id(this->id());
  if(this->_last_query.type_selected())
    buff.set_type(this->type());
  if(this->_last_query.vendor_id_selected())
    buff.set_vendor_id(this->vendor_id());
  if(this->_last_query.max_compute_units_selected())
    buff.set_max_compute_units(this->max_compute_units());
  if(this->_last_query.max_work_item_dimensions_selected())
    buff.set_max_work_item_dimensions(this->max_work_item_dimensions());
  if(this->_last_query.max_work_group_size_selected())
    buff.set_max_work_group_size(this->max_work_group_size());
  if(this->_last_query.max_work_item_sizes_selected())
    for(size_t i=0; i < this->max_work_item_sizes().size(); ++i)
      buff.add_max_work_item_sizes(this->max_work_item_sizes()[i]);
  if(this->_last_query.preferred_vector_width_char_selected())
    buff.set_preferred_vector_width_char(this->preferred_vector_width_char());
  if(this->_last_query.preferred_vector_width_short_selected())
    buff.set_preferred_vector_width_short(this->preferred_vector_width_short());
  if(this->_last_query.preferred_vector_width_int_selected())
    buff.set_preferred_vector_width_int(this->preferred_vector_width_int());
  if(this->_last_query.preferred_vector_width_long_selected())
    buff.set_preferred_vector_width_long(this->preferred_vector_width_long());
  if(this->_last_query.preferred_vector_width_float_selected())
    buff.set_preferred_vector_width_float(this->preferred_vector_width_float());
  if(this->_last_query.preferred_vector_width_double_selected())
    buff.set_preferred_vector_width_double(this->preferred_vector_width_double());
  if(this->_last_query.max_clock_frequency_selected())
    buff.set_max_clock_frequency(this->max_clock_frequency());
  if(this->_last_query.address_bits_selected())
    buff.set_address_bits(this->address_bits());
  if(this->_last_query.max_read_image_args_selected())
    buff.set_max_read_image_args(this->max_read_image_args());
  if(this->_last_query.max_write_image_args_selected())
    buff.set_max_write_image_args(this->max_write_image_args());
  if(this->_last_query.max_mem_alloc_size_selected())
    buff.set_max_mem_alloc_size(this->max_mem_alloc_size());
  if(this->_last_query.image2d_max_width_selected())
    buff.set_image2d_max_width(this->image2d_max_width());
  if(this->_last_query.image2d_max_height_selected())
    buff.set_image2d_max_height(this->image2d_max_height());
  if(this->_last_query.image3d_max_width_selected())
    buff.set_image3d_max_width(this->image3d_max_width());
  if(this->_last_query.image3d_max_height_selected())
    buff.set_image3d_max_height(this->image3d_max_height());
  if(this->_last_query.image3d_max_depth_selected())
    buff.set_image3d_max_depth(this->image3d_max_depth());
  if(this->_last_query.image_support_selected())
    buff.set_image_support(this->image_support());
  if(this->_last_query.max_parameter_size_selected())
    buff.set_max_parameter_size(this->max_parameter_size());
  if(this->_last_query.max_samplers_selected())
    buff.set_max_samplers(this->max_samplers());
  if(this->_last_query.mem_base_addr_align_selected())
    buff.set_mem_base_addr_align(this->mem_base_addr_align());
  if(this->_last_query.min_data_type_align_size_selected())
    buff.set_min_data_type_align_size(this->min_data_type_align_size());
  if(this->_last_query.single_fp_config_selected())
    buff.set_single_fp_config(this->single_fp_config());
  if(this->_last_query.global_mem_cache_type_selected())
    buff.set_global_mem_cache_type(this->global_mem_cache_type());
  if(this->_last_query.global_mem_cacheline_size_selected())
    buff.set_global_mem_cacheline_size(this->global_mem_cacheline_size());
  if(this->_last_query.global_mem_cache_size_selected())
    buff.set_global_mem_cache_size(this->global_mem_cache_size());
  if(this->_last_query.global_mem_size_selected())
    buff.set_global_mem_size(this->global_mem_size());
  if(this->_last_query.max_constant_buffer_size_selected())
    buff.set_max_constant_buffer_size(this->max_constant_buffer_size());
  if(this->_last_query.max_constant_args_selected())
    buff.set_max_constant_args(this->max_constant_args());
  if(this->_last_query.local_mem_type_selected())
    buff.set_local_mem_type(this->local_mem_type());
  if(this->_last_query.local_mem_size_selected())
    buff.set_local_mem_size(this->local_mem_size());
  if(this->_last_query.error_correction_support_selected())
    buff.set_error_correction_support(this->error_correction_support());
  if(this->_last_query.profiling_timer_resolution_selected())
    buff.set_profiling_timer_resolution(this->profiling_timer_resolution());
  if(this->_last_query.endian_little_selected())
    buff.set_endian_little(this->endian_little());
  if(this->_last_query.available_selected())
    buff.set_available(this->available());
  if(this->_last_query.compiler_available_selected())
    buff.set_compiler_available(this->compiler_available());
  if(this->_last_query.execution_capabilities_selected())
    buff.set_execution_capabilities(this->execution_capabilities());
  if(this->_last_query.queue_properties_selected())
    buff.set_queue_properties(this->queue_properties());
  if(this->_last_query.name_selected())
    buff.set_name(this->name());
  if(this->_last_query.vendor_selected())
    buff.set_vendor(this->vendor());
  if(this->_last_query.driver_version_selected())
    buff.set_driver_version(this->driver_version());
  if(this->_last_query.profile_selected())
    buff.set_profile(this->profile());
  if(this->_last_query.version_selected())
    buff.set_version(this->version());
  if(this->_last_query.extensions_selected())
    buff.set_extensions(this->extensions());
  if(this->_last_query.platform_id_selected())
    buff.set_platform_id(this->platform_id());
  if(this->_last_query.double_fp_config_selected())
    buff.set_double_fp_config(this->double_fp_config());
  if(this->_last_query.preferred_vector_width_half_selected())
    buff.set_preferred_vector_width_half(this->preferred_vector_width_half());
  if(this->_last_query.host_unified_memory_selected())
    buff.set_host_unified_memory(this->host_unified_memory());
  if(this->_last_query.native_vector_width_char_selected())
    buff.set_native_vector_width_char(this->native_vector_width_char());
  if(this->_last_query.native_vector_width_short_selected())
    buff.set_native_vector_width_short(this->native_vector_width_short());
  if(this->_last_query.native_vector_width_int_selected())
    buff.set_native_vector_width_int(this->native_vector_width_int());
  if(this->_last_query.native_vector_width_long_selected())
    buff.set_native_vector_width_long(this->native_vector_width_long());
  if(this->_last_query.native_vector_width_float_selected())
    buff.set_native_vector_width_float(this->native_vector_width_float());
  if(this->_last_query.native_vector_width_double_selected())
    buff.set_native_vector_width_double(this->native_vector_width_double());
  if(this->_last_query.native_vector_width_half_selected())
    buff.set_native_vector_width_half(this->native_vector_width_half());
  if(this->_last_query.opencl_c_version_selected())
    buff.set_opencl_c_version(this->opencl_c_version());
  if(this->_last_query.linker_available_selected())
    buff.set_linker_available(this->linker_available());
  if(this->_last_query.built_in_kernels_selected())
    buff.set_built_in_kernels(this->built_in_kernels());
  if(this->_last_query.image_max_buffer_size_selected())
    buff.set_image_max_buffer_size(this->image_max_buffer_size());
  if(this->_last_query.image_max_array_size_selected())
    buff.set_image_max_array_size(this->image_max_array_size());
  if(this->_last_query.parent_device_id_selected())
    buff.set_parent_device_id(this->parent_device_id());
  if(this->_last_query.partition_max_sub_devices_selected())
    buff.set_partition_max_sub_devices(this->partition_max_sub_devices());
  if(this->_last_query.partition_properties_selected())
    for(size_t i=0; i < this->partition_properties().size(); ++i)
      buff.add_partition_properties(this->partition_properties()[i]);
  if(this->_last_query.partition_affinity_domain_selected())
    buff.set_partition_affinity_domain(this->partition_affinity_domain());
  if(this->_last_query.partition_type_selected())
    for(size_t i=0; i < this->partition_type().size(); ++i)
      buff.add_partition_type(this->partition_type()[i]);
  if(this->_last_query.reference_count_selected())
    buff.set_reference_count(this->reference_count());
  if(this->_last_query.preferred_interop_user_sync_selected())
    buff.set_preferred_interop_user_sync(this->preferred_interop_user_sync());
  if(this->_last_query.printf_buffer_size_selected())
    buff.set_printf_buffer_size(this->printf_buffer_size());
  if(this->_last_query.image_pitch_alignment_selected())
    buff.set_image_pitch_alignment(this->image_pitch_alignment());
  if(this->_last_query.image_base_address_alignment_selected())
    buff.set_image_base_address_alignment(this->image_base_address_alignment());
}

void Device_Info::
read(Dimbo::Protobuf::Clinfo::Device_Info const& buff)
{
  this->clear();
  if(buff.has_id())
    {
      this->_id = buff.id();
      this->_last_query.select_id();
    }
  if(buff.has_type())
    {
      this->_type = buff.type();
      this->_last_query.select_type();
    }
  if(buff.has_vendor_id())
    {
      this->_vendor_id = buff.vendor_id();
      this->_last_query.select_vendor_id();
    }
  if(buff.has_max_compute_units())
    {
      this->_max_compute_units = buff.max_compute_units();
      this->_last_query.select_max_compute_units();
    }
  if(buff.has_max_work_item_dimensions())
    {
      this->_max_work_item_dimensions = buff.max_work_item_dimensions();
      this->_last_query.select_max_work_item_dimensions();
    }
  if(buff.has_max_work_group_size())
    {
      this->_max_work_group_size = buff.max_work_group_size();
      this->_last_query.select_max_work_group_size();
    }
  if(buff.max_work_item_sizes_size() > 0)
    {
      this->_max_work_item_sizes.assign(buff.max_work_item_sizes().begin(),buff.max_work_item_sizes().end());
      this->_last_query.select_max_work_item_sizes();
    }
  if(buff.has_preferred_vector_width_char())
    {
      this->_preferred_vector_width_char = buff.preferred_vector_width_char();
      this->_last_query.select_preferred_vector_width_char();
    }
  if(buff.has_preferred_vector_width_short())
    {
      this->_preferred_vector_width_short = buff.preferred_vector_width_short();
      this->_last_query.select_preferred_vector_width_short();
    }
  if(buff.has_preferred_vector_width_int())
    {
      this->_preferred_vector_width_int = buff.preferred_vector_width_int();
      this->_last_query.select_preferred_vector_width_int();
    }
  if(buff.has_preferred_vector_width_long())
    {
      this->_preferred_vector_width_long = buff.preferred_vector_width_long();
      this->_last_query.select_preferred_vector_width_long();
    }
  if(buff.has_preferred_vector_width_float())
    {
      this->_preferred_vector_width_float = buff.preferred_vector_width_float();
      this->_last_query.select_preferred_vector_width_float();
    }
  if(buff.has_preferred_vector_width_double())
    {
      this->_preferred_vector_width_double = buff.preferred_vector_width_double();
      this->_last_query.select_preferred_vector_width_double();
    }
  if(buff.has_max_clock_frequency())
    {
      this->_max_clock_frequency = buff.max_clock_frequency();
      this->_last_query.select_max_clock_frequency();
    }
  if(buff.has_address_bits())
    {
      this->_address_bits = buff.address_bits();
      this->_last_query.select_address_bits();
    }
  if(buff.has_max_read_image_args())
    {
      this->_max_read_image_args = buff.max_read_image_args();
      this->_last_query.select_max_read_image_args();
    }
  if(buff.has_max_write_image_args())
    {
      this->_max_write_image_args = buff.max_write_image_args();
      this->_last_query.select_max_write_image_args();
    }
  if(buff.has_max_mem_alloc_size())
    {
      this->_max_mem_alloc_size = buff.max_mem_alloc_size();
      this->_last_query.select_max_mem_alloc_size();
    }
  if(buff.has_image2d_max_width())
    {
      this->_image2d_max_width = buff.image2d_max_width();
      this->_last_query.select_image2d_max_width();
    }
  if(buff.has_image2d_max_height())
    {
      this->_image2d_max_height = buff.image2d_max_height();
      this->_last_query.select_image2d_max_height();
    }
  if(buff.has_image3d_max_width())
    {
      this->_image3d_max_width = buff.image3d_max_width();
      this->_last_query.select_image3d_max_width();
    }
  if(buff.has_image3d_max_height())
    {
      this->_image3d_max_height = buff.image3d_max_height();
      this->_last_query.select_image3d_max_height();
    }
  if(buff.has_image3d_max_depth())
    {
      this->_image3d_max_depth = buff.image3d_max_depth();
      this->_last_query.select_image3d_max_depth();
    }
  if(buff.has_image_support())
    {
      this->_image_support = buff.image_support();
      this->_last_query.select_image_support();
    }
  if(buff.has_max_parameter_size())
    {
      this->_max_parameter_size = buff.max_parameter_size();
      this->_last_query.select_max_parameter_size();
    }
  if(buff.has_max_samplers())
    {
      this->_max_samplers = buff.max_samplers();
      this->_last_query.select_max_samplers();
    }
  if(buff.has_mem_base_addr_align())
    {
      this->_mem_base_addr_align = buff.mem_base_addr_align();
      this->_last_query.select_mem_base_addr_align();
    }
  if(buff.has_min_data_type_align_size())
    {
      this->_min_data_type_align_size = buff.min_data_type_align_size();
      this->_last_query.select_min_data_type_align_size();
    }
  if(buff.has_single_fp_config())
    {
      this->_single_fp_config = buff.single_fp_config();
      this->_last_query.select_single_fp_config();
    }
  if(buff.has_global_mem_cache_type())
    {
      this->_global_mem_cache_type = buff.global_mem_cache_type();
      this->_last_query.select_global_mem_cache_type();
    }
  if(buff.has_global_mem_cacheline_size())
    {
      this->_global_mem_cacheline_size = buff.global_mem_cacheline_size();
      this->_last_query.select_global_mem_cacheline_size();
    }
  if(buff.has_global_mem_cache_size())
    {
      this->_global_mem_cache_size = buff.global_mem_cache_size();
      this->_last_query.select_global_mem_cache_size();
    }
  if(buff.has_global_mem_size())
    {
      this->_global_mem_size = buff.global_mem_size();
      this->_last_query.select_global_mem_size();
    }
  if(buff.has_max_constant_buffer_size())
    {
      this->_max_constant_buffer_size = buff.max_constant_buffer_size();
      this->_last_query.select_max_constant_buffer_size();
    }
  if(buff.has_max_constant_args())
    {
      this->_max_constant_args = buff.max_constant_args();
      this->_last_query.select_max_constant_args();
    }
  if(buff.has_local_mem_type())
    {
      this->_local_mem_type = buff.local_mem_type();
      this->_last_query.select_local_mem_type();
    }
  if(buff.has_local_mem_size())
    {
      this->_local_mem_size = buff.local_mem_size();
      this->_last_query.select_local_mem_size();
    }
  if(buff.has_error_correction_support())
    {
      this->_error_correction_support = buff.error_correction_support();
      this->_last_query.select_error_correction_support();
    }
  if(buff.has_profiling_timer_resolution())
    {
      this->_profiling_timer_resolution = buff.profiling_timer_resolution();
      this->_last_query.select_profiling_timer_resolution();
    }
  if(buff.has_endian_little())
    {
      this->_endian_little = buff.endian_little();
      this->_last_query.select_endian_little();
    }
  if(buff.has_available())
    {
      this->_available = buff.available();
      this->_last_query.select_available();
    }
  if(buff.has_compiler_available())
    {
      this->_compiler_available = buff.compiler_available();
      this->_last_query.select_compiler_available();
    }
  if(buff.has_execution_capabilities())
    {
      this->_execution_capabilities = buff.execution_capabilities();
      this->_last_query.select_execution_capabilities();
    }
  if(buff.has_queue_properties())
    {
      this->_queue_properties = buff.queue_properties();
      this->_last_query.select_queue_properties();
    }
  if(buff.has_name())
    {
      this->_name = buff.name();
      this->_last_query.select_name();
    }
  if(buff.has_vendor())
    {
      this->_vendor = buff.vendor();
      this->_last_query.select_vendor();
    }
  if(buff.has_driver_version())
    {
      this->_driver_version = buff.driver_version();
      this->_last_query.select_driver_version();
    }
  if(buff.has_profile())
    {
      this->_profile = buff.profile();
      this->_last_query.select_profile();
    }
  if(buff.has_version())
    {
      this->_version = buff.version();
      this->_last_query.select_version();
    }
  if(buff.has_extensions())
    {
      this->_extensions = buff.extensions();
      this->_last_query.select_extensions();
    }
  if(buff.has_platform_id())
    {
      this->_platform_id = buff.platform_id();
      this->_last_query.select_platform_id();
    }
  if(buff.has_double_fp_config())
    {
      this->_double_fp_config = buff.double_fp_config();
      this->_last_query.select_double_fp_config();
    }
  if(buff.has_preferred_vector_width_half())
    {
      this->_preferred_vector_width_half = buff.preferred_vector_width_half();
      this->_last_query.select_preferred_vector_width_half();
    }
  if(buff.has_host_unified_memory())
    {
      this->_host_unified_memory = buff.host_unified_memory();
      this->_last_query.select_host_unified_memory();
    }
  if(buff.has_native_vector_width_char())
    {
      this->_native_vector_width_char = buff.native_vector_width_char();
      this->_last_query.select_native_vector_width_char();
    }
  if(buff.has_native_vector_width_short())
    {
      this->_native_vector_width_short = buff.native_vector_width_short();
      this->_last_query.select_native_vector_width_short();
    }
  if(buff.has_native_vector_width_int())
    {
      this->_native_vector_width_int = buff.native_vector_width_int();
      this->_last_query.select_native_vector_width_int();
    }
  if(buff.has_native_vector_width_long())
    {
      this->_native_vector_width_long = buff.native_vector_width_long();
      this->_last_query.select_native_vector_width_long();
    }
  if(buff.has_native_vector_width_float())
    {
      this->_native_vector_width_float = buff.native_vector_width_float();
      this->_last_query.select_native_vector_width_float();
    }
  if(buff.has_native_vector_width_double())
    {
      this->_native_vector_width_double = buff.native_vector_width_double();
      this->_last_query.select_native_vector_width_double();
    }
  if(buff.has_native_vector_width_half())
    {
      this->_native_vector_width_half = buff.native_vector_width_half();
      this->_last_query.select_native_vector_width_half();
    }
  if(buff.has_opencl_c_version())
    {
      this->_opencl_c_version = buff.opencl_c_version();
      this->_last_query.select_opencl_c_version();
    }
  if(buff.has_linker_available())
    {
      this->_linker_available = buff.linker_available();
      this->_last_query.select_linker_available();
    }
  if(buff.has_built_in_kernels())
    {
      this->_built_in_kernels = buff.built_in_kernels();
      this->_last_query.select_built_in_kernels();
    }
  if(buff.has_image_max_buffer_size())
    {
      this->_image_max_buffer_size = buff.image_max_buffer_size();
      this->_last_query.select_image_max_buffer_size();
    }
  if(buff.has_image_max_array_size())
    {
      this->_image_max_array_size = buff.image_max_array_size();
      this->_last_query.select_image_max_array_size();
    }
  if(buff.has_parent_device_id())
    {
      this->_parent_device_id = buff.parent_device_id();
      this->_last_query.select_parent_device_id();
    }
  if(buff.has_partition_max_sub_devices())
    {
      this->_partition_max_sub_devices = buff.partition_max_sub_devices();
      this->_last_query.select_partition_max_sub_devices();
    }
  if(buff.partition_properties().size() > 0)
    {
      this->_partition_properties.assign(buff.partition_properties().begin(),buff.partition_properties().end());
      this->_last_query.select_partition_properties();
    }
  if(buff.has_partition_affinity_domain())
    {
      this->_partition_affinity_domain = buff.partition_affinity_domain();
      this->_last_query.select_partition_affinity_domain();
    }
  if(buff.partition_type().size() > 0)
    {
      this->_partition_type.assign(buff.partition_type().begin(),buff.partition_type().end());
      this->_last_query.select_partition_type();
    }
  if(buff.has_reference_count())
    {
      this->_reference_count = buff.reference_count();
      this->_last_query.select_reference_count();
    }
  if(buff.has_preferred_interop_user_sync())
    {
      this->_preferred_interop_user_sync = buff.preferred_interop_user_sync();
      this->_last_query.select_preferred_interop_user_sync();
    }
  if(buff.has_printf_buffer_size())
    {
      this->_printf_buffer_size = buff.printf_buffer_size();
      this->_last_query.select_printf_buffer_size();
    }
  if(buff.has_image_pitch_alignment())
    {
      this->_image_pitch_alignment = buff.image_pitch_alignment();
      this->_last_query.select_image_pitch_alignment();
    }
  if(buff.has_image_base_address_alignment())
    {
      this->_image_base_address_alignment = buff.image_base_address_alignment();
      this->_last_query.select_image_base_address_alignment();
    }
}

bool operator== (Device_Info const& a, Device_Info const& b)
{
  Device_Query const& aq = a.last_query();
  Device_Query const& bq = b.last_query();

  if((aq != bq)
  || (aq.id_selected() && (a.id() != b.id()))
  || (aq.type_selected() && (a.type() != b.type()))
  || (aq.vendor_id_selected() && (a.vendor_id() != b.vendor_id()))
  || (aq.max_compute_units_selected() && (a.max_compute_units() != b.max_compute_units()))
  || (aq.max_work_item_dimensions_selected() && (a.max_work_item_dimensions() != b.max_work_item_dimensions()))
  || (aq.max_work_group_size_selected() && (a.max_work_group_size() != b.max_work_group_size()))
  || (aq.max_work_item_sizes_selected() && (a.max_work_item_sizes() != b.max_work_item_sizes()))
  || (aq.preferred_vector_width_char_selected() && (a.preferred_vector_width_char() != b.preferred_vector_width_char()))
  || (aq.preferred_vector_width_short_selected() && (a.preferred_vector_width_short() != b.preferred_vector_width_short()))
  || (aq.preferred_vector_width_int_selected() && (a.preferred_vector_width_int() != b.preferred_vector_width_int()))
  || (aq.preferred_vector_width_long_selected() && (a.preferred_vector_width_long() != b.preferred_vector_width_long()))
  || (aq.preferred_vector_width_float_selected() && (a.preferred_vector_width_float() != b.preferred_vector_width_float()))
  || (aq.preferred_vector_width_double_selected() && (a.preferred_vector_width_double() != b.preferred_vector_width_double()))
  || (aq.max_clock_frequency_selected() && (a.max_clock_frequency() != b.max_clock_frequency()))
  || (aq.address_bits_selected() && (a.address_bits() != b.address_bits()))
  || (aq.max_read_image_args_selected() && (a.max_read_image_args() != b.max_read_image_args()))
  || (aq.max_write_image_args_selected() && (a.max_write_image_args() != b.max_write_image_args()))
  || (aq.max_mem_alloc_size_selected() && (a.max_mem_alloc_size() != b.max_mem_alloc_size()))
  || (aq.image2d_max_width_selected() && (a.image2d_max_width() != b.image2d_max_width()))
  || (aq.image2d_max_height_selected() && (a.image2d_max_height() != b.image2d_max_height()))
  || (aq.image3d_max_width_selected() && (a.image3d_max_width() != b.image3d_max_width()))
  || (aq.image3d_max_height_selected() && (a.image3d_max_height() != b.image3d_max_height()))
  || (aq.image3d_max_depth_selected() && (a.image3d_max_depth() != b.image3d_max_depth()))
  || (aq.image_support_selected() && (a.image_support() != b.image_support()))
  || (aq.max_parameter_size_selected() && (a.max_parameter_size() != b.max_parameter_size()))
  || (aq.max_samplers_selected() && (a.max_samplers() != b.max_samplers()))
  || (aq.mem_base_addr_align_selected() && (a.mem_base_addr_align() != b.mem_base_addr_align()))
  || (aq.min_data_type_align_size_selected() && (a.min_data_type_align_size() != b.min_data_type_align_size()))
  || (aq.single_fp_config_selected() && (a.single_fp_config() != b.single_fp_config()))
  || (aq.global_mem_cache_type_selected() && (a.global_mem_cache_type() != b.global_mem_cache_type()))
  || (aq.global_mem_cacheline_size_selected() && (a.global_mem_cacheline_size() != b.global_mem_cacheline_size()))
  || (aq.global_mem_cache_size_selected() && (a.global_mem_cache_size() != b.global_mem_cache_size()))
  || (aq.global_mem_size_selected() && (a.global_mem_size() != b.global_mem_size()))
  || (aq.max_constant_buffer_size_selected() && (a.max_constant_buffer_size() != b.max_constant_buffer_size()))
  || (aq.max_constant_args_selected() && (a.max_constant_args() != b.max_constant_args()))
  || (aq.local_mem_type_selected() && (a.local_mem_type() != b.local_mem_type()))
  || (aq.local_mem_size_selected() && (a.local_mem_size() != b.local_mem_size()))
  || (aq.error_correction_support_selected() && (a.error_correction_support() != b.error_correction_support()))
  || (aq.profiling_timer_resolution_selected() && (a.profiling_timer_resolution() != b.profiling_timer_resolution()))
  || (aq.endian_little_selected() && (a.endian_little() != b.endian_little()))
  || (aq.available_selected() && (a.available() != b.available()))
  || (aq.compiler_available_selected() && (a.compiler_available() != b.compiler_available()))
  || (aq.execution_capabilities_selected() && (a.execution_capabilities() != b.execution_capabilities()))
  || (aq.queue_properties_selected() && (a.queue_properties() != b.queue_properties()))
  || (aq.name_selected() && (a.name() != b.name()))
  || (aq.vendor_selected() && (a.vendor() != b.vendor()))
  || (aq.driver_version_selected() && (a.driver_version() != b.driver_version()))
  || (aq.profile_selected() && (a.profile() != b.profile()))
  || (aq.version_selected() && (a.version() != b.version()))
  || (aq.extensions_selected() && (a.extensions() != b.extensions()))
  || (aq.platform_id_selected() && (a.platform_id() != b.platform_id()))
  || (aq.double_fp_config_selected() && (a.double_fp_config() != b.double_fp_config()))
  || (aq.preferred_vector_width_half_selected() && (a.preferred_vector_width_half() != b.preferred_vector_width_half()))
  || (aq.host_unified_memory_selected() && (a.host_unified_memory() != b.host_unified_memory()))
  || (aq.native_vector_width_char_selected() && (a.native_vector_width_char() != b.native_vector_width_char()))
  || (aq.native_vector_width_short_selected() && (a.native_vector_width_short() != b.native_vector_width_short()))
  || (aq.native_vector_width_int_selected() && (a.native_vector_width_int() != b.native_vector_width_int()))
  || (aq.native_vector_width_long_selected() && (a.native_vector_width_long() != b.native_vector_width_long()))
  || (aq.native_vector_width_float_selected() && (a.native_vector_width_float() != b.native_vector_width_float()))
  || (aq.native_vector_width_double_selected() && (a.native_vector_width_double() != b.native_vector_width_double()))
  || (aq.native_vector_width_half_selected() && (a.native_vector_width_half() != b.native_vector_width_half()))
  || (aq.opencl_c_version_selected() && (a.opencl_c_version() != b.opencl_c_version()))
  || (aq.linker_available_selected() && (a.linker_available() != b.linker_available()))
  || (aq.built_in_kernels_selected() && (a.built_in_kernels() != b.built_in_kernels()))
  || (aq.image_max_buffer_size_selected() && (a.image_max_buffer_size() != b.image_max_buffer_size()))
  || (aq.image_max_array_size_selected() && (a.image_max_array_size() != b.image_max_array_size()))
  || (aq.parent_device_id_selected() && (a.parent_device_id() != b.parent_device_id()))
  || (aq.partition_max_sub_devices_selected() && (a.partition_max_sub_devices() != b.partition_max_sub_devices()))
  || (aq.partition_properties_selected() && (a.partition_properties() != b.partition_properties()))
  || (aq.partition_affinity_domain_selected() && (a.partition_affinity_domain() != b.partition_affinity_domain()))
  || (aq.partition_type_selected() && (a.partition_type() != b.partition_type()))
  || (aq.reference_count_selected() && (a.reference_count() != b.reference_count()))
  || (aq.preferred_interop_user_sync_selected() && (a.preferred_interop_user_sync() != b.preferred_interop_user_sync()))
  || (aq.printf_buffer_size_selected() && (a.printf_buffer_size() != b.printf_buffer_size()))
  || (aq.image_pitch_alignment_selected() && (a.image_pitch_alignment() != b.image_pitch_alignment()))
  || (aq.image_base_address_alignment_selected() && (a.image_base_address_alignment() != b.image_base_address_alignment())))
    return false;
  return true;
}

} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: