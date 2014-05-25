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

// dimbo/clinfo/platform_info_fixtures.hpp

/** // doc: dimbo/clinfo/platform_info_fixtures.hpp {{{
 * \file dimbo/clinfo/platform_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_INFO_FIXTURES_HPP_INCLUDED
#define DIMBO_CLINFO_PLATFORM_INFO_FIXTURES_HPP_INCLUDED

#include <dimbo/clinfo/platform_info.hpp>

namespace Dimbo {
namespace Clinfo {

struct Platform_Info_Fixtures
{
  static Platform_Info _1()
  {
    return Platform_Info()
        .set_id(0x1234ul)
        .set_profile("FULL_PROFILE")
        .set_version("OpenCL 1.2 AMD-APP (1348.4)")
        .set_name("AMD Accelerated Parallel Processing")
        .set_vendor("Advanced Micro Devices, Inc.")
        .set_extensions("cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }

  static Platform_Info _2()
  {
    return Platform_Info()
        .set_id(0x54321ul)
        .set_profile("xprofilex")
        .set_version("xversionx")
        .set_name("xnamex")
        .set_vendor("xvendorx")
        .set_extensions("xextensionsx");
  }
};


} /* namespace Clinfo */
} /* namespace Dimbo */

#endif /* DIMBO_CLINFO_PLATFORM_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
