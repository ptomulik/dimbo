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

// dimbo/cl/devices.hpp

/** // doc: dimbo/cl/devices.hpp {{{
 * \file dimbo/cl/devices.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_DEVICES_HPP_INCLUDED
#define DIMBO_CL_DEVICES_HPP_INCLUDED

#include <dimbo/cl/device.hpp>
#include <dimbo/cl/platform.hpp>
#include <dimbo/util/obid_vec.hpp>
#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_found.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device_type.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_platform.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_resources.hpp>
#include <CL/cl.h>

namespace Dimbo {
namespace Cl {

/** // doc: DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
#define DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS \
           DIMBO_CL_CL_ERROR_NO(CL_INVALID_PLATFORM) \
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_DEVICE_TYPE) \
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
         , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_FOUND) \
         , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_RESOURCES) \
         , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
         , DIMBO_CL_OTHER_CL_ERROR

/** // doc: Devices {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
typedef ::Dimbo::ObId_Vec<Device> Devices;

/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
cl_uint
get_num_devices(cl_platform_id platform, cl_device_type device_type)
   throw( DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS );
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
void
get_device_ids(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint* num_devices)
   throw( DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS );
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
std::vector<cl_device_id>
get_device_ids(cl_platform_id platform,
               cl_device_type device_type = CL_DEVICE_TYPE_ALL)
   throw( DIMBO_CL_EXCEPTION(Bad_Alloc), DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS );
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
Devices
get_devices(cl_platform_id platform,
            cl_device_type device_type = CL_DEVICE_TYPE_ALL)
   throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
        , DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS );
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
Devices
get_devices(Platform const& platform,
            cl_device_type device_type = CL_DEVICE_TYPE_ALL)
   throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
        , DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS );

} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_DEVICES_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
