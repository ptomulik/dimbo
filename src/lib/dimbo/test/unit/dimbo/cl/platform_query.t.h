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

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Cl { class Platform_Query_TestSuite; } }

/** // doc: class Dimbo::Cl::Platform_Query_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Cl::Platform_Query_TestSuite : public CxxTest::TestSuite
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
    TS_ASSERT(Platform_Query().vendor_selected());
    TS_ASSERT(Platform_Query().extensions_selected());
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
  /** // doc: test_select_name() {{{
   * \todo Write documentation
   * \brief Test select_name() method.
   */ // }}}
  void test_select_name( )
  {
    Platform_Query q;
    q.select_name(false);
    TS_ASSERT(!q.name_selected());
    q.select_name(true);
    TS_ASSERT(q.name_selected());
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
  /** // doc: test_serialize_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_1( )
  {
    Platform_Query a;
    Platform_Query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << a;

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    TS_ASSERT_EQUALS(a, b);
  }
  /** // doc: test_eq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op( )
  {
    Platform_Query q1;
    Platform_Query q2;
    TS_ASSERT(q1 == q2);

    q1.select_id(false);
    TS_ASSERT(!(q1 == q2));

    q1 = q2;
    TS_ASSERT(q1 == q2);
    q1.select_profile(false);
    TS_ASSERT(!(q1 == q2));

    q1 = q2;
    TS_ASSERT(q1 == q2);
    q1.select_version(false);
    TS_ASSERT(!(q1 == q2));

    q1 = q2;
    TS_ASSERT(q1 == q2);
    q1.select_name(false);
    TS_ASSERT(!(q1 == q2));

    q1 = q2;
    TS_ASSERT(q1 == q2);
    q1.select_vendor(false);
    TS_ASSERT(!(q1 == q2));

    q1 = q2;
    TS_ASSERT(q1 == q2);
    q1.select_extensions(false);
    TS_ASSERT(!(q1 == q2));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op( )
  {
    Platform_Query q1;
    Platform_Query q2;

    TS_ASSERT(!(q1 != q2));
    q1.select_id(false);
    TS_ASSERT(q1 != q2);

    q1 = q2;
    TS_ASSERT(!(q1 != q2));
    q1.select_profile(false);
    TS_ASSERT(q1 != q2);

    q1 = q2;
    TS_ASSERT(!(q1 != q2));
    q1.select_version(false);
    TS_ASSERT(q1 != q2);

    q1 = q2;
    TS_ASSERT(!(q1 != q2));
    q1.select_name(false);
    TS_ASSERT(q1 != q2);

    q1 = q2;
    TS_ASSERT(!(q1 != q2));
    q1.select_vendor(false);
    TS_ASSERT(q1 != q2);

    q1 = q2;
    TS_ASSERT(!(q1 != q2));
    q1.select_extensions(false);
    TS_ASSERT(q1 != q2);
  }

  /** // doc: test_write_protobuf_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_protobuf_1( )
  {
    Platform_Query q;
    Dimbo::Protobuf::Cl::Platform_Query buff;

    q.write(buff);

    // With bare defaults, the buffer should be empty.
    TS_ASSERT(!buff.has_select_id());
    TS_ASSERT(!buff.has_select_profile());
    TS_ASSERT(!buff.has_select_version());
    TS_ASSERT(!buff.has_select_name());
    TS_ASSERT(!buff.has_select_vendor());
    TS_ASSERT(!buff.has_select_extensions());
  }

  /** // doc: test_write_protobuf_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_protobuf_2( )
  {
    Platform_Query q;
    Dimbo::Protobuf::Cl::Platform_Query buff;

    q.select_none();
    q.write(buff);

    // With bare defaults, the buffer should be empty.
    TS_ASSERT(buff.has_select_id() && !buff.select_id());
    TS_ASSERT(buff.has_select_profile() && !buff.select_profile());
    TS_ASSERT(buff.has_select_version() && !buff.select_version());
    TS_ASSERT(buff.has_select_name() && !buff.select_name());
    TS_ASSERT(buff.has_select_vendor() && !buff.select_vendor());
    TS_ASSERT(buff.has_select_extensions() && !buff.select_extensions());
  }

  /** // doc: test_read_protobuf_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_protobuf_1( )
  {
    Platform_Query q;
    Dimbo::Protobuf::Cl::Platform_Query buff;

    q.select_none(); // change from defaults
    q.read(buff);

    // With empty buffer we should be set back to bare defaults
    TS_ASSERT(q.id_selected());
    TS_ASSERT(q.profile_selected());
    TS_ASSERT(q.version_selected());
    TS_ASSERT(q.name_selected());
    TS_ASSERT(q.vendor_selected());
    TS_ASSERT(q.extensions_selected());
  }

  /** // doc: test_read_protobuf_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_protobuf_2( )
  {
    Platform_Query q;
    Platform_Query empty;
    Dimbo::Protobuf::Cl::Platform_Query buff;

    buff.set_select_id(false);
    buff.set_select_profile(false);
    buff.set_select_version(false);
    buff.set_select_name(false);
    buff.set_select_vendor(false);
    buff.set_select_extensions(false);

    q.read(buff);
    empty.select_none();

    TS_ASSERT(q == empty);
  }
};

#endif /* DIMBO_CL_PLATFORM_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
