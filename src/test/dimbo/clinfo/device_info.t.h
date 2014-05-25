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

// dimbo/clinfo/device_info.t.h

/** // doc: dimbo/clinfo/device_info.t.h {{{
 * \file dimbo/clinfo/device_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CLINFO_DEVICE_INFO_T_H_INCLUDED
#define DIMBO_CLINFO_DEVICE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/clinfo/device_info.hpp>
#include <dimbo/clinfo/device_info_fixtures.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Clinfo { class Device_Info_TestSuite; } }

/** // doc: class Dimbo::Clinfo::Device_Info_TestSuite {{{
 * \brief Unit tests for Dimbo::Clinfo::Device_Info class
 */ // }}}
class Dimbo::Clinfo::Device_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(!Device_Info().has_id());
    TS_ASSERT(!Device_Info().has_type());
    TS_ASSERT(!Device_Info().has_vendor_id());
    TS_ASSERT(!Device_Info().has_max_compute_units());
    TS_ASSERT(!Device_Info().has_max_work_item_dimensions());
    TS_ASSERT(!Device_Info().has_max_work_group_size());
    TS_ASSERT(!Device_Info().has_max_work_item_sizes());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_char());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_short());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_int());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_long());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_float());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_double());
    TS_ASSERT(!Device_Info().has_max_clock_frequency());
    TS_ASSERT(!Device_Info().has_address_bits());
    TS_ASSERT(!Device_Info().has_max_read_image_args());
    TS_ASSERT(!Device_Info().has_max_write_image_args());
    TS_ASSERT(!Device_Info().has_max_mem_alloc_size());
    TS_ASSERT(!Device_Info().has_image2d_max_width());
    TS_ASSERT(!Device_Info().has_image2d_max_height());
    TS_ASSERT(!Device_Info().has_image3d_max_width());
    TS_ASSERT(!Device_Info().has_image3d_max_height());
    TS_ASSERT(!Device_Info().has_image3d_max_depth());
    TS_ASSERT(!Device_Info().has_image_support());
    TS_ASSERT(!Device_Info().has_max_parameter_size());
    TS_ASSERT(!Device_Info().has_max_samplers());
    TS_ASSERT(!Device_Info().has_mem_base_addr_align());
    TS_ASSERT(!Device_Info().has_min_data_type_align_size());
    TS_ASSERT(!Device_Info().has_single_fp_config());
    TS_ASSERT(!Device_Info().has_global_mem_cache_type());
    TS_ASSERT(!Device_Info().has_global_mem_cacheline_size());
    TS_ASSERT(!Device_Info().has_global_mem_cache_size());
    TS_ASSERT(!Device_Info().has_global_mem_size());
    TS_ASSERT(!Device_Info().has_max_constant_buffer_size());
    TS_ASSERT(!Device_Info().has_max_constant_args());
    TS_ASSERT(!Device_Info().has_local_mem_type());
    TS_ASSERT(!Device_Info().has_local_mem_size());
    TS_ASSERT(!Device_Info().has_error_correction_support());
    TS_ASSERT(!Device_Info().has_profiling_timer_resolution());
    TS_ASSERT(!Device_Info().has_endian_little());
    TS_ASSERT(!Device_Info().has_available());
    TS_ASSERT(!Device_Info().has_compiler_available());
    TS_ASSERT(!Device_Info().has_execution_capabilities());
    TS_ASSERT(!Device_Info().has_queue_properties());
    TS_ASSERT(!Device_Info().has_name());
    TS_ASSERT(!Device_Info().has_vendor());
    TS_ASSERT(!Device_Info().has_driver_version());
    TS_ASSERT(!Device_Info().has_profile());
    TS_ASSERT(!Device_Info().has_version());
    TS_ASSERT(!Device_Info().has_extensions());
    TS_ASSERT(!Device_Info().has_platform_id());
    TS_ASSERT(!Device_Info().has_double_fp_config());
    TS_ASSERT(!Device_Info().has_preferred_vector_width_half());
    TS_ASSERT(!Device_Info().has_host_unified_memory());
    TS_ASSERT(!Device_Info().has_native_vector_width_char());
    TS_ASSERT(!Device_Info().has_native_vector_width_short());
    TS_ASSERT(!Device_Info().has_native_vector_width_int());
    TS_ASSERT(!Device_Info().has_native_vector_width_long());
    TS_ASSERT(!Device_Info().has_native_vector_width_float());
    TS_ASSERT(!Device_Info().has_native_vector_width_double());
    TS_ASSERT(!Device_Info().has_native_vector_width_half());
    TS_ASSERT(!Device_Info().has_opencl_c_version());
    TS_ASSERT(!Device_Info().has_linker_available());
    TS_ASSERT(!Device_Info().has_built_in_kernels());
    TS_ASSERT(!Device_Info().has_image_max_buffer_size());
    TS_ASSERT(!Device_Info().has_image_max_array_size());
    TS_ASSERT(!Device_Info().has_parent_device_id());
    TS_ASSERT(!Device_Info().has_partition_max_sub_devices());
    TS_ASSERT(!Device_Info().has_partition_properties());
    TS_ASSERT(!Device_Info().has_partition_affinity_domain());
    TS_ASSERT(!Device_Info().has_partition_type());
    TS_ASSERT(!Device_Info().has_reference_count());
    TS_ASSERT(!Device_Info().has_preferred_interop_user_sync());
    TS_ASSERT(!Device_Info().has_printf_buffer_size());
    TS_ASSERT(!Device_Info().has_image_pitch_alignment());
    TS_ASSERT(!Device_Info().has_image_base_address_alignment());
  }
  /** // doc: test_getter_exceptions() {{{
   * \todo Write documentation
   */ // }}}
  void test_getter_exceptions( )
  {
    TS_ASSERT_THROWS(Device_Info().id(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().type(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().vendor_id(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_compute_units(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_work_item_dimensions(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_work_group_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_work_item_sizes(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_char(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_short(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_int(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_long(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_float(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_double(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_clock_frequency(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().address_bits(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_read_image_args(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_write_image_args(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_mem_alloc_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image2d_max_width(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image2d_max_height(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image3d_max_width(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image3d_max_height(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image3d_max_depth(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image_support(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_parameter_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_samplers(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().mem_base_addr_align(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().min_data_type_align_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().single_fp_config(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().global_mem_cache_type(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().global_mem_cacheline_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().global_mem_cache_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().global_mem_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_constant_buffer_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().max_constant_args(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().local_mem_type(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().local_mem_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().error_correction_support(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().profiling_timer_resolution(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().endian_little(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().available(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().compiler_available(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().execution_capabilities(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().queue_properties(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().name(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().vendor(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().driver_version(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().profile(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().version(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().extensions(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().platform_id(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().double_fp_config(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_vector_width_half(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().host_unified_memory(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_char(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_short(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_int(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_long(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_float(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_double(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().native_vector_width_half(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().opencl_c_version(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().linker_available(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().built_in_kernels(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image_max_buffer_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image_max_array_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().parent_device_id(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().partition_max_sub_devices(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().partition_properties(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().partition_affinity_domain(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().partition_type(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().reference_count(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().preferred_interop_user_sync(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().printf_buffer_size(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image_pitch_alignment(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Device_Info().image_base_address_alignment(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  }
  /** // doc: test_set_get() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get( )
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };

    TS_ASSERT_EQUALS(Device_Info().set_id(0x1234ul).id(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_type(0x1234ul).type(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_vendor_id(0x1234u).vendor_id(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_compute_units(0x1234u).max_compute_units(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_work_item_dimensions(0x1234u).max_work_item_dimensions(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_work_group_size(0x1234ul).max_work_group_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)).max_work_item_sizes(),std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3));
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_char(0x1234u).preferred_vector_width_char(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_short(0x1234u).preferred_vector_width_short(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_int(0x1234u).preferred_vector_width_int(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_long(0x1234u).preferred_vector_width_long(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_float(0x1234u).preferred_vector_width_float(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_double(0x1234u).preferred_vector_width_double(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_clock_frequency(0x1234u).max_clock_frequency(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_address_bits(0x1234u).address_bits(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_read_image_args(0x1234u).max_read_image_args(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_write_image_args(0x1234u).max_write_image_args(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_mem_alloc_size(0x1234ul).max_mem_alloc_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image2d_max_width(0x1234ul).image2d_max_width(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image2d_max_height(0x1234ul).image2d_max_height(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image3d_max_width(0x1234ul).image3d_max_width(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image3d_max_height(0x1234ul).image3d_max_height(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image3d_max_depth(0x1234ul).image3d_max_depth(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image_support(0).image_support(),0);
    TS_ASSERT_EQUALS(Device_Info().set_max_parameter_size(0x1234ul).max_parameter_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_max_samplers(0x1234u).max_samplers(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_mem_base_addr_align(0x1234u).mem_base_addr_align(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_min_data_type_align_size(0x1234u).min_data_type_align_size(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_single_fp_config(0x1234).single_fp_config(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_global_mem_cache_type(0x1234).global_mem_cache_type(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_global_mem_cacheline_size(0x1234u).global_mem_cacheline_size(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_global_mem_cache_size(0x1234ul).global_mem_cache_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_global_mem_size(0x1234ul).global_mem_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_max_constant_buffer_size(0x1234u).max_constant_buffer_size(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_max_constant_args(0x1234u).max_constant_args(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_local_mem_type(0x1234).local_mem_type(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_local_mem_size(0x1234ul).local_mem_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_error_correction_support(0).error_correction_support(),0);
    TS_ASSERT_EQUALS(Device_Info().set_profiling_timer_resolution(0x1234ul).profiling_timer_resolution(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_endian_little(0).endian_little(),0);
    TS_ASSERT_EQUALS(Device_Info().set_available(0).available(),0);
    TS_ASSERT_EQUALS(Device_Info().set_compiler_available(0).compiler_available(),0);
    TS_ASSERT_EQUALS(Device_Info().set_execution_capabilities(0x1234).execution_capabilities(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_queue_properties(0x1234).queue_properties(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_name("_name").name(),"_name");
    TS_ASSERT_EQUALS(Device_Info().set_vendor("_vendor").vendor(),"_vendor");
    TS_ASSERT_EQUALS(Device_Info().set_driver_version("_driver_version").driver_version(),"_driver_version");
    TS_ASSERT_EQUALS(Device_Info().set_profile("_profile").profile(),"_profile");
    TS_ASSERT_EQUALS(Device_Info().set_version("_version").version(),"_version");
    TS_ASSERT_EQUALS(Device_Info().set_extensions("_extensions").extensions(),"_extensions");
    TS_ASSERT_EQUALS(Device_Info().set_platform_id(0x1234ul).platform_id(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_double_fp_config(0x1234).double_fp_config(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_vector_width_half(0x1234u).preferred_vector_width_half(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_host_unified_memory(0).host_unified_memory(),0);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_char(0x1234u).native_vector_width_char(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_short(0x1234u).native_vector_width_short(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_int(0x1234u).native_vector_width_int(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_long(0x1234u).native_vector_width_long(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_float(0x1234u).native_vector_width_float(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_double(0x1234u).native_vector_width_double(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_native_vector_width_half(0x1234u).native_vector_width_half(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_opencl_c_version("_opencl_c_version").opencl_c_version(),"_opencl_c_version");
    TS_ASSERT_EQUALS(Device_Info().set_linker_available(0).linker_available(),0);
    TS_ASSERT_EQUALS(Device_Info().set_built_in_kernels("_built_in_kernels").built_in_kernels(),"_built_in_kernels");
    TS_ASSERT_EQUALS(Device_Info().set_image_max_buffer_size(0x1234ul).image_max_buffer_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image_max_array_size(0x1234ul).image_max_array_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_parent_device_id(0x1234ul).parent_device_id(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_partition_max_sub_devices(0x1234u).partition_max_sub_devices(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)).partition_properties(),std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2));
    TS_ASSERT_EQUALS(Device_Info().set_partition_affinity_domain(0x1234).partition_affinity_domain(),0x1234);
    TS_ASSERT_EQUALS(Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)).partition_type(),std::vector<cl_device_partition_property>(partition_type1,partition_type1+2));
    TS_ASSERT_EQUALS(Device_Info().set_reference_count(0x1234u).reference_count(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_preferred_interop_user_sync(0).preferred_interop_user_sync(),0);
    TS_ASSERT_EQUALS(Device_Info().set_printf_buffer_size(0x1234ul).printf_buffer_size(),0x1234ul);
    TS_ASSERT_EQUALS(Device_Info().set_image_pitch_alignment(0x1234u).image_pitch_alignment(),0x1234u);
    TS_ASSERT_EQUALS(Device_Info().set_image_base_address_alignment(0x1234u).image_base_address_alignment(),0x1234u);
  }
  /** // doc: test_set_has() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_has( )
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };

    TS_ASSERT(Device_Info().set_id(0x1234ul).has_id());
    TS_ASSERT(Device_Info().set_type(0x1234ul).has_type());
    TS_ASSERT(Device_Info().set_vendor_id(0x1234u).has_vendor_id());
    TS_ASSERT(Device_Info().set_max_compute_units(0x1234u).has_max_compute_units());
    TS_ASSERT(Device_Info().set_max_work_item_dimensions(0x1234u).has_max_work_item_dimensions());
    TS_ASSERT(Device_Info().set_max_work_group_size(0x1234ul).has_max_work_group_size());
    TS_ASSERT(Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)).has_max_work_item_sizes());
    TS_ASSERT(Device_Info().set_preferred_vector_width_char(0x1234u).has_preferred_vector_width_char());
    TS_ASSERT(Device_Info().set_preferred_vector_width_short(0x1234u).has_preferred_vector_width_short());
    TS_ASSERT(Device_Info().set_preferred_vector_width_int(0x1234u).has_preferred_vector_width_int());
    TS_ASSERT(Device_Info().set_preferred_vector_width_long(0x1234u).has_preferred_vector_width_long());
    TS_ASSERT(Device_Info().set_preferred_vector_width_float(0x1234u).has_preferred_vector_width_float());
    TS_ASSERT(Device_Info().set_preferred_vector_width_double(0x1234u).has_preferred_vector_width_double());
    TS_ASSERT(Device_Info().set_max_clock_frequency(0x1234u).has_max_clock_frequency());
    TS_ASSERT(Device_Info().set_address_bits(0x1234u).has_address_bits());
    TS_ASSERT(Device_Info().set_max_read_image_args(0x1234u).has_max_read_image_args());
    TS_ASSERT(Device_Info().set_max_write_image_args(0x1234u).has_max_write_image_args());
    TS_ASSERT(Device_Info().set_max_mem_alloc_size(0x1234ul).has_max_mem_alloc_size());
    TS_ASSERT(Device_Info().set_image2d_max_width(0x1234ul).has_image2d_max_width());
    TS_ASSERT(Device_Info().set_image2d_max_height(0x1234ul).has_image2d_max_height());
    TS_ASSERT(Device_Info().set_image3d_max_width(0x1234ul).has_image3d_max_width());
    TS_ASSERT(Device_Info().set_image3d_max_height(0x1234ul).has_image3d_max_height());
    TS_ASSERT(Device_Info().set_image3d_max_depth(0x1234ul).has_image3d_max_depth());
    TS_ASSERT(Device_Info().set_image_support(0).has_image_support());
    TS_ASSERT(Device_Info().set_max_parameter_size(0x1234ul).has_max_parameter_size());
    TS_ASSERT(Device_Info().set_max_samplers(0x1234u).has_max_samplers());
    TS_ASSERT(Device_Info().set_mem_base_addr_align(0x1234u).has_mem_base_addr_align());
    TS_ASSERT(Device_Info().set_min_data_type_align_size(0x1234u).has_min_data_type_align_size());
    TS_ASSERT(Device_Info().set_single_fp_config(0x1234).has_single_fp_config());
    TS_ASSERT(Device_Info().set_global_mem_cache_type(0x1234).has_global_mem_cache_type());
    TS_ASSERT(Device_Info().set_global_mem_cacheline_size(0x1234u).has_global_mem_cacheline_size());
    TS_ASSERT(Device_Info().set_global_mem_cache_size(0x1234ul).has_global_mem_cache_size());
    TS_ASSERT(Device_Info().set_global_mem_size(0x1234ul).has_global_mem_size());
    TS_ASSERT(Device_Info().set_max_constant_buffer_size(0x1234u).has_max_constant_buffer_size());
    TS_ASSERT(Device_Info().set_max_constant_args(0x1234u).has_max_constant_args());
    TS_ASSERT(Device_Info().set_local_mem_type(0x1234).has_local_mem_type());
    TS_ASSERT(Device_Info().set_local_mem_size(0x1234ul).has_local_mem_size());
    TS_ASSERT(Device_Info().set_error_correction_support(0).has_error_correction_support());
    TS_ASSERT(Device_Info().set_profiling_timer_resolution(0x1234ul).has_profiling_timer_resolution());
    TS_ASSERT(Device_Info().set_endian_little(0).has_endian_little());
    TS_ASSERT(Device_Info().set_available(0).has_available());
    TS_ASSERT(Device_Info().set_compiler_available(0).has_compiler_available());
    TS_ASSERT(Device_Info().set_execution_capabilities(0x1234).has_execution_capabilities());
    TS_ASSERT(Device_Info().set_queue_properties(0x1234).has_queue_properties());
    TS_ASSERT(Device_Info().set_name("_name").has_name());
    TS_ASSERT(Device_Info().set_vendor("_vendor").has_vendor());
    TS_ASSERT(Device_Info().set_driver_version("_driver_version").has_driver_version());
    TS_ASSERT(Device_Info().set_profile("_profile").has_profile());
    TS_ASSERT(Device_Info().set_version("_version").has_version());
    TS_ASSERT(Device_Info().set_extensions("_extensions").has_extensions());
    TS_ASSERT(Device_Info().set_platform_id(0x1234ul).has_platform_id());
    TS_ASSERT(Device_Info().set_double_fp_config(0x1234).has_double_fp_config());
    TS_ASSERT(Device_Info().set_preferred_vector_width_half(0x1234u).has_preferred_vector_width_half());
    TS_ASSERT(Device_Info().set_host_unified_memory(0).has_host_unified_memory());
    TS_ASSERT(Device_Info().set_native_vector_width_char(0x1234u).has_native_vector_width_char());
    TS_ASSERT(Device_Info().set_native_vector_width_short(0x1234u).has_native_vector_width_short());
    TS_ASSERT(Device_Info().set_native_vector_width_int(0x1234u).has_native_vector_width_int());
    TS_ASSERT(Device_Info().set_native_vector_width_long(0x1234u).has_native_vector_width_long());
    TS_ASSERT(Device_Info().set_native_vector_width_float(0x1234u).has_native_vector_width_float());
    TS_ASSERT(Device_Info().set_native_vector_width_double(0x1234u).has_native_vector_width_double());
    TS_ASSERT(Device_Info().set_native_vector_width_half(0x1234u).has_native_vector_width_half());
    TS_ASSERT(Device_Info().set_opencl_c_version("_opencl_c_version").has_opencl_c_version());
    TS_ASSERT(Device_Info().set_linker_available(0).has_linker_available());
    TS_ASSERT(Device_Info().set_built_in_kernels("_built_in_kernels").has_built_in_kernels());
    TS_ASSERT(Device_Info().set_image_max_buffer_size(0x1234ul).has_image_max_buffer_size());
    TS_ASSERT(Device_Info().set_image_max_array_size(0x1234ul).has_image_max_array_size());
    TS_ASSERT(Device_Info().set_parent_device_id(0x1234ul).has_parent_device_id());
    TS_ASSERT(Device_Info().set_partition_max_sub_devices(0x1234u).has_partition_max_sub_devices());
    TS_ASSERT(Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)).has_partition_properties());
    TS_ASSERT(Device_Info().set_partition_affinity_domain(0x1234).has_partition_affinity_domain());
    TS_ASSERT(Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)).has_partition_type());
    TS_ASSERT(Device_Info().set_reference_count(0x1234u).has_reference_count());
    TS_ASSERT(Device_Info().set_preferred_interop_user_sync(0).has_preferred_interop_user_sync());
    TS_ASSERT(Device_Info().set_printf_buffer_size(0x1234ul).has_printf_buffer_size());
    TS_ASSERT(Device_Info().set_image_pitch_alignment(0x1234u).has_image_pitch_alignment());
    TS_ASSERT(Device_Info().set_image_base_address_alignment(0x1234u).has_image_base_address_alignment());
  }
  /** // doc: test_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_has_1( )
  {
    Device_Info const infos[2] = { Device_Info_Fixtures::_1(), Device_Info_Fixtures::_2() };
    for(Device_Info const* info = infos; info < infos + 2; ++info)
      {
        TS_ASSERT(info->has_id());
        TS_ASSERT(info->has_type());
        TS_ASSERT(info->has_vendor_id());
        TS_ASSERT(info->has_max_compute_units());
        TS_ASSERT(info->has_max_work_item_dimensions());
        TS_ASSERT(info->has_max_work_group_size());
        TS_ASSERT(info->has_max_work_item_sizes());
        TS_ASSERT(info->has_preferred_vector_width_char());
        TS_ASSERT(info->has_preferred_vector_width_short());
        TS_ASSERT(info->has_preferred_vector_width_int());
        TS_ASSERT(info->has_preferred_vector_width_long());
        TS_ASSERT(info->has_preferred_vector_width_float());
        TS_ASSERT(info->has_preferred_vector_width_double());
        TS_ASSERT(info->has_max_clock_frequency());
        TS_ASSERT(info->has_address_bits());
        TS_ASSERT(info->has_max_read_image_args());
        TS_ASSERT(info->has_max_write_image_args());
        TS_ASSERT(info->has_max_mem_alloc_size());
        TS_ASSERT(info->has_image2d_max_width());
        TS_ASSERT(info->has_image2d_max_height());
        TS_ASSERT(info->has_image3d_max_width());
        TS_ASSERT(info->has_image3d_max_height());
        TS_ASSERT(info->has_image3d_max_depth());
        TS_ASSERT(info->has_image_support());
        TS_ASSERT(info->has_max_parameter_size());
        TS_ASSERT(info->has_max_samplers());
        TS_ASSERT(info->has_mem_base_addr_align());
        TS_ASSERT(info->has_min_data_type_align_size());
        TS_ASSERT(info->has_single_fp_config());
        TS_ASSERT(info->has_global_mem_cache_type());
        TS_ASSERT(info->has_global_mem_cacheline_size());
        TS_ASSERT(info->has_global_mem_cache_size());
        TS_ASSERT(info->has_global_mem_size());
        TS_ASSERT(info->has_max_constant_buffer_size());
        TS_ASSERT(info->has_max_constant_args());
        TS_ASSERT(info->has_local_mem_type());
        TS_ASSERT(info->has_local_mem_size());
        TS_ASSERT(info->has_error_correction_support());
        TS_ASSERT(info->has_profiling_timer_resolution());
        TS_ASSERT(info->has_endian_little());
        TS_ASSERT(info->has_available());
        TS_ASSERT(info->has_compiler_available());
        TS_ASSERT(info->has_execution_capabilities());
        TS_ASSERT(info->has_queue_properties());
        TS_ASSERT(info->has_name());
        TS_ASSERT(info->has_vendor());
        TS_ASSERT(info->has_driver_version());
        TS_ASSERT(info->has_profile());
        TS_ASSERT(info->has_version());
        TS_ASSERT(info->has_extensions());
        TS_ASSERT(info->has_platform_id());
        TS_ASSERT(info->has_double_fp_config());
        TS_ASSERT(info->has_preferred_vector_width_half());
        TS_ASSERT(info->has_host_unified_memory());
        TS_ASSERT(info->has_native_vector_width_char());
        TS_ASSERT(info->has_native_vector_width_short());
        TS_ASSERT(info->has_native_vector_width_int());
        TS_ASSERT(info->has_native_vector_width_long());
        TS_ASSERT(info->has_native_vector_width_float());
        TS_ASSERT(info->has_native_vector_width_double());
        TS_ASSERT(info->has_native_vector_width_half());
        TS_ASSERT(info->has_opencl_c_version());
        TS_ASSERT(info->has_linker_available());
        TS_ASSERT(info->has_built_in_kernels());
        TS_ASSERT(info->has_image_max_buffer_size());
        TS_ASSERT(info->has_image_max_array_size());
        TS_ASSERT(info->has_parent_device_id());
        TS_ASSERT(info->has_partition_max_sub_devices());
        TS_ASSERT(info->has_partition_properties());
        TS_ASSERT(info->has_partition_affinity_domain());
        TS_ASSERT(info->has_partition_type());
        TS_ASSERT(info->has_reference_count());
        TS_ASSERT(info->has_preferred_interop_user_sync());
        TS_ASSERT(info->has_printf_buffer_size());
        TS_ASSERT(info->has_image_pitch_alignment());
        TS_ASSERT(info->has_image_base_address_alignment());
      }
  }
  /** // doc: test_clear_dont_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_dont_has_1( )
  {
    Device_Info info(Device_Info_Fixtures::_1());

    info.clear();

    TS_ASSERT(!info.has_id());
    TS_ASSERT(!info.has_type());
    TS_ASSERT(!info.has_vendor_id());
    TS_ASSERT(!info.has_max_compute_units());
    TS_ASSERT(!info.has_max_work_item_dimensions());
    TS_ASSERT(!info.has_max_work_group_size());
    TS_ASSERT(!info.has_max_work_item_sizes());
    TS_ASSERT(!info.has_preferred_vector_width_char());
    TS_ASSERT(!info.has_preferred_vector_width_short());
    TS_ASSERT(!info.has_preferred_vector_width_int());
    TS_ASSERT(!info.has_preferred_vector_width_long());
    TS_ASSERT(!info.has_preferred_vector_width_float());
    TS_ASSERT(!info.has_preferred_vector_width_double());
    TS_ASSERT(!info.has_max_clock_frequency());
    TS_ASSERT(!info.has_address_bits());
    TS_ASSERT(!info.has_max_read_image_args());
    TS_ASSERT(!info.has_max_write_image_args());
    TS_ASSERT(!info.has_max_mem_alloc_size());
    TS_ASSERT(!info.has_image2d_max_width());
    TS_ASSERT(!info.has_image2d_max_height());
    TS_ASSERT(!info.has_image3d_max_width());
    TS_ASSERT(!info.has_image3d_max_height());
    TS_ASSERT(!info.has_image3d_max_depth());
    TS_ASSERT(!info.has_image_support());
    TS_ASSERT(!info.has_max_parameter_size());
    TS_ASSERT(!info.has_max_samplers());
    TS_ASSERT(!info.has_mem_base_addr_align());
    TS_ASSERT(!info.has_min_data_type_align_size());
    TS_ASSERT(!info.has_single_fp_config());
    TS_ASSERT(!info.has_global_mem_cache_type());
    TS_ASSERT(!info.has_global_mem_cacheline_size());
    TS_ASSERT(!info.has_global_mem_cache_size());
    TS_ASSERT(!info.has_global_mem_size());
    TS_ASSERT(!info.has_max_constant_buffer_size());
    TS_ASSERT(!info.has_max_constant_args());
    TS_ASSERT(!info.has_local_mem_type());
    TS_ASSERT(!info.has_local_mem_size());
    TS_ASSERT(!info.has_error_correction_support());
    TS_ASSERT(!info.has_profiling_timer_resolution());
    TS_ASSERT(!info.has_endian_little());
    TS_ASSERT(!info.has_available());
    TS_ASSERT(!info.has_compiler_available());
    TS_ASSERT(!info.has_execution_capabilities());
    TS_ASSERT(!info.has_queue_properties());
    TS_ASSERT(!info.has_name());
    TS_ASSERT(!info.has_vendor());
    TS_ASSERT(!info.has_driver_version());
    TS_ASSERT(!info.has_profile());
    TS_ASSERT(!info.has_version());
    TS_ASSERT(!info.has_extensions());
    TS_ASSERT(!info.has_platform_id());
    TS_ASSERT(!info.has_double_fp_config());
    TS_ASSERT(!info.has_preferred_vector_width_half());
    TS_ASSERT(!info.has_host_unified_memory());
    TS_ASSERT(!info.has_native_vector_width_char());
    TS_ASSERT(!info.has_native_vector_width_short());
    TS_ASSERT(!info.has_native_vector_width_int());
    TS_ASSERT(!info.has_native_vector_width_long());
    TS_ASSERT(!info.has_native_vector_width_float());
    TS_ASSERT(!info.has_native_vector_width_double());
    TS_ASSERT(!info.has_native_vector_width_half());
    TS_ASSERT(!info.has_opencl_c_version());
    TS_ASSERT(!info.has_linker_available());
    TS_ASSERT(!info.has_built_in_kernels());
    TS_ASSERT(!info.has_image_max_buffer_size());
    TS_ASSERT(!info.has_image_max_array_size());
    TS_ASSERT(!info.has_parent_device_id());
    TS_ASSERT(!info.has_partition_max_sub_devices());
    TS_ASSERT(!info.has_partition_properties());
    TS_ASSERT(!info.has_partition_affinity_domain());
    TS_ASSERT(!info.has_partition_type());
    TS_ASSERT(!info.has_reference_count());
    TS_ASSERT(!info.has_preferred_interop_user_sync());
    TS_ASSERT(!info.has_printf_buffer_size());
    TS_ASSERT(!info.has_image_pitch_alignment());
    TS_ASSERT(!info.has_image_base_address_alignment());
  }
  /** // doc: test_clear_dont_has_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_dont_has_2( )
  {
    Device_Info info(Device_Info_Fixtures::_1());

    TS_ASSERT(!info.clear_id().has_id());
    TS_ASSERT(!info.clear_type().has_type());
    TS_ASSERT(!info.clear_vendor_id().has_vendor_id());
    TS_ASSERT(!info.clear_max_compute_units().has_max_compute_units());
    TS_ASSERT(!info.clear_max_work_item_dimensions().has_max_work_item_dimensions());
    TS_ASSERT(!info.clear_max_work_group_size().has_max_work_group_size());
    TS_ASSERT(!info.clear_max_work_item_sizes().has_max_work_item_sizes());
    TS_ASSERT(!info.clear_preferred_vector_width_char().has_preferred_vector_width_char());
    TS_ASSERT(!info.clear_preferred_vector_width_short().has_preferred_vector_width_short());
    TS_ASSERT(!info.clear_preferred_vector_width_int().has_preferred_vector_width_int());
    TS_ASSERT(!info.clear_preferred_vector_width_long().has_preferred_vector_width_long());
    TS_ASSERT(!info.clear_preferred_vector_width_float().has_preferred_vector_width_float());
    TS_ASSERT(!info.clear_preferred_vector_width_double().has_preferred_vector_width_double());
    TS_ASSERT(!info.clear_max_clock_frequency().has_max_clock_frequency());
    TS_ASSERT(!info.clear_address_bits().has_address_bits());
    TS_ASSERT(!info.clear_max_read_image_args().has_max_read_image_args());
    TS_ASSERT(!info.clear_max_write_image_args().has_max_write_image_args());
    TS_ASSERT(!info.clear_max_mem_alloc_size().has_max_mem_alloc_size());
    TS_ASSERT(!info.clear_image2d_max_width().has_image2d_max_width());
    TS_ASSERT(!info.clear_image2d_max_height().has_image2d_max_height());
    TS_ASSERT(!info.clear_image3d_max_width().has_image3d_max_width());
    TS_ASSERT(!info.clear_image3d_max_height().has_image3d_max_height());
    TS_ASSERT(!info.clear_image3d_max_depth().has_image3d_max_depth());
    TS_ASSERT(!info.clear_image_support().has_image_support());
    TS_ASSERT(!info.clear_max_parameter_size().has_max_parameter_size());
    TS_ASSERT(!info.clear_max_samplers().has_max_samplers());
    TS_ASSERT(!info.clear_mem_base_addr_align().has_mem_base_addr_align());
    TS_ASSERT(!info.clear_min_data_type_align_size().has_min_data_type_align_size());
    TS_ASSERT(!info.clear_single_fp_config().has_single_fp_config());
    TS_ASSERT(!info.clear_global_mem_cache_type().has_global_mem_cache_type());
    TS_ASSERT(!info.clear_global_mem_cacheline_size().has_global_mem_cacheline_size());
    TS_ASSERT(!info.clear_global_mem_cache_size().has_global_mem_cache_size());
    TS_ASSERT(!info.clear_global_mem_size().has_global_mem_size());
    TS_ASSERT(!info.clear_max_constant_buffer_size().has_max_constant_buffer_size());
    TS_ASSERT(!info.clear_max_constant_args().has_max_constant_args());
    TS_ASSERT(!info.clear_local_mem_type().has_local_mem_type());
    TS_ASSERT(!info.clear_local_mem_size().has_local_mem_size());
    TS_ASSERT(!info.clear_error_correction_support().has_error_correction_support());
    TS_ASSERT(!info.clear_profiling_timer_resolution().has_profiling_timer_resolution());
    TS_ASSERT(!info.clear_endian_little().has_endian_little());
    TS_ASSERT(!info.clear_available().has_available());
    TS_ASSERT(!info.clear_compiler_available().has_compiler_available());
    TS_ASSERT(!info.clear_execution_capabilities().has_execution_capabilities());
    TS_ASSERT(!info.clear_queue_properties().has_queue_properties());
    TS_ASSERT(!info.clear_name().has_name());
    TS_ASSERT(!info.clear_vendor().has_vendor());
    TS_ASSERT(!info.clear_driver_version().has_driver_version());
    TS_ASSERT(!info.clear_profile().has_profile());
    TS_ASSERT(!info.clear_version().has_version());
    TS_ASSERT(!info.clear_extensions().has_extensions());
    TS_ASSERT(!info.clear_platform_id().has_platform_id());
    TS_ASSERT(!info.clear_double_fp_config().has_double_fp_config());
    TS_ASSERT(!info.clear_preferred_vector_width_half().has_preferred_vector_width_half());
    TS_ASSERT(!info.clear_host_unified_memory().has_host_unified_memory());
    TS_ASSERT(!info.clear_native_vector_width_char().has_native_vector_width_char());
    TS_ASSERT(!info.clear_native_vector_width_short().has_native_vector_width_short());
    TS_ASSERT(!info.clear_native_vector_width_int().has_native_vector_width_int());
    TS_ASSERT(!info.clear_native_vector_width_long().has_native_vector_width_long());
    TS_ASSERT(!info.clear_native_vector_width_float().has_native_vector_width_float());
    TS_ASSERT(!info.clear_native_vector_width_double().has_native_vector_width_double());
    TS_ASSERT(!info.clear_native_vector_width_half().has_native_vector_width_half());
    TS_ASSERT(!info.clear_opencl_c_version().has_opencl_c_version());
    TS_ASSERT(!info.clear_linker_available().has_linker_available());
    TS_ASSERT(!info.clear_built_in_kernels().has_built_in_kernels());
    TS_ASSERT(!info.clear_image_max_buffer_size().has_image_max_buffer_size());
    TS_ASSERT(!info.clear_image_max_array_size().has_image_max_array_size());
    TS_ASSERT(!info.clear_parent_device_id().has_parent_device_id());
    TS_ASSERT(!info.clear_partition_max_sub_devices().has_partition_max_sub_devices());
    TS_ASSERT(!info.clear_partition_properties().has_partition_properties());
    TS_ASSERT(!info.clear_partition_affinity_domain().has_partition_affinity_domain());
    TS_ASSERT(!info.clear_partition_type().has_partition_type());
    TS_ASSERT(!info.clear_reference_count().has_reference_count());
    TS_ASSERT(!info.clear_preferred_interop_user_sync().has_preferred_interop_user_sync());
    TS_ASSERT(!info.clear_printf_buffer_size().has_printf_buffer_size());
    TS_ASSERT(!info.clear_image_pitch_alignment().has_image_pitch_alignment());
    TS_ASSERT(!info.clear_image_base_address_alignment().has_image_base_address_alignment());
  }
  /** // doc: test_eq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_1()
  {
    TS_ASSERT((Device_Info() == Device_Info()));
  }
  /** // doc: test_eq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_2()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };

    // Note, we test separately each attribute
    TS_ASSERT(!(Device_Info().set_id(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_type(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_vendor_id(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_compute_units(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_work_item_dimensions(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_work_group_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_char(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_short(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_int(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_long(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_float(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_double(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_clock_frequency(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_address_bits(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_read_image_args(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_write_image_args(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_mem_alloc_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image2d_max_width(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image2d_max_height(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image3d_max_width(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image3d_max_height(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image3d_max_depth(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image_support(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_parameter_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_samplers(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_mem_base_addr_align(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_min_data_type_align_size(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_single_fp_config(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_global_mem_cache_type(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_global_mem_cacheline_size(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_global_mem_cache_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_global_mem_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_constant_buffer_size(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_max_constant_args(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_local_mem_type(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_local_mem_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_error_correction_support(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_profiling_timer_resolution(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_endian_little(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_available(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_compiler_available(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_execution_capabilities(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_queue_properties(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_name("_name") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_vendor("_vendor") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_driver_version("_driver_version") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_profile("_profile") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_version("_version") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_extensions("_extensions") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_platform_id(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_double_fp_config(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_half(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_host_unified_memory(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_char(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_short(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_int(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_long(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_float(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_double(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_native_vector_width_half(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_opencl_c_version("_opencl_c_version") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_linker_available(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_built_in_kernels("_built_in_kernels") == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image_max_buffer_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image_max_array_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_parent_device_id(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_partition_max_sub_devices(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_partition_affinity_domain(0x1234) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_reference_count(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_preferred_interop_user_sync(0) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_printf_buffer_size(0x1234ul) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image_pitch_alignment(0x1234u) == Device_Info()));
    TS_ASSERT(!(Device_Info().set_image_base_address_alignment(0x1234u) == Device_Info()));
  }
  /** // doc: test_eq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_3()
  {
    TS_ASSERT(!(Device_Info_Fixtures::_1() == Device_Info_Fixtures::_2()));
  }
  /** // doc: test_eq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_4()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };

    TS_ASSERT((Device_Info().set_id(0x1234ul) == Device_Info().set_id(0x1234ul)));
    TS_ASSERT((Device_Info().set_type(0x1234ul) == Device_Info().set_type(0x1234ul)));
    TS_ASSERT((Device_Info().set_vendor_id(0x1234u) == Device_Info().set_vendor_id(0x1234u)));
    TS_ASSERT((Device_Info().set_max_compute_units(0x1234u) == Device_Info().set_max_compute_units(0x1234u)));
    TS_ASSERT((Device_Info().set_max_work_item_dimensions(0x1234u) == Device_Info().set_max_work_item_dimensions(0x1234u)));
    TS_ASSERT((Device_Info().set_max_work_group_size(0x1234ul) == Device_Info().set_max_work_group_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) == Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3))));
    TS_ASSERT((Device_Info().set_preferred_vector_width_char(0x1234u) == Device_Info().set_preferred_vector_width_char(0x1234u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_short(0x1234u) == Device_Info().set_preferred_vector_width_short(0x1234u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_int(0x1234u) == Device_Info().set_preferred_vector_width_int(0x1234u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_long(0x1234u) == Device_Info().set_preferred_vector_width_long(0x1234u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_float(0x1234u) == Device_Info().set_preferred_vector_width_float(0x1234u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_double(0x1234u) == Device_Info().set_preferred_vector_width_double(0x1234u)));
    TS_ASSERT((Device_Info().set_max_clock_frequency(0x1234u) == Device_Info().set_max_clock_frequency(0x1234u)));
    TS_ASSERT((Device_Info().set_address_bits(0x1234u) == Device_Info().set_address_bits(0x1234u)));
    TS_ASSERT((Device_Info().set_max_read_image_args(0x1234u) == Device_Info().set_max_read_image_args(0x1234u)));
    TS_ASSERT((Device_Info().set_max_write_image_args(0x1234u) == Device_Info().set_max_write_image_args(0x1234u)));
    TS_ASSERT((Device_Info().set_max_mem_alloc_size(0x1234ul) == Device_Info().set_max_mem_alloc_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_image2d_max_width(0x1234ul) == Device_Info().set_image2d_max_width(0x1234ul)));
    TS_ASSERT((Device_Info().set_image2d_max_height(0x1234ul) == Device_Info().set_image2d_max_height(0x1234ul)));
    TS_ASSERT((Device_Info().set_image3d_max_width(0x1234ul) == Device_Info().set_image3d_max_width(0x1234ul)));
    TS_ASSERT((Device_Info().set_image3d_max_height(0x1234ul) == Device_Info().set_image3d_max_height(0x1234ul)));
    TS_ASSERT((Device_Info().set_image3d_max_depth(0x1234ul) == Device_Info().set_image3d_max_depth(0x1234ul)));
    TS_ASSERT((Device_Info().set_image_support(0) == Device_Info().set_image_support(0)));
    TS_ASSERT((Device_Info().set_max_parameter_size(0x1234ul) == Device_Info().set_max_parameter_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_max_samplers(0x1234u) == Device_Info().set_max_samplers(0x1234u)));
    TS_ASSERT((Device_Info().set_mem_base_addr_align(0x1234u) == Device_Info().set_mem_base_addr_align(0x1234u)));
    TS_ASSERT((Device_Info().set_min_data_type_align_size(0x1234u) == Device_Info().set_min_data_type_align_size(0x1234u)));
    TS_ASSERT((Device_Info().set_single_fp_config(0x1234) == Device_Info().set_single_fp_config(0x1234)));
    TS_ASSERT((Device_Info().set_global_mem_cache_type(0x1234) == Device_Info().set_global_mem_cache_type(0x1234)));
    TS_ASSERT((Device_Info().set_global_mem_cacheline_size(0x1234u) == Device_Info().set_global_mem_cacheline_size(0x1234u)));
    TS_ASSERT((Device_Info().set_global_mem_cache_size(0x1234ul) == Device_Info().set_global_mem_cache_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_global_mem_size(0x1234ul) == Device_Info().set_global_mem_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_max_constant_buffer_size(0x1234u) == Device_Info().set_max_constant_buffer_size(0x1234u)));
    TS_ASSERT((Device_Info().set_max_constant_args(0x1234u) == Device_Info().set_max_constant_args(0x1234u)));
    TS_ASSERT((Device_Info().set_local_mem_type(0x1234) == Device_Info().set_local_mem_type(0x1234)));
    TS_ASSERT((Device_Info().set_local_mem_size(0x1234ul) == Device_Info().set_local_mem_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_error_correction_support(0) == Device_Info().set_error_correction_support(0)));
    TS_ASSERT((Device_Info().set_profiling_timer_resolution(0x1234ul) == Device_Info().set_profiling_timer_resolution(0x1234ul)));
    TS_ASSERT((Device_Info().set_endian_little(0) == Device_Info().set_endian_little(0)));
    TS_ASSERT((Device_Info().set_available(0) == Device_Info().set_available(0)));
    TS_ASSERT((Device_Info().set_compiler_available(0) == Device_Info().set_compiler_available(0)));
    TS_ASSERT((Device_Info().set_execution_capabilities(0x1234) == Device_Info().set_execution_capabilities(0x1234)));
    TS_ASSERT((Device_Info().set_queue_properties(0x1234) == Device_Info().set_queue_properties(0x1234)));
    TS_ASSERT((Device_Info().set_name("_name") == Device_Info().set_name("_name")));
    TS_ASSERT((Device_Info().set_vendor("_vendor") == Device_Info().set_vendor("_vendor")));
    TS_ASSERT((Device_Info().set_driver_version("_driver_version") == Device_Info().set_driver_version("_driver_version")));
    TS_ASSERT((Device_Info().set_profile("_profile") == Device_Info().set_profile("_profile")));
    TS_ASSERT((Device_Info().set_version("_version") == Device_Info().set_version("_version")));
    TS_ASSERT((Device_Info().set_extensions("_extensions") == Device_Info().set_extensions("_extensions")));
    TS_ASSERT((Device_Info().set_platform_id(0x1234ul) == Device_Info().set_platform_id(0x1234ul)));
    TS_ASSERT((Device_Info().set_double_fp_config(0x1234) == Device_Info().set_double_fp_config(0x1234)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_half(0x1234u) == Device_Info().set_preferred_vector_width_half(0x1234u)));
    TS_ASSERT((Device_Info().set_host_unified_memory(0) == Device_Info().set_host_unified_memory(0)));
    TS_ASSERT((Device_Info().set_native_vector_width_char(0x1234u) == Device_Info().set_native_vector_width_char(0x1234u)));
    TS_ASSERT((Device_Info().set_native_vector_width_short(0x1234u) == Device_Info().set_native_vector_width_short(0x1234u)));
    TS_ASSERT((Device_Info().set_native_vector_width_int(0x1234u) == Device_Info().set_native_vector_width_int(0x1234u)));
    TS_ASSERT((Device_Info().set_native_vector_width_long(0x1234u) == Device_Info().set_native_vector_width_long(0x1234u)));
    TS_ASSERT((Device_Info().set_native_vector_width_float(0x1234u) == Device_Info().set_native_vector_width_float(0x1234u)));
    TS_ASSERT((Device_Info().set_native_vector_width_double(0x1234u) == Device_Info().set_native_vector_width_double(0x1234u)));
    TS_ASSERT((Device_Info().set_native_vector_width_half(0x1234u) == Device_Info().set_native_vector_width_half(0x1234u)));
    TS_ASSERT((Device_Info().set_opencl_c_version("_opencl_c_version") == Device_Info().set_opencl_c_version("_opencl_c_version")));
    TS_ASSERT((Device_Info().set_linker_available(0) == Device_Info().set_linker_available(0)));
    TS_ASSERT((Device_Info().set_built_in_kernels("_built_in_kernels") == Device_Info().set_built_in_kernels("_built_in_kernels")));
    TS_ASSERT((Device_Info().set_image_max_buffer_size(0x1234ul) == Device_Info().set_image_max_buffer_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_image_max_array_size(0x1234ul) == Device_Info().set_image_max_array_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_parent_device_id(0x1234ul) == Device_Info().set_parent_device_id(0x1234ul)));
    TS_ASSERT((Device_Info().set_partition_max_sub_devices(0x1234u) == Device_Info().set_partition_max_sub_devices(0x1234u)));
    TS_ASSERT((Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)) == Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2))));
    TS_ASSERT((Device_Info().set_partition_affinity_domain(0x1234) == Device_Info().set_partition_affinity_domain(0x1234)));
    TS_ASSERT((Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)) == Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2))));
    TS_ASSERT((Device_Info().set_reference_count(0x1234u) == Device_Info().set_reference_count(0x1234u)));
    TS_ASSERT((Device_Info().set_preferred_interop_user_sync(0) == Device_Info().set_preferred_interop_user_sync(0)));
    TS_ASSERT((Device_Info().set_printf_buffer_size(0x1234ul) == Device_Info().set_printf_buffer_size(0x1234ul)));
    TS_ASSERT((Device_Info().set_image_pitch_alignment(0x1234u) == Device_Info().set_image_pitch_alignment(0x1234u)));
    TS_ASSERT((Device_Info().set_image_base_address_alignment(0x1234u) == Device_Info().set_image_base_address_alignment(0x1234u)));
  }
  /** // doc: test_neq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_1()
  {
    TS_ASSERT(!(Device_Info() != Device_Info()));
  }
  /** // doc: test_neq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_2()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };

    TS_ASSERT((Device_Info().set_id(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_type(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_vendor_id(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_compute_units(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_work_item_dimensions(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_work_group_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_char(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_short(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_int(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_long(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_float(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_double(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_clock_frequency(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_address_bits(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_read_image_args(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_write_image_args(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_mem_alloc_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image2d_max_width(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image2d_max_height(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image3d_max_width(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image3d_max_height(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image3d_max_depth(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image_support(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_parameter_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_samplers(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_mem_base_addr_align(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_min_data_type_align_size(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_single_fp_config(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_global_mem_cache_type(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_global_mem_cacheline_size(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_global_mem_cache_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_global_mem_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_constant_buffer_size(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_max_constant_args(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_local_mem_type(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_local_mem_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_error_correction_support(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_profiling_timer_resolution(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_endian_little(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_available(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_compiler_available(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_execution_capabilities(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_queue_properties(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_name("_name") != Device_Info()));
    TS_ASSERT((Device_Info().set_vendor("_vendor") != Device_Info()));
    TS_ASSERT((Device_Info().set_driver_version("_driver_version") != Device_Info()));
    TS_ASSERT((Device_Info().set_profile("_profile") != Device_Info()));
    TS_ASSERT((Device_Info().set_version("_version") != Device_Info()));
    TS_ASSERT((Device_Info().set_extensions("_extensions") != Device_Info()));
    TS_ASSERT((Device_Info().set_platform_id(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_double_fp_config(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_vector_width_half(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_host_unified_memory(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_char(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_short(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_int(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_long(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_float(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_double(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_native_vector_width_half(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_opencl_c_version("_opencl_c_version") != Device_Info()));
    TS_ASSERT((Device_Info().set_linker_available(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_built_in_kernels("_built_in_kernels") != Device_Info()));
    TS_ASSERT((Device_Info().set_image_max_buffer_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image_max_array_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_parent_device_id(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_partition_max_sub_devices(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)) != Device_Info()));
    TS_ASSERT((Device_Info().set_partition_affinity_domain(0x1234) != Device_Info()));
    TS_ASSERT((Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)) != Device_Info()));
    TS_ASSERT((Device_Info().set_reference_count(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_preferred_interop_user_sync(0) != Device_Info()));
    TS_ASSERT((Device_Info().set_printf_buffer_size(0x1234ul) != Device_Info()));
    TS_ASSERT((Device_Info().set_image_pitch_alignment(0x1234u) != Device_Info()));
    TS_ASSERT((Device_Info().set_image_base_address_alignment(0x1234u) != Device_Info()));
  }
  /** // doc: test_neq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_3()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    size_t max_work_item_sizes2[3] = { 3, 2, 1 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_properties2[2] = { 2, 1 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };
    cl_device_partition_property partition_type2[2] = { 2, 1 };

    TS_ASSERT((Device_Info().set_id(0x1234ul) != Device_Info().set_id(0x4321ul)));
    TS_ASSERT((Device_Info().set_type(0x1234ul) != Device_Info().set_type(0x4321ul)));
    TS_ASSERT((Device_Info().set_vendor_id(0x1234u) != Device_Info().set_vendor_id(0x4321u)));
    TS_ASSERT((Device_Info().set_max_compute_units(0x1234u) != Device_Info().set_max_compute_units(0x4321u)));
    TS_ASSERT((Device_Info().set_max_work_item_dimensions(0x1234u) != Device_Info().set_max_work_item_dimensions(0x4321u)));
    TS_ASSERT((Device_Info().set_max_work_group_size(0x1234ul) != Device_Info().set_max_work_group_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) != Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes2,max_work_item_sizes2+3))));
    TS_ASSERT((Device_Info().set_preferred_vector_width_char(0x1234u) != Device_Info().set_preferred_vector_width_char(0x4321u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_short(0x1234u) != Device_Info().set_preferred_vector_width_short(0x4321u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_int(0x1234u) != Device_Info().set_preferred_vector_width_int(0x4321u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_long(0x1234u) != Device_Info().set_preferred_vector_width_long(0x4321u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_float(0x1234u) != Device_Info().set_preferred_vector_width_float(0x4321u)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_double(0x1234u) != Device_Info().set_preferred_vector_width_double(0x4321u)));
    TS_ASSERT((Device_Info().set_max_clock_frequency(0x1234u) != Device_Info().set_max_clock_frequency(0x4321u)));
    TS_ASSERT((Device_Info().set_address_bits(0x1234u) != Device_Info().set_address_bits(0x4321u)));
    TS_ASSERT((Device_Info().set_max_read_image_args(0x1234u) != Device_Info().set_max_read_image_args(0x4321u)));
    TS_ASSERT((Device_Info().set_max_write_image_args(0x1234u) != Device_Info().set_max_write_image_args(0x4321u)));
    TS_ASSERT((Device_Info().set_max_mem_alloc_size(0x1234ul) != Device_Info().set_max_mem_alloc_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_image2d_max_width(0x1234ul) != Device_Info().set_image2d_max_width(0x4321ul)));
    TS_ASSERT((Device_Info().set_image2d_max_height(0x1234ul) != Device_Info().set_image2d_max_height(0x4321ul)));
    TS_ASSERT((Device_Info().set_image3d_max_width(0x1234ul) != Device_Info().set_image3d_max_width(0x4321ul)));
    TS_ASSERT((Device_Info().set_image3d_max_height(0x1234ul) != Device_Info().set_image3d_max_height(0x4321ul)));
    TS_ASSERT((Device_Info().set_image3d_max_depth(0x1234ul) != Device_Info().set_image3d_max_depth(0x4321ul)));
    TS_ASSERT((Device_Info().set_image_support(0) != Device_Info().set_image_support(1)));
    TS_ASSERT((Device_Info().set_max_parameter_size(0x1234ul) != Device_Info().set_max_parameter_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_max_samplers(0x1234u) != Device_Info().set_max_samplers(0x4321u)));
    TS_ASSERT((Device_Info().set_mem_base_addr_align(0x1234u) != Device_Info().set_mem_base_addr_align(0x4321u)));
    TS_ASSERT((Device_Info().set_min_data_type_align_size(0x1234u) != Device_Info().set_min_data_type_align_size(0x4321u)));
    TS_ASSERT((Device_Info().set_single_fp_config(0x1234) != Device_Info().set_single_fp_config(0x4321)));
    TS_ASSERT((Device_Info().set_global_mem_cache_type(0x1234) != Device_Info().set_global_mem_cache_type(0x4321)));
    TS_ASSERT((Device_Info().set_global_mem_cacheline_size(0x1234u) != Device_Info().set_global_mem_cacheline_size(0x4321u)));
    TS_ASSERT((Device_Info().set_global_mem_cache_size(0x1234ul) != Device_Info().set_global_mem_cache_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_global_mem_size(0x1234ul) != Device_Info().set_global_mem_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_max_constant_buffer_size(0x1234u) != Device_Info().set_max_constant_buffer_size(0x4321u)));
    TS_ASSERT((Device_Info().set_max_constant_args(0x1234u) != Device_Info().set_max_constant_args(0x4321u)));
    TS_ASSERT((Device_Info().set_local_mem_type(0x1234) != Device_Info().set_local_mem_type(0x4321)));
    TS_ASSERT((Device_Info().set_local_mem_size(0x1234ul) != Device_Info().set_local_mem_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_error_correction_support(0) != Device_Info().set_error_correction_support(1)));
    TS_ASSERT((Device_Info().set_profiling_timer_resolution(0x1234ul) != Device_Info().set_profiling_timer_resolution(0x4321ul)));
    TS_ASSERT((Device_Info().set_endian_little(0) != Device_Info().set_endian_little(1)));
    TS_ASSERT((Device_Info().set_available(0) != Device_Info().set_available(1)));
    TS_ASSERT((Device_Info().set_compiler_available(0) != Device_Info().set_compiler_available(1)));
    TS_ASSERT((Device_Info().set_execution_capabilities(0x1234) != Device_Info().set_execution_capabilities(0x4321)));
    TS_ASSERT((Device_Info().set_queue_properties(0x1234) != Device_Info().set_queue_properties(0x4321)));
    TS_ASSERT((Device_Info().set_name("_name") != Device_Info().set_name("x_namex")));
    TS_ASSERT((Device_Info().set_vendor("_vendor") != Device_Info().set_vendor("x_vendorx")));
    TS_ASSERT((Device_Info().set_driver_version("_driver_version") != Device_Info().set_driver_version("x_driver_versionx")));
    TS_ASSERT((Device_Info().set_profile("_profile") != Device_Info().set_profile("x_profilex")));
    TS_ASSERT((Device_Info().set_version("_version") != Device_Info().set_version("x_versionx")));
    TS_ASSERT((Device_Info().set_extensions("_extensions") != Device_Info().set_extensions("x_extensionsx")));
    TS_ASSERT((Device_Info().set_platform_id(0x1234ul) != Device_Info().set_platform_id(0x4321ul)));
    TS_ASSERT((Device_Info().set_double_fp_config(0x1234) != Device_Info().set_double_fp_config(0x4321)));
    TS_ASSERT((Device_Info().set_preferred_vector_width_half(0x1234u) != Device_Info().set_preferred_vector_width_half(0x4321u)));
    TS_ASSERT((Device_Info().set_host_unified_memory(0) != Device_Info().set_host_unified_memory(1)));
    TS_ASSERT((Device_Info().set_native_vector_width_char(0x1234u) != Device_Info().set_native_vector_width_char(0x4321u)));
    TS_ASSERT((Device_Info().set_native_vector_width_short(0x1234u) != Device_Info().set_native_vector_width_short(0x4321u)));
    TS_ASSERT((Device_Info().set_native_vector_width_int(0x1234u) != Device_Info().set_native_vector_width_int(0x4321u)));
    TS_ASSERT((Device_Info().set_native_vector_width_long(0x1234u) != Device_Info().set_native_vector_width_long(0x4321u)));
    TS_ASSERT((Device_Info().set_native_vector_width_float(0x1234u) != Device_Info().set_native_vector_width_float(0x4321u)));
    TS_ASSERT((Device_Info().set_native_vector_width_double(0x1234u) != Device_Info().set_native_vector_width_double(0x4321u)));
    TS_ASSERT((Device_Info().set_native_vector_width_half(0x1234u) != Device_Info().set_native_vector_width_half(0x4321u)));
    TS_ASSERT((Device_Info().set_opencl_c_version("_opencl_c_version") != Device_Info().set_opencl_c_version("x_opencl_c_versionx")));
    TS_ASSERT((Device_Info().set_linker_available(0) != Device_Info().set_linker_available(1)));
    TS_ASSERT((Device_Info().set_built_in_kernels("_built_in_kernels") != Device_Info().set_built_in_kernels("x_built_in_kernelsx")));
    TS_ASSERT((Device_Info().set_image_max_buffer_size(0x1234ul) != Device_Info().set_image_max_buffer_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_image_max_array_size(0x1234ul) != Device_Info().set_image_max_array_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_parent_device_id(0x1234ul) != Device_Info().set_parent_device_id(0x4321ul)));
    TS_ASSERT((Device_Info().set_partition_max_sub_devices(0x1234u) != Device_Info().set_partition_max_sub_devices(0x4321u)));
    TS_ASSERT((Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)) != Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties2,partition_properties2+2))));
    TS_ASSERT((Device_Info().set_partition_affinity_domain(0x1234) != Device_Info().set_partition_affinity_domain(0x4321)));
    TS_ASSERT((Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)) != Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type2,partition_type2+2))));
    TS_ASSERT((Device_Info().set_reference_count(0x1234u) != Device_Info().set_reference_count(0x4321u)));
    TS_ASSERT((Device_Info().set_preferred_interop_user_sync(0) != Device_Info().set_preferred_interop_user_sync(1)));
    TS_ASSERT((Device_Info().set_printf_buffer_size(0x1234ul) != Device_Info().set_printf_buffer_size(0x4321ul)));
    TS_ASSERT((Device_Info().set_image_pitch_alignment(0x1234u) != Device_Info().set_image_pitch_alignment(0x4321u)));
    TS_ASSERT((Device_Info().set_image_base_address_alignment(0x1234u) != Device_Info().set_image_base_address_alignment(0x4321u)));
  }
  /** // doc: test_neq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_4()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    cl_device_partition_property partition_properties1[2] = { 1, 2 };
    cl_device_partition_property partition_type1[2] = { 1, 2 };

    TS_ASSERT(!(Device_Info().set_id(0x1234ul) != Device_Info().set_id(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_type(0x1234ul) != Device_Info().set_type(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_vendor_id(0x1234u) != Device_Info().set_vendor_id(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_compute_units(0x1234u) != Device_Info().set_max_compute_units(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_work_item_dimensions(0x1234u) != Device_Info().set_max_work_item_dimensions(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_work_group_size(0x1234ul) != Device_Info().set_max_work_group_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) != Device_Info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3))));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_char(0x1234u) != Device_Info().set_preferred_vector_width_char(0x1234u)));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_short(0x1234u) != Device_Info().set_preferred_vector_width_short(0x1234u)));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_int(0x1234u) != Device_Info().set_preferred_vector_width_int(0x1234u)));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_long(0x1234u) != Device_Info().set_preferred_vector_width_long(0x1234u)));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_float(0x1234u) != Device_Info().set_preferred_vector_width_float(0x1234u)));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_double(0x1234u) != Device_Info().set_preferred_vector_width_double(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_clock_frequency(0x1234u) != Device_Info().set_max_clock_frequency(0x1234u)));
    TS_ASSERT(!(Device_Info().set_address_bits(0x1234u) != Device_Info().set_address_bits(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_read_image_args(0x1234u) != Device_Info().set_max_read_image_args(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_write_image_args(0x1234u) != Device_Info().set_max_write_image_args(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_mem_alloc_size(0x1234ul) != Device_Info().set_max_mem_alloc_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image2d_max_width(0x1234ul) != Device_Info().set_image2d_max_width(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image2d_max_height(0x1234ul) != Device_Info().set_image2d_max_height(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image3d_max_width(0x1234ul) != Device_Info().set_image3d_max_width(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image3d_max_height(0x1234ul) != Device_Info().set_image3d_max_height(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image3d_max_depth(0x1234ul) != Device_Info().set_image3d_max_depth(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image_support(0) != Device_Info().set_image_support(0)));
    TS_ASSERT(!(Device_Info().set_max_parameter_size(0x1234ul) != Device_Info().set_max_parameter_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_max_samplers(0x1234u) != Device_Info().set_max_samplers(0x1234u)));
    TS_ASSERT(!(Device_Info().set_mem_base_addr_align(0x1234u) != Device_Info().set_mem_base_addr_align(0x1234u)));
    TS_ASSERT(!(Device_Info().set_min_data_type_align_size(0x1234u) != Device_Info().set_min_data_type_align_size(0x1234u)));
    TS_ASSERT(!(Device_Info().set_single_fp_config(0x1234) != Device_Info().set_single_fp_config(0x1234)));
    TS_ASSERT(!(Device_Info().set_global_mem_cache_type(0x1234) != Device_Info().set_global_mem_cache_type(0x1234)));
    TS_ASSERT(!(Device_Info().set_global_mem_cacheline_size(0x1234u) != Device_Info().set_global_mem_cacheline_size(0x1234u)));
    TS_ASSERT(!(Device_Info().set_global_mem_cache_size(0x1234ul) != Device_Info().set_global_mem_cache_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_global_mem_size(0x1234ul) != Device_Info().set_global_mem_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_max_constant_buffer_size(0x1234u) != Device_Info().set_max_constant_buffer_size(0x1234u)));
    TS_ASSERT(!(Device_Info().set_max_constant_args(0x1234u) != Device_Info().set_max_constant_args(0x1234u)));
    TS_ASSERT(!(Device_Info().set_local_mem_type(0x1234) != Device_Info().set_local_mem_type(0x1234)));
    TS_ASSERT(!(Device_Info().set_local_mem_size(0x1234ul) != Device_Info().set_local_mem_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_error_correction_support(0) != Device_Info().set_error_correction_support(0)));
    TS_ASSERT(!(Device_Info().set_profiling_timer_resolution(0x1234ul) != Device_Info().set_profiling_timer_resolution(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_endian_little(0) != Device_Info().set_endian_little(0)));
    TS_ASSERT(!(Device_Info().set_available(0) != Device_Info().set_available(0)));
    TS_ASSERT(!(Device_Info().set_compiler_available(0) != Device_Info().set_compiler_available(0)));
    TS_ASSERT(!(Device_Info().set_execution_capabilities(0x1234) != Device_Info().set_execution_capabilities(0x1234)));
    TS_ASSERT(!(Device_Info().set_queue_properties(0x1234) != Device_Info().set_queue_properties(0x1234)));
    TS_ASSERT(!(Device_Info().set_name("_name") != Device_Info().set_name("_name")));
    TS_ASSERT(!(Device_Info().set_vendor("_vendor") != Device_Info().set_vendor("_vendor")));
    TS_ASSERT(!(Device_Info().set_driver_version("_driver_version") != Device_Info().set_driver_version("_driver_version")));
    TS_ASSERT(!(Device_Info().set_profile("_profile") != Device_Info().set_profile("_profile")));
    TS_ASSERT(!(Device_Info().set_version("_version") != Device_Info().set_version("_version")));
    TS_ASSERT(!(Device_Info().set_extensions("_extensions") != Device_Info().set_extensions("_extensions")));
    TS_ASSERT(!(Device_Info().set_platform_id(0x1234ul) != Device_Info().set_platform_id(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_double_fp_config(0x1234) != Device_Info().set_double_fp_config(0x1234)));
    TS_ASSERT(!(Device_Info().set_preferred_vector_width_half(0x1234u) != Device_Info().set_preferred_vector_width_half(0x1234u)));
    TS_ASSERT(!(Device_Info().set_host_unified_memory(0) != Device_Info().set_host_unified_memory(0)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_char(0x1234u) != Device_Info().set_native_vector_width_char(0x1234u)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_short(0x1234u) != Device_Info().set_native_vector_width_short(0x1234u)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_int(0x1234u) != Device_Info().set_native_vector_width_int(0x1234u)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_long(0x1234u) != Device_Info().set_native_vector_width_long(0x1234u)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_float(0x1234u) != Device_Info().set_native_vector_width_float(0x1234u)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_double(0x1234u) != Device_Info().set_native_vector_width_double(0x1234u)));
    TS_ASSERT(!(Device_Info().set_native_vector_width_half(0x1234u) != Device_Info().set_native_vector_width_half(0x1234u)));
    TS_ASSERT(!(Device_Info().set_opencl_c_version("_opencl_c_version") != Device_Info().set_opencl_c_version("_opencl_c_version")));
    TS_ASSERT(!(Device_Info().set_linker_available(0) != Device_Info().set_linker_available(0)));
    TS_ASSERT(!(Device_Info().set_built_in_kernels("_built_in_kernels") != Device_Info().set_built_in_kernels("_built_in_kernels")));
    TS_ASSERT(!(Device_Info().set_image_max_buffer_size(0x1234ul) != Device_Info().set_image_max_buffer_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image_max_array_size(0x1234ul) != Device_Info().set_image_max_array_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_parent_device_id(0x1234ul) != Device_Info().set_parent_device_id(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_partition_max_sub_devices(0x1234u) != Device_Info().set_partition_max_sub_devices(0x1234u)));
    TS_ASSERT(!(Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2)) != Device_Info().set_partition_properties(std::vector<cl_device_partition_property>(partition_properties1,partition_properties1+2))));
    TS_ASSERT(!(Device_Info().set_partition_affinity_domain(0x1234) != Device_Info().set_partition_affinity_domain(0x1234)));
    TS_ASSERT(!(Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2)) != Device_Info().set_partition_type(std::vector<cl_device_partition_property>(partition_type1,partition_type1+2))));
    TS_ASSERT(!(Device_Info().set_reference_count(0x1234u) != Device_Info().set_reference_count(0x1234u)));
    TS_ASSERT(!(Device_Info().set_preferred_interop_user_sync(0) != Device_Info().set_preferred_interop_user_sync(0)));
    TS_ASSERT(!(Device_Info().set_printf_buffer_size(0x1234ul) != Device_Info().set_printf_buffer_size(0x1234ul)));
    TS_ASSERT(!(Device_Info().set_image_pitch_alignment(0x1234u) != Device_Info().set_image_pitch_alignment(0x1234u)));
    TS_ASSERT(!(Device_Info().set_image_base_address_alignment(0x1234u) != Device_Info().set_image_base_address_alignment(0x1234u)));
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor()
  {
    Device_Info a(Device_Info_Fixtures::_1());
    Device_Info b(a);
    TS_ASSERT((a == b));
  }
  /** // doc: test_assign_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign_op()
  {
    Device_Info a(Device_Info_Fixtures::_1());
    Device_Info b;
    b = a;
    TS_ASSERT((a == b));
  }
};

#endif /* DIMBO_CLINFO_DEVICE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
