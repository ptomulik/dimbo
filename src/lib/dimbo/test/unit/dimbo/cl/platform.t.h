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

// dimbo/test/unit/dimbo/cl/platform.t.h

/** // doc: dimbo/test/unit/dimbo/cl/platform.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/platform.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_T_H_INCLUDED
#define DIMBO_CL_PLATFORM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/platform.hpp>

namespace Dimbo { namespace Cl { class Platform_TestSuite; } }

/** // doc: class Dimbo::Cl::Platform_TestSuite {{{
 * \brief Unit tests for Dimbo::Cl::Platform class
 */ // }}}
class Dimbo::Cl::Platform_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_ctor_default() {{{
   * \brief Ensure that id() == NULL by default.
   */ // }}}
  void test_ctor_default( )
  {
    Platform p;
    TS_ASSERT_EQUALS(p.id(), reinterpret_cast<cl_platform_id>(NULL));
  }
  /** // doc: test_ctor_assign() {{{
   * \brief Ensure that assigining constructor works as expected.
   */ // }}}
  void test_ctor_assign( )
  {
    Platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS(p1.id(), reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_ctor_copy() {{{
   * \brief Ensure that copy constructor works as expected.
   */ // }}}
  void test_ctor_copy( )
  {
    Platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    Platform p2(p1);
    TS_ASSERT_EQUALS(p2.id(), p1.id());
  }
  /** // doc: test_op_assign() {{{
   * \brief Ensure that assignment operator works.
   */ // }}}
  void test_op_assign( )
  {
    Platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    Platform p2;
    TS_ASSERT_EQUALS(&(p2 = p1), &p2);
    TS_ASSERT_EQUALS(p2.id(), p1.id());
  }
  /** // doc: test_op_cast() {{{
   * \brief Ensure that conversion operator works.
   */ // }}}
  void test_op_cast( )
  {
    Platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS((cl_platform_id)p1, reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_assign() {{{
   * \brief Ensure that assign() method works.
   */ // }}}
  void test_assign( )
  {
    Platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    Platform p2;
    p2.assign(p1);
    TS_ASSERT_EQUALS(p2.id(), p1.id());
  }
  /** // doc: test_is_initialized_1() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_1( )
  {
    Platform p;
    TS_ASSERT(!p.is_initialized());
  }
  /** // doc: test_is_initialized_2() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_2( )
  {
    Platform p(reinterpret_cast<cl_platform_id>(NULL));
    TS_ASSERT(!p.is_initialized());
  }
  /** // doc: test_is_initialized_3() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_3( )
  {
    Platform p(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT(p.is_initialized());
  }
  /** // doc: test_id_1() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_1( )
  {
    Platform p(reinterpret_cast<cl_platform_id>(NULL));
    TS_ASSERT_EQUALS(p.id(),reinterpret_cast<cl_platform_id>(NULL));
  }
  /** // doc: test_id_2() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_2( )
  {
    Platform p(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS(p.id(),reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_get_valid_id_1() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_1( )
  {
    Platform p(reinterpret_cast<cl_platform_id>(NULL));
    TS_ASSERT_THROWS(p.get_valid_id(), DIMBO_CL_EXCEPTION(Uninitialized_Platform));
  }
  /** // doc: test_get_valid_id_2() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_2( )
  {
    Platform p(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS(p.get_valid_id(),reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_get_info_wrong_id() {{{
   * \brief Test get_info(CL_PLATFORM_PROFILE, ...) on platform object having wrong id.
   */ // }}}
  void test_get_info_wrong_id( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(reinterpret_cast<cl_platform_id>(0x34556ul));
    TS_ASSERT_THROWS(p.get_info(CL_PLATFORM_PROFILE, 0, NULL, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_PLATFORM>);
  }
  /** // doc: test_get_info_0() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test_get_info_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    TS_ASSERT_THROWS(p.get_info(0, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_1() {{{
   * \brief Test get_info(CL_PLATFORM_PROFILE, 1, value, NULL).
   */ // }}}
  void test_get_info_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[1];
    TS_ASSERT_THROWS(p.get_info(CL_PLATFORM_PROFILE, 1, value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_profile_0() {{{
   * \brief Test get_info(CL_PLATFORM_PROFILE, 0, NULL, &size).
   */ // }}}
  void test_get_info_profile_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(CL_PLATFORM_PROFILE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
  /** // doc: test_get_info_profile_1() {{{
   * \brief Test get_info(CL_PLATFORM_PROFILE, ...).
   */ // }}}
  void test_get_info_profile_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[13];
    p.get_info(CL_PLATFORM_PROFILE, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "FULL_PROFILE");
  }
  /** // doc: test_get_info_version_0() {{{
   * \brief Test get_info(CL_PLATFORM_VERSION, 0, NULL, &size).
   */ // }}}
  void test_get_info_version_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(CL_PLATFORM_VERSION, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 28);
  }
//  /** // doc: test_get_info_version_1() {{{
//   * \brief Test get_info(CL_PLATFORM_PROFILE, ...).
//   */ // }}}
  void test_get_info_version_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[28];
    p.get_info(CL_PLATFORM_VERSION, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_get_info_name_0() {{{
   * \brief Test get_info(CL_PLATFORM_NAME, 0, NULL, &size).
   */ // }}}
  void test_get_info_name_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(CL_PLATFORM_NAME, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 36);
  }
//  /** // doc: test_get_info_name_1() {{{
//   * \brief Test get_info(CL_PLATFORM_PROFILE, ...).
//   */ // }}}
  void test_get_info_name_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[36];
    p.get_info(CL_PLATFORM_NAME, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "AMD Accelerated Parallel Processing");
  }
  /** // doc: test_get_info_vendor_0() {{{
   * \brief Test get_info(CL_PLATFORM_VENDOR, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(CL_PLATFORM_VENDOR, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 29);
  }
//  /** // doc: test_get_info_vendor_1() {{{
//   * \brief Test get_info(CL_PLATFORM_PROFILE, ...).
//   */ // }}}
  void test_get_info_vendor_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[29];
    p.get_info(CL_PLATFORM_VENDOR, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "Advanced Micro Devices, Inc.");
  }
  /** // doc: test_get_info_extensions_0() {{{
   * \brief Test get_info(CL_PLATFORM_EXTENSIONS, 0, NULL, &size).
   */ // }}}
  void test_get_info_extensions_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(CL_PLATFORM_EXTENSIONS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 56);
  }
//  /** // doc: test_get_info_extensions_1() {{{
//   * \brief Test get_info(CL_PLATFORM_PROFILE, ...).
//   */ // }}}
  void test_get_info_extensions_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[56];
    p.get_info(CL_PLATFORM_EXTENSIONS, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
  /** // doc: test_get_profile_1() {{{
   * \brief Test get_profile()
   */ // }}}
  void test_get_profile_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_profile(), "FULL_PROFILE");
  }
//  /** // doc: test_get_version_1() {{{
//   * \brief Test get_version()
//   */ // }}}
  void test_get_version_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
//  /** // doc: test_get_name_1() {{{
//   * \brief Test get_name()
//   */ // }}}
  void test_get_name_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_name(), "AMD Accelerated Parallel Processing");
  }
//  /** // doc: test_get_vendor_1() {{{
//   * \brief Test get_vendor()
//   */ // }}}
  void test_get_vendor_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_vendor(), "Advanced Micro Devices, Inc.");
  }
//  /** // doc: test_get_extensions_1() {{{
//   * \brief Test get_extensions()
//   */ // }}}
  void test_get_extensions_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    Platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
};

#endif /* DIMBO_CL_PLATFORM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
