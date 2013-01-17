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

// dimbo/cl/program_interface.hpp

/** // doc: dimbo/cl/program_interface.hpp {{{ 
 * \file dimbo/cl/program_interface.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PROGRAM_INTERFACE_HPP_INCLUDED
#define DIMBO_CL_PROGRAM_INTERFACE_HPP_INCLUDED

#include <CL/cl.h>
#include <vector>
#include <string>
#include <boost/shared_array.hpp>

namespace Dimbo {
namespace Cl {

/** // doc: class Program_Interface {{{
 * \todo Write documentation
 */ // }}}
class Program_Interface
{
protected:
  /** // doc: program_id() {{{
   * \todo Write documentation
   */ // }}}
//  virtual cl_program program() const = 0;
public:
  /** // doc: ~Program_Interface() {{{
   * \todo Write documentation for class Program_Interface
   */ // }}}
  virtual ~Program_Interface() { }
  /** // doc: get_info() {{{
   * \todo Write documentation
   */ // }}}
  virtual void get_info(cl_program_info name, size_t value_size, void* value,
                        size_t* value_size_ret) const = 0;
  /** // doc: get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  virtual cl_uint get_reference_count() const = 0;
  /** // doc: get_context() {{{
   * \todo Write documentation
   */ // }}}
  virtual cl_context get_context() const = 0;
  /** // doc: get_num_devices() {{{
   * \todo Write documentation
   */ // }}}
  virtual cl_uint get_num_devices() const = 0;
  /** // doc: get_devices() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::vector<cl_device_id> get_devices() const = 0;
  /** // doc: get_source() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string get_source() const = 0;
  /** // doc: get_binary_sizes() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::vector<size_t> get_binary_sizes() const = 0;
  /** // doc: get_binaries() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::vector<boost::shared_array<unsigned char> > get_binaries() const = 0;
};
} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_PROGRAM_INTERFACE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
