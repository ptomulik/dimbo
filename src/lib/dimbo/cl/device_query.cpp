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

// dimbo/cl/device_query.cpp

/** // doc: dimbo/cl/device_query.cpp {{{
 * @file dimbo/cl/device_query.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/device_query.hpp>

namespace Dimbo {
namespace Cl {
Device_Query::
Device_Query()
{
  _init_device_query();
}

Device_Query::
~Device_Query()
{
}

Device_Query& Device_Query::
select_all()
{
  this -> select_id(true);
  this -> select_type(true);
  this -> select_vendor_id(true);
  this -> select_max_compute_units(true);
  this -> select_max_work_item_dimensions(true);
  this -> select_max_work_item_sizes(true);
  this -> select_max_work_group_size(true);
  this -> select_preferred_vector_width_char(true);
  this -> select_preferred_vector_width_short(true);
  this -> select_preferred_vector_width_int(true);
  this -> select_preferred_vector_width_long(true);
  this -> select_preferred_vector_width_float(true);
  this -> select_preferred_vector_width_double(true);
  this -> select_preferred_vector_width_half(true);
  this -> select_native_vector_width_char(true);
  this -> select_native_vector_width_short(true);
  this -> select_native_vector_width_int(true);
  this -> select_native_vector_width_long(true);
  this -> select_native_vector_width_float(true);
  this -> select_native_vector_width_double(true);
  this -> select_native_vector_width_half(true);
  this -> select_max_clock_frequency(true);
  this -> select_address_bits(true);
  this -> select_max_mem_alloc_size(true);
  this -> select_image_support(true);
  this -> select_max_read_image_args(true);
  this -> select_max_write_image_args(true);
  this -> select_image2d_max_width(true);
  this -> select_image2d_max_height(true);
  this -> select_image3d_max_width(true);
  this -> select_image3d_max_height(true);
  this -> select_image3d_max_depth(true);
  this -> select_max_samplers(true);
  this -> select_max_parameter_size(true);
  this -> select_mem_base_addr_align(true);
  this -> select_min_data_type_align_size(true);
  this -> select_single_fp_config(true);
  this -> select_global_mem_cache_type(true);
  this -> select_global_mem_cacheline_size(true);
  this -> select_global_mem_cache_size(true);
  this -> select_global_mem_size(true);
  this -> select_max_constant_args(true);
  this -> select_local_mem_type(true);
  this -> select_local_mem_size(true);
  this -> select_error_correction_support(true);
  this -> select_host_unified_memory(true);
  this -> select_profiling_timer_resolution(true);
  this -> select_endian_little(true);
  this -> select_available(true);
  this -> select_compiler_available(true);
  this -> select_execution_capabilities(true);
  this -> select_queue_properties(true);
  this -> select_platform_id(true);
  this -> select_name(true);
  this -> select_vendor(true);
  this -> select_driver_version(true);
  this -> select_profile(true);
  this -> select_version(true);
  this -> select_opencl_c_version(true);
  this -> select_extensions(true);
  return *this;
}

Device_Query& Device_Query::
select_none()
{
  this -> select_id(false);
  this -> select_type(false);
  this -> select_vendor_id(false);
  this -> select_max_compute_units(false);
  this -> select_max_work_item_dimensions(false);
  this -> select_max_work_item_sizes(false);
  this -> select_max_work_group_size(false);
  this -> select_preferred_vector_width_char(false);
  this -> select_preferred_vector_width_short(false);
  this -> select_preferred_vector_width_int(false);
  this -> select_preferred_vector_width_long(false);
  this -> select_preferred_vector_width_float(false);
  this -> select_preferred_vector_width_double(false);
  this -> select_preferred_vector_width_half(false);
  this -> select_native_vector_width_char(false);
  this -> select_native_vector_width_short(false);
  this -> select_native_vector_width_int(false);
  this -> select_native_vector_width_long(false);
  this -> select_native_vector_width_float(false);
  this -> select_native_vector_width_double(false);
  this -> select_native_vector_width_half(false);
  this -> select_max_clock_frequency(false);
  this -> select_address_bits(false);
  this -> select_max_mem_alloc_size(false);
  this -> select_image_support(false);
  this -> select_max_read_image_args(false);
  this -> select_max_write_image_args(false);
  this -> select_image2d_max_width(false);
  this -> select_image2d_max_height(false);
  this -> select_image3d_max_width(false);
  this -> select_image3d_max_height(false);
  this -> select_image3d_max_depth(false);
  this -> select_max_samplers(false);
  this -> select_max_parameter_size(false);
  this -> select_mem_base_addr_align(false);
  this -> select_min_data_type_align_size(false);
  this -> select_single_fp_config(false);
  this -> select_global_mem_cache_type(false);
  this -> select_global_mem_cacheline_size(false);
  this -> select_global_mem_cache_size(false);
  this -> select_global_mem_size(false);
  this -> select_max_constant_args(false);
  this -> select_local_mem_type(false);
  this -> select_local_mem_size(false);
  this -> select_error_correction_support(false);
  this -> select_host_unified_memory(false);
  this -> select_profiling_timer_resolution(false);
  this -> select_endian_little(false);
  this -> select_available(false);
  this -> select_compiler_available(false);
  this -> select_execution_capabilities(false);
  this -> select_queue_properties(false);
  this -> select_platform_id(false);
  this -> select_name(false);
  this -> select_vendor(false);
  this -> select_driver_version(false);
  this -> select_profile(false);
  this -> select_version(false);
  this -> select_opencl_c_version(false);
  this -> select_extensions(false);
  return *this;
}

void Device_Query::
_init_device_query()
{
  this -> select_all();
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
