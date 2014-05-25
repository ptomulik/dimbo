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

// dimbo/clinfo/device_query.t.h

/** // doc: dimbo/clinfo/device_query.t.h {{{
 * \file dimbo/clinfo/device_query.t.h
 * \brief Unit tests for Dimbo::Clinfo::Device_Query
 */ // }}}
#ifndef DIMBO_CLINFO_DEVICE_QUERY_T_H_INCLUDED
#define DIMBO_CLINFO_DEVICE_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/clinfo/device_query.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Clinfo { class Device_Query_TestSuite; } }

/** // doc: class Dimbo::Clinfo::Device_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Clinfo::Device_Query_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(Device_Query().id_selected());
    TS_ASSERT(Device_Query().type_selected());
    TS_ASSERT(Device_Query().vendor_id_selected());
    TS_ASSERT(Device_Query().max_compute_units_selected());
    TS_ASSERT(Device_Query().max_work_item_dimensions_selected());
    TS_ASSERT(Device_Query().max_work_group_size_selected());
    TS_ASSERT(Device_Query().max_work_item_sizes_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_char_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_short_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_int_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_long_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_float_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_double_selected());
    TS_ASSERT(Device_Query().max_clock_frequency_selected());
    TS_ASSERT(Device_Query().address_bits_selected());
    TS_ASSERT(Device_Query().max_read_image_args_selected());
    TS_ASSERT(Device_Query().max_write_image_args_selected());
    TS_ASSERT(Device_Query().max_mem_alloc_size_selected());
    TS_ASSERT(Device_Query().image2d_max_width_selected());
    TS_ASSERT(Device_Query().image2d_max_height_selected());
    TS_ASSERT(Device_Query().image3d_max_width_selected());
    TS_ASSERT(Device_Query().image3d_max_height_selected());
    TS_ASSERT(Device_Query().image3d_max_depth_selected());
    TS_ASSERT(Device_Query().image_support_selected());
    TS_ASSERT(Device_Query().max_parameter_size_selected());
    TS_ASSERT(Device_Query().max_samplers_selected());
    TS_ASSERT(Device_Query().mem_base_addr_align_selected());
    TS_ASSERT(Device_Query().min_data_type_align_size_selected());
    TS_ASSERT(Device_Query().single_fp_config_selected());
    TS_ASSERT(Device_Query().global_mem_cache_type_selected());
    TS_ASSERT(Device_Query().global_mem_cacheline_size_selected());
    TS_ASSERT(Device_Query().global_mem_cache_size_selected());
    TS_ASSERT(Device_Query().global_mem_size_selected());
    TS_ASSERT(Device_Query().max_constant_buffer_size_selected());
    TS_ASSERT(Device_Query().max_constant_args_selected());
    TS_ASSERT(Device_Query().local_mem_type_selected());
    TS_ASSERT(Device_Query().local_mem_size_selected());
    TS_ASSERT(Device_Query().error_correction_support_selected());
    TS_ASSERT(Device_Query().profiling_timer_resolution_selected());
    TS_ASSERT(Device_Query().endian_little_selected());
    TS_ASSERT(Device_Query().available_selected());
    TS_ASSERT(Device_Query().compiler_available_selected());
    TS_ASSERT(Device_Query().execution_capabilities_selected());
    TS_ASSERT(Device_Query().queue_properties_selected());
    TS_ASSERT(Device_Query().name_selected());
    TS_ASSERT(Device_Query().vendor_selected());
    TS_ASSERT(Device_Query().driver_version_selected());
    TS_ASSERT(Device_Query().profile_selected());
    TS_ASSERT(Device_Query().version_selected());
    TS_ASSERT(Device_Query().extensions_selected());
    TS_ASSERT(Device_Query().platform_id_selected());
    TS_ASSERT(Device_Query().double_fp_config_selected());
    TS_ASSERT(Device_Query().preferred_vector_width_half_selected());
    TS_ASSERT(Device_Query().host_unified_memory_selected());
    TS_ASSERT(Device_Query().native_vector_width_char_selected());
    TS_ASSERT(Device_Query().native_vector_width_short_selected());
    TS_ASSERT(Device_Query().native_vector_width_int_selected());
    TS_ASSERT(Device_Query().native_vector_width_long_selected());
    TS_ASSERT(Device_Query().native_vector_width_float_selected());
    TS_ASSERT(Device_Query().native_vector_width_double_selected());
    TS_ASSERT(Device_Query().native_vector_width_half_selected());
    TS_ASSERT(Device_Query().opencl_c_version_selected());
    TS_ASSERT(Device_Query().linker_available_selected());
    TS_ASSERT(Device_Query().built_in_kernels_selected());
    TS_ASSERT(Device_Query().image_max_buffer_size_selected());
    TS_ASSERT(Device_Query().image_max_array_size_selected());
    TS_ASSERT(Device_Query().parent_device_id_selected());
    TS_ASSERT(Device_Query().partition_max_sub_devices_selected());
    TS_ASSERT(Device_Query().partition_properties_selected());
    TS_ASSERT(Device_Query().partition_affinity_domain_selected());
    TS_ASSERT(Device_Query().partition_type_selected());
    TS_ASSERT(Device_Query().reference_count_selected());
    TS_ASSERT(Device_Query().preferred_interop_user_sync_selected());
    TS_ASSERT(Device_Query().printf_buffer_size_selected());
    TS_ASSERT(Device_Query().image_pitch_alignment_selected());
    TS_ASSERT(Device_Query().image_base_address_alignment_selected());
  }
  /** // doc: test_ctor_true() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_true( )
  {
    TS_ASSERT(Device_Query(true).id_selected());
    TS_ASSERT(Device_Query(true).type_selected());
    TS_ASSERT(Device_Query(true).vendor_id_selected());
    TS_ASSERT(Device_Query(true).max_compute_units_selected());
    TS_ASSERT(Device_Query(true).max_work_item_dimensions_selected());
    TS_ASSERT(Device_Query(true).max_work_group_size_selected());
    TS_ASSERT(Device_Query(true).max_work_item_sizes_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_char_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_short_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_int_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_long_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_float_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_double_selected());
    TS_ASSERT(Device_Query(true).max_clock_frequency_selected());
    TS_ASSERT(Device_Query(true).address_bits_selected());
    TS_ASSERT(Device_Query(true).max_read_image_args_selected());
    TS_ASSERT(Device_Query(true).max_write_image_args_selected());
    TS_ASSERT(Device_Query(true).max_mem_alloc_size_selected());
    TS_ASSERT(Device_Query(true).image2d_max_width_selected());
    TS_ASSERT(Device_Query(true).image2d_max_height_selected());
    TS_ASSERT(Device_Query(true).image3d_max_width_selected());
    TS_ASSERT(Device_Query(true).image3d_max_height_selected());
    TS_ASSERT(Device_Query(true).image3d_max_depth_selected());
    TS_ASSERT(Device_Query(true).image_support_selected());
    TS_ASSERT(Device_Query(true).max_parameter_size_selected());
    TS_ASSERT(Device_Query(true).max_samplers_selected());
    TS_ASSERT(Device_Query(true).mem_base_addr_align_selected());
    TS_ASSERT(Device_Query(true).min_data_type_align_size_selected());
    TS_ASSERT(Device_Query(true).single_fp_config_selected());
    TS_ASSERT(Device_Query(true).global_mem_cache_type_selected());
    TS_ASSERT(Device_Query(true).global_mem_cacheline_size_selected());
    TS_ASSERT(Device_Query(true).global_mem_cache_size_selected());
    TS_ASSERT(Device_Query(true).global_mem_size_selected());
    TS_ASSERT(Device_Query(true).max_constant_buffer_size_selected());
    TS_ASSERT(Device_Query(true).max_constant_args_selected());
    TS_ASSERT(Device_Query(true).local_mem_type_selected());
    TS_ASSERT(Device_Query(true).local_mem_size_selected());
    TS_ASSERT(Device_Query(true).error_correction_support_selected());
    TS_ASSERT(Device_Query(true).profiling_timer_resolution_selected());
    TS_ASSERT(Device_Query(true).endian_little_selected());
    TS_ASSERT(Device_Query(true).available_selected());
    TS_ASSERT(Device_Query(true).compiler_available_selected());
    TS_ASSERT(Device_Query(true).execution_capabilities_selected());
    TS_ASSERT(Device_Query(true).queue_properties_selected());
    TS_ASSERT(Device_Query(true).name_selected());
    TS_ASSERT(Device_Query(true).vendor_selected());
    TS_ASSERT(Device_Query(true).driver_version_selected());
    TS_ASSERT(Device_Query(true).profile_selected());
    TS_ASSERT(Device_Query(true).version_selected());
    TS_ASSERT(Device_Query(true).extensions_selected());
    TS_ASSERT(Device_Query(true).platform_id_selected());
    TS_ASSERT(Device_Query(true).double_fp_config_selected());
    TS_ASSERT(Device_Query(true).preferred_vector_width_half_selected());
    TS_ASSERT(Device_Query(true).host_unified_memory_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_char_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_short_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_int_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_long_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_float_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_double_selected());
    TS_ASSERT(Device_Query(true).native_vector_width_half_selected());
    TS_ASSERT(Device_Query(true).opencl_c_version_selected());
    TS_ASSERT(Device_Query(true).linker_available_selected());
    TS_ASSERT(Device_Query(true).built_in_kernels_selected());
    TS_ASSERT(Device_Query(true).image_max_buffer_size_selected());
    TS_ASSERT(Device_Query(true).image_max_array_size_selected());
    TS_ASSERT(Device_Query(true).parent_device_id_selected());
    TS_ASSERT(Device_Query(true).partition_max_sub_devices_selected());
    TS_ASSERT(Device_Query(true).partition_properties_selected());
    TS_ASSERT(Device_Query(true).partition_affinity_domain_selected());
    TS_ASSERT(Device_Query(true).partition_type_selected());
    TS_ASSERT(Device_Query(true).reference_count_selected());
    TS_ASSERT(Device_Query(true).preferred_interop_user_sync_selected());
    TS_ASSERT(Device_Query(true).printf_buffer_size_selected());
    TS_ASSERT(Device_Query(true).image_pitch_alignment_selected());
    TS_ASSERT(Device_Query(true).image_base_address_alignment_selected());
  }
  /** // doc: test_ctor_false() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_false( )
  {
    TS_ASSERT(!Device_Query(false).id_selected());
    TS_ASSERT(!Device_Query(false).type_selected());
    TS_ASSERT(!Device_Query(false).vendor_id_selected());
    TS_ASSERT(!Device_Query(false).max_compute_units_selected());
    TS_ASSERT(!Device_Query(false).max_work_item_dimensions_selected());
    TS_ASSERT(!Device_Query(false).max_work_group_size_selected());
    TS_ASSERT(!Device_Query(false).max_work_item_sizes_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_char_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_short_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_int_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_long_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_float_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_double_selected());
    TS_ASSERT(!Device_Query(false).max_clock_frequency_selected());
    TS_ASSERT(!Device_Query(false).address_bits_selected());
    TS_ASSERT(!Device_Query(false).max_read_image_args_selected());
    TS_ASSERT(!Device_Query(false).max_write_image_args_selected());
    TS_ASSERT(!Device_Query(false).max_mem_alloc_size_selected());
    TS_ASSERT(!Device_Query(false).image2d_max_width_selected());
    TS_ASSERT(!Device_Query(false).image2d_max_height_selected());
    TS_ASSERT(!Device_Query(false).image3d_max_width_selected());
    TS_ASSERT(!Device_Query(false).image3d_max_height_selected());
    TS_ASSERT(!Device_Query(false).image3d_max_depth_selected());
    TS_ASSERT(!Device_Query(false).image_support_selected());
    TS_ASSERT(!Device_Query(false).max_parameter_size_selected());
    TS_ASSERT(!Device_Query(false).max_samplers_selected());
    TS_ASSERT(!Device_Query(false).mem_base_addr_align_selected());
    TS_ASSERT(!Device_Query(false).min_data_type_align_size_selected());
    TS_ASSERT(!Device_Query(false).single_fp_config_selected());
    TS_ASSERT(!Device_Query(false).global_mem_cache_type_selected());
    TS_ASSERT(!Device_Query(false).global_mem_cacheline_size_selected());
    TS_ASSERT(!Device_Query(false).global_mem_cache_size_selected());
    TS_ASSERT(!Device_Query(false).global_mem_size_selected());
    TS_ASSERT(!Device_Query(false).max_constant_buffer_size_selected());
    TS_ASSERT(!Device_Query(false).max_constant_args_selected());
    TS_ASSERT(!Device_Query(false).local_mem_type_selected());
    TS_ASSERT(!Device_Query(false).local_mem_size_selected());
    TS_ASSERT(!Device_Query(false).error_correction_support_selected());
    TS_ASSERT(!Device_Query(false).profiling_timer_resolution_selected());
    TS_ASSERT(!Device_Query(false).endian_little_selected());
    TS_ASSERT(!Device_Query(false).available_selected());
    TS_ASSERT(!Device_Query(false).compiler_available_selected());
    TS_ASSERT(!Device_Query(false).execution_capabilities_selected());
    TS_ASSERT(!Device_Query(false).queue_properties_selected());
    TS_ASSERT(!Device_Query(false).name_selected());
    TS_ASSERT(!Device_Query(false).vendor_selected());
    TS_ASSERT(!Device_Query(false).driver_version_selected());
    TS_ASSERT(!Device_Query(false).profile_selected());
    TS_ASSERT(!Device_Query(false).version_selected());
    TS_ASSERT(!Device_Query(false).extensions_selected());
    TS_ASSERT(!Device_Query(false).platform_id_selected());
    TS_ASSERT(!Device_Query(false).double_fp_config_selected());
    TS_ASSERT(!Device_Query(false).preferred_vector_width_half_selected());
    TS_ASSERT(!Device_Query(false).host_unified_memory_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_char_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_short_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_int_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_long_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_float_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_double_selected());
    TS_ASSERT(!Device_Query(false).native_vector_width_half_selected());
    TS_ASSERT(!Device_Query(false).opencl_c_version_selected());
    TS_ASSERT(!Device_Query(false).linker_available_selected());
    TS_ASSERT(!Device_Query(false).built_in_kernels_selected());
    TS_ASSERT(!Device_Query(false).image_max_buffer_size_selected());
    TS_ASSERT(!Device_Query(false).image_max_array_size_selected());
    TS_ASSERT(!Device_Query(false).parent_device_id_selected());
    TS_ASSERT(!Device_Query(false).partition_max_sub_devices_selected());
    TS_ASSERT(!Device_Query(false).partition_properties_selected());
    TS_ASSERT(!Device_Query(false).partition_affinity_domain_selected());
    TS_ASSERT(!Device_Query(false).partition_type_selected());
    TS_ASSERT(!Device_Query(false).reference_count_selected());
    TS_ASSERT(!Device_Query(false).preferred_interop_user_sync_selected());
    TS_ASSERT(!Device_Query(false).printf_buffer_size_selected());
    TS_ASSERT(!Device_Query(false).image_pitch_alignment_selected());
    TS_ASSERT(!Device_Query(false).image_base_address_alignment_selected());
  }
  /** // doc: test_set_get_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get_1( )
  {
    TS_ASSERT(!Device_Query(true).select_id(false).id_selected());
    TS_ASSERT(!Device_Query(true).select_type(false).type_selected());
    TS_ASSERT(!Device_Query(true).select_vendor_id(false).vendor_id_selected());
    TS_ASSERT(!Device_Query(true).select_max_compute_units(false).max_compute_units_selected());
    TS_ASSERT(!Device_Query(true).select_max_work_item_dimensions(false).max_work_item_dimensions_selected());
    TS_ASSERT(!Device_Query(true).select_max_work_group_size(false).max_work_group_size_selected());
    TS_ASSERT(!Device_Query(true).select_max_work_item_sizes(false).max_work_item_sizes_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_char(false).preferred_vector_width_char_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_short(false).preferred_vector_width_short_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_int(false).preferred_vector_width_int_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_long(false).preferred_vector_width_long_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_float(false).preferred_vector_width_float_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_double(false).preferred_vector_width_double_selected());
    TS_ASSERT(!Device_Query(true).select_max_clock_frequency(false).max_clock_frequency_selected());
    TS_ASSERT(!Device_Query(true).select_address_bits(false).address_bits_selected());
    TS_ASSERT(!Device_Query(true).select_max_read_image_args(false).max_read_image_args_selected());
    TS_ASSERT(!Device_Query(true).select_max_write_image_args(false).max_write_image_args_selected());
    TS_ASSERT(!Device_Query(true).select_max_mem_alloc_size(false).max_mem_alloc_size_selected());
    TS_ASSERT(!Device_Query(true).select_image2d_max_width(false).image2d_max_width_selected());
    TS_ASSERT(!Device_Query(true).select_image2d_max_height(false).image2d_max_height_selected());
    TS_ASSERT(!Device_Query(true).select_image3d_max_width(false).image3d_max_width_selected());
    TS_ASSERT(!Device_Query(true).select_image3d_max_height(false).image3d_max_height_selected());
    TS_ASSERT(!Device_Query(true).select_image3d_max_depth(false).image3d_max_depth_selected());
    TS_ASSERT(!Device_Query(true).select_image_support(false).image_support_selected());
    TS_ASSERT(!Device_Query(true).select_max_parameter_size(false).max_parameter_size_selected());
    TS_ASSERT(!Device_Query(true).select_max_samplers(false).max_samplers_selected());
    TS_ASSERT(!Device_Query(true).select_mem_base_addr_align(false).mem_base_addr_align_selected());
    TS_ASSERT(!Device_Query(true).select_min_data_type_align_size(false).min_data_type_align_size_selected());
    TS_ASSERT(!Device_Query(true).select_single_fp_config(false).single_fp_config_selected());
    TS_ASSERT(!Device_Query(true).select_global_mem_cache_type(false).global_mem_cache_type_selected());
    TS_ASSERT(!Device_Query(true).select_global_mem_cacheline_size(false).global_mem_cacheline_size_selected());
    TS_ASSERT(!Device_Query(true).select_global_mem_cache_size(false).global_mem_cache_size_selected());
    TS_ASSERT(!Device_Query(true).select_global_mem_size(false).global_mem_size_selected());
    TS_ASSERT(!Device_Query(true).select_max_constant_buffer_size(false).max_constant_buffer_size_selected());
    TS_ASSERT(!Device_Query(true).select_max_constant_args(false).max_constant_args_selected());
    TS_ASSERT(!Device_Query(true).select_local_mem_type(false).local_mem_type_selected());
    TS_ASSERT(!Device_Query(true).select_local_mem_size(false).local_mem_size_selected());
    TS_ASSERT(!Device_Query(true).select_error_correction_support(false).error_correction_support_selected());
    TS_ASSERT(!Device_Query(true).select_profiling_timer_resolution(false).profiling_timer_resolution_selected());
    TS_ASSERT(!Device_Query(true).select_endian_little(false).endian_little_selected());
    TS_ASSERT(!Device_Query(true).select_available(false).available_selected());
    TS_ASSERT(!Device_Query(true).select_compiler_available(false).compiler_available_selected());
    TS_ASSERT(!Device_Query(true).select_execution_capabilities(false).execution_capabilities_selected());
    TS_ASSERT(!Device_Query(true).select_queue_properties(false).queue_properties_selected());
    TS_ASSERT(!Device_Query(true).select_name(false).name_selected());
    TS_ASSERT(!Device_Query(true).select_vendor(false).vendor_selected());
    TS_ASSERT(!Device_Query(true).select_driver_version(false).driver_version_selected());
    TS_ASSERT(!Device_Query(true).select_profile(false).profile_selected());
    TS_ASSERT(!Device_Query(true).select_version(false).version_selected());
    TS_ASSERT(!Device_Query(true).select_extensions(false).extensions_selected());
    TS_ASSERT(!Device_Query(true).select_platform_id(false).platform_id_selected());
    TS_ASSERT(!Device_Query(true).select_double_fp_config(false).double_fp_config_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_vector_width_half(false).preferred_vector_width_half_selected());
    TS_ASSERT(!Device_Query(true).select_host_unified_memory(false).host_unified_memory_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_char(false).native_vector_width_char_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_short(false).native_vector_width_short_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_int(false).native_vector_width_int_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_long(false).native_vector_width_long_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_float(false).native_vector_width_float_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_double(false).native_vector_width_double_selected());
    TS_ASSERT(!Device_Query(true).select_native_vector_width_half(false).native_vector_width_half_selected());
    TS_ASSERT(!Device_Query(true).select_opencl_c_version(false).opencl_c_version_selected());
    TS_ASSERT(!Device_Query(true).select_linker_available(false).linker_available_selected());
    TS_ASSERT(!Device_Query(true).select_built_in_kernels(false).built_in_kernels_selected());
    TS_ASSERT(!Device_Query(true).select_image_max_buffer_size(false).image_max_buffer_size_selected());
    TS_ASSERT(!Device_Query(true).select_image_max_array_size(false).image_max_array_size_selected());
    TS_ASSERT(!Device_Query(true).select_parent_device_id(false).parent_device_id_selected());
    TS_ASSERT(!Device_Query(true).select_partition_max_sub_devices(false).partition_max_sub_devices_selected());
    TS_ASSERT(!Device_Query(true).select_partition_properties(false).partition_properties_selected());
    TS_ASSERT(!Device_Query(true).select_partition_affinity_domain(false).partition_affinity_domain_selected());
    TS_ASSERT(!Device_Query(true).select_partition_type(false).partition_type_selected());
    TS_ASSERT(!Device_Query(true).select_reference_count(false).reference_count_selected());
    TS_ASSERT(!Device_Query(true).select_preferred_interop_user_sync(false).preferred_interop_user_sync_selected());
    TS_ASSERT(!Device_Query(true).select_printf_buffer_size(false).printf_buffer_size_selected());
    TS_ASSERT(!Device_Query(true).select_image_pitch_alignment(false).image_pitch_alignment_selected());
    TS_ASSERT(!Device_Query(true).select_image_base_address_alignment(false).image_base_address_alignment_selected());
  }
  /** // doc: test_set_get_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get_2( )
  {
    TS_ASSERT(Device_Query(false).select_id(true).id_selected());
    TS_ASSERT(Device_Query(false).select_type(true).type_selected());
    TS_ASSERT(Device_Query(false).select_vendor_id(true).vendor_id_selected());
    TS_ASSERT(Device_Query(false).select_max_compute_units(true).max_compute_units_selected());
    TS_ASSERT(Device_Query(false).select_max_work_item_dimensions(true).max_work_item_dimensions_selected());
    TS_ASSERT(Device_Query(false).select_max_work_group_size(true).max_work_group_size_selected());
    TS_ASSERT(Device_Query(false).select_max_work_item_sizes(true).max_work_item_sizes_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_char(true).preferred_vector_width_char_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_short(true).preferred_vector_width_short_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_int(true).preferred_vector_width_int_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_long(true).preferred_vector_width_long_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_float(true).preferred_vector_width_float_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_double(true).preferred_vector_width_double_selected());
    TS_ASSERT(Device_Query(false).select_max_clock_frequency(true).max_clock_frequency_selected());
    TS_ASSERT(Device_Query(false).select_address_bits(true).address_bits_selected());
    TS_ASSERT(Device_Query(false).select_max_read_image_args(true).max_read_image_args_selected());
    TS_ASSERT(Device_Query(false).select_max_write_image_args(true).max_write_image_args_selected());
    TS_ASSERT(Device_Query(false).select_max_mem_alloc_size(true).max_mem_alloc_size_selected());
    TS_ASSERT(Device_Query(false).select_image2d_max_width(true).image2d_max_width_selected());
    TS_ASSERT(Device_Query(false).select_image2d_max_height(true).image2d_max_height_selected());
    TS_ASSERT(Device_Query(false).select_image3d_max_width(true).image3d_max_width_selected());
    TS_ASSERT(Device_Query(false).select_image3d_max_height(true).image3d_max_height_selected());
    TS_ASSERT(Device_Query(false).select_image3d_max_depth(true).image3d_max_depth_selected());
    TS_ASSERT(Device_Query(false).select_image_support(true).image_support_selected());
    TS_ASSERT(Device_Query(false).select_max_parameter_size(true).max_parameter_size_selected());
    TS_ASSERT(Device_Query(false).select_max_samplers(true).max_samplers_selected());
    TS_ASSERT(Device_Query(false).select_mem_base_addr_align(true).mem_base_addr_align_selected());
    TS_ASSERT(Device_Query(false).select_min_data_type_align_size(true).min_data_type_align_size_selected());
    TS_ASSERT(Device_Query(false).select_single_fp_config(true).single_fp_config_selected());
    TS_ASSERT(Device_Query(false).select_global_mem_cache_type(true).global_mem_cache_type_selected());
    TS_ASSERT(Device_Query(false).select_global_mem_cacheline_size(true).global_mem_cacheline_size_selected());
    TS_ASSERT(Device_Query(false).select_global_mem_cache_size(true).global_mem_cache_size_selected());
    TS_ASSERT(Device_Query(false).select_global_mem_size(true).global_mem_size_selected());
    TS_ASSERT(Device_Query(false).select_max_constant_buffer_size(true).max_constant_buffer_size_selected());
    TS_ASSERT(Device_Query(false).select_max_constant_args(true).max_constant_args_selected());
    TS_ASSERT(Device_Query(false).select_local_mem_type(true).local_mem_type_selected());
    TS_ASSERT(Device_Query(false).select_local_mem_size(true).local_mem_size_selected());
    TS_ASSERT(Device_Query(false).select_error_correction_support(true).error_correction_support_selected());
    TS_ASSERT(Device_Query(false).select_profiling_timer_resolution(true).profiling_timer_resolution_selected());
    TS_ASSERT(Device_Query(false).select_endian_little(true).endian_little_selected());
    TS_ASSERT(Device_Query(false).select_available(true).available_selected());
    TS_ASSERT(Device_Query(false).select_compiler_available(true).compiler_available_selected());
    TS_ASSERT(Device_Query(false).select_execution_capabilities(true).execution_capabilities_selected());
    TS_ASSERT(Device_Query(false).select_queue_properties(true).queue_properties_selected());
    TS_ASSERT(Device_Query(false).select_name(true).name_selected());
    TS_ASSERT(Device_Query(false).select_vendor(true).vendor_selected());
    TS_ASSERT(Device_Query(false).select_driver_version(true).driver_version_selected());
    TS_ASSERT(Device_Query(false).select_profile(true).profile_selected());
    TS_ASSERT(Device_Query(false).select_version(true).version_selected());
    TS_ASSERT(Device_Query(false).select_extensions(true).extensions_selected());
    TS_ASSERT(Device_Query(false).select_platform_id(true).platform_id_selected());
    TS_ASSERT(Device_Query(false).select_double_fp_config(true).double_fp_config_selected());
    TS_ASSERT(Device_Query(false).select_preferred_vector_width_half(true).preferred_vector_width_half_selected());
    TS_ASSERT(Device_Query(false).select_host_unified_memory(true).host_unified_memory_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_char(true).native_vector_width_char_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_short(true).native_vector_width_short_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_int(true).native_vector_width_int_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_long(true).native_vector_width_long_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_float(true).native_vector_width_float_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_double(true).native_vector_width_double_selected());
    TS_ASSERT(Device_Query(false).select_native_vector_width_half(true).native_vector_width_half_selected());
    TS_ASSERT(Device_Query(false).select_opencl_c_version(true).opencl_c_version_selected());
    TS_ASSERT(Device_Query(false).select_linker_available(true).linker_available_selected());
    TS_ASSERT(Device_Query(false).select_built_in_kernels(true).built_in_kernels_selected());
    TS_ASSERT(Device_Query(false).select_image_max_buffer_size(true).image_max_buffer_size_selected());
    TS_ASSERT(Device_Query(false).select_image_max_array_size(true).image_max_array_size_selected());
    TS_ASSERT(Device_Query(false).select_parent_device_id(true).parent_device_id_selected());
    TS_ASSERT(Device_Query(false).select_partition_max_sub_devices(true).partition_max_sub_devices_selected());
    TS_ASSERT(Device_Query(false).select_partition_properties(true).partition_properties_selected());
    TS_ASSERT(Device_Query(false).select_partition_affinity_domain(true).partition_affinity_domain_selected());
    TS_ASSERT(Device_Query(false).select_partition_type(true).partition_type_selected());
    TS_ASSERT(Device_Query(false).select_reference_count(true).reference_count_selected());
    TS_ASSERT(Device_Query(false).select_preferred_interop_user_sync(true).preferred_interop_user_sync_selected());
    TS_ASSERT(Device_Query(false).select_printf_buffer_size(true).printf_buffer_size_selected());
    TS_ASSERT(Device_Query(false).select_image_pitch_alignment(true).image_pitch_alignment_selected());
    TS_ASSERT(Device_Query(false).select_image_base_address_alignment(true).image_base_address_alignment_selected());
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_all( )
  {
    Device_Query query(false);
    query.select_all();
    TS_ASSERT(query.id_selected());
    TS_ASSERT(query.type_selected());
    TS_ASSERT(query.vendor_id_selected());
    TS_ASSERT(query.max_compute_units_selected());
    TS_ASSERT(query.max_work_item_dimensions_selected());
    TS_ASSERT(query.max_work_group_size_selected());
    TS_ASSERT(query.max_work_item_sizes_selected());
    TS_ASSERT(query.preferred_vector_width_char_selected());
    TS_ASSERT(query.preferred_vector_width_short_selected());
    TS_ASSERT(query.preferred_vector_width_int_selected());
    TS_ASSERT(query.preferred_vector_width_long_selected());
    TS_ASSERT(query.preferred_vector_width_float_selected());
    TS_ASSERT(query.preferred_vector_width_double_selected());
    TS_ASSERT(query.max_clock_frequency_selected());
    TS_ASSERT(query.address_bits_selected());
    TS_ASSERT(query.max_read_image_args_selected());
    TS_ASSERT(query.max_write_image_args_selected());
    TS_ASSERT(query.max_mem_alloc_size_selected());
    TS_ASSERT(query.image2d_max_width_selected());
    TS_ASSERT(query.image2d_max_height_selected());
    TS_ASSERT(query.image3d_max_width_selected());
    TS_ASSERT(query.image3d_max_height_selected());
    TS_ASSERT(query.image3d_max_depth_selected());
    TS_ASSERT(query.image_support_selected());
    TS_ASSERT(query.max_parameter_size_selected());
    TS_ASSERT(query.max_samplers_selected());
    TS_ASSERT(query.mem_base_addr_align_selected());
    TS_ASSERT(query.min_data_type_align_size_selected());
    TS_ASSERT(query.single_fp_config_selected());
    TS_ASSERT(query.global_mem_cache_type_selected());
    TS_ASSERT(query.global_mem_cacheline_size_selected());
    TS_ASSERT(query.global_mem_cache_size_selected());
    TS_ASSERT(query.global_mem_size_selected());
    TS_ASSERT(query.max_constant_buffer_size_selected());
    TS_ASSERT(query.max_constant_args_selected());
    TS_ASSERT(query.local_mem_type_selected());
    TS_ASSERT(query.local_mem_size_selected());
    TS_ASSERT(query.error_correction_support_selected());
    TS_ASSERT(query.profiling_timer_resolution_selected());
    TS_ASSERT(query.endian_little_selected());
    TS_ASSERT(query.available_selected());
    TS_ASSERT(query.compiler_available_selected());
    TS_ASSERT(query.execution_capabilities_selected());
    TS_ASSERT(query.queue_properties_selected());
    TS_ASSERT(query.name_selected());
    TS_ASSERT(query.vendor_selected());
    TS_ASSERT(query.driver_version_selected());
    TS_ASSERT(query.profile_selected());
    TS_ASSERT(query.version_selected());
    TS_ASSERT(query.extensions_selected());
    TS_ASSERT(query.platform_id_selected());
    TS_ASSERT(query.double_fp_config_selected());
    TS_ASSERT(query.preferred_vector_width_half_selected());
    TS_ASSERT(query.host_unified_memory_selected());
    TS_ASSERT(query.native_vector_width_char_selected());
    TS_ASSERT(query.native_vector_width_short_selected());
    TS_ASSERT(query.native_vector_width_int_selected());
    TS_ASSERT(query.native_vector_width_long_selected());
    TS_ASSERT(query.native_vector_width_float_selected());
    TS_ASSERT(query.native_vector_width_double_selected());
    TS_ASSERT(query.native_vector_width_half_selected());
    TS_ASSERT(query.opencl_c_version_selected());
    TS_ASSERT(query.linker_available_selected());
    TS_ASSERT(query.built_in_kernels_selected());
    TS_ASSERT(query.image_max_buffer_size_selected());
    TS_ASSERT(query.image_max_array_size_selected());
    TS_ASSERT(query.parent_device_id_selected());
    TS_ASSERT(query.partition_max_sub_devices_selected());
    TS_ASSERT(query.partition_properties_selected());
    TS_ASSERT(query.partition_affinity_domain_selected());
    TS_ASSERT(query.partition_type_selected());
    TS_ASSERT(query.reference_count_selected());
    TS_ASSERT(query.preferred_interop_user_sync_selected());
    TS_ASSERT(query.printf_buffer_size_selected());
    TS_ASSERT(query.image_pitch_alignment_selected());
    TS_ASSERT(query.image_base_address_alignment_selected());
  }
  /** // doc: test_select_none() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_none( )
  {
    Device_Query query(true);
    query.select_none();
    TS_ASSERT(!query.id_selected());
    TS_ASSERT(!query.type_selected());
    TS_ASSERT(!query.vendor_id_selected());
    TS_ASSERT(!query.max_compute_units_selected());
    TS_ASSERT(!query.max_work_item_dimensions_selected());
    TS_ASSERT(!query.max_work_group_size_selected());
    TS_ASSERT(!query.max_work_item_sizes_selected());
    TS_ASSERT(!query.preferred_vector_width_char_selected());
    TS_ASSERT(!query.preferred_vector_width_short_selected());
    TS_ASSERT(!query.preferred_vector_width_int_selected());
    TS_ASSERT(!query.preferred_vector_width_long_selected());
    TS_ASSERT(!query.preferred_vector_width_float_selected());
    TS_ASSERT(!query.preferred_vector_width_double_selected());
    TS_ASSERT(!query.max_clock_frequency_selected());
    TS_ASSERT(!query.address_bits_selected());
    TS_ASSERT(!query.max_read_image_args_selected());
    TS_ASSERT(!query.max_write_image_args_selected());
    TS_ASSERT(!query.max_mem_alloc_size_selected());
    TS_ASSERT(!query.image2d_max_width_selected());
    TS_ASSERT(!query.image2d_max_height_selected());
    TS_ASSERT(!query.image3d_max_width_selected());
    TS_ASSERT(!query.image3d_max_height_selected());
    TS_ASSERT(!query.image3d_max_depth_selected());
    TS_ASSERT(!query.image_support_selected());
    TS_ASSERT(!query.max_parameter_size_selected());
    TS_ASSERT(!query.max_samplers_selected());
    TS_ASSERT(!query.mem_base_addr_align_selected());
    TS_ASSERT(!query.min_data_type_align_size_selected());
    TS_ASSERT(!query.single_fp_config_selected());
    TS_ASSERT(!query.global_mem_cache_type_selected());
    TS_ASSERT(!query.global_mem_cacheline_size_selected());
    TS_ASSERT(!query.global_mem_cache_size_selected());
    TS_ASSERT(!query.global_mem_size_selected());
    TS_ASSERT(!query.max_constant_buffer_size_selected());
    TS_ASSERT(!query.max_constant_args_selected());
    TS_ASSERT(!query.local_mem_type_selected());
    TS_ASSERT(!query.local_mem_size_selected());
    TS_ASSERT(!query.error_correction_support_selected());
    TS_ASSERT(!query.profiling_timer_resolution_selected());
    TS_ASSERT(!query.endian_little_selected());
    TS_ASSERT(!query.available_selected());
    TS_ASSERT(!query.compiler_available_selected());
    TS_ASSERT(!query.execution_capabilities_selected());
    TS_ASSERT(!query.queue_properties_selected());
    TS_ASSERT(!query.name_selected());
    TS_ASSERT(!query.vendor_selected());
    TS_ASSERT(!query.driver_version_selected());
    TS_ASSERT(!query.profile_selected());
    TS_ASSERT(!query.version_selected());
    TS_ASSERT(!query.extensions_selected());
    TS_ASSERT(!query.platform_id_selected());
    TS_ASSERT(!query.double_fp_config_selected());
    TS_ASSERT(!query.preferred_vector_width_half_selected());
    TS_ASSERT(!query.host_unified_memory_selected());
    TS_ASSERT(!query.native_vector_width_char_selected());
    TS_ASSERT(!query.native_vector_width_short_selected());
    TS_ASSERT(!query.native_vector_width_int_selected());
    TS_ASSERT(!query.native_vector_width_long_selected());
    TS_ASSERT(!query.native_vector_width_float_selected());
    TS_ASSERT(!query.native_vector_width_double_selected());
    TS_ASSERT(!query.native_vector_width_half_selected());
    TS_ASSERT(!query.opencl_c_version_selected());
    TS_ASSERT(!query.linker_available_selected());
    TS_ASSERT(!query.built_in_kernels_selected());
    TS_ASSERT(!query.image_max_buffer_size_selected());
    TS_ASSERT(!query.image_max_array_size_selected());
    TS_ASSERT(!query.parent_device_id_selected());
    TS_ASSERT(!query.partition_max_sub_devices_selected());
    TS_ASSERT(!query.partition_properties_selected());
    TS_ASSERT(!query.partition_affinity_domain_selected());
    TS_ASSERT(!query.partition_type_selected());
    TS_ASSERT(!query.reference_count_selected());
    TS_ASSERT(!query.preferred_interop_user_sync_selected());
    TS_ASSERT(!query.printf_buffer_size_selected());
    TS_ASSERT(!query.image_pitch_alignment_selected());
    TS_ASSERT(!query.image_base_address_alignment_selected());
  }
  /** // doc: test_restrict_to_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_default( )
  {
    TS_ASSERT(Device_Query(true).select_default() == Device_Query());
    TS_ASSERT(Device_Query(false).select_default() == Device_Query());
  }
  /** // doc: test_restrict_to_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_restrict_to_1_2( )
  {
    Device_Query a;
    Device_Query b;

    TS_ASSERT((a == b));
    a.restrict_to(1,2);
    TS_ASSERT((a == b));
  }
  /** // doc: test_restrict_to_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_restrict_to_1_1( )
  {
    Device_Query a;
    Device_Query b;

    TS_ASSERT((a == b));
    a.restrict_to(1,1);
    TS_ASSERT((a != b));

    // Make sure these are unselected
    TS_ASSERT(!a.double_fp_config_selected());
    TS_ASSERT(!a.linker_available_selected());
    TS_ASSERT(!a.built_in_kernels_selected());
    TS_ASSERT(!a.image_max_buffer_size_selected());
    TS_ASSERT(!a.image_max_array_size_selected());
    TS_ASSERT(!a.parent_device_id_selected());
    TS_ASSERT(!a.partition_max_sub_devices_selected());
    TS_ASSERT(!a.partition_properties_selected());
    TS_ASSERT(!a.partition_affinity_domain_selected());
    TS_ASSERT(!a.partition_type_selected());
    TS_ASSERT(!a.reference_count_selected());
    TS_ASSERT(!a.preferred_interop_user_sync_selected());
    TS_ASSERT(!a.printf_buffer_size_selected());
    TS_ASSERT(!a.image_pitch_alignment_selected());
    TS_ASSERT(!a.image_base_address_alignment_selected());

    // Make sure ONLY these were unselected
    a.select_double_fp_config();
    a.select_linker_available();
    a.select_built_in_kernels();
    a.select_image_max_buffer_size();
    a.select_image_max_array_size();
    a.select_parent_device_id();
    a.select_partition_max_sub_devices();
    a.select_partition_properties();
    a.select_partition_affinity_domain();
    a.select_partition_type();
    a.select_reference_count();
    a.select_preferred_interop_user_sync();
    a.select_printf_buffer_size();
    a.select_image_pitch_alignment();
    a.select_image_base_address_alignment();

    TS_ASSERT((a == b));
  }
  /** // doc: test_restrict_to_1_0() {{{
   * \todo Write documentation
   */ // }}}
  void test_restrict_to_1_0( )
  {
    Device_Query a;
    Device_Query b;

    TS_ASSERT((a == b));
    a.restrict_to(1,0);
    TS_ASSERT((a != b));

    // Make sure these are unselected
    TS_ASSERT(!a.preferred_vector_width_half_selected());
    TS_ASSERT(!a.host_unified_memory_selected());
    TS_ASSERT(!a.native_vector_width_char_selected());
    TS_ASSERT(!a.native_vector_width_short_selected());
    TS_ASSERT(!a.native_vector_width_int_selected());
    TS_ASSERT(!a.native_vector_width_long_selected());
    TS_ASSERT(!a.native_vector_width_float_selected());
    TS_ASSERT(!a.native_vector_width_double_selected());
    TS_ASSERT(!a.native_vector_width_half_selected());
    TS_ASSERT(!a.opencl_c_version_selected());
    TS_ASSERT(!a.double_fp_config_selected());
    TS_ASSERT(!a.linker_available_selected());
    TS_ASSERT(!a.built_in_kernels_selected());
    TS_ASSERT(!a.image_max_buffer_size_selected());
    TS_ASSERT(!a.image_max_array_size_selected());
    TS_ASSERT(!a.parent_device_id_selected());
    TS_ASSERT(!a.partition_max_sub_devices_selected());
    TS_ASSERT(!a.partition_properties_selected());
    TS_ASSERT(!a.partition_affinity_domain_selected());
    TS_ASSERT(!a.partition_type_selected());
    TS_ASSERT(!a.reference_count_selected());
    TS_ASSERT(!a.preferred_interop_user_sync_selected());
    TS_ASSERT(!a.printf_buffer_size_selected());
    TS_ASSERT(!a.image_pitch_alignment_selected());
    TS_ASSERT(!a.image_base_address_alignment_selected());

    // Make sure ONLY these were unselected
    a.select_preferred_vector_width_half();
    a.select_host_unified_memory();
    a.select_native_vector_width_char();
    a.select_native_vector_width_short();
    a.select_native_vector_width_int();
    a.select_native_vector_width_long();
    a.select_native_vector_width_float();
    a.select_native_vector_width_double();
    a.select_native_vector_width_half();
    a.select_opencl_c_version();
    a.select_double_fp_config();
    a.select_linker_available();
    a.select_built_in_kernels();
    a.select_image_max_buffer_size();
    a.select_image_max_array_size();
    a.select_parent_device_id();
    a.select_partition_max_sub_devices();
    a.select_partition_properties();
    a.select_partition_affinity_domain();
    a.select_partition_type();
    a.select_reference_count();
    a.select_preferred_interop_user_sync();
    a.select_printf_buffer_size();
    a.select_image_pitch_alignment();
    a.select_image_base_address_alignment();

    TS_ASSERT((a == b));
  }
  /** // doc: test_eq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_1( )
  {
    TS_ASSERT((Device_Query() == Device_Query()));
    TS_ASSERT((Device_Query(true) == Device_Query(true)));
    TS_ASSERT((Device_Query(false) == Device_Query(false)));
  }
  /** // doc: test_eq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_2( )
  {
    TS_ASSERT(!(Device_Query(true).select_id(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_type(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_vendor_id(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_compute_units(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_work_item_dimensions(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_work_group_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_work_item_sizes(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_char(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_int(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_short(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_long(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_float(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_double(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_clock_frequency(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_address_bits(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_read_image_args(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_write_image_args(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_mem_alloc_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image2d_max_width(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image2d_max_height(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image3d_max_width(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image3d_max_height(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image3d_max_depth(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image_support(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_parameter_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_samplers(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_mem_base_addr_align(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_min_data_type_align_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_single_fp_config(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_global_mem_cache_type(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_global_mem_cacheline_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_global_mem_cache_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_global_mem_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_constant_buffer_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_max_constant_args(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_local_mem_type(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_local_mem_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_error_correction_support(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_profiling_timer_resolution(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_endian_little(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_available(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_id(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_compiler_available(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_queue_properties(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_name(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_vendor(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_driver_version(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_extensions(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_platform_id(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_double_fp_config(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_vector_width_half(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_host_unified_memory(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_char(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_short(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_int(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_long(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_float(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_double(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_native_vector_width_half(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_opencl_c_version(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_linker_available(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_built_in_kernels(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image_max_buffer_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image_max_array_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_parent_device_id(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_partition_max_sub_devices(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_partition_properties(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_partition_affinity_domain(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_partition_type(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_reference_count(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_preferred_interop_user_sync(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_printf_buffer_size(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image_pitch_alignment(false) == Device_Query(true)));
    TS_ASSERT(!(Device_Query(true).select_image_base_address_alignment(false) == Device_Query(true)));
  }
  /** // doc: test_neq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_1( )
  {
    TS_ASSERT(!(Device_Query() != Device_Query()));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op( )
  {
    TS_ASSERT((Device_Query(true).select_id(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_type(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_vendor_id(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_compute_units(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_work_item_dimensions(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_work_group_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_work_item_sizes(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_char(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_int(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_short(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_long(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_float(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_double(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_clock_frequency(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_address_bits(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_read_image_args(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_write_image_args(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_mem_alloc_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image2d_max_width(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image2d_max_height(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image3d_max_width(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image3d_max_height(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image3d_max_depth(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image_support(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_parameter_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_samplers(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_mem_base_addr_align(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_min_data_type_align_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_single_fp_config(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_global_mem_cache_type(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_global_mem_cacheline_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_global_mem_cache_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_global_mem_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_constant_buffer_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_max_constant_args(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_local_mem_type(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_local_mem_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_error_correction_support(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_profiling_timer_resolution(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_endian_little(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_available(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_id(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_compiler_available(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_queue_properties(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_name(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_vendor(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_driver_version(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_extensions(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_platform_id(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_double_fp_config(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_vector_width_half(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_host_unified_memory(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_char(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_short(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_int(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_long(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_float(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_double(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_native_vector_width_half(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_opencl_c_version(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_linker_available(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_built_in_kernels(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image_max_buffer_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image_max_array_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_parent_device_id(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_partition_max_sub_devices(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_partition_properties(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_partition_affinity_domain(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_partition_type(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_reference_count(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_preferred_interop_user_sync(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_printf_buffer_size(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image_pitch_alignment(false) != Device_Query(true)));
    TS_ASSERT((Device_Query(true).select_image_base_address_alignment(false) != Device_Query(true)));
  }
};

#endif /* DIMBO_CLINFO_DEVICE_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
