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

// dimbo/test/unit/dimbo/cl/device_query.t.h

/** // doc: dimbo/test/unit/dimbo/cl/device_query.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/device_query.t.h
 * \brief Unit tests for Dimbo::Cl::Device_Query
 */ // }}}
#ifndef DIMBO_CL_DEVICE_QUERY_T_H_INCLUDED
#define DIMBO_CL_DEVICE_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/device_query.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Cl { class Device_Query_TestSuite; } }

/** // doc: class Dimbo::Cl::Device_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Device_Query_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_values() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_values( )
  {
    Device_Query q;
    TS_ASSERT(q.id_selected());
    TS_ASSERT(q.type_selected());
    TS_ASSERT(q.vendor_id_selected());
    TS_ASSERT(q.max_compute_units_selected());
    TS_ASSERT(q.max_work_item_dimensions_selected());
    TS_ASSERT(q.max_work_group_size_selected());
    TS_ASSERT(q.max_work_item_sizes_selected());
    TS_ASSERT(q.preferred_vector_width_char_selected());
    TS_ASSERT(q.preferred_vector_width_short_selected());
    TS_ASSERT(q.preferred_vector_width_int_selected());
    TS_ASSERT(q.preferred_vector_width_long_selected());
    TS_ASSERT(q.preferred_vector_width_float_selected());
    TS_ASSERT(q.preferred_vector_width_double_selected());
    TS_ASSERT(q.max_clock_frequency_selected());
    TS_ASSERT(q.address_bits_selected());
    TS_ASSERT(q.max_read_image_args_selected());
    TS_ASSERT(q.max_write_image_args_selected());
    TS_ASSERT(q.max_mem_alloc_size_selected());
    TS_ASSERT(q.image2d_max_width_selected());
    TS_ASSERT(q.image2d_max_height_selected());
    TS_ASSERT(q.image3d_max_width_selected());
    TS_ASSERT(q.image3d_max_height_selected());
    TS_ASSERT(q.image3d_max_depth_selected());
    TS_ASSERT(q.image_support_selected());
    TS_ASSERT(q.max_parameter_size_selected());
    TS_ASSERT(q.max_samplers_selected());
    TS_ASSERT(q.mem_base_addr_align_selected());
    TS_ASSERT(q.min_data_type_align_size_selected());
    TS_ASSERT(q.single_fp_config_selected());
    TS_ASSERT(q.global_mem_cache_type_selected());
    TS_ASSERT(q.global_mem_cacheline_size_selected());
    TS_ASSERT(q.global_mem_cache_size_selected());
    TS_ASSERT(q.global_mem_size_selected());
    TS_ASSERT(q.max_constant_buffer_size_selected());
    TS_ASSERT(q.max_constant_args_selected());
    TS_ASSERT(q.local_mem_type_selected());
    TS_ASSERT(q.local_mem_size_selected());
    TS_ASSERT(q.error_correction_support_selected());
    TS_ASSERT(q.profiling_timer_resolution_selected());
    TS_ASSERT(q.endian_little_selected());
    TS_ASSERT(q.available_selected());
    TS_ASSERT(q.compiler_available_selected());
    TS_ASSERT(q.execution_capabilities_selected());
    TS_ASSERT(q.queue_properties_selected());
    TS_ASSERT(q.name_selected());
    TS_ASSERT(q.vendor_selected());
    TS_ASSERT(q.driver_version_selected());
    TS_ASSERT(q.profile_selected());
    TS_ASSERT(q.version_selected());
    TS_ASSERT(q.extensions_selected());
    TS_ASSERT(q.platform_id_selected());
    TS_ASSERT(q.double_fp_config_selected());
    TS_ASSERT(q.preferred_vector_width_half_selected());
    TS_ASSERT(q.host_unified_memory_selected());
    TS_ASSERT(q.native_vector_width_char_selected());
    TS_ASSERT(q.native_vector_width_short_selected());
    TS_ASSERT(q.native_vector_width_int_selected());
    TS_ASSERT(q.native_vector_width_long_selected());
    TS_ASSERT(q.native_vector_width_float_selected());
    TS_ASSERT(q.native_vector_width_double_selected());
    TS_ASSERT(q.native_vector_width_half_selected());
    TS_ASSERT(q.opencl_c_version_selected());
    TS_ASSERT(q.linker_available_selected());
    TS_ASSERT(q.built_in_kernels_selected());
    TS_ASSERT(q.image_max_buffer_size_selected());
    TS_ASSERT(q.image_max_array_size_selected());
    TS_ASSERT(q.parent_device_id_selected());
    TS_ASSERT(q.partition_max_sub_devices_selected());
    TS_ASSERT(q.partition_properties_selected());
    TS_ASSERT(q.partition_affinity_domain_selected());
    TS_ASSERT(q.partition_type_selected());
    TS_ASSERT(q.reference_count_selected());
    TS_ASSERT(q.preferred_interop_user_sync_selected());
    TS_ASSERT(q.printf_buffer_size_selected());
    TS_ASSERT(q.image_pitch_alignment_selected());
    TS_ASSERT(q.image_base_address_alignment_selected());
  }
  /** // doc: test_select_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_id( )
  {
    Device_Query q;
    q.select_id(false);
    TS_ASSERT(!q.id_selected());
    q.select_id(true);
    TS_ASSERT(q.id_selected());
  }
  /** // doc: test_select_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_type( )
  {
    Device_Query q;
    q.select_type(false);
    TS_ASSERT(!q.type_selected());
    q.select_type(true);
    TS_ASSERT(q.type_selected());
  }
  /** // doc: test_select_vendor_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_vendor_id( )
  {
    Device_Query q;
    q.select_vendor_id(false);
    TS_ASSERT(!q.vendor_id_selected());
    q.select_vendor_id(true);
    TS_ASSERT(q.vendor_id_selected());
  }
  /** // doc: test_select_max_compute_units() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_compute_units( )
  {
    Device_Query q;
    q.select_max_compute_units(false);
    TS_ASSERT(!q.max_compute_units_selected());
    q.select_max_compute_units(true);
    TS_ASSERT(q.max_compute_units_selected());
  }
  /** // doc: test_select_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_work_item_dimensions( )
  {
    Device_Query q;
    q.select_max_work_item_dimensions(false);
    TS_ASSERT(!q.max_work_item_dimensions_selected());
    q.select_max_work_item_dimensions(true);
    TS_ASSERT(q.max_work_item_dimensions_selected());
  }
  /** // doc: test_select_max_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_work_group_size( )
  {
    Device_Query q;
    q.select_max_work_group_size(false);
    TS_ASSERT(!q.max_work_group_size_selected());
    q.select_max_work_group_size(true);
    TS_ASSERT(q.max_work_group_size_selected());
  }
  /** // doc: test_select_max_work_item_sizes() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_work_item_sizes( )
  {
    Device_Query q;
    q.select_max_work_item_sizes(false);
    TS_ASSERT(!q.max_work_item_sizes_selected());
    q.select_max_work_item_sizes(true);
    TS_ASSERT(q.max_work_item_sizes_selected());
  }
  /** // doc: test_select_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_char( )
  {
    Device_Query q;
    q.select_preferred_vector_width_char(false);
    TS_ASSERT(!q.preferred_vector_width_char_selected());
    q.select_preferred_vector_width_char(true);
    TS_ASSERT(q.preferred_vector_width_char_selected());
  }
  /** // doc: test_select_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_short( )
  {
    Device_Query q;
    q.select_preferred_vector_width_short(false);
    TS_ASSERT(!q.preferred_vector_width_short_selected());
    q.select_preferred_vector_width_short(true);
    TS_ASSERT(q.preferred_vector_width_short_selected());
  }
  /** // doc: test_select_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_int( )
  {
    Device_Query q;
    q.select_preferred_vector_width_int(false);
    TS_ASSERT(!q.preferred_vector_width_int_selected());
    q.select_preferred_vector_width_int(true);
    TS_ASSERT(q.preferred_vector_width_int_selected());
  }
  /** // doc: test_select_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_long( )
  {
    Device_Query q;
    q.select_preferred_vector_width_long(false);
    TS_ASSERT(!q.preferred_vector_width_long_selected());
    q.select_preferred_vector_width_long(true);
    TS_ASSERT(q.preferred_vector_width_long_selected());
  }
  /** // doc: test_select_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_float( )
  {
    Device_Query q;
    q.select_preferred_vector_width_float(false);
    TS_ASSERT(!q.preferred_vector_width_float_selected());
    q.select_preferred_vector_width_float(true);
    TS_ASSERT(q.preferred_vector_width_float_selected());
  }
  /** // doc: test_select_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_double( )
  {
    Device_Query q;
    q.select_preferred_vector_width_double(false);
    TS_ASSERT(!q.preferred_vector_width_double_selected());
    q.select_preferred_vector_width_double(true);
    TS_ASSERT(q.preferred_vector_width_double_selected());
  }
  /** // doc: test_select_max_clock_frequency() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_clock_frequency( )
  {
    Device_Query q;
    q.select_max_clock_frequency(false);
    TS_ASSERT(!q.max_clock_frequency_selected());
    q.select_max_clock_frequency(true);
    TS_ASSERT(q.max_clock_frequency_selected());
  }
  /** // doc: test_select_address_bits() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_address_bits( )
  {
    Device_Query q;
    q.select_address_bits(false);
    TS_ASSERT(!q.address_bits_selected());
    q.select_address_bits(true);
    TS_ASSERT(q.address_bits_selected());
  }
  /** // doc: test_select_max_read_image_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_read_image_args( )
  {
    Device_Query q;
    q.select_max_read_image_args(false);
    TS_ASSERT(!q.max_read_image_args_selected());
    q.select_max_read_image_args(true);
    TS_ASSERT(q.max_read_image_args_selected());
  }
  /** // doc: test_select_max_write_image_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_write_image_args( )
  {
    Device_Query q;
    q.select_max_write_image_args(false);
    TS_ASSERT(!q.max_write_image_args_selected());
    q.select_max_write_image_args(true);
    TS_ASSERT(q.max_write_image_args_selected());
  }
  /** // doc: test_select_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_mem_alloc_size( )
  {
    Device_Query q;
    q.select_max_mem_alloc_size(false);
    TS_ASSERT(!q.max_mem_alloc_size_selected());
    q.select_max_mem_alloc_size(true);
    TS_ASSERT(q.max_mem_alloc_size_selected());
  }
  /** // doc: test_select_image2d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image2d_max_width( )
  {
    Device_Query q;
    q.select_image2d_max_width(false);
    TS_ASSERT(!q.image2d_max_width_selected());
    q.select_image2d_max_width(true);
    TS_ASSERT(q.image2d_max_width_selected());
  }
  /** // doc: test_select_image2d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image2d_max_height( )
  {
    Device_Query q;
    q.select_image2d_max_height(false);
    TS_ASSERT(!q.image2d_max_height_selected());
    q.select_image2d_max_height(true);
    TS_ASSERT(q.image2d_max_height_selected());
  }
  /** // doc: test_select_image3d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image3d_max_width( )
  {
    Device_Query q;
    q.select_image3d_max_width(false);
    TS_ASSERT(!q.image3d_max_width_selected());
    q.select_image3d_max_width(true);
    TS_ASSERT(q.image3d_max_width_selected());
  }
  /** // doc: test_select_image3d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image3d_max_height( )
  {
    Device_Query q;
    q.select_image3d_max_height(false);
    TS_ASSERT(!q.image3d_max_height_selected());
    q.select_image3d_max_height(true);
    TS_ASSERT(q.image3d_max_height_selected());
  }
  /** // doc: test_select_image3d_max_depth() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image3d_max_depth( )
  {
    Device_Query q;
    q.select_image3d_max_depth(false);
    TS_ASSERT(!q.image3d_max_depth_selected());
    q.select_image3d_max_depth(true);
    TS_ASSERT(q.image3d_max_depth_selected());
  }
  /** // doc: test_select_image_support() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image_support( )
  {
    Device_Query q;
    q.select_image_support(false);
    TS_ASSERT(!q.image_support_selected());
    q.select_image_support(true);
    TS_ASSERT(q.image_support_selected());
  }
  /** // doc: test_select_max_parameter_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_parameter_size( )
  {
    Device_Query q;
    q.select_max_parameter_size(false);
    TS_ASSERT(!q.max_parameter_size_selected());
    q.select_max_parameter_size(true);
    TS_ASSERT(q.max_parameter_size_selected());
  }
  /** // doc: test_select_max_samplers() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_samplers( )
  {
    Device_Query q;
    q.select_max_samplers(false);
    TS_ASSERT(!q.max_samplers_selected());
    q.select_max_samplers(true);
    TS_ASSERT(q.max_samplers_selected());
  }
  /** // doc: test_select_mem_base_addr_align() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_mem_base_addr_align( )
  {
    Device_Query q;
    q.select_mem_base_addr_align(false);
    TS_ASSERT(!q.mem_base_addr_align_selected());
    q.select_mem_base_addr_align(true);
    TS_ASSERT(q.mem_base_addr_align_selected());
  }
  /** // doc: test_select_min_data_type_align_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_min_data_type_align_size( )
  {
    Device_Query q;
    q.select_min_data_type_align_size(false);
    TS_ASSERT(!q.min_data_type_align_size_selected());
    q.select_min_data_type_align_size(true);
    TS_ASSERT(q.min_data_type_align_size_selected());
  }
  /** // doc: test_select_single_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_single_fp_config( )
  {
    Device_Query q;
    q.select_single_fp_config(false);
    TS_ASSERT(!q.single_fp_config_selected());
    q.select_single_fp_config(true);
    TS_ASSERT(q.single_fp_config_selected());
  }
  /** // doc: test_select_global_mem_cache_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_global_mem_cache_type( )
  {
    Device_Query q;
    q.select_global_mem_cache_type(false);
    TS_ASSERT(!q.global_mem_cache_type_selected());
    q.select_global_mem_cache_type(true);
    TS_ASSERT(q.global_mem_cache_type_selected());
  }
  /** // doc: test_select_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_global_mem_cacheline_size( )
  {
    Device_Query q;
    q.select_global_mem_cacheline_size(false);
    TS_ASSERT(!q.global_mem_cacheline_size_selected());
    q.select_global_mem_cacheline_size(true);
    TS_ASSERT(q.global_mem_cacheline_size_selected());
  }
  /** // doc: test_select_global_mem_cache_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_global_mem_cache_size( )
  {
    Device_Query q;
    q.select_global_mem_cache_size(false);
    TS_ASSERT(!q.global_mem_cache_size_selected());
    q.select_global_mem_cache_size(true);
    TS_ASSERT(q.global_mem_cache_size_selected());
  }
  /** // doc: test_select_global_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_global_mem_size( )
  {
    Device_Query q;
    q.select_global_mem_size(false);
    TS_ASSERT(!q.global_mem_size_selected());
    q.select_global_mem_size(true);
    TS_ASSERT(q.global_mem_size_selected());
  }
  /** // doc: test_select_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_constant_buffer_size( )
  {
    Device_Query q;
    q.select_max_constant_buffer_size(false);
    TS_ASSERT(!q.max_constant_buffer_size_selected());
    q.select_max_constant_buffer_size(true);
    TS_ASSERT(q.max_constant_buffer_size_selected());
  }
  /** // doc: test_select_max_constant_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_max_constant_args( )
  {
    Device_Query q;
    q.select_max_constant_args(false);
    TS_ASSERT(!q.max_constant_args_selected());
    q.select_max_constant_args(true);
    TS_ASSERT(q.max_constant_args_selected());
  }
  /** // doc: test_select_local_mem_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_local_mem_type( )
  {
    Device_Query q;
    q.select_local_mem_type(false);
    TS_ASSERT(!q.local_mem_type_selected());
    q.select_local_mem_type(true);
    TS_ASSERT(q.local_mem_type_selected());
  }
  /** // doc: test_select_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_local_mem_size( )
  {
    Device_Query q;
    q.select_local_mem_size(false);
    TS_ASSERT(!q.local_mem_size_selected());
    q.select_local_mem_size(true);
    TS_ASSERT(q.local_mem_size_selected());
  }
  /** // doc: test_select_error_correction_support() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_error_correction_support( )
  {
    Device_Query q;
    q.select_error_correction_support(false);
    TS_ASSERT(!q.error_correction_support_selected());
    q.select_error_correction_support(true);
    TS_ASSERT(q.error_correction_support_selected());
  }
  /** // doc: test_select_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_profiling_timer_resolution( )
  {
    Device_Query q;
    q.select_profiling_timer_resolution(false);
    TS_ASSERT(!q.profiling_timer_resolution_selected());
    q.select_profiling_timer_resolution(true);
    TS_ASSERT(q.profiling_timer_resolution_selected());
  }
  /** // doc: test_select_endian_little() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_endian_little( )
  {
    Device_Query q;
    q.select_endian_little(false);
    TS_ASSERT(!q.endian_little_selected());
    q.select_endian_little(true);
    TS_ASSERT(q.endian_little_selected());
  }
  /** // doc: test_select_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_available( )
  {
    Device_Query q;
    q.select_available(false);
    TS_ASSERT(!q.available_selected());
    q.select_available(true);
    TS_ASSERT(q.available_selected());
  }
  /** // doc: test_select_compiler_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_compiler_available( )
  {
    Device_Query q;
    q.select_compiler_available(false);
    TS_ASSERT(!q.compiler_available_selected());
    q.select_compiler_available(true);
    TS_ASSERT(q.compiler_available_selected());
  }
  /** // doc: test_select_execution_capabilities() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_execution_capabilities( )
  {
    Device_Query q;
    q.select_execution_capabilities(false);
    TS_ASSERT(!q.execution_capabilities_selected());
    q.select_execution_capabilities(true);
    TS_ASSERT(q.execution_capabilities_selected());
  }
  /** // doc: test_select_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_queue_properties( )
  {
    Device_Query q;
    q.select_queue_properties(false);
    TS_ASSERT(!q.queue_properties_selected());
    q.select_queue_properties(true);
    TS_ASSERT(q.queue_properties_selected());
  }
  /** // doc: test_select_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_name( )
  {
    Device_Query q;
    q.select_name(false);
    TS_ASSERT(!q.name_selected());
    q.select_name(true);
    TS_ASSERT(q.name_selected());
  }
  /** // doc: test_select_vendor() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_vendor( )
  {
    Device_Query q;
    q.select_vendor(false);
    TS_ASSERT(!q.vendor_selected());
    q.select_vendor(true);
    TS_ASSERT(q.vendor_selected());
  }
  /** // doc: test_select_driver_version() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_driver_version( )
  {
    Device_Query q;
    q.select_driver_version(false);
    TS_ASSERT(!q.driver_version_selected());
    q.select_driver_version(true);
    TS_ASSERT(q.driver_version_selected());
  }
  /** // doc: test_select_profile() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_profile( )
  {
    Device_Query q;
    q.select_profile(false);
    TS_ASSERT(!q.profile_selected());
    q.select_profile(true);
    TS_ASSERT(q.profile_selected());
  }
  /** // doc: test_select_version() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_version( )
  {
    Device_Query q;
    q.select_version(false);
    TS_ASSERT(!q.version_selected());
    q.select_version(true);
    TS_ASSERT(q.version_selected());
  }
  /** // doc: test_select_extensions() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_extensions( )
  {
    Device_Query q;
    q.select_extensions(false);
    TS_ASSERT(!q.extensions_selected());
    q.select_extensions(true);
    TS_ASSERT(q.extensions_selected());
  }
  /** // doc: test_select_platform_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_platform_id( )
  {
    Device_Query q;
    q.select_platform_id(false);
    TS_ASSERT(!q.platform_id_selected());
    q.select_platform_id(true);
    TS_ASSERT(q.platform_id_selected());
  }
  /** // doc: test_select_double_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_double_fp_config( )
  {
    Device_Query q;
    q.select_double_fp_config(false);
    TS_ASSERT(!q.double_fp_config_selected());
    q.select_double_fp_config(true);
    TS_ASSERT(q.double_fp_config_selected());
  }
  /** // doc: test_select_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_vector_width_half( )
  {
    Device_Query q;
    q.select_preferred_vector_width_half(false);
    TS_ASSERT(!q.preferred_vector_width_half_selected());
    q.select_preferred_vector_width_half(true);
    TS_ASSERT(q.preferred_vector_width_half_selected());
  }
  /** // doc: test_select_host_unified_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_host_unified_memory( )
  {
    Device_Query q;
    q.select_host_unified_memory(false);
    TS_ASSERT(!q.host_unified_memory_selected());
    q.select_host_unified_memory(true);
    TS_ASSERT(q.host_unified_memory_selected());
  }
  /** // doc: test_select_native_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_char( )
  {
    Device_Query q;
    q.select_native_vector_width_char(false);
    TS_ASSERT(!q.native_vector_width_char_selected());
    q.select_native_vector_width_char(true);
    TS_ASSERT(q.native_vector_width_char_selected());
  }
  /** // doc: test_select_native_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_short( )
  {
    Device_Query q;
    q.select_native_vector_width_short(false);
    TS_ASSERT(!q.native_vector_width_short_selected());
    q.select_native_vector_width_short(true);
    TS_ASSERT(q.native_vector_width_short_selected());
  }
  /** // doc: test_select_native_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_int( )
  {
    Device_Query q;
    q.select_native_vector_width_int(false);
    TS_ASSERT(!q.native_vector_width_int_selected());
    q.select_native_vector_width_int(true);
    TS_ASSERT(q.native_vector_width_int_selected());
  }
  /** // doc: test_select_native_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_long( )
  {
    Device_Query q;
    q.select_native_vector_width_long(false);
    TS_ASSERT(!q.native_vector_width_long_selected());
    q.select_native_vector_width_long(true);
    TS_ASSERT(q.native_vector_width_long_selected());
  }
  /** // doc: test_select_native_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_float( )
  {
    Device_Query q;
    q.select_native_vector_width_float(false);
    TS_ASSERT(!q.native_vector_width_float_selected());
    q.select_native_vector_width_float(true);
    TS_ASSERT(q.native_vector_width_float_selected());
  }
  /** // doc: test_select_native_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_double( )
  {
    Device_Query q;
    q.select_native_vector_width_double(false);
    TS_ASSERT(!q.native_vector_width_double_selected());
    q.select_native_vector_width_double(true);
    TS_ASSERT(q.native_vector_width_double_selected());
  }
  /** // doc: test_select_native_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_native_vector_width_half( )
  {
    Device_Query q;
    q.select_native_vector_width_half(false);
    TS_ASSERT(!q.native_vector_width_half_selected());
    q.select_native_vector_width_half(true);
    TS_ASSERT(q.native_vector_width_half_selected());
  }
  /** // doc: test_select_opencl_c_version() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_opencl_c_version( )
  {
    Device_Query q;
    q.select_opencl_c_version(false);
    TS_ASSERT(!q.opencl_c_version_selected());
    q.select_opencl_c_version(true);
    TS_ASSERT(q.opencl_c_version_selected());
  }
  /** // doc: test_select_linker_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_linker_available( )
  {
    Device_Query q;
    q.select_linker_available(false);
    TS_ASSERT(!q.linker_available_selected());
    q.select_linker_available(true);
    TS_ASSERT(q.linker_available_selected());
  }
  /** // doc: test_select_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_built_in_kernels( )
  {
    Device_Query q;
    q.select_built_in_kernels(false);
    TS_ASSERT(!q.built_in_kernels_selected());
    q.select_built_in_kernels(true);
    TS_ASSERT(q.built_in_kernels_selected());
  }
  /** // doc: test_select_image_max_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image_max_buffer_size( )
  {
    Device_Query q;
    q.select_image_max_buffer_size(false);
    TS_ASSERT(!q.image_max_buffer_size_selected());
    q.select_image_max_buffer_size(true);
    TS_ASSERT(q.image_max_buffer_size_selected());
  }
  /** // doc: test_select_image_max_array_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image_max_array_size( )
  {
    Device_Query q;
    q.select_image_max_array_size(false);
    TS_ASSERT(!q.image_max_array_size_selected());
    q.select_image_max_array_size(true);
    TS_ASSERT(q.image_max_array_size_selected());
  }
  /** // doc: test_select_parent_device_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_parent_device_id( )
  {
    Device_Query q;
    q.select_parent_device_id(false);
    TS_ASSERT(!q.parent_device_id_selected());
    q.select_parent_device_id(true);
    TS_ASSERT(q.parent_device_id_selected());
  }
  /** // doc: test_select_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_partition_max_sub_devices( )
  {
    Device_Query q;
    q.select_partition_max_sub_devices(false);
    TS_ASSERT(!q.partition_max_sub_devices_selected());
    q.select_partition_max_sub_devices(true);
    TS_ASSERT(q.partition_max_sub_devices_selected());
  }
  /** // doc: test_select_partition_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_partition_properties( )
  {
    Device_Query q;
    q.select_partition_properties(false);
    TS_ASSERT(!q.partition_properties_selected());
    q.select_partition_properties(true);
    TS_ASSERT(q.partition_properties_selected());
  }
  /** // doc: test_select_partition_affinity_domain() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_partition_affinity_domain( )
  {
    Device_Query q;
    q.select_partition_affinity_domain(false);
    TS_ASSERT(!q.partition_affinity_domain_selected());
    q.select_partition_affinity_domain(true);
    TS_ASSERT(q.partition_affinity_domain_selected());
  }
  /** // doc: test_select_partition_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_partition_type( )
  {
    Device_Query q;
    q.select_partition_type(false);
    TS_ASSERT(!q.partition_type_selected());
    q.select_partition_type(true);
    TS_ASSERT(q.partition_type_selected());
  }
  /** // doc: test_select_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_reference_count( )
  {
    Device_Query q;
    q.select_reference_count(false);
    TS_ASSERT(!q.reference_count_selected());
    q.select_reference_count(true);
    TS_ASSERT(q.reference_count_selected());
  }
  /** // doc: test_select_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_preferred_interop_user_sync( )
  {
    Device_Query q;
    q.select_preferred_interop_user_sync(false);
    TS_ASSERT(!q.preferred_interop_user_sync_selected());
    q.select_preferred_interop_user_sync(true);
    TS_ASSERT(q.preferred_interop_user_sync_selected());
  }
  /** // doc: test_select_printf_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_printf_buffer_size( )
  {
    Device_Query q;
    q.select_printf_buffer_size(false);
    TS_ASSERT(!q.printf_buffer_size_selected());
    q.select_printf_buffer_size(true);
    TS_ASSERT(q.printf_buffer_size_selected());
  }
  /** // doc: test_select_image_pitch_alignment() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image_pitch_alignment( )
  {
    Device_Query q;
    q.select_image_pitch_alignment(false);
    TS_ASSERT(!q.image_pitch_alignment_selected());
    q.select_image_pitch_alignment(true);
    TS_ASSERT(q.image_pitch_alignment_selected());
  }
  /** // doc: test_select_image_base_address_alignment() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_image_base_address_alignment( )
  {
    Device_Query q;
    q.select_image_base_address_alignment(false);
    TS_ASSERT(!q.image_base_address_alignment_selected());
    q.select_image_base_address_alignment(true);
    TS_ASSERT(q.image_base_address_alignment_selected());
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_all( )
  {
    Device_Query q;
    q.select_none();
    q.select_all();
    TS_ASSERT(q.id_selected());
    TS_ASSERT(q.type_selected());
    TS_ASSERT(q.vendor_id_selected());
    TS_ASSERT(q.max_compute_units_selected());
    TS_ASSERT(q.max_work_item_dimensions_selected());
    TS_ASSERT(q.max_work_group_size_selected());
    TS_ASSERT(q.max_work_item_sizes_selected());
    TS_ASSERT(q.preferred_vector_width_char_selected());
    TS_ASSERT(q.preferred_vector_width_short_selected());
    TS_ASSERT(q.preferred_vector_width_int_selected());
    TS_ASSERT(q.preferred_vector_width_long_selected());
    TS_ASSERT(q.preferred_vector_width_float_selected());
    TS_ASSERT(q.preferred_vector_width_double_selected());
    TS_ASSERT(q.max_clock_frequency_selected());
    TS_ASSERT(q.address_bits_selected());
    TS_ASSERT(q.max_read_image_args_selected());
    TS_ASSERT(q.max_write_image_args_selected());
    TS_ASSERT(q.max_mem_alloc_size_selected());
    TS_ASSERT(q.image2d_max_width_selected());
    TS_ASSERT(q.image2d_max_height_selected());
    TS_ASSERT(q.image3d_max_width_selected());
    TS_ASSERT(q.image3d_max_height_selected());
    TS_ASSERT(q.image3d_max_depth_selected());
    TS_ASSERT(q.image_support_selected());
    TS_ASSERT(q.max_parameter_size_selected());
    TS_ASSERT(q.max_samplers_selected());
    TS_ASSERT(q.mem_base_addr_align_selected());
    TS_ASSERT(q.min_data_type_align_size_selected());
    TS_ASSERT(q.single_fp_config_selected());
    TS_ASSERT(q.global_mem_cache_type_selected());
    TS_ASSERT(q.global_mem_cacheline_size_selected());
    TS_ASSERT(q.global_mem_cache_size_selected());
    TS_ASSERT(q.global_mem_size_selected());
    TS_ASSERT(q.max_constant_buffer_size_selected());
    TS_ASSERT(q.max_constant_args_selected());
    TS_ASSERT(q.local_mem_type_selected());
    TS_ASSERT(q.local_mem_size_selected());
    TS_ASSERT(q.error_correction_support_selected());
    TS_ASSERT(q.profiling_timer_resolution_selected());
    TS_ASSERT(q.endian_little_selected());
    TS_ASSERT(q.available_selected());
    TS_ASSERT(q.compiler_available_selected());
    TS_ASSERT(q.execution_capabilities_selected());
    TS_ASSERT(q.queue_properties_selected());
    TS_ASSERT(q.name_selected());
    TS_ASSERT(q.vendor_selected());
    TS_ASSERT(q.driver_version_selected());
    TS_ASSERT(q.profile_selected());
    TS_ASSERT(q.version_selected());
    TS_ASSERT(q.extensions_selected());
    TS_ASSERT(q.platform_id_selected());
    TS_ASSERT(q.double_fp_config_selected());
    TS_ASSERT(q.preferred_vector_width_half_selected());
    TS_ASSERT(q.host_unified_memory_selected());
    TS_ASSERT(q.native_vector_width_char_selected());
    TS_ASSERT(q.native_vector_width_short_selected());
    TS_ASSERT(q.native_vector_width_int_selected());
    TS_ASSERT(q.native_vector_width_long_selected());
    TS_ASSERT(q.native_vector_width_float_selected());
    TS_ASSERT(q.native_vector_width_double_selected());
    TS_ASSERT(q.native_vector_width_half_selected());
    TS_ASSERT(q.opencl_c_version_selected());
    TS_ASSERT(q.linker_available_selected());
    TS_ASSERT(q.built_in_kernels_selected());
    TS_ASSERT(q.image_max_buffer_size_selected());
    TS_ASSERT(q.image_max_array_size_selected());
    TS_ASSERT(q.parent_device_id_selected());
    TS_ASSERT(q.partition_max_sub_devices_selected());
    TS_ASSERT(q.partition_properties_selected());
    TS_ASSERT(q.partition_affinity_domain_selected());
    TS_ASSERT(q.partition_type_selected());
    TS_ASSERT(q.reference_count_selected());
    TS_ASSERT(q.preferred_interop_user_sync_selected());
    TS_ASSERT(q.printf_buffer_size_selected());
    TS_ASSERT(q.image_pitch_alignment_selected());
    TS_ASSERT(q.image_base_address_alignment_selected());
  }
  /** // doc: test_select_none() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_none( )
  {
    Device_Query q;
    q.select_none();
    TS_ASSERT(!q.id_selected());
    TS_ASSERT(!q.type_selected());
    TS_ASSERT(!q.vendor_id_selected());
    TS_ASSERT(!q.max_compute_units_selected());
    TS_ASSERT(!q.max_work_item_dimensions_selected());
    TS_ASSERT(!q.max_work_group_size_selected());
    TS_ASSERT(!q.max_work_item_sizes_selected());
    TS_ASSERT(!q.preferred_vector_width_char_selected());
    TS_ASSERT(!q.preferred_vector_width_short_selected());
    TS_ASSERT(!q.preferred_vector_width_int_selected());
    TS_ASSERT(!q.preferred_vector_width_long_selected());
    TS_ASSERT(!q.preferred_vector_width_float_selected());
    TS_ASSERT(!q.preferred_vector_width_double_selected());
    TS_ASSERT(!q.max_clock_frequency_selected());
    TS_ASSERT(!q.address_bits_selected());
    TS_ASSERT(!q.max_read_image_args_selected());
    TS_ASSERT(!q.max_write_image_args_selected());
    TS_ASSERT(!q.max_mem_alloc_size_selected());
    TS_ASSERT(!q.image2d_max_width_selected());
    TS_ASSERT(!q.image2d_max_height_selected());
    TS_ASSERT(!q.image3d_max_width_selected());
    TS_ASSERT(!q.image3d_max_height_selected());
    TS_ASSERT(!q.image3d_max_depth_selected());
    TS_ASSERT(!q.image_support_selected());
    TS_ASSERT(!q.max_parameter_size_selected());
    TS_ASSERT(!q.max_samplers_selected());
    TS_ASSERT(!q.mem_base_addr_align_selected());
    TS_ASSERT(!q.min_data_type_align_size_selected());
    TS_ASSERT(!q.single_fp_config_selected());
    TS_ASSERT(!q.global_mem_cache_type_selected());
    TS_ASSERT(!q.global_mem_cacheline_size_selected());
    TS_ASSERT(!q.global_mem_cache_size_selected());
    TS_ASSERT(!q.global_mem_size_selected());
    TS_ASSERT(!q.max_constant_buffer_size_selected());
    TS_ASSERT(!q.max_constant_args_selected());
    TS_ASSERT(!q.local_mem_type_selected());
    TS_ASSERT(!q.local_mem_size_selected());
    TS_ASSERT(!q.error_correction_support_selected());
    TS_ASSERT(!q.profiling_timer_resolution_selected());
    TS_ASSERT(!q.endian_little_selected());
    TS_ASSERT(!q.available_selected());
    TS_ASSERT(!q.compiler_available_selected());
    TS_ASSERT(!q.execution_capabilities_selected());
    TS_ASSERT(!q.queue_properties_selected());
    TS_ASSERT(!q.name_selected());
    TS_ASSERT(!q.vendor_selected());
    TS_ASSERT(!q.driver_version_selected());
    TS_ASSERT(!q.profile_selected());
    TS_ASSERT(!q.version_selected());
    TS_ASSERT(!q.extensions_selected());
    TS_ASSERT(!q.platform_id_selected());
    TS_ASSERT(!q.double_fp_config_selected());
    TS_ASSERT(!q.preferred_vector_width_half_selected());
    TS_ASSERT(!q.host_unified_memory_selected());
    TS_ASSERT(!q.native_vector_width_char_selected());
    TS_ASSERT(!q.native_vector_width_short_selected());
    TS_ASSERT(!q.native_vector_width_int_selected());
    TS_ASSERT(!q.native_vector_width_long_selected());
    TS_ASSERT(!q.native_vector_width_float_selected());
    TS_ASSERT(!q.native_vector_width_double_selected());
    TS_ASSERT(!q.native_vector_width_half_selected());
    TS_ASSERT(!q.opencl_c_version_selected());
    TS_ASSERT(!q.linker_available_selected());
    TS_ASSERT(!q.built_in_kernels_selected());
    TS_ASSERT(!q.image_max_buffer_size_selected());
    TS_ASSERT(!q.image_max_array_size_selected());
    TS_ASSERT(!q.parent_device_id_selected());
    TS_ASSERT(!q.partition_max_sub_devices_selected());
    TS_ASSERT(!q.partition_properties_selected());
    TS_ASSERT(!q.partition_affinity_domain_selected());
    TS_ASSERT(!q.partition_type_selected());
    TS_ASSERT(!q.reference_count_selected());
    TS_ASSERT(!q.preferred_interop_user_sync_selected());
    TS_ASSERT(!q.printf_buffer_size_selected());
    TS_ASSERT(!q.image_pitch_alignment_selected());
    TS_ASSERT(!q.image_base_address_alignment_selected());
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
  /** // doc: test_serialize_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_1( )
  {
    Device_Query a;
    Device_Query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << a;

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    TS_ASSERT_EQUALS(a, b);
  }
  /** // doc: test_eq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op( )
  {
    Device_Query a;
    Device_Query b;

    TS_ASSERT((a == b));
    a.select_id(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_type(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_vendor_id(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_compute_units(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_work_item_dimensions(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_work_group_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_work_item_sizes(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_char(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_int(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_short(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_long(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_float(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_double(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_clock_frequency(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_address_bits(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_read_image_args(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_write_image_args(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_mem_alloc_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image2d_max_width(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image2d_max_height(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image3d_max_width(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image3d_max_height(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image3d_max_depth(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image_support(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_parameter_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_samplers(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_mem_base_addr_align(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_min_data_type_align_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_single_fp_config(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_global_mem_cache_type(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_global_mem_cacheline_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_global_mem_cache_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_global_mem_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_constant_buffer_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_max_constant_args(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_local_mem_type(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_local_mem_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_error_correction_support(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_profiling_timer_resolution(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_endian_little(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_available(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_id(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_compiler_available(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_queue_properties(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_name(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_vendor(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_driver_version(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_extensions(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_platform_id(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_double_fp_config(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_vector_width_half(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_host_unified_memory(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_char(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_short(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_int(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_long(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_float(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_double(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_native_vector_width_half(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_opencl_c_version(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_linker_available(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_built_in_kernels(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image_max_buffer_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image_max_array_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_parent_device_id(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_partition_max_sub_devices(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_partition_properties(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_partition_affinity_domain(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_partition_type(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_reference_count(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_preferred_interop_user_sync(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_printf_buffer_size(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image_pitch_alignment(false);
    TS_ASSERT(!(a == b));

    a = b;
    TS_ASSERT((a == b));
    a.select_image_base_address_alignment(false);
    TS_ASSERT(!(a == b));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op( )
  {
    Device_Query a;
    Device_Query b;
    TS_ASSERT(!(a != b));
    a.select_image3d_max_depth(!a.image3d_max_depth_selected());
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_type(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_vendor_id(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_compute_units(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_work_item_dimensions(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_work_group_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_work_item_sizes(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_char(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_int(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_short(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_long(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_float(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_double(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_clock_frequency(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_address_bits(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_read_image_args(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_write_image_args(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_mem_alloc_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image2d_max_width(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image2d_max_height(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image3d_max_width(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image3d_max_height(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image3d_max_depth(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image_support(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_parameter_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_samplers(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_mem_base_addr_align(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_min_data_type_align_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_single_fp_config(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_global_mem_cache_type(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_global_mem_cacheline_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_global_mem_cache_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_global_mem_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_constant_buffer_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_max_constant_args(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_local_mem_type(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_local_mem_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_error_correction_support(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_profiling_timer_resolution(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_endian_little(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_available(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_id(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_compiler_available(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_queue_properties(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_name(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_vendor(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_driver_version(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_extensions(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_platform_id(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_double_fp_config(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_vector_width_half(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_host_unified_memory(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_char(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_short(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_int(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_long(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_float(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_double(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_native_vector_width_half(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_opencl_c_version(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_linker_available(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_built_in_kernels(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image_max_buffer_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image_max_array_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_parent_device_id(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_partition_max_sub_devices(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_partition_properties(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_partition_affinity_domain(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_partition_type(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_reference_count(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_preferred_interop_user_sync(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_printf_buffer_size(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image_pitch_alignment(false);
    TS_ASSERT((a != b));

    a = b;
    TS_ASSERT(!(a != b));
    a.select_image_base_address_alignment(false);
    TS_ASSERT((a != b));
  }
};

#endif /* DIMBO_CL_DEVICE_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
