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

// dimbo/test/unit/dimbo/exception.t.h

/** // doc: dimbo/test/unit/dimbo/exception.t.h {{{
 * \file dimbo/test/unit/dimbo/exception.t.h
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
      Base_Exception(Src_At const& at) : Exception(at) { }
    };
  class Test_Exception 
    : public Standardized_Exception<Base_Exception, std::domain_error>
    {
    public:
      Test_Exception(Src_At const& at)
        : Standardized_Exception(at, "Test exception") { }
    };
public:
  /** // doc: test_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_1( )
  {
    TS_ASSERT_THROWS(throw Test_Exception(DIMBO_HERE), Test_Exception const&);
  }
  /** // doc: test_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_2( )
  {
    TS_ASSERT_THROWS(throw Test_Exception(DIMBO_HERE), Exception const&);
  }
  /** // doc: test_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_3( )
  {
    TS_ASSERT_THROWS(throw Test_Exception(DIMBO_HERE), std::domain_error const&);
  }
  /** // doc: test_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_4( )
  {
    TS_ASSERT_EQUALS(Test_Exception(DIMBO_HERE).at().file(), DIMBO_HERE.file());
  }
  /** // doc: test_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_5( )
  {
    TS_ASSERT_EQUALS(Test_Exception(DIMBO_HERE).at().line(), DIMBO_HERE.line());
  }
  /** // doc: test_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_6( )
  {
    TS_ASSERT_EQUALS(Test_Exception(DIMBO_HERE).at().function(), DIMBO_HERE.function());
  }
};

#endif /* DIMBO_EXCEPTION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
