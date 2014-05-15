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

// dimbo/test/unit/dimbo/cl/platform_query.t.h

/** // doc: dimbo/test/unit/dimbo/cl/platform_query.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/platform_query.t.h
 * \brief Unit tests for Dimbo::Cl::Platform_Query
 */ // }}}
#ifndef DIMBO_CL_PLATFORM_QUERY_T_H_INCLUDED
#define DIMBO_CL_PLATFORM_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/platform_query.hpp>

namespace Dimbo { namespace Cl { class Platform_Query_TestSuite; } }

/** // doc: class Dimbo::Cl::Platform_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Platform_Query_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_ctor() {{{
   * \brief Test default constructor
   */ // }}}
  void test_default_ctor( )
  {
    Platform_Query q;
    TS_ASSERT(q.id_selected());
    TS_ASSERT(q.profile_selected());
    TS_ASSERT(q.version_selected());
    TS_ASSERT(q.vendor_selected());
    TS_ASSERT(q.extensions_selected());
  }
  /** // doc: test_select_id() {{{
   * \brief Test select_id() method.
   */ // }}}
  void test_select_id( )
  {
    Platform_Query q;
    q.select_id(false);
    TS_ASSERT(!q.id_selected());
    q.select_id(true);
    TS_ASSERT(q.id_selected());
  }
  /** // doc: test_select_profile() {{{
   * \todo Write documentation
   * \brief Test select_profile() method.
   */ // }}}
  void test_select_profile( )
  {
    Platform_Query q;
    q.select_profile(false);
    TS_ASSERT(!q.profile_selected());
    q.select_profile(true);
    TS_ASSERT(q.profile_selected());
  }
  /** // doc: test_select_version() {{{
   * \todo Write documentation
   * \brief Test select_version() method.
   */ // }}}
  void test_select_version( )
  {
    Platform_Query q;
    q.select_version(false);
    TS_ASSERT(!q.version_selected());
    q.select_version(true);
    TS_ASSERT(q.version_selected());
  }
  /** // doc: test_select_vendor() {{{
   * \brief Test select_vendor() method.
   */ // }}}
  void test_select_vendor( )
  {
    Platform_Query q;
    q.select_vendor(false);
    TS_ASSERT(!q.vendor_selected());
    q.select_vendor(true);
    TS_ASSERT(q.vendor_selected());
  }
  /** // doc: test_select_extensions() {{{
   * \brief Test select_extensions() method.
   */ // }}}
  void test_select_extensions( )
  {
    Platform_Query q;
    q.select_extensions(false);
    TS_ASSERT(!q.extensions_selected());
    q.select_extensions(true);
    TS_ASSERT(q.extensions_selected());
  }
};

#endif /* DIMBO_CL_PLATFORM_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
