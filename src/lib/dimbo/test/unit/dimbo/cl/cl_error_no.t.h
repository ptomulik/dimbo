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

// dimbo/test/unit/dimbo/cl/cl_error_no.t.h

/** // doc: dimbo/test/unit/dimbo/cl/cl_error_no.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/cl_error_no.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CL_ERROR_NO_T_H_INCLUDED
#define DIMBO_CL_CL_ERROR_NO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/cl_error_no.hpp>
#include <type_traits>

namespace Dimbo { namespace Cl { class Cl_Error_No_TestSuite; } }

/** // doc: class Dimbo::Cl::Cl_Error_No_TestSuite {{{
 * \brief Test suite for Dimbo::Cl::Cl_Error_No
 *
 * Actually we just check whether the isolated code form
 * dimbo/cl/cl_error_no.hpp compiles.
 *
 */ // }}}
class Dimbo::Cl::Cl_Error_No_TestSuite : public CxxTest::TestSuite
{
public:
  void test_is_default_constructible(void)
  { TS_ASSERT((std::is_default_constructible<Cl_Error_No<0> >::value)); }
  void test_is_copy_constructible(void)
  { TS_ASSERT((std::is_copy_constructible<Cl_Error_No<0> >::value)); }
};

#endif /* DIMBO_CL_CL_ERROR_NO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
