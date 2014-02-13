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

// dimbo/cl/platform_query.cpp

/** // doc: dimbo/cl/platform_query.cpp {{{
 * @file dimbo/cl/platform_query.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/cl/platform_query.hpp>
#include <CL/cl.h>

namespace Dimbo {
namespace Cl {
Platform_Query::
Platform_Query()
{
  this->_init_query();
}

Platform_Query::
~Platform_Query()
{
}

void Platform_Query::
_init_query()
{
  this->select_all();
}

void Platform_Query::
select_all()
{
  this -> select_id();
  this -> select_profile();
  this -> select_version();
  this -> select_name();
  this -> select_vendor();
  this -> select_extensions();
}

void Platform_Query::
select_none()
{
  this -> select_id(false);
  this -> select_profile(false);
  this -> select_version(false);
  this -> select_name(false);
  this -> select_vendor(false);
  this -> select_extensions(false);
}
} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
