/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */

/** // {{{
 * \file dimbo/examples/cl/platform/cl_platform2.cpp
 * \todo Write file documentation
 */ // }}}
/** // {{{
 * \example cl_platform2.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
// [Includes]
#include <dimbo/cl/platforms.hpp>
#include <dimbo/cl/devices.hpp>
#include <dimbo/clinfo/platform_info.hpp>
#include <dimbo/clinfo/device_info.hpp>
#include <dimbo/format/clinfo/platform_info.hpp>
#include <dimbo/format/clinfo/device_info.hpp>
#include <iostream>
// [Includes]

void print_exception(Dimbo::Exception const&e)
{
  using namespace std;
  cerr << "Exception caught: " << endl;
  cerr << "  at: " << e.debug_info().file() <<":"<< e.debug_info().line() << endl;
  cerr << "  in: " << e.debug_info().function() << endl;
  cerr << " msg: " << e.std_except().what() << endl;
}

void print_exception(std::exception const&e)
{
  using namespace std;
  cerr << "Exception cautht: " << e.what() << endl;
}

int main(int, char const*[])
{
  using namespace std;
  using namespace Dimbo::Cl;
  using namespace Dimbo::Clinfo;
  using namespace Dimbo::Format;
  try {
    // [CreatePlatforms]
    // Create proxies for all local OpenCL platforms
    Platforms platforms(get_platforms());
    // [CreatePlatforms]

    // [PreparePlatformQuery]
    // Prepare platform query
    Platform_Query platform_query;
    platform_query.select_none();
    platform_query.select_id();
    platform_query.select_name();
    platform_query.select_vendor();
    // [PreparePlatformQuery]

    // [PrepareDeviceQuery]
    // Prepare device query
    Device_Query device_query;
    device_query.select_none();
    device_query.select_id();
    device_query.select_name();
    device_query.select_vendor();
    device_query.select_version();
    // [PrepareDeviceQuery]

    // Query all platforms
    for (Platforms::const_iterator pi = platforms.begin();
         pi != platforms.end(); ++ pi)
      {
        // [CreatePlatformInfo]
        // Crete Platform_Info object and gather information about *pi
        // by performing query described by platform_query
        Platform_Info platform_info;
        query_platform_info(*pi, platform_query);
        // [CreatePlatformInfo]

        // Print-out pi info
        cout << "Platform " << pi - platforms.begin() << ":" << endl;
        write(cout, platform_info, 2) << endl;

        // Query all devices that belong to platform *pi
        // [CreateDevices]
        // Create proxies to all devices that belong to platform *pi.
        Devices devices(get_devices(*pi));
        // [CreateDevices]
        for(Devices::const_iterator di = devices.begin();
            di != devices.end(); ++di)
          {
            // [CreateDeviceInfo]
            // Crete Device_Info object gather information about *di by
            // performing query described by device_query
            Device_Info device_info;
            query_device_info(*di, device_query);
            // [CreateDeviceInfo]
            // Print-out device info
            cout << "    Device " << di - devices.begin() << ":" << endl;
            write(cout, device_info, 4) << endl;
          }
    }
  } catch (Dimbo::Exception const& e) {
    print_exception(e);
    return EXIT_FAILURE;
  } catch (exception const& e) {
    print_exception(e);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
