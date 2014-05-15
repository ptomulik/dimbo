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

// dimbo/test/unit/dimbo/cl/platforms.t.h

/** // doc: dimbo/test/unit/dimbo/cl/platforms.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/platforms.t.h
 * \brief Unit tests for dimbo/cl/platforms.hpp
 */ // }}}
#ifndef DIMBO_CL_PLATFORMS_T_H_INCLUDED
#define DIMBO_CL_PLATFORMS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/platforms.hpp>

namespace Dimbo { namespace Cl { class Platforms_TestSuite; } }

/** // doc: class Platforms_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Platforms_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_num_platforms_1() {{{
   * \brief Test get_num_platforms() on Newton.
   */ // }}}
  void test_get_num_platforms_1( )
  {
    T::Newton_clGetPlatformIDs mock;
    TS_ASSERT_EQUALS(get_num_platforms(), 2);
  }
  /** // doc: test_get_platform_ids_1() {{{
   * \brief Test get_platform_ids() - array version.
   */ // }}}
  void test_get_platform_ids_1( )
  {
    T::Newton_clGetPlatformIDs mock;
    cl_platform_id ids[2];
    get_platform_ids(2, ids, NULL);
    TS_ASSERT_EQUALS(ids[0], T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(ids[1], T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_platform_ids_2() {{{
   * \brief Test get_platform_ids() - std::vector version.
   */ // }}}
  void test_get_platform_ids_2( )
  {
    T::Newton_clGetPlatformIDs mock;
    std::vector<cl_platform_id> ids(get_platform_ids());
    TS_ASSERT_EQUALS(ids.size(), 2);
    TS_ASSERT_EQUALS(ids[0], T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(ids[1], T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_platforms_1() {{{
   * \brief Test get_platforms() - std::vector version.
   */ // }}}
  void test_get_platforms_1( )
  {
    T::Newton_clGetPlatformIDs mock;
    Platforms p(get_platforms());
    TS_ASSERT_EQUALS(p.size(), 2);
    TS_ASSERT_EQUALS(static_cast<Platform>(p[0]).id(), T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(static_cast<Platform>(p[1]).id(), T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_platform_ids_zero_num_entries() {{{
   * \brief Test get_platform_ids() - array version with num_entries == 0.
   */ // }}}
  void test_get_platform_ids_zero_num_entries( )
  {
    T::Newton_clGetPlatformIDs mock;
    cl_platform_id ids[2];
    TS_ASSERT_THROWS(get_platform_ids(0, ids, NULL), Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_platform_ids_nulls() {{{
   * \brief Test get_platform_ids() - array version num_platforms == NULL and platforms == NULL.
   */ // }}}
  void test_get_platform_ids_nulls( )
  {
    T::Newton_clGetPlatformIDs mock;
    TS_ASSERT_THROWS(get_platform_ids(2, NULL, NULL), Cl_Error_No<CL_INVALID_VALUE>);
  }
// sorry, but this may irritate OOM instead of throw bad_alloc
//  /** // doc: test_get_platform_ids_negsize() {{{
//   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs()
//   *        returns negative num_platforms.
//   */ // }}}
//  void test_get_platform_ids_negsize( )
//  {
//    T::SizeRet_clGetPlatformIDs mock(-32);
//    TS_ASSERT_THROWS(get_platform_ids(), DIMBO_CL_EXCEPTION(Bad_Alloc));
//  }
  /** // doc: test_invalid_value() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        CL_INVALID_VALUE.
   */ // }}}
  void test_invalid_value( )
  {
    T::ErrRet_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_num_platforms(), Cl_Error_No<CL_INVALID_VALUE>);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), Cl_Error_No<CL_INVALID_VALUE>);
    TS_ASSERT_THROWS(get_platform_ids(), Cl_Error_No<CL_INVALID_VALUE>);
    TS_ASSERT_THROWS(get_platforms(), Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_out_of_host_memory( )
  {
    T::ErrRet_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_num_platforms(), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
    TS_ASSERT_THROWS(get_platform_ids(), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
    TS_ASSERT_THROWS(get_platforms(), Cl_Error_No<CL_OUT_OF_HOST_MEMORY>);
  }
  /** // doc: test_other_error() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        unknown error code.
   */ // }}}
  void test_other_error( )
  {
    T::ErrRet_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_num_platforms(), Other_Cl_Error);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), Other_Cl_Error);
    TS_ASSERT_THROWS(get_platform_ids(), Other_Cl_Error);
    TS_ASSERT_THROWS(get_platforms(), Other_Cl_Error);
  }
};

#endif /* DIMBO_CL_PLATFORMS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
