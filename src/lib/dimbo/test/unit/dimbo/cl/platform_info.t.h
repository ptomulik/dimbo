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

// dimbo/test/unit/dimbo/cl/platform_info.t.h

/** // doc: dimbo/test/unit/dimbo/cl/platform_info.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/platform_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_INFO_T_H_INCLUDED
#define DIMBO_CL_PLATFORM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/platform_info.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Cl { class Platform_Info_TestSuite; } }

/** // doc: class Dimbo::Cl::Platform_Info_TestSuite {{{
 * \brief Unit tests for Dimbo::Cl::Platform_Info class
 */ // }}}
class Dimbo::Cl::Platform_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_id() {{{
   * \brief Ensure that Platform_Info has id() == 0.
   */ // }}}
  void test_default_id( )
  {
    TS_ASSERT_EQUALS(Platform_Info().id(), 0);
  }
  /** // doc: test_default_profile() {{{
   * \brief Ensure that Platform_Info has profile() == "" by default.
   */ // }}}
  void test_default_profile( )
  {
    TS_ASSERT_EQUALS(Platform_Info().profile(), "");
  }
  /** // doc: test_default_profile() {{{
   * \brief Ensure that Platform_Info has version() == "" by default.
   */ // }}}
  void test_default_version( )
  {
    TS_ASSERT_EQUALS(Platform_Info().version(), "");
  }
  /** // doc: test_default_vendor() {{{
   * \brief Ensure that Platform_Info has vendor() == "" by default.
   */ // }}}
  void test_default_vendor( )
  {
    TS_ASSERT_EQUALS(Platform_Info().vendor(), "");
  }
  /** // doc: test_default_extensions() {{{
   * \brief Ensure that Platform_Info has extensions() == "" by default.
   */ // }}}
  void test_default_extensions( )
  {
    TS_ASSERT_EQUALS(Platform_Info().extensions(), "");
  }
  /** // doc: test_default_last_query() {{{
   * \brief Ensure that Platform_Info has empty last_query() by default.
   */ // }}}
  void test_default_last_query( )
  {
    Platform_Query empty;
    empty.select_none();
    TS_ASSERT_EQUALS(Platform_Info().last_query(), empty);
  }
  /** // doc: test_ctor() {{{
   * \brief Test Platform_Info's default constructor.
   */ // }}}
  void test_ctor( )
  {
    Platform_Info info;
    Platform_Query query;
    query.select_none();

    TS_ASSERT_EQUALS(info.id(),0);
    TS_ASSERT_EQUALS(info.profile(),"");
    TS_ASSERT_EQUALS(info.version(),"");
    TS_ASSERT_EQUALS(info.name(),"");
    TS_ASSERT_EQUALS(info.vendor(),"");
    TS_ASSERT_EQUALS(info.extensions(),"");
    TS_ASSERT_EQUALS(info.last_query(), query);
  }
  /** // doc: test_ctor_invalid_platform() {{{
   * \brief Test Platform_Info(platform) constructor call.
   *
   * Ensures that the Platform_Info(platform) throws appropriate exception
   * when **platform** refers to an inexistent OpenCL platform.
   */ // }}}
  void test_ctor_invalid_platform( )
  {
    T::ErrRet_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    Platform platform(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_THROWS(Platform_Info info(platform),Cl_Error_No<CL_INVALID_PLATFORM>)
  }
  /** // doc: test_ctor_newton_cpu() {{{
   * \brief Test Platform_Info(platform) constructor call.
   *
   * Ensures that the constructor initializes the Platform_Info instance with
   * correct values.
   */ // }}}
  void test_ctor_newton_cpu()
  {
    T::Newton_clGetPlatformInfo mock;
    Platform platform(T::Newton_clGetPlatformIDs::platforms[0]);
    Platform_Info info(platform);
    TS_ASSERT_EQUALS(info.profile(),"FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(),"OpenCL 1.2 AMD-APP (1348.4)");
    TS_ASSERT_EQUALS(info.name(),"AMD Accelerated Parallel Processing");
    TS_ASSERT_EQUALS(info.vendor(),"Advanced Micro Devices, Inc.");
    TS_ASSERT_EQUALS(info.extensions(),"cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
    TS_ASSERT_EQUALS(info.last_query(), Platform_Query());
  }
  /** // doc: test_ctor_newton_gpu() {{{
   * \brief Test Platform_Info(platform) constructor call.
   *
   * Ensures that the constructor initializes the Platform_Info instance with
   * correct values.
   */ // }}}
  void test_ctor_newton_gpu()
  {
    T::Newton_clGetPlatformInfo mock;
    Platform platform(T::Newton_clGetPlatformIDs::platforms[1]);
    Platform_Info info(platform);
    TS_ASSERT_EQUALS(info.profile(),"FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(),"OpenCL 1.1 CUDA 4.2.1");
    TS_ASSERT_EQUALS(info.name(),"NVIDIA CUDA");
    TS_ASSERT_EQUALS(info.vendor(),"NVIDIA Corporation");
    TS_ASSERT_EQUALS(info.extensions(),"cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll");
    TS_ASSERT_EQUALS(info.last_query(), Platform_Query());
  }
  /** // doc: test_serialize_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_1()
  {
    T::Newton_clGetPlatformInfo mock;
    Platform platform(T::Newton_clGetPlatformIDs::platforms[1]);
    Platform_Info orig(platform);
    Platform_Info info;

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << orig; // serialize

    boost::archive::text_iarchive ia(ss);
    ia >> info; // deserialize

    TS_ASSERT_EQUALS(info, orig);
  }
  /** // doc: test_eq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op()
  {
    T::Newton_clGetPlatformInfo mock;
    Platform platform(T::Newton_clGetPlatformIDs::platforms[1]);
    Platform_Info a(platform);
    Platform_Info b(platform);
    Platform_Info c;
    TS_ASSERT((a == b));
    TS_ASSERT(!(a == c));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op()
  {
    T::Newton_clGetPlatformInfo mock;
    Platform platform(T::Newton_clGetPlatformIDs::platforms[1]);
    Platform_Info a(platform);
    Platform_Info b(platform);
    Platform_Info c;
    TS_ASSERT(!(a != b));
    TS_ASSERT((a != c));
  }
};

#endif /* DIMBO_CL_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
