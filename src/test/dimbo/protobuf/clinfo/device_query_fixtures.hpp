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

// /dimbo/protobuf/clinfo/device_query_fixtures.hpp

/** // doc: /dimbo/protobuf/clinfo/device_query_fixtures.hpp {{{
 * \file /dimbo/protobuf/clinfo/device_query_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_FIXTURES_HPP_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_FIXTURES_HPP_INCLUDED

#include <dimbo/protobuf/clinfo/device_query.hpp>

namespace Dimbo {
namespace Protobuf {
namespace Clinfo {

struct Device_Query_Fixtures
  {
    // This corresponds to Dimbo::Clinfo::Device_Query_Fixtures::_false()
    // see "dimbo/clinfo/device_query_fixtures.hpp" under "src/test".
    static Device_Query _false()
    {
      Device_Query buf;
      buf.set_id_selected(false);
      buf.set_type_selected(false);
      buf.set_vendor_id_selected(false);
      buf.set_max_compute_units_selected(false);
      buf.set_max_work_item_dimensions_selected(false);
      buf.set_max_work_group_size_selected(false);
      buf.set_max_work_item_sizes_selected(false);
      buf.set_preferred_vector_width_char_selected(false);
      buf.set_preferred_vector_width_short_selected(false);
      buf.set_preferred_vector_width_int_selected(false);
      buf.set_preferred_vector_width_long_selected(false);
      buf.set_preferred_vector_width_float_selected(false);
      buf.set_preferred_vector_width_double_selected(false);
      buf.set_max_clock_frequency_selected(false);
      buf.set_address_bits_selected(false);
      buf.set_max_read_image_args_selected(false);
      buf.set_max_write_image_args_selected(false);
      buf.set_max_mem_alloc_size_selected(false);
      buf.set_image2d_max_width_selected(false);
      buf.set_image2d_max_height_selected(false);
      buf.set_image3d_max_width_selected(false);
      buf.set_image3d_max_height_selected(false);
      buf.set_image3d_max_depth_selected(false);
      buf.set_image_support_selected(false);
      buf.set_max_parameter_size_selected(false);
      buf.set_max_samplers_selected(false);
      buf.set_mem_base_addr_align_selected(false);
      buf.set_min_data_type_align_size_selected(false);
      buf.set_single_fp_config_selected(false);
      buf.set_global_mem_cache_type_selected(false);
      buf.set_global_mem_cacheline_size_selected(false);
      buf.set_global_mem_cache_size_selected(false);
      buf.set_global_mem_size_selected(false);
      buf.set_max_constant_buffer_size_selected(false);
      buf.set_max_constant_args_selected(false);
      buf.set_local_mem_type_selected(false);
      buf.set_local_mem_size_selected(false);
      buf.set_error_correction_support_selected(false);
      buf.set_profiling_timer_resolution_selected(false);
      buf.set_endian_little_selected(false);
      buf.set_available_selected(false);
      buf.set_compiler_available_selected(false);
      buf.set_execution_capabilities_selected(false);
      buf.set_queue_properties_selected(false);
      buf.set_name_selected(false);
      buf.set_vendor_selected(false);
      buf.set_driver_version_selected(false);
      buf.set_profile_selected(false);
      buf.set_version_selected(false);
      buf.set_extensions_selected(false);
      buf.set_platform_id_selected(false);
      buf.set_double_fp_config_selected(false);
      buf.set_preferred_vector_width_half_selected(false);
      buf.set_host_unified_memory_selected(false);
      buf.set_native_vector_width_char_selected(false);
      buf.set_native_vector_width_short_selected(false);
      buf.set_native_vector_width_int_selected(false);
      buf.set_native_vector_width_long_selected(false);
      buf.set_native_vector_width_float_selected(false);
      buf.set_native_vector_width_double_selected(false);
      buf.set_native_vector_width_half_selected(false);
      buf.set_opencl_c_version_selected(false);
      buf.set_linker_available_selected(false);
      buf.set_built_in_kernels_selected(false);
      buf.set_image_max_buffer_size_selected(false);
      buf.set_image_max_array_size_selected(false);
      buf.set_parent_device_id_selected(false);
      buf.set_partition_max_sub_devices_selected(false);
      buf.set_partition_properties_selected(false);
      buf.set_partition_affinity_domain_selected(false);
      buf.set_partition_type_selected(false);
      buf.set_reference_count_selected(false);
      buf.set_preferred_interop_user_sync_selected(false);
      buf.set_printf_buffer_size_selected(false);
      buf.set_image_pitch_alignment_selected(false);
      buf.set_image_base_address_alignment_selected(false);
      return buf;
    }
    // This corresponds to Dimbo::Clinfo::Device_Query_Fixtures::_true()
    // see "dimbo/clinfo/device_query_fixtures.hpp" under "src/test".
    static Device_Query _true()
    {
      Device_Query buf;
      buf.set_id_selected(true);
      buf.set_type_selected(true);
      buf.set_vendor_id_selected(true);
      buf.set_max_compute_units_selected(true);
      buf.set_max_work_item_dimensions_selected(true);
      buf.set_max_work_group_size_selected(true);
      buf.set_max_work_item_sizes_selected(true);
      buf.set_preferred_vector_width_char_selected(true);
      buf.set_preferred_vector_width_short_selected(true);
      buf.set_preferred_vector_width_int_selected(true);
      buf.set_preferred_vector_width_long_selected(true);
      buf.set_preferred_vector_width_float_selected(true);
      buf.set_preferred_vector_width_double_selected(true);
      buf.set_max_clock_frequency_selected(true);
      buf.set_address_bits_selected(true);
      buf.set_max_read_image_args_selected(true);
      buf.set_max_write_image_args_selected(true);
      buf.set_max_mem_alloc_size_selected(true);
      buf.set_image2d_max_width_selected(true);
      buf.set_image2d_max_height_selected(true);
      buf.set_image3d_max_width_selected(true);
      buf.set_image3d_max_height_selected(true);
      buf.set_image3d_max_depth_selected(true);
      buf.set_image_support_selected(true);
      buf.set_max_parameter_size_selected(true);
      buf.set_max_samplers_selected(true);
      buf.set_mem_base_addr_align_selected(true);
      buf.set_min_data_type_align_size_selected(true);
      buf.set_single_fp_config_selected(true);
      buf.set_global_mem_cache_type_selected(true);
      buf.set_global_mem_cacheline_size_selected(true);
      buf.set_global_mem_cache_size_selected(true);
      buf.set_global_mem_size_selected(true);
      buf.set_max_constant_buffer_size_selected(true);
      buf.set_max_constant_args_selected(true);
      buf.set_local_mem_type_selected(true);
      buf.set_local_mem_size_selected(true);
      buf.set_error_correction_support_selected(true);
      buf.set_profiling_timer_resolution_selected(true);
      buf.set_endian_little_selected(true);
      buf.set_available_selected(true);
      buf.set_compiler_available_selected(true);
      buf.set_execution_capabilities_selected(true);
      buf.set_queue_properties_selected(true);
      buf.set_name_selected(true);
      buf.set_vendor_selected(true);
      buf.set_driver_version_selected(true);
      buf.set_profile_selected(true);
      buf.set_version_selected(true);
      buf.set_extensions_selected(true);
      buf.set_platform_id_selected(true);
      buf.set_double_fp_config_selected(true);
      buf.set_preferred_vector_width_half_selected(true);
      buf.set_host_unified_memory_selected(true);
      buf.set_native_vector_width_char_selected(true);
      buf.set_native_vector_width_short_selected(true);
      buf.set_native_vector_width_int_selected(true);
      buf.set_native_vector_width_long_selected(true);
      buf.set_native_vector_width_float_selected(true);
      buf.set_native_vector_width_double_selected(true);
      buf.set_native_vector_width_half_selected(true);
      buf.set_opencl_c_version_selected(true);
      buf.set_linker_available_selected(true);
      buf.set_built_in_kernels_selected(true);
      buf.set_image_max_buffer_size_selected(true);
      buf.set_image_max_array_size_selected(true);
      buf.set_parent_device_id_selected(true);
      buf.set_partition_max_sub_devices_selected(true);
      buf.set_partition_properties_selected(true);
      buf.set_partition_affinity_domain_selected(true);
      buf.set_partition_type_selected(true);
      buf.set_reference_count_selected(true);
      buf.set_preferred_interop_user_sync_selected(true);
      buf.set_printf_buffer_size_selected(true);
      buf.set_image_pitch_alignment_selected(true);
      buf.set_image_base_address_alignment_selected(true);
      return buf;
    }
  };

} /* namespace Clinfo */
} /* namespace Protobuf */
} /* namespace Dimbo */

#endif /* DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
