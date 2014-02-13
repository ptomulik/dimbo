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

// dimbo/cl/device_query.hpp

/** // doc: dimbo/cl/device_query.hpp {{{
 * \file dimbo/cl/device_query.hpp
 *
 * This file contains definition of Dimbo::Cl::Device_Query class, which
 * configures queries to OpenCL devices.
 */ // }}}
#ifndef DIMBO_CL_DEVICE_INFO_QUERY_HPP_INCLUDED
#define DIMBO_CL_DEVICE_INFO_QUERY_HPP_INCLUDED

#ifndef SWIG // FIXME: provide more verbose constant name
# include <boost/serialization/version.hpp>
# include <boost/serialization/access.hpp>
# include <boost/serialization/nvp.hpp>
#endif

namespace Dimbo {
namespace Cl {

/** // doc: class Device_Query {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief Set of boolean flags that define parameters to be retrieved from
 *        OpenCL device.
 *
 * This class encapsulates several boolean flags which tell what information
 * should be retrieved from an OpenCL device. Objects of type Device_Query are
 * used together with Device_Info to query several parmeters describing local
 * OpenCL device(s) at once.
 */ // }}}
class Device_Query
{
public:
#ifndef SWIG // FIXME: provide more verbose constant name
  BOOST_STATIC_CONSTANT(unsigned int, class_version = 1);
#endif
public:
  /** // doc: Device_Query() {{{
   * \todo Write documentation
   */ // }}}
  Device_Query();
  /** // doc: ~Device_Query() {{{
   * \todo Write documentation for class Device_Query
   */ // }}}
  virtual ~Device_Query();
  /** // doc: select_all() {{{
   * \todo Write documentation
   */ // }}}
  Device_Query& select_all() ;
  /** // doc: select_all() {{{
   * \todo Write documentation
   */ // }}}
  Device_Query& select_none() ;
  // getters ... {{{
  /** // doc: id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool id_selected() const
  {
    return this->_select_id;
  }
  /** // doc: type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool type_selected() const
  {
    return this->_select_type;
  }
  /** // doc: vendor_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool vendor_id_selected() const
  {
    return this->_select_vendor_id;
  }
  /** // doc: max_compute_units_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_compute_units_selected() const
  {
    return this->_select_max_compute_units;
  }
  /** // doc: max_work_item_dimensions_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_work_item_dimensions_selected() const
  {
    return this->_select_max_work_item_dimensions;
  }
  /** // doc: max_work_item_sizes_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_work_item_sizes_selected() const
  {
    return this->_select_max_work_item_sizes;
  }
  /** // doc: max_work_group_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_work_group_size_selected() const
  {
    return this->_select_max_work_group_size;
  }
  /** // doc: preferred_vector_width_char_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_char_selected() const
  {
    return this->_select_preferred_vector_width_char;
  }
  /** // doc: preferred_vector_width_short_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_short_selected() const
  {
    return this->_select_preferred_vector_width_short;
  }
  /** // doc: preferred_vector_width_int_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_int_selected() const
  {
    return this->_select_preferred_vector_width_int;
  }
  /** // doc: preferred_vector_width_long_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_long_selected() const
  {
    return this->_select_preferred_vector_width_long;
  }
  /** // doc: preferred_vector_width_float_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_float_selected() const
  {
    return this->_select_preferred_vector_width_float;
  }
  /** // doc: preferred_vector_width_double_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_double_selected() const
  {
    return this->_select_preferred_vector_width_double;
  }
  /** // doc: preferred_vector_width_half_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool preferred_vector_width_half_selected() const
  {
    return this->_select_preferred_vector_width_half;
  }
  /** // doc: native_vector_width_char_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_char_selected() const
  {
    return this->_select_native_vector_width_char;
  }
  /** // doc: native_vector_width_short_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_short_selected() const
  {
    return this->_select_native_vector_width_short;
  }
  /** // doc: native_vector_width_int_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_int_selected() const
  {
    return this->_select_native_vector_width_int;
  }
  /** // doc: native_vector_width_long_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_long_selected() const
  {
    return this->_select_native_vector_width_long;
  }
  /** // doc: native_vector_width_float_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_float_selected() const
  {
    return this->_select_native_vector_width_float;
  }
  /** // doc: native_vector_width_double_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_double_selected() const
  {
    return this->_select_native_vector_width_double;
  }
  /** // doc: native_vector_width_half_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool native_vector_width_half_selected() const
  {
    return this->_select_native_vector_width_half;
  }
  /** // doc: max_clock_frequency_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_clock_frequency_selected() const
  {
    return this->_select_max_clock_frequency;
  }
  /** // doc: address_bits_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool address_bits_selected() const
  {
    return this->_select_address_bits;
  }
  /** // doc: max_mem_alloc_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_mem_alloc_size_selected() const
  {
    return this->_select_max_mem_alloc_size;
  }
  /** // doc: image_support_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool image_support_selected() const
  {
    return this->_select_image_support;
  }
  /** // doc: max_read_image_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_read_image_args_selected() const
  {
    return this->_select_max_read_image_args;
  }
  /** // doc: max_write_image_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_write_image_args_selected() const
  {
    return this->_select_max_write_image_args;
  }
  /** // doc: image2d_max_width_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool image2d_max_width_selected() const
  {
    return this->_select_image2d_max_width;
  }
  /** // doc: image2d_max_height_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool image2d_max_height_selected() const
  {
    return this->_select_image2d_max_height;
  }
  /** // doc: image3d_max_width_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool image3d_max_width_selected() const
  {
    return this->_select_image3d_max_width;
  }
  /** // doc: image3d_max_height_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool image3d_max_height_selected() const
  {
    return this->_select_image3d_max_height;
  }
  /** // doc: image3d_max_depth_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool image3d_max_depth_selected() const
  {
    return this->_select_image3d_max_depth;
  }
  /** // doc: max_samplers_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_samplers_selected() const
  {
    return this->_select_max_samplers;
  }
  /** // doc: max_parameter_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_parameter_size_selected() const
  {
    return this->_select_max_parameter_size;
  }
  /** // doc: mem_base_addr_align_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool mem_base_addr_align_selected() const
  {
    return this->_select_mem_base_addr_align;
  }
  /** // doc: min_data_type_align_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool min_data_type_align_size_selected() const
  {
    return this->_select_min_data_type_align_size;
  }
  /** // doc: single_fp_config_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool single_fp_config_selected() const
  {
    return this->_select_single_fp_config;
  }
  /** // doc: global_mem_cache_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool global_mem_cache_type_selected() const
  {
    return this->_select_global_mem_cache_type;
  }
  /** // doc: global_mem_cacheline_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool global_mem_cacheline_size_selected() const
  {
    return this->_select_global_mem_cacheline_size;
  }
  /** // doc: global_mem_cache_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool global_mem_cache_size_selected() const
  {
    return this->_select_global_mem_cache_size;
  }
  /** // doc: global_mem_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool global_mem_size_selected() const
  {
    return this->_select_global_mem_size;
  }
  /** // doc: max_constant_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool max_constant_args_selected() const
  {
    return this->_select_max_constant_args;
  }
  /** // doc: local_mem_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool local_mem_type_selected() const
  {
    return this->_select_local_mem_type;
  }
  /** // doc: local_mem_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool local_mem_size_selected() const
  {
    return this->_select_local_mem_size;
  }
  /** // doc: error_correction_support_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool error_correction_support_selected() const
  {
    return this->_select_error_correction_support;
  }
  /** // doc: host_unified_memory_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool host_unified_memory_selected() const
  {
    return this->_select_host_unified_memory;
  }
  /** // doc: profiling_timer_resolution_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool profiling_timer_resolution_selected() const
  {
    return this->_select_profiling_timer_resolution;
  }
  /** // doc: endian_little_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool endian_little_selected() const
  {
    return this->_select_endian_little;
  }
  /** // doc: available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool available_selected() const
  {
    return this->_select_available;
  }
  /** // doc: compiler_available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool compiler_available_selected() const
  {
    return this->_select_compiler_available;
  }
  /** // doc: execution_capabilities_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool execution_capabilities_selected() const
  {
    return this->_select_execution_capabilities;
  }
  /** // doc: queue_properties_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool queue_properties_selected() const
  {
    return this->_select_queue_properties;
  }
  /** // doc: platform_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool platform_id_selected() const
  {
    return this->_select_platform_id;
  }
  /** // doc: name_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool name_selected() const
  {
    return this->_select_name;
  }
  /** // doc: vendor_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool vendor_selected() const
  {
    return this->_select_vendor;
  }
  /** // doc: driver_version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool driver_version_selected() const
  {
    return this->_select_driver_version;
  }
  /** // doc: profile_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool profile_selected() const
  {
    return this->_select_profile;
  }
  /** // doc: version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool version_selected() const
  {
    return this->_select_version;
  }
  /** // doc: opencl_c_version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool opencl_c_version_selected() const
  {
    return this->_select_opencl_c_version;
  }
  /** // doc: extensions_selected() {{{
   * \todo Write documentation
   */ //  }}}
  bool extensions_selected() const
  {
    return this->_select_extensions;
  }
  // }}}
  // selectors {{{
  /** // doc: select_id() {{{
   * \todo Write documentation
   */ //  }}}
  void select_id(bool flag = true)
  {
    this->_select_id = flag;
  }
  /** // doc: select_type() {{{
   * \todo Write documentation
   */ //  }}}
  void select_type(bool flag = true)
  {
    this->_select_type = flag;
  }
  /** // doc: select_vendor_id() {{{
   * \todo Write documentation
   */ //  }}}
  void select_vendor_id(bool flag = true)
  {
    this->_select_vendor_id = flag;
  }
  /** // doc: select_max_compute_units() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_compute_units(bool flag = true)
  {
    this->_select_max_compute_units = flag;
  }
  /** // doc: select_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_work_item_dimensions(bool flag = true)
  {
    this->_select_max_work_item_dimensions = flag;
  }
  /** // doc: select_max_work_item_sizes() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_work_item_sizes(bool flag = true)
  {
    this->_select_max_work_item_sizes = flag;
  }
  /** // doc: select_max_work_group_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_work_group_size(bool flag = true)
  {
    this->_select_max_work_group_size = flag;
  }
  /** // doc: select_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_char(bool flag = true)
  {
    this->_select_preferred_vector_width_char = flag;
  }
  /** // doc: select_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_short(bool flag = true)
  {
    this->_select_preferred_vector_width_short = flag;
  }
  /** // doc: select_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_int(bool flag = true)
  {
    this->_select_preferred_vector_width_int = flag;
  }
  /** // doc: select_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_long(bool flag = true)
  {
    this->_select_preferred_vector_width_long = flag;
  }
  /** // doc: select_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_float(bool flag = true)
  {
    this->_select_preferred_vector_width_float = flag;
  }
  /** // doc: select_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_double(bool flag = true)
  {
    this->_select_preferred_vector_width_double = flag;
  }
  /** // doc: select_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ //  }}}
  void select_preferred_vector_width_half(bool flag = true)
  {
    this->_select_preferred_vector_width_half = flag;
  }
  /** // doc: select_native_vector_width_char() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_char(bool flag = true)
  {
    this->_select_native_vector_width_char = flag;
  }
  /** // doc: select_native_vector_width_short() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_short(bool flag = true)
  {
    this->_select_native_vector_width_short = flag;
  }
  /** // doc: select_native_vector_width_int() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_int(bool flag = true)
  {
    this->_select_native_vector_width_int = flag;
  }
  /** // doc: select_native_vector_width_long() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_long(bool flag = true)
  {
    this->_select_native_vector_width_long = flag;
  }
  /** // doc: select_native_vector_width_float() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_float(bool flag = true)
  {
    this->_select_native_vector_width_float = flag;
  }
  /** // doc: select_native_vector_width_double() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_double(bool flag = true)
  {
    this->_select_native_vector_width_double = flag;
  }
  /** // doc: select_native_vector_width_half() {{{
   * \todo Write documentation
   */ //  }}}
  void select_native_vector_width_half(bool flag = true)
  {
    this->_select_native_vector_width_half = flag;
  }
  /** // doc: select_max_clock_frequency() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_clock_frequency(bool flag = true)
  {
    this->_select_max_clock_frequency = flag;
  }
  /** // doc: select_address_bits() {{{
   * \todo Write documentation
   */ //  }}}
  void select_address_bits(bool flag = true)
  {
    this->_select_address_bits = flag;
  }
  /** // doc: select_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_mem_alloc_size(bool flag = true)
  {
    this->_select_max_mem_alloc_size = flag;
  }
  /** // doc: select_image_support() {{{
   * \todo Write documentation
   */ //  }}}
  void select_image_support(bool flag = true)
  {
    this->_select_image_support = flag;
  }
  /** // doc: select_max_read_image_args() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_read_image_args(bool flag = true)
  {
    this->_select_max_read_image_args = flag;
  }
  /** // doc: select_max_write_image_args() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_write_image_args(bool flag = true)
  {
    this->_select_max_write_image_args = flag;
  }
  /** // doc: select_image2d_max_width() {{{
   * \todo Write documentation
   */ //  }}}
  void select_image2d_max_width(bool flag = true)
  {
    this->_select_image2d_max_width = flag;
  }
  /** // doc: select_image2d_max_height() {{{
   * \todo Write documentation
   */ //  }}}
  void select_image2d_max_height(bool flag = true)
  {
    this->_select_image2d_max_height = flag;
  }
  /** // doc: select_image3d_max_width() {{{
   * \todo Write documentation
   */ //  }}}
  void select_image3d_max_width(bool flag = true)
  {
    this->_select_image3d_max_width = flag;
  }
  /** // doc: select_image3d_max_height() {{{
   * \todo Write documentation
   */ //  }}}
  void select_image3d_max_height(bool flag = true)
  {
    this->_select_image3d_max_height = flag;
  }
  /** // doc: select_image3d_max_depth() {{{
   * \todo Write documentation
   */ //  }}}
  void select_image3d_max_depth(bool flag = true)
  {
    this->_select_image3d_max_depth = flag;
  }
  /** // doc: select_max_samplers() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_samplers(bool flag = true)
  {
    this->_select_max_samplers = flag;
  }
  /** // doc: select_max_parameter_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_parameter_size(bool flag = true)
  {
    this->_select_max_parameter_size = flag;
  }
  /** // doc: select_mem_base_addr_align() {{{
   * \todo Write documentation
   */ //  }}}
  void select_mem_base_addr_align(bool flag = true)
  {
    this->_select_mem_base_addr_align = flag;
  }
  /** // doc: select_min_data_type_align_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_min_data_type_align_size(bool flag = true)
  {
    this->_select_min_data_type_align_size = flag;
  }
  /** // doc: select_single_fp_config() {{{
   * \todo Write documentation
   */ //  }}}
  void select_single_fp_config(bool flag = true)
  {
    this->_select_single_fp_config = flag;
  }
  /** // doc: select_global_mem_cache_type() {{{
   * \todo Write documentation
   */ //  }}}
  void select_global_mem_cache_type(bool flag = true)
  {
    this->_select_global_mem_cache_type = flag;
  }
  /** // doc: select_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_global_mem_cacheline_size(bool flag = true)
  {
    this->_select_global_mem_cacheline_size = flag;
  }
  /** // doc: select_global_mem_cache_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_global_mem_cache_size(bool flag = true)
  {
    this->_select_global_mem_cache_size = flag;
  }
  /** // doc: select_global_mem_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_global_mem_size(bool flag = true)
  {
    this->_select_global_mem_size = flag;
  }
  /** // doc: select_max_constant_args() {{{
   * \todo Write documentation
   */ //  }}}
  void select_max_constant_args(bool flag = true)
  {
    this->_select_max_constant_args = flag;
  }
  /** // doc: select_local_mem_type() {{{
   * \todo Write documentation
   */ //  }}}
  void select_local_mem_type(bool flag = true)
  {
    this->_select_local_mem_type = flag;
  }
  /** // doc: select_local_mem_size() {{{
   * \todo Write documentation
   */ //  }}}
  void select_local_mem_size(bool flag = true)
  {
    this->_select_local_mem_size = flag;
  }
  /** // doc: select_error_correction_support() {{{
   * \todo Write documentation
   */ //  }}}
  void select_error_correction_support(bool flag = true)
  {
    this->_select_error_correction_support = flag;
  }
  /** // doc: select_host_unified_memory() {{{
   * \todo Write documentation
   */ //  }}}
  void select_host_unified_memory(bool flag = true)
  {
    this->_select_host_unified_memory = flag;
  }
  /** // doc: select_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ //  }}}
  void select_profiling_timer_resolution(bool flag = true)
  {
    this->_select_profiling_timer_resolution = flag;
  }
  /** // doc: select_endian_little() {{{
   * \todo Write documentation
   */ //  }}}
  void select_endian_little(bool flag = true)
  {
    this->_select_endian_little = flag;
  }
  /** // doc: select_available() {{{
   * \todo Write documentation
   */ //  }}}
  void select_available(bool flag = true)
  {
    this->_select_available = flag;
  }
  /** // doc: select_compiler_available() {{{
   * \todo Write documentation
   */ //  }}}
  void select_compiler_available(bool flag = true)
  {
    this->_select_compiler_available = flag;
  }
  /** // doc: select_execution_capabilities() {{{
   * \todo Write documentation
   */ //  }}}
  void select_execution_capabilities(bool flag = true)
  {
    this->_select_execution_capabilities = flag;
  }
  /** // doc: select_queue_properties() {{{
   * \todo Write documentation
   */ //  }}}
  void select_queue_properties(bool flag = true)
  {
    this->_select_queue_properties = flag;
  }
  /** // doc: select_platform_id() {{{
   * \todo Write documentation
   */ //  }}}
  void select_platform_id(bool flag = true)
  {
    this->_select_platform_id = flag;
  }
  /** // doc: select_name() {{{
   * \todo Write documentation
   */ //  }}}
  void select_name(bool flag = true)
  {
    this->_select_name = flag;
  }
  /** // doc: select_vendor() {{{
   * \todo Write documentation
   */ //  }}}
  void select_vendor(bool flag = true)
  {
    this->_select_vendor = flag;
  }
  /** // doc: select_driver_version() {{{
   * \todo Write documentation
   */ //  }}}
  void select_driver_version(bool flag = true)
  {
    this->_select_driver_version = flag;
  }
  /** // doc: select_profile() {{{
   * \todo Write documentation
   */ //  }}}
  void select_profile(bool flag = true)
  {
    this->_select_profile = flag;
  }
  /** // doc: select_version() {{{
   * \todo Write documentation
   */ //  }}}
  void select_version(bool flag = true)
  {
    this->_select_version = flag;
  }
  /** // doc: select_opencl_c_version() {{{
   * \todo Write documentation
   */ //  }}}
  void select_opencl_c_version(bool flag = true)
  {
    this->_select_opencl_c_version = flag;
  }
  /** // doc: select_extensions() {{{
   * \todo Write documentation
   */ //  }}}
  void select_extensions(bool flag = true)
  {
    this->_select_extensions = flag;
  }
  // }}}
private:
#ifndef SWIG // FIXME: provide more verbose constant name
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int /* version */)
  {
    // attributes {{{
    using boost::serialization::make_nvp;
    ar & make_nvp("select_id", _select_id);
    ar & make_nvp("select_type", _select_type);
    ar & make_nvp("select_vendor_id", _select_vendor_id);
    ar & make_nvp("select_max_compute_units", _select_max_compute_units);
    ar & make_nvp("select_max_work_item_dimensions", _select_max_work_item_dimensions);
    ar & make_nvp("select_max_work_item_sizes", _select_max_work_item_sizes);
    ar & make_nvp("select_max_work_group_size", _select_max_work_group_size);
    ar & make_nvp("select_preferred_vector_width_char", _select_preferred_vector_width_char);
    ar & make_nvp("select_preferred_vector_width_short", _select_preferred_vector_width_short);
    ar & make_nvp("select_preferred_vector_width_int", _select_preferred_vector_width_int);
    ar & make_nvp("select_preferred_vector_width_long", _select_preferred_vector_width_long);
    ar & make_nvp("select_preferred_vector_width_float", _select_preferred_vector_width_float);
    ar & make_nvp("select_preferred_vector_width_double", _select_preferred_vector_width_double);
    ar & make_nvp("select_preferred_vector_width_half", _select_preferred_vector_width_half);
    ar & make_nvp("select_native_vector_width_char", _select_native_vector_width_char);
    ar & make_nvp("select_native_vector_width_short", _select_native_vector_width_short);
    ar & make_nvp("select_native_vector_width_int", _select_native_vector_width_int);
    ar & make_nvp("select_native_vector_width_long", _select_native_vector_width_long);
    ar & make_nvp("select_native_vector_width_float", _select_native_vector_width_float);
    ar & make_nvp("select_native_vector_width_double", _select_native_vector_width_double);
    ar & make_nvp("select_native_vector_width_half", _select_native_vector_width_half);
    ar & make_nvp("select_max_clock_frequency", _select_max_clock_frequency);
    ar & make_nvp("select_address_bits", _select_address_bits);
    ar & make_nvp("select_max_mem_alloc_size", _select_max_mem_alloc_size);
    ar & make_nvp("select_image_support", _select_image_support);
    ar & make_nvp("select_max_read_image_args", _select_max_read_image_args);
    ar & make_nvp("select_max_write_image_args", _select_max_write_image_args);
    ar & make_nvp("select_image2d_max_width", _select_image2d_max_width);
    ar & make_nvp("select_image2d_max_height", _select_image2d_max_height);
    ar & make_nvp("select_image3d_max_width", _select_image3d_max_width);
    ar & make_nvp("select_image3d_max_height", _select_image3d_max_height);
    ar & make_nvp("select_image3d_max_depth", _select_image3d_max_depth);
    ar & make_nvp("select_max_samplers", _select_max_samplers);
    ar & make_nvp("select_max_parameter_size", _select_max_parameter_size);
    ar & make_nvp("select_mem_base_addr_align", _select_mem_base_addr_align);
    ar & make_nvp("select_min_data_type_align_size", _select_min_data_type_align_size);
    ar & make_nvp("select_single_fp_config", _select_single_fp_config);
    ar & make_nvp("select_global_mem_cache_type", _select_global_mem_cache_type);
    ar & make_nvp("select_global_mem_cacheline_size", _select_global_mem_cacheline_size);
    ar & make_nvp("select_global_mem_cache_size", _select_global_mem_cache_size);
    ar & make_nvp("select_global_mem_size", _select_global_mem_size);
    ar & make_nvp("select_max_constant_args", _select_max_constant_args);
    ar & make_nvp("select_local_mem_type", _select_local_mem_type);
    ar & make_nvp("select_local_mem_size", _select_local_mem_size);
    ar & make_nvp("select_error_correction_support", _select_error_correction_support);
    ar & make_nvp("select_host_unified_memory", _select_host_unified_memory);
    ar & make_nvp("select_profiling_timer_resolution", _select_profiling_timer_resolution);
    ar & make_nvp("select_endian_little", _select_endian_little);
    ar & make_nvp("select_available", _select_available);
    ar & make_nvp("select_compiler_available", _select_compiler_available);
    ar & make_nvp("select_execution_capabilities", _select_execution_capabilities);
    ar & make_nvp("select_queue_properties", _select_queue_properties);
    ar & make_nvp("select_platform_id", _select_platform_id);
    ar & make_nvp("select_name", _select_name);
    ar & make_nvp("select_vendor", _select_vendor);
    ar & make_nvp("select_driver_version", _select_driver_version);
    ar & make_nvp("select_profile", _select_profile);
    ar & make_nvp("select_version", _select_version);
    ar & make_nvp("select_opencl_c_version", _select_opencl_c_version);
    ar & make_nvp("select_extensions", _select_extensions);
    // }}}
  }
#endif
private:
  void _init_device_query();
  // attributes {{{
  bool _select_id;
  bool _select_type;
  bool _select_vendor_id;
  bool _select_max_compute_units;
  bool _select_max_work_item_dimensions;
  bool _select_max_work_item_sizes;
  bool _select_max_work_group_size;
  bool _select_preferred_vector_width_char;
  bool _select_preferred_vector_width_short;
  bool _select_preferred_vector_width_int;
  bool _select_preferred_vector_width_long;
  bool _select_preferred_vector_width_float;
  bool _select_preferred_vector_width_double;
  bool _select_preferred_vector_width_half;
  bool _select_native_vector_width_char;
  bool _select_native_vector_width_short;
  bool _select_native_vector_width_int;
  bool _select_native_vector_width_long;
  bool _select_native_vector_width_float;
  bool _select_native_vector_width_double;
  bool _select_native_vector_width_half;
  bool _select_max_clock_frequency;
  bool _select_address_bits;
  bool _select_max_mem_alloc_size;
  bool _select_image_support;
  bool _select_max_read_image_args;
  bool _select_max_write_image_args;
  bool _select_image2d_max_width;
  bool _select_image2d_max_height;
  bool _select_image3d_max_width;
  bool _select_image3d_max_height;
  bool _select_image3d_max_depth;
  bool _select_max_samplers;
  bool _select_max_parameter_size;
  bool _select_mem_base_addr_align;
  bool _select_min_data_type_align_size;
  bool _select_single_fp_config;
  bool _select_global_mem_cache_type;
  bool _select_global_mem_cacheline_size;
  bool _select_global_mem_cache_size;
  bool _select_global_mem_size;
  bool _select_max_constant_args;
  bool _select_local_mem_type;
  bool _select_local_mem_size;
  bool _select_error_correction_support;
  bool _select_host_unified_memory;
  bool _select_profiling_timer_resolution;
  bool _select_endian_little;
  bool _select_available;
  bool _select_compiler_available;
  bool _select_execution_capabilities;
  bool _select_queue_properties;
  bool _select_platform_id;
  bool _select_name;
  bool _select_vendor;
  bool _select_driver_version;
  bool _select_profile;
  bool _select_version;
  bool _select_opencl_c_version;
  bool _select_extensions;
  // }}}
};

} /* namespace Cl */
} /* namespace Dimbo */

#ifndef SWIG // FIXME: provide more verbose constant name
BOOST_CLASS_VERSION( Dimbo::Cl::Device_Query
                   , Dimbo::Cl::Device_Query::class_version )
#endif

#endif /* DIMBO_CL_DEVICE_INFO_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
