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

// /dimbo/protobuf/clinfo/platform_info_fixtures.hpp

/** // doc: /dimbo/protobuf/clinfo/platform_info_fixtures.hpp {{{
 * \file /dimbo/protobuf/clinfo/platform_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_PLATFORM_INFO_FIXTURES_HPP_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_PLATFORM_INFO_FIXTURES_HPP_INCLUDED

#include <dimbo/protobuf/clinfo/platform_info.hpp>

namespace Dimbo {
namespace Protobuf {
namespace Clinfo {

struct Platform_Info_Fixtures
  {
    // This corresponds to Dimbo::Clinfo::Platform_Info_Fixtures::_1()
    // see "dimbo/clinfo/platform_info_fixtures.hpp" under "src/test".
    static Platform_Info _1()
    {
      Platform_Info buf;
      buf.set_id(0x1234ul);
      buf.set_profile("FULL_PROFILE");
      buf.set_version("OpenCL 1.2 AMD-APP (1348.4)");
      buf.set_name("AMD Accelerated Parallel Processing");
      buf.set_vendor("Advanced Micro Devices, Inc.");
      buf.set_extensions("cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
      return buf;
    }
  };

} /* namespace Clinfo */
} /* namespace Protobuf */
} /* namespace Dimbo */

#endif /* DIMBO_PROTOBUF_CLINFO_PLATFORM_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
