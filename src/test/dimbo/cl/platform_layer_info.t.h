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

// dimbo/cl/platform_layer_info.t.h

/** // doc: dimbo/cl/platform_layer_info.t.h {{{
 * \file dimbo/cl/platform_layer_info.t.h
 * \brief Unit tests for Dimbo::Cl::Platform_Layer_Info
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_LAYER_INFO_T_H_INCLUDED
#define DIMBO_CL_PLATFORM_LAYER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/platform_layer_info.hpp>

namespace Dimbo { namespace Cl { class Platform_Layer_Info_TestSuite; } }

/** // doc: class Dimbo::Cl::Platform_Layer_Info_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Platform_Layer_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_ctor() {{{
   * \brief Test default constructor
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(Platform_Layer_Info p);
    TS_ASSERT_EQUALS(Platform_Layer_Info().platforms().size(), 0);
    TS_ASSERT_EQUALS(Platform_Layer_Info().devices().size(), 0);
  }
  /** // doc: test_ctor_1() {{{
   * \brief Test Platform_Layer_Info(layer, pquery, dquery)
   */ // }}}
  void test_ctor_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Platform_Query pquery;
    Device_Query dquery;
    TS_ASSERT_THROWS_NOTHING(Platform_Layer_Info p(layer, pquery,dquery));
  }
  /** // doc: test_ctor_2() {{{
   * \brief Test Platform_Layer_Info(layer)
   */ // }}}
  void test_ctor_2( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    TS_ASSERT_THROWS_NOTHING(Platform_Layer_Info p(layer));
  }
  /** // doc: test_clear() {{{
   * \brief Test the clear() method.
   */ // }}}
  void test_clear( )
  {
  }
  /** // doc: test_query() {{{
   * \brief Test the query() method
   */ // }}}
  void test_query( )
  {
  }
  /** // doc: test_platforms() {{{
   * \brief Test the platforms() method.
   */ // }}}
  void test_platforms( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Platform_Layer_Info p(layer);
    Platform_Layer_Info::Platform_Infos infos(p.platforms());

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
  /** // doc: test_devices_1() {{{
   * \brief Test the devices() method.
   */ // }}}
  void test_devices_1( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Platform_Layer_Info p(layer);
    Platform_Layer_Info::Device_Infos infos(p.devices());

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
  /** // doc: test_devices_2() {{{
   * \brief Test the devices(platforms()[0]) invocation.
   */ // }}}
  void test_devices_2( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Platform_Layer_Info p(layer);
    Platform_Layer_Info::Device_Infos infos(p.devices(p.platforms()[0]));

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
  /** // doc: test_devices_3() {{{
   * \brief Test the devices(platforms()[1]) invocation.
   */ // }}}
  void test_devices_3( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Platform_Layer_Info p(layer);
    Platform_Layer_Info::Device_Infos infos(p.devices(p.platforms()[1]));

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
  /** // doc: test_devices_4() {{{
   * \brief Test the devices(unknown_platform) invocation.
   */ // }}}
  void test_devices_4( )
  {
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    Platform_Layer layer;
    Platform_Layer_Info p(layer);
    Platform_Layer_Info::Const_Platform_Info_Ptr unknown_platform(NULL);
    Platform_Layer_Info::Device_Infos infos(p.devices(unknown_platform));

    TS_ASSERT_EQUALS(infos.size(), 0);
  }
};

#endif /* DIMBO_CL_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
