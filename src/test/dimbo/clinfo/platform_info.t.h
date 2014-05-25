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

// dimbo/clinfo/platform_info.t.h

/** // doc: dimbo/clinfo/platform_info.t.h {{{
 * \file dimbo/clinfo/platform_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_INFO_T_H_INCLUDED
#define DIMBO_CLINFO_PLATFORM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/clinfo/platform_info.hpp>
#include <dimbo/clinfo/platform_info_fixtures.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Clinfo { class Platform_Info_TestSuite; } }

/** // doc: class Dimbo::Clinfo::Platform_Info_TestSuite {{{
 * \brief Unit tests for Dimbo::Clinfo::Platform_Info class
 */ // }}}
class Dimbo::Clinfo::Platform_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(!Platform_Info().has_id());
    TS_ASSERT(!Platform_Info().has_profile());
    TS_ASSERT(!Platform_Info().has_version());
    TS_ASSERT(!Platform_Info().has_name());
    TS_ASSERT(!Platform_Info().has_vendor());
    TS_ASSERT(!Platform_Info().has_extensions());
  }
  /** // doc: test_getter_exceptions() {{{
   * \todo Write documentation
   */ // }}}
  void test_getter_exceptions( )
  {
    TS_ASSERT_THROWS(Platform_Info().id(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Platform_Info().profile(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Platform_Info().version(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Platform_Info().name(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Platform_Info().vendor(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
    TS_ASSERT_THROWS(Platform_Info().extensions(), DIMBO_CLINFO_EXCEPTION(Uninitialized_Value));
  }
  /** // doc: test_set_get() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get( )
  {
    TS_ASSERT_EQUALS(Platform_Info().set_id(0x12345ul).id(), 0x12345ul);
    TS_ASSERT_EQUALS(Platform_Info().set_profile("profile").profile(), "profile");
    TS_ASSERT_EQUALS(Platform_Info().set_version("version").version(), "version");
    TS_ASSERT_EQUALS(Platform_Info().set_name("name").name(), "name");
    TS_ASSERT_EQUALS(Platform_Info().set_vendor("vendor").vendor(), "vendor");
    TS_ASSERT_EQUALS(Platform_Info().set_extensions("extensions").extensions(), "extensions");
  }
  /** // doc: test_set_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_has_1( )
  {
    TS_ASSERT(Platform_Info().set_id(0x12345ul).has_id());
    TS_ASSERT(Platform_Info().set_profile("profile").has_profile());
    TS_ASSERT(Platform_Info().set_version("version").has_version());
    TS_ASSERT(Platform_Info().set_name("name").has_name());
    TS_ASSERT(Platform_Info().set_vendor("vendor").has_vendor());
    TS_ASSERT(Platform_Info().set_extensions("extensions").has_extensions());
  }
  /** // doc: test_set_has_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_has_2( )
  {
    Platform_Info const infos[2] = { Platform_Info_Fixtures::_1(), Platform_Info_Fixtures::_2() };
    for(Platform_Info const* info = infos; info < infos + 2; ++info)
    {
      TS_ASSERT(info->has_id());
      TS_ASSERT(info->has_profile());
      TS_ASSERT(info->has_version());
      TS_ASSERT(info->has_name());
      TS_ASSERT(info->has_vendor());
      TS_ASSERT(info->has_extensions());
    }
  }
  /** // doc: test_clear_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_has_1( )
  {
    TS_ASSERT(!Platform_Info().set_id(0x12345ul).clear_id().has_id());
    TS_ASSERT(!Platform_Info().set_profile("profile").clear_profile().has_profile());
    TS_ASSERT(!Platform_Info().set_version("version").clear_version().has_version());
    TS_ASSERT(!Platform_Info().set_name("name").clear_name().has_name());
    TS_ASSERT(!Platform_Info().set_vendor("vendor").clear_vendor().has_vendor());
    TS_ASSERT(!Platform_Info().set_extensions("extensions").clear_extensions().has_extensions());
  }
  /** // doc: test_clear_has_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_has_2( )
  {
    Platform_Info info(Platform_Info_Fixtures::_1());

    info.clear();

    TS_ASSERT(!info.has_id());
    TS_ASSERT(!info.has_profile());
    TS_ASSERT(!info.has_version());
    TS_ASSERT(!info.has_name());
    TS_ASSERT(!info.has_vendor());
    TS_ASSERT(!info.has_extensions());
  }
  /** // doc: test_eq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_1()
  {
    TS_ASSERT((Platform_Info() == Platform_Info()));
  }
  /** // doc: test_eq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_2()
  {
    TS_ASSERT(!(Platform_Info().set_id(0x12345ul) == Platform_Info()));
    TS_ASSERT(!(Platform_Info().set_profile("profile") == Platform_Info()));
    TS_ASSERT(!(Platform_Info().set_version("version") == Platform_Info()));
    TS_ASSERT(!(Platform_Info().set_name("name") == Platform_Info()));
    TS_ASSERT(!(Platform_Info().set_vendor("vendor") == Platform_Info()));
    TS_ASSERT(!(Platform_Info().set_extensions("extensions") == Platform_Info()));
  }
  /** // doc: test_eq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_3()
  {
    TS_ASSERT(!(Platform_Info().set_id(0x12345ul) == Platform_Info().set_id(0x56798ul)));
    TS_ASSERT(!(Platform_Info().set_profile("profile") == Platform_Info().set_profile("xxx")));
    TS_ASSERT(!(Platform_Info().set_version("version") == Platform_Info().set_version("xxx")));
    TS_ASSERT(!(Platform_Info().set_name("name") == Platform_Info().set_name("xxx")));
    TS_ASSERT(!(Platform_Info().set_vendor("vendor") == Platform_Info().set_vendor("xxx")));
    TS_ASSERT(!(Platform_Info().set_extensions("extensions") == Platform_Info().set_extensions("xxx")));
  }
  /** // doc: test_eq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_4()
  {
    TS_ASSERT((Platform_Info().set_id(0x12345ul) == Platform_Info().set_id(0x12345ul)));
    TS_ASSERT((Platform_Info().set_profile("profile") == Platform_Info().set_profile("profile")));
    TS_ASSERT((Platform_Info().set_version("version") == Platform_Info().set_version("version")));
    TS_ASSERT((Platform_Info().set_name("name") == Platform_Info().set_name("name")));
    TS_ASSERT((Platform_Info().set_vendor("vendor") == Platform_Info().set_vendor("vendor")));
    TS_ASSERT((Platform_Info().set_extensions("extensions") == Platform_Info().set_extensions("extensions")));
  }
  /** // doc: test_neq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_1()
  {
    TS_ASSERT(!(Platform_Info() != Platform_Info()));
  }
  /** // doc: test_neq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_2()
  {
    TS_ASSERT((Platform_Info().set_id(0x12345ul) != Platform_Info()));
    TS_ASSERT((Platform_Info().set_profile("profile") != Platform_Info()));
    TS_ASSERT((Platform_Info().set_version("version") != Platform_Info()));
    TS_ASSERT((Platform_Info().set_name("name") != Platform_Info()));
    TS_ASSERT((Platform_Info().set_vendor("vendor") != Platform_Info()));
    TS_ASSERT((Platform_Info().set_extensions("extensions") != Platform_Info()));
  }
  /** // doc: test_neq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_3()
  {
    TS_ASSERT((Platform_Info().set_id(0x12345ul) != Platform_Info().set_id(0x56798ul)));
    TS_ASSERT((Platform_Info().set_profile("profile") != Platform_Info().set_profile("xxx")));
    TS_ASSERT((Platform_Info().set_version("version") != Platform_Info().set_version("xxx")));
    TS_ASSERT((Platform_Info().set_name("name") != Platform_Info().set_name("xxx")));
    TS_ASSERT((Platform_Info().set_vendor("vendor") != Platform_Info().set_vendor("xxx")));
    TS_ASSERT((Platform_Info().set_extensions("extensions") != Platform_Info().set_extensions("xxx")));
  }
  /** // doc: test_neq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_4()
  {
    TS_ASSERT(!(Platform_Info().set_id(0x12345ul) != Platform_Info().set_id(0x12345ul)));
    TS_ASSERT(!(Platform_Info().set_profile("profile") != Platform_Info().set_profile("profile")));
    TS_ASSERT(!(Platform_Info().set_version("version") != Platform_Info().set_version("version")));
    TS_ASSERT(!(Platform_Info().set_name("name") != Platform_Info().set_name("name")));
    TS_ASSERT(!(Platform_Info().set_vendor("vendor") != Platform_Info().set_vendor("vendor")));
    TS_ASSERT(!(Platform_Info().set_extensions("extensions") != Platform_Info().set_extensions("extensions")));
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor()
  {
    Platform_Info a(Platform_Info_Fixtures::_1());
    Platform_Info b(a);
    TS_ASSERT((a == b));
  }
  /** // doc: test_assign_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign_op()
  {
    Platform_Info a(Platform_Info_Fixtures::_1());
    Platform_Info b;
    b = a;
    TS_ASSERT((a == b));
  }
};

#endif /* DIMBO_CLINFO_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
