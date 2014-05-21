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

// dimbo/test/unit/dimbo/cl/platform_layer.t.h

/** // doc: dimbo/test/unit/dimbo/cl/platform_layer.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/platform_layer.t.h
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
  /** // doc: test_foo() {{{
   * \todo Write documentation
   */ // }}}
  void test_foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* DIMBO_CL_PLATFORM_LAYER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
