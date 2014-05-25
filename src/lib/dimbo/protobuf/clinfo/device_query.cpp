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

/** // doc: dimbo/protobuf/clinfo/device_query.cpp {{{
 * \file dimbo/protobuf/clinfo/device_query.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/protobuf/clinfo/device_query.hpp>

namespace Dimbo {
namespace Protobuf {

/* ------------------------------------------------------------------------ */
void write(Dimbo::Protobuf::Clinfo::Device_Query& buf,
           Dimbo::Clinfo::Device_Query const& obj)
{
  buf.Clear();
  // Put to buffer only fields that differ from their defaults.
  if(!obj.id_selected()) buf.set_id_selected(false);
  if(!obj.type_selected()) buf.set_type_selected(false);
  if(!obj.vendor_id_selected()) buf.set_vendor_id_selected(false);
  if(!obj.max_compute_units_selected()) buf.set_max_compute_units_selected(false);
  if(!obj.max_work_item_dimensions_selected()) buf.set_max_work_item_dimensions_selected(false);
  if(!obj.max_work_group_size_selected()) buf.set_max_work_group_size_selected(false);
  if(!obj.max_work_item_sizes_selected()) buf.set_max_work_item_sizes_selected(false);
  if(!obj.preferred_vector_width_char_selected()) buf.set_preferred_vector_width_char_selected(false);
  if(!obj.preferred_vector_width_short_selected()) buf.set_preferred_vector_width_short_selected(false);
  if(!obj.preferred_vector_width_int_selected()) buf.set_preferred_vector_width_int_selected(false);
  if(!obj.preferred_vector_width_long_selected()) buf.set_preferred_vector_width_long_selected(false);
  if(!obj.preferred_vector_width_float_selected()) buf.set_preferred_vector_width_float_selected(false);
  if(!obj.preferred_vector_width_double_selected()) buf.set_preferred_vector_width_double_selected(false);
  if(!obj.max_clock_frequency_selected()) buf.set_max_clock_frequency_selected(false);
  if(!obj.address_bits_selected()) buf.set_address_bits_selected(false);
  if(!obj.max_read_image_args_selected()) buf.set_max_read_image_args_selected(false);
  if(!obj.max_write_image_args_selected()) buf.set_max_write_image_args_selected(false);
  if(!obj.max_mem_alloc_size_selected()) buf.set_max_mem_alloc_size_selected(false);
  if(!obj.image2d_max_width_selected()) buf.set_image2d_max_width_selected(false);
  if(!obj.image2d_max_height_selected()) buf.set_image2d_max_height_selected(false);
  if(!obj.image3d_max_width_selected()) buf.set_image3d_max_width_selected(false);
  if(!obj.image3d_max_height_selected()) buf.set_image3d_max_height_selected(false);
  if(!obj.image3d_max_depth_selected()) buf.set_image3d_max_depth_selected(false);
  if(!obj.image_support_selected()) buf.set_image_support_selected(false);
  if(!obj.max_parameter_size_selected()) buf.set_max_parameter_size_selected(false);
  if(!obj.max_samplers_selected()) buf.set_max_samplers_selected(false);
  if(!obj.mem_base_addr_align_selected()) buf.set_mem_base_addr_align_selected(false);
  if(!obj.min_data_type_align_size_selected()) buf.set_min_data_type_align_size_selected(false);
  if(!obj.single_fp_config_selected()) buf.set_single_fp_config_selected(false);
  if(!obj.global_mem_cache_type_selected()) buf.set_global_mem_cache_type_selected(false);
  if(!obj.global_mem_cacheline_size_selected()) buf.set_global_mem_cacheline_size_selected(false);
  if(!obj.global_mem_cache_size_selected()) buf.set_global_mem_cache_size_selected(false);
  if(!obj.global_mem_size_selected()) buf.set_global_mem_size_selected(false);
  if(!obj.max_constant_buffer_size_selected()) buf.set_max_constant_buffer_size_selected(false);
  if(!obj.max_constant_args_selected()) buf.set_max_constant_args_selected(false);
  if(!obj.local_mem_type_selected()) buf.set_local_mem_type_selected(false);
  if(!obj.local_mem_size_selected()) buf.set_local_mem_size_selected(false);
  if(!obj.error_correction_support_selected()) buf.set_error_correction_support_selected(false);
  if(!obj.profiling_timer_resolution_selected()) buf.set_profiling_timer_resolution_selected(false);
  if(!obj.endian_little_selected()) buf.set_endian_little_selected(false);
  if(!obj.available_selected()) buf.set_available_selected(false);
  if(!obj.compiler_available_selected()) buf.set_compiler_available_selected(false);
  if(!obj.execution_capabilities_selected()) buf.set_execution_capabilities_selected(false);
  if(!obj.queue_properties_selected()) buf.set_queue_properties_selected(false);
  if(!obj.name_selected()) buf.set_name_selected(false);
  if(!obj.vendor_selected()) buf.set_vendor_selected(false);
  if(!obj.driver_version_selected()) buf.set_driver_version_selected(false);
  if(!obj.profile_selected()) buf.set_profile_selected(false);
  if(!obj.version_selected()) buf.set_version_selected(false);
  if(!obj.extensions_selected()) buf.set_extensions_selected(false);
  if(!obj.platform_id_selected()) buf.set_platform_id_selected(false);
  if(!obj.double_fp_config_selected()) buf.set_double_fp_config_selected(false);
  if(!obj.preferred_vector_width_half_selected()) buf.set_preferred_vector_width_half_selected(false);
  if(!obj.host_unified_memory_selected()) buf.set_host_unified_memory_selected(false);
  if(!obj.native_vector_width_char_selected()) buf.set_native_vector_width_char_selected(false);
  if(!obj.native_vector_width_short_selected()) buf.set_native_vector_width_short_selected(false);
  if(!obj.native_vector_width_int_selected()) buf.set_native_vector_width_int_selected(false);
  if(!obj.native_vector_width_long_selected()) buf.set_native_vector_width_long_selected(false);
  if(!obj.native_vector_width_float_selected()) buf.set_native_vector_width_float_selected(false);
  if(!obj.native_vector_width_double_selected()) buf.set_native_vector_width_double_selected(false);
  if(!obj.native_vector_width_half_selected()) buf.set_native_vector_width_half_selected(false);
  if(!obj.opencl_c_version_selected()) buf.set_opencl_c_version_selected(false);
  if(!obj.linker_available_selected()) buf.set_linker_available_selected(false);
  if(!obj.built_in_kernels_selected()) buf.set_built_in_kernels_selected(false);
  if(!obj.image_max_buffer_size_selected()) buf.set_image_max_buffer_size_selected(false);
  if(!obj.image_max_array_size_selected()) buf.set_image_max_array_size_selected(false);
  if(!obj.parent_device_id_selected()) buf.set_parent_device_id_selected(false);
  if(!obj.partition_max_sub_devices_selected()) buf.set_partition_max_sub_devices_selected(false);
  if(!obj.partition_properties_selected()) buf.set_partition_properties_selected(false);
  if(!obj.partition_affinity_domain_selected()) buf.set_partition_affinity_domain_selected(false);
  if(!obj.partition_type_selected()) buf.set_partition_type_selected(false);
  if(!obj.reference_count_selected()) buf.set_reference_count_selected(false);
  if(!obj.preferred_interop_user_sync_selected()) buf.set_preferred_interop_user_sync_selected(false);
  if(!obj.printf_buffer_size_selected()) buf.set_printf_buffer_size_selected(false);
  if(!obj.image_pitch_alignment_selected()) buf.set_image_pitch_alignment_selected(false);
  if(!obj.image_base_address_alignment_selected()) buf.set_image_base_address_alignment_selected(false);
}
/* ------------------------------------------------------------------------ */
void read(Dimbo::Protobuf::Clinfo::Device_Query const& buf,
          Dimbo::Clinfo::Device_Query& obj)
{
  obj.select_default();
  if(buf.has_id_selected()) obj.select_id(buf.id_selected());
  if(buf.has_type_selected()) obj.select_type(buf.type_selected());
  if(buf.has_vendor_id_selected()) obj.select_vendor_id(buf.vendor_id_selected());
  if(buf.has_max_compute_units_selected()) obj.select_max_compute_units(buf.max_compute_units_selected());
  if(buf.has_max_work_item_dimensions_selected()) obj.select_max_work_item_dimensions(buf.max_work_item_dimensions_selected());
  if(buf.has_max_work_group_size_selected()) obj.select_max_work_group_size(buf.max_work_group_size_selected());
  if(buf.has_max_work_item_sizes_selected()) obj.select_max_work_item_sizes(buf.max_work_item_sizes_selected());
  if(buf.has_preferred_vector_width_char_selected()) obj.select_preferred_vector_width_char(buf.preferred_vector_width_char_selected());
  if(buf.has_preferred_vector_width_short_selected()) obj.select_preferred_vector_width_short(buf.preferred_vector_width_short_selected());
  if(buf.has_preferred_vector_width_int_selected()) obj.select_preferred_vector_width_int(buf.preferred_vector_width_int_selected());
  if(buf.has_preferred_vector_width_long_selected()) obj.select_preferred_vector_width_long(buf.preferred_vector_width_long_selected());
  if(buf.has_preferred_vector_width_float_selected()) obj.select_preferred_vector_width_float(buf.preferred_vector_width_float_selected());
  if(buf.has_preferred_vector_width_double_selected()) obj.select_preferred_vector_width_double(buf.preferred_vector_width_double_selected());
  if(buf.has_max_clock_frequency_selected()) obj.select_max_clock_frequency(buf.max_clock_frequency_selected());
  if(buf.has_address_bits_selected()) obj.select_address_bits(buf.address_bits_selected());
  if(buf.has_max_read_image_args_selected()) obj.select_max_read_image_args(buf.max_read_image_args_selected());
  if(buf.has_max_write_image_args_selected()) obj.select_max_write_image_args(buf.max_write_image_args_selected());
  if(buf.has_max_mem_alloc_size_selected()) obj.select_max_mem_alloc_size(buf.max_mem_alloc_size_selected());
  if(buf.has_image2d_max_width_selected()) obj.select_image2d_max_width(buf.image2d_max_width_selected());
  if(buf.has_image2d_max_height_selected()) obj.select_image2d_max_height(buf.image2d_max_height_selected());
  if(buf.has_image3d_max_width_selected()) obj.select_image3d_max_width(buf.image3d_max_width_selected());
  if(buf.has_image3d_max_height_selected()) obj.select_image3d_max_height(buf.image3d_max_height_selected());
  if(buf.has_image3d_max_depth_selected()) obj.select_image3d_max_depth(buf.image3d_max_depth_selected());
  if(buf.has_image_support_selected()) obj.select_image_support(buf.image_support_selected());
  if(buf.has_max_parameter_size_selected()) obj.select_max_parameter_size(buf.max_parameter_size_selected());
  if(buf.has_max_samplers_selected()) obj.select_max_samplers(buf.max_samplers_selected());
  if(buf.has_mem_base_addr_align_selected()) obj.select_mem_base_addr_align(buf.mem_base_addr_align_selected());
  if(buf.has_min_data_type_align_size_selected()) obj.select_min_data_type_align_size(buf.min_data_type_align_size_selected());
  if(buf.has_single_fp_config_selected()) obj.select_single_fp_config(buf.single_fp_config_selected());
  if(buf.has_global_mem_cache_type_selected()) obj.select_global_mem_cache_type(buf.global_mem_cache_type_selected());
  if(buf.has_global_mem_cacheline_size_selected()) obj.select_global_mem_cacheline_size(buf.global_mem_cacheline_size_selected());
  if(buf.has_global_mem_cache_size_selected()) obj.select_global_mem_cache_size(buf.global_mem_cache_size_selected());
  if(buf.has_global_mem_size_selected()) obj.select_global_mem_size(buf.global_mem_size_selected());
  if(buf.has_max_constant_buffer_size_selected()) obj.select_max_constant_buffer_size(buf.max_constant_buffer_size_selected());
  if(buf.has_max_constant_args_selected()) obj.select_max_constant_args(buf.max_constant_args_selected());
  if(buf.has_local_mem_type_selected()) obj.select_local_mem_type(buf.local_mem_type_selected());
  if(buf.has_local_mem_size_selected()) obj.select_local_mem_size(buf.local_mem_size_selected());
  if(buf.has_error_correction_support_selected()) obj.select_error_correction_support(buf.error_correction_support_selected());
  if(buf.has_profiling_timer_resolution_selected()) obj.select_profiling_timer_resolution(buf.profiling_timer_resolution_selected());
  if(buf.has_endian_little_selected()) obj.select_endian_little(buf.endian_little_selected());
  if(buf.has_available_selected()) obj.select_available(buf.available_selected());
  if(buf.has_compiler_available_selected()) obj.select_compiler_available(buf.compiler_available_selected());
  if(buf.has_execution_capabilities_selected()) obj.select_execution_capabilities(buf.execution_capabilities_selected());
  if(buf.has_queue_properties_selected()) obj.select_queue_properties(buf.queue_properties_selected());
  if(buf.has_name_selected()) obj.select_name(buf.name_selected());
  if(buf.has_vendor_selected()) obj.select_vendor(buf.vendor_selected());
  if(buf.has_driver_version_selected()) obj.select_driver_version(buf.driver_version_selected());
  if(buf.has_profile_selected()) obj.select_profile(buf.profile_selected());
  if(buf.has_version_selected()) obj.select_version(buf.version_selected());
  if(buf.has_extensions_selected()) obj.select_extensions(buf.extensions_selected());
  if(buf.has_platform_id_selected()) obj.select_platform_id(buf.platform_id_selected());
  if(buf.has_double_fp_config_selected()) obj.select_double_fp_config(buf.double_fp_config_selected());
  if(buf.has_preferred_vector_width_half_selected()) obj.select_preferred_vector_width_half(buf.preferred_vector_width_half_selected());
  if(buf.has_host_unified_memory_selected()) obj.select_host_unified_memory(buf.host_unified_memory_selected());
  if(buf.has_native_vector_width_char_selected()) obj.select_native_vector_width_char(buf.native_vector_width_char_selected());
  if(buf.has_native_vector_width_short_selected()) obj.select_native_vector_width_short(buf.native_vector_width_short_selected());
  if(buf.has_native_vector_width_int_selected()) obj.select_native_vector_width_int(buf.native_vector_width_int_selected());
  if(buf.has_native_vector_width_long_selected()) obj.select_native_vector_width_long(buf.native_vector_width_long_selected());
  if(buf.has_native_vector_width_float_selected()) obj.select_native_vector_width_float(buf.native_vector_width_float_selected());
  if(buf.has_native_vector_width_double_selected()) obj.select_native_vector_width_double(buf.native_vector_width_double_selected());
  if(buf.has_native_vector_width_half_selected()) obj.select_native_vector_width_half(buf.native_vector_width_half_selected());
  if(buf.has_opencl_c_version_selected()) obj.select_opencl_c_version(buf.opencl_c_version_selected());
  if(buf.has_linker_available_selected()) obj.select_linker_available(buf.linker_available_selected());
  if(buf.has_built_in_kernels_selected()) obj.select_built_in_kernels(buf.built_in_kernels_selected());
  if(buf.has_image_max_buffer_size_selected()) obj.select_image_max_buffer_size(buf.image_max_buffer_size_selected());
  if(buf.has_image_max_array_size_selected()) obj.select_image_max_array_size(buf.image_max_array_size_selected());
  if(buf.has_parent_device_id_selected()) obj.select_parent_device_id(buf.parent_device_id_selected());
  if(buf.has_partition_max_sub_devices_selected()) obj.select_partition_max_sub_devices(buf.partition_max_sub_devices_selected());
  if(buf.has_partition_properties_selected()) obj.select_partition_properties(buf.partition_properties_selected());
  if(buf.has_partition_affinity_domain_selected()) obj.select_partition_affinity_domain(buf.partition_affinity_domain_selected());
  if(buf.has_partition_type_selected()) obj.select_partition_type(buf.partition_type_selected());
  if(buf.has_reference_count_selected()) obj.select_reference_count(buf.reference_count_selected());
  if(buf.has_preferred_interop_user_sync_selected()) obj.select_preferred_interop_user_sync(buf.preferred_interop_user_sync_selected());
  if(buf.has_printf_buffer_size_selected()) obj.select_printf_buffer_size(buf.printf_buffer_size_selected());
  if(buf.has_image_pitch_alignment_selected()) obj.select_image_pitch_alignment(buf.image_pitch_alignment_selected());
  if(buf.has_image_base_address_alignment_selected()) obj.select_image_base_address_alignment(buf.image_base_address_alignment_selected());
}
/* ------------------------------------------------------------------------ */

} /* namesapce Protobuf */
} /* namespace Dimbo */

/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Device_Query&
operator<<(Dimbo::Protobuf::Clinfo::Device_Query& buf,
           Dimbo::Clinfo::Device_Query const& obj)
{
  Dimbo::Protobuf::write(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Device_Query const&
operator>>(Dimbo::Protobuf::Clinfo::Device_Query const& buf,
           Dimbo::Clinfo::Device_Query& obj)
{
  Dimbo::Protobuf::read(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
