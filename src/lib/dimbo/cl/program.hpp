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

// dimbo/cl/program.hpp

/** // doc: dimbo/cl/program.hpp {{{
 * \file dimbo/cl/program.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_PROGRAM_HPP_INCLUDED
#define DIMBO_CL_PROGRAM_HPP_INCLUDED

#include <dimbo/cl/program_interface.hpp>

#include <dimbo/cl/exceptions/decl_logic_error.hpp>
#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/exceptions/uninitialized_program.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_program.hpp>

namespace Dimbo {
namespace Cl {

/** // doc: DIMBO_CL_GET_PROGRAM_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_GET_PROGRAM_INFO_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_PROGRAM_INFO_EXCEPTIONS {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS \
            DIMBO_CL_EXCEPTION(Uninitialized_Program) \
          , DIMBO_CL_GET_PROGRAM_INFO_EXCEPTIONS

/** // doc: class Program {{{
 * @todo Write documentation
 */ // }}}
class Program : public Program_Interface
{
private:
  cl_program _id;
  Program();
  /** // doc: program_id() {{{
   * \todo Write documentation
   */ // }}}
protected:
  cl_program id() const
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Program) );
  /** // doc: _set_id() {{{
   * \todo Write documentation for class Program_Interface
   */ // }}}
  void _set_id(cl_program id, bool retain_new, bool release_old)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) );
  Program(cl_program id, bool retain)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) );
public:
  /** // doc: Program() {{{
   * \todo Write documentation for class Program_Interface
   */ // }}}
  virtual ~Program() throw();
  /** // doc: ~Program() {{{
   * \todo Write documentation for class Program_Interface
   */ // }}}
  Program(const Program& rhs)
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Program)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) );
/* FIXME: develop more verbose constant name */
#ifndef SWIG
  /** // {{{
   * \brief Assignment operator
   * \todo Finish documentation
   */ // }}}
  Program& operator=(Program const& rhs)
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Program)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) );
#endif
  /** // {{{
   * \brief Assignment
   * \todo Finish documentation
   */ // }}}
  void assign(Program const& rhs)
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Program)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) );
  /** // {{{
   * \todo Finish documentation
   */ // }}}
  bool is_initialized() const
  {
    return (this->_id != NULL);
  }
  /** // doc: get_info() {{{
   * \todo Write documentation
   */ // }}}
  void get_info(cl_program_info name, size_t value_size,
                void* value, size_t* value_size_ret) const
    throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  cl_uint get_reference_count() const
    throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_context() {{{
   * \todo Write documentation
   */ // }}}
  cl_context get_context() const
    throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_num_devices() {{{
   * \todo Write documentation
   */ // }}}
  cl_uint get_num_devices() const
    throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_devices() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<cl_device_id> get_devices() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_source() {{{
   * \todo Write documentation
   */ // }}}
  std::string get_source() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_binary_sizes() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<size_t> get_binary_sizes() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
  /** // doc: get_binaries() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<boost::shared_array<unsigned char> > get_binaries() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS );
};
/** // {{{
 * \todo Write documentation
 */ // }}}
void
get_program_info(cl_program program, cl_program_info name,
                 size_t value_size, void *value,
                 size_t* value_size_ret)
  throw( DIMBO_CL_GET_PROGRAM_INFO_EXCEPTIONS );
} /* namespace Cl */
} /* namespace Dimbo */
#endif /* DIMBO_CL_PROGRAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
