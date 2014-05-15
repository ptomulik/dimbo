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

// dimbo/cl/platforms.cpp

/** // doc: dimbo/cl/platforms.cpp {{{
 * \file dimbo/cl/platforms.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/platforms.hpp>
#include <dimbo/cl/throw.hpp>
#include <dimbo/cl/throw_cl.hpp>
#include <dimbo/cl/throw_other_cl.hpp>

namespace Dimbo {
namespace Cl {
/* ------------------------------------------------------------------------ */
cl_uint
get_num_platforms()
  throw( DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS )
{
  cl_uint num_platforms;
  get_platform_ids(0, NULL, &num_platforms);
  return num_platforms;
}
/* ------------------------------------------------------------------------ */
void
get_platform_ids( cl_uint num_entries,
                  cl_platform_id* platforms,
                  cl_uint* num_platforms )
  throw( DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS )
{
  cl_int err = T::clGetPlatformIDs(num_entries,platforms,num_platforms);
  switch(err)
    {
      case CL_SUCCESS:            break;
      case CL_INVALID_VALUE:      DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      case CL_OUT_OF_HOST_MEMORY: DIMBO_CL_THROW_CL(CL_OUT_OF_HOST_MEMORY);
      default:                    DIMBO_CL_THROW_OTHER_CL(err);
    }
}
/* ------------------------------------------------------------------------ */
std::vector<cl_platform_id>
get_platform_ids()
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS )
{
    try {
      std::vector<cl_platform_id> ids(get_num_platforms());
      if(ids.size() > 0)
        get_platform_ids(ids.size(), &ids.front(), NULL);
      return ids;
    } catch(Dimbo::Cl::Exception const&) {
      /* rethrow OpenCL exceptions because catch(std::bad_alloc ..) would
       * eat some of them (e.g. CL_OUT_OF_HOST_MEMORY) */
      throw;
    } catch(std::bad_alloc const&) { DIMBO_CL_THROW(Bad_Alloc); }
}
/* ------------------------------------------------------------------------ */
Platforms
get_platforms()
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS )
{
  std::vector<cl_platform_id> ids(get_platform_ids());
  try {
    return Platforms(ids);
  } catch (std::bad_alloc const&) {
    DIMBO_CL_THROW(Bad_Alloc);
  }
}
/* ------------------------------------------------------------------------ */
} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
