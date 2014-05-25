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

// dimbo/clinfo/platform_query.t.h

/** // doc: dimbo/clinfo/platform_query.t.h {{{
 * \file dimbo/clinfo/platform_query.t.h
 * \brief Unit tests for Dimbo::Clinfo::Platform_Query
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_QUERY_T_H_INCLUDED
#define DIMBO_CLINFO_PLATFORM_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/clinfo/platform_query.hpp>
#include <dimbo/clinfo/platform_query_fixtures.hpp>

namespace Dimbo { namespace Clinfo { class Platform_Query_TestSuite; } }

/** // doc: class Dimbo::Clinfo::Platform_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Clinfo::Platform_Query_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \brief Test default constructor
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(Platform_Query().id_selected());
    TS_ASSERT(Platform_Query().profile_selected());
    TS_ASSERT(Platform_Query().version_selected());
    TS_ASSERT(Platform_Query().name_selected());
    TS_ASSERT(Platform_Query().vendor_selected());
    TS_ASSERT(Platform_Query().extensions_selected());
  }
  /** // doc: test_ctor_true() {{{
   * \brief Test default constructor
   */ // }}}
  void test_ctor_true( )
  {
    TS_ASSERT(Platform_Query(true).id_selected());
    TS_ASSERT(Platform_Query(true).profile_selected());
    TS_ASSERT(Platform_Query(true).version_selected());
    TS_ASSERT(Platform_Query(true).name_selected());
    TS_ASSERT(Platform_Query(true).vendor_selected());
    TS_ASSERT(Platform_Query(true).extensions_selected());
  }
  /** // doc: test_ctor_false() {{{
   * \brief Test default constructor
   */ // }}}
  void test_ctor_false( )
  {
    TS_ASSERT(!Platform_Query(false).id_selected());
    TS_ASSERT(!Platform_Query(false).profile_selected());
    TS_ASSERT(!Platform_Query(false).version_selected());
    TS_ASSERT(!Platform_Query(false).name_selected());
    TS_ASSERT(!Platform_Query(false).vendor_selected());
    TS_ASSERT(!Platform_Query(false).extensions_selected());
  }
  /** // doc: test_set_get_1() {{{
   * \brief Test set_get_1() method.
   */ // }}}
  void test_set_get_1( )
  {
    TS_ASSERT(!Platform_Query(true).select_id(false).id_selected());
    TS_ASSERT(!Platform_Query(true).select_profile(false).profile_selected());
    TS_ASSERT(!Platform_Query(true).select_version(false).version_selected());
    TS_ASSERT(!Platform_Query(true).select_name(false).name_selected());
    TS_ASSERT(!Platform_Query(true).select_vendor(false).vendor_selected());
    TS_ASSERT(!Platform_Query(true).select_extensions(false).extensions_selected());
  }
  /** // doc: test_eq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op( )
  {
    TS_ASSERT(!(Platform_Query(true).select_id(false) == Platform_Query(true)));
    TS_ASSERT(!(Platform_Query(true).select_profile(false) == Platform_Query(true)));
    TS_ASSERT(!(Platform_Query(true).select_version(false) == Platform_Query(true)));
    TS_ASSERT(!(Platform_Query(true).select_name(false) == Platform_Query(true)));
    TS_ASSERT(!(Platform_Query(true).select_vendor(false) == Platform_Query(true)));
    TS_ASSERT(!(Platform_Query(true).select_extensions(false) == Platform_Query(true)));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op( )
  {
    TS_ASSERT((Platform_Query(true).select_id(false) != Platform_Query(true)));
    TS_ASSERT((Platform_Query(true).select_profile(false) != Platform_Query(true)));
    TS_ASSERT((Platform_Query(true).select_version(false) != Platform_Query(true)));
    TS_ASSERT((Platform_Query(true).select_name(false) != Platform_Query(true)));
    TS_ASSERT((Platform_Query(true).select_vendor(false) != Platform_Query(true)));
    TS_ASSERT((Platform_Query(true).select_extensions(false) != Platform_Query(true)));
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_all( )
  {
    TS_ASSERT((Platform_Query(false).select_all().id_selected()));
    TS_ASSERT((Platform_Query(false).select_all().profile_selected()));
    TS_ASSERT((Platform_Query(false).select_all().version_selected()));
    TS_ASSERT((Platform_Query(false).select_all().name_selected()));
    TS_ASSERT((Platform_Query(false).select_all().vendor_selected()));
    TS_ASSERT((Platform_Query(false).select_all().extensions_selected()));
  }
  /** // doc: test_select_none() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_none( )
  {
    TS_ASSERT(!(Platform_Query(true).select_none().id_selected()));
    TS_ASSERT(!(Platform_Query(true).select_none().profile_selected()));
    TS_ASSERT(!(Platform_Query(true).select_none().version_selected()));
    TS_ASSERT(!(Platform_Query(true).select_none().name_selected()));
    TS_ASSERT(!(Platform_Query(true).select_none().vendor_selected()));
    TS_ASSERT(!(Platform_Query(true).select_none().extensions_selected()));
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_default( )
  {
    TS_ASSERT((Platform_Query(false).select_default() == Platform_Query()));
    TS_ASSERT((Platform_Query(true).select_default() == Platform_Query()));
  }
};

#endif /* DIMBO_CLINFO_PLATFORM_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
