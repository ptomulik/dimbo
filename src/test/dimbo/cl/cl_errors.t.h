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

// dimbo/cl/cl_errors.t.h

/** // doc: dimbo/cl/cl_errors.t.h {{{
 * \file dimbo/cl/cl_errors.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CL_ERRORS_T_H_INCLUDED
#define DIMBO_CL_CL_ERRORS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/cl_errors.hpp>
#include <type_traits>

namespace Dimbo { namespace Cl { class Cl_Errors_TestSuite; } }

/** // doc: class Dimbo::Cl::Cl_Errors_TestSuite {{{
 * \brief Test suite for exception classes included with
 *        dimbo/cl/cl_errors.hpp.
 */ // }}}
class Dimbo::Cl::Cl_Errors_TestSuite : public CxxTest::TestSuite
{
public:
  void test_cl_invalid_work_dimension(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_WORK_DIMENSION> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_WORK_DIMENSION> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_WORK_DIMENSION> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_WORK_DIMENSION> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_WORK_DIMENSION>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_WORK_DIMENSION")));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_WORK_DIMENSION>(DIMBO_HERE).cl_error()),(CL_INVALID_WORK_DIMENSION));
  }
  void test_cl_invalid_kernel(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_KERNEL> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_KERNEL> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_KERNEL> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_KERNEL> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL>(DIMBO_HERE).cl_error()),(CL_INVALID_KERNEL));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_KERNEL")));
  }
  void test_cl_invalid_program_executable(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_PROGRAM_EXECUTABLE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_PROGRAM_EXECUTABLE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_PROGRAM_EXECUTABLE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_PROGRAM_EXECUTABLE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_PROGRAM_EXECUTABLE>(DIMBO_HERE).cl_error()),(CL_INVALID_PROGRAM_EXECUTABLE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_PROGRAM_EXECUTABLE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_PROGRAM_EXECUTABLE")));
  }
  void test_cl_invalid_global_offset(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_GLOBAL_OFFSET> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_GLOBAL_OFFSET> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_GLOBAL_OFFSET> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_GLOBAL_OFFSET> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_GLOBAL_OFFSET>(DIMBO_HERE).cl_error()),(CL_INVALID_GLOBAL_OFFSET));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_GLOBAL_OFFSET>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_GLOBAL_OFFSET")));
  }
  void test_cl_invalid_work_item_size(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_WORK_ITEM_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_WORK_ITEM_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_WORK_ITEM_SIZE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_WORK_ITEM_SIZE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_WORK_ITEM_SIZE>(DIMBO_HERE).cl_error()),(CL_INVALID_WORK_ITEM_SIZE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_WORK_ITEM_SIZE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_WORK_ITEM_SIZE")));
  }
  void test_cl_invalid_program(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_PROGRAM> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_PROGRAM> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_PROGRAM> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_PROGRAM> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_PROGRAM>(DIMBO_HERE).cl_error()),(CL_INVALID_PROGRAM));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_PROGRAM>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_PROGRAM")));
  }
  void test_cl_compiler_not_available(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_COMPILER_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_COMPILER_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_COMPILER_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_COMPILER_NOT_AVAILABLE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_COMPILER_NOT_AVAILABLE>(DIMBO_HERE).cl_error()),(CL_COMPILER_NOT_AVAILABLE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_COMPILER_NOT_AVAILABLE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_COMPILER_NOT_AVAILABLE")));
  }
  void test_cl_map_failure(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_MAP_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_MAP_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_MAP_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<std::runtime_error,Cl_Error_No<CL_MAP_FAILURE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_MAP_FAILURE>(DIMBO_HERE).cl_error()),(CL_MAP_FAILURE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_MAP_FAILURE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_MAP_FAILURE")));
  }
  void test_cl_image_format_not_supported(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_IMAGE_FORMAT_NOT_SUPPORTED> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_IMAGE_FORMAT_NOT_SUPPORTED> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_IMAGE_FORMAT_NOT_SUPPORTED> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_IMAGE_FORMAT_NOT_SUPPORTED> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_IMAGE_FORMAT_NOT_SUPPORTED>(DIMBO_HERE).cl_error()),(CL_IMAGE_FORMAT_NOT_SUPPORTED));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_IMAGE_FORMAT_NOT_SUPPORTED>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_IMAGE_FORMAT_NOT_SUPPORTED")));
  }
  void test_cl_invalid_gl_object(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_GL_OBJECT> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_GL_OBJECT> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_GL_OBJECT> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_GL_OBJECT> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_GL_OBJECT>(DIMBO_HERE).cl_error()),(CL_INVALID_GL_OBJECT));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_GL_OBJECT>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_GL_OBJECT")));
  }
  void test_cl_mem_object_allocation_failure(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_MEM_OBJECT_ALLOCATION_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_MEM_OBJECT_ALLOCATION_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_MEM_OBJECT_ALLOCATION_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<std::bad_alloc,Cl_Error_No<CL_MEM_OBJECT_ALLOCATION_FAILURE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_MEM_OBJECT_ALLOCATION_FAILURE>(DIMBO_HERE).cl_error()),(CL_MEM_OBJECT_ALLOCATION_FAILURE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_MEM_OBJECT_ALLOCATION_FAILURE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_MEM_OBJECT_ALLOCATION_FAILURE")));
  }
  void test_cl_invalid_buffer_size(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_BUFFER_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_BUFFER_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_BUFFER_SIZE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_BUFFER_SIZE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_BUFFER_SIZE>(DIMBO_HERE).cl_error()),(CL_INVALID_BUFFER_SIZE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_BUFFER_SIZE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_BUFFER_SIZE")));
  }
  void test_cl_invalid_kernel_name(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_KERNEL_NAME> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_KERNEL_NAME> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_KERNEL_NAME> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_KERNEL_NAME> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL_NAME>(DIMBO_HERE).cl_error()),(CL_INVALID_KERNEL_NAME));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL_NAME>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_KERNEL_NAME")));
  }
  void test_cl_mem_copy_overlap(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_MEM_COPY_OVERLAP> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_MEM_COPY_OVERLAP> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_MEM_COPY_OVERLAP> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_MEM_COPY_OVERLAP> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_MEM_COPY_OVERLAP>(DIMBO_HERE).cl_error()),(CL_MEM_COPY_OVERLAP));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_MEM_COPY_OVERLAP>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_MEM_COPY_OVERLAP")));
  }
  void test_cl_invalid_kernel_args(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_KERNEL_ARGS> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_KERNEL_ARGS> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_KERNEL_ARGS> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_KERNEL_ARGS> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL_ARGS>(DIMBO_HERE).cl_error()),(CL_INVALID_KERNEL_ARGS));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL_ARGS>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_KERNEL_ARGS")));
  }
  void test_cl_image_format_mismatch(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_IMAGE_FORMAT_MISMATCH> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_IMAGE_FORMAT_MISMATCH> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_IMAGE_FORMAT_MISMATCH> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_IMAGE_FORMAT_MISMATCH> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_IMAGE_FORMAT_MISMATCH>(DIMBO_HERE).cl_error()),(CL_IMAGE_FORMAT_MISMATCH));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_IMAGE_FORMAT_MISMATCH>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_IMAGE_FORMAT_MISMATCH")));
  }
  void test_cl_invalid_work_group_size(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_WORK_GROUP_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_WORK_GROUP_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_WORK_GROUP_SIZE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_WORK_GROUP_SIZE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_WORK_GROUP_SIZE>(DIMBO_HERE).cl_error()),(CL_INVALID_WORK_GROUP_SIZE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_WORK_GROUP_SIZE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_WORK_GROUP_SIZE")));
  }
  void test_cl_device_not_found(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_DEVICE_NOT_FOUND> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_DEVICE_NOT_FOUND> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_DEVICE_NOT_FOUND> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_DEVICE_NOT_FOUND> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_DEVICE_NOT_FOUND>(DIMBO_HERE).cl_error()),(CL_DEVICE_NOT_FOUND));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_DEVICE_NOT_FOUND>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_DEVICE_NOT_FOUND")));
  }
  void test_cl_invalid_event(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_EVENT> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_EVENT> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_EVENT> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_EVENT> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_EVENT>(DIMBO_HERE).cl_error()),(CL_INVALID_EVENT));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_EVENT>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_EVENT")));
  }
  void test_cl_invalid_value(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_VALUE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_VALUE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_VALUE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_VALUE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_VALUE>(DIMBO_HERE).cl_error()),(CL_INVALID_VALUE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_VALUE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_VALUE")));
  }
  void test_cl_invalid_platform(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_PLATFORM> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_PLATFORM> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_PLATFORM> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_PLATFORM> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_PLATFORM>(DIMBO_HERE).cl_error()),(CL_INVALID_PLATFORM));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_PLATFORM>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_PLATFORM")));
  }
  void test_cl_invalid_context(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_CONTEXT> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_CONTEXT> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_CONTEXT> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_CONTEXT> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_CONTEXT>(DIMBO_HERE).cl_error()),(CL_INVALID_CONTEXT));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_CONTEXT>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_CONTEXT")));
  }
  void test_cl_invalid_sampler(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_SAMPLER> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_SAMPLER> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_SAMPLER> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_SAMPLER> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_SAMPLER>(DIMBO_HERE).cl_error()),(CL_INVALID_SAMPLER));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_SAMPLER>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_SAMPLER")));
  }
  void test_cl_invalid_kernel_definition(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_KERNEL_DEFINITION> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_KERNEL_DEFINITION> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_KERNEL_DEFINITION> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_KERNEL_DEFINITION> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL_DEFINITION>(DIMBO_HERE).cl_error()),(CL_INVALID_KERNEL_DEFINITION));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_KERNEL_DEFINITION>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_KERNEL_DEFINITION")));
  }
  void test_cl_device_not_available(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_DEVICE_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_DEVICE_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_DEVICE_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_DEVICE_NOT_AVAILABLE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_DEVICE_NOT_AVAILABLE>(DIMBO_HERE).cl_error()),(CL_DEVICE_NOT_AVAILABLE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_DEVICE_NOT_AVAILABLE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_DEVICE_NOT_AVAILABLE")));
  }
  void test_cl_invalid_arg_value(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_ARG_VALUE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_ARG_VALUE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_ARG_VALUE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_ARG_VALUE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_ARG_VALUE>(DIMBO_HERE).cl_error()),(CL_INVALID_ARG_VALUE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_ARG_VALUE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_ARG_VALUE")));
  }
  void test_cl_invalid_mip_level(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_MIP_LEVEL> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_MIP_LEVEL> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_MIP_LEVEL> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_MIP_LEVEL> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_MIP_LEVEL>(DIMBO_HERE).cl_error()),(CL_INVALID_MIP_LEVEL));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_MIP_LEVEL>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_MIP_LEVEL")));
  }
  void test_cl_out_of_host_memory(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_OUT_OF_HOST_MEMORY> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_OUT_OF_HOST_MEMORY> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_OUT_OF_HOST_MEMORY> >::value));
    TS_ASSERT((std::is_base_of<std::bad_alloc,Cl_Error_No<CL_OUT_OF_HOST_MEMORY> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_OUT_OF_HOST_MEMORY>(DIMBO_HERE).cl_error()),(CL_OUT_OF_HOST_MEMORY));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_OUT_OF_HOST_MEMORY>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_OUT_OF_HOST_MEMORY")));
  }
  void test_cl_build_program_failure(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_BUILD_PROGRAM_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_BUILD_PROGRAM_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_BUILD_PROGRAM_FAILURE> >::value));
    TS_ASSERT((std::is_base_of<std::runtime_error,Cl_Error_No<CL_BUILD_PROGRAM_FAILURE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_BUILD_PROGRAM_FAILURE>(DIMBO_HERE).cl_error()),(CL_BUILD_PROGRAM_FAILURE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_BUILD_PROGRAM_FAILURE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_BUILD_PROGRAM_FAILURE")));
  }
  void test_cl_invalid_binary(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_BINARY> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_BINARY> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_BINARY> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_BINARY> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_BINARY>(DIMBO_HERE).cl_error()),(CL_INVALID_BINARY));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_BINARY>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_BINARY")));
  }
  void test_cl_invalid_host_ptr(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_HOST_PTR> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_HOST_PTR> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_HOST_PTR> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_HOST_PTR> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_HOST_PTR>(DIMBO_HERE).cl_error()),(CL_INVALID_HOST_PTR));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_HOST_PTR>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_HOST_PTR")));
  }
  void test_cl_profiling_info_not_available(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_PROFILING_INFO_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_PROFILING_INFO_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_PROFILING_INFO_NOT_AVAILABLE> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_PROFILING_INFO_NOT_AVAILABLE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_PROFILING_INFO_NOT_AVAILABLE>(DIMBO_HERE).cl_error()),(CL_PROFILING_INFO_NOT_AVAILABLE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_PROFILING_INFO_NOT_AVAILABLE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_PROFILING_INFO_NOT_AVAILABLE")));
  }
  void test_cl_invalid_arg_index(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_ARG_INDEX> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_ARG_INDEX> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_ARG_INDEX> >::value));
    TS_ASSERT((std::is_base_of<std::exception,Cl_Error_No<CL_INVALID_ARG_INDEX> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_ARG_INDEX>(DIMBO_HERE).cl_error()),(CL_INVALID_ARG_INDEX));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_ARG_INDEX>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_ARG_INDEX")));
  }
  void test_cl_invalid_arg_size(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_ARG_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_ARG_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_ARG_SIZE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_ARG_SIZE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_ARG_SIZE>(DIMBO_HERE).cl_error()),(CL_INVALID_ARG_SIZE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_ARG_SIZE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_ARG_SIZE")));
  }
  void test_cl_invalid_queue_properties(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_QUEUE_PROPERTIES> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_QUEUE_PROPERTIES> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_QUEUE_PROPERTIES> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_QUEUE_PROPERTIES> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_QUEUE_PROPERTIES>(DIMBO_HERE).cl_error()),(CL_INVALID_QUEUE_PROPERTIES));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_QUEUE_PROPERTIES>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_QUEUE_PROPERTIES")));
  }
  void test_cl_invalid_device_type(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_DEVICE_TYPE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_DEVICE_TYPE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_DEVICE_TYPE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_DEVICE_TYPE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_DEVICE_TYPE>(DIMBO_HERE).cl_error()),(CL_INVALID_DEVICE_TYPE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_DEVICE_TYPE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_DEVICE_TYPE")));
  }
  void test_cl_invalid_operation(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_OPERATION> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_OPERATION> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_OPERATION> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_OPERATION> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_OPERATION>(DIMBO_HERE).cl_error()),(CL_INVALID_OPERATION));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_OPERATION>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_OPERATION")));
  }
  void test_cl_invalid_image_format_descriptor(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_IMAGE_FORMAT_DESCRIPTOR> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_IMAGE_FORMAT_DESCRIPTOR> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_IMAGE_FORMAT_DESCRIPTOR> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_IMAGE_FORMAT_DESCRIPTOR> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_IMAGE_FORMAT_DESCRIPTOR>(DIMBO_HERE).cl_error()),(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_IMAGE_FORMAT_DESCRIPTOR>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_IMAGE_FORMAT_DESCRIPTOR")));
  }
  void test_cl_invalid_command_queue(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_COMMAND_QUEUE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_COMMAND_QUEUE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_COMMAND_QUEUE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_COMMAND_QUEUE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_COMMAND_QUEUE>(DIMBO_HERE).cl_error()),(CL_INVALID_COMMAND_QUEUE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_COMMAND_QUEUE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_COMMAND_QUEUE")));
  }
  void test_cl_invalid_build_options(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_BUILD_OPTIONS> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_BUILD_OPTIONS> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_BUILD_OPTIONS> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_BUILD_OPTIONS> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_BUILD_OPTIONS>(DIMBO_HERE).cl_error()),(CL_INVALID_BUILD_OPTIONS));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_BUILD_OPTIONS>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_BUILD_OPTIONS")));
  }
  void test_cl_out_of_resources(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_OUT_OF_RESOURCES> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_OUT_OF_RESOURCES> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_OUT_OF_RESOURCES> >::value));
    TS_ASSERT((std::is_base_of<std::runtime_error,Cl_Error_No<CL_OUT_OF_RESOURCES> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_OUT_OF_RESOURCES>(DIMBO_HERE).cl_error()),(CL_OUT_OF_RESOURCES));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_OUT_OF_RESOURCES>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_OUT_OF_RESOURCES")));
  }
  void test_cl_invalid_event_wait_list(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_EVENT_WAIT_LIST> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_EVENT_WAIT_LIST> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_EVENT_WAIT_LIST> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_EVENT_WAIT_LIST> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_EVENT_WAIT_LIST>(DIMBO_HERE).cl_error()),(CL_INVALID_EVENT_WAIT_LIST));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_EVENT_WAIT_LIST>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_EVENT_WAIT_LIST")));
  }
  void test_cl_invalid_global_work_size(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_GLOBAL_WORK_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_GLOBAL_WORK_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_GLOBAL_WORK_SIZE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_GLOBAL_WORK_SIZE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_GLOBAL_WORK_SIZE>(DIMBO_HERE).cl_error()),(CL_INVALID_GLOBAL_WORK_SIZE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_GLOBAL_WORK_SIZE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_GLOBAL_WORK_SIZE")));
  }
  void test_cl_invalid_mem_object(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_MEM_OBJECT> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_MEM_OBJECT> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_MEM_OBJECT> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_MEM_OBJECT> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_MEM_OBJECT>(DIMBO_HERE).cl_error()),(CL_INVALID_MEM_OBJECT));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_MEM_OBJECT>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_MEM_OBJECT")));
  }
  void test_cl_invalid_image_size(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_IMAGE_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_IMAGE_SIZE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_IMAGE_SIZE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_IMAGE_SIZE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_IMAGE_SIZE>(DIMBO_HERE).cl_error()),(CL_INVALID_IMAGE_SIZE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_IMAGE_SIZE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_IMAGE_SIZE")));
  }
  void test_cl_invalid_device(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Cl_Error_No<CL_INVALID_DEVICE> >::value));
    TS_ASSERT((std::is_base_of<Exception,Cl_Error_No<CL_INVALID_DEVICE> >::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Cl_Error_No<CL_INVALID_DEVICE> >::value));
    TS_ASSERT((std::is_base_of<std::invalid_argument,Cl_Error_No<CL_INVALID_DEVICE> >::value));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_DEVICE>(DIMBO_HERE).cl_error()),(CL_INVALID_DEVICE));
    TS_ASSERT_EQUALS((Cl_Error_No<CL_INVALID_DEVICE>(DIMBO_HERE).what()),(std::string("Dimbo.Cl: CL_INVALID_DEVICE")));
  }
  void test_other_cl_error(void)
  {
    TS_ASSERT((std::is_base_of<Dimbo::Exception,Other_Cl_Error>::value));
    TS_ASSERT((std::is_base_of<Exception,Other_Cl_Error>::value));
    TS_ASSERT((std::is_base_of<Cl_Error,Other_Cl_Error>::value));
    TS_ASSERT((std::is_base_of<std::exception,Other_Cl_Error>::value));
    TS_ASSERT_EQUALS((Other_Cl_Error(-10,DIMBO_HERE).cl_error()),(-10));
    TS_ASSERT_EQUALS((Other_Cl_Error(-10,DIMBO_HERE).what()),(std::string("Dimbo.Cl: other error")));
  }
};

#endif /* DIMBO_CL_CL_ERRORS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
