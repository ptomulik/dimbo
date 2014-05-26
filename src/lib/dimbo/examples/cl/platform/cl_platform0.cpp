/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */

/** // {{{
 * \file dimbo/examples/cl/platform/cl_platform0.cpp
 * \todo Write file documentation
 */ // }}}
/** // {{{
 * \example cl_platform0.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally. We use Dimbo::Cl::Platform_Layer and
 * Dimbo::Cl::Platform_Layer_Info for that.
 */ // }}}
// [Program]
// [Includes]
#include <dimbo/cl/platform_layer.hpp>
#include <dimbo/clinfo/platform_layer_info.hpp>
#include <dimbo/format/clinfo/platform_layer_info.hpp>
#include <iostream>
// [Includes]

int main(int, char const*[])
{
  using namespace Dimbo::Cl;
  // [Query_Print_Info]
  std::cout << query_platform_layer_info(Platform_Layer()) << std::endl;
  // [Query_Print_Info]
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
