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

// dimbo/clinfo/device_info_fixtures.hpp

/** // doc: dimbo/clinfo/device_info_fixtures.hpp {{{
 * \file dimbo/clinfo/device_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CLINFO_DEVICE_INFO_FIXTURES_HPP_INCLUDED
#define DIMBO_CLINFO_DEVICE_INFO_FIXTURES_HPP_INCLUDED

#include <dimbo/clinfo/device_info.hpp>

namespace Dimbo {
namespace Clinfo {

struct Device_Info_Fixtures
  {
    static Device_Info _1()
    {
      size_t max_work_item_sizes[3] = { 1, 2, 3 };
      cl_device_partition_property partition_properties[2] = { 1, 2 };
      cl_device_partition_property partition_type[2] = { 1, 2 };

      return Device_Info()
         .set_id(0x1234ul)
         .set_type(0x1234ul)
         .set_vendor_id(0x1234u)
         .set_max_compute_units(0x1234u)
         .set_max_work_item_dimensions(0x1234u)
         .set_max_work_group_size(0x1234ul)
         .set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes,max_work_item_sizes+3))
         .set_preferred_vector_width_char(0x1234u)
         .set_preferred_vector_width_short(0x1234u)
         .set_preferred_vector_width_int(0x1234u)
         .set_preferred_vector_width_long(0x1234u)
         .set_preferred_vector_width_float(0x1234u)
         .set_preferred_vector_width_double(0x1234u)
         .set_max_clock_frequency(0x1234u)
         .set_address_bits(0x1234u)
         .set_max_read_image_args(0x1234u)
         .set_max_write_image_args(0x1234u)
         .set_max_mem_alloc_size(0x1234ul)
         .set_image2d_max_width(0x1234ul)
         .set_image2d_max_height(0x1234ul)
         .set_image3d_max_width(0x1234ul)
         .set_image3d_max_height(0x1234ul)
         .set_image3d_max_depth(0x1234ul)
         .set_image_support(0)
         .set_max_parameter_size(0x1234ul)
         .set_max_samplers(0x1234u)
         .set_mem_base_addr_align(0x1234u)
         .set_min_data_type_align_size(0x1234u)
         .set_single_fp_config(0x1234)
         .set_global_mem_cache_type(0x1234)
         .set_global_mem_cacheline_size(0x1234u)
         .set_global_mem_cache_size(0x1234ul)
         .set_global_mem_size(0x1234ul)
         .set_max_constant_buffer_size(0x1234u)
         .set_max_constant_args(0x1234u)
         .set_local_mem_type(0x1234)
         .set_local_mem_size(0x1234ul)
         .set_error_correction_support(0)
         .set_profiling_timer_resolution(0x1234ul)
         .set_endian_little(0)
         .set_available(0)
         .set_compiler_available(0)
         .set_execution_capabilities(0x1234)
         .set_queue_properties(0x1234)
         .set_name("_name")
         .set_vendor("_vendor")
         .set_driver_version("_driver_version")
         .set_profile("_profile")
         .set_version("_version")
         .set_extensions("_extensions")
         .set_platform_id(0x1234ul)
         .set_double_fp_config(0x1234)
         .set_preferred_vector_width_half(0x1234u)
         .set_host_unified_memory(0)
         .set_native_vector_width_char(0x1234u)
         .set_native_vector_width_short(0x1234u)
         .set_native_vector_width_int(0x1234u)
         .set_native_vector_width_long(0x1234u)
         .set_native_vector_width_float(0x1234u)
         .set_native_vector_width_double(0x1234u)
         .set_native_vector_width_half(0x1234u)
         .set_opencl_c_version("_opencl_c_version")
         .set_linker_available(0)
         .set_built_in_kernels("_built_in_kernels")
         .set_image_max_buffer_size(0x1234ul)
         .set_image_max_array_size(0x1234ul)
         .set_parent_device_id(0x1234ul)
         .set_partition_max_sub_devices(0x1234u)
         .set_partition_properties(std::vector<cl_device_partition_property>(partition_properties,partition_properties+2))
         .set_partition_affinity_domain(0x1234)
         .set_partition_type(std::vector<cl_device_partition_property>(partition_type,partition_type+2))
         .set_reference_count(0x1234u)
         .set_preferred_interop_user_sync(0)
         .set_printf_buffer_size(0x1234ul)
         .set_image_pitch_alignment(0x1234u)
         .set_image_base_address_alignment(0x1234u);
    }
    static Device_Info _2()
    {
      size_t max_work_item_sizes[3] = { 3, 2, 1 };
      cl_device_partition_property partition_properties[2] = { 2, 1 };
      cl_device_partition_property partition_type[2] = { 2, 1 };

      return Device_Info()
          .set_id(0x4321ul)
          .set_type(0x4321ul)
          .set_vendor_id(0x4321u)
          .set_max_compute_units(0x4321u)
          .set_max_work_item_dimensions(0x4321u)
          .set_max_work_group_size(0x4321ul)
          .set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes,max_work_item_sizes+3))
          .set_preferred_vector_width_char(0x4321u)
          .set_preferred_vector_width_short(0x4321u)
          .set_preferred_vector_width_int(0x4321u)
          .set_preferred_vector_width_long(0x4321u)
          .set_preferred_vector_width_float(0x4321u)
          .set_preferred_vector_width_double(0x4321u)
          .set_max_clock_frequency(0x4321u)
          .set_address_bits(0x4321u)
          .set_max_read_image_args(0x4321u)
          .set_max_write_image_args(0x4321u)
          .set_max_mem_alloc_size(0x4321ul)
          .set_image2d_max_width(0x4321ul)
          .set_image2d_max_height(0x4321ul)
          .set_image3d_max_width(0x4321ul)
          .set_image3d_max_height(0x4321ul)
          .set_image3d_max_depth(0x4321ul)
          .set_image_support(1)
          .set_max_parameter_size(0x4321ul)
          .set_max_samplers(0x4321u)
          .set_mem_base_addr_align(0x4321u)
          .set_min_data_type_align_size(0x4321u)
          .set_single_fp_config(0x4321)
          .set_global_mem_cache_type(0x4321)
          .set_global_mem_cacheline_size(0x4321u)
          .set_global_mem_cache_size(0x4321ul)
          .set_global_mem_size(0x4321ul)
          .set_max_constant_buffer_size(0x4321u)
          .set_max_constant_args(0x4321u)
          .set_local_mem_type(0x4321)
          .set_local_mem_size(0x4321ul)
          .set_error_correction_support(1)
          .set_profiling_timer_resolution(0x4321ul)
          .set_endian_little(1)
          .set_available(1)
          .set_compiler_available(1)
          .set_execution_capabilities(0x4321)
          .set_queue_properties(0x4321)
          .set_name("x_namex")
          .set_vendor("x_vendorx")
          .set_driver_version("x_driver_versionx")
          .set_profile("x_profilex")
          .set_version("x_versionx")
          .set_extensions("x_extensionsx")
          .set_platform_id(0x4321ul)
          .set_double_fp_config(0x4321)
          .set_preferred_vector_width_half(0x4321u)
          .set_host_unified_memory(1)
          .set_native_vector_width_char(0x4321u)
          .set_native_vector_width_short(0x4321u)
          .set_native_vector_width_int(0x4321u)
          .set_native_vector_width_long(0x4321u)
          .set_native_vector_width_float(0x4321u)
          .set_native_vector_width_double(0x4321u)
          .set_native_vector_width_half(0x4321u)
          .set_opencl_c_version("x_opencl_c_versionx")
          .set_linker_available(1)
          .set_built_in_kernels("x_built_in_kernelsx")
          .set_image_max_buffer_size(0x4321ul)
          .set_image_max_array_size(0x4321ul)
          .set_parent_device_id(0x4321ul)
          .set_partition_max_sub_devices(0x4321u)
          .set_partition_properties(std::vector<cl_device_partition_property>(partition_properties,partition_properties+2))
          .set_partition_affinity_domain(0x4321)
          .set_partition_type(std::vector<cl_device_partition_property>(partition_type,partition_type+2))
          .set_reference_count(0x4321u)
          .set_preferred_interop_user_sync(1)
          .set_printf_buffer_size(0x4321ul)
          .set_image_pitch_alignment(0x4321u)
          .set_image_base_address_alignment(0x4321u);
    }
  };

} /* namespace Clinfo */
} /* namespace Dimbo */

#endif /* DIMBO_CLINFO_DEVICE_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
