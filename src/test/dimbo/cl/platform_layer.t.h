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

// dimbo/cl/platform_layer.t.h

/** // doc: dimbo/cl/platform_layer.t.h {{{
 * \file dimbo/cl/platform_layer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_LAYER_T_H_INCLUDED
#define DIMBO_CL_PLATFORM_LAYER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/platform_layer.hpp>

namespace Dimbo { namespace Cl { class Platform_Layer_TestSuite; } }

/** // doc: class Dimbo::Cl::Platform_Layer_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Platform_Layer_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;

    TS_ASSERT_EQUALS(Platform_Layer().platforms().size(), 2);
    TS_ASSERT_EQUALS(Platform_Layer().devices().size(), 3);
  }
  /** // doc: test_platforms_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_platforms_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Platform p = pl.platforms()[0];

    TS_ASSERT_EQUALS(p.id(), T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(p.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
    TS_ASSERT_EQUALS(p.get_name(), "AMD Accelerated Parallel Processing");
    TS_ASSERT_EQUALS(p.get_vendor(), "Advanced Micro Devices, Inc.");
    TS_ASSERT_EQUALS(p.get_extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
  /** // doc: test_platforms_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_platforms_2( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Platform p = pl.platforms()[1];

    TS_ASSERT_EQUALS(p.id(), T::Newton_clGetPlatformIDs::platforms[1]);
    TS_ASSERT_EQUALS(p.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(p.get_version(), "OpenCL 1.1 CUDA 4.2.1");
    TS_ASSERT_EQUALS(p.get_name(), "NVIDIA CUDA");
    TS_ASSERT_EQUALS(p.get_vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(p.get_extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll");
  }
  /** // doc: test_platform_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_platform_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Devices d = pl.devices();

    TS_ASSERT_EQUALS(pl.devices().size(), 3);
    TS_ASSERT_EQUALS(pl.platform(d[0]).id(), T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(pl.platform(d[1]).id(), T::Newton_clGetPlatformIDs::platforms[1]);
    TS_ASSERT_EQUALS(pl.platform(d[2]).id(), T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_devices_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Device d = pl.devices()[0];

    TS_ASSERT_EQUALS(d.id(), T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(d.get_vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(d.get_driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_devices_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_devices_2( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Device d = pl.devices()[1];

    TS_ASSERT_EQUALS(d.id(), T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_name(), "Tesla C1060");
    TS_ASSERT_EQUALS(d.get_vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(d.get_driver_version(), "319.76");
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_devices_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_devices_3( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Device d = pl.devices()[2];

    TS_ASSERT_EQUALS(d.id(), T::Newton_clGetDeviceIDs::devices[2]);
    TS_ASSERT_EQUALS(d.get_name(), "Tesla C1060");
    TS_ASSERT_EQUALS(d.get_vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(d.get_driver_version(), "319.76");
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_devices_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_devices_4( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Platform p = pl.platforms()[0];
    Devices ds = pl.devices(p);

    TS_ASSERT_EQUALS(ds.size(), 1);

    Device d = ds[0];

    TS_ASSERT_EQUALS(d.id(), T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test_devices_5() {{{
   * \todo Write documentation
   */ // }}}
  void test_devices_5( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Platform p = pl.platforms()[1];
    Devices ds = pl.devices(p);

    TS_ASSERT_EQUALS(ds.size(), 2);

    Device d = ds[0];

    TS_ASSERT_EQUALS(d.id(), T::Newton_clGetDeviceIDs::devices[1]);
  }
  /** // doc: test_devices_6() {{{
   * \todo Write documentation
   */ // }}}
  void test_devices_6( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer pl;
    Platform p = pl.platforms()[1];
    Devices ds = pl.devices(p);

    TS_ASSERT_EQUALS(ds.size(), 2);

    Device d = ds[1];

    TS_ASSERT_EQUALS(d.id(), T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test_query_platform_layer_info_1() {{{
   * \brief Test the platforms() method.
   */ // }}}
  void test_query_platform_layer_info_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Dimbo::Clinfo::Platform_Layer_Info p(query_platform_layer_info(layer));
    Dimbo::Clinfo::Platform_Info_Ptrs infos(p.platforms());

    TS_ASSERT_EQUALS(infos.size(), 2);

    /* Check if we have obtained  correct information */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetPlatformIDs::platforms[0]));
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.2 AMD-APP (1348.4)");
    TS_ASSERT_EQUALS(infos[0]->name(), "AMD Accelerated Parallel Processing");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "Advanced Micro Devices, Inc.");
    TS_ASSERT_EQUALS(infos[0]->extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");

    TS_ASSERT_EQUALS(infos[1]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetPlatformIDs::platforms[1]));
    TS_ASSERT_EQUALS(infos[1]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[1]->version(), "OpenCL 1.1 CUDA 4.2.1");
    TS_ASSERT_EQUALS(infos[1]->name(), "NVIDIA CUDA");
    TS_ASSERT_EQUALS(infos[1]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[1]->extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll");
  }
  /** // doc: test_query_platform_layer_info_2() {{{
   * \brief Test the devices() method.
   */ // }}}
  void test_query_platform_layer_info_2( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Dimbo::Clinfo::Platform_Layer_Info p(query_platform_layer_info(layer));
    Dimbo::Clinfo::Device_Info_Ptrs infos(p.devices());

    TS_ASSERT_EQUALS(infos.size(), 3);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[0]));
    TS_ASSERT_EQUALS(infos[0]->name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(infos[0]->driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.2 AMD-APP (1348.4)");

    TS_ASSERT_EQUALS(infos[1]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[1]));
    TS_ASSERT_EQUALS(infos[1]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[1]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[1]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[1]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[1]->version(), "OpenCL 1.0 CUDA");

    TS_ASSERT_EQUALS(infos[2]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[2]));
    TS_ASSERT_EQUALS(infos[2]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[2]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[2]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[2]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[2]->version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_query_platform_layer_info_2() {{{
   * \brief Test the query_platform_layer_info(platforms()[0]) invocation.
   */ // }}}
  void test_query_platform_layer_info_3( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Dimbo::Clinfo::Platform_Layer_Info p(query_platform_layer_info(layer));
    Dimbo::Clinfo::Device_Info_Ptrs infos(p.devices(p.platforms()[0]));

    TS_ASSERT_EQUALS(infos.size(), 1);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[0]));
    TS_ASSERT_EQUALS(infos[0]->name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(infos[0]->driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_query_platform_layer_info_2() {{{
   * \brief Test the query_platform_layer_info(platforms()[0]) invocation.
   */ // }}}
  void test_query_platform_layer_info_4( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Dimbo::Clinfo::Platform_Layer_Info p(query_platform_layer_info(layer));
    Dimbo::Clinfo::Device_Info_Ptrs infos(p.devices(p.platforms()[1]));

    TS_ASSERT_EQUALS(infos.size(), 2);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[1]));
    TS_ASSERT_EQUALS(infos[0]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[0]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.0 CUDA");

    TS_ASSERT_EQUALS(infos[1]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[2]));
    TS_ASSERT_EQUALS(infos[1]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[1]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[1]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[1]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[1]->version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_query_platform_layer_info_5() {{{
   * \brief Test the devices(unknown_platform) invocation.
   */ // }}}
  void test_query_platform_layer_info_5( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Dimbo::Clinfo::Platform_Layer_Info p(query_platform_layer_info(layer));
    Dimbo::Clinfo::Const_Platform_Info_Ptr unknown_platform(NULL);
    Dimbo::Clinfo::Device_Info_Ptrs infos(p.devices(unknown_platform));

    TS_ASSERT(infos.empty());
  }
};

#endif /* DIMBO_CL_PLATFORM_LAYER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
