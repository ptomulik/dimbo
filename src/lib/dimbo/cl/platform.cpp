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

// dimbo/cl/platform.hpp

/** // doc: dimbo/cl/platform.hpp {{{
 * \file dimbo/cl/platform.hpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/platform.hpp>
#include <dimbo/cl/throw.hpp>
#include <dimbo/cl/throw_cl.hpp>
#include <dimbo/cl/throw_other_cl.hpp>
#include <boost/shared_array.hpp>


namespace Dimbo {
namespace Cl {

/* ------------------------------------------------------------------------ */
static std::string
_get_string_info(Platform const& platform, cl_platform_info name)
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  size_t size;
  platform.get_info(name, 0, NULL, &size);

  boost::shared_array<char> str;
  try { str = boost::shared_array<char>(new char[size]); }
  catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
  platform.get_info(name, size, str.get(), &size);
  try { return std::string(str.get()); }
  catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
}
/* ------------------------------------------------------------------------ */
cl_platform_id Platform::
get_valid_id() const
  throw( DIMBO_CL_EXCEPTION(Uninitialized_Platform) )
{
  if(!this->is_initialized())
    DIMBO_CL_THROW(Uninitialized_Platform);
  return this->_platform_id;
}
/* ------------------------------------------------------------------------ */
void Platform::
get_info( cl_platform_info name, size_t value_size, void* value,
          size_t* value_size_ret) const
  throw( DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  get_platform_info(this->get_valid_id(),name,value_size,value,value_size_ret);
}
/* ------------------------------------------------------------------------ */
std::string Platform::
get_profile() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this,CL_PLATFORM_PROFILE);
}
/* ------------------------------------------------------------------------ */
std::string Platform::
get_version() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this,CL_PLATFORM_VERSION);
}
/* ------------------------------------------------------------------------ */
std::string Platform::
get_name() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this,CL_PLATFORM_NAME);
}
/* ------------------------------------------------------------------------ */
std::string Platform::
get_vendor() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this,CL_PLATFORM_VENDOR);
}
/* ------------------------------------------------------------------------ */
std::string Platform::
get_extensions() const
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_PLATFORM_GET_INFO_EXCEPTIONS )
{
  return _get_string_info(*this,CL_PLATFORM_EXTENSIONS);
}
} // }}} /* namespace Cl */
} // }}} /* namespace Dimbo */

namespace Dimbo {
namespace Cl {
void
get_platform_info(  cl_platform_id platform,
                    cl_platform_info param_name,
                    size_t param_value_size,
                    void* param_value,
                    size_t* param_value_size_ret)
  throw( DIMBO_CL_GET_PLATFORM_INFO_EXCEPTIONS )
{
  cl_int err = T::clGetPlatformInfo(platform, param_name, param_value_size,
                                    param_value, param_value_size_ret);
  switch(err)
    {
      case CL_SUCCESS:            break;
      case CL_INVALID_PLATFORM:   DIMBO_CL_THROW_CL(CL_INVALID_PLATFORM);
      case CL_INVALID_VALUE:      DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_OUT_OF_HOST_MEMORY: DIMBO_CL_THROW_CL(CL_OUT_OF_HOST_MEMORY);
      default:                    DIMBO_CL_THROW_OTHER_CL(err);
    }
}
} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
