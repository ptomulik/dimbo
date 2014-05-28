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
/** // \defgroup Dimbo_Clinfo {{{
 * \defgroup Dimbo_Clinfo Clinfo, encapsulating OpenCL information
 * \brief Objects used to represent OpenCL information such as platform of
 *        device parameters.
 *
 * <h3 class="groupheader">Overwiev</h3>
 *
 * This module provides objects which encapsulate OpenCL-related information.
 * This allow to represent, and pass around, the information about available
 * OpenCL computational resources.
 *
 * <h3 class="groupheader">Location in source tree</h3>
 *
 * The source code providing the core of this module's content may be found in
 * @c src/lib/dimbo/clinfo directory. There is also an amount of associated
 * code scattered over other directories, for example serialization is in
 * @c src/lib/dimbo/serialization/clinfo, support for protocol buffers within
 * @c src/lib/dimbo/protobuf/clinfo etc.
 *
 * <h3 class="groupheader">Contents</h3>
 *
 * Currently the following classes constitute the core of %Dimbo Clinfo module:
 *    - platform/device information (Dimbo::Clinfo::Platform_Info,
 *      Dimbo::Clinfo::Device_Info),
 *    - information selectors/query objects (Dimbo::Clinfo::Platform_Query,
 *      Dimbo::Clinfo::Device_Query),
 *    - platform layer information (Dimbo::Clinfo::Platform_Layer_Info),
 *
 * The Dimbo::Clinfo::Platform_Info encapsulates parameters returned by a
 * single query performed on an OpenCL platform. The Dimbo::Clinfo::Device_Info
 * encapsulates the result of single query to an OpenCL device.
 *
 * <h3 class="groupheader">Defining queries</h3>
 *
 * Queries may be predefined via Dimbo::Clinfo::Platform_Query
 * and Dimbo::Clinfo::Device_Query objects respectively. The query objects
 * Dimbo::Clinfo::Platform_Query and Dimbo::Clinfo::Device_Query define a set
 * of boolean flags to decide what parameters should be retrieved from
 * platform/device. Single query object may be used multiple times to retrieve
 * same set of parameters from different platforms/devices.
 *
 * The Dimbo::Clinfo::Platform_Layer and Dimbo::Clinfo::Platform_Layer_Info provide
 * convenient ways to query multiple platforms/devices at once (see Examples
 * below).
 *
 * The easiest way to retrieve parameters of all locally available platforms
 * and their devices is to:
 *    -# Create Dimbo::Clinfo::Platform_Layer object, for example:
 *       \snippet cl_platform1.cpp CreatePlatformLayer
 *    -# Optionaly prepare query objects for platforms and devices, for
 *       example:
 *       \snippet cl_platform1.cpp PrepareQueries
 *    -# Create Dimbo::Clinfo::Platform_Layer_Info object and retrieve all
 *       parameters with Dimbo::Clinfo::Platform_Layer_Info::query().
 *       If you provide Dimbo::Clinfo::Platform_Layer object to
 *       Dimbo::Clinfo::Platform_Layer_Info constructor, you don't have to
 *       call @c query() method explicitly:
 *       \snippet cl_platform1.cpp CreatePlatformLayerInfo
 *
 *
 * A complete code example for this method may be found in \ref
 * cl_platform1.cpp.
 *
 * Platforms/devices may be queried without using Dimbo::Clinfo::Platform_Layer.
 * In this case the usual workflow is following:
 *    -# Create proxy object(s) &mdash; i.e. create instance(s) of
 *       Dimbo::Clinfo::Platform or Dimbo::Clinfo::Device:
 *       \snippet cl_platform2.cpp CreatePlatforms
 *       \snippet cl_platform2.cpp CreateDevices
 *    -# Optionally create and preconfigue query objects, i.e.
 *       create instance(s) of Dimbo::Clinfo::Platform_Query and/or
 *       Dimbo::Clinfo::Device_Query.
 *    -# Create info object, i.e. an instance of Dimbo::Clinfo::Platform_Info or
 *       Dimbo::Clinfo::Device_Info and perform query by
 *       Dimbo::Clinfo::Platform_Info::query() or Dimbo::Clinfo::Device_Info::query()
 *       respectively. These two activities may also be done during
 *       initialization of Dimbo::Clinfo::Platform_Info or Dimbo::Clinfo::Device_Info
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
 * Dimbo::Clinfo::Device::get_name()). A complete code example for this may
 * be found in \ref cl_platform3.cpp.
 */ // }}}
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
