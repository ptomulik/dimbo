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

// dimbo/examples/exception/new_exception.cpp

/** // {{{
 * \file dimbo/examples/exception/new_exception.cpp
 * \todo Write documentation
 */ // }}}
/** // {{{
 * \example new_exception.cpp
 * This is an example of how to start new branch of exceptions and define
 * new %Dimbo exceptions within this branch.
 */ // }}}
// [Includes]
#include <dimbo/exception.hpp>
#include <dimbo/standardized_exception.hpp>
#include <iostream>
#include <stdexcept>
// [Includes]

// [Namespaces_Start]
namespace Dimbo {
namespace Foo {
// [Namespaces_Start]
// [Exception]
/**
 * \brief Exception class recognized at user's side.
 */
struct Exception : public Dimbo::Exception
  {
    Exception(Dimbo::Debug_Info const& debug_info) : Dimbo::Exception(debug_info) { }
  };
// [Exception]
// [Exception1]
/**
 * First example exception.
 */
class Exception1
  : public Dimbo::Standardized_Exception<Exception, std::domain_error>
  {
  public:
    Exception1(Dimbo::Debug_Info const& debug_info)
      : Standardized_Exception(debug_info, "Exception1 domain error") { }
  };
// [Exception1]
// [Exception2]
/**
 * Second example exception.
 */
class Exception2
  : public Dimbo::Standardized_Exception<Exception, std::bad_alloc>
  {
  public:
    Exception2(Dimbo::Debug_Info const& debug_info)
      : Standardized_Exception(debug_info) { }
  };
// [Exception2]
// [Namespaces_End]
} /* namespace Dimbo */
} /* namespace Foo */
// [Namespaces_End]

// [Test]
void print_exception(Dimbo::Exception const& e)
{
  std::cerr << "foo exception: " << e.debug_info().file()
            << ":" << e.debug_info().line()
            << ":" << e.std_except().what() << std::endl;
}

void print_exception(std::exception const& e)
{
  std::cerr << "std exception: " << e.what() << std::endl;
}

int main(int, char* [])
{
  try { // Test Exception1
    try {
      throw Dimbo::Foo::Exception1(DIMBO_HERE);
    } catch(Dimbo::Foo::Exception const& e) {
      print_exception(e);
      throw;
    }
  } catch(std::exception const& e) {
    print_exception(e);
  }
  try { // Test Exception2
    try {
      throw Dimbo::Foo::Exception2(DIMBO_HERE);
    } catch(Dimbo::Foo::Exception const& e) {
      print_exception(e);
      throw;
    }
  } catch(std::exception const& e) {
    print_exception(e);
  }
  return EXIT_SUCCESS;
}
// [Test]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
