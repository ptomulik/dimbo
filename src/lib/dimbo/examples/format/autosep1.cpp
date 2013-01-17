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

/** // doc: unit.cpp {{{
 * \file dimbo/examples/format/autosep1.cpp
 * \todo Write documentation
 */ // }}}
/** // example {{{
 * \example autosep1.cpp
 * This example demonstrates how one may use the Dimbo::Format::Autosep object
 * to format sequences when printing them to a stream.
 */ // }}}
// [Program]
#include <dimbo/format/autosep.hpp>
#include <iostream>
int main(int, char**)
{
  using Dimbo::Format::Autosep;
  int tab[] = {1, 2, 3};
  Autosep<const char*> as(", ");
  std::cout << "tab[] = {";
  for(int i = 0; i < (int)(sizeof(tab)/sizeof(*tab)); ++i) {
    std::cout << as;
    std::cout << tab[i];
  }
  std::cout << "}" << std::endl;
  return EXIT_SUCCESS;
}
// [Program]


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
