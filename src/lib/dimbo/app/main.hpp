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

// dimbo/app/main.hpp

/** // doc: dimbo/app/main.hpp {{{
 * \file dimbo/app/main.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_MAIN_HPP_INCLUDED
#define DIMBO_APP_MAIN_HPP_INCLUDED

namespace Dimbo {
namespace App {

/** // doc: class Main {{{
 * \todo Write documentation
 */ // }}}
class Main
{
public:
  /** // doc: ~Main() {{{
   * \todo Write documentation for class Main
   */ // }}}
  virtual ~Main();
  /** // doc: Main() {{{
   * \todo Write documentation
   */ // }}}
  Main();
  /** // doc: run() {{{
   * \todo Write documentation
   */ // }}}
  virtual void init(int argc, char const* argv[]) = 0;
  /** // doc: run() {{{
   * \todo Write documentation
   */ // }}}
  virtual int run( ) = 0;
};
} /* namespace App */
} /* namespace Dimbo */

#endif /* DIMBO_APP_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
