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

// dimbo/cl/mocks/nohw.hpp

/** // doc: dimbo/cl/mocks/nohw.hpp {{{
 * \file dimbo/cl/mocks/nohw.hpp
 *
 * This file implements OpenCL mocks emulating the situation when there is no
 * OpenCL hardware around. It means, the number of OpenCL platforms is zero,
 * and most of the queries just return CL_INVALID_PLATFORM, CL_INVALID_DEVICE
 * error or such (see documentation of particular mocks for details).
 *
 * The implementation is created only when the \c CXXTEST_MOCK_TEST_SOURCE_FILE
 * constant is defined,
 *
 * **Example**:
 * 
 * The following code is an excerpt from unit test for
 * dimbo/cl/platform_info.cpp module. It uses the mock for clGetPlatformInfo, 
 * that is the T::NoHw_clGetPlatformInfo mock.
 *
 * \code
 * #include <cxxtest/TestSuite.h>
 * #include <dimbo/platform_info.hpp>
 * namespace Dimbo { namespace Cl { class Platform_Info_TestSuite; } }
 * class Dimbo::Cl::Platform_Info_TestSuite : public CxxTest::TestSuite
 * {
 * public:
 *    // ...
 *    void test_ctor_nohw( )
 *    {
 *      T::NoHw_clGetPlatformInfo mock;
 *      Platform platform(reinterpret_cast<cl_platform_id>(0x1234ul));
 *      TS_ASSERT_THROWS(Platform_Info info(platform), Dimbo::Cl::Cl_Error_No<CL_INVALID_PLATFORM>)
 *    }
 * };
 * \endcode
 *
 *
 */ // }}}
#ifndef DIMBO_CL_MOCKS_NOHW_HPP_INCLUDED
#define DIMBO_CL_MOCKS_NOHW_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)
namespace T {
/** // doc: NoHw_clGetPlatformIDs {{{
 * \brief Default mock for clGetPlatformIDs OpenCL function.
 *
 * Does not return any IDs - it behaves as there were no OpenCL platforms.
 */ // }}}
class NoHw_clGetPlatformIDs
  : public T::Base_clGetPlatformIDs
{
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint *num_platforms);
};

/** // doc: NoHw_clGetPlatformInfo {{{
 * \brief Default mock for clGetPlatformInfo OpenCL function.
 *
 * The mock just returns @c CL_INVALID_PLATFORM error.
 */ // }}}
class NoHw_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo
{
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
};

/** // doc: NoHw_clGetDeviceIDs {{{
 * \brief Default mock for clGetDeviceIDs OpenCL function.
 *
 * The mock just returns @c CL_INVALID_PLATFORM error.
 */ // }}}
class NoHw_clGetDeviceIDs
  : public T::Base_clGetDeviceIDs
{
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, 
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint *num_devices);
};

/** // doc: NoHw_clGetDeviceInfo {{{
 * \brief Default mock for clGetDeviceInfo OpenCL function.
 *
 * The mock just returns @c CL_INVALID_DEVICE error.
 */ // }}}
class NoHw_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo
{
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
};

//CXXTEST_MOCK_GLOBAL(cl_context, clCreateContext,
//  ( const cl_context_properties *properties, cl_uint num_devices,
//    const cl_device_id* devices,
//    void (*pfn_notify)( const char* errinfo, const void* private_info,
//                        size_t cb, void *user_data ),
//    void *user_data,
//    cl_int* errcode_ret ),
//  ( properties, num_devices, devices, pfn_notify, user_data, errcode_ret)
//);
//
//CXXTEST_MOCK_GLOBAL(cl_context, clCreateContextFromType,
//  ( const cl_context_properties *properties, const cl_device_type device_type,
//    void (*pfn_notify)( const char* errinfo, const void* private_info,
//                        size_t cb, void *user_data ),
//    void *user_data,
//    cl_int* errcode_ret ),
//  ( properties, device_type, pfn_notify, user_data, errcode_ret)
//);
//
//CXXTEST_MOCK_GLOBAL(cl_int, clGetContextInfo,
//  ( cl_context context, cl_context_info param_name,
//    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
//  ( context, param_name, param_value_size, param_value, param_value_size_ret)
//);
//
//CXXTEST_MOCK_GLOBAL(cl_int, clRetainContext,
//  (cl_context context),
//  (context)
//);
//
//CXXTEST_MOCK_GLOBAL(cl_int, clReleaseContext,
//  (cl_context context),
//  (context)
//);
//
//CXXTEST_MOCK_GLOBAL(cl_int, clGetProgramInfo,
//  ( cl_program program, cl_program_info param_name,
//    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
//  ( program, param_name, param_value_size, param_value, param_value_size_ret)
//);
//
//CXXTEST_MOCK_GLOBAL(cl_int, clRetainProgram, (cl_program program), (program));
//CXXTEST_MOCK_GLOBAL(cl_int, clReleaseProgram, (cl_program program), (program));

} /* namespace T */
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)
namespace T {

cl_int NoHw_clGetPlatformIDs::
clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                 cl_uint *num_platforms)
{
  (void)platforms;  /* prevent 'unused parameter' warning */
  (void)num_entries;/* prevent 'unused parameter' warning */
  if(num_platforms != NULL)
    {
      *num_platforms = 0;
    }
  return CL_SUCCESS;
}

cl_int NoHw_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)platform;             /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return CL_INVALID_PLATFORM;
}

cl_int NoHw_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, 
               cl_uint num_entries, cl_device_id* devices,
               cl_uint *num_devices)
{
  (void)platform;   /* prevent 'unused parameter' warning */
  (void)device_type;/* prevent 'unused parameter' warning */
  (void)num_entries;/* prevent 'unused parameter' warning */
  (void)devices;    /* prevent 'unused parameter' warning */ 
  (void)num_devices;/* prevent 'unused parameter' warning */
  return CL_INVALID_PLATFORM;
}

cl_int NoHw_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  (void)device;               /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return CL_INVALID_DEVICE;
}
} /* namespace T */
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* DIMBO_CL_MOCKS_NOHW_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
