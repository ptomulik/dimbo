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

// dimbo/protobuf/clinfo/platform_info.t.h

/** // doc: dimbo/protobuf/clinfo/platform_info.t.h {{{
 * \file dimbo/protobuf/clinfo/platform_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_PLATFORM_INFO_T_H_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_PLATFORM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/protobuf/clinfo/platform_info.hpp>
#include <dimbo/clinfo/platform_info_fixtures.hpp>
#include <dimbo/protobuf/clinfo/platform_info_fixtures.hpp>

namespace Dimbo { namespace Protobuf { namespace Clinfo { class Platform_Info_TestSuite; } } }

/** // doc: class Dimbo::Clinfo::Platform_Info_TestSuite {{{
 * \brief Unit tests for Dimbo::Clinfo::Platform_Info class
 */ // }}}
class Dimbo::Protobuf::Clinfo::Platform_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_write_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_empty()
  {
    Platform_Info buf;

    write(buf,Dimbo::Clinfo::Platform_Info());

    TS_ASSERT(!buf.has_id());
    TS_ASSERT(!buf.has_profile());
    TS_ASSERT(!buf.has_version());
    TS_ASSERT(!buf.has_name());
    TS_ASSERT(!buf.has_vendor());
    TS_ASSERT(!buf.has_extensions());
  }
  /** // doc: test_write_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_1()
  {
    Platform_Info buf;
    Platform_Info fix(Platform_Info_Fixtures::_1());

    write(buf,Dimbo::Clinfo::Platform_Info_Fixtures::_1());

    TS_ASSERT_EQUALS(buf.id(), fix.id());
    TS_ASSERT_EQUALS(buf.profile(), fix.profile());
    TS_ASSERT_EQUALS(buf.version(), fix.version());
    TS_ASSERT_EQUALS(buf.name(), fix.name());
    TS_ASSERT_EQUALS(buf.vendor(), fix.vendor());
    TS_ASSERT_EQUALS(buf.extensions(), fix.extensions());
  }
  /** // doc: test_read_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_empty()
  {
    Platform_Info buf;
    Dimbo::Clinfo::Platform_Info info;

    read(buf,info);

    TS_ASSERT(!info.has_id());
    TS_ASSERT(!info.has_profile());
    TS_ASSERT(!info.has_version());
    TS_ASSERT(!info.has_name());
    TS_ASSERT(!info.has_vendor());
    TS_ASSERT(!info.has_extensions());
  }
  /** // doc: test_read_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_1()
  {
    Dimbo::Clinfo::Platform_Info info;

    read(Platform_Info_Fixtures::_1(), info);

    TS_ASSERT((info == Dimbo::Clinfo::Platform_Info_Fixtures::_1()));
  }
};

#endif /* DIMBO_PROTOBUF_CLINFO_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
