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
/** // \defgroup Dimbo_Cl_Platform {{{
 * \defgroup Dimbo_Cl_Platform Dimbo OpenCL platform layer
 *
 * This module provides access to OpenCL platform layer described by the
 * OpenCL specification under chapter 4 "The OpenCL Platform Layer". Most of
 * the functionalities is provided in object oriented way, some calls are
 * simplified, OpenCL errors are turned-out into %Dimbo CL exceptions
 * (see \ref Dimbo::Cl::Exception).  All the stuff is made type-safe. 
 * Some objects used to represent platform/device parameters or parameter
 * queries are serializable.
 *
 * The %Dimbo OpenCL platform layer implements three kinds of classes:
 *    - platform/device proxy (Dimbo::Cl::Platform and Dimbo::Cl::Device),
 *    - platform/device info  (Dimbo::Cl::Platform_Info and
 *      Dimbo::Cl::Device_Info) and,
 *    - platform/device query (Dimbo::Cl::Platform_Query and
 *      Dimbo::Cl::Device_Query).
 *
 * The whole OpenCL platform layer (all locally available OpenCL platforms and
 * devices) is represented by Dimbo::Cl::Platform_Layer object.
 *
 * The Dimbo::Cl::Platform object is used to send queries to single OpenCL
 * platform. The Dimbo::Cl::Device is used to send queries to single OpenCL
 * device. The Dimbo::Cl::Platform and Dimbo::Cl::Device objects are
 * lightweight. In fact, each of them stores only one attribute &mdash; the
 * platform/device identifier. 
 *
 * The Dimbo::Cl::Platform_Info encapsulates parameters that are result of
 * single query performed on a platform. The Dimbo::Cl::Device_Info
 * encapsulates the result of single query to device.
 *
 * Queries may be predefined via Dimbo::Cl::Platform_Query
 * and Dimbo::Cl::Device_Query objects respectivelly. The query objects
 * Dimbo::Cl::Platform_Query and Dimbo::Cl::Device_Query define a set
 * of boolean flags to decide what parameters should be retrieved from
 * platform/device. Single query object may be used multiple times to retrieve
 * same set of parameters from different platforms/devices.
 *
 * The Dimbo::Cl::Platform_Layer and Dimbo::Cl::Platform_Layer_Info provide
 * convienient ways to query multiple platforms/devices at once (see Examples
 * below).
 *
 * The easiest way to retrieve parameters of all locally available platforms
 * and their devices is to:
 *    -# Create Dimbo::Cl::Platform_Layer object, for example:
 *       \snippet cl_platform1.cpp CreatePlatformLayer
 *    -# Optionaly prepare query objects for platforms and devices, for
 *       example:
 *       \snippet cl_platform1.cpp PrepareQueries
 *    -# Create Dimbo::Cl::Platform_Layer_Info object and retrieve all
 *       parameters with Dimbo::Cl::Platform_Layer_Info::query().
 *       If you provide Dimbo::Cl::Platform_Layer object to
 *       Dimbo::Cl::Platform_Layer_Info constructor, you don't have to
 *       call @c query() method explicitelly:
 *       \snippet cl_platform1.cpp CreatePlatformLayerInfo
 *
 *
 * A complete code example for this method may be found in \ref
 * cl_platform1.cpp.
 *
 * Platforms/devices may be queried without using Dimbo::Cl::Platform_Layer.
 * In this case the usual workflow is following:
 *    -# Create proxy object(s) &mdash; i.e. create instance(s) of
 *       Dimbo::Cl::Platform or Dimbo::Cl::Device:
 *       \snippet cl_platform2.cpp CreatePlatforms
 *       \snippet cl_platform2.cpp CreateDevices
 *    -# Optionally create and preconfigue query objects, i.e.
 *       create instance(s) of Dimbo::Cl::Platform_Query and/or
 *       Dimbo::Cl::Device_Query.
 *    -# Create info object, i.e. an instance of Dimbo::Cl::Platform_Info or
 *       Dimbo::Cl::Device_Info and perform query by
 *       Dimbo::Cl::Platform_Info::query() or Dimbo::Cl::Device_Info::query()
 *       respectivelly. These two activities may also be done during
 *       initialization of Dimbo::Cl::Platform_Info or Dimbo::Cl::Device_Info
 *       objects:
 *       \snippet cl_platform2.cpp CreatePlatformInfo
 *       \snippet cl_platform2.cpp CreateDeviceInfo
 *
 *
 * A complete code example for this may be found in \ref cl_platform2.cpp.
 *
 * Finally, platform and device parameters may also be retrieved without
 * involving info and query objects by just invoking platform/device
 * get_xxx() methods "by hand" (for example
 * Dimbo::Cl::Device::get_name()). A complete code example for this may
 * be found in \ref cl_platform3.cpp.
 */ // }}}
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
