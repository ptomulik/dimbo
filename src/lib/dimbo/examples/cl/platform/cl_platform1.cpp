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
 * \file dimbo/examples/cl/platform/cl_platform1.cpp
 * \todo Write file documentation
 */ // }}}
/** // {{{
 * \example cl_platform1.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally. We use Dimbo::Cl::Platform_Layer and
 * Dimbo::Cl::Platform_Layer_Info for that.
 */ // }}}
// [Program]
// [Includes]
#include <dimbo/cl/platform_layer.hpp>
#include <dimbo/cl/platform_layer_info.hpp>
#include <dimbo/format/cl/platform_layer_info.hpp>
#include <iostream>
// [Includes]

void print_exception(Dimbo::Exception const&e)
{
  using namespace std;
  cerr << "Exception caught: " << endl;
  cerr << "  at: " << e.at().file() <<":"<< e.at().line() << endl;
  cerr << "  in: " << e.at().function() << endl;
  cerr << " msg: " << e.std_except().what() << endl;
}

void print_exception(std::exception const&e)
{
  using namespace std;
  cerr << "Exception caught: " << e.what() << endl;
}

int main(int, char const*[])
{
  using namespace std;
  using namespace Dimbo::Cl;
  using namespace Dimbo::Format;
  try {
    // [PrepareQueries]
    // Preconfigure platform query
    Platform_Query platform_query;
    platform_query.select_none();
    platform_query.select_id();
    platform_query.select_name();
    platform_query.select_vendor();
    // Preconfigure device query
    Device_Query device_query;
    device_query.select_none();
    device_query.select_id();
    device_query.select_name();
    device_query.select_vendor();
    device_query.select_version();
    // [PrepareQueries]

    // [CreatePlatformLayer]
    Platform_Layer layer;
    // [CreatePlatformLayer]
    // [CreatePlatformLayerInfo]
    Platform_Layer_Info info(layer, platform_query, device_query);
    // [CreatePlatformLayerInfo]

    write(cout, info, 2)  << endl;

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
