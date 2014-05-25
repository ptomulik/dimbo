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

// dimbo/protobuf/clinfo/platform_query.t.h

/** // doc: dimbo/protobuf/clinfo/platform_query.t.h {{{
 * \file dimbo/protobuf/clinfo/platform_query.t.h
 * \brief Unit tests for Dimbo::Clinfo::Platform_Query
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_PLATFORM_QUERY_T_H_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_PLATFORM_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/protobuf/clinfo/platform_query.hpp>

namespace Dimbo { namespace Protobuf { namespace Clinfo { class Platform_Query_TestSuite; } } }

/** // doc: class Dimbo::Clinfo::Platform_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Protobuf::Clinfo::Platform_Query_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_write_protobuf_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_protobuf_1( )
  {
    Platform_Query buf;
    Dimbo::Clinfo::Platform_Query query;

    write(buf,query);

    // With bare defaults, the buffer should be empty.
    TS_ASSERT(!buf.has_id_selected());
    TS_ASSERT(!buf.has_profile_selected());
    TS_ASSERT(!buf.has_version_selected());
    TS_ASSERT(!buf.has_name_selected());
    TS_ASSERT(!buf.has_vendor_selected());
    TS_ASSERT(!buf.has_extensions_selected());
  }
  /** // doc: test_write_protobuf_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_protobuf_2( )
  {
    Platform_Query buf;
    Dimbo::Clinfo::Platform_Query query(false);

    write(buf,query);

    // With bare defaults, the buffer should be empty.
    TS_ASSERT(buf.has_id_selected() && !buf.id_selected());
    TS_ASSERT(buf.has_profile_selected() && !buf.profile_selected());
    TS_ASSERT(buf.has_version_selected() && !buf.version_selected());
    TS_ASSERT(buf.has_name_selected() && !buf.name_selected());
    TS_ASSERT(buf.has_vendor_selected() && !buf.vendor_selected());
    TS_ASSERT(buf.has_extensions_selected() && !buf.extensions_selected());
  }
  /** // doc: test_read_protobuf_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_protobuf_1( )
  {
    Platform_Query buf;
    Dimbo::Clinfo::Platform_Query query(false);

    read(buf,query);

    // With empty buffer we should be set back to default query
    TS_ASSERT((query == Dimbo::Clinfo::Platform_Query()));
  }

  /** // doc: test_read_protobuf_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_protobuf_2( )
  {
    Platform_Query buf;
    Dimbo::Clinfo::Platform_Query query(true);

    // unset all attributes
    buf.set_id_selected(false);
    buf.set_profile_selected(false);
    buf.set_version_selected(false);
    buf.set_name_selected(false);
    buf.set_vendor_selected(false);
    buf.set_extensions_selected(false);

    read(buf,query);

    TS_ASSERT((query == Dimbo::Clinfo::Platform_Query(false)));
  }
};

#endif /* DIMBO_PROTOBUF_CLINFO_PLATFORM_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
