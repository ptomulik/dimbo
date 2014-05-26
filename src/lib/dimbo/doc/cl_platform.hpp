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
 * the functionalities is provided in object oriented way, most calls are
 * simplified, OpenCL errors are turned-out into %Dimbo CL exceptions
 * (see \ref Dimbo::Cl::Exception). All the stuff is made type-safe.
 *
 * The source code providing the core functionality of OpenCL platform layer
 * may be found in \c src/lib/dimbo/cl/ directory. There is also an amount of
 * associated code scattered over other directories, for example swig wrappers
 * may be found in \c src/lib/dimbo/swig/dimbo/cl/, swig wrappers specific to
 * python in \c src/lib/dimbo/python/dimbo/cl/ etc.
 *
 * The %Dimbo OpenCL platform layer provides these classes:
 *    - platform/device proxy (Dimbo::Cl::Platform and Dimbo::Cl::Device),
 *    - platform/device collection (Dimbo::Cl::Platforms and Dimbo::Cl::Devices) and,
 *    - entire platform layer (Dimbo::Cl::Platform_Layer).
 *
 * The Dimbo::Cl::Platform object is used to send queries to single OpenCL
 * platform (via \c clGetPlatformInfo()). The Dimbo::Cl::Device is used to send
 * queries to single OpenCL device (via \c clGetDeviceInfo()). The
 * Dimbo::Cl::Platform and Dimbo::Cl::Device objects are lightweight - each of
 * them stores only its platform/device identifier.
 *
 * The whole OpenCL platform layer (OpenCL platforms and devices available
 * locally to the current process) is represented by Dimbo::Cl::Platform_Layer
 * object. The Dimbo::Cl::Platform_Layer provides convenient ways to query multiple
 * platforms/devices at once (see Examples below).
 *
 * <h3 class="groupheader">
 * Querying OpenCL platforms/devices in a straightforward way
 * </h3>
 * \anchor querying_cl_platform_straight
 *
 *
 * Platforms/devices may be queried by using Dimbo::Cl::Platform,
 * Dimbo::Cl::Device objects. A straightforward workflow is to:
 *    -# Create a collection of Platform objects:
 *        \snippet cl_platform3.cpp Create_Platforms
 *    -# Iterate over the platforms,
 *       \snippet cl_platform3.cpp Iterate_Platforms
 *       and query it for necessary information, e.g (the code within our
 *       custom query_platform functor):
 *       \snippet cl_platform3.cpp Query_Platform_Info
 *    -# For each platform, retrieve its Devices,
 *       \snippet cl_platform3.cpp Retrieve_Platform_Devices
 *       then iterate over these devices
 *       \snippet cl_platform3.cpp Iterate_Platform_Devices
 *       and query each device for device information, e.g. (the code within
 *       our custom query_device functor):
 *       \snippet cl_platform3.cpp Query_Device_Info
 *
 *
 * The complete code for the above example may be found in \ref
 * cl_platform3.cpp. Note, that this is suboptimal (you see the boilerplate
 * related to iteration and manual querying). The better, and more flexible
 * approach is described below.
 *
 * <h3 class="groupheader">
 * Using the Dimbo::Cl::Platform_Layer object
 * </h3>
 * \anchor using_cl_platform_layer_object
 *
 * Retrieval and enumeration of (all) available platforms and devices is
 * implemented in class Dimbo::Cl::Platform_Layer. An instance of
 * Dimbo::Cl::Platform_Layer represents (locally available) OpenCL platforms
 * and their devices. It's intended to cooperate with other objects, such as
 * these defined in module named \ref Dimbo_Clinfo.
 *
 * An OpenCL information describing all the platforms and devices represented
 * by Dimbo::Cl::Platform_Layer object may be easily encapsulated within an
 * instance of Dimbo::Clinfo::Platform_Layer_Info. Querying all the information
 * and storing it with Dimbo::Clinfo::Platform_Layer_Info is as simple as
 * single call to Dimbo::Cl::query_platform_layer_info(). With few additional
 * utilities implemented in %Dimbo we may reduce the whole executable code to
 * a single line:
 * 
 * \snippet cl_platform0.cpp Query_Print_Info
 *
 * The complete example is found in cl_platform0.cpp
 *
 */ // }}}
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
