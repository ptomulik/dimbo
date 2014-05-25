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

// dimbo/format/clinfo/device_info_impl.hpp

#ifndef DIMBO_FORMAT_CLINFO_DEVICE_INFO_IMPL
#define DIMBO_FORMAT_CLINFO_DEVICE_INFO_IMPL

/** // doc: dimbo/format/clinfo/device_info_impl.hpp {{{
 * @file dimbo/format/clinfo/device_info_impl.hpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/format/clinfo/device_info.hpp>
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
write_id(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_hex(os, dev.id());
}

template<class Ostream> static Ostream&
write_type(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
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
write_vendor_id(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_hex(os, dev.vendor_id());
}
template<class Ostream> static Ostream&
write_max_compute_units(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_compute_units());
}
template<class Ostream> static Ostream&
write_max_work_item_dimensions(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_work_item_dimensions());
}
template<class Ostream> static Ostream&
write_max_work_item_sizes(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_work_item_sizes());
}
template<class Ostream> static Ostream&
write_max_work_group_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_work_group_size());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_char(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_char());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_short(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_short());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_int(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_int());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_long(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_long());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_float(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_float());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_double(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_double());
}
template<class Ostream> static Ostream&
write_preferred_vector_width_half(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_vector_width_half());
}
template<class Ostream> static Ostream&
write_native_vector_width_char(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_char());
}
template<class Ostream> static Ostream&
write_native_vector_width_short(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_short());
}
template<class Ostream> static Ostream&
write_native_vector_width_int(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_int());
}
template<class Ostream> static Ostream&
write_native_vector_width_long(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_long());
}
template<class Ostream> static Ostream&
write_native_vector_width_float(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_float());
}
template<class Ostream> static Ostream&
write_native_vector_width_double(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_double());
}
template<class Ostream> static Ostream&
write_native_vector_width_half(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.native_vector_width_half());
}
template<class Ostream> static Ostream&
write_max_clock_frequency(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_clock_frequency() << " MHz");
}
template<class Ostream> static Ostream&
write_address_bits(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.address_bits());
}
template<class Ostream> static Ostream&
write_max_mem_alloc_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_mem_alloc_size());
}
template<class Ostream> static Ostream&
write_image_support(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.image_support());
}
template<class Ostream> static Ostream&
write_max_read_image_args(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_read_image_args());
}
template<class Ostream> static Ostream&
write_max_write_image_args(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_write_image_args());
}
template<class Ostream> static Ostream&
write_image2d_max_width(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image2d_max_width());
}
template<class Ostream> static Ostream&
write_image2d_max_height(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image2d_max_height());
}
template<class Ostream> static Ostream&
write_image3d_max_width(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image3d_max_width());
}
template<class Ostream> static Ostream&
write_image3d_max_height(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image3d_max_height());
}
template<class Ostream> static Ostream&
write_image3d_max_depth(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image3d_max_depth());
}
template<class Ostream> static Ostream&
write_image_max_buffer_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image_max_buffer_size());
}
template<class Ostream> static Ostream&
write_image_max_array_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image_max_array_size());
}
template<class Ostream> static Ostream&
write_max_samplers(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_samplers());
}
template<class Ostream> static Ostream&
write_max_parameter_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_parameter_size());
}
template<class Ostream> static Ostream&
write_mem_base_addr_align(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.mem_base_addr_align());
}
template<class Ostream> static Ostream&
write_min_data_type_align_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.min_data_type_align_size());
}
template<class Ostream> static Ostream&
write_single_fp_config(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  static const Bit<cl_device_fp_config> nvp[8] =
    {
      {"Denorm", CL_FP_DENORM},
      {"Inf & Quiet NaN", CL_FP_INF_NAN},
      {"Round to Nearest Even", CL_FP_ROUND_TO_NEAREST},
      {"Round to Zero", CL_FP_ROUND_TO_ZERO},
      {"Round to Inf", CL_FP_ROUND_TO_INF},
      {"FMA", CL_FP_FMA},
      {"Soft Float", CL_FP_SOFT_FLOAT},
      {"Correctly Rounded Divide SQRT", CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT}
    };
  return write_bits(os, nvp, dev.single_fp_config());
}
template<class Ostream> static Ostream&
write_double_fp_config(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  static const Bit<cl_device_fp_config> nvp[8] =
    {
      {"Denorm", CL_FP_DENORM},
      {"Inf & Quiet NaN", CL_FP_INF_NAN},
      {"Round to Nearest Even", CL_FP_ROUND_TO_NEAREST},
      {"Round to Zero", CL_FP_ROUND_TO_ZERO},
      {"Round to Inf", CL_FP_ROUND_TO_INF},
      {"FMA", CL_FP_FMA},
      {"Soft Float", CL_FP_SOFT_FLOAT},
      {"Correctly Rounded Divide SQRT", CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT}
    };
  return write_bits(os, nvp, dev.double_fp_config());
}
template<class Ostream> static Ostream&
write_global_mem_cache_type(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
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
write_global_mem_cacheline_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.global_mem_cacheline_size());
}
template<class Ostream> static Ostream&
write_global_mem_cache_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.global_mem_cache_size());
}
template<class Ostream> static Ostream&
write_global_mem_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.global_mem_size());
}
template<class Ostream> static Ostream&
write_max_constant_buffer_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_constant_buffer_size());
}
template<class Ostream> static Ostream&
write_max_constant_args(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.max_constant_args());
}
template<class Ostream> static Ostream&
write_local_mem_type(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  static const Const<cl_device_local_mem_type> nvp[2] =
    {
      {"Dedicated", CL_LOCAL},
      {"Global", CL_GLOBAL}
    };
  return write_constant(os, nvp, dev.local_mem_type());
}
template<class Ostream> static Ostream&
write_local_mem_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.local_mem_size());
}
template<class Ostream> static Ostream&
write_error_correction_support(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.error_correction_support());
}
template<class Ostream> static Ostream&
write_host_unified_memory(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.host_unified_memory());
}
template<class Ostream> static Ostream&
write_profiling_timer_resolution(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.profiling_timer_resolution());
}
template<class Ostream> static Ostream&
write_endian_little(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.endian_little());
}
template<class Ostream> static Ostream&
write_available(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.available());
}
template<class Ostream> static Ostream&
write_compiler_available(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.compiler_available());
}
template<class Ostream> static Ostream&
write_linker_available(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_bool(os, dev.linker_available());
}
template<class Ostream> static Ostream&
write_execution_capabilities(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  static const Bit<cl_device_exec_capabilities> nvp[2] =
    {
      {"OpenCL Kernel", CL_EXEC_KERNEL},
      {"Native Kernel", CL_EXEC_NATIVE_KERNEL}
    };
  return write_bits(os, nvp, dev.execution_capabilities());
}
template<class Ostream> static Ostream&
write_queue_properties(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  static const Bit<cl_command_queue_properties> nvp[2] =
    {
      {"Out of Order Exec", CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE},
      {"Queue Profiling", CL_QUEUE_PROFILING_ENABLE}
    };
  return write_bits(os, nvp, dev.queue_properties());
}
template<class Ostream> static Ostream&
write_platform_id(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write_hex(os, dev.platform_id());
}
template<class Ostream> static Ostream&
write_name(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.name());
}
template<class Ostream> static Ostream&
write_vendor(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.vendor());
}
template<class Ostream> static Ostream&
write_driver_version(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.driver_version());
}
template<class Ostream> static Ostream&
write_profile(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.profile());
}
template<class Ostream> static Ostream&
write_version(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.version());
}
template<class Ostream> static Ostream&
write_opencl_c_version(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.opencl_c_version());
}
template<class Ostream> static Ostream&
write_extensions(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.extensions());
}
template<class Ostream> static Ostream&
write_built_in_kernels(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.built_in_kernels());
}
template<class Ostream> static Ostream&
write_parent_device_id(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.parent_device_id());
}
template<class Ostream> static Ostream&
write_partition_max_sub_devices(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.partition_max_sub_devices());
}
template<class Ostream> static Ostream&
write_partition_properties(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  // FIXME: this is not ideal, we should print symbolic names, not numbers here
  return (os << dev.partition_properties());
}
template<class Ostream> static Ostream&
write_partition_affinity_domain(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  static const Bit<cl_device_affinity_domain> nvp[6] =
    {
      {"Numa", CL_DEVICE_AFFINITY_DOMAIN_NUMA},
      {"L4 Cache", CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE},
      {"L3 Cache", CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE},
      {"L2 Cache", CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE},
      {"L1 Cache", CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE},
      {"Next Partitionable", CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE},
    };
  return write_bits(os, nvp, dev.partition_affinity_domain());
}
template<class Ostream> static Ostream&
write_partition_type(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  // FIXME: this is not ideal, we should print symbolic names, not numbers here
  return (os << dev.partition_type());
}
template<class Ostream> static Ostream&
write_reference_count(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.reference_count());
}
template<class Ostream> static Ostream&
write_preferred_interop_user_sync(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.preferred_interop_user_sync());
}
template<class Ostream> static Ostream&
write_printf_buffer_size(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.printf_buffer_size());
}
template<class Ostream> static Ostream&
write_image_pitch_alignment(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image_pitch_alignment());
}
template<class Ostream> static Ostream&
write_image_base_address_alignment(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return (os << dev.image_base_address_alignment());
}

namespace Dimbo {
namespace Format {

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Clinfo::Device_Info const& info, int ind)
{
  Autosep<const char*> as("\n");
  std::string pre(ind, ' ');

  if(info.has_id()) {
    os << as << pre << "Id (within current process) ..: ";
    write_id(os, info);
  }
  if(info.has_type()) {
    os << as << pre << "Type .........................: ";
    write_type(os, info);
  }
  if(info.has_vendor_id()) {
    os << as << pre << "Vendor Id ....................: ";
    write_vendor_id(os, info);
  }
  if(info.has_max_compute_units()) {
    os << as << pre << "Max Compute Units ............: ";
    write_max_compute_units(os, info);
  }
  if(info.has_max_work_item_dimensions()) {
    os << as << pre << "Max Work Item Dimensions .....: ";
    write_max_work_item_dimensions(os, info);
  }
  if(info.has_max_work_item_sizes()) {
    os << as << pre << "Max Work Item Sizes ..........: ";
    write_max_work_item_sizes(os, info);
  }
  if(info.has_max_work_group_size()) {
    os << as << pre << "Max Work Group Size ..........: ";
    write_max_work_group_size(os, info);
  }
  if(info.has_preferred_vector_width_char()) {
    os << as << pre << "Preferred Vector Width Char ..: ";
    write_preferred_vector_width_char(os, info);
  }
  if(info.has_preferred_vector_width_short()) {
    os << as << pre << "Preferred Vector Width Short .: ";
    write_preferred_vector_width_short(os, info);
  }
  if(info.has_preferred_vector_width_int()) {
    os << as << pre << "Preferred Vector Width Int ...: ";
    write_preferred_vector_width_int(os, info);
  }
  if(info.has_preferred_vector_width_long()) {
    os << as << pre << "Preferred Vector Width Long ..: ";
    write_preferred_vector_width_long(os, info);
  }
  if(info.has_preferred_vector_width_float()) {
    os << as << pre << "Preferred Vector Width Float .: ";
    write_preferred_vector_width_float(os, info);
  }
  if(info.has_preferred_vector_width_double()) {
    os << as << pre << "Preferred Vector Width Double : ";
    write_preferred_vector_width_double(os, info);
  }
  if(info.has_preferred_vector_width_half()) {
    os << as << pre << "Preferred Vector Width Half ..: ";
    write_preferred_vector_width_half(os, info);
  }
  if(info.has_native_vector_width_char()) {
    os << as << pre << "Native Vector Width Char .....: ";
    write_native_vector_width_char(os, info);
  }
  if(info.has_native_vector_width_short()) {
    os << as << pre << "Native Vector Width Short ....: ";
    write_native_vector_width_short(os, info);
  }
  if(info.has_native_vector_width_int()) {
    os << as << pre << "Native Vector Width Int ......: ";
    write_native_vector_width_int(os, info);
  }
  if(info.has_native_vector_width_long()) {
    os << as << pre << "Native Vector Width Long .....: ";
    write_native_vector_width_long(os, info);
  }
  if(info.has_native_vector_width_float()) {
    os << as << pre << "Native Vector Width Float ....: ";
    write_native_vector_width_float(os, info);
  }
  if(info.has_native_vector_width_double()) {
    os << as << pre << "Native Vector Width Double ...: ";
    write_native_vector_width_double(os, info);
  }
  if(info.has_native_vector_width_half()) {
    os << as << pre << "Native Vector Width Half .....: ";
    write_native_vector_width_half(os, info);
  }
  if(info.has_max_clock_frequency()) {
    os << as << pre << "Max Clock Frequency ..........: ";
    write_max_clock_frequency(os, info);
  }
  if(info.has_address_bits()) {
    os << as << pre << "Address Bits .................: ";
    write_address_bits(os, info);
  }
  if(info.has_max_mem_alloc_size()) {
    os << as << pre << "Max Mem Alloc Size ...........: ";
    write_max_mem_alloc_size(os, info);
  }
  if(info.has_image_support()) {
    os << as << pre << "Image Support ................: ";
    write_image_support(os, info);
  }
  if(info.has_max_read_image_args()) {
    os << as << pre << "Max Read Image Args ..........: ";
    write_max_read_image_args(os, info);
  }
  if(info.has_max_write_image_args()) {
    os << as << pre << "Max Write Image Args .........: ";
    write_max_write_image_args(os, info);
  }
  if(info.has_image2d_max_width()) {
    os << as << pre << "Image2d Max Width ............: ";
    write_image2d_max_width(os, info);
  }
  if(info.has_image2d_max_height()) {
    os << as << pre << "Image2d Max Height ...........: ";
    write_image2d_max_height(os, info);
  }
  if(info.has_image3d_max_width()) {
    os << as << pre << "Image3d Max Width ............: ";
    write_image3d_max_width(os, info);
  }
  if(info.has_image3d_max_height()) {
    os << as << pre << "Image3d Max Height ...........: ";
    write_image3d_max_height(os, info);
  }
  if(info.has_image3d_max_depth()) {
    os << as << pre << "Image3d Max Depth ............: ";
    write_image3d_max_depth(os, info);
  }
  if(info.has_image_max_buffer_size()) {
    os << as << pre << "Image Max Buffer Size ........: ";
    write_image_max_buffer_size(os, info);
  }
  if(info.has_image_max_array_size()) {
    os << as << pre << "Image Max Array Size  ........: ";
    write_image_max_array_size(os, info);
  }
  if(info.has_max_samplers()) {
    os << as << pre << "Max Samplers .................: ";
    write_max_samplers(os, info);
  }
  if(info.has_max_parameter_size()) {
    os << as << pre << "Max Parameter Size ...........: ";
    write_max_parameter_size(os, info);
  }
  if(info.has_mem_base_addr_align()) {
    os << as << pre << "Mem Base Addr Align ..........: ";
    write_mem_base_addr_align(os, info);
  }
  if(info.has_min_data_type_align_size()) {
    os << as << pre << "Min Data Type Align Size .....: ";
    write_min_data_type_align_size(os, info);
  }
  if(info.has_single_fp_config()) {
    os << as << pre << "Single Prec. Floating Pt Caps : ";
    write_single_fp_config(os, info);
  }
  if(info.has_double_fp_config()) {
    os << as << pre << "Double Prec. Floating Pt Caps : ";
    write_double_fp_config(os, info);
  }
  if(info.has_global_mem_cache_type()) {
    os << as << pre << "Global Mem Cache Type ........: ";
    write_global_mem_cache_type(os, info);
  }
  if(info.has_global_mem_cacheline_size()) {
    os << as << pre << "Global Mem Cacheline Size ....: ";
    write_global_mem_cacheline_size(os, info);
  }
  if(info.has_global_mem_cache_size()) {
    os << as << pre << "Global Mem Cache Size ........: ";
    write_global_mem_cache_size(os, info);
  }
  if(info.has_global_mem_size()) {
    os << as << pre << "Global Mem Size ..............: ";
    write_global_mem_size(os, info);
  }
  if(info.has_max_constant_buffer_size()) {
    os << as << pre << "Max Constant Buffer Size .....: ";
    write_max_constant_buffer_size(os, info);
  }
  if(info.has_max_constant_args()) {
    os << as << pre << "Max Constant Args ............: ";
    write_max_constant_args(os, info);
  }
  if(info.has_local_mem_type()) {
    os << as << pre << "Local Mem Type ...............: ";
    write_local_mem_type(os, info);
  }
  if(info.has_local_mem_size()) {
    os << as << pre << "Local Mem Size ...............: ";
    write_local_mem_size(os, info);
  }
  if(info.has_error_correction_support()) {
    os << as << pre << "Error Correction Support .....: ";
    write_error_correction_support(os, info);
  }
  if(info.has_host_unified_memory()) {
    os << as << pre << "Host Unified Memory ..........: ";
    write_host_unified_memory(os, info);
  }
  if(info.has_profiling_timer_resolution()) {
    os << as << pre << "Profiling Timer Resolution ...: ";
    write_profiling_timer_resolution(os, info);
  }
  if(info.has_endian_little()) {
    os << as << pre << "Endian Little ................: ";
    write_endian_little(os, info);
  }
  if(info.has_available()) {
    os << as << pre << "Available ....................: ";
    write_available(os, info);
  }
  if(info.has_compiler_available()) {
    os << as << pre << "Compiler Available ...........: ";
    write_compiler_available(os, info);
  }
  if(info.has_linker_available()) {
    os << as << pre << "Linker Available .............: ";
    write_linker_available(os, info);
  }
  if(info.has_execution_capabilities()) {
    os << as << pre << "Execution Capabilities .......: ";
    write_execution_capabilities(os, info);
  }
  if(info.has_queue_properties()) {
    os << as << pre << "Queue Properties .............: ";
    write_queue_properties(os, info);
  }
  if(info.has_platform_id()) {
    os << as << pre << "Platform Id (current process).: ";
    write_platform_id(os, info);
  }
  if(info.has_name()) {
    os << as << pre << "Name .........................: ";
    write_name(os, info);
  }
  if(info.has_vendor()) {
    os << as << pre << "Vendor .......................: ";
    write_vendor(os, info);
  }
  if(info.has_driver_version()) {
    os << as << pre << "Driver Version ...............: ";
    write_driver_version(os, info);
  }
  if(info.has_profile()) {
    os << as << pre << "Profile ......................: ";
    write_profile(os, info);
  }
  if(info.has_version()) {
    os << as << pre << "Version ......................: ";
    write_version(os, info);
  }
  if(info.has_opencl_c_version()) {
    os << as << pre << "Opencl C Version .............: ";
    write_opencl_c_version(os, info);
  }
  if(info.has_extensions()) {
    os << as << pre << "Extensions ...................: ";
    write_extensions(os, info);
  }
  if(info.has_built_in_kernels()) {
    os << as << pre << "Built in Kernels .............: ";
    write_built_in_kernels(os, info);
  }
  if(info.has_parent_device_id()) {
    os << as << pre << "Parent Device ................: ";
    write_parent_device_id(os, info);
  }
  if(info.has_partition_max_sub_devices()) {
    os << as << pre << "Partition Max SubDevices .....: ";
    write_partition_max_sub_devices(os, info);
  }
  if(info.has_partition_properties()) {
    os << as << pre << "Partition Properties .........: ";
    write_partition_properties(os, info);
  }
  if(info.has_partition_affinity_domain()) {
    os << as << pre << "Partition Affinity Domain ....: ";
    write_partition_affinity_domain(os, info);
  }
  if(info.has_partition_type()) {
    os << as << pre << "Partition Type ...............: ";
    write_partition_type(os, info);
  }
  if(info.has_reference_count()) {
    os << as << pre << "Reference Count ..............: ";
    write_reference_count(os, info);
  }
  if(info.has_preferred_interop_user_sync()) {
    os << as << pre << "Preferred Interop User Sync ..: ";
    write_preferred_interop_user_sync(os, info);
  }
  if(info.has_printf_buffer_size()) {
    os << as << pre << "Printf Buffer Size ...........: ";
    write_printf_buffer_size(os, info);
  }
  if(info.has_image_pitch_alignment()) {
    os << as << pre << "Image Pitch Alignment ........: ";
    write_image_pitch_alignment(os, info);
  }
  if(info.has_image_base_address_alignment()) {
    os << as << pre << "Image Base Address Alignment .: ";
    write_image_base_address_alignment(os, info);
  }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Clinfo::Device_Info const& dev)
{
  return write(os, dev, 0);
}

} /* namespace Format */
} /* namespace Dimbo */

#endif /* DIMBO_FORMAT_CLINFO_DEVICE_INFO_IMPL */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
