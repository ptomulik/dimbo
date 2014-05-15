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

// dimbo/cl/mocks/corner.hpp

/** // doc: dimbo/cl/mocks/corner.hpp {{{
 * \file dimbo/cl/mocks/corner.hpp
 *
 * This file implements OpenCL mocks emulating several corner cases, such as
 * memory allocation errors.
 *
 * The implementation is created only when the \c CXXTEST_MOCK_TEST_SOURCE_FILE
 * constant is defined,
 *
 */ // }}}
#ifndef DIMBO_CL_MOCKS_CORNER_HPP_INCLUDED
#define DIMBO_CL_MOCKS_CORNER_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)
namespace T {
/** // doc: NegSize_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class NegSize_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo
{
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};
/** // doc: NegSize_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class NegSize_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo
{
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};
/** // doc: OutOfResources_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * Always returns CL_OUT_OF_RESOURCES.
 */ // }}}
class OutOfResources_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo
{
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};
/** // doc: OutOfResources_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * Always returns CL_OUT_OF_RESOURCES.
 */ // }}}
class OutOfResources_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo
{
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};
/** // doc: OutOfHostMemory_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * Always returns OUT_OF_HOST_MEMORY.
 */ // }}}
class OutOfHostMemory_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo
{
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};
/** // doc: OutOfHostMemory_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * Always returns OUT_OF_HOST_MEMORY.
 */ // }}}
class OutOfHostMemory_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo
{
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};
} /* namespace T */
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)
namespace T {

cl_int NegSize_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)platform;             /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  if(param_value_size_ret)
    {
      *param_value_size_ret = -16;
    }
  return CL_SUCCESS;
}

cl_int NegSize_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)device;             /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  if(param_value_size_ret)
    {
      *param_value_size_ret = -16;
    }
  return CL_SUCCESS;
}

cl_int OutOfResources_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)platform;             /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return CL_OUT_OF_RESOURCES;
}

cl_int OutOfResources_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)device;               /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return CL_OUT_OF_RESOURCES;
}

cl_int OutOfHostMemory_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)platform;             /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return CL_OUT_OF_HOST_MEMORY;
}

cl_int OutOfHostMemory_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)device;               /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return CL_OUT_OF_HOST_MEMORY;
}
} /* namespace T */
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* DIMBO_CL_MOCKS_CORNER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
