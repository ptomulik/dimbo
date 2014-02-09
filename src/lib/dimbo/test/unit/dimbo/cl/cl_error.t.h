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

// dimbo/test/unit/cl_error.t.h

/** // doc: dimbo/test/unit/cl_error.t.h {{{ 
 * \file dimbo/test/unit/cl_error.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CL_ERROR_T_H_INCLUDED
#define DIMBO_CL_CL_ERROR_T_H_INCLUDED

#include <dimbo/cl/cl_error.hpp>
#include <cxxtest/TestSuite.h>
#include <type_traits>

namespace Dimbo { namespace Cl { class Cl_Error_TestSuite; } }

class Dimbo::Cl::Cl_Error_TestSuite : public CxxTest::TestSuite
{
public:
  void test_is_derived_from_exception(void)
  { TS_ASSERT((std::is_base_of<Dimbo::Cl::Exception, Dimbo::Cl::Cl_Error>::value)); }
  void test_has_virtual_destructor(void)
  { TS_ASSERT((std::has_virtual_destructor<Dimbo::Cl::Cl_Error>::value)); }
  void test_is_abstract(void)
  { TS_ASSERT((std::is_abstract<Dimbo::Cl::Cl_Error>::value)); }
};

#endif /* DIMBO_CL_CL_ERROR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
