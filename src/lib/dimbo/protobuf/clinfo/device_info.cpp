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

/** // doc: dimbo/protobuf/clinfo/device_info.cpp {{{
 * \file dimbo/protobuf/clinfo/device_info.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/protobuf/clinfo/device_info.hpp>

namespace Dimbo {
namespace Protobuf {

/* ------------------------------------------------------------------------ */
void write(Dimbo::Protobuf::Clinfo::Device_Info& buf,
           Dimbo::Clinfo::Device_Info const& obj)
{
  buf.Clear();
  if(obj.has_id())
    buf.set_id(obj.id());
  if(obj.has_type())
    buf.set_type(obj.type());
  if(obj.has_vendor_id())
    buf.set_vendor_id(obj.vendor_id());
  if(obj.has_max_compute_units())
    buf.set_max_compute_units(obj.max_compute_units());
  if(obj.has_max_work_item_dimensions())
    buf.set_max_work_item_dimensions(obj.max_work_item_dimensions());
  if(obj.has_max_work_group_size())
    buf.set_max_work_group_size(obj.max_work_group_size());
  if(obj.has_max_work_item_sizes())
    for(size_t i=0; i < obj.max_work_item_sizes().size(); ++i)
      buf.add_max_work_item_sizes(obj.max_work_item_sizes()[i]);
  if(obj.has_preferred_vector_width_char())
    buf.set_preferred_vector_width_char(obj.preferred_vector_width_char());
  if(obj.has_preferred_vector_width_short())
    buf.set_preferred_vector_width_short(obj.preferred_vector_width_short());
  if(obj.has_preferred_vector_width_int())
    buf.set_preferred_vector_width_int(obj.preferred_vector_width_int());
  if(obj.has_preferred_vector_width_long())
    buf.set_preferred_vector_width_long(obj.preferred_vector_width_long());
  if(obj.has_preferred_vector_width_float())
    buf.set_preferred_vector_width_float(obj.preferred_vector_width_float());
  if(obj.has_preferred_vector_width_double())
    buf.set_preferred_vector_width_double(obj.preferred_vector_width_double());
  if(obj.has_max_clock_frequency())
    buf.set_max_clock_frequency(obj.max_clock_frequency());
  if(obj.has_address_bits())
    buf.set_address_bits(obj.address_bits());
  if(obj.has_max_read_image_args())
    buf.set_max_read_image_args(obj.max_read_image_args());
  if(obj.has_max_write_image_args())
    buf.set_max_write_image_args(obj.max_write_image_args());
  if(obj.has_max_mem_alloc_size())
    buf.set_max_mem_alloc_size(obj.max_mem_alloc_size());
  if(obj.has_image2d_max_width())
    buf.set_image2d_max_width(obj.image2d_max_width());
  if(obj.has_image2d_max_height())
    buf.set_image2d_max_height(obj.image2d_max_height());
  if(obj.has_image3d_max_width())
    buf.set_image3d_max_width(obj.image3d_max_width());
  if(obj.has_image3d_max_height())
    buf.set_image3d_max_height(obj.image3d_max_height());
  if(obj.has_image3d_max_depth())
    buf.set_image3d_max_depth(obj.image3d_max_depth());
  if(obj.has_image_support())
    buf.set_image_support(obj.image_support());
  if(obj.has_max_parameter_size())
    buf.set_max_parameter_size(obj.max_parameter_size());
  if(obj.has_max_samplers())
    buf.set_max_samplers(obj.max_samplers());
  if(obj.has_mem_base_addr_align())
    buf.set_mem_base_addr_align(obj.mem_base_addr_align());
  if(obj.has_min_data_type_align_size())
    buf.set_min_data_type_align_size(obj.min_data_type_align_size());
  if(obj.has_single_fp_config())
    buf.set_single_fp_config(obj.single_fp_config());
  if(obj.has_global_mem_cache_type())
    buf.set_global_mem_cache_type(obj.global_mem_cache_type());
  if(obj.has_global_mem_cacheline_size())
    buf.set_global_mem_cacheline_size(obj.global_mem_cacheline_size());
  if(obj.has_global_mem_cache_size())
    buf.set_global_mem_cache_size(obj.global_mem_cache_size());
  if(obj.has_global_mem_size())
    buf.set_global_mem_size(obj.global_mem_size());
  if(obj.has_max_constant_buffer_size())
    buf.set_max_constant_buffer_size(obj.max_constant_buffer_size());
  if(obj.has_max_constant_args())
    buf.set_max_constant_args(obj.max_constant_args());
  if(obj.has_local_mem_type())
    buf.set_local_mem_type(obj.local_mem_type());
  if(obj.has_local_mem_size())
    buf.set_local_mem_size(obj.local_mem_size());
  if(obj.has_error_correction_support())
    buf.set_error_correction_support(obj.error_correction_support());
  if(obj.has_profiling_timer_resolution())
    buf.set_profiling_timer_resolution(obj.profiling_timer_resolution());
  if(obj.has_endian_little())
    buf.set_endian_little(obj.endian_little());
  if(obj.has_available())
    buf.set_available(obj.available());
  if(obj.has_compiler_available())
    buf.set_compiler_available(obj.compiler_available());
  if(obj.has_execution_capabilities())
    buf.set_execution_capabilities(obj.execution_capabilities());
  if(obj.has_queue_properties())
    buf.set_queue_properties(obj.queue_properties());
  if(obj.has_name())
    buf.set_name(obj.name());
  if(obj.has_vendor())
    buf.set_vendor(obj.vendor());
  if(obj.has_driver_version())
    buf.set_driver_version(obj.driver_version());
  if(obj.has_profile())
    buf.set_profile(obj.profile());
  if(obj.has_version())
    buf.set_version(obj.version());
  if(obj.has_extensions())
    buf.set_extensions(obj.extensions());
  if(obj.has_platform_id())
    buf.set_platform_id(obj.platform_id());
  if(obj.has_double_fp_config())
    buf.set_double_fp_config(obj.double_fp_config());
  if(obj.has_preferred_vector_width_half())
    buf.set_preferred_vector_width_half(obj.preferred_vector_width_half());
  if(obj.has_host_unified_memory())
    buf.set_host_unified_memory(obj.host_unified_memory());
  if(obj.has_native_vector_width_char())
    buf.set_native_vector_width_char(obj.native_vector_width_char());
  if(obj.has_native_vector_width_short())
    buf.set_native_vector_width_short(obj.native_vector_width_short());
  if(obj.has_native_vector_width_int())
    buf.set_native_vector_width_int(obj.native_vector_width_int());
  if(obj.has_native_vector_width_long())
    buf.set_native_vector_width_long(obj.native_vector_width_long());
  if(obj.has_native_vector_width_float())
    buf.set_native_vector_width_float(obj.native_vector_width_float());
  if(obj.has_native_vector_width_double())
    buf.set_native_vector_width_double(obj.native_vector_width_double());
  if(obj.has_native_vector_width_half())
    buf.set_native_vector_width_half(obj.native_vector_width_half());
  if(obj.has_opencl_c_version())
    buf.set_opencl_c_version(obj.opencl_c_version());
  if(obj.has_linker_available())
    buf.set_linker_available(obj.linker_available());
  if(obj.has_built_in_kernels())
    buf.set_built_in_kernels(obj.built_in_kernels());
  if(obj.has_image_max_buffer_size())
    buf.set_image_max_buffer_size(obj.image_max_buffer_size());
  if(obj.has_image_max_array_size())
    buf.set_image_max_array_size(obj.image_max_array_size());
  if(obj.has_parent_device_id())
    buf.set_parent_device_id(obj.parent_device_id());
  if(obj.has_partition_max_sub_devices())
    buf.set_partition_max_sub_devices(obj.partition_max_sub_devices());
  if(obj.has_partition_properties())
    for(size_t i=0; i < obj.partition_properties().size(); ++i)
      buf.add_partition_properties(obj.partition_properties()[i]);
  if(obj.has_partition_affinity_domain())
    buf.set_partition_affinity_domain(obj.partition_affinity_domain());
  if(obj.has_partition_type())
    for(size_t i=0; i < obj.partition_type().size(); ++i)
      buf.add_partition_type(obj.partition_type()[i]);
  if(obj.has_reference_count())
    buf.set_reference_count(obj.reference_count());
  if(obj.has_preferred_interop_user_sync())
    buf.set_preferred_interop_user_sync(obj.preferred_interop_user_sync());
  if(obj.has_printf_buffer_size())
    buf.set_printf_buffer_size(obj.printf_buffer_size());
  if(obj.has_image_pitch_alignment())
    buf.set_image_pitch_alignment(obj.image_pitch_alignment());
  if(obj.has_image_base_address_alignment())
    buf.set_image_base_address_alignment(obj.image_base_address_alignment());
}
/* ------------------------------------------------------------------------ */
void read(Dimbo::Protobuf::Clinfo::Device_Info const& buf,
          Dimbo::Clinfo::Device_Info& obj)
{
  obj.clear();
  if(buf.has_id())
    obj.set_id(buf.id());
  if(buf.has_type())
    obj.set_type(buf.type());
  if(buf.has_vendor_id())
    obj.set_vendor_id(buf.vendor_id());
  if(buf.has_max_compute_units())
    obj.set_max_compute_units(buf.max_compute_units());
  if(buf.has_max_work_item_dimensions())
    obj.set_max_work_item_dimensions(buf.max_work_item_dimensions());
  if(buf.has_max_work_group_size())
    obj.set_max_work_group_size(buf.max_work_group_size());
  if(buf.max_work_item_sizes_size() > 0)
    obj.set_max_work_item_sizes(std::vector<size_t>(buf.max_work_item_sizes().begin(),buf.max_work_item_sizes().end()));
  if(buf.has_preferred_vector_width_char())
    obj.set_preferred_vector_width_char(buf.preferred_vector_width_char());
  if(buf.has_preferred_vector_width_short())
    obj.set_preferred_vector_width_short(buf.preferred_vector_width_short());
  if(buf.has_preferred_vector_width_int())
    obj.set_preferred_vector_width_int(buf.preferred_vector_width_int());
  if(buf.has_preferred_vector_width_long())
    obj.set_preferred_vector_width_long(buf.preferred_vector_width_long());
  if(buf.has_preferred_vector_width_float())
    obj.set_preferred_vector_width_float(buf.preferred_vector_width_float());
  if(buf.has_preferred_vector_width_double())
    obj.set_preferred_vector_width_double(buf.preferred_vector_width_double());
  if(buf.has_max_clock_frequency())
    obj.set_max_clock_frequency(buf.max_clock_frequency());
  if(buf.has_address_bits())
    obj.set_address_bits(buf.address_bits());
  if(buf.has_max_read_image_args())
    obj.set_max_read_image_args(buf.max_read_image_args());
  if(buf.has_max_write_image_args())
    obj.set_max_write_image_args(buf.max_write_image_args());
  if(buf.has_max_mem_alloc_size())
    obj.set_max_mem_alloc_size(buf.max_mem_alloc_size());
  if(buf.has_image2d_max_width())
    obj.set_image2d_max_width(buf.image2d_max_width());
  if(buf.has_image2d_max_height())
    obj.set_image2d_max_height(buf.image2d_max_height());
  if(buf.has_image3d_max_width())
    obj.set_image3d_max_width(buf.image3d_max_width());
  if(buf.has_image3d_max_height())
    obj.set_image3d_max_height(buf.image3d_max_height());
  if(buf.has_image3d_max_depth())
    obj.set_image3d_max_depth(buf.image3d_max_depth());
  if(buf.has_image_support())
    obj.set_image_support(buf.image_support());
  if(buf.has_max_parameter_size())
    obj.set_max_parameter_size(buf.max_parameter_size());
  if(buf.has_max_samplers())
    obj.set_max_samplers(buf.max_samplers());
  if(buf.has_mem_base_addr_align())
    obj.set_mem_base_addr_align(buf.mem_base_addr_align());
  if(buf.has_min_data_type_align_size())
    obj.set_min_data_type_align_size(buf.min_data_type_align_size());
  if(buf.has_single_fp_config())
    obj.set_single_fp_config(buf.single_fp_config());
  if(buf.has_global_mem_cache_type())
    obj.set_global_mem_cache_type(buf.global_mem_cache_type());
  if(buf.has_global_mem_cacheline_size())
    obj.set_global_mem_cacheline_size(buf.global_mem_cacheline_size());
  if(buf.has_global_mem_cache_size())
    obj.set_global_mem_cache_size(buf.global_mem_cache_size());
  if(buf.has_global_mem_size())
    obj.set_global_mem_size(buf.global_mem_size());
  if(buf.has_max_constant_buffer_size())
    obj.set_max_constant_buffer_size(buf.max_constant_buffer_size());
  if(buf.has_max_constant_args())
    obj.set_max_constant_args(buf.max_constant_args());
  if(buf.has_local_mem_type())
    obj.set_local_mem_type(buf.local_mem_type());
  if(buf.has_local_mem_size())
    obj.set_local_mem_size(buf.local_mem_size());
  if(buf.has_error_correction_support())
    obj.set_error_correction_support(buf.error_correction_support());
  if(buf.has_profiling_timer_resolution())
    obj.set_profiling_timer_resolution(buf.profiling_timer_resolution());
  if(buf.has_endian_little())
    obj.set_endian_little(buf.endian_little());
  if(buf.has_available())
    obj.set_available(buf.available());
  if(buf.has_compiler_available())
    obj.set_compiler_available(buf.compiler_available());
  if(buf.has_execution_capabilities())
    obj.set_execution_capabilities(buf.execution_capabilities());
  if(buf.has_queue_properties())
    obj.set_queue_properties(buf.queue_properties());
  if(buf.has_name())
    obj.set_name(buf.name());
  if(buf.has_vendor())
    obj.set_vendor(buf.vendor());
  if(buf.has_driver_version())
    obj.set_driver_version(buf.driver_version());
  if(buf.has_profile())
    obj.set_profile(buf.profile());
  if(buf.has_version())
    obj.set_version(buf.version());
  if(buf.has_extensions())
    obj.set_extensions(buf.extensions());
  if(buf.has_platform_id())
    obj.set_platform_id(buf.platform_id());
  if(buf.has_double_fp_config())
    obj.set_double_fp_config(buf.double_fp_config());
  if(buf.has_preferred_vector_width_half())
    obj.set_preferred_vector_width_half(buf.preferred_vector_width_half());
  if(buf.has_host_unified_memory())
    obj.set_host_unified_memory(buf.host_unified_memory());
  if(buf.has_native_vector_width_char())
    obj.set_native_vector_width_char(buf.native_vector_width_char());
  if(buf.has_native_vector_width_short())
    obj.set_native_vector_width_short(buf.native_vector_width_short());
  if(buf.has_native_vector_width_int())
    obj.set_native_vector_width_int(buf.native_vector_width_int());
  if(buf.has_native_vector_width_long())
    obj.set_native_vector_width_long(buf.native_vector_width_long());
  if(buf.has_native_vector_width_float())
    obj.set_native_vector_width_float(buf.native_vector_width_float());
  if(buf.has_native_vector_width_double())
    obj.set_native_vector_width_double(buf.native_vector_width_double());
  if(buf.has_native_vector_width_half())
    obj.set_native_vector_width_half(buf.native_vector_width_half());
  if(buf.has_opencl_c_version())
    obj.set_opencl_c_version(buf.opencl_c_version());
  if(buf.has_linker_available())
    obj.set_linker_available(buf.linker_available());
  if(buf.has_built_in_kernels())
    obj.set_built_in_kernels(buf.built_in_kernels());
  if(buf.has_image_max_buffer_size())
    obj.set_image_max_buffer_size(buf.image_max_buffer_size());
  if(buf.has_image_max_array_size())
    obj.set_image_max_array_size(buf.image_max_array_size());
  if(buf.has_parent_device_id())
    obj.set_parent_device_id(buf.parent_device_id());
  if(buf.has_partition_max_sub_devices())
    obj.set_partition_max_sub_devices(buf.partition_max_sub_devices());
  if(buf.partition_properties_size() > 0)
    obj.set_partition_properties(std::vector<cl_device_partition_property>(buf.partition_properties().begin(),buf.partition_properties().end()));
  if(buf.has_partition_affinity_domain())
    obj.set_partition_affinity_domain(buf.partition_affinity_domain());
  if(buf.partition_type_size() > 0)
    obj.set_partition_type(std::vector<cl_device_partition_property>(buf.partition_type().begin(),buf.partition_type().end()));
  if(buf.has_reference_count())
    obj.set_reference_count(buf.reference_count());
  if(buf.has_preferred_interop_user_sync())
    obj.set_preferred_interop_user_sync(buf.preferred_interop_user_sync());
  if(buf.has_printf_buffer_size())
    obj.set_printf_buffer_size(buf.printf_buffer_size());
  if(buf.has_image_pitch_alignment())
    obj.set_image_pitch_alignment(buf.image_pitch_alignment());
  if(buf.has_image_base_address_alignment())
    obj.set_image_base_address_alignment(buf.image_base_address_alignment());
}
/* ------------------------------------------------------------------------ */

} /* namesapce Protobuf */
} /* namespace Dimbo */

/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Device_Info&
operator<<(Dimbo::Protobuf::Clinfo::Device_Info& buf,
           Dimbo::Clinfo::Device_Info const& obj)
{
  Dimbo::Protobuf::write(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
Dimbo::Protobuf::Clinfo::Device_Info const&
operator>>(Dimbo::Protobuf::Clinfo::Device_Info const& buf,
           Dimbo::Clinfo::Device_Info& obj)
{
  Dimbo::Protobuf::read(buf,obj);
  return buf;
}
/* ------------------------------------------------------------------------ */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
