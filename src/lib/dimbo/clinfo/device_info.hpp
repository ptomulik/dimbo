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

// dimbo/clinfo/device_info.hpp

/** // doc: dimbo/clinfo/device_info.hpp {{{
 * \file dimbo/clinfo/device_info.hpp
 * \todo Refine
 *
 * This module contains class Dimbo::Clinfo::Device_Info which stores paramteres
 * of an OpenClinfo device.
 *
 */ // }}}
#ifndef DIMBO_CLINFO_DEVICE_INFO_HPP_INCLUDED
#define DIMBO_CLINFO_DEVICE_INFO_HPP_INCLUDED

#include <vector>
#include <string>
#include <boost/optional.hpp>

#include <dimbo/clinfo/throw.hpp>
#include <dimbo/clinfo/exceptions/bad_alloc.hpp>
#include <dimbo/clinfo/exceptions/length_error.hpp>
#include <dimbo/clinfo/exceptions/uninitialized_value.hpp>

// FIXME: it would be great if we could get rid of this dependency
#include <CL/cl.h>

namespace Dimbo {
namespace Clinfo {

/** // doc: class Device_Info {{{
 * \ingroup Dimbo_Clinfo_Platform
 * \class Dimbo::Clinfo::Device_Info
 * \brief Container for device parameters.
 *
 * This class encapsulates the result of a single query to OpenCL function
 * \c clGetDeviceInfo(). The query is defined by Dimbo::Clinfo::Device_Query.
 * The Dimbo::Clinfo::Device_Info may be filled-in with device parameters in
 * several ways. The info may be queried at
 *
 * \todo Refine documentation
 */ // }}}
class Device_Info
{
  template <class Archive>
  friend void _serialize(Archive&, Device_Info&, const unsigned int);
public:
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: Device_Info() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info();
  /** // doc: ~Device_Info() {{{
   * \todo Write documentation for class Device_Info
   */ // }}}
  virtual ~Device_Info();
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear();
  /** // doc: cmp(rhs) {{{
   * \todo Write documentation
   */ // }}}
  bool cmp(Device_Info const&) const throw();
  // getters {{{
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_type type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint vendor_id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_compute_units() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_work_item_dimensions() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t max_work_group_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<size_t> max_work_item_sizes() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_char() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_short() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_int() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_long() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_float() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_double() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_clock_frequency() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint address_bits() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_read_image_args() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_write_image_args() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong max_mem_alloc_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image2d_max_width() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image2d_max_height() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_width() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_height() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_depth() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool image_support() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t max_parameter_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_samplers() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint mem_base_addr_align() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint min_data_type_align_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_fp_config single_fp_config() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_mem_cache_type global_mem_cache_type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint global_mem_cacheline_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong global_mem_cache_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong global_mem_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong max_constant_buffer_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_constant_args() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_local_mem_type local_mem_type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong local_mem_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool error_correction_support() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t profiling_timer_resolution() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool endian_little() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool available() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool compiler_available() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_exec_capabilities execution_capabilities() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_command_queue_properties queue_properties() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& name() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& vendor() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& driver_version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& profile() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& extensions() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long platform_id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_fp_config double_fp_config() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_half() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool host_unified_memory() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_char() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_short() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_int() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_long() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_float() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_double() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_half() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& opencl_c_version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool linker_available() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& built_in_kernels() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image_max_buffer_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image_max_array_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long parent_device_id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint partition_max_sub_devices() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<cl_device_partition_property> partition_properties() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_affinity_domain partition_affinity_domain() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<cl_device_partition_property> partition_type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint reference_count() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool preferred_interop_user_sync() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t printf_buffer_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint image_pitch_alignment() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint image_base_address_alignment() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  // }}}
  // setters {{{
  /** doc: set_id(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_id(unsigned long val) throw();
  /** doc: set_type(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_type(cl_device_type val) throw();
  /** doc: set_vendor_id(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_vendor_id(cl_uint val) throw();
  /** doc: set_max_compute_units(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_compute_units(cl_uint val) throw();
  /** doc: set_max_work_item_dimensions(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_work_item_dimensions(cl_uint val) throw();
  /** doc: set_max_work_group_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_work_group_size(size_t val) throw();
  /** doc: set_max_work_item_sizes(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_work_item_sizes(std::vector<size_t> const& val);
  /** doc: set_preferred_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_char(cl_uint val) throw();
  /** doc: set_preferred_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_short(cl_uint val) throw();
  /** doc: set_preferred_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_int(cl_uint val) throw();
  /** doc: set_preferred_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_long(cl_uint val) throw();
  /** doc: set_preferred_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_float(cl_uint val) throw();
  /** doc: set_preferred_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_double(cl_uint val) throw();
  /** doc: set_max_clock_frequency(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_clock_frequency(cl_uint val) throw();
  /** doc: set_address_bits(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_address_bits(cl_uint val) throw();
  /** doc: set_max_read_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_read_image_args(cl_uint val) throw();
  /** doc: set_max_write_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_write_image_args(cl_uint val) throw();
  /** doc: set_max_mem_alloc_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_mem_alloc_size(cl_ulong val) throw();
  /** doc: set_image2d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image2d_max_width(size_t val) throw();
  /** doc: set_image2d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image2d_max_height(size_t val) throw();
  /** doc: set_image3d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image3d_max_width(size_t val) throw();
  /** doc: set_image3d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image3d_max_height(size_t val) throw();
  /** doc: set_image3d_max_depth(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image3d_max_depth(size_t val) throw();
  /** doc: set_image_support(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image_support(cl_bool val) throw();
  /** doc: set_max_parameter_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_parameter_size(size_t val) throw();
  /** doc: set_max_samplers(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_samplers(cl_uint val) throw();
  /** doc: set_mem_base_addr_align(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_mem_base_addr_align(cl_uint val) throw();
  /** doc: set_min_data_type_align_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_min_data_type_align_size(cl_uint val) throw();
  /** doc: set_single_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_single_fp_config(cl_device_fp_config val) throw();
  /** doc: set_global_mem_cache_type(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_global_mem_cache_type(cl_device_mem_cache_type val) throw();
  /** doc: set_global_mem_cacheline_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_global_mem_cacheline_size(cl_uint val) throw();
  /** doc: set_global_mem_cache_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_global_mem_cache_size(cl_ulong val) throw();
  /** doc: set_global_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_global_mem_size(cl_ulong val) throw();
  /** doc: set_max_constant_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_constant_buffer_size(cl_uint val) throw();
  /** doc: set_max_constant_args(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_max_constant_args(cl_uint val) throw();
  /** doc: set_local_mem_type(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_local_mem_type(cl_device_local_mem_type val) throw();
  /** doc: set_local_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_local_mem_size(cl_ulong val) throw();
  /** doc: set_error_correction_support(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_error_correction_support(cl_bool val) throw();
  /** doc: set_profiling_timer_resolution(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_profiling_timer_resolution(size_t val) throw();
  /** doc: set_endian_little(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_endian_little(cl_bool val) throw();
  /** doc: set_available(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_available(cl_bool val) throw();
  /** doc: set_compiler_available(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_compiler_available(cl_bool val) throw();
  /** doc: set_execution_capabilities(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_execution_capabilities(cl_device_exec_capabilities val) throw();
  /** doc: set_queue_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_queue_properties(cl_command_queue_properties val) throw();
  /** doc: set_name(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_name(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_vendor(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_vendor(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_driver_version(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_driver_version(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_profile(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_profile(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_version(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_version(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_extensions(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_extensions(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_platform_id(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_platform_id(unsigned long val) throw();
  /** doc: set_double_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_double_fp_config(cl_device_fp_config val) throw();
  /** doc: set_preferred_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_vector_width_half(cl_uint val) throw();
  /** doc: set_host_unified_memory(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_host_unified_memory(cl_bool val) throw();
  /** doc: set_native_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_char(cl_uint val) throw();
  /** doc: set_native_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_short(cl_uint val) throw();
  /** doc: set_native_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_int(cl_uint val) throw();
  /** doc: set_native_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_long(cl_uint val) throw();
  /** doc: set_native_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_float(cl_uint val) throw();
  /** doc: set_native_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_double(cl_uint val) throw();
  /** doc: set_native_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_native_vector_width_half(cl_uint val) throw();
  /** doc: set_opencl_c_version(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_opencl_c_version(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_linker_available(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_linker_available(cl_bool val) throw();
  /** doc: set_built_in_kernels(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_built_in_kernels(std::string const& val)
    throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error));
  /** doc: set_image_max_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image_max_buffer_size(size_t val) throw();
  /** doc: set_image_max_array_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image_max_array_size(size_t val) throw();
  /** doc: set_parent_device_id(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_parent_device_id(unsigned long val) throw();
  /** doc: set_partition_max_sub_devices(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_partition_max_sub_devices(cl_uint val) throw();
  /** doc: set_partition_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_partition_properties(std::vector<cl_device_partition_property> const& val);
  /** doc: set_partition_affinity_domain(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_partition_affinity_domain(cl_device_affinity_domain val) throw();
  /** doc: set_partition_type(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_partition_type(std::vector<cl_device_partition_property> const& val);
  /** doc: set_reference_count(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_reference_count(cl_uint val) throw();
  /** doc: set_preferred_interop_user_sync(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_preferred_interop_user_sync(cl_bool val) throw();
  /** doc: set_printf_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_printf_buffer_size(size_t val) throw();
  /** doc: set_image_pitch_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image_pitch_alignment(cl_uint val) throw();
  /** doc: set_image_base_address_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_image_base_address_alignment(cl_uint val) throw();
  // }}}
  // cleaners {{{
  /** doc: clear_id() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_id() throw();
  /** doc: clear_type() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_type() throw();
  /** doc: clear_vendor_id() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_vendor_id() throw();
  /** doc: clear_max_compute_units() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_compute_units() throw();
  /** doc: clear_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_work_item_dimensions() throw();
  /** doc: clear_max_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_work_group_size() throw();
  /** doc: clear_max_work_item_sizes() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_work_item_sizes() throw();
  /** doc: clear_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_char() throw();
  /** doc: clear_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_short() throw();
  /** doc: clear_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_int() throw();
  /** doc: clear_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_long() throw();
  /** doc: clear_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_float() throw();
  /** doc: clear_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_double() throw();
  /** doc: clear_max_clock_frequency() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_clock_frequency() throw();
  /** doc: clear_address_bits() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_address_bits() throw();
  /** doc: clear_max_read_image_args() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_read_image_args() throw();
  /** doc: clear_max_write_image_args() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_write_image_args() throw();
  /** doc: clear_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_mem_alloc_size() throw();
  /** doc: clear_image2d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image2d_max_width() throw();
  /** doc: clear_image2d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image2d_max_height() throw();
  /** doc: clear_image3d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image3d_max_width() throw();
  /** doc: clear_image3d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image3d_max_height() throw();
  /** doc: clear_image3d_max_depth() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image3d_max_depth() throw();
  /** doc: clear_image_support() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image_support() throw();
  /** doc: clear_max_parameter_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_parameter_size() throw();
  /** doc: clear_max_samplers() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_samplers() throw();
  /** doc: clear_mem_base_addr_align() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_mem_base_addr_align() throw();
  /** doc: clear_min_data_type_align_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_min_data_type_align_size() throw();
  /** doc: clear_single_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_single_fp_config() throw();
  /** doc: clear_global_mem_cache_type() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_global_mem_cache_type() throw();
  /** doc: clear_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_global_mem_cacheline_size() throw();
  /** doc: clear_global_mem_cache_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_global_mem_cache_size() throw();
  /** doc: clear_global_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_global_mem_size() throw();
  /** doc: clear_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_constant_buffer_size() throw();
  /** doc: clear_max_constant_args() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_max_constant_args() throw();
  /** doc: clear_local_mem_type() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_local_mem_type() throw();
  /** doc: clear_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_local_mem_size() throw();
  /** doc: clear_error_correction_support() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_error_correction_support() throw();
  /** doc: clear_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_profiling_timer_resolution() throw();
  /** doc: clear_endian_little() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_endian_little() throw();
  /** doc: clear_available() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_available() throw();
  /** doc: clear_compiler_available() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_compiler_available() throw();
  /** doc: clear_execution_capabilities() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_execution_capabilities() throw();
  /** doc: clear_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_queue_properties() throw();
  /** doc: clear_name() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_name() throw();
  /** doc: clear_vendor() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_vendor() throw();
  /** doc: clear_driver_version() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_driver_version() throw();
  /** doc: clear_profile() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_profile() throw();
  /** doc: clear_version() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_version() throw();
  /** doc: clear_extensions() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_extensions() throw();
  /** doc: clear_platform_id() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_platform_id() throw();
  /** doc: clear_double_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_double_fp_config() throw();
  /** doc: clear_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_vector_width_half() throw();
  /** doc: clear_host_unified_memory() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_host_unified_memory() throw();
  /** doc: clear_native_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_char() throw();
  /** doc: clear_native_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_short() throw();
  /** doc: clear_native_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_int() throw();
  /** doc: clear_native_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_long() throw();
  /** doc: clear_native_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_float() throw();
  /** doc: clear_native_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_double() throw();
  /** doc: clear_native_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_native_vector_width_half() throw();
  /** doc: clear_opencl_c_version() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_opencl_c_version() throw();
  /** doc: clear_linker_available() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_linker_available() throw();
  /** doc: clear_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_built_in_kernels() throw();
  /** doc: clear_image_max_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image_max_buffer_size() throw();
  /** doc: clear_image_max_array_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image_max_array_size() throw();
  /** doc: clear_parent_device_id() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_parent_device_id() throw();
  /** doc: clear_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_partition_max_sub_devices() throw();
  /** doc: clear_partition_properties() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_partition_properties() throw();
  /** doc: clear_partition_affinity_domain() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_partition_affinity_domain() throw();
  /** doc: clear_partition_type() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_partition_type() throw();
  /** doc: clear_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_reference_count() throw();
  /** doc: clear_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_preferred_interop_user_sync() throw();
  /** doc: clear_printf_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_printf_buffer_size() throw();
  /** doc: clear_image_pitch_alignment() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image_pitch_alignment() throw();
  /** doc: clear_image_base_address_alignment() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_image_base_address_alignment() throw();
  // }}}
  // presence {{{
  /** doc: has_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_id() const throw();
  /** doc: has_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_type() const throw();
  /** doc: has_vendor_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_vendor_id() const throw();
  /** doc: has_max_compute_units(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_compute_units() const throw();
  /** doc: has_max_work_item_dimensions(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_work_item_dimensions() const throw();
  /** doc: has_max_work_group_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_work_group_size() const throw();
  /** doc: has_max_work_item_sizes(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_work_item_sizes() const throw();
  /** doc: has_preferred_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_char() const throw();
  /** doc: has_preferred_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_short() const throw();
  /** doc: has_preferred_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_int() const throw();
  /** doc: has_preferred_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_long() const throw();
  /** doc: has_preferred_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_float() const throw();
  /** doc: has_preferred_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_double() const throw();
  /** doc: has_max_clock_frequency(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_clock_frequency() const throw();
  /** doc: has_address_bits(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_address_bits() const throw();
  /** doc: has_max_read_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_read_image_args() const throw();
  /** doc: has_max_write_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_write_image_args() const throw();
  /** doc: has_max_mem_alloc_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_mem_alloc_size() const throw();
  /** doc: has_image2d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image2d_max_width() const throw();
  /** doc: has_image2d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image2d_max_height() const throw();
  /** doc: has_image3d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image3d_max_width() const throw();
  /** doc: has_image3d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image3d_max_height() const throw();
  /** doc: has_image3d_max_depth(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image3d_max_depth() const throw();
  /** doc: has_image_support(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_support() const throw();
  /** doc: has_max_parameter_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_parameter_size() const throw();
  /** doc: has_max_samplers(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_samplers() const throw();
  /** doc: has_mem_base_addr_align(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_mem_base_addr_align() const throw();
  /** doc: has_min_data_type_align_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_min_data_type_align_size() const throw();
  /** doc: has_single_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_single_fp_config() const throw();
  /** doc: has_global_mem_cache_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_cache_type() const throw();
  /** doc: has_global_mem_cacheline_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_cacheline_size() const throw();
  /** doc: has_global_mem_cache_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_cache_size() const throw();
  /** doc: has_global_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_size() const throw();
  /** doc: has_max_constant_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_constant_buffer_size() const throw();
  /** doc: has_max_constant_args(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_constant_args() const throw();
  /** doc: has_local_mem_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_local_mem_type() const throw();
  /** doc: has_local_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_local_mem_size() const throw();
  /** doc: has_error_correction_support(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_error_correction_support() const throw();
  /** doc: has_profiling_timer_resolution(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_profiling_timer_resolution() const throw();
  /** doc: has_endian_little(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_endian_little() const throw();
  /** doc: has_available(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_available() const throw();
  /** doc: has_compiler_available(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_compiler_available() const throw();
  /** doc: has_execution_capabilities(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_execution_capabilities() const throw();
  /** doc: has_queue_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_queue_properties() const throw();
  /** doc: has_name(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_name() const throw();
  /** doc: has_vendor(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_vendor() const throw();
  /** doc: has_driver_version(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_driver_version() const throw();
  /** doc: has_profile(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_profile() const throw();
  /** doc: has_version(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_version() const throw();
  /** doc: has_extensions(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_extensions() const throw();
  /** doc: has_platform_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_platform_id() const throw();
  /** doc: has_double_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_double_fp_config() const throw();
  /** doc: has_preferred_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_half() const throw();
  /** doc: has_host_unified_memory(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_host_unified_memory() const throw();
  /** doc: has_native_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_char() const throw();
  /** doc: has_native_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_short() const throw();
  /** doc: has_native_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_int() const throw();
  /** doc: has_native_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_long() const throw();
  /** doc: has_native_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_float() const throw();
  /** doc: has_native_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_double() const throw();
  /** doc: has_native_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_half() const throw();
  /** doc: has_opencl_c_version(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_opencl_c_version() const throw();
  /** doc: has_linker_available(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_linker_available() const throw();
  /** doc: has_built_in_kernels(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_built_in_kernels() const throw();
  /** doc: has_image_max_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_max_buffer_size() const throw();
  /** doc: has_image_max_array_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_max_array_size() const throw();
  /** doc: has_parent_device_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_parent_device_id() const throw();
  /** doc: has_partition_max_sub_devices(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_max_sub_devices() const throw();
  /** doc: has_partition_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_properties() const throw();
  /** doc: has_partition_affinity_domain(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_affinity_domain() const throw();
  /** doc: has_partition_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_type() const throw();
  /** doc: has_reference_count(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_reference_count() const throw();
  /** doc: has_preferred_interop_user_sync(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_interop_user_sync() const throw();
  /** doc: has_printf_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_printf_buffer_size() const throw();
  /** doc: has_image_pitch_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_pitch_alignment() const throw();
  /** doc: has_image_base_address_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_base_address_alignment() const throw();
  // }}}
private:
  void _init();
  void _clear();
  // attributes {{{
  boost::optional<unsigned long> _id;
  boost::optional<cl_device_type> _type;
  boost::optional<cl_uint> _vendor_id;
  boost::optional<cl_uint> _max_compute_units;
  boost::optional<cl_uint> _max_work_item_dimensions;
  boost::optional<size_t> _max_work_group_size;
  boost::optional<std::vector<size_t> > _max_work_item_sizes;
  boost::optional<cl_uint> _preferred_vector_width_char;
  boost::optional<cl_uint> _preferred_vector_width_short;
  boost::optional<cl_uint> _preferred_vector_width_int;
  boost::optional<cl_uint> _preferred_vector_width_long;
  boost::optional<cl_uint> _preferred_vector_width_float;
  boost::optional<cl_uint> _preferred_vector_width_double;
  boost::optional<cl_uint> _max_clock_frequency;
  boost::optional<cl_uint> _address_bits;
  boost::optional<cl_uint> _max_read_image_args;
  boost::optional<cl_uint> _max_write_image_args;
  boost::optional<cl_ulong> _max_mem_alloc_size;
  boost::optional<size_t> _image2d_max_width;
  boost::optional<size_t> _image2d_max_height;
  boost::optional<size_t> _image3d_max_width;
  boost::optional<size_t> _image3d_max_height;
  boost::optional<size_t> _image3d_max_depth;
  boost::optional<cl_bool> _image_support;
  boost::optional<size_t> _max_parameter_size;
  boost::optional<cl_uint> _max_samplers;
  boost::optional<cl_uint> _mem_base_addr_align;
  boost::optional<cl_uint> _min_data_type_align_size;
  boost::optional<cl_device_fp_config> _single_fp_config;
  boost::optional<cl_device_mem_cache_type> _global_mem_cache_type;
  boost::optional<cl_uint> _global_mem_cacheline_size;
  boost::optional<cl_ulong> _global_mem_cache_size;
  boost::optional<cl_ulong> _global_mem_size;
  boost::optional<cl_uint> _max_constant_buffer_size;
  boost::optional<cl_uint> _max_constant_args;
  boost::optional<cl_device_local_mem_type> _local_mem_type;
  boost::optional<cl_ulong> _local_mem_size;
  boost::optional<cl_bool> _error_correction_support;
  boost::optional<size_t> _profiling_timer_resolution;
  boost::optional<cl_bool> _endian_little;
  boost::optional<cl_bool> _available;
  boost::optional<cl_bool> _compiler_available;
  boost::optional<cl_device_exec_capabilities> _execution_capabilities;
  boost::optional<cl_command_queue_properties> _queue_properties;
  boost::optional<std::string>  _name;
  boost::optional<std::string>  _vendor;
  boost::optional<std::string>  _driver_version;
  boost::optional<std::string>  _profile;
  boost::optional<std::string>  _version;
  boost::optional<std::string>  _extensions;
  boost::optional<unsigned long> _platform_id;
  boost::optional<cl_device_fp_config> _double_fp_config;
  boost::optional<cl_uint> _preferred_vector_width_half;
  boost::optional<cl_bool> _host_unified_memory;
  boost::optional<cl_uint> _native_vector_width_char;
  boost::optional<cl_uint> _native_vector_width_short;
  boost::optional<cl_uint> _native_vector_width_int;
  boost::optional<cl_uint> _native_vector_width_long;
  boost::optional<cl_uint> _native_vector_width_float;
  boost::optional<cl_uint> _native_vector_width_double;
  boost::optional<cl_uint> _native_vector_width_half;
  boost::optional<std::string>  _opencl_c_version;
  boost::optional<cl_bool> _linker_available;
  boost::optional<std::string>  _built_in_kernels;
  boost::optional<size_t> _image_max_buffer_size;
  boost::optional<size_t> _image_max_array_size;
  boost::optional<unsigned long> _parent_device_id;
  boost::optional<cl_uint> _partition_max_sub_devices;
  boost::optional<std::vector<cl_device_partition_property> > _partition_properties;
  boost::optional<cl_device_affinity_domain> _partition_affinity_domain;
  boost::optional<std::vector<cl_device_partition_property> > _partition_type;
  boost::optional<cl_uint> _reference_count;
  boost::optional<cl_bool> _preferred_interop_user_sync;
  boost::optional<size_t> _printf_buffer_size;
  boost::optional<cl_uint> _image_pitch_alignment;
  boost::optional<cl_uint> _image_base_address_alignment;
  // }}}
};

/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator== (Device_Info const& a, Device_Info const& b)
  throw()
{ return a.cmp(b); }
/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!= (Device_Info const& a, Device_Info const& b)
  throw()
{ return !(a == b); }

} /* namespace Clinfo */
} /* namespace Dimbo */

#endif /* DIMBO_CLINFO_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
