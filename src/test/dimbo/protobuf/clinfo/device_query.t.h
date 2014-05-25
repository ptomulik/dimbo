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

// dimbo/protobuf/clinfo/device_query.t.h

/** // doc: dimbo/protobuf/clinfo/device_query.t.h {{{
 * \file dimbo/protobuf/clinfo/device_query.t.h
 * \brief Unit tests for Dimbo::Clinfo::Device_Query
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_T_H_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/protobuf/clinfo/device_query.hpp>
#include <dimbo/protobuf/clinfo/device_query_fixtures.hpp>
#include <dimbo/clinfo/device_query_fixtures.hpp>

namespace Dimbo { namespace Protobuf { namespace Clinfo { class Device_Query_TestSuite; } } }

/** // doc: class Dimbo::Protobuf::Clinfo::Device_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Protobuf::Clinfo::Device_Query_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_write_default() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_default( )
  {
    Dimbo::Clinfo::Device_Query query;
    Device_Query buf;

    write(buf,query);

    TS_ASSERT(!buf.has_type_selected());
    TS_ASSERT(!buf.has_vendor_id_selected());
    TS_ASSERT(!buf.has_max_compute_units_selected());
    TS_ASSERT(!buf.has_max_work_item_dimensions_selected());
    TS_ASSERT(!buf.has_max_work_group_size_selected());
    TS_ASSERT(!buf.has_max_work_item_sizes_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_char_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_short_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_int_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_long_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_float_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_double_selected());
    TS_ASSERT(!buf.has_max_clock_frequency_selected());
    TS_ASSERT(!buf.has_address_bits_selected());
    TS_ASSERT(!buf.has_max_read_image_args_selected());
    TS_ASSERT(!buf.has_max_write_image_args_selected());
    TS_ASSERT(!buf.has_max_mem_alloc_size_selected());
    TS_ASSERT(!buf.has_image2d_max_width_selected());
    TS_ASSERT(!buf.has_image2d_max_height_selected());
    TS_ASSERT(!buf.has_image3d_max_width_selected());
    TS_ASSERT(!buf.has_image3d_max_height_selected());
    TS_ASSERT(!buf.has_image3d_max_depth_selected());
    TS_ASSERT(!buf.has_image_support_selected());
    TS_ASSERT(!buf.has_max_parameter_size_selected());
    TS_ASSERT(!buf.has_max_samplers_selected());
    TS_ASSERT(!buf.has_mem_base_addr_align_selected());
    TS_ASSERT(!buf.has_min_data_type_align_size_selected());
    TS_ASSERT(!buf.has_single_fp_config_selected());
    TS_ASSERT(!buf.has_global_mem_cache_type_selected());
    TS_ASSERT(!buf.has_global_mem_cacheline_size_selected());
    TS_ASSERT(!buf.has_global_mem_cache_size_selected());
    TS_ASSERT(!buf.has_global_mem_size_selected());
    TS_ASSERT(!buf.has_max_constant_buffer_size_selected());
    TS_ASSERT(!buf.has_max_constant_args_selected());
    TS_ASSERT(!buf.has_local_mem_type_selected());
    TS_ASSERT(!buf.has_local_mem_size_selected());
    TS_ASSERT(!buf.has_error_correction_support_selected());
    TS_ASSERT(!buf.has_profiling_timer_resolution_selected());
    TS_ASSERT(!buf.has_endian_little_selected());
    TS_ASSERT(!buf.has_available_selected());
    TS_ASSERT(!buf.has_compiler_available_selected());
    TS_ASSERT(!buf.has_execution_capabilities_selected());
    TS_ASSERT(!buf.has_queue_properties_selected());
    TS_ASSERT(!buf.has_name_selected());
    TS_ASSERT(!buf.has_vendor_selected());
    TS_ASSERT(!buf.has_driver_version_selected());
    TS_ASSERT(!buf.has_profile_selected());
    TS_ASSERT(!buf.has_version_selected());
    TS_ASSERT(!buf.has_extensions_selected());
    TS_ASSERT(!buf.has_platform_id_selected());
    TS_ASSERT(!buf.has_double_fp_config_selected());
    TS_ASSERT(!buf.has_preferred_vector_width_half_selected());
    TS_ASSERT(!buf.has_host_unified_memory_selected());
    TS_ASSERT(!buf.has_native_vector_width_char_selected());
    TS_ASSERT(!buf.has_native_vector_width_short_selected());
    TS_ASSERT(!buf.has_native_vector_width_int_selected());
    TS_ASSERT(!buf.has_native_vector_width_long_selected());
    TS_ASSERT(!buf.has_native_vector_width_float_selected());
    TS_ASSERT(!buf.has_native_vector_width_double_selected());
    TS_ASSERT(!buf.has_native_vector_width_half_selected());
    TS_ASSERT(!buf.has_opencl_c_version_selected());
    TS_ASSERT(!buf.has_linker_available_selected());
    TS_ASSERT(!buf.has_built_in_kernels_selected());
    TS_ASSERT(!buf.has_image_max_buffer_size_selected());
    TS_ASSERT(!buf.has_image_max_array_size_selected());
    TS_ASSERT(!buf.has_parent_device_id_selected());
    TS_ASSERT(!buf.has_partition_max_sub_devices_selected());
    TS_ASSERT(!buf.has_partition_properties_selected());
    TS_ASSERT(!buf.has_partition_affinity_domain_selected());
    TS_ASSERT(!buf.has_partition_type_selected());
    TS_ASSERT(!buf.has_reference_count_selected());
    TS_ASSERT(!buf.has_preferred_interop_user_sync_selected());
    TS_ASSERT(!buf.has_printf_buffer_size_selected());
    TS_ASSERT(!buf.has_image_pitch_alignment_selected());
    TS_ASSERT(!buf.has_image_base_address_alignment_selected());
  }
  /** // doc: test_write_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_1( )
  {
    Dimbo::Clinfo::Device_Query query(false);
    Device_Query buf;

    write(buf,query);

    TS_ASSERT(buf.has_type_selected() && !buf.type_selected());
    TS_ASSERT(buf.has_vendor_id_selected() && !buf.vendor_id_selected());
    TS_ASSERT(buf.has_max_compute_units_selected() && !buf.max_compute_units_selected());
    TS_ASSERT(buf.has_max_work_item_dimensions_selected() && !buf.max_work_item_dimensions_selected());
    TS_ASSERT(buf.has_max_work_group_size_selected() && !buf.max_work_group_size_selected());
    TS_ASSERT(buf.has_max_work_item_sizes_selected() && !buf.max_work_item_sizes_selected());
    TS_ASSERT(buf.has_preferred_vector_width_char_selected() && !buf.preferred_vector_width_char_selected());
    TS_ASSERT(buf.has_preferred_vector_width_short_selected() && !buf.preferred_vector_width_short_selected());
    TS_ASSERT(buf.has_preferred_vector_width_int_selected() && !buf.preferred_vector_width_int_selected());
    TS_ASSERT(buf.has_preferred_vector_width_long_selected() && !buf.preferred_vector_width_long_selected());
    TS_ASSERT(buf.has_preferred_vector_width_float_selected() && !buf.preferred_vector_width_float_selected());
    TS_ASSERT(buf.has_preferred_vector_width_double_selected() && !buf.preferred_vector_width_double_selected());
    TS_ASSERT(buf.has_max_clock_frequency_selected() && !buf.max_clock_frequency_selected());
    TS_ASSERT(buf.has_address_bits_selected() && !buf.address_bits_selected());
    TS_ASSERT(buf.has_max_read_image_args_selected() && !buf.max_read_image_args_selected());
    TS_ASSERT(buf.has_max_write_image_args_selected() && !buf.max_write_image_args_selected());
    TS_ASSERT(buf.has_max_mem_alloc_size_selected() && !buf.max_mem_alloc_size_selected());
    TS_ASSERT(buf.has_image2d_max_width_selected() && !buf.image2d_max_width_selected());
    TS_ASSERT(buf.has_image2d_max_height_selected() && !buf.image2d_max_height_selected());
    TS_ASSERT(buf.has_image3d_max_width_selected() && !buf.image3d_max_width_selected());
    TS_ASSERT(buf.has_image3d_max_height_selected() && !buf.image3d_max_height_selected());
    TS_ASSERT(buf.has_image3d_max_depth_selected() && !buf.image3d_max_depth_selected());
    TS_ASSERT(buf.has_image_support_selected() && !buf.image_support_selected());
    TS_ASSERT(buf.has_max_parameter_size_selected() && !buf.max_parameter_size_selected());
    TS_ASSERT(buf.has_max_samplers_selected() && !buf.max_samplers_selected());
    TS_ASSERT(buf.has_mem_base_addr_align_selected() && !buf.mem_base_addr_align_selected());
    TS_ASSERT(buf.has_min_data_type_align_size_selected() && !buf.min_data_type_align_size_selected());
    TS_ASSERT(buf.has_single_fp_config_selected() && !buf.single_fp_config_selected());
    TS_ASSERT(buf.has_global_mem_cache_type_selected() && !buf.global_mem_cache_type_selected());
    TS_ASSERT(buf.has_global_mem_cacheline_size_selected() && !buf.global_mem_cacheline_size_selected());
    TS_ASSERT(buf.has_global_mem_cache_size_selected() && !buf.global_mem_cache_size_selected());
    TS_ASSERT(buf.has_global_mem_size_selected() && !buf.global_mem_size_selected());
    TS_ASSERT(buf.has_max_constant_buffer_size_selected() && !buf.max_constant_buffer_size_selected());
    TS_ASSERT(buf.has_max_constant_args_selected() && !buf.max_constant_args_selected());
    TS_ASSERT(buf.has_local_mem_type_selected() && !buf.local_mem_type_selected());
    TS_ASSERT(buf.has_local_mem_size_selected() && !buf.local_mem_size_selected());
    TS_ASSERT(buf.has_error_correction_support_selected() && !buf.error_correction_support_selected());
    TS_ASSERT(buf.has_profiling_timer_resolution_selected() && !buf.profiling_timer_resolution_selected());
    TS_ASSERT(buf.has_endian_little_selected() && !buf.endian_little_selected());
    TS_ASSERT(buf.has_available_selected() && !buf.available_selected());
    TS_ASSERT(buf.has_compiler_available_selected() && !buf.compiler_available_selected());
    TS_ASSERT(buf.has_execution_capabilities_selected() && !buf.execution_capabilities_selected());
    TS_ASSERT(buf.has_queue_properties_selected() && !buf.queue_properties_selected());
    TS_ASSERT(buf.has_name_selected() && !buf.name_selected());
    TS_ASSERT(buf.has_vendor_selected() && !buf.vendor_selected());
    TS_ASSERT(buf.has_driver_version_selected() && !buf.driver_version_selected());
    TS_ASSERT(buf.has_profile_selected() && !buf.profile_selected());
    TS_ASSERT(buf.has_version_selected() && !buf.version_selected());
    TS_ASSERT(buf.has_extensions_selected() && !buf.extensions_selected());
    TS_ASSERT(buf.has_platform_id_selected() && !buf.platform_id_selected());
    TS_ASSERT(buf.has_double_fp_config_selected() && !buf.double_fp_config_selected());
    TS_ASSERT(buf.has_preferred_vector_width_half_selected() && !buf.preferred_vector_width_half_selected());
    TS_ASSERT(buf.has_host_unified_memory_selected() && !buf.host_unified_memory_selected());
    TS_ASSERT(buf.has_native_vector_width_char_selected() && !buf.native_vector_width_char_selected());
    TS_ASSERT(buf.has_native_vector_width_short_selected() && !buf.native_vector_width_short_selected());
    TS_ASSERT(buf.has_native_vector_width_int_selected() && !buf.native_vector_width_int_selected());
    TS_ASSERT(buf.has_native_vector_width_long_selected() && !buf.native_vector_width_long_selected());
    TS_ASSERT(buf.has_native_vector_width_float_selected() && !buf.native_vector_width_float_selected());
    TS_ASSERT(buf.has_native_vector_width_double_selected() && !buf.native_vector_width_double_selected());
    TS_ASSERT(buf.has_native_vector_width_half_selected() && !buf.native_vector_width_half_selected());
    TS_ASSERT(buf.has_opencl_c_version_selected() && !buf.opencl_c_version_selected());
    TS_ASSERT(buf.has_linker_available_selected() && !buf.linker_available_selected());
    TS_ASSERT(buf.has_built_in_kernels_selected() && !buf.built_in_kernels_selected());
    TS_ASSERT(buf.has_image_max_buffer_size_selected() && !buf.image_max_buffer_size_selected());
    TS_ASSERT(buf.has_image_max_array_size_selected() && !buf.image_max_array_size_selected());
    TS_ASSERT(buf.has_parent_device_id_selected() && !buf.parent_device_id_selected());
    TS_ASSERT(buf.has_partition_max_sub_devices_selected() && !buf.partition_max_sub_devices_selected());
    TS_ASSERT(buf.has_partition_properties_selected() && !buf.partition_properties_selected());
    TS_ASSERT(buf.has_partition_affinity_domain_selected() && !buf.partition_affinity_domain_selected());
    TS_ASSERT(buf.has_partition_type_selected() && !buf.partition_type_selected());
    TS_ASSERT(buf.has_reference_count_selected() && !buf.reference_count_selected());
    TS_ASSERT(buf.has_preferred_interop_user_sync_selected() && !buf.preferred_interop_user_sync_selected());
    TS_ASSERT(buf.has_printf_buffer_size_selected() && !buf.printf_buffer_size_selected());
    TS_ASSERT(buf.has_image_pitch_alignment_selected() && !buf.image_pitch_alignment_selected());
    TS_ASSERT(buf.has_image_base_address_alignment_selected() && !buf.image_base_address_alignment_selected());
  }
  /** // doc: test_read_default() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_default( )
  {
    Dimbo::Clinfo::Device_Query query(false);
    Device_Query buf;

    read(buf,query);

    TS_ASSERT((query == Dimbo::Clinfo::Device_Query()));
  }
  /** // doc: test_read_true() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_true( )
  {
    Dimbo::Clinfo::Device_Query query(false);
    Device_Query buf(Device_Query_Fixtures::_true());

    read(buf,query);

    TS_ASSERT((query == Dimbo::Clinfo::Device_Query(true)));
  }
  /** // doc: test_read_false() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_false( )
  {
    Dimbo::Clinfo::Device_Query query(true);
    Device_Query buf(Device_Query_Fixtures::_false());

    read(buf,query);

    TS_ASSERT((query == Dimbo::Clinfo::Device_Query(false)));
  }
};

#endif /* DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
