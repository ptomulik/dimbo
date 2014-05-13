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

// dimbo/format/cl/device_query_impl.hpp

#ifndef DIMBO_FORMAT_CL_DEVICE_QUERY_IMPL
#define DIMBO_FORMAT_CL_DEVICE_QUERY_IMPL

/** // doc: dimbo/format/cl/device_query_impl.hpp {{{
 * @file dimbo/format/cl/device_query_impl.hpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/format/cl/device_query.hpp>
#include <dimbo/format/autosep.hpp>
#include <string>
#include <ostream>

template<class Ostream, typename T> static Ostream&
write_bool(Ostream& os, T value)
{
  return (os << (value ? "Yes" : "No"));
}

namespace Dimbo {
namespace Format {

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Cl::Device_Query const& query, int ind)
{
  Autosep<const char*> as("\n");
  std::string pre(ind, ' ');

  os << as << pre << "Id (within current process) ..: ";
  write_bool(os, query.id_selected());
  os << as << pre << "Type .........................: ";
  write_bool(os, query.type_selected());
  os << as << pre << "Vendor Id ....................: ";
  write_bool(os, query.vendor_id_selected());
  os << as << pre << "Max Compute Units ............: ";
  write_bool(os, query.max_compute_units_selected());
  os << as << pre << "Max Work Item Dimensions .....: ";
  write_bool(os, query.max_work_item_dimensions_selected());
  os << as << pre << "Max Work Group Size ..........: ";
  write_bool(os, query.max_work_group_size_selected());
  os << as << pre << "Max Work Item Sizes ..........: ";
  write_bool(os, query.max_work_item_sizes_selected());
  os << as << pre << "Preferred Vector Width Char ..: ";
  write_bool(os, query.preferred_vector_width_char_selected());
  os << as << pre << "Preferred Vector Width Short .: ";
  write_bool(os, query.preferred_vector_width_short_selected());
  os << as << pre << "Preferred Vector Width Int ...: ";
  write_bool(os, query.preferred_vector_width_int_selected());
  os << as << pre << "Preferred Vector Width Long ..: ";
  write_bool(os, query.preferred_vector_width_long_selected());
  os << as << pre << "Preferred Vector Width Float .: ";
  write_bool(os, query.preferred_vector_width_float_selected());
  os << as << pre << "Preferred Vector Width Double : ";
  write_bool(os, query.preferred_vector_width_double_selected());
  os << as << pre << "Preferred Vector Width Half ..: ";
  write_bool(os, query.preferred_vector_width_half_selected());
  os << as << pre << "Native Vector Width Char .....: ";
  write_bool(os, query.native_vector_width_char_selected());
  os << as << pre << "Native Vector Width Short ....: ";
  write_bool(os, query.native_vector_width_short_selected());
  os << as << pre << "Native Vector Width Int ......: ";
  write_bool(os, query.native_vector_width_int_selected());
  os << as << pre << "Native Vector Width Long .....: ";
  write_bool(os, query.native_vector_width_long_selected());
  os << as << pre << "Native Vector Width Float ....: ";
  write_bool(os, query.native_vector_width_float_selected());
  os << as << pre << "Native Vector Width Double ...: ";
  write_bool(os, query.native_vector_width_double_selected());
  os << as << pre << "Native Vector Width Half .....: ";
  write_bool(os, query.native_vector_width_half_selected());
  os << as << pre << "Max Clock Frequency ..........: ";
  write_bool(os, query.max_clock_frequency_selected());
  os << as << pre << "Address Bits .................: ";
  write_bool(os, query.address_bits_selected());
  os << as << pre << "Max Mem Alloc Size ...........: ";
  write_bool(os, query.max_mem_alloc_size_selected());
  os << as << pre << "Image Support ................: ";
  write_bool(os, query.image_support_selected());
  os << as << pre << "Max Read Image Args ..........: ";
  write_bool(os, query.max_read_image_args_selected());
  os << as << pre << "Max Write Image Args .........: ";
  write_bool(os, query.max_write_image_args_selected());
  os << as << pre << "Image2d Max Width ............: ";
  write_bool(os, query.image2d_max_width_selected());
  os << as << pre << "Image2d Max Height ...........: ";
  write_bool(os, query.image2d_max_height_selected());
  os << as << pre << "Image3d Max Width ............: ";
  write_bool(os, query.image3d_max_width_selected());
  os << as << pre << "Image3d Max Height ...........: ";
  write_bool(os, query.image3d_max_height_selected());
  os << as << pre << "Image3d Max Depth ............: ";
  write_bool(os, query.image3d_max_depth_selected());
  os << as << pre << "Max Samplers .................: ";
  write_bool(os, query.max_samplers_selected());
  os << as << pre << "Max Parameter Size ...........: ";
  write_bool(os, query.max_parameter_size_selected());
  os << as << pre << "Mem Base Addr Align ..........: ";
  write_bool(os, query.mem_base_addr_align_selected());
  os << as << pre << "Min Data Type Align Size .....: ";
  write_bool(os, query.min_data_type_align_size_selected());
  os << as << pre << "Single Prec. Floating Pt Caps : ";
  write_bool(os, query.single_fp_config_selected());
  os << as << pre << "Global Mem Cache Type ........: ";
  write_bool(os, query.global_mem_cache_type_selected());
  os << as << pre << "Global Mem Cacheline Size ....: ";
  write_bool(os, query.global_mem_cacheline_size_selected());
  os << as << pre << "Global Mem Cache Size ........: ";
  write_bool(os, query.global_mem_cache_size_selected());
  os << as << pre << "Global Mem Size ..............: ";
  write_bool(os, query.global_mem_size_selected());
  os << as << pre << "Max Constant Buffer Size .....: ";
  write_bool(os, query.max_constant_buffer_size_selected());
  os << as << pre << "Max Constant Args ............: ";
  write_bool(os, query.max_constant_args_selected());
  os << as << pre << "Local Mem Type ...............: ";
  write_bool(os, query.local_mem_type_selected());
  os << as << pre << "Local Mem Size ...............: ";
  write_bool(os, query.local_mem_size_selected());
  os << as << pre << "Error Correction Support .....: ";
  write_bool(os, query.error_correction_support_selected());
  os << as << pre << "Host Unified Memory ..........: ";
  write_bool(os, query.host_unified_memory_selected());
  os << as << pre << "Profiling Timer Resolution ...: ";
  write_bool(os, query.profiling_timer_resolution_selected());
  os << as << pre << "Endian Little ................: ";
  write_bool(os, query.endian_little_selected());
  os << as << pre << "Available ....................: ";
  write_bool(os, query.available_selected());
  os << as << pre << "Compiler Available ...........: ";
  write_bool(os, query.compiler_available_selected());
  os << as << pre << "Execution Capabilities .......: ";
  write_bool(os, query.execution_capabilities_selected());
  os << as << pre << "Queue Properties .............: ";
  write_bool(os, query.queue_properties_selected());
  os << as << pre << "Platform Id (current process).: ";
  write_bool(os, query.platform_id_selected());
  os << as << pre << "Name .........................: ";
  write_bool(os, query.name_selected());
  os << as << pre << "Vendor .......................: ";
  write_bool(os, query.vendor_selected());
  os << as << pre << "Driver Version ...............: ";
  write_bool(os, query.driver_version_selected());
  os << as << pre << "Profile ......................: ";
  write_bool(os, query.profile_selected());
  os << as << pre << "Version ......................: ";
  write_bool(os, query.version_selected());
  os << as << pre << "Opencl C Version .............: ";
  write_bool(os, query.opencl_c_version_selected());
  os << as << pre << "Extensions ...................: ";
  write_bool(os, query.extensions_selected());
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Cl::Device_Query const& dev)
{
  return write(os, dev, 0);
}

} /* namespace Format */
} /* namespace Dimbo */

#endif /* DIMBO_FORMAT_CL_DEVICE_QUERY_IMPL */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
