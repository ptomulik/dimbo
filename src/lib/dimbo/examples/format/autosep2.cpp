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
 * \file dimbo/examples/format/autosep2.cpp
 * \todo Write documentation
 */ // }}}
/** // example {{{
 * \example autosep2.cpp
 * This example demonstrates how one may use the Dimbo::Format::autosep()
 * function.
 */ // }}}
// [Program]
#include <dimbo/format/autosep.hpp>
#include <iostream>

template <class Iter, class As>
void print_seq(Iter first, Iter last, As const& as)
{
  std::cout << "tab[] = {";
  for(Iter cur(first); cur != last; ++ cur) std::cout << as << *cur;
  std::cout << "}" << std::endl;
}

int main(int, char**)
{
  using Dimbo::Format::autosep;
  int tab[] = {1, 2, 3};
  print_seq(tab, tab + 3, autosep(","));
  return EXIT_SUCCESS;
}
// [Program]


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
