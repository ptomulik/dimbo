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

// dimbo/cl/devices.cpp

/** // doc: dimbo/cl/devices.cpp {{{
 * \file dimbo/cl/devices.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/devices.hpp>
#include <dimbo/cl/throw.hpp>
#include <dimbo/cl/throw_cl.hpp>
#include <dimbo/cl/throw_other_cl.hpp>

namespace Dimbo {
namespace Cl {

/* ------------------------------------------------------------------------ */
cl_uint
get_num_devices(cl_platform_id platform, cl_device_type device_type)
  throw( DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS )
{
  cl_uint num_devices = 0;
  get_device_ids(platform,device_type,0,NULL,&num_devices);
  return num_devices;
}
/* ------------------------------------------------------------------------ */
void
get_device_ids(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices, cl_uint* num_devices)
  throw( DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS )
{
  cl_int err = clGetDeviceIDs(platform, device_type, num_entries, devices,
                              num_devices);
  switch(err)
    {
      case CL_SUCCESS: break;
      case CL_INVALID_PLATFORM: DIMBO_CL_THROW_CL(CL_INVALID_PLATFORM);
      case CL_INVALID_DEVICE_TYPE: DIMBO_CL_THROW_CL(CL_INVALID_DEVICE_TYPE);
      case CL_INVALID_VALUE: DIMBO_CL_THROW_CL(CL_INVALID_VALUE);
      // case CL_DEVICE_NOT_FOUND: DIMBO_CL_THROW_CL(CL_DEVICE_NOT_FOUND);
      case CL_DEVICE_NOT_FOUND: break;
      case CL_OUT_OF_RESOURCES: DIMBO_CL_THROW_CL(CL_OUT_OF_RESOURCES);
      case CL_OUT_OF_HOST_MEMORY: DIMBO_CL_THROW_CL(CL_OUT_OF_HOST_MEMORY);
      default: DIMBO_CL_THROW_OTHER_CL(err);
    }
}
/* ------------------------------------------------------------------------ */
std::vector<cl_device_id>
get_device_ids(cl_platform_id platform, cl_device_type device_type)
  throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
       , DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS )
{
    try {
      std::vector<cl_device_id> ids(get_num_devices(platform,device_type));
      if(ids.size() > 0)
        get_device_ids(platform, device_type, ids.size(), &ids[0], NULL);
      return ids;
    } catch(std::bad_alloc const& e) { DIMBO_CL_THROW(Bad_Alloc); }
}
/* ------------------------------------------------------------------------ */
Devices
get_devices(cl_platform_id platform, cl_device_type device_type)
   throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
        , DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS )

{
  try {
    return Devices(get_device_ids(platform, device_type));
  } catch (std::bad_alloc const& e) {
    DIMBO_CL_THROW(Bad_Alloc);
  }
}
/* ------------------------------------------------------------------------ */
Devices
get_devices(Platform const& platform, cl_device_type device_type)
   throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
        , DIMBO_CL_GET_DEVICE_IDS_EXCEPTIONS )

{
  return get_devices(platform.id(), device_type);
}

} /* namespace Cl */
} /* namespace Dimbo */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
