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

namespace Dimbo { namespace Cl { class Platform_Info_TestSuite; } }
namespace Dimbo { namespace Cl { class clGetPlatformInfo_Mock; } }


class Dimbo::Cl::clGetPlatformInfo_Mock
  : public T::Base_clGetPlatformInfo
{
public:
  cl_platform_id last_platform_id;
  clGetPlatformInfo_Mock()
    : last_platform_id(reinterpret_cast<cl_platform_id>(0))
  {
  }

  /* Implementation of clGetPlatformInfo() that does not return anything */
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret)
  {
    this->last_platform_id = platform;
    (void)param_name; // prevent "unused parameter" warning
    if(param_value != NULL && param_value_size > 0)
      {
        /* At least for OpenCL 1.0, all the returned types are char[] */
        *(static_cast<char*>(param_value)) = 0;
      }
    if(param_value_size_ret != NULL)
      {
        *param_value_size_ret = 1;
      }
    return 0;
  }
};

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
  /** // doc: test_ctor_1() {{{
   * \brief Test Platform_Info(platform) constructor call.
   */ // }}}
  void test_ctor_1( )
  {
    const cl_platform_id id = reinterpret_cast<cl_platform_id>(0x1234ul);
    clGetPlatformInfo_Mock mock;
    Platform platform(id);
    Platform_Info info(platform); // this queries platfrom info
    TS_ASSERT_EQUALS(info.id(), 0x1234ul);
    TS_ASSERT_EQUALS(info.last_query(), Platform_Query());
    TS_ASSERT_EQUALS(mock.last_platform_id, id);
  }
};

#endif /* DIMBO_CL_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
