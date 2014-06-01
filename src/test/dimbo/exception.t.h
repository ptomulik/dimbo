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

// dimbo/exception.t.h

/** // doc: dimbo/exception.t.h {{{
 * \file dimbo/exception.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_EXCEPTION_T_H_INCLUDED
#define DIMBO_EXCEPTION_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/exception.hpp>
#include <dimbo/standardized_exception.hpp>

namespace Dimbo { class Exception_TestSuite; }

/** // doc: class Dimbo::Exception_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Exception_TestSuite : public CxxTest::TestSuite
{
  struct Base_Exception : public Exception
    {
      Base_Exception(Debug_Info const& debug_info) : Exception(debug_info) { }
    };
  class Test_Exception1
    : public Standardized_Exception<Base_Exception, std::domain_error>
    {
    public:
      Test_Exception1(Debug_Info const& debug_info)
        : Standardized_Exception(debug_info, "Test exception") { }
    };
  class Test_Exception2
    : public Standardized_Exception<Base_Exception, std::bad_alloc>
    {
    public:
      Test_Exception2(Debug_Info const& debug_info)
        : Standardized_Exception(debug_info) { }
    };
public:
  /** // doc: test_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_catch_exact_exception( )
  {
    TS_ASSERT_THROWS(throw Test_Exception1(DIMBO_HERE), Test_Exception1 const&);
    TS_ASSERT_THROWS(throw Test_Exception2(DIMBO_HERE), Test_Exception2 const&);
  }
  /** // doc: test_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_catch_dimbo_exception( )
  {
    TS_ASSERT_THROWS(throw Test_Exception1(DIMBO_HERE), Exception const&);
    TS_ASSERT_THROWS(throw Test_Exception2(DIMBO_HERE), Exception const&);
  }
  /** // doc: test_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_catch_std_exception( )
  {
    TS_ASSERT_THROWS(throw Test_Exception1(DIMBO_HERE), std::domain_error const&);
    TS_ASSERT_THROWS(throw Test_Exception2(DIMBO_HERE), std::bad_alloc const&);
  }
  /** // doc: test_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_at_file( )
  {
    TS_ASSERT_EQUALS(Test_Exception1(DIMBO_HERE).debug_info().file(), DIMBO_HERE.file());
    TS_ASSERT_EQUALS(Test_Exception2(DIMBO_HERE).debug_info().file(), DIMBO_HERE.file());
  }
  /** // doc: test_5() {{{
   * \todo Write documentation
   */ // }}}
  void test_at_line( )
  {
    TS_ASSERT_EQUALS(Test_Exception1(DIMBO_HERE).debug_info().line(), DIMBO_HERE.line());
    TS_ASSERT_EQUALS(Test_Exception2(DIMBO_HERE).debug_info().line(), DIMBO_HERE.line());
  }
  /** // doc: test_6() {{{
   * \todo Write documentation
   */ // }}}
  void test_at_function( )
  {
    TS_ASSERT_EQUALS(Test_Exception1(DIMBO_HERE).debug_info().function(), DIMBO_HERE.function());
    TS_ASSERT_EQUALS(Test_Exception2(DIMBO_HERE).debug_info().function(), DIMBO_HERE.function());
  }
  /** // doc: test_7() {{{
   * \todo Write documentation
   */ // }}}
  void test_std_except( )
  {
    TS_ASSERT_THROWS_NOTHING(Test_Exception1(DIMBO_HERE).std_except());
    TS_ASSERT_THROWS_NOTHING(Test_Exception2(DIMBO_HERE).std_except());
  }
};

#endif /* DIMBO_EXCEPTION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
