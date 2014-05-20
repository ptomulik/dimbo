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

// dimbo/cl/device_query.cpp

/** // doc: dimbo/cl/device_query.cpp {{{
 * @file dimbo/cl/device_query.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/device_query.hpp>

namespace Dimbo {
namespace Cl {
Device_Query::
Device_Query()
{
  _init_device_query();
}

Device_Query::
~Device_Query()
{
}

Device_Query& Device_Query::
select_all()
{
  this -> select_id(true);
  this -> select_type(true);
  this -> select_vendor_id(true);
  this -> select_max_compute_units(true);
  this -> select_max_work_item_dimensions(true);
  this -> select_max_work_group_size(true);
  this -> select_max_work_item_sizes(true);
  this -> select_preferred_vector_width_char(true);
  this -> select_preferred_vector_width_short(true);
  this -> select_preferred_vector_width_int(true);
  this -> select_preferred_vector_width_long(true);
  this -> select_preferred_vector_width_float(true);
  this -> select_preferred_vector_width_double(true);
  this -> select_max_clock_frequency(true);
  this -> select_address_bits(true);
  this -> select_max_read_image_args(true);
  this -> select_max_write_image_args(true);
  this -> select_max_mem_alloc_size(true);
  this -> select_image2d_max_width(true);
  this -> select_image2d_max_height(true);
  this -> select_image3d_max_width(true);
  this -> select_image3d_max_height(true);
  this -> select_image3d_max_depth(true);
  this -> select_image_support(true);
  this -> select_max_parameter_size(true);
  this -> select_max_samplers(true);
  this -> select_mem_base_addr_align(true);
  this -> select_min_data_type_align_size(true);
  this -> select_single_fp_config(true);
  this -> select_global_mem_cache_type(true);
  this -> select_global_mem_cacheline_size(true);
  this -> select_global_mem_cache_size(true);
  this -> select_global_mem_size(true);
  this -> select_max_constant_buffer_size(true);
  this -> select_max_constant_args(true);
  this -> select_local_mem_type(true);
  this -> select_local_mem_size(true);
  this -> select_error_correction_support(true);
  this -> select_host_unified_memory(true);
  this -> select_profiling_timer_resolution(true);
  this -> select_endian_little(true);
  this -> select_available(true);
  this -> select_compiler_available(true);
  this -> select_execution_capabilities(true);
  this -> select_queue_properties(true);
  this -> select_name(true);
  this -> select_vendor(true);
  this -> select_driver_version(true);
  this -> select_profile(true);
  this -> select_version(true);
  this -> select_extensions(true);
  this -> select_platform_id(true);
  this -> select_double_fp_config(true);
  this -> select_preferred_vector_width_half(true);
  this -> select_native_vector_width_char(true);
  this -> select_native_vector_width_short(true);
  this -> select_native_vector_width_int(true);
  this -> select_native_vector_width_long(true);
  this -> select_native_vector_width_float(true);
  this -> select_native_vector_width_double(true);
  this -> select_native_vector_width_half(true);
  this -> select_opencl_c_version(true);
  this -> select_linker_available(true);
  this -> select_built_in_kernels(true);
  this -> select_image_max_buffer_size(true);
  this -> select_image_max_array_size(true);
  this -> select_parent_device_id(true);
  this -> select_partition_max_sub_devices(true);
  this -> select_partition_properties(true);
  this -> select_partition_affinity_domain(true);
  this -> select_partition_type(true);
  this -> select_reference_count(true);
  this -> select_preferred_interop_user_sync(true);
  this -> select_printf_buffer_size(true);
  this -> select_image_pitch_alignment(true);
  this -> select_image_base_address_alignment(true);
  return *this;
}

Device_Query& Device_Query::
select_none()
{
  this -> select_id(false);
  this -> select_type(false);
  this -> select_vendor_id(false);
  this -> select_max_compute_units(false);
  this -> select_max_work_item_dimensions(false);
  this -> select_max_work_group_size(false);
  this -> select_max_work_item_sizes(false);
  this -> select_preferred_vector_width_char(false);
  this -> select_preferred_vector_width_short(false);
  this -> select_preferred_vector_width_int(false);
  this -> select_preferred_vector_width_long(false);
  this -> select_preferred_vector_width_float(false);
  this -> select_preferred_vector_width_double(false);
  this -> select_max_clock_frequency(false);
  this -> select_address_bits(false);
  this -> select_max_read_image_args(false);
  this -> select_max_write_image_args(false);
  this -> select_max_mem_alloc_size(false);
  this -> select_image2d_max_width(false);
  this -> select_image2d_max_height(false);
  this -> select_image3d_max_width(false);
  this -> select_image3d_max_height(false);
  this -> select_image3d_max_depth(false);
  this -> select_image_support(false);
  this -> select_max_parameter_size(false);
  this -> select_max_samplers(false);
  this -> select_mem_base_addr_align(false);
  this -> select_min_data_type_align_size(false);
  this -> select_single_fp_config(false);
  this -> select_global_mem_cache_type(false);
  this -> select_global_mem_cacheline_size(false);
  this -> select_global_mem_cache_size(false);
  this -> select_global_mem_size(false);
  this -> select_max_constant_buffer_size(false);
  this -> select_max_constant_args(false);
  this -> select_local_mem_type(false);
  this -> select_local_mem_size(false);
  this -> select_error_correction_support(false);
  this -> select_host_unified_memory(false);
  this -> select_profiling_timer_resolution(false);
  this -> select_endian_little(false);
  this -> select_available(false);
  this -> select_compiler_available(false);
  this -> select_execution_capabilities(false);
  this -> select_queue_properties(false);
  this -> select_name(false);
  this -> select_vendor(false);
  this -> select_driver_version(false);
  this -> select_profile(false);
  this -> select_version(false);
  this -> select_extensions(false);
  this -> select_platform_id(false);
  this -> select_double_fp_config(false);
  this -> select_preferred_vector_width_half(false);
  this -> select_native_vector_width_char(false);
  this -> select_native_vector_width_short(false);
  this -> select_native_vector_width_int(false);
  this -> select_native_vector_width_long(false);
  this -> select_native_vector_width_float(false);
  this -> select_native_vector_width_double(false);
  this -> select_native_vector_width_half(false);
  this -> select_opencl_c_version(false);
  this -> select_linker_available(false);
  this -> select_built_in_kernels(false);
  this -> select_image_max_buffer_size(false);
  this -> select_image_max_array_size(false);
  this -> select_parent_device_id(false);
  this -> select_partition_max_sub_devices(false);
  this -> select_partition_properties(false);
  this -> select_partition_affinity_domain(false);
  this -> select_partition_type(false);
  this -> select_reference_count(false);
  this -> select_preferred_interop_user_sync(false);
  this -> select_printf_buffer_size(false);
  this -> select_image_pitch_alignment(false);
  this -> select_image_base_address_alignment(false);
  return *this;
}

Device_Query& Device_Query::
restrict_to(int major, int minor)
{
  if(major == 1 && minor < 1)
    {
      // ver < 1.1
      this->select_preferred_vector_width_half(false);
      this->select_host_unified_memory(false);
      this->select_native_vector_width_char(false);
      this->select_native_vector_width_short(false);
      this->select_native_vector_width_int(false);
      this->select_native_vector_width_long(false);
      this->select_native_vector_width_float(false);
      this->select_native_vector_width_double(false);
      this->select_native_vector_width_half(false);
      this->select_opencl_c_version(false);
    }
  if(major == 1 && minor < 2)
    {
      // ver < 1.2
      this->select_double_fp_config(false);
      this->select_linker_available(false);
      this->select_built_in_kernels(false);
      this->select_image_max_buffer_size(false);
      this->select_image_max_array_size(false);
      this->select_parent_device_id(false);
      this->select_partition_max_sub_devices(false);
      this->select_partition_properties(false);
      this->select_partition_affinity_domain(false);
      this->select_partition_type(false);
      this->select_reference_count(false);
      this->select_preferred_interop_user_sync(false);
      this->select_printf_buffer_size(false);
      this->select_image_pitch_alignment(false);
      this->select_image_base_address_alignment(false);
    }
  return *this;
}

void Device_Query::
_init_device_query()
{
  this -> select_all();
}

bool operator== (Device_Query const& a, Device_Query const& b)
{
  return (a.id_selected() == b.id_selected()
       && a.type_selected() == b.type_selected()
       && a.vendor_id_selected() == b.vendor_id_selected()
       && a.max_compute_units_selected() == b.max_compute_units_selected()
       && a.max_work_item_dimensions_selected() == b.max_work_item_dimensions_selected()
       && a.max_work_group_size_selected() == b.max_work_group_size_selected()
       && a.max_work_item_sizes_selected() == b.max_work_item_sizes_selected()
       && a.preferred_vector_width_char_selected() == b.preferred_vector_width_char_selected()
       && a.preferred_vector_width_short_selected() == b.preferred_vector_width_short_selected()
       && a.preferred_vector_width_int_selected() == b.preferred_vector_width_int_selected()
       && a.preferred_vector_width_long_selected() == b.preferred_vector_width_long_selected()
       && a.preferred_vector_width_float_selected() == b.preferred_vector_width_float_selected()
       && a.preferred_vector_width_double_selected() == b.preferred_vector_width_double_selected()
       && a.max_clock_frequency_selected() == b.max_clock_frequency_selected()
       && a.address_bits_selected() == b.address_bits_selected()
       && a.max_read_image_args_selected() == b.max_read_image_args_selected()
       && a.max_write_image_args_selected() == b.max_write_image_args_selected()
       && a.max_mem_alloc_size_selected() == b.max_mem_alloc_size_selected()
       && a.image2d_max_width_selected() == b.image2d_max_width_selected()
       && a.image2d_max_height_selected() == b.image2d_max_height_selected()
       && a.image3d_max_width_selected() == b.image3d_max_width_selected()
       && a.image3d_max_height_selected() == b.image3d_max_height_selected()
       && a.image3d_max_depth_selected() == b.image3d_max_depth_selected()
       && a.image_support_selected() == b.image_support_selected()
       && a.max_parameter_size_selected() == b.max_parameter_size_selected()
       && a.max_samplers_selected() == b.max_samplers_selected()
       && a.mem_base_addr_align_selected() == b.mem_base_addr_align_selected()
       && a.min_data_type_align_size_selected() == b.min_data_type_align_size_selected()
       && a.single_fp_config_selected() == b.single_fp_config_selected()
       && a.global_mem_cache_type_selected() == b.global_mem_cache_type_selected()
       && a.global_mem_cacheline_size_selected() == b.global_mem_cacheline_size_selected()
       && a.global_mem_cache_size_selected() == b.global_mem_cache_size_selected()
       && a.global_mem_size_selected() == b.global_mem_size_selected()
       && a.max_constant_buffer_size_selected() == b.max_constant_buffer_size_selected()
       && a.max_constant_args_selected() == b.max_constant_args_selected()
       && a.local_mem_type_selected() == b.local_mem_type_selected()
       && a.local_mem_size_selected() == b.local_mem_size_selected()
       && a.error_correction_support_selected() == b.error_correction_support_selected()
       && a.profiling_timer_resolution_selected() == b.profiling_timer_resolution_selected()
       && a.endian_little_selected() == b.endian_little_selected()
       && a.available_selected() == b.available_selected()
       && a.compiler_available_selected() == b.compiler_available_selected()
       && a.execution_capabilities_selected() == b.execution_capabilities_selected()
       && a.queue_properties_selected() == b.queue_properties_selected()
       && a.name_selected() == b.name_selected()
       && a.vendor_selected() == b.vendor_selected()
       && a.driver_version_selected() == b.driver_version_selected()
       && a.profile_selected() == b.profile_selected()
       && a.version_selected() == b.version_selected()
       && a.extensions_selected() == b.extensions_selected()
       && a.platform_id_selected() == b.platform_id_selected()
       && a.double_fp_config_selected() == b.double_fp_config_selected()
       && a.preferred_vector_width_half_selected() == b.preferred_vector_width_half_selected()
       && a.host_unified_memory_selected() == b.host_unified_memory_selected()
       && a.native_vector_width_char_selected() == b.native_vector_width_char_selected()
       && a.native_vector_width_short_selected() == b.native_vector_width_short_selected()
       && a.native_vector_width_int_selected() == b.native_vector_width_int_selected()
       && a.native_vector_width_long_selected() == b.native_vector_width_long_selected()
       && a.native_vector_width_float_selected() == b.native_vector_width_float_selected()
       && a.native_vector_width_double_selected() == b.native_vector_width_double_selected()
       && a.native_vector_width_half_selected() == b.native_vector_width_half_selected()
       && a.opencl_c_version_selected() == b.opencl_c_version_selected()
       && a.linker_available_selected() == b.linker_available_selected()
       && a.built_in_kernels_selected() == b.built_in_kernels_selected()
       && a.image_max_buffer_size_selected() == b.image_max_buffer_size_selected()
       && a.image_max_array_size_selected() == b.image_max_array_size_selected()
       && a.parent_device_id_selected() == b.parent_device_id_selected()
       && a.partition_max_sub_devices_selected() == b.partition_max_sub_devices_selected()
       && a.partition_properties_selected() == b.partition_properties_selected()
       && a.partition_affinity_domain_selected() == b.partition_affinity_domain_selected()
       && a.partition_type_selected() == b.partition_type_selected()
       && a.reference_count_selected() == b.reference_count_selected()
       && a.preferred_interop_user_sync_selected() == b.preferred_interop_user_sync_selected()
       && a.printf_buffer_size_selected() == b.printf_buffer_size_selected()
       && a.image_pitch_alignment_selected() == b.image_pitch_alignment_selected()
       && a.image_base_address_alignment_selected() == b.image_base_address_alignment_selected());
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
