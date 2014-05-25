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

// dimbo/cl/device_info.t.h

/** // doc: dimbo/cl/device_info.t.h {{{
 * \file dimbo/cl/device_info.t.h
 * \brief Unit tests for Dimbo::Clinfo::Device_Info
 */ // }}}
#ifndef DIMBO_CL_DEVICE_INFO_T_H_INCLUDED
#define DIMBO_CL_DEVICE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/protobuf/clinfo/device_info.hpp>
#include <dimbo/protobuf/clinfo/device_info_fixtures.hpp>
#include <dimbo/clinfo/device_info_fixtures.hpp>

namespace Dimbo { namespace Protobuf { namespace Clinfo { class Device_Info_TestSuite; } } }

/** // doc: class Dimbo::Clinfo::Device_Info_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Protobuf::Clinfo::Device_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_write_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_empty()
  {
    Dimbo::Clinfo::Device_Info info;
    Device_Info buf;

    write(buf,info);

    // Any smart way to check that all fields are cleared out?
    TS_ASSERT(!buf.has_id());
    TS_ASSERT(!buf.has_type());
    TS_ASSERT(!buf.has_vendor_id());
    TS_ASSERT(!buf.has_max_compute_units());
    TS_ASSERT(!buf.has_max_work_item_dimensions());
    TS_ASSERT(!buf.has_max_work_group_size());
    TS_ASSERT_EQUALS(buf.max_work_item_sizes_size(), 0ul);
    TS_ASSERT(!buf.has_preferred_vector_width_char());
    TS_ASSERT(!buf.has_preferred_vector_width_short());
    TS_ASSERT(!buf.has_preferred_vector_width_int());
    TS_ASSERT(!buf.has_preferred_vector_width_long());
    TS_ASSERT(!buf.has_preferred_vector_width_float());
    TS_ASSERT(!buf.has_preferred_vector_width_double());
    TS_ASSERT(!buf.has_max_clock_frequency());
    TS_ASSERT(!buf.has_address_bits());
    TS_ASSERT(!buf.has_max_read_image_args());
    TS_ASSERT(!buf.has_max_write_image_args());
    TS_ASSERT(!buf.has_max_mem_alloc_size());
    TS_ASSERT(!buf.has_image2d_max_width());
    TS_ASSERT(!buf.has_image2d_max_height());
    TS_ASSERT(!buf.has_image3d_max_width());
    TS_ASSERT(!buf.has_image3d_max_height());
    TS_ASSERT(!buf.has_image3d_max_depth());
    TS_ASSERT(!buf.has_image_support());
    TS_ASSERT(!buf.has_max_parameter_size());
    TS_ASSERT(!buf.has_max_samplers());
    TS_ASSERT(!buf.has_mem_base_addr_align());
    TS_ASSERT(!buf.has_min_data_type_align_size());
    TS_ASSERT(!buf.has_single_fp_config());
    TS_ASSERT(!buf.has_global_mem_cache_type());
    TS_ASSERT(!buf.has_global_mem_cacheline_size());
    TS_ASSERT(!buf.has_global_mem_cache_size());
    TS_ASSERT(!buf.has_global_mem_size());
    TS_ASSERT(!buf.has_max_constant_buffer_size());
    TS_ASSERT(!buf.has_max_constant_args());
    TS_ASSERT(!buf.has_local_mem_type());
    TS_ASSERT(!buf.has_local_mem_size());
    TS_ASSERT(!buf.has_error_correction_support());
    TS_ASSERT(!buf.has_profiling_timer_resolution());
    TS_ASSERT(!buf.has_endian_little());
    TS_ASSERT(!buf.has_available());
    TS_ASSERT(!buf.has_compiler_available());
    TS_ASSERT(!buf.has_execution_capabilities());
    TS_ASSERT(!buf.has_queue_properties());
    TS_ASSERT(!buf.has_name());
    TS_ASSERT(!buf.has_vendor());
    TS_ASSERT(!buf.has_driver_version());
    TS_ASSERT(!buf.has_profile());
    TS_ASSERT(!buf.has_version());
    TS_ASSERT(!buf.has_extensions());
    TS_ASSERT(!buf.has_platform_id());
    TS_ASSERT(!buf.has_double_fp_config());
    TS_ASSERT(!buf.has_preferred_vector_width_half());
    TS_ASSERT(!buf.has_host_unified_memory());
    TS_ASSERT(!buf.has_native_vector_width_char());
    TS_ASSERT(!buf.has_native_vector_width_short());
    TS_ASSERT(!buf.has_native_vector_width_int());
    TS_ASSERT(!buf.has_native_vector_width_long());
    TS_ASSERT(!buf.has_native_vector_width_float());
    TS_ASSERT(!buf.has_native_vector_width_double());
    TS_ASSERT(!buf.has_native_vector_width_half());
    TS_ASSERT(!buf.has_opencl_c_version());
    TS_ASSERT(!buf.has_linker_available());
    TS_ASSERT(!buf.has_built_in_kernels());
    TS_ASSERT(!buf.has_image_max_buffer_size());
    TS_ASSERT(!buf.has_image_max_array_size());
    TS_ASSERT(!buf.has_parent_device_id());
    TS_ASSERT(!buf.has_partition_max_sub_devices());
    TS_ASSERT_EQUALS(buf.partition_properties_size(), 0ul);
    TS_ASSERT(!buf.has_partition_affinity_domain());
    TS_ASSERT_EQUALS(buf.partition_type_size(), 0ul);
    TS_ASSERT(!buf.has_reference_count());
    TS_ASSERT(!buf.has_preferred_interop_user_sync());
    TS_ASSERT(!buf.has_printf_buffer_size());
    TS_ASSERT(!buf.has_image_pitch_alignment());
    TS_ASSERT(!buf.has_image_base_address_alignment());
  }
  /** // doc: test_write_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_1()
  {
    Dimbo::Clinfo::Device_Info info(Dimbo::Clinfo::Device_Info_Fixtures::_1());
    Device_Info fix(Device_Info_Fixtures::_1());
    Device_Info buf;

    write(buf, info);

    TS_ASSERT_EQUALS(buf.id(), fix.id());
    TS_ASSERT_EQUALS(buf.type(), fix.type());
    TS_ASSERT_EQUALS(buf.vendor_id(), fix.vendor_id());
    TS_ASSERT_EQUALS(buf.max_compute_units(), fix.max_compute_units());
    TS_ASSERT_EQUALS(buf.max_work_item_dimensions(), fix.max_work_item_dimensions());
    TS_ASSERT_EQUALS(buf.max_work_group_size(), fix.max_work_group_size());
    //TS_ASSERT_EQUALS(buf.max_work_item_sizes(), fix.max_work_item_sizes());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_char(), fix.preferred_vector_width_char());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_short(), fix.preferred_vector_width_short());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_int(), fix.preferred_vector_width_int());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_long(), fix.preferred_vector_width_long());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_float(), fix.preferred_vector_width_float());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_double(), fix.preferred_vector_width_double());
    TS_ASSERT_EQUALS(buf.max_clock_frequency(), fix.max_clock_frequency());
    TS_ASSERT_EQUALS(buf.address_bits(), fix.address_bits());
    TS_ASSERT_EQUALS(buf.max_read_image_args(), fix.max_read_image_args());
    TS_ASSERT_EQUALS(buf.max_write_image_args(), fix.max_write_image_args());
    TS_ASSERT_EQUALS(buf.max_mem_alloc_size(), fix.max_mem_alloc_size());
    TS_ASSERT_EQUALS(buf.image2d_max_width(), fix.image2d_max_width());
    TS_ASSERT_EQUALS(buf.image2d_max_height(), fix.image2d_max_height());
    TS_ASSERT_EQUALS(buf.image3d_max_width(), fix.image3d_max_width());
    TS_ASSERT_EQUALS(buf.image3d_max_height(), fix.image3d_max_height());
    TS_ASSERT_EQUALS(buf.image3d_max_depth(), fix.image3d_max_depth());
    TS_ASSERT_EQUALS(buf.image_support(), fix.image_support());
    TS_ASSERT_EQUALS(buf.max_parameter_size(), fix.max_parameter_size());
    TS_ASSERT_EQUALS(buf.max_samplers(), fix.max_samplers());
    TS_ASSERT_EQUALS(buf.mem_base_addr_align(), fix.mem_base_addr_align());
    TS_ASSERT_EQUALS(buf.min_data_type_align_size(), fix.min_data_type_align_size());
    TS_ASSERT_EQUALS(buf.single_fp_config(), fix.single_fp_config());
    TS_ASSERT_EQUALS(buf.global_mem_cache_type(), fix.global_mem_cache_type());
    TS_ASSERT_EQUALS(buf.global_mem_cacheline_size(), fix.global_mem_cacheline_size());
    TS_ASSERT_EQUALS(buf.global_mem_cache_size(), fix.global_mem_cache_size());
    TS_ASSERT_EQUALS(buf.global_mem_size(), fix.global_mem_size());
    TS_ASSERT_EQUALS(buf.max_constant_buffer_size(), fix.max_constant_buffer_size());
    TS_ASSERT_EQUALS(buf.max_constant_args(), fix.max_constant_args());
    TS_ASSERT_EQUALS(buf.local_mem_type(), fix.local_mem_type());
    TS_ASSERT_EQUALS(buf.local_mem_size(), fix.local_mem_size());
    TS_ASSERT_EQUALS(buf.error_correction_support(), fix.error_correction_support());
    TS_ASSERT_EQUALS(buf.profiling_timer_resolution(), fix.profiling_timer_resolution());
    TS_ASSERT_EQUALS(buf.endian_little(), fix.endian_little());
    TS_ASSERT_EQUALS(buf.available(), fix.available());
    TS_ASSERT_EQUALS(buf.compiler_available(), fix.compiler_available());
    TS_ASSERT_EQUALS(buf.execution_capabilities(), fix.execution_capabilities());
    TS_ASSERT_EQUALS(buf.queue_properties(), fix.queue_properties());
    TS_ASSERT_EQUALS(buf.name(), fix.name());
    TS_ASSERT_EQUALS(buf.vendor(), fix.vendor());
    TS_ASSERT_EQUALS(buf.driver_version(), fix.driver_version());
    TS_ASSERT_EQUALS(buf.profile(), fix.profile());
    TS_ASSERT_EQUALS(buf.version(), fix.version());
    TS_ASSERT_EQUALS(buf.extensions(), fix.extensions());
    TS_ASSERT_EQUALS(buf.platform_id(), fix.platform_id());
    TS_ASSERT_EQUALS(buf.double_fp_config(), fix.double_fp_config());
    TS_ASSERT_EQUALS(buf.preferred_vector_width_half(), fix.preferred_vector_width_half());
    TS_ASSERT_EQUALS(buf.host_unified_memory(), fix.host_unified_memory());
    TS_ASSERT_EQUALS(buf.native_vector_width_char(), fix.native_vector_width_char());
    TS_ASSERT_EQUALS(buf.native_vector_width_short(), fix.native_vector_width_short());
    TS_ASSERT_EQUALS(buf.native_vector_width_int(), fix.native_vector_width_int());
    TS_ASSERT_EQUALS(buf.native_vector_width_long(), fix.native_vector_width_long());
    TS_ASSERT_EQUALS(buf.native_vector_width_float(), fix.native_vector_width_float());
    TS_ASSERT_EQUALS(buf.native_vector_width_double(), fix.native_vector_width_double());
    TS_ASSERT_EQUALS(buf.native_vector_width_half(), fix.native_vector_width_half());
    TS_ASSERT_EQUALS(buf.opencl_c_version(), fix.opencl_c_version());
    TS_ASSERT_EQUALS(buf.linker_available(), fix.linker_available());
    TS_ASSERT_EQUALS(buf.built_in_kernels(), fix.built_in_kernels());
    TS_ASSERT_EQUALS(buf.image_max_buffer_size(), fix.image_max_buffer_size());
    TS_ASSERT_EQUALS(buf.image_max_array_size(), fix.image_max_array_size());
    TS_ASSERT_EQUALS(buf.parent_device_id(), fix.parent_device_id());
    TS_ASSERT_EQUALS(buf.partition_max_sub_devices(), fix.partition_max_sub_devices());
    //TS_ASSERT_EQUALS(buf.partition_properties(), fix.partition_properties());
    TS_ASSERT_EQUALS(buf.partition_affinity_domain(), fix.partition_affinity_domain());
    //TS_ASSERT_EQUALS(buf.partition_type(), fix.partition_type());
    TS_ASSERT_EQUALS(buf.reference_count(), fix.reference_count());
    TS_ASSERT_EQUALS(buf.preferred_interop_user_sync(), fix.preferred_interop_user_sync());
    TS_ASSERT_EQUALS(buf.printf_buffer_size(), fix.printf_buffer_size());
    TS_ASSERT_EQUALS(buf.image_pitch_alignment(), fix.image_pitch_alignment());
    TS_ASSERT_EQUALS(buf.image_base_address_alignment(), fix.image_base_address_alignment());
  }
  /** // doc: test_read_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_empty()
  {
    Dimbo::Clinfo::Device_Info info(Dimbo::Clinfo::Device_Info_Fixtures::_1());
    Device_Info buf;

    read(buf, info);

    TS_ASSERT((info == Dimbo::Clinfo::Device_Info()));
  }
  /** // doc: test_read_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_1()
  {
    Dimbo::Clinfo::Device_Info info;
    Device_Info buf(Device_Info_Fixtures::_1());

    read(buf, info);

    TS_ASSERT((info == Dimbo::Clinfo::Device_Info_Fixtures::_1()));
  }
};

#endif /* DIMBO_CL_DEVICE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
