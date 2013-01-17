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

// dimbo/format/cl/device_info_impl.hpp

#ifndef DIMBO_FORMAT_CL_DEVICE_INFO_IMPL
#define DIMBO_FORMAT_CL_DEVICE_INFO_IMPL

/** // doc: dimbo/format/cl/device_info_impl.hpp {{{
 * @file dimbo/format/cl/device_info_impl.hpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/format/cl/device_info.hpp>
#include <dimbo/format/autosep.hpp>
#include <ostream>
#include <vector>
#include <string>
#include <sstream>

template<typename T>
struct Bit 
{
  const char* name;
  T value;
};

template<typename T>
struct Const 
{
  const char* name;
  T value;
};


// local implementation of << operator for vectors (we have one here)
template<class Ostream, typename T> static Ostream&
operator << (Ostream& os, std::vector<T> const& v)
{
  typedef typename std::vector<T>::const_iterator iterator;
  iterator cur(v.begin());
  iterator end(v.end());
  Dimbo::Format::Autosep<const char*> as(",");
  while(cur != end)
    os << as << *cur++;
  return os;
}

template<class Ostream, typename T1, typename T2, int N> static Ostream&
write_bits(Ostream& os, const Bit<T1> (&nvp)[N], T2 value)
{
  Dimbo::Format::Autosep<const char*> as(",");
  for(int i=0; i < N; ++i) {
    if(value & nvp[i].value)
      os << as << nvp[i].name;
  }
  return os;
}

template<class Ostream, typename T1, typename T2, int N> static Ostream&
write_constant(Ostream& os, const Const<T1> (&nvp)[N], T2 value)
{
  for(int i=0; i<N; ++i) {
    if(value == nvp[i].value) {
      os << nvp[i].name;
      return os;
    }
  }
  os << "Unknown";
  return os;
}

template<class Ostream> static Ostream&
write_bool(Ostream& os, cl_bool value)
{
  return (os << (value ? "Yes" : "No"));
}

template<class Ostream, typename T> static Ostream&
write_hex(Ostream& os, T const& x)
{
  std::ostringstream oss;
  oss << "0x" << std::hex << x;
  return (os << oss.str());
}

template<class Ostream> static Ostream&
write_id(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_hex(os, dev.id());
}

template<class Ostream> static Ostream&
write_type(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  static const Bit<cl_device_type> nvp[4] = 
    {
      {"CPU", CL_DEVICE_TYPE_CPU}
    , {"GPU", CL_DEVICE_TYPE_GPU}
    , {"Acceerator", CL_DEVICE_TYPE_ACCELERATOR}
    , {"Default", CL_DEVICE_TYPE_DEFAULT}
    };
  return write_bits(os, nvp, dev.type());
}
template<class Ostream> static Ostream&
write_vendor_id(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_hex(os, dev.vendor_id());
}
template<class Ostream> static Ostream&
write_max_compute_units(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_compute_units());
}
template<class Ostream> static Ostream&
write_max_work_item_dimensions(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_work_item_dimensions());
}
template<class Ostream> static Ostream&
write_max_work_item_sizes(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_work_item_sizes());
}
template<class Ostream> static Ostream&
write_max_work_group_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_work_group_size());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_char(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_char());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_short(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_short());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_int(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_int());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_long(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_long());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_float(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_float());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_double(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_double());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_half(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_half());
}
template<class Ostream> static Ostream&
write_native_vector_width_char(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_char());
}
template<class Ostream> static Ostream&
write_native_vector_width_short(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_short());
}
template<class Ostream> static Ostream&
write_native_vector_width_int(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_int());
}
template<class Ostream> static Ostream&
write_native_vector_width_long(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_long());
}
template<class Ostream> static Ostream&
write_native_vector_width_float(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_float());
}
template<class Ostream> static Ostream&
write_native_vector_width_double(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_double());
}
template<class Ostream> static Ostream&
write_native_vector_width_half(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.native_vector_width_half());
}
template<class Ostream> static Ostream&
write_max_clock_frequency(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_clock_frequency() << " MHz");
}
template<class Ostream> static Ostream&
write_address_bits(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.address_bits());
}
template<class Ostream> static Ostream&
write_max_mem_alloc_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_mem_alloc_size());
}
template<class Ostream> static Ostream&
write_image_support(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_bool(os, dev.image_support());
}
template<class Ostream> static Ostream&
write_max_read_image_args(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_read_image_args());
}
template<class Ostream> static Ostream&
write_max_write_image_args(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_write_image_args());
}
template<class Ostream> static Ostream&
write_image2d_max_width(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.image2d_max_width());
}
template<class Ostream> static Ostream&
write_image2d_max_height(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.image2d_max_height());
}
template<class Ostream> static Ostream&
write_image3d_max_width(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.image3d_max_width());
}
template<class Ostream> static Ostream&
write_image3d_max_height(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.image3d_max_height());
}
template<class Ostream> static Ostream&
write_image3d_max_depth(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.image3d_max_depth());
}
template<class Ostream> static Ostream&
write_max_samplers(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_samplers());
}
template<class Ostream> static Ostream&
write_max_parameter_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_parameter_size());
}
template<class Ostream> static Ostream&
write_mem_base_addr_align(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.mem_base_addr_align());
}
template<class Ostream> static Ostream&
write_min_data_type_align_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.min_data_type_align_size());
}
template<class Ostream> static Ostream&
write_single_fp_config(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  static const Bit<cl_device_fp_config> nvp[7] = 
    {
      {"Denorm", CL_FP_DENORM},
      {"Inf & Quiet NaN", CL_FP_INF_NAN},
      {"Round to Nearest Even", CL_FP_ROUND_TO_NEAREST},
      {"Round to Zero", CL_FP_ROUND_TO_ZERO},
      {"Round to Inf", CL_FP_ROUND_TO_INF},
      {"FMA", CL_FP_FMA},
      {"Soft Float", CL_FP_SOFT_FLOAT}
    };
  return write_bits(os, nvp, dev.single_fp_config());
}
template<class Ostream> static Ostream&
write_global_mem_cache_type(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  static const Const<cl_device_mem_cache_type> nvp[3] = 
    {
      {"None", CL_NONE},
      {"Read Only", CL_READ_ONLY_CACHE},
      {"Read Write", CL_READ_WRITE_CACHE}
    };
  return write_constant(os, nvp, dev.global_mem_cache_type());
}
template<class Ostream> static Ostream&
write_global_mem_cacheline_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.global_mem_cacheline_size());
}
template<class Ostream> static Ostream&
write_global_mem_cache_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.global_mem_cache_size());
}
template<class Ostream> static Ostream&
write_global_mem_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.global_mem_size());
}
template<class Ostream> static Ostream&
write_max_constant_args(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.max_constant_args());
}
template<class Ostream> static Ostream&
write_local_mem_type(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  static const Const<cl_device_local_mem_type> nvp[2] = 
    {
      {"Dedicated", CL_LOCAL},
      {"Global", CL_GLOBAL}
    };
  return write_constant(os, nvp, dev.local_mem_type());
}
template<class Ostream> static Ostream&
write_local_mem_size(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.local_mem_size());
}
template<class Ostream> static Ostream&
write_error_correction_support(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_bool(os, dev.error_correction_support());
}
template<class Ostream> static Ostream&
write_host_unified_memory(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_bool(os, dev.host_unified_memory());
}
template<class Ostream> static Ostream&
write_profiling_timer_resolution(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.profiling_timer_resolution());
}
template<class Ostream> static Ostream&
write_endian_little(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_bool(os, dev.endian_little());
}
template<class Ostream> static Ostream&
write_available(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_bool(os, dev.available());
}
template<class Ostream> static Ostream&
write_compiler_available(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_bool(os, dev.compiler_available());
}
template<class Ostream> static Ostream&
write_execution_capabilities(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  static const Bit<cl_device_exec_capabilities> nvp[2] = 
    {
      {"OpenCL Kernel", CL_EXEC_KERNEL},
      {"Native Kernel", CL_EXEC_NATIVE_KERNEL}
    };
  return write_bits(os, nvp, dev.execution_capabilities());
}
template<class Ostream> static Ostream&
write_queue_properties(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  static const Bit<cl_command_queue_properties> nvp[2] = 
    {
      {"Out of Order Exec", CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE},
      {"Queue Profiling", CL_QUEUE_PROFILING_ENABLE}
    };
  return write_bits(os, nvp, dev.queue_properties());
}
template<class Ostream> static Ostream&
write_platform_id(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write_hex(os, dev.platform_id());
}
template<class Ostream> static Ostream&
write_name(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.name());
}
template<class Ostream> static Ostream&
write_vendor(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.vendor());
}
template<class Ostream> static Ostream&
write_driver_version(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.driver_version());
}
template<class Ostream> static Ostream&
write_profile(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.profile());
}
template<class Ostream> static Ostream&
write_version(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.version());
}
template<class Ostream> static Ostream&
write_opencl_c_version(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.opencl_c_version());
}
template<class Ostream> static Ostream&
write_extensions(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return (os << dev.extensions());
}

namespace Dimbo {
namespace Format {

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Cl::Device_Info const& dev, int ind)
{
  Dimbo::Cl::Device_Query const& query = dev.last_query();
  Autosep<const char*> as("\n");
  std::string pre(ind, ' ');

  if(query.id_selected()) {
    os << as << pre << "Id (within current process) ..: ";
    write_id(os, dev);
  }
  if(query.type_selected()) {
    os << as << pre << "Type .........................: ";
    write_type(os, dev);
  }
  if(query.vendor_id_selected()) {
    os << as << pre << "Vendor Id ....................: ";
    write_vendor_id(os, dev);
  }
  if(query.max_compute_units_selected()) {
    os << as << pre << "Max Compute Units ............: ";
    write_max_compute_units(os, dev);
  }
  if(query.max_work_item_dimensions_selected()) {
    os << as << pre << "Max Work Item Dimensions .....: ";
    write_max_work_item_dimensions(os, dev);
  }
  if(query.max_work_item_sizes_selected()) {
    os << as << pre << "Max Work Item Sizes ..........: ";
    write_max_work_item_sizes(os, dev);
  }
  if(query.max_work_group_size_selected()) {
    os << as << pre << "Max Work Group Size ..........: ";
    write_max_work_group_size(os, dev);
  }
  if(query.preferred_vector_width_char_selected()) {
    os << as << pre << "Preferred Vector Width Char ..: ";
    write_preferred_vector_width_char(os, dev);
  }
  if(query.preferred_vector_width_short_selected()) {
    os << as << pre << "Preferred Vector Width Short .: ";
    write_preferred_vector_width_short(os, dev);
  }
  if(query.preferred_vector_width_int_selected()) {
    os << as << pre << "Preferred Vector Width Int ...: ";
    write_preferred_vector_width_int(os, dev);
  }
  if(query.preferred_vector_width_long_selected()) {
    os << as << pre << "Preferred Vector Width Long ..: ";
    write_preferred_vector_width_long(os, dev);
  }
  if(query.preferred_vector_width_float_selected()) {
    os << as << pre << "Preferred Vector Width Float .: ";
    write_preferred_vector_width_float(os, dev);
  }
  if(query.preferred_vector_width_double_selected()) {
    os << as << pre << "Preferred Vector Width Double : ";
    write_preferred_vector_width_double(os, dev);
  }
  if(query.preferred_vector_width_half_selected()) {
    os << as << pre << "Preferred Vector Width Half ..: ";
    write_preferred_vector_width_half(os, dev);
  }
  if(query.native_vector_width_char_selected()) {
    os << as << pre << "Native Vector Width Char .....: ";
    write_native_vector_width_char(os, dev);
  }
  if(query.native_vector_width_short_selected()) {
    os << as << pre << "Native Vector Width Short ....: ";
    write_native_vector_width_short(os, dev);
  }
  if(query.native_vector_width_int_selected()) {
    os << as << pre << "Native Vector Width Int ......: ";
    write_native_vector_width_int(os, dev);
  }
  if(query.native_vector_width_long_selected()) {
    os << as << pre << "Native Vector Width Long .....: ";
    write_native_vector_width_long(os, dev);
  }
  if(query.native_vector_width_float_selected()) {
    os << as << pre << "Native Vector Width Float ....: ";
    write_native_vector_width_float(os, dev);
  }
  if(query.native_vector_width_double_selected()) {
    os << as << pre << "Native Vector Width Double ...: ";
    write_native_vector_width_double(os, dev);
  }
  if(query.native_vector_width_half_selected()) {
    os << as << pre << "Native Vector Width Half .....: ";
    write_native_vector_width_half(os, dev);
  }
  if(query.max_clock_frequency_selected()) {
    os << as << pre << "Max Clock Frequency ..........: ";
    write_max_clock_frequency(os, dev);
  }
  if(query.address_bits_selected()) {
    os << as << pre << "Address Bits .................: ";
    write_address_bits(os, dev);
  }
  if(query.max_mem_alloc_size_selected()) {
    os << as << pre << "Max Mem Alloc Size ...........: ";
    write_max_mem_alloc_size(os, dev);
  }
  if(query.image_support_selected()) {
    os << as << pre << "Image Support ................: ";
    write_image_support(os, dev);
  }
  if(query.max_read_image_args_selected()) {
    os << as << pre << "Max Read Image Args ..........: ";
    write_max_read_image_args(os, dev);
  }
  if(query.max_write_image_args_selected()) {
    os << as << pre << "Max Write Image Args .........: ";
    write_max_write_image_args(os, dev);
  }
  if(query.image2d_max_width_selected()) {
    os << as << pre << "Image2d Max Width ............: ";
    write_image2d_max_width(os, dev);
  }
  if(query.image2d_max_height_selected()) {
    os << as << pre << "Image2d Max Height ...........: ";
    write_image2d_max_height(os, dev);
  }
  if(query.image3d_max_width_selected()) {
    os << as << pre << "Image3d Max Width ............: ";
    write_image3d_max_width(os, dev);
  }
  if(query.image3d_max_height_selected()) {
    os << as << pre << "Image3d Max Height ...........: ";
    write_image3d_max_height(os, dev);
  }
  if(query.image3d_max_depth_selected()) {
    os << as << pre << "Image3d Max Depth ............: ";
    write_image3d_max_depth(os, dev);
  }
  if(query.max_samplers_selected()) {
    os << as << pre << "Max Samplers .................: ";
    write_max_samplers(os, dev);
  }
  if(query.max_parameter_size_selected()) {
    os << as << pre << "Max Parameter Size ...........: ";
    write_max_parameter_size(os, dev);
  }
  if(query.mem_base_addr_align_selected()) {
    os << as << pre << "Mem Base Addr Align ..........: ";
    write_mem_base_addr_align(os, dev);
  }
  if(query.min_data_type_align_size_selected()) {
    os << as << pre << "Min Data Type Align Size .....: ";
    write_min_data_type_align_size(os, dev);
  }
  if(query.single_fp_config_selected()) {
    os << as << pre << "Single Prec. Floating Pt Caps : ";
    write_single_fp_config(os, dev);
  }
  if(query.global_mem_cache_type_selected()) {
    os << as << pre << "Global Mem Cache Type ........: ";
    write_global_mem_cache_type(os, dev);
  }
  if(query.global_mem_cacheline_size_selected()) {
    os << as << pre << "Global Mem Cacheline Size ....: ";
    write_global_mem_cacheline_size(os, dev);
  }
  if(query.global_mem_cache_size_selected()) {
    os << as << pre << "Global Mem Cache Size ........: ";
    write_global_mem_cache_size(os, dev);
  }
  if(query.global_mem_size_selected()) {
    os << as << pre << "Global Mem Size ..............: ";
    write_global_mem_size(os, dev);
  }
  if(query.max_constant_args_selected()) {
    os << as << pre << "Max Constant Args ............: ";
    write_max_constant_args(os, dev);
  }
  if(query.local_mem_type_selected()) {
    os << as << pre << "Local Mem Type ...............: ";
    write_local_mem_type(os, dev);
  }
  if(query.local_mem_size_selected()) {
    os << as << pre << "Local Mem Size ...............: ";
    write_local_mem_size(os, dev);
  }
  if(query.error_correction_support_selected()) {
    os << as << pre << "Error Correction Support .....: ";
    write_error_correction_support(os, dev);
  }
  if(query.host_unified_memory_selected()) {
    os << as << pre << "Host Unified Memory ..........: ";
    write_host_unified_memory(os, dev);
  }
  if(query.profiling_timer_resolution_selected()) {
    os << as << pre << "Profiling Timer Resolution ...: ";
    write_profiling_timer_resolution(os, dev);
  }
  if(query.endian_little_selected()) {
    os << as << pre << "Endian Little ................: ";
    write_endian_little(os, dev);
  }
  if(query.available_selected()) {
    os << as << pre << "Available ....................: ";
    write_available(os, dev);
  }
  if(query.compiler_available_selected()) {
    os << as << pre << "Compiler Available ...........: ";
    write_compiler_available(os, dev);
  }
  if(query.execution_capabilities_selected()) {
    os << as << pre << "Execution Capabilities .......: ";
    write_execution_capabilities(os, dev);
  }
  if(query.queue_properties_selected()) {
    os << as << pre << "Queue Properties .............: ";
    write_queue_properties(os, dev);
  }
  if(query.platform_id_selected()) {
    os << as << pre << "Platform Id (current process).: ";
    write_platform_id(os, dev);
  }
  if(query.name_selected()) {
    os << as << pre << "Name .........................: ";
    write_name(os, dev);
  }
  if(query.vendor_selected()) {
    os << as << pre << "Vendor .......................: ";
    write_vendor(os, dev);
  }
  if(query.driver_version_selected()) {
    os << as << pre << "Driver Version ...............: ";
    write_driver_version(os, dev);
  }
  if(query.profile_selected()) {
    os << as << pre << "Profile ......................: ";
    write_profile(os, dev);
  }
  if(query.version_selected()) {
    os << as << pre << "Version ......................: ";
    write_version(os, dev);
  }
  if(query.opencl_c_version_selected()) {
    os << as << pre << "Opencl C Version .............: ";
    write_opencl_c_version(os, dev);
  }
  if(query.extensions_selected()) {
    os << as << pre << "Extensions ...................: ";
    write_extensions(os, dev);
  }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Cl::Device_Info const& dev)
{
  return write(os, dev, 0);
}

} /* namespace Format */
} /* namespace Dimbo */

#endif /* DIMBO_FORMAT_CL_DEVICE_INFO_IMPL */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
