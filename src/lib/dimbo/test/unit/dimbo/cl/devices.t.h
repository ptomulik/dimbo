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

// dimbo/test/unit/dimbo/cl/devices.t.h

/** // doc: dimbo/test/unit/dimbo/cl/devices.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/devices.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_DEVICES_T_H_INCLUDED
#define DIMBO_CL_DEVICES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/devices.hpp>

namespace Dimbo { namespace Cl { class Devices_TestSuite; } }

/** // doc: class Dimbo::Cl::Devices_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Devices_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_num_devices_0() {{{
   * \brief Test get_num_devices() on Newton.
   */ // }}}
  void test_get_num_devices_1( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id const p = T::Newton_clGetPlatformIDs::platforms[0];
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_CPU),1);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_GPU),0);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_ACCELERATOR),0);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_CUSTOM),0);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_DEFAULT),1);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_ALL),1);
  }
  /** // doc: test_get_num_devices_1() {{{
   * \brief Test get_num_devices() on Newton.
   */ // }}}
  void test_get_num_devices_2( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id const p = T::Newton_clGetPlatformIDs::platforms[1];
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_CPU),0);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_GPU),2);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_ACCELERATOR),0);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_CUSTOM),0);
    TS_ASSERT_EQUALS(get_num_devices(p,CL_DEVICE_TYPE_ALL),2);
  }
  /** // doc: test_get_device_ids_1() {{{
   * \brief Test get_device_ids() on Newton - array version.
   */ // }}}
  void test_get_device_ids_1( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    cl_device_id devices[1];
    get_device_ids(p,CL_DEVICE_TYPE_ALL,1,devices,NULL);
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test_get_device_ids_2() {{{
   * \brief Test get_device_ids() on Newton - array version.
   */ // }}}
  void test_get_device_ids_2( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    cl_device_id devices[2];
    get_device_ids(p,CL_DEVICE_TYPE_ALL,2,devices,NULL);
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(devices[1], T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test_get_device_ids_3() {{{
   * \brief Test get_device_ids() on Newton - vector version.
   */ // }}}
  void test_get_device_ids_3( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    std::vector<cl_device_id> devices(get_device_ids(p,CL_DEVICE_TYPE_ALL));
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test_get_device_ids_4() {{{
   * \brief Test get_device_ids() on Newton - vector version.
   */ // }}}
  void test_get_device_ids_4( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    std::vector<cl_device_id> devices(get_device_ids(p,CL_DEVICE_TYPE_ALL));
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(devices[1], T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test_get_devices_1() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test_get_devices_1( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    Devices devices(get_devices(p, CL_DEVICE_TYPE_ALL));
    TS_ASSERT_EQUALS(static_cast<Device>(devices[0]).id(), T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test_get_devices_2() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test_get_devices_2( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    Devices devices(get_devices(p, CL_DEVICE_TYPE_ALL));
    TS_ASSERT_EQUALS(static_cast<Device>(devices[0]).id(), T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(static_cast<Device>(devices[1]).id(), T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test_get_devices_3() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test_get_devices_3( )
  {
    T::Newton_clGetDeviceIDs mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    Devices devices(get_devices(p, CL_DEVICE_TYPE_ALL));
    TS_ASSERT_EQUALS(((Device)devices[0]).id(), T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test_get_devices_4() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test_get_devices_4( )
  {
    T::Newton_clGetDeviceIDs mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[1]);
    Devices devices(get_devices(p, CL_DEVICE_TYPE_ALL));
    TS_ASSERT_EQUALS(((Device)devices[0]).id(), T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(((Device)devices[1]).id(), T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test_invalid_platform() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_PLATFORM.
   */ // }}}
  void test_invalid_platform( )
  {
    T::ErrRet_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_num_devices(NULL,0),Cl_Error_No<CL_INVALID_PLATFORM>);
    TS_ASSERT_THROWS(get_device_ids(NULL,0),Cl_Error_No<CL_INVALID_PLATFORM>);
    TS_ASSERT_THROWS(get_devices(NULL,0),Cl_Error_No<CL_INVALID_PLATFORM>);
  }
  /** // doc: test_invalid_device_type() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test_invalid_device_type( )
  {
    T::ErrRet_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_num_devices(NULL,0),Cl_Error_No<CL_INVALID_DEVICE_TYPE>);
    TS_ASSERT_THROWS(get_device_ids(NULL,0),Cl_Error_No<CL_INVALID_DEVICE_TYPE>);
    TS_ASSERT_THROWS(get_devices(NULL,0),Cl_Error_No<CL_INVALID_DEVICE_TYPE>);
    TS_ASSERT_THROWS(get_devices(Platform(NULL),0),Cl_Error_No<CL_INVALID_DEVICE_TYPE>);
  }
  /** // doc: test_invalid_value() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_VALUE.
   */ // }}}
  void test_invalid_value( )
  {
    T::ErrRet_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_num_devices(NULL,0),Cl_Error_No<CL_INVALID_VALUE>);
    TS_ASSERT_THROWS(get_device_ids(NULL,0),Cl_Error_No<CL_INVALID_VALUE>);
    TS_ASSERT_THROWS(get_devices(NULL,0),Cl_Error_No<CL_INVALID_VALUE>);
    TS_ASSERT_THROWS(get_devices(Platform(NULL),0),Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_device_not_found() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_DEVICE_NOT_FOUND.
   */ // }}}
  void test_device_not_found( )
  {
    T::ErrRet_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    TS_ASSERT_THROWS_NOTHING(get_num_devices(NULL,0))
    TS_ASSERT_THROWS_NOTHING(get_device_ids(NULL,0))
    TS_ASSERT_THROWS_NOTHING(get_devices(NULL,0))
    TS_ASSERT_THROWS_NOTHING(get_devices(Platform(NULL),0))
  }
  /** // doc: test_out_of_resources() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_out_of_resources( )
  {
    T::ErrRet_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_num_devices(NULL,0),Cl_Error_No<CL_OUT_OF_RESOURCES>);
    TS_ASSERT_THROWS(get_device_ids(NULL,0),Cl_Error_No<CL_OUT_OF_RESOURCES>);
    TS_ASSERT_THROWS(get_devices(NULL,0),Cl_Error_No<CL_OUT_OF_RESOURCES>);
    TS_ASSERT_THROWS(get_devices(Platform(NULL),0),Cl_Error_No<CL_OUT_OF_RESOURCES>);
  }
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_out_of_host_memory( )
  {
    T::ErrRet_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_num_devices(NULL,0), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
    TS_ASSERT_THROWS(get_device_ids(NULL,0), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
    TS_ASSERT_THROWS(get_devices(NULL,0), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
    TS_ASSERT_THROWS(get_devices(Platform(NULL),0), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
  }
  /** // doc: test_other_error() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        unknown error code.
   */ // }}}
  void test_other_error( )
  {
    T::ErrRet_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_num_devices(NULL,0),Other_Cl_Error);
    TS_ASSERT_THROWS(get_device_ids(NULL,0),Other_Cl_Error);
    TS_ASSERT_THROWS(get_devices(NULL,0),Other_Cl_Error);
    TS_ASSERT_THROWS(get_devices(Platform(NULL),0),Other_Cl_Error);
  }
};

#endif /* DIMBO_CL_DEVICES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
