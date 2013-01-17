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

// dimbo/cl/program.cpp 

/** // doc: dimbo/cl/program.cpp {{{
 * \file dimbo/cl/program.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/program.hpp>
#include <boost/shared_array.hpp>

#include <dimbo/cl/throw.hpp>
#include <dimbo/cl/throw_cl.hpp>
#include <dimbo/cl/throw_other_cl.hpp>

namespace Dimbo {
namespace Cl {

static std::string
_get_string_info(Program const& prog, cl_program_info name)
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  size_t size;
  prog.get_info(name, 0, NULL, &size);

  boost::shared_array<char> str;
  try { str = boost::shared_array<char>(new char[size]); } 
  catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
  prog.get_info(name, size, str.get(), &size);
  try { return std::string(str.get()); }
  catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
}
template<typename T> static T
_get_pod_info(Program const& prog, cl_program_info name)
  throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  T value;
  prog.get_info(name,sizeof(value),&value,NULL);
  return value;
}
template<typename T> static std::vector<T>
_get_vec_info(Program const& prog, cl_program_info name) 
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  size_t size;
  prog.get_info(name,0,NULL,&size);
  try {
    std::vector<T> values(size/sizeof(T));
    prog.get_info(name,values.size()*sizeof(T),&values.front(),NULL);
    return values;
  } catch(std::bad_alloc const& e) {
    DIMBO_CL_THROW(Bad_Alloc);
  }
}
void Program::
_set_id(cl_program id, bool retain_new, bool release_old)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) )
{
  if(id != this->_id) // Avoid unintended deletion by clReleaseProgram()
    { 
      if(release_old)
        {
          cl_int err = clReleaseProgram(this->id());
          switch(err)
            {
              case CL_SUCCESS: break;
              case CL_INVALID_PROGRAM: DIMBO_CL_THROW_CL(CL_INVALID_PROGRAM);
              default: DIMBO_CL_THROW_OTHER_CL(err);
            }
        }
      this->_id = id;
      if(retain_new)
        {
          cl_int err = clRetainProgram(this->_id);
          switch(err)
            {
              case CL_SUCCESS: break;
              case CL_INVALID_PROGRAM: DIMBO_CL_THROW_CL(CL_INVALID_PROGRAM);
              default: DIMBO_CL_THROW_OTHER_CL(err);
            }
        }
    }
}
Program::
Program(cl_program id, bool retain)
  throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) )
{
  this->_set_id(id, retain, false);
}
Program::
Program(const Program& rhs) 
  throw( DIMBO_CL_EXCEPTION(Program_Uninitialized)
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) )
{
  this->_set_id(rhs.id(), true, false);
}
Program::
~Program() throw()
{
  // catch all: destructor shouldn't throw anything ... 
  try { this->_set_id(NULL, false, true); }
  catch(...) { }
}
void Program::
get_info(cl_program_info name, size_t value_size,
         void* value, size_t* value_size_ret) const
  throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  get_program_info(this->id(), name, value_size, value, value_size_ret);
}
cl_program Program::
id() const
  throw( DIMBO_CL_EXCEPTION(Program_Uninitialized) )
{
  if(!this->is_initialized())
    DIMBO_CL_THROW(Program_Uninitialized);
  return this->_id;
}
Program& Program::
operator=(Program const& rhs)
  throw( DIMBO_CL_EXCEPTION(Program_Uninitialized)
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) )
{
  this->assign(rhs);
  return *this;
}
void Program::
assign(Program const& rhs)
  throw( DIMBO_CL_EXCEPTION(Program_Uninitialized) 
       , DIMBO_CL_CL_ERROR_NO(CL_INVALID_PROGRAM) )
{
  if(&rhs != this)
    {
      this->_set_id(rhs.id(), true, true);
    }
}
cl_uint Program::
get_reference_count() const
  throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_PROGRAM_REFERENCE_COUNT);
}
cl_context Program::
get_context() const
  throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_context>(*this, CL_PROGRAM_CONTEXT);
}
cl_uint Program::
get_num_devices() const
  throw( DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  return _get_pod_info<cl_uint>(*this, CL_PROGRAM_NUM_DEVICES);
}
std::vector<cl_device_id> Program::
get_devices() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  return _get_vec_info<cl_device_id>(*this, CL_PROGRAM_DEVICES);
}
std::string Program::
get_source() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this, CL_PROGRAM_SOURCE);
}
std::vector<size_t> Program::
get_binary_sizes() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  return _get_vec_info<size_t>(*this, CL_PROGRAM_BINARY_SIZES);
}
std::vector<boost::shared_array<unsigned char> > Program::
get_binaries() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PROGRAM_GET_INFO_EXCEPTIONS )
{
  typedef unsigned char uchar;
  typedef boost::shared_array<uchar> shared_array;
  try {
    std::vector<size_t> sizes(this->get_binary_sizes());
    std::vector<uchar*> ptrs(sizes.size());
    for (size_t i = 0; i < sizes.size(); ++i)
      if(sizes[i]) ptrs[i] = new uchar[sizes[i]];
      else ptrs[i] = NULL;
    this->get_info(CL_PROGRAM_BINARIES, ptrs.size()*sizeof(uchar),
                   &ptrs.front(), NULL);
    std::vector<shared_array> binaries(ptrs.begin(), ptrs.end());
    return binaries;
  } catch (std::bad_alloc const& e) {
    DIMBO_CL_THROW(Bad_Alloc);
  }
}

void 
get_program_info(cl_program id, cl_program_info name,
                 size_t value_size, void *value,
                 size_t* value_size_ret)
  throw( DIMBO_CL_GET_PROGRAM_INFO_EXCEPTIONS )
{
  cl_int err = clGetProgramInfo(id, name, value_size, value, value_size_ret);
  switch(err)
    {
      case CL_SUCCESS:          break;
      case CL_INVALID_VALUE:    DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_INVALID_PROGRAM:  DIMBO_CL_THROW_CL(CL_INVALID_PROGRAM);
      default:                  DIMBO_CL_THROW_OTHER_CL(err);
    }
}

} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
