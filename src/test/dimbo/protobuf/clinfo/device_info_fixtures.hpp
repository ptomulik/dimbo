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

// /dimbo/protobuf/clinfo/device_info_fixtures.hpp

/** // doc: /dimbo/protobuf/clinfo/device_info_fixtures.hpp {{{
 * \file /dimbo/protobuf/clinfo/device_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_DEVICE_INFO_FIXTURES_HPP_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_DEVICE_INFO_FIXTURES_HPP_INCLUDED

#include <dimbo/protobuf/clinfo/device_info.hpp>

namespace Dimbo {
namespace Protobuf {
namespace Clinfo {

struct Device_Info_Fixtures
  {
    // This corresponds to Dimbo::Clinfo::Device_Info_Fixtures::_1()
    // see "dimbo/clinfo/device_info_fixtures.hpp" under "src/test".
    static Device_Info _1()
    {
      size_t max_work_item_sizes[3] = { 1, 2, 3 };
      cl_device_partition_property partition_properties[2] = { 1, 2 };
      cl_device_partition_property partition_type[2] = { 1, 2 };

      Device_Info buf;
      buf.set_id(0x1234ul);
      buf.set_type(0x1234ul);
      buf.set_vendor_id(0x1234u);
      buf.set_max_compute_units(0x1234u);
      buf.set_max_work_item_dimensions(0x1234u);
      buf.set_max_work_group_size(0x1234ul);
      for(int i=0;i<3;++i) buf.add_max_work_item_sizes(max_work_item_sizes[i]);
      buf.set_preferred_vector_width_char(0x1234u);
      buf.set_preferred_vector_width_short(0x1234u);
      buf.set_preferred_vector_width_int(0x1234u);
      buf.set_preferred_vector_width_long(0x1234u);
      buf.set_preferred_vector_width_float(0x1234u);
      buf.set_preferred_vector_width_double(0x1234u);
      buf.set_max_clock_frequency(0x1234u);
      buf.set_address_bits(0x1234u);
      buf.set_max_read_image_args(0x1234u);
      buf.set_max_write_image_args(0x1234u);
      buf.set_max_mem_alloc_size(0x1234ul);
      buf.set_image2d_max_width(0x1234ul);
      buf.set_image2d_max_height(0x1234ul);
      buf.set_image3d_max_width(0x1234ul);
      buf.set_image3d_max_height(0x1234ul);
      buf.set_image3d_max_depth(0x1234ul);
      buf.set_image_support(0);
      buf.set_max_parameter_size(0x1234ul);
      buf.set_max_samplers(0x1234u);
      buf.set_mem_base_addr_align(0x1234u);
      buf.set_min_data_type_align_size(0x1234u);
      buf.set_single_fp_config(0x1234);
      buf.set_global_mem_cache_type(0x1234);
      buf.set_global_mem_cacheline_size(0x1234u);
      buf.set_global_mem_cache_size(0x1234ul);
      buf.set_global_mem_size(0x1234ul);
      buf.set_max_constant_buffer_size(0x1234u);
      buf.set_max_constant_args(0x1234u);
      buf.set_local_mem_type(0x1234);
      buf.set_local_mem_size(0x1234ul);
      buf.set_error_correction_support(0);
      buf.set_profiling_timer_resolution(0x1234ul);
      buf.set_endian_little(0);
      buf.set_available(0);
      buf.set_compiler_available(0);
      buf.set_execution_capabilities(0x1234);
      buf.set_queue_properties(0x1234);
      buf.set_name("_name");
      buf.set_vendor("_vendor");
      buf.set_driver_version("_driver_version");
      buf.set_profile("_profile");
      buf.set_version("_version");
      buf.set_extensions("_extensions");
      buf.set_platform_id(0x1234ul);
      buf.set_double_fp_config(0x1234);
      buf.set_preferred_vector_width_half(0x1234u);
      buf.set_host_unified_memory(0);
      buf.set_native_vector_width_char(0x1234u);
      buf.set_native_vector_width_short(0x1234u);
      buf.set_native_vector_width_int(0x1234u);
      buf.set_native_vector_width_long(0x1234u);
      buf.set_native_vector_width_float(0x1234u);
      buf.set_native_vector_width_double(0x1234u);
      buf.set_native_vector_width_half(0x1234u);
      buf.set_opencl_c_version("_opencl_c_version");
      buf.set_linker_available(0);
      buf.set_built_in_kernels("_built_in_kernels");
      buf.set_image_max_buffer_size(0x1234ul);
      buf.set_image_max_array_size(0x1234ul);
      buf.set_parent_device_id(0x1234ul);
      buf.set_partition_max_sub_devices(0x1234u);
      for(int i=0; i<2; ++i) buf.add_partition_properties(partition_properties[i]);
      buf.set_partition_affinity_domain(0x1234);
      for(int i=0; i<2; ++i) buf.add_partition_type(partition_type[i]);
      buf.set_reference_count(0x1234u);
      buf.set_preferred_interop_user_sync(0);
      buf.set_printf_buffer_size(0x1234ul);
      buf.set_image_pitch_alignment(0x1234u);
      buf.set_image_base_address_alignment(0x1234u);
      return buf;
    }
    // This corresponds to Dimbo::Clinfo::Device_Info_Fixtures::_2()
    // see "dimbo/clinfo/device_info_fixtures.hpp" under "src/test".
    static Device_Info _2()
    {
      size_t max_work_item_sizes[3] = { 3, 2, 1 };
      cl_device_partition_property partition_properties[2] = { 2, 1 };
      cl_device_partition_property partition_type[2] = { 2, 1 };

      Device_Info buf;
      buf.set_id(0x4321ul);
      buf.set_type(0x4321ul);
      buf.set_vendor_id(0x4321u);
      buf.set_max_compute_units(0x4321u);
      buf.set_max_work_item_dimensions(0x4321u);
      buf.set_max_work_group_size(0x4321ul);
      for(int i=0; i<3; ++i) buf.add_max_work_item_sizes(max_work_item_sizes[i]);
      buf.set_preferred_vector_width_char(0x4321u);
      buf.set_preferred_vector_width_short(0x4321u);
      buf.set_preferred_vector_width_int(0x4321u);
      buf.set_preferred_vector_width_long(0x4321u);
      buf.set_preferred_vector_width_float(0x4321u);
      buf.set_preferred_vector_width_double(0x4321u);
      buf.set_max_clock_frequency(0x4321u);
      buf.set_address_bits(0x4321u);
      buf.set_max_read_image_args(0x4321u);
      buf.set_max_write_image_args(0x4321u);
      buf.set_max_mem_alloc_size(0x4321ul);
      buf.set_image2d_max_width(0x4321ul);
      buf.set_image2d_max_height(0x4321ul);
      buf.set_image3d_max_width(0x4321ul);
      buf.set_image3d_max_height(0x4321ul);
      buf.set_image3d_max_depth(0x4321ul);
      buf.set_image_support(1);
      buf.set_max_parameter_size(0x4321ul);
      buf.set_max_samplers(0x4321u);
      buf.set_mem_base_addr_align(0x4321u);
      buf.set_min_data_type_align_size(0x4321u);
      buf.set_single_fp_config(0x4321);
      buf.set_global_mem_cache_type(0x4321);
      buf.set_global_mem_cacheline_size(0x4321u);
      buf.set_global_mem_cache_size(0x4321ul);
      buf.set_global_mem_size(0x4321ul);
      buf.set_max_constant_buffer_size(0x4321u);
      buf.set_max_constant_args(0x4321u);
      buf.set_local_mem_type(0x4321);
      buf.set_local_mem_size(0x4321ul);
      buf.set_error_correction_support(1);
      buf.set_profiling_timer_resolution(0x4321ul);
      buf.set_endian_little(1);
      buf.set_available(1);
      buf.set_compiler_available(1);
      buf.set_execution_capabilities(0x4321);
      buf.set_queue_properties(0x4321);
      buf.set_name("x_namex");
      buf.set_vendor("x_vendorx");
      buf.set_driver_version("x_driver_versionx");
      buf.set_profile("x_profilex");
      buf.set_version("x_versionx");
      buf.set_extensions("x_extensionsx");
      buf.set_platform_id(0x4321ul);
      buf.set_double_fp_config(0x4321);
      buf.set_preferred_vector_width_half(0x4321u);
      buf.set_host_unified_memory(1);
      buf.set_native_vector_width_char(0x4321u);
      buf.set_native_vector_width_short(0x4321u);
      buf.set_native_vector_width_int(0x4321u);
      buf.set_native_vector_width_long(0x4321u);
      buf.set_native_vector_width_float(0x4321u);
      buf.set_native_vector_width_double(0x4321u);
      buf.set_native_vector_width_half(0x4321u);
      buf.set_opencl_c_version("x_opencl_c_versionx");
      buf.set_linker_available(1);
      buf.set_built_in_kernels("x_built_in_kernelsx");
      buf.set_image_max_buffer_size(0x4321ul);
      buf.set_image_max_array_size(0x4321ul);
      buf.set_parent_device_id(0x4321ul);
      buf.set_partition_max_sub_devices(0x4321u);
      for(int i=0; i<2; ++i) buf.add_partition_properties(partition_properties[i]);
      buf.set_partition_affinity_domain(0x4321);
      for(int i=0; i<2; ++i) buf.add_partition_type(partition_type[i]);
      buf.set_reference_count(0x4321u);
      buf.set_preferred_interop_user_sync(1);
      buf.set_printf_buffer_size(0x4321ul);
      buf.set_image_pitch_alignment(0x4321u);
      buf.set_image_base_address_alignment(0x4321u);
      return buf;
    }
  };

} /* namespace Clinfo */
} /* namespace Protobuf */
} /* namespace Dimbo */

#endif /* DIMBO_PROTOBUF_CLINFO_DEVICE_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
