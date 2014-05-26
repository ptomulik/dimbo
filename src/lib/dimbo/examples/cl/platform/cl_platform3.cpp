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
 * \file dimbo/examples/cl/platform/cl_platform3.cpp
 * \todo Write file documentation
 */ // }}}
/** // {{{
 * \example cl_platform3.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
#include <dimbo/cl/platforms.hpp>
#include <dimbo/cl/devices.hpp>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::for_each;
using Dimbo::Cl::Platform;
using Dimbo::Cl::Device;
using Dimbo::Cl::Platforms;
using Dimbo::Cl::Devices;

class query_device
{
  int i;
public:
  query_device() : i(1) { }
  void operator ()(Device const& device)
  {
    cout << "  Device " << this->i << endl;
    // [Query_Device_Info]
    cout << "    Id:      " << device.id() << endl;
    cout << "    Name:    " << device.get_name() << endl;
    cout << "    Vendor:  " << device.get_vendor() << endl;
    cout << "    Version: " << device.get_version() << endl;
    // [Query_Device_Info]
    ++this->i;
  }
};

class query_platform
{
  int i;
public:
  query_platform() : i(1) { }
  void operator () (Platform const& platform)
  {
    using Dimbo::Cl::get_devices;
    // [Retrieve_Platform_Devices]
    Devices devices(get_devices(platform));
    // [Retrieve_Platform_Devices]
    cout << "Platform " << this->i << endl;
    // [Query_Platform_Info]
    cout << "  Id:      " << platform.id() << endl;
    cout << "  Name:    " << platform.get_name() << endl;
    cout << "  Profile: " << platform.get_profile() << endl;
    cout << "  Version: " << platform.get_version() << endl;
    cout << "  Ext's:   " << platform.get_extensions() << endl;
    // [Query_Platform_Info]
    // [Iterate_Platform_Devices]
    for_each(devices.begin(), devices.end(), query_device());
    // [Iterate_Platform_Devices]
    cout << endl;
    ++this->i;
  }
};

void print_exception(Dimbo::Exception const&e)
{
  cerr << "Exception caught: " << endl;
  cerr << "  at: " << e.at().file() <<":"<< e.at().line() << endl;
  cerr << "  in: " << e.at().function() << endl;
  cerr << " msg: " << e.std_except().what() << endl;
}

void print_exception(std::exception const&e)
{
  cerr << "Exception cautht: " << e.what() << endl;
}

int main(int, char const*[])
{
  using Dimbo::Cl::get_platforms;
  try {
    // [Create_Platforms]
    Platforms platforms(get_platforms());
    // [Create_Platforms]
    // [Iterate_Platforms]
    for_each(platforms.begin(), platforms.end(), query_platform());
    // [Iterate_Platforms]
  } catch (Dimbo::Exception const& e) {
    print_exception(e);
    return EXIT_FAILURE;
  } catch (std::exception const& e) {
    print_exception(e);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
