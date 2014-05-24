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
  inline unsigned long id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_id.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_type type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_type.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint vendor_id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_vendor_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_vendor_id.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_compute_units() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_compute_units()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_compute_units.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_work_item_dimensions() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_work_item_dimensions()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_work_item_dimensions.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t max_work_group_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_work_group_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_work_group_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::vector<size_t> max_work_item_sizes() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_work_item_sizes()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_work_item_sizes.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_char() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_char()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_char.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_short() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_short()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_short.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_int() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_int()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_int.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_long() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_long()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_long.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_float() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_float()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_float.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_double() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_double()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_double.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_clock_frequency() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_clock_frequency()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_clock_frequency.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint address_bits() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_address_bits()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_address_bits.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_read_image_args() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_read_image_args()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_read_image_args.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_write_image_args() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_write_image_args()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_write_image_args.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_ulong max_mem_alloc_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_mem_alloc_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_mem_alloc_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image2d_max_width() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image2d_max_width()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image2d_max_width.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image2d_max_height() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image2d_max_height()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image2d_max_height.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image3d_max_width() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image3d_max_width()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image3d_max_width.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image3d_max_height() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image3d_max_height()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image3d_max_height.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image3d_max_depth() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image3d_max_depth()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image3d_max_depth.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool image_support() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image_support()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image_support.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t max_parameter_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_parameter_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_parameter_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_samplers() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_samplers()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_samplers.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint mem_base_addr_align() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_mem_base_addr_align()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_mem_base_addr_align.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint min_data_type_align_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_min_data_type_align_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_min_data_type_align_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_fp_config single_fp_config() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_single_fp_config()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_single_fp_config.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_mem_cache_type global_mem_cache_type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_global_mem_cache_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_global_mem_cache_type.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint global_mem_cacheline_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_global_mem_cacheline_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_global_mem_cacheline_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_ulong global_mem_cache_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_global_mem_cache_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_global_mem_cache_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_ulong global_mem_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_global_mem_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_global_mem_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_ulong max_constant_buffer_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_constant_buffer_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_constant_buffer_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint max_constant_args() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_max_constant_args()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_max_constant_args.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_local_mem_type local_mem_type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_local_mem_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_local_mem_type.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_ulong local_mem_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_local_mem_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_local_mem_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool error_correction_support() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_error_correction_support()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_error_correction_support.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t profiling_timer_resolution() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_profiling_timer_resolution()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_profiling_timer_resolution.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool endian_little() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_endian_little()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_endian_little.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool available() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_available()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_available.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool compiler_available() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_compiler_available()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_compiler_available.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_exec_capabilities execution_capabilities() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_execution_capabilities()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_execution_capabilities.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_command_queue_properties queue_properties() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_queue_properties()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_queue_properties.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& name() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_name()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_name.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& vendor() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_vendor()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_vendor.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& driver_version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_driver_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_driver_version.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& profile() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_profile()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_profile.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_version.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& extensions() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_extensions()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_extensions.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline unsigned long platform_id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_platform_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_platform_id.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_fp_config double_fp_config() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_double_fp_config()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_double_fp_config.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint preferred_vector_width_half() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_vector_width_half()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_vector_width_half.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool host_unified_memory() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_host_unified_memory()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_host_unified_memory.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_char() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_char()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_char.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_short() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_short()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_short.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_int() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_int()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_int.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_long() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_long()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_long.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_float() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_float()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_float.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_double() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_double()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_double.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint native_vector_width_half() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_native_vector_width_half()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_native_vector_width_half.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& opencl_c_version() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_opencl_c_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_opencl_c_version.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool linker_available() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_linker_available()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_linker_available.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::string const& built_in_kernels() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_built_in_kernels()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_built_in_kernels.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image_max_buffer_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image_max_buffer_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image_max_buffer_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t image_max_array_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image_max_array_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image_max_array_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline unsigned long parent_device_id() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_parent_device_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_parent_device_id.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint partition_max_sub_devices() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_partition_max_sub_devices()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_partition_max_sub_devices.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::vector<cl_device_partition_property> partition_properties() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_partition_properties()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_partition_properties.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_device_affinity_domain partition_affinity_domain() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_partition_affinity_domain()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_partition_affinity_domain.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline std::vector<cl_device_partition_property> partition_type() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_partition_type()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_partition_type.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint reference_count() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_reference_count()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_reference_count.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_bool preferred_interop_user_sync() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_preferred_interop_user_sync()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_preferred_interop_user_sync.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline size_t printf_buffer_size() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_printf_buffer_size()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_printf_buffer_size.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint image_pitch_alignment() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image_pitch_alignment()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image_pitch_alignment.get();
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  inline cl_uint image_base_address_alignment() const
    throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
  {
    if(!this->has_image_base_address_alignment()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
    return this->_image_base_address_alignment.get();
  }
  // }}}
  // setters {{{
  /** doc: set_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_id(unsigned long val) throw()
  {
    this->_id = val;
    return *this;
  }
  /** doc: set_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_type(cl_device_type val) throw()
  {
    this->_type = val;
    return *this;
  }
  /** doc: set_vendor_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_vendor_id(cl_uint val) throw()
  {
    this->_vendor_id = val;
    return *this;
  }
  /** doc: set_max_compute_units(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_compute_units(cl_uint val) throw()
  {
    this->_max_compute_units = val;
    return *this;
  }
  /** doc: set_max_work_item_dimensions(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_work_item_dimensions(cl_uint val) throw()
  {
    this->_max_work_item_dimensions = val;
    return *this;
  }
  /** doc: set_max_work_group_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_work_group_size(size_t val) throw()
  {
    this->_max_work_group_size = val;
    return *this;
  }
  /** doc: set_max_work_item_sizes(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_work_item_sizes(std::vector<size_t> const& val)
  {
    this->_max_work_item_sizes = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_char(cl_uint val) throw()
  {
    this->_preferred_vector_width_char = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_short(cl_uint val) throw()
  {
    this->_preferred_vector_width_short = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_int(cl_uint val) throw()
  {
    this->_preferred_vector_width_int = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_long(cl_uint val) throw()
  {
    this->_preferred_vector_width_long = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_float(cl_uint val) throw()
  {
    this->_preferred_vector_width_float = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_double(cl_uint val) throw()
  {
    this->_preferred_vector_width_double = val;
    return *this;
  }
  /** doc: set_max_clock_frequency(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_clock_frequency(cl_uint val) throw()
  {
    this->_max_clock_frequency = val;
    return *this;
  }
  /** doc: set_address_bits(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_address_bits(cl_uint val) throw()
  {
    this->_address_bits = val;
    return *this;
  }
  /** doc: set_max_read_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_read_image_args(cl_uint val) throw()
  {
    this->_max_read_image_args = val;
    return *this;
  }
  /** doc: set_max_write_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_write_image_args(cl_uint val) throw()
  {
    this->_max_write_image_args = val;
    return *this;
  }
  /** doc: set_max_mem_alloc_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_mem_alloc_size(cl_ulong val) throw()
  {
    this->_max_mem_alloc_size = val;
    return *this;
  }
  /** doc: set_image2d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image2d_max_width(size_t val) throw()
  {
    this->_image2d_max_width = val;
    return *this;
  }
  /** doc: set_image2d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image2d_max_height(size_t val) throw()
  {
    this->_image2d_max_height = val;
    return *this;
  }
  /** doc: set_image3d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image3d_max_width(size_t val) throw()
  {
    this->_image3d_max_width = val;
    return *this;
  }
  /** doc: set_image3d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image3d_max_height(size_t val) throw()
  {
    this->_image3d_max_height = val;
    return *this;
  }
  /** doc: set_image3d_max_depth(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image3d_max_depth(size_t val) throw()
  {
    this->_image3d_max_depth = val;
    return *this;
  }
  /** doc: set_image_support(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image_support(cl_bool val) throw()
  {
    this->_image_support = val;
    return *this;
  }
  /** doc: set_max_parameter_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_parameter_size(size_t val) throw()
  {
    this->_max_parameter_size = val;
    return *this;
  }
  /** doc: set_max_samplers(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_samplers(cl_uint val) throw()
  {
    this->_max_samplers = val;
    return *this;
  }
  /** doc: set_mem_base_addr_align(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_mem_base_addr_align(cl_uint val) throw()
  {
    this->_mem_base_addr_align = val;
    return *this;
  }
  /** doc: set_min_data_type_align_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_min_data_type_align_size(cl_uint val) throw()
  {
    this->_min_data_type_align_size = val;
    return *this;
  }
  /** doc: set_single_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_single_fp_config(cl_device_fp_config val) throw()
  {
    this->_single_fp_config = val;
    return *this;
  }
  /** doc: set_global_mem_cache_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_global_mem_cache_type(cl_device_mem_cache_type val) throw()
  {
    this->_global_mem_cache_type = val;
    return *this;
  }
  /** doc: set_global_mem_cacheline_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_global_mem_cacheline_size(cl_uint val) throw()
  {
    this->_global_mem_cacheline_size = val;
    return *this;
  }
  /** doc: set_global_mem_cache_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_global_mem_cache_size(cl_ulong val) throw()
  {
    this->_global_mem_cache_size = val;
    return *this;
  }
  /** doc: set_global_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_global_mem_size(cl_ulong val) throw()
  {
    this->_global_mem_size = val;
    return *this;
  }
  /** doc: set_max_constant_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_constant_buffer_size(cl_uint val) throw()
  {
    this->_max_constant_buffer_size = val;
    return *this;
  }
  /** doc: set_max_constant_args(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_max_constant_args(cl_uint val) throw()
  {
    this->_max_constant_args = val;
    return *this;
  }
  /** doc: set_local_mem_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_local_mem_type(cl_device_local_mem_type val) throw()
  {
    this->_local_mem_type = val;
    return *this;
  }
  /** doc: set_local_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_local_mem_size(cl_ulong val) throw()
  {
    this->_local_mem_size = val;
    return *this;
  }
  /** doc: set_error_correction_support(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_error_correction_support(cl_bool val) throw()
  {
    this->_error_correction_support = val;
    return *this;
  }
  /** doc: set_profiling_timer_resolution(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_profiling_timer_resolution(size_t val) throw()
  {
    this->_profiling_timer_resolution = val;
    return *this;
  }
  /** doc: set_endian_little(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_endian_little(cl_bool val) throw()
  {
    this->_endian_little = val;
    return *this;
  }
  /** doc: set_available(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_available(cl_bool val) throw()
  {
    this->_available = val;
    return *this;
  }
  /** doc: set_compiler_available(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_compiler_available(cl_bool val) throw()
  {
    this->_compiler_available = val;
    return *this;
  }
  /** doc: set_execution_capabilities(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_execution_capabilities(cl_device_exec_capabilities val) throw()
  {
    this->_execution_capabilities = val;
    return *this;
  }
  /** doc: set_queue_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_queue_properties(cl_command_queue_properties val) throw()
  {
    this->_queue_properties = val;
    return *this;
  }
  /** doc: set_name(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_name(std::string const& val)
  {
    this->_name = val;
    return *this;
  }
  /** doc: set_vendor(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_vendor(std::string const& val)
  {
    this->_vendor = val;
    return *this;
  }
  /** doc: set_driver_version(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_driver_version(std::string const& val)
  {
    this->_driver_version = val;
    return *this;
  }
  /** doc: set_profile(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_profile(std::string const& val)
  {
    this->_profile = val;
    return *this;
  }
  /** doc: set_version(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_version(std::string const& val)
  {
    this->_version = val;
    return *this;
  }
  /** doc: set_extensions(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_extensions(std::string const& val)
  {
    this->_extensions = val;
    return *this;
  }
  /** doc: set_platform_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_platform_id(unsigned long val) throw()
  {
    this->_platform_id = val;
    return *this;
  }
  /** doc: set_double_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_double_fp_config(cl_device_fp_config val) throw()
  {
    this->_double_fp_config = val;
    return *this;
  }
  /** doc: set_preferred_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_vector_width_half(cl_uint val) throw()
  {
    this->_preferred_vector_width_half = val;
    return *this;
  }
  /** doc: set_host_unified_memory(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_host_unified_memory(cl_bool val) throw()
  {
    this->_host_unified_memory = val;
    return *this;
  }
  /** doc: set_native_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_char(cl_uint val) throw()
  {
    this->_native_vector_width_char = val;
    return *this;
  }
  /** doc: set_native_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_short(cl_uint val) throw()
  {
    this->_native_vector_width_short = val;
    return *this;
  }
  /** doc: set_native_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_int(cl_uint val) throw()
  {
    this->_native_vector_width_int = val;
    return *this;
  }
  /** doc: set_native_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_long(cl_uint val) throw()
  {
    this->_native_vector_width_long = val;
    return *this;
  }
  /** doc: set_native_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_float(cl_uint val) throw()
  {
    this->_native_vector_width_float = val;
    return *this;
  }
  /** doc: set_native_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_double(cl_uint val) throw()
  {
    this->_native_vector_width_double = val;
    return *this;
  }
  /** doc: set_native_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_native_vector_width_half(cl_uint val) throw()
  {
    this->_native_vector_width_half = val;
    return *this;
  }
  /** doc: set_opencl_c_version(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_opencl_c_version(std::string const& val)
  {
    this->_opencl_c_version = val;
    return *this;
  }
  /** doc: set_linker_available(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_linker_available(cl_bool val) throw()
  {
    this->_linker_available = val;
    return *this;
  }
  /** doc: set_built_in_kernels(val) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& set_built_in_kernels(std::string const& val)
  {
    this->_built_in_kernels = val;
    return *this;
  }
  /** doc: set_image_max_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image_max_buffer_size(size_t val) throw()
  {
    this->_image_max_buffer_size = val;
    return *this;
  }
  /** doc: set_image_max_array_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image_max_array_size(size_t val) throw()
  {
    this->_image_max_array_size = val;
    return *this;
  }
  /** doc: set_parent_device_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_parent_device_id(unsigned long val) throw()
  {
    this->_parent_device_id = val;
    return *this;
  }
  /** doc: set_partition_max_sub_devices(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_partition_max_sub_devices(cl_uint val) throw()
  {
    this->_partition_max_sub_devices = val;
    return *this;
  }
  /** doc: set_partition_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_partition_properties(std::vector<cl_device_partition_property> const& val)
  {
    this->_partition_properties = val;
    return *this;
  }
  /** doc: set_partition_affinity_domain(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_partition_affinity_domain(cl_device_affinity_domain val) throw()
  {
    this->_partition_affinity_domain = val;
    return *this;
  }
  /** doc: set_partition_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_partition_type(std::vector<cl_device_partition_property> const& val)
  {
    this->_partition_type = val;
    return *this;
  }
  /** doc: set_reference_count(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_reference_count(cl_uint val) throw()
  {
    this->_reference_count = val;
    return *this;
  }
  /** doc: set_preferred_interop_user_sync(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_preferred_interop_user_sync(cl_bool val) throw()
  {
    this->_preferred_interop_user_sync = val;
    return *this;
  }
  /** doc: set_printf_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_printf_buffer_size(size_t val) throw()
  {
    this->_printf_buffer_size = val;
    return *this;
  }
  /** doc: set_image_pitch_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image_pitch_alignment(cl_uint val) throw()
  {
    this->_image_pitch_alignment = val;
    return *this;
  }
  /** doc: set_image_base_address_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& set_image_base_address_alignment(cl_uint val) throw()
  {
    this->_image_base_address_alignment = val;
    return *this;
  }
  // }}}
  // cleaners {{{
  /** doc: clear_id() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_id() throw()
  {
    this->_id = boost::none;
    return *this;
  }
  /** doc: clear_type() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_type() throw()
  {
    this->_type = boost::none;
    return *this;
  }
  /** doc: clear_vendor_id() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_vendor_id() throw()
  {
    this->_vendor_id = boost::none;
    return *this;
  }
  /** doc: clear_max_compute_units() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_compute_units() throw()
  {
    this->_max_compute_units = boost::none;
    return *this;
  }
  /** doc: clear_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_work_item_dimensions() throw()
  {
    this->_max_work_item_dimensions = boost::none;
    return *this;
  }
  /** doc: clear_max_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_work_group_size() throw()
  {
    this->_max_work_group_size = boost::none;
    return *this;
  }
  /** doc: clear_max_work_item_sizes() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_work_item_sizes() throw()
  {
    this->_max_work_item_sizes = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_char() throw()
  {
    this->_preferred_vector_width_char = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_short() throw()
  {
    this->_preferred_vector_width_short = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_int() throw()
  {
    this->_preferred_vector_width_int = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_long() throw()
  {
    this->_preferred_vector_width_long = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_float() throw()
  {
    this->_preferred_vector_width_float = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_double() throw()
  {
    this->_preferred_vector_width_double = boost::none;
    return *this;
  }
  /** doc: clear_max_clock_frequency() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_clock_frequency() throw()
  {
    this->_max_clock_frequency = boost::none;
    return *this;
  }
  /** doc: clear_address_bits() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_address_bits() throw()
  {
    this->_address_bits = boost::none;
    return *this;
  }
  /** doc: clear_max_read_image_args() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_read_image_args() throw()
  {
    this->_max_read_image_args = boost::none;
    return *this;
  }
  /** doc: clear_max_write_image_args() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_write_image_args() throw()
  {
    this->_max_write_image_args = boost::none;
    return *this;
  }
  /** doc: clear_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_mem_alloc_size() throw()
  {
    this->_max_mem_alloc_size = boost::none;
    return *this;
  }
  /** doc: clear_image2d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image2d_max_width() throw()
  {
    this->_image2d_max_width = boost::none;
    return *this;
  }
  /** doc: clear_image2d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image2d_max_height() throw()
  {
    this->_image2d_max_height = boost::none;
    return *this;
  }
  /** doc: clear_image3d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image3d_max_width() throw()
  {
    this->_image3d_max_width = boost::none;
    return *this;
  }
  /** doc: clear_image3d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image3d_max_height() throw()
  {
    this->_image3d_max_height = boost::none;
    return *this;
  }
  /** doc: clear_image3d_max_depth() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image3d_max_depth() throw()
  {
    this->_image3d_max_depth = boost::none;
    return *this;
  }
  /** doc: clear_image_support() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image_support() throw()
  {
    this->_image_support = boost::none;
    return *this;
  }
  /** doc: clear_max_parameter_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_parameter_size() throw()
  {
    this->_max_parameter_size = boost::none;
    return *this;
  }
  /** doc: clear_max_samplers() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_samplers() throw()
  {
    this->_max_samplers = boost::none;
    return *this;
  }
  /** doc: clear_mem_base_addr_align() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_mem_base_addr_align() throw()
  {
    this->_mem_base_addr_align = boost::none;
    return *this;
  }
  /** doc: clear_min_data_type_align_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_min_data_type_align_size() throw()
  {
    this->_min_data_type_align_size = boost::none;
    return *this;
  }
  /** doc: clear_single_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_single_fp_config() throw()
  {
    this->_single_fp_config = boost::none;
    return *this;
  }
  /** doc: clear_global_mem_cache_type() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_global_mem_cache_type() throw()
  {
    this->_global_mem_cache_type = boost::none;
    return *this;
  }
  /** doc: clear_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_global_mem_cacheline_size() throw()
  {
    this->_global_mem_cacheline_size = boost::none;
    return *this;
  }
  /** doc: clear_global_mem_cache_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_global_mem_cache_size() throw()
  {
    this->_global_mem_cache_size = boost::none;
    return *this;
  }
  /** doc: clear_global_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_global_mem_size() throw()
  {
    this->_global_mem_size = boost::none;
    return *this;
  }
  /** doc: clear_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_constant_buffer_size() throw()
  {
    this->_max_constant_buffer_size = boost::none;
    return *this;
  }
  /** doc: clear_max_constant_args() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_max_constant_args() throw()
  {
    this->_max_constant_args = boost::none;
    return *this;
  }
  /** doc: clear_local_mem_type() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_local_mem_type() throw()
  {
    this->_local_mem_type = boost::none;
    return *this;
  }
  /** doc: clear_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_local_mem_size() throw()
  {
    this->_local_mem_size = boost::none;
    return *this;
  }
  /** doc: clear_error_correction_support() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_error_correction_support() throw()
  {
    this->_error_correction_support = boost::none;
    return *this;
  }
  /** doc: clear_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_profiling_timer_resolution() throw()
  {
    this->_profiling_timer_resolution = boost::none;
    return *this;
  }
  /** doc: clear_endian_little() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_endian_little() throw()
  {
    this->_endian_little = boost::none;
    return *this;
  }
  /** doc: clear_available() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_available() throw()
  {
    this->_available = boost::none;
    return *this;
  }
  /** doc: clear_compiler_available() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_compiler_available() throw()
  {
    this->_compiler_available = boost::none;
    return *this;
  }
  /** doc: clear_execution_capabilities() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_execution_capabilities() throw()
  {
    this->_execution_capabilities = boost::none;
    return *this;
  }
  /** doc: clear_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_queue_properties() throw()
  {
    this->_queue_properties = boost::none;
    return *this;
  }
  /** doc: clear_name() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_name() throw()
  {
    this->_name = boost::none;
    return *this;
  }
  /** doc: clear_vendor() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_vendor() throw()
  {
    this->_vendor = boost::none;
    return *this;
  }
  /** doc: clear_driver_version() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_driver_version() throw()
  {
    this->_driver_version = boost::none;
    return *this;
  }
  /** doc: clear_profile() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_profile() throw()
  {
    this->_profile = boost::none;
    return *this;
  }
  /** doc: clear_version() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_version() throw()
  {
    this->_version = boost::none;
    return *this;
  }
  /** doc: clear_extensions() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_extensions() throw()
  {
    this->_extensions = boost::none;
    return *this;
  }
  /** doc: clear_platform_id() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_platform_id() throw()
  {
    this->_platform_id = boost::none;
    return *this;
  }
  /** doc: clear_double_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_double_fp_config() throw()
  {
    this->_double_fp_config = boost::none;
    return *this;
  }
  /** doc: clear_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_vector_width_half() throw()
  {
    this->_preferred_vector_width_half = boost::none;
    return *this;
  }
  /** doc: clear_host_unified_memory() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_host_unified_memory() throw()
  {
    this->_host_unified_memory = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_char() throw()
  {
    this->_native_vector_width_char = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_short() throw()
  {
    this->_native_vector_width_short = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_int() throw()
  {
    this->_native_vector_width_int = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_long() throw()
  {
    this->_native_vector_width_long = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_float() throw()
  {
    this->_native_vector_width_float = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_double() throw()
  {
    this->_native_vector_width_double = boost::none;
    return *this;
  }
  /** doc: clear_native_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_native_vector_width_half() throw()
  {
    this->_native_vector_width_half = boost::none;
    return *this;
  }
  /** doc: clear_opencl_c_version() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_opencl_c_version() throw()
  {
    this->_opencl_c_version = boost::none;
    return *this;
  }
  /** doc: clear_linker_available() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_linker_available() throw()
  {
    this->_linker_available = boost::none;
    return *this;
  }
  /** doc: clear_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear_built_in_kernels() throw()
  {
    this->_built_in_kernels = boost::none;
    return *this;
  }
  /** doc: clear_image_max_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image_max_buffer_size() throw()
  {
    this->_image_max_buffer_size = boost::none;
    return *this;
  }
  /** doc: clear_image_max_array_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image_max_array_size() throw()
  {
    this->_image_max_array_size = boost::none;
    return *this;
  }
  /** doc: clear_parent_device_id() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_parent_device_id() throw()
  {
    this->_parent_device_id = boost::none;
    return *this;
  }
  /** doc: clear_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_partition_max_sub_devices() throw()
  {
    this->_partition_max_sub_devices = boost::none;
    return *this;
  }
  /** doc: clear_partition_properties() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_partition_properties() throw()
  {
    this->_partition_properties = boost::none;
    return *this;
  }
  /** doc: clear_partition_affinity_domain() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_partition_affinity_domain() throw()
  {
    this->_partition_affinity_domain = boost::none;
    return *this;
  }
  /** doc: clear_partition_type() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_partition_type() throw()
  {
    this->_partition_type = boost::none;
    return *this;
  }
  /** doc: clear_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_reference_count() throw()
  {
    this->_reference_count = boost::none;
    return *this;
  }
  /** doc: clear_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_preferred_interop_user_sync() throw()
  {
    this->_preferred_interop_user_sync = boost::none;
    return *this;
  }
  /** doc: clear_printf_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_printf_buffer_size() throw()
  {
    this->_printf_buffer_size = boost::none;
    return *this;
  }
  /** doc: clear_image_pitch_alignment() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image_pitch_alignment() throw()
  {
    this->_image_pitch_alignment = boost::none;
    return *this;
  }
  /** doc: clear_image_base_address_alignment() {{{
   * \todo Write documentation
   */ // }}}
  inline Device_Info& clear_image_base_address_alignment() throw()
  {
    this->_image_base_address_alignment = boost::none;
    return *this;
  }
  // }}}
  // presence {{{
  /** doc: has_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_id() const throw()
  {
    return this->_id.is_initialized();
  }
  /** doc: has_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_type() const throw()
  {
    return this->_type.is_initialized();
  }
  /** doc: has_vendor_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_vendor_id() const throw()
  {
    return this->_vendor_id.is_initialized();
  }
  /** doc: has_max_compute_units(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_compute_units() const throw()
  {
    return this->_max_compute_units.is_initialized();
  }
  /** doc: has_max_work_item_dimensions(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_work_item_dimensions() const throw()
  {
    return this->_max_work_item_dimensions.is_initialized();
  }
  /** doc: has_max_work_group_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_work_group_size() const throw()
  {
    return this->_max_work_group_size.is_initialized();
  }
  /** doc: has_max_work_item_sizes(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_work_item_sizes() const throw()
  {
    return this->_max_work_item_sizes.is_initialized();
  }
  /** doc: has_preferred_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_char() const throw()
  {
    return this->_preferred_vector_width_char.is_initialized();
  }
  /** doc: has_preferred_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_short() const throw()
  {
    return this->_preferred_vector_width_short.is_initialized();
  }
  /** doc: has_preferred_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_int() const throw()
  {
    return this->_preferred_vector_width_int.is_initialized();
  }
  /** doc: has_preferred_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_long() const throw()
  {
    return this->_preferred_vector_width_long.is_initialized();
  }
  /** doc: has_preferred_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_float() const throw()
  {
    return this->_preferred_vector_width_float.is_initialized();
  }
  /** doc: has_preferred_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_double() const throw()
  {
    return this->_preferred_vector_width_double.is_initialized();
  }
  /** doc: has_max_clock_frequency(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_clock_frequency() const throw()
  {
    return this->_max_clock_frequency.is_initialized();
  }
  /** doc: has_address_bits(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_address_bits() const throw()
  {
    return this->_address_bits.is_initialized();
  }
  /** doc: has_max_read_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_read_image_args() const throw()
  {
    return this->_max_read_image_args.is_initialized();
  }
  /** doc: has_max_write_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_write_image_args() const throw()
  {
    return this->_max_write_image_args.is_initialized();
  }
  /** doc: has_max_mem_alloc_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_mem_alloc_size() const throw()
  {
    return this->_max_mem_alloc_size.is_initialized();
  }
  /** doc: has_image2d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image2d_max_width() const throw()
  {
    return this->_image2d_max_width.is_initialized();
  }
  /** doc: has_image2d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image2d_max_height() const throw()
  {
    return this->_image2d_max_height.is_initialized();
  }
  /** doc: has_image3d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image3d_max_width() const throw()
  {
    return this->_image3d_max_width.is_initialized();
  }
  /** doc: has_image3d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image3d_max_height() const throw()
  {
    return this->_image3d_max_height.is_initialized();
  }
  /** doc: has_image3d_max_depth(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image3d_max_depth() const throw()
  {
    return this->_image3d_max_depth.is_initialized();
  }
  /** doc: has_image_support(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image_support() const throw()
  {
    return this->_image_support.is_initialized();
  }
  /** doc: has_max_parameter_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_parameter_size() const throw()
  {
    return this->_max_parameter_size.is_initialized();
  }
  /** doc: has_max_samplers(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_samplers() const throw()
  {
    return this->_max_samplers.is_initialized();
  }
  /** doc: has_mem_base_addr_align(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_mem_base_addr_align() const throw()
  {
    return this->_mem_base_addr_align.is_initialized();
  }
  /** doc: has_min_data_type_align_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_min_data_type_align_size() const throw()
  {
    return this->_min_data_type_align_size.is_initialized();
  }
  /** doc: has_single_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_single_fp_config() const throw()
  {
    return this->_single_fp_config.is_initialized();
  }
  /** doc: has_global_mem_cache_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_global_mem_cache_type() const throw()
  {
    return this->_global_mem_cache_type.is_initialized();
  }
  /** doc: has_global_mem_cacheline_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_global_mem_cacheline_size() const throw()
  {
    return this->_global_mem_cacheline_size.is_initialized();
  }
  /** doc: has_global_mem_cache_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_global_mem_cache_size() const throw()
  {
    return this->_global_mem_cache_size.is_initialized();
  }
  /** doc: has_global_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_global_mem_size() const throw()
  {
    return this->_global_mem_size.is_initialized();
  }
  /** doc: has_max_constant_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_constant_buffer_size() const throw()
  {
    return this->_max_constant_buffer_size.is_initialized();
  }
  /** doc: has_max_constant_args(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_max_constant_args() const throw()
  {
    return this->_max_constant_args.is_initialized();
  }
  /** doc: has_local_mem_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_local_mem_type() const throw()
  {
    return this->_local_mem_type.is_initialized();
  }
  /** doc: has_local_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_local_mem_size() const throw()
  {
    return this->_local_mem_size.is_initialized();
  }
  /** doc: has_error_correction_support(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_error_correction_support() const throw()
  {
    return this->_error_correction_support.is_initialized();
  }
  /** doc: has_profiling_timer_resolution(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_profiling_timer_resolution() const throw()
  {
    return this->_profiling_timer_resolution.is_initialized();
  }
  /** doc: has_endian_little(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_endian_little() const throw()
  {
    return this->_endian_little.is_initialized();
  }
  /** doc: has_available(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_available() const throw()
  {
    return this->_available.is_initialized();
  }
  /** doc: has_compiler_available(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_compiler_available() const throw()
  {
    return this->_compiler_available.is_initialized();
  }
  /** doc: has_execution_capabilities(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_execution_capabilities() const throw()
  {
    return this->_execution_capabilities.is_initialized();
  }
  /** doc: has_queue_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_queue_properties() const throw()
  {
    return this->_queue_properties.is_initialized();
  }
  /** doc: has_name(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_name() const throw()
  {
    return this->_name.is_initialized();
  }
  /** doc: has_vendor(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_vendor() const throw()
  {
    return this->_vendor.is_initialized();
  }
  /** doc: has_driver_version(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_driver_version() const throw()
  {
    return this->_driver_version.is_initialized();
  }
  /** doc: has_profile(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_profile() const throw()
  {
    return this->_profile.is_initialized();
  }
  /** doc: has_version(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_version() const throw()
  {
    return this->_version.is_initialized();
  }
  /** doc: has_extensions(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_extensions() const throw()
  {
    return this->_extensions.is_initialized();
  }
  /** doc: has_platform_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_platform_id() const throw()
  {
    return this->_platform_id.is_initialized();
  }
  /** doc: has_double_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_double_fp_config() const throw()
  {
    return this->_double_fp_config.is_initialized();
  }
  /** doc: has_preferred_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_vector_width_half() const throw()
  {
    return this->_preferred_vector_width_half.is_initialized();
  }
  /** doc: has_host_unified_memory(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_host_unified_memory() const throw()
  {
    return this->_host_unified_memory.is_initialized();
  }
  /** doc: has_native_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_char() const throw()
  {
    return this->_native_vector_width_char.is_initialized();
  }
  /** doc: has_native_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_short() const throw()
  {
    return this->_native_vector_width_short.is_initialized();
  }
  /** doc: has_native_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_int() const throw()
  {
    return this->_native_vector_width_int.is_initialized();
  }
  /** doc: has_native_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_long() const throw()
  {
    return this->_native_vector_width_long.is_initialized();
  }
  /** doc: has_native_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_float() const throw()
  {
    return this->_native_vector_width_float.is_initialized();
  }
  /** doc: has_native_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_double() const throw()
  {
    return this->_native_vector_width_double.is_initialized();
  }
  /** doc: has_native_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_native_vector_width_half() const throw()
  {
    return this->_native_vector_width_half.is_initialized();
  }
  /** doc: has_opencl_c_version(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_opencl_c_version() const throw()
  {
    return this->_opencl_c_version.is_initialized();
  }
  /** doc: has_linker_available(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_linker_available() const throw()
  {
    return this->_linker_available.is_initialized();
  }
  /** doc: has_built_in_kernels(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_built_in_kernels() const throw()
  {
    return this->_built_in_kernels.is_initialized();
  }
  /** doc: has_image_max_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image_max_buffer_size() const throw()
  {
    return this->_image_max_buffer_size.is_initialized();
  }
  /** doc: has_image_max_array_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image_max_array_size() const throw()
  {
    return this->_image_max_array_size.is_initialized();
  }
  /** doc: has_parent_device_id(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_parent_device_id() const throw()
  {
    return this->_parent_device_id.is_initialized();
  }
  /** doc: has_partition_max_sub_devices(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_partition_max_sub_devices() const throw()
  {
    return this->_partition_max_sub_devices.is_initialized();
  }
  /** doc: has_partition_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_partition_properties() const throw()
  {
    return this->_partition_properties.is_initialized();
  }
  /** doc: has_partition_affinity_domain(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_partition_affinity_domain() const throw()
  {
    return this->_partition_affinity_domain.is_initialized();
  }
  /** doc: has_partition_type(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_partition_type() const throw()
  {
    return this->_partition_type.is_initialized();
  }
  /** doc: has_reference_count(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_reference_count() const throw()
  {
    return this->_reference_count.is_initialized();
  }
  /** doc: has_preferred_interop_user_sync(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_preferred_interop_user_sync() const throw()
  {
    return this->_preferred_interop_user_sync.is_initialized();
  }
  /** doc: has_printf_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_printf_buffer_size() const throw()
  {
    return this->_printf_buffer_size.is_initialized();
  }
  /** doc: has_image_pitch_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image_pitch_alignment() const throw()
  {
    return this->_image_pitch_alignment.is_initialized();
  }
  /** doc: has_image_base_address_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  inline bool has_image_base_address_alignment() const throw()
  {
    return this->_image_base_address_alignment.is_initialized();
  }
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
  boost::optional<std::vector<size_t>> _max_work_item_sizes;
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
  boost::optional<std::vector<cl_device_partition_property>> _partition_properties;
  boost::optional<cl_device_affinity_domain> _partition_affinity_domain;
  boost::optional<std::vector<cl_device_partition_property>> _partition_type;
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
