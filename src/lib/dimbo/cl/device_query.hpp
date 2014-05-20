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
  /** // doc: restrict_to(major,minor) {{{
   * \todo Write documentation
   */ // }}}
  Device_Query& restrict_to(int major, int minor);
  // getters ... {{{
  /** // doc: id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool id_selected() const
  {
    return this->_select_id;
  }
  /** // doc: type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool type_selected() const
  {
    return this->_select_type;
  }
  /** // doc: vendor_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool vendor_id_selected() const
  {
    return this->_select_vendor_id;
  }
  /** // doc: max_compute_units_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_compute_units_selected() const
  {
    return this->_select_max_compute_units;
  }
  /** // doc: max_work_item_dimensions_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_work_item_dimensions_selected() const
  {
    return this->_select_max_work_item_dimensions;
  }
  /** // doc: max_work_group_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_work_group_size_selected() const
  {
    return this->_select_max_work_group_size;
  }
  /** // doc: max_work_item_sizes_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_work_item_sizes_selected() const
  {
    return this->_select_max_work_item_sizes;
  }
  /** // doc: preferred_vector_width_char_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_char_selected() const
  {
    return this->_select_preferred_vector_width_char;
  }
  /** // doc: preferred_vector_width_short_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_short_selected() const
  {
    return this->_select_preferred_vector_width_short;
  }
  /** // doc: preferred_vector_width_int_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_int_selected() const
  {
    return this->_select_preferred_vector_width_int;
  }
  /** // doc: preferred_vector_width_long_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_long_selected() const
  {
    return this->_select_preferred_vector_width_long;
  }
  /** // doc: preferred_vector_width_float_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_float_selected() const
  {
    return this->_select_preferred_vector_width_float;
  }
  /** // doc: preferred_vector_width_double_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_double_selected() const
  {
    return this->_select_preferred_vector_width_double;
  }
  /** // doc: max_clock_frequency_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_clock_frequency_selected() const
  {
    return this->_select_max_clock_frequency;
  }
  /** // doc: address_bits_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool address_bits_selected() const
  {
    return this->_select_address_bits;
  }
  /** // doc: max_read_image_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_read_image_args_selected() const
  {
    return this->_select_max_read_image_args;
  }
  /** // doc: max_write_image_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_write_image_args_selected() const
  {
    return this->_select_max_write_image_args;
  }
  /** // doc: max_mem_alloc_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_mem_alloc_size_selected() const
  {
    return this->_select_max_mem_alloc_size;
  }
  /** // doc: image2d_max_width_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image2d_max_width_selected() const
  {
    return this->_select_image2d_max_width;
  }
  /** // doc: image2d_max_height_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image2d_max_height_selected() const
  {
    return this->_select_image2d_max_height;
  }
  /** // doc: image3d_max_width_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image3d_max_width_selected() const
  {
    return this->_select_image3d_max_width;
  }
  /** // doc: image3d_max_height_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image3d_max_height_selected() const
  {
    return this->_select_image3d_max_height;
  }
  /** // doc: image3d_max_depth_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image3d_max_depth_selected() const
  {
    return this->_select_image3d_max_depth;
  }
  /** // doc: image_support_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_support_selected() const
  {
    return this->_select_image_support;
  }
  /** // doc: max_parameter_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_parameter_size_selected() const
  {
    return this->_select_max_parameter_size;
  }
  /** // doc: max_samplers_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_samplers_selected() const
  {
    return this->_select_max_samplers;
  }
  /** // doc: mem_base_addr_align_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool mem_base_addr_align_selected() const
  {
    return this->_select_mem_base_addr_align;
  }
  /** // doc: min_data_type_align_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool min_data_type_align_size_selected() const
  {
    return this->_select_min_data_type_align_size;
  }
  /** // doc: single_fp_config_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool single_fp_config_selected() const
  {
    return this->_select_single_fp_config;
  }
  /** // doc: global_mem_cache_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_cache_type_selected() const
  {
    return this->_select_global_mem_cache_type;
  }
  /** // doc: global_mem_cacheline_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_cacheline_size_selected() const
  {
    return this->_select_global_mem_cacheline_size;
  }
  /** // doc: global_mem_cache_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_cache_size_selected() const
  {
    return this->_select_global_mem_cache_size;
  }
  /** // doc: global_mem_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_size_selected() const
  {
    return this->_select_global_mem_size;
  }
  /** // doc: max_constant_buffer_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_constant_buffer_size_selected() const
  {
    return this->_select_max_constant_buffer_size;
  }
  /** // doc: max_constant_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_constant_args_selected() const
  {
    return this->_select_max_constant_args;
  }
  /** // doc: local_mem_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool local_mem_type_selected() const
  {
    return this->_select_local_mem_type;
  }
  /** // doc: local_mem_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool local_mem_size_selected() const
  {
    return this->_select_local_mem_size;
  }
  /** // doc: error_correction_support_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool error_correction_support_selected() const
  {
    return this->_select_error_correction_support;
  }
  /** // doc: profiling_timer_resolution_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool profiling_timer_resolution_selected() const
  {
    return this->_select_profiling_timer_resolution;
  }
  /** // doc: endian_little_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool endian_little_selected() const
  {
    return this->_select_endian_little;
  }
  /** // doc: available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool available_selected() const
  {
    return this->_select_available;
  }
  /** // doc: compiler_available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool compiler_available_selected() const
  {
    return this->_select_compiler_available;
  }
  /** // doc: execution_capabilities_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool execution_capabilities_selected() const
  {
    return this->_select_execution_capabilities;
  }
  /** // doc: queue_properties_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool queue_properties_selected() const
  {
    return this->_select_queue_properties;
  }
  /** // doc: name_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool name_selected() const
  {
    return this->_select_name;
  }
  /** // doc: vendor_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool vendor_selected() const
  {
    return this->_select_vendor;
  }
  /** // doc: driver_version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool driver_version_selected() const
  {
    return this->_select_driver_version;
  }
  /** // doc: profile_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool profile_selected() const
  {
    return this->_select_profile;
  }
  /** // doc: version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool version_selected() const
  {
    return this->_select_version;
  }
  /** // doc: extensions_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool extensions_selected() const
  {
    return this->_select_extensions;
  }
  /** // doc: platform_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool platform_id_selected() const
  {
    return this->_select_platform_id;
  }
  /** // doc: double_fp_config_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool double_fp_config_selected() const
  {
    return this->_select_double_fp_config;
  }
  /** // doc: preferred_vector_width_half_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_half_selected() const
  {
    return this->_select_preferred_vector_width_half;
  }
  /** // doc: host_unified_memory_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool host_unified_memory_selected() const
  {
    return this->_select_host_unified_memory;
  }
  /** // doc: native_vector_width_char_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_char_selected() const
  {
    return this->_select_native_vector_width_char;
  }
  /** // doc: native_vector_width_short_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_short_selected() const
  {
    return this->_select_native_vector_width_short;
  }
  /** // doc: native_vector_width_int_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_int_selected() const
  {
    return this->_select_native_vector_width_int;
  }
  /** // doc: native_vector_width_long_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_long_selected() const
  {
    return this->_select_native_vector_width_long;
  }
  /** // doc: native_vector_width_float_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_float_selected() const
  {
    return this->_select_native_vector_width_float;
  }
  /** // doc: native_vector_width_double_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_double_selected() const
  {
    return this->_select_native_vector_width_double;
  }
  /** // doc: native_vector_width_half_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_half_selected() const
  {
    return this->_select_native_vector_width_half;
  }
  /** // doc: opencl_c_version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool opencl_c_version_selected() const
  {
    return this->_select_opencl_c_version;
  }
  /** // doc: linker_available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool linker_available_selected() const
  {
    return this->_select_linker_available;
  }
  /** // doc: built_in_kernels_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool built_in_kernels_selected() const
  {
    return this->_select_built_in_kernels;
  }
  /** // doc: image_max_buffer_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_max_buffer_size_selected() const
  {
    return this->_select_image_max_buffer_size;
  }
  /** // doc: image_max_array_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_max_array_size_selected() const
  {
    return this->_select_image_max_array_size;
  }
  /** // doc: parent_device_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool parent_device_id_selected() const
  {
    return this->_select_parent_device_id;
  }
  /** // doc: partition_max_sub_devices_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_max_sub_devices_selected() const
  {
    return this->_select_partition_max_sub_devices;
  }
  /** // doc: partition_properties_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_properties_selected() const
  {
    return this->_select_partition_properties;
  }
  /** // doc: partition_affinity_domain_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_affinity_domain_selected() const
  {
    return this->_select_partition_affinity_domain;
  }
  /** // doc: partition_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_type_selected() const
  {
    return this->_select_partition_type;
  }
  /** // doc: reference_count_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool reference_count_selected() const
  {
    return this->_select_reference_count;
  }
  /** // doc: preferred_interop_user_sync_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_interop_user_sync_selected() const
  {
    return this->_select_preferred_interop_user_sync;
  }
  /** // doc: printf_buffer_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool printf_buffer_size_selected() const
  {
    return this->_select_printf_buffer_size;
  }
  /** // doc: image_pitch_alignment_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_pitch_alignment_selected() const
  {
    return this->_select_image_pitch_alignment;
  }
  /** // doc: image_base_address_alignment_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_base_address_alignment_selected() const
  {
    return this->_select_image_base_address_alignment;
  }
  // }}}
  // selectors {{{
  /** // doc: select_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_id(bool flag = true)
  {
    this->_select_id = flag;
    return *this;
  }
  /** // doc: select_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_type(bool flag = true)
  {
    this->_select_type = flag;
    return *this;
  }
  /** // doc: select_vendor_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_vendor_id(bool flag = true)
  {
    this->_select_vendor_id = flag;
    return *this;
  }
  /** // doc: select_max_compute_units() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_compute_units(bool flag = true)
  {
    this->_select_max_compute_units = flag;
    return *this;
  }
  /** // doc: select_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_work_item_dimensions(bool flag = true)
  {
    this->_select_max_work_item_dimensions = flag;
    return *this;
  }
  /** // doc: select_max_work_group_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_work_group_size(bool flag = true)
  {
    this->_select_max_work_group_size = flag;
    return *this;
  }
  /** // doc: select_max_work_item_sizes() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_work_item_sizes(bool flag = true)
  {
    this->_select_max_work_item_sizes = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_char(bool flag = true)
  {
    this->_select_preferred_vector_width_char = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_short(bool flag = true)
  {
    this->_select_preferred_vector_width_short = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_int(bool flag = true)
  {
    this->_select_preferred_vector_width_int = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_long(bool flag = true)
  {
    this->_select_preferred_vector_width_long = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_float(bool flag = true)
  {
    this->_select_preferred_vector_width_float = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_double(bool flag = true)
  {
    this->_select_preferred_vector_width_double = flag;
    return *this;
  }
  /** // doc: select_max_clock_frequency() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_clock_frequency(bool flag = true)
  {
    this->_select_max_clock_frequency = flag;
    return *this;
  }
  /** // doc: select_address_bits() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_address_bits(bool flag = true)
  {
    this->_select_address_bits = flag;
    return *this;
  }
  /** // doc: select_max_read_image_args() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_read_image_args(bool flag = true)
  {
    this->_select_max_read_image_args = flag;
    return *this;
  }
  /** // doc: select_max_write_image_args() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_write_image_args(bool flag = true)
  {
    this->_select_max_write_image_args = flag;
    return *this;
  }
  /** // doc: select_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_mem_alloc_size(bool flag = true)
  {
    this->_select_max_mem_alloc_size = flag;
    return *this;
  }
  /** // doc: select_image2d_max_width() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image2d_max_width(bool flag = true)
  {
    this->_select_image2d_max_width = flag;
    return *this;
  }
  /** // doc: select_image2d_max_height() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image2d_max_height(bool flag = true)
  {
    this->_select_image2d_max_height = flag;
    return *this;
  }
  /** // doc: select_image3d_max_width() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image3d_max_width(bool flag = true)
  {
    this->_select_image3d_max_width = flag;
    return *this;
  }
  /** // doc: select_image3d_max_height() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image3d_max_height(bool flag = true)
  {
    this->_select_image3d_max_height = flag;
    return *this;
  }
  /** // doc: select_image3d_max_depth() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image3d_max_depth(bool flag = true)
  {
    this->_select_image3d_max_depth = flag;
    return *this;
  }
  /** // doc: select_image_support() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image_support(bool flag = true)
  {
    this->_select_image_support = flag;
    return *this;
  }
  /** // doc: select_max_parameter_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_parameter_size(bool flag = true)
  {
    this->_select_max_parameter_size = flag;
    return *this;
  }
  /** // doc: select_max_samplers() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_samplers(bool flag = true)
  {
    this->_select_max_samplers = flag;
    return *this;
  }
  /** // doc: select_mem_base_addr_align() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_mem_base_addr_align(bool flag = true)
  {
    this->_select_mem_base_addr_align = flag;
    return *this;
  }
  /** // doc: select_min_data_type_align_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_min_data_type_align_size(bool flag = true)
  {
    this->_select_min_data_type_align_size = flag;
    return *this;
  }
  /** // doc: select_single_fp_config() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_single_fp_config(bool flag = true)
  {
    this->_select_single_fp_config = flag;
    return *this;
  }
  /** // doc: select_global_mem_cache_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_global_mem_cache_type(bool flag = true)
  {
    this->_select_global_mem_cache_type = flag;
    return *this;
  }
  /** // doc: select_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_global_mem_cacheline_size(bool flag = true)
  {
    this->_select_global_mem_cacheline_size = flag;
    return *this;
  }
  /** // doc: select_global_mem_cache_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_global_mem_cache_size(bool flag = true)
  {
    this->_select_global_mem_cache_size = flag;
    return *this;
  }
  /** // doc: select_global_mem_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_global_mem_size(bool flag = true)
  {
    this->_select_global_mem_size = flag;
    return *this;
  }
  /** // doc: select_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_constant_buffer_size(bool flag = true)
  {
    this->_select_max_constant_buffer_size = flag;
    return *this;
  }
  /** // doc: select_max_constant_args() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_max_constant_args(bool flag = true)
  {
    this->_select_max_constant_args = flag;
    return *this;
  }
  /** // doc: select_local_mem_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_local_mem_type(bool flag = true)
  {
    this->_select_local_mem_type = flag;
    return *this;
  }
  /** // doc: select_local_mem_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_local_mem_size(bool flag = true)
  {
    this->_select_local_mem_size = flag;
    return *this;
  }
  /** // doc: select_error_correction_support() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_error_correction_support(bool flag = true)
  {
    this->_select_error_correction_support = flag;
    return *this;
  }
  /** // doc: select_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_profiling_timer_resolution(bool flag = true)
  {
    this->_select_profiling_timer_resolution = flag;
    return *this;
  }
  /** // doc: select_endian_little() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_endian_little(bool flag = true)
  {
    this->_select_endian_little = flag;
    return *this;
  }
  /** // doc: select_available() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_available(bool flag = true)
  {
    this->_select_available = flag;
    return *this;
  }
  /** // doc: select_compiler_available() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_compiler_available(bool flag = true)
  {
    this->_select_compiler_available = flag;
    return *this;
  }
  /** // doc: select_execution_capabilities() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_execution_capabilities(bool flag = true)
  {
    this->_select_execution_capabilities = flag;
    return *this;
  }
  /** // doc: select_queue_properties() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_queue_properties(bool flag = true)
  {
    this->_select_queue_properties = flag;
    return *this;
  }
  /** // doc: select_name() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_name(bool flag = true)
  {
    this->_select_name = flag;
    return *this;
  }
  /** // doc: select_vendor() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_vendor(bool flag = true)
  {
    this->_select_vendor = flag;
    return *this;
  }
  /** // doc: select_driver_version() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_driver_version(bool flag = true)
  {
    this->_select_driver_version = flag;
    return *this;
  }
  /** // doc: select_profile() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_profile(bool flag = true)
  {
    this->_select_profile = flag;
    return *this;
  }
  /** // doc: select_version() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_version(bool flag = true)
  {
    this->_select_version = flag;
    return *this;
  }
  /** // doc: select_extensions() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_extensions(bool flag = true)
  {
    this->_select_extensions = flag;
    return *this;
  }
  /** // doc: select_platform_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_platform_id(bool flag = true)
  {
    this->_select_platform_id = flag;
    return *this;
  }
  /** // doc: select_double_fp_config() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_double_fp_config(bool flag = true)
  {
    this->_select_double_fp_config = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_vector_width_half(bool flag = true)
  {
    this->_select_preferred_vector_width_half = flag;
    return *this;
  }
  /** // doc: select_host_unified_memory() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_host_unified_memory(bool flag = true)
  {
    this->_select_host_unified_memory = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_char() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_char(bool flag = true)
  {
    this->_select_native_vector_width_char = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_short() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_short(bool flag = true)
  {
    this->_select_native_vector_width_short = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_int() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_int(bool flag = true)
  {
    this->_select_native_vector_width_int = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_long() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_long(bool flag = true)
  {
    this->_select_native_vector_width_long = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_float() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_float(bool flag = true)
  {
    this->_select_native_vector_width_float = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_double() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_double(bool flag = true)
  {
    this->_select_native_vector_width_double = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_half() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_native_vector_width_half(bool flag = true)
  {
    this->_select_native_vector_width_half = flag;
    return *this;
  }
  /** // doc: select_opencl_c_version() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_opencl_c_version(bool flag = true)
  {
    this->_select_opencl_c_version = flag;
    return *this;
  }
  /** // doc: select_linker_available() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_linker_available(bool flag = true)
  {
    this->_select_linker_available = flag;
    return *this;
  }
  /** // doc: select_built_in_kernels() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_built_in_kernels(bool flag = true)
  {
    this->_select_built_in_kernels = flag;
    return *this;
  }
  /** // doc: select_image_max_buffer_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image_max_buffer_size(bool flag = true)
  {
    this->_select_image_max_buffer_size = flag;
    return *this;
  }
  /** // doc: select_image_max_array_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image_max_array_size(bool flag = true)
  {
    this->_select_image_max_array_size = flag;
    return *this;
  }
  /** // doc: select_parent_device_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_parent_device_id(bool flag = true)
  {
    this->_select_parent_device_id = flag;
    return *this;
  }
  /** // doc: select_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_partition_max_sub_devices(bool flag = true)
  {
    this->_select_partition_max_sub_devices = flag;
    return *this;
  }
  /** // doc: select_partition_properties() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_partition_properties(bool flag = true)
  {
    this->_select_partition_properties = flag;
    return *this;
  }
  /** // doc: select_partition_affinity_domain() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_partition_affinity_domain(bool flag = true)
  {
    this->_select_partition_affinity_domain = flag;
    return *this;
  }
  /** // doc: select_partition_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_partition_type(bool flag = true)
  {
    this->_select_partition_type = flag;
    return *this;
  }
  /** // doc: select_reference_count() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_reference_count(bool flag = true)
  {
    this->_select_reference_count = flag;
    return *this;
  }
  /** // doc: select_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_preferred_interop_user_sync(bool flag = true)
  {
    this->_select_preferred_interop_user_sync = flag;
    return *this;
  }
  /** // doc: select_printf_buffer_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_printf_buffer_size(bool flag = true)
  {
    this->_select_printf_buffer_size = flag;
    return *this;
  }
  /** // doc: select_image_pitch_alignment() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image_pitch_alignment(bool flag = true)
  {
    this->_select_image_pitch_alignment = flag;
    return *this;
  }
  /** // doc: select_image_base_address_alignment() {{{
   * \todo Write documentation
   */ //  }}}
  inline Device_Query& select_image_base_address_alignment(bool flag = true)
  {
    this->_select_image_base_address_alignment = flag;
    return *this;
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
    ar & make_nvp("select_max_work_group_size", _select_max_work_group_size);
    ar & make_nvp("select_max_work_item_sizes", _select_max_work_item_sizes);
    ar & make_nvp("select_preferred_vector_width_char", _select_preferred_vector_width_char);
    ar & make_nvp("select_preferred_vector_width_short", _select_preferred_vector_width_short);
    ar & make_nvp("select_preferred_vector_width_int", _select_preferred_vector_width_int);
    ar & make_nvp("select_preferred_vector_width_long", _select_preferred_vector_width_long);
    ar & make_nvp("select_preferred_vector_width_float", _select_preferred_vector_width_float);
    ar & make_nvp("select_preferred_vector_width_double", _select_preferred_vector_width_double);
    ar & make_nvp("select_max_clock_frequency", _select_max_clock_frequency);
    ar & make_nvp("select_address_bits", _select_address_bits);
    ar & make_nvp("select_max_read_image_args", _select_max_read_image_args);
    ar & make_nvp("select_max_write_image_args", _select_max_write_image_args);
    ar & make_nvp("select_max_mem_alloc_size", _select_max_mem_alloc_size);
    ar & make_nvp("select_image2d_max_width", _select_image2d_max_width);
    ar & make_nvp("select_image2d_max_height", _select_image2d_max_height);
    ar & make_nvp("select_image3d_max_width", _select_image3d_max_width);
    ar & make_nvp("select_image3d_max_height", _select_image3d_max_height);
    ar & make_nvp("select_image3d_max_depth", _select_image3d_max_depth);
    ar & make_nvp("select_image_support", _select_image_support);
    ar & make_nvp("select_max_parameter_size", _select_max_parameter_size);
    ar & make_nvp("select_max_samplers", _select_max_samplers);
    ar & make_nvp("select_mem_base_addr_align", _select_mem_base_addr_align);
    ar & make_nvp("select_min_data_type_align_size", _select_min_data_type_align_size);
    ar & make_nvp("select_single_fp_config", _select_single_fp_config);
    ar & make_nvp("select_global_mem_cache_type", _select_global_mem_cache_type);
    ar & make_nvp("select_global_mem_cacheline_size", _select_global_mem_cacheline_size);
    ar & make_nvp("select_global_mem_cache_size", _select_global_mem_cache_size);
    ar & make_nvp("select_global_mem_size", _select_global_mem_size);
    ar & make_nvp("select_max_constant_buffer_size", _select_max_constant_buffer_size);
    ar & make_nvp("select_max_constant_args", _select_max_constant_args);
    ar & make_nvp("select_local_mem_type", _select_local_mem_type);
    ar & make_nvp("select_local_mem_size", _select_local_mem_size);
    ar & make_nvp("select_error_correction_support", _select_error_correction_support);
    ar & make_nvp("select_profiling_timer_resolution", _select_profiling_timer_resolution);
    ar & make_nvp("select_endian_little", _select_endian_little);
    ar & make_nvp("select_available", _select_available);
    ar & make_nvp("select_compiler_available", _select_compiler_available);
    ar & make_nvp("select_execution_capabilities", _select_execution_capabilities);
    ar & make_nvp("select_queue_properties", _select_queue_properties);
    ar & make_nvp("select_name", _select_name);
    ar & make_nvp("select_vendor", _select_vendor);
    ar & make_nvp("select_driver_version", _select_driver_version);
    ar & make_nvp("select_profile", _select_profile);
    ar & make_nvp("select_version", _select_version);
    ar & make_nvp("select_extensions", _select_extensions);
    ar & make_nvp("select_platform_id", _select_platform_id);
    ar & make_nvp("select_double_fp_config", _select_double_fp_config);
    ar & make_nvp("select_preferred_vector_width_half", _select_preferred_vector_width_half);
    ar & make_nvp("select_host_unified_memory", _select_host_unified_memory);
    ar & make_nvp("select_native_vector_width_char", _select_native_vector_width_char);
    ar & make_nvp("select_native_vector_width_short", _select_native_vector_width_short);
    ar & make_nvp("select_native_vector_width_int", _select_native_vector_width_int);
    ar & make_nvp("select_native_vector_width_long", _select_native_vector_width_long);
    ar & make_nvp("select_native_vector_width_float", _select_native_vector_width_float);
    ar & make_nvp("select_native_vector_width_double", _select_native_vector_width_double);
    ar & make_nvp("select_native_vector_width_half", _select_native_vector_width_half);
    ar & make_nvp("select_opencl_c_version", _select_opencl_c_version);
    ar & make_nvp("select_linker_available", _select_linker_available);
    ar & make_nvp("select_built_in_kernels", _select_built_in_kernels);
    ar & make_nvp("select_image_max_buffer_size", _select_image_max_buffer_size);
    ar & make_nvp("select_image_max_array_size", _select_image_max_array_size);
    ar & make_nvp("select_image_max_array_size",_select_image_max_array_size);
    ar & make_nvp("select_parent_device_id",_select_parent_device_id);
    ar & make_nvp("select_partition_max_sub_devices",_select_partition_max_sub_devices);
    ar & make_nvp("select_partition_properties",_select_partition_properties);
    ar & make_nvp("select_partition_affinity_domain",_select_partition_affinity_domain);
    ar & make_nvp("select_partition_type",_select_partition_type);
    ar & make_nvp("select_reference_count",_select_reference_count);
    ar & make_nvp("select_preferred_interop_user_sync",_select_preferred_interop_user_sync);
    ar & make_nvp("select_printf_buffer_size",_select_printf_buffer_size);
    ar & make_nvp("select_image_pitch_alignment",_select_image_pitch_alignment);
    ar & make_nvp("select_image_base_address_alignment",_select_image_base_address_alignment);
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
  bool _select_max_work_group_size;
  bool _select_max_work_item_sizes;
  bool _select_preferred_vector_width_char;
  bool _select_preferred_vector_width_short;
  bool _select_preferred_vector_width_int;
  bool _select_preferred_vector_width_long;
  bool _select_preferred_vector_width_float;
  bool _select_preferred_vector_width_double;
  bool _select_max_clock_frequency;
  bool _select_address_bits;
  bool _select_max_read_image_args;
  bool _select_max_write_image_args;
  bool _select_max_mem_alloc_size;
  bool _select_image2d_max_width;
  bool _select_image2d_max_height;
  bool _select_image3d_max_width;
  bool _select_image3d_max_height;
  bool _select_image3d_max_depth;
  bool _select_image_support;
  bool _select_max_parameter_size;
  bool _select_max_samplers;
  bool _select_mem_base_addr_align;
  bool _select_min_data_type_align_size;
  bool _select_single_fp_config;
  bool _select_global_mem_cache_type;
  bool _select_global_mem_cacheline_size;
  bool _select_global_mem_cache_size;
  bool _select_global_mem_size;
  bool _select_max_constant_buffer_size;
  bool _select_max_constant_args;
  bool _select_local_mem_type;
  bool _select_local_mem_size;
  bool _select_error_correction_support;
  bool _select_profiling_timer_resolution;
  bool _select_endian_little;
  bool _select_available;
  bool _select_compiler_available;
  bool _select_execution_capabilities;
  bool _select_queue_properties;
  bool _select_name;
  bool _select_vendor;
  bool _select_driver_version;
  bool _select_profile;
  bool _select_version;
  bool _select_extensions;
  bool _select_platform_id;
  bool _select_double_fp_config;
  bool _select_preferred_vector_width_half;
  bool _select_host_unified_memory;
  bool _select_native_vector_width_char;
  bool _select_native_vector_width_short;
  bool _select_native_vector_width_int;
  bool _select_native_vector_width_long;
  bool _select_native_vector_width_float;
  bool _select_native_vector_width_double;
  bool _select_native_vector_width_half;
  bool _select_opencl_c_version;
  bool _select_linker_available;
  bool _select_built_in_kernels;
  bool _select_image_max_buffer_size;
  bool _select_image_max_array_size;
  bool _select_parent_device_id;
  bool _select_partition_max_sub_devices;
  bool _select_partition_properties;
  bool _select_partition_affinity_domain;
  bool _select_partition_type;
  bool _select_reference_count;
  bool _select_preferred_interop_user_sync;
  bool _select_printf_buffer_size;
  bool _select_image_pitch_alignment;
  bool _select_image_base_address_alignment;
  // }}}
};

bool operator==(Device_Query const&, Device_Query const&);
inline bool operator!=(Device_Query const& a, Device_Query const& b)
{ return !(a == b);}

} /* namespace Cl */
} /* namespace Dimbo */

#ifndef SWIG // FIXME: provide more verbose constant name
BOOST_CLASS_VERSION( Dimbo::Cl::Device_Query
                   , Dimbo::Cl::Device_Query::class_version )
#endif

#endif /* DIMBO_CL_DEVICE_INFO_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
