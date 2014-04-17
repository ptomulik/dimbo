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

// dimbo/cl/device_info.hpp

/** // doc: dimbo/cl/device_info.hpp {{{
 * \file dimbo/cl/device_info.hpp
 * \todo Refine
 *
 * This module contains class Dimbo::Cl::Device_Info which stores paramteres
 * of an OpenCl device.
 *
 */ // }}}
#ifndef DIMBO_CL_DEVICE_INFO_HPP_INCLUDED
#define DIMBO_CL_DEVICE_INFO_HPP_INCLUDED

#include <dimbo/cl/device.hpp>
#include <dimbo/cl/device_query.hpp>
#ifndef SWIG // FIXME: provide more verbose constant name
# include <boost/serialization/version.hpp>
# include <boost/serialization/access.hpp>
# include <boost/serialization/nvp.hpp>
# include <boost/serialization/vector.hpp>
#endif
#include <dimbo/cl/cl.hpp>
#include <vector>

namespace Dimbo {
namespace Cl {

/** // doc: class Device_Info {{{
 * \ingroup Dimbo_Cl_Platform
 * \class Dimbo::Cl::Device_Info
 * \brief Container for device parameters.
 *
 * This class encapsulates the result of a single query to OpenCL function
 * \c clGetDeviceInfo(). The query is defined by Dimbo::Cl::Device_Query.
 * The Dimbo::Cl::Device_Info may be filled-in with device parameters in
 * several ways. The info may be queried at
 *
 * \todo Refine documentation
 */ // }}}
class Device_Info
{
public:
#ifndef SWIG // FIXME: provide more verbose constant name
  BOOST_STATIC_CONSTANT(unsigned int, class_version = 1);
#endif
public:
  /** // doc: Device_Info() {{{
   * \todo Write documentation
   */ // }}}
  Device_Info();
  /** // doc: Device_Info(...) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info( Device const& device
             , Device_Query const& query = Device_Query());
  /** // doc: ~Device_Info() {{{
   * \todo Write documentation for class Device_Info
   */ // }}}
  virtual ~Device_Info();
  /** // doc: Device_Info(...) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& query( Device const& device
                    , Device_Query const& query = Device_Query());
  /** // doc: Device_Info(...) {{{
   * \todo Write documentation
   */ // }}}
  Device_Info& clear();
  /** // doc: Device_Info(...) {{{
   * \todo Write documentation
   */ // }}}
  Device_Query const& last_query() const
  {
    return this->_last_query;
  }
  // getters {{{
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long id() const
  {
    return this->_id;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_type type() const
  {
    return this->_type;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint vendor_id() const
  {
    return this->_vendor_id;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_compute_units() const
  {
    return this->_max_compute_units;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_work_item_dimensions() const
  {
    return this->_max_work_item_dimensions;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<size_t> max_work_item_sizes() const
  {
    return this->_max_work_item_sizes;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t max_work_group_size() const
  {
    return this->_max_work_group_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_char() const
  {
    return this->_preferred_vector_width_char;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_short() const
  {
    return this->_preferred_vector_width_short;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_int() const
  {
    return this->_preferred_vector_width_int;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_long() const
  {
    return this->_preferred_vector_width_long;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_float() const
  {
    return this->_preferred_vector_width_float;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_double() const
  {
    return this->_preferred_vector_width_double;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_half() const
  {
    return this->_preferred_vector_width_half;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_char() const
  {
    return this->_native_vector_width_char;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_short() const
  {
    return this->_native_vector_width_short;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_int() const
  {
    return this->_native_vector_width_int;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_long() const
  {
    return this->_native_vector_width_long;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_float() const
  {
    return this->_native_vector_width_float;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_double() const
  {
    return this->_native_vector_width_double;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_half() const
  {
    return this->_native_vector_width_half;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_clock_frequency() const
  {
    return this->_max_clock_frequency;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint address_bits() const
  {
    return this->_address_bits;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong max_mem_alloc_size() const
  {
    return this->_max_mem_alloc_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool image_support() const
  {
    return this->_image_support;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_read_image_args() const
  {
    return this->_max_read_image_args;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_write_image_args() const
  {
    return this->_max_write_image_args;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image2d_max_width() const
  {
    return this->_image2d_max_width;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image2d_max_height() const
  {
    return this->_image2d_max_height;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_width() const
  {
    return this->_image3d_max_width;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_height() const
  {
    return this->_image3d_max_height;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_depth() const
  {
    return this->_image3d_max_depth;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_samplers() const
  {
    return this->_max_samplers;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t max_parameter_size() const
  {
    return this->_max_parameter_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint mem_base_addr_align() const
  {
    return this->_mem_base_addr_align;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint min_data_type_align_size() const
  {
    return this->_min_data_type_align_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_fp_config single_fp_config() const
  {
    return this->_single_fp_config;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_mem_cache_type global_mem_cache_type() const
  {
    return this->_global_mem_cache_type;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint global_mem_cacheline_size() const
  {
    return this->_global_mem_cacheline_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong global_mem_cache_size() const
  {
    return this->_global_mem_cache_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong global_mem_size() const
  {
    return this->_global_mem_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_constant_args() const
  {
    return this->_max_constant_args;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_local_mem_type local_mem_type() const
  {
    return this->_local_mem_type;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong local_mem_size() const
  {
    return this->_local_mem_size;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool error_correction_support() const
  {
    return this->_error_correction_support;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool host_unified_memory() const
  {
    return this->_host_unified_memory;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t profiling_timer_resolution() const
  {
    return this->_profiling_timer_resolution;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool endian_little() const
  {
    return this->_endian_little;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool available() const
  {
    return this->_available;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool compiler_available() const
  {
    return this->_compiler_available;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_device_exec_capabilities execution_capabilities() const
  {
    return this->_execution_capabilities;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_command_queue_properties queue_properties() const
  {
    return this->_queue_properties;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long platform_id() const
  {
    return this->_platform_id;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& name() const
  {
    return this->_name;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& vendor() const
  {
    return this->_vendor;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& driver_version() const
  {
    return this->_driver_version;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& profile() const
  {
    return this->_profile;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& version() const
  {
    return this->_version;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& opencl_c_version() const
  {
    return this->_opencl_c_version;
  }
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& extensions() const
  {
    return this->_extensions;
  }
  // }}}
private:
#ifndef SWIG // FIXME: provide more verbose constant name
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int /* version */)
  {
    // {{{
    using boost::serialization::make_nvp;
    ar & make_nvp("last_query", _last_query);
    // FIXME: cl_platform_id is a pointer to incomplete type
    //        must workaround it somehow
    //ar & make_nvp("id", _id);
    ar & make_nvp("type", _type);
    ar & make_nvp("vendor_id", _vendor_id);
    ar & make_nvp("max_compute_units", _max_compute_units);
    ar & make_nvp("max_work_item_dimensions", _max_work_item_dimensions);
    ar & make_nvp("max_work_item_sizes", _max_work_item_sizes);
    ar & make_nvp("max_work_group_size", _max_work_group_size);
    ar & make_nvp("preferred_vector_width_char", _preferred_vector_width_char);
    ar & make_nvp("preferred_vector_width_short", _preferred_vector_width_short);
    ar & make_nvp("preferred_vector_width_int", _preferred_vector_width_int);
    ar & make_nvp("preferred_vector_width_long", _preferred_vector_width_long);
    ar & make_nvp("preferred_vector_width_float", _preferred_vector_width_float);
    ar & make_nvp("preferred_vector_width_double", _preferred_vector_width_double);
    ar & make_nvp("preferred_vector_width_half", _preferred_vector_width_half);
    ar & make_nvp("native_vector_width_char", _native_vector_width_char);
    ar & make_nvp("native_vector_width_short", _native_vector_width_short);
    ar & make_nvp("native_vector_width_int", _native_vector_width_int);
    ar & make_nvp("native_vector_width_long", _native_vector_width_long);
    ar & make_nvp("native_vector_width_float", _native_vector_width_float);
    ar & make_nvp("native_vector_width_double", _native_vector_width_double);
    ar & make_nvp("native_vector_width_half", _native_vector_width_half);
    ar & make_nvp("max_clock_frequency", _max_clock_frequency);
    ar & make_nvp("address_bits", _address_bits);
    ar & make_nvp("max_mem_alloc_size", _max_mem_alloc_size);
    ar & make_nvp("image_support", _image_support);
    ar & make_nvp("max_read_image_args", _max_read_image_args);
    ar & make_nvp("max_write_image_args", _max_write_image_args);
    ar & make_nvp("image2d_max_width", _image2d_max_width);
    ar & make_nvp("image2d_max_height", _image2d_max_height);
    ar & make_nvp("image3d_max_width", _image3d_max_width);
    ar & make_nvp("image3d_max_height", _image3d_max_height);
    ar & make_nvp("image3d_max_depth", _image3d_max_depth);
    ar & make_nvp("max_samplers", _max_samplers);
    ar & make_nvp("max_parameter_size", _max_parameter_size);
    ar & make_nvp("mem_base_addr_align", _mem_base_addr_align);
    ar & make_nvp("min_data_type_align_size", _min_data_type_align_size);
    ar & make_nvp("single_fp_config", _single_fp_config);
    ar & make_nvp("global_mem_cache_type", _global_mem_cache_type);
    ar & make_nvp("global_mem_cacheline_size", _global_mem_cacheline_size);
    ar & make_nvp("global_mem_cache_size", _global_mem_cache_size);
    ar & make_nvp("global_mem_size", _global_mem_size);
    ar & make_nvp("max_constant_args", _max_constant_args);
    ar & make_nvp("local_mem_type", _local_mem_type);
    ar & make_nvp("local_mem_size", _local_mem_size);
    ar & make_nvp("error_correction_support", _error_correction_support);
    ar & make_nvp("host_unified_memory", _host_unified_memory);
    ar & make_nvp("profiling_timer_resolution", _profiling_timer_resolution);
    ar & make_nvp("endian_little", _endian_little);
    ar & make_nvp("available", _available);
    ar & make_nvp("compiler_available", _compiler_available);
    ar & make_nvp("execution_capabilities", _execution_capabilities);
    ar & make_nvp("queue_properties", _queue_properties);
    // FIXME: cl_platform_id is a pointer to incomplete type
    //        must workaround it somehow
    //ar & make_nvp("platform_id", _platform_id);
    ar & make_nvp("name", _name);
    ar & make_nvp("vendor", _vendor);
    ar & make_nvp("driver_version", _driver_version);
    ar & make_nvp("profile", _profile);
    ar & make_nvp("version", _version);
    ar & make_nvp("opencl_c_version", _opencl_c_version);
    ar & make_nvp("extensions", _extensions);
    // }}}
  }
#endif
private:
  void _init_device_info();
  Device_Query _last_query;
  // attrbutes {{{
  unsigned long _id;
  cl_device_type _type;
  cl_uint _vendor_id;
  cl_uint _max_compute_units;
  cl_uint _max_work_item_dimensions;
  std::vector<size_t> _max_work_item_sizes;
  size_t _max_work_group_size;
  cl_uint _preferred_vector_width_char;
  cl_uint _preferred_vector_width_short;
  cl_uint _preferred_vector_width_int;
  cl_uint _preferred_vector_width_long;
  cl_uint _preferred_vector_width_float;
  cl_uint _preferred_vector_width_double;
  cl_uint _preferred_vector_width_half;
  cl_uint _native_vector_width_char;
  cl_uint _native_vector_width_short;
  cl_uint _native_vector_width_int;
  cl_uint _native_vector_width_long;
  cl_uint _native_vector_width_float;
  cl_uint _native_vector_width_double;
  cl_uint _native_vector_width_half;
  cl_uint _max_clock_frequency;
  cl_uint _address_bits;
  cl_ulong _max_mem_alloc_size;
  cl_bool _image_support;
  cl_uint _max_read_image_args;
  cl_uint _max_write_image_args;
  size_t _image2d_max_width;
  size_t _image2d_max_height;
  size_t _image3d_max_width;
  size_t _image3d_max_height;
  size_t _image3d_max_depth;
  cl_uint _max_samplers;
  size_t _max_parameter_size;
  cl_uint _mem_base_addr_align;
  cl_uint _min_data_type_align_size;
  cl_device_fp_config _single_fp_config;
  cl_device_mem_cache_type _global_mem_cache_type;
  cl_uint _global_mem_cacheline_size;
  cl_ulong _global_mem_cache_size;
  cl_ulong _global_mem_size;
  cl_uint _max_constant_args;
  cl_device_local_mem_type _local_mem_type;
  cl_ulong _local_mem_size;
  cl_bool _error_correction_support;
  cl_bool _host_unified_memory;
  size_t _profiling_timer_resolution;
  cl_bool _endian_little;
  cl_bool _available;
  cl_bool _compiler_available;
  cl_device_exec_capabilities _execution_capabilities;
  cl_command_queue_properties _queue_properties;
  unsigned long _platform_id;
  std::string  _name;
  std::string  _vendor;
  std::string  _driver_version;
  std::string  _profile;
  std::string  _version;
  std::string  _opencl_c_version;
  std::string  _extensions;
  // }}}
};

} /* namespace Cl */
} /* namespace Dimbo */


#ifndef SWIG // FIXME: provide more verbose constant name
BOOST_CLASS_VERSION( Dimbo::Cl::Device_Info
                   , Dimbo::Cl::Device_Info::class_version )
#endif

#endif /* DIMBO_CL_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
