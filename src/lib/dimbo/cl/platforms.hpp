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

// dimbo/cl/platforms.hpp

/** // doc: dimbo/cl/platforms.hpp {{{
 * \file dimbo/cl/platforms.hpp
 *
 * This file provides functions to retrieve platform identifiers (and platform
 * proxy objects) of (all) locally available OpenCL platforms.
 */ // }}}
#ifndef DIMBO_CL_PLATFORMS_HPP_INCLUDED
#define DIMBO_CL_PLATFORMS_HPP_INCLUDED

#include <dimbo/cl/platform.hpp>
#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>

namespace Dimbo {
namespace Cl {

/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \def DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS
 * List of exceptions thrown by Dimbo::Cl::get_platform_ids() functions.
 *
 * The excepetions correspond to the following OpenCL errors:
 *
 * - \c CL_INVALID_VALUE
 * - \c CL_OUT_OF_HOST_MEMORY
 *
 * \see Dimbo::Cl::get_num_platforms(),
 * \see Dimbo::Cl::get_platform_ids(cl_uint, cl_platform_id*, cl_uint*),
 * \see Dimbo::Cl::get_platform_ids(),
 * \see Dimbo::Cl::get_platforms().
 *
 */ // }}}
#define DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS \
         DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
       , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
       , DIMBO_CL_OTHER_CL_ERROR

/** // {{{ doc: Platforms
 * \ingroup Dimbo_Cl_Platform
 * \brief Container type to keep and pass multiple Platform objects at once.
 *
 * Used to keep multiple platforms. It encapsulates a vector of Platform
 * objects and a second vector of their corresponding \c cl_platform_id
 * identifiers (just for convienience). All methods of Dimbo::ObId_Vec
 * are available.
 *
 * \see Dimbo::ObId_Vec
 */ // }}}
typedef std::vector<Platform> Platforms;

/** // {{{ doc: get_num_platforms()
 * \ingroup Dimbo_Cl_Platform
 * \brief Get number of OpenCL platforms available locally.
 * \return The number of available OpenCL platforms
 *
 * In case of error, this function throws one of the exceptions defined by
 * DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS.
 */ // }}}
cl_uint
get_num_platforms()
  throw( DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS );
/** // {{{ doc: get_platform_ids()
 * \ingroup Dimbo_Cl_Platform
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 * \param num_entries
 *    The number of \c cl_platform_id entries that can be added to \c
 *    platforms. If \c platforms is not \c NULL, the \c num_entries must be
 *    greater than zero
 * \param platforms
 *    Returns a list of OpenCL platforms found. The \c cl_platform_id values
 *    returned in platforms can be used to identify a specific OpenCL platform.
 *    If platforms argument is \c NULL, this argument is ignored. The number
 *    ofOpenCL platforms returned is the mininum of the value specified by
 *    \c num_entries or the number of OpenCL platforms available
 * \param num_platforms
 *    Returns the number of OpenCL platforms available. If \c num_platforms is
 *    \c NULL, this argument is ignored
 *
 * Call to this function maps directly to call to \c clGetPlatformIDs().
 *
 * In case of error, this function throws one of the exceptions defined by
 * DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS.
 */ // }}}
void
get_platform_ids(   cl_uint num_entries,
                    cl_platform_id* platforms,
                    cl_uint* num_platforms)
  throw( DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS );
/** // {{{ doc: get_platform_ids()
 * \ingroup Dimbo_Cl_Platform
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 * \return Vector of \c cl_platform_id identifiers.
 *
 * In case of error, this function throws one of the exceptions defined by
 * DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS or DIMBO_CL_EXCEPTION(Bad_Alloc).
 */ // }}}
std::vector<cl_platform_id>
get_platform_ids()
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS );
/** // {{{ doc: get_platforms()
 * \ingroup Dimbo_Cl_Platform
 * \brief Get proxy Platform objects for locally available OpenCL platforms.
 * \return Platforms.
 *
 * In case of error, this function throws one of the exceptions defined by
 * DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS or DIMBO_CL_EXCEPTION(Bad_Alloc).
 */ // }}}
Platforms
get_platforms()
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_GET_PLATFORM_IDS_EXCEPTIONS );

/** // {{{ doc: make_platforms(ids)
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 *
 * In case of error, this function throws an exception defined by
 * DIMBO_CL_EXCEPTION(Bad_Alloc).
 */ // }}}
Platforms
make_platforms(std::vector<cl_platform_id> const& ids)
  throw(DIMBO_CL_EXCEPTION(Bad_Alloc));
} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_PLATFORMS_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
