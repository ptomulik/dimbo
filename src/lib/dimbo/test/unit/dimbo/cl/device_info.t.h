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

// dimbo/test/unit/dimbo/cl/device_info.t.h

/** // doc: dimbo/test/unit/dimbo/cl/device_info.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/device_info.t.h
 * \brief Unit tests for Dimbo::Cl::Device_Info
 */ // }}}
#ifndef DIMBO_CL_DEVICE_INFO_T_H_INCLUDED
#define DIMBO_CL_DEVICE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/device_info.hpp>

namespace Dimbo { namespace Cl { class Device_Info_TestSuite; } }

/** // doc: class Dimbo::Cl::Device_Info_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Device_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(Device_Info d);
  }
  /** // doc: test_default_last_query() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_last_query( )
  {
    Device_Query empty;
    empty.select_none();
    TS_ASSERT_EQUALS(Device_Info().last_query(), empty);
  }
  /** // doc: test_default_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_id( )
  {
    TS_ASSERT_EQUALS(Device_Info().id(), 0);
  }
  /** // doc: test_default_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_type( )
  {
    TS_ASSERT_EQUALS(Device_Info().type(), 0);
  }
  /** // doc: test_default_vendor_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_vendor_id( )
  {
    TS_ASSERT_EQUALS(Device_Info().vendor_id(), 0);
  }
  /** // doc: test_default_max_compute_units() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_compute_units( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_compute_units(), 0);
  }
  /** // doc: test_default_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_work_item_dimensions( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_work_item_dimensions(), 0);
  }
  /** // doc: test_default_max_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_work_group_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_work_group_size(), 0);
  }
  /** // doc: test_default_max_work_item_sizes() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_work_item_sizes( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_work_item_sizes(), std::vector<size_t>());
  }
  /** // doc: test_default_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_char( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_char(), 0);
  }
  /** // doc: test_default_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_short( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_short(), 0);
  }
  /** // doc: test_default_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_int( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_int(), 0);
  }
  /** // doc: test_default_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_long( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_long(), 0);
  }
  /** // doc: test_default_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_float( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_float(), 0);
  }
  /** // doc: test_default_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_double( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_double(), 0);
  }
  /** // doc: test_default_max_clock_frequency() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_clock_frequency( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_clock_frequency(), 0);
  }
  /** // doc: test_default_address_bits() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_address_bits( )
  {
    TS_ASSERT_EQUALS(Device_Info().address_bits(), 0);
  }
  /** // doc: test_default_max_read_image_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_read_image_args( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_read_image_args(), 0);
  }
  /** // doc: test_default_max_write_image_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_write_image_args( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_write_image_args(), 0);
  }
  /** // doc: test_default_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_mem_alloc_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_mem_alloc_size(), 0);
  }
  /** // doc: test_default_image2d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image2d_max_width( )
  {
    TS_ASSERT_EQUALS(Device_Info().image2d_max_width(), 0);
  }
  /** // doc: test_default_image2d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image2d_max_height( )
  {
    TS_ASSERT_EQUALS(Device_Info().image2d_max_height(), 0);
  }
  /** // doc: test_default_image3d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image3d_max_width( )
  {
    TS_ASSERT_EQUALS(Device_Info().image3d_max_width(), 0);
  }
  /** // doc: test_default_image3d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image3d_max_height( )
  {
    TS_ASSERT_EQUALS(Device_Info().image3d_max_height(), 0);
  }
  /** // doc: test_default_image3d_max_depth() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image3d_max_depth( )
  {
    TS_ASSERT_EQUALS(Device_Info().image3d_max_depth(), 0);
  }
  /** // doc: test_default_image_support() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image_support( )
  {
    TS_ASSERT_EQUALS(Device_Info().image_support(), false);
  }
  /** // doc: test_default_max_parameter_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_parameter_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_parameter_size(), 0);
  }
  /** // doc: test_default_max_samplers() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_samplers( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_samplers(), 0);
  }
  /** // doc: test_default_mem_base_addr_align() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_mem_base_addr_align( )
  {
    TS_ASSERT_EQUALS(Device_Info().mem_base_addr_align(), 0);
  }
  /** // doc: test_default_min_data_type_align_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_min_data_type_align_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().min_data_type_align_size(), 0);
  }
  /** // doc: test_default_single_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_single_fp_config( )
  {
    TS_ASSERT_EQUALS(Device_Info().single_fp_config(), 0);
  }
  /** // doc: test_default_global_mem_cache_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_global_mem_cache_type( )
  {
    TS_ASSERT_EQUALS(Device_Info().global_mem_cache_type(), 0);
  }
  /** // doc: test_default_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_global_mem_cacheline_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().global_mem_cacheline_size(), 0);
  }
  /** // doc: test_default_global_mem_cache_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_global_mem_cache_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().global_mem_cache_size(), 0);
  }
  /** // doc: test_default_global_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_global_mem_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().global_mem_size(), 0);
  }
  /** // doc: test_default_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_constant_buffer_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_constant_buffer_size(), 0);
  }
  /** // doc: test_default_max_constant_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_max_constant_args( )
  {
    TS_ASSERT_EQUALS(Device_Info().max_constant_args(), 0);
  }
  /** // doc: test_default_local_mem_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_local_mem_type( )
  {
    TS_ASSERT_EQUALS(Device_Info().local_mem_type(), 0);
  }
  /** // doc: test_default_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_local_mem_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().local_mem_size(), 0);
  }
  /** // doc: test_default_error_correction_support() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_error_correction_support( )
  {
    TS_ASSERT_EQUALS(Device_Info().error_correction_support(), 0);
  }
  /** // doc: test_default_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_profiling_timer_resolution( )
  {
    TS_ASSERT_EQUALS(Device_Info().profiling_timer_resolution(), 0);
  }
  /** // doc: test_default_endian_little() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_endian_little( )
  {
    TS_ASSERT_EQUALS(Device_Info().endian_little(), false);
  }
  /** // doc: test_default_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_available( )
  {
    TS_ASSERT_EQUALS(Device_Info().available(), false);
  }
  /** // doc: test_default_compiler_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_compiler_available( )
  {
    TS_ASSERT_EQUALS(Device_Info().compiler_available(), false);
  }
  /** // doc: test_default_execution_capabilities() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_execution_capabilities( )
  {
    TS_ASSERT_EQUALS(Device_Info().execution_capabilities(), 0);
  }
  /** // doc: test_default_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_queue_properties( )
  {
    TS_ASSERT_EQUALS(Device_Info().queue_properties(), 0);
  }
  /** // doc: test_default_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_name( )
  {
    TS_ASSERT_EQUALS(Device_Info().name(), "");
  }
  /** // doc: test_default_vendor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_vendor( )
  {
    TS_ASSERT_EQUALS(Device_Info().vendor(), "");
  }
  /** // doc: test_default_driver_version() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_driver_version( )
  {
    TS_ASSERT_EQUALS(Device_Info().driver_version(), "");
  }
  /** // doc: test_default_profile() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_profile( )
  {
    TS_ASSERT_EQUALS(Device_Info().profile(), "");
  }
  /** // doc: test_default_version() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_version( )
  {
    TS_ASSERT_EQUALS(Device_Info().version(), "");
  }
  /** // doc: test_default_extensions() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_extensions( )
  {
    TS_ASSERT_EQUALS(Device_Info().extensions(), "");
  }
  /** // doc: test_default_platform_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_platform_id( )
  {
    TS_ASSERT_EQUALS(Device_Info().platform_id(), 0);
  }
  /** // doc: test_default_double_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_double_fp_config( )
  {
    TS_ASSERT_EQUALS(Device_Info().double_fp_config(), 0);
  }
  /** // doc: test_default_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_vector_width_half( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_vector_width_half(), 0);
  }
  /** // doc: test_default_host_unified_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_host_unified_memory( )
  {
    TS_ASSERT_EQUALS(Device_Info().host_unified_memory(), false);
  }
  /** // doc: test_default_native_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_char( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_char(), 0);
  }
  /** // doc: test_default_native_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_short( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_short(), 0);
  }
  /** // doc: test_default_native_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_int( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_int(), 0);
  }
  /** // doc: test_default_native_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_long( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_long(), 0);
  }
  /** // doc: test_default_native_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_float( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_float(), 0);
  }
  /** // doc: test_default_native_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_double( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_double(), 0);
  }
  /** // doc: test_default_native_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_native_vector_width_half( )
  {
    TS_ASSERT_EQUALS(Device_Info().native_vector_width_half(), 0);
  }
  /** // doc: test_default_opencl_c_version() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_opencl_c_version( )
  {
    TS_ASSERT_EQUALS(Device_Info().opencl_c_version(), "");
  }
  /** // doc: test_default_linker_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_linker_available( )
  {
    TS_ASSERT_EQUALS(Device_Info().linker_available(), false);
  }
  /** // doc: test_default_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_built_in_kernels( )
  {
    TS_ASSERT_EQUALS(Device_Info().built_in_kernels(), "");
  }
  /** // doc: test_default_image_max_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image_max_buffer_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().image_max_buffer_size(), 0);
  }
  /** // doc: test_default_image_max_array_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image_max_array_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().image_max_array_size(), 0);
  }
  /** // doc: test_default_parent_device_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_parent_device_id( )
  {
    TS_ASSERT_EQUALS(Device_Info().parent_device_id(), 0);
  }
  /** // doc: test_default_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_partition_max_sub_devices( )
  {
    TS_ASSERT_EQUALS(Device_Info().partition_max_sub_devices(), 0);
  }
  /** // doc: test_default_partition_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_partition_properties( )
  {
    TS_ASSERT_EQUALS(Device_Info().partition_properties(), std::vector<cl_device_partition_property>());
  }
  /** // doc: test_default_partition_affinity_domain() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_partition_affinity_domain( )
  {
    TS_ASSERT_EQUALS(Device_Info().partition_affinity_domain(), 0);
  }
  /** // doc: test_default_partition_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_partition_type( )
  {
    TS_ASSERT_EQUALS(Device_Info().partition_type(), std::vector<cl_device_partition_property>());
  }
  /** // doc: test_default_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_reference_count( )
  {
    TS_ASSERT_EQUALS(Device_Info().reference_count(), 0);
  }
  /** // doc: test_default_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_preferred_interop_user_sync( )
  {
    TS_ASSERT_EQUALS(Device_Info().preferred_interop_user_sync(), false);
  }
  /** // doc: test_default_printf_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_printf_buffer_size( )
  {
    TS_ASSERT_EQUALS(Device_Info().printf_buffer_size(), 0);
  }
  /** // doc: test_default_image_pitch_alignment() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image_pitch_alignment( )
  {
    TS_ASSERT_EQUALS(Device_Info().image_pitch_alignment(), 0);
  }
  /** // doc: test_default_image_base_address_alignment() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_image_base_address_alignment( )
  {
    TS_ASSERT_EQUALS(Device_Info().image_base_address_alignment(), 0);
  }
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    Device_Info info(d);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(info.id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[0]));
    TS_ASSERT_EQUALS(info.name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(info.vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(info.driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    Device_Info info(d);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(info.id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[1]));
    TS_ASSERT_EQUALS(info.name(), "Tesla C1060");
    TS_ASSERT_EQUALS(info.vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(info.driver_version(), "319.76");
    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_ctor_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_3( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    Device_Query q;

    q.select_none();
    q.select_name();

    Device_Info info(d,q);

    TS_ASSERT_EQUALS(info.last_query(), q);
    TS_ASSERT_EQUALS(info.name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
  }
};

#endif /* DIMBO_CL_DEVICE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
