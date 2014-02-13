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

// dimbo/app/clinfo/main.hpp

/** // doc: dimbo/app/clinfo/main.hpp {{{
 * \file dimbo/app/clinfo/main.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_CLINFO_MAIN_HPP_INCLUDED
#define DIMBO_APP_CLINFO_MAIN_HPP_INCLUDED

#include <dimbo/app/main.hpp>
#include <dimbo/app/clinfo/options_description.hpp>
#include <dimbo/app/options/options_map.hpp>
#include <string>
#include <vector>

namespace Dimbo {
namespace App {
namespace Clinfo {

/** // doc: class Main {{{
 * \todo Write documentation
 */ // }}}
class Main
  : public Dimbo::App::Main
{
public:
  typedef Dimbo::App::Options::Options_Map Options_Map;
public:
  /** // doc: ~Main() {{{
   * \todo Write documentation for class Main
   */ // }}}
  virtual ~Main();
  /** // doc: Main() {{{
   * \todo Write documentation
   */ // }}}
  Main();
  /** // doc: Main(argc, argv) {{{
   * \todo Write documentation
   */ // }}}
  Main(int argc, char const* argv[]);
  /** // doc: init() {{{
   * \todo Write documentation
   */ // }}}
  virtual void init(int argc, char const* argv[]) ;
  /** // doc: run() {{{
   * \todo Write documentation
   */ // }}}
  virtual int run( ) ;
  /** // doc: options_description() {{{
   * \todo Write documentation
   */ // }}}
  inline Options_Description const& options_description() const
  {
    return this->_options_description;
  }
  /** // doc: options_map() {{{
   * \todo Write documentation
   */ // }}}
  inline Options_Map const& options_map() const
  {
    return this->_options_map;
  }
  /** // doc: process_options(om) {{{
   * \todo Write documentation
   */ // }}}
private:
  void _init_main( );
private:
  Options_Description _options_description;
  Options_Map _options_map;
};

int run(int argc, char const* argv[]);
} /* namespace Clinfo */
} /* namespace App */
} /* namespace Dimbo */

#endif /* DIMBO_APP_CLINFO_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
