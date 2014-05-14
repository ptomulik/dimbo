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

// dimbo/test/unit/dimbo/cl/device.t.h

/** // doc: dimbo/test/unit/dimbo/cl/device.t.h {{{
 * \file dimbo/test/unit/dimbo/cl/device.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_DEVICE_T_H_INCLUDED
#define DIMBO_CL_DEVICE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/cl/device.hpp>

namespace Dimbo { namespace Cl { class Device_TestSuite; } }

/** // doc: class Dimbo::Cl::Device_TestSuite {{{
 * \brief Unit tests for Dimbo::Cl::Device class
 */ // }}}
class Dimbo::Cl::Device_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_ctor_default() {{{
   * \brief Ensure that id() == NULL by default.
   */ // }}}
  void test_ctor_default( )
  {
    Device d;
    TS_ASSERT_EQUALS(d.id(), reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_ctor_assign() {{{
   * \brief Ensure that assigining constructor works as expected.
   */ // }}}
  void test_ctor_assign( )
  {
    Device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS(d1.id(), reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_ctor_copy() {{{
   * \brief Ensure that copy constructor works as expected.
   */ // }}}
  void test_ctor_copy( )
  {
    Device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    Device d2(d1);
    TS_ASSERT_EQUALS(d2.id(), d1.id());
  }
  /** // doc: test_op_assign() {{{
   * \brief Ensure that assignment operator works.
   */ // }}}
  void test_op_assign( )
  {
    Device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    Device d2;
    TS_ASSERT_EQUALS(&(d2 = d1), &d2);
    TS_ASSERT_EQUALS(d2.id(), d1.id());
  }
  /** // doc: test_op_cast() {{{
   * \brief Ensure that conversion operator works.
   */ // }}}
  void test_op_cast( )
  {
    Device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS((cl_device_id)d1, reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_assign() {{{
   * \brief Ensure that assign() method works.
   */ // }}}
  void test_assign( )
  {
    Device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    Device d2;
    d2.assign(d1);
    TS_ASSERT_EQUALS(d2.id(), d1.id());
  }
  /** // doc: test_is_initialized_1() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_1( )
  {
    Device d;
    TS_ASSERT(!d.is_initialized());
  }
  /** // doc: test_is_initialized_2() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_2( )
  {
    Device d(reinterpret_cast<cl_device_id>(NULL));
    TS_ASSERT(!d.is_initialized());
  }
  /** // doc: test_is_initialized_3() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_3( )
  {
    Device d(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT(d.is_initialized());
  }
  /** // doc: test_id_1() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_1( )
  {
    Device d(reinterpret_cast<cl_device_id>(NULL));
    TS_ASSERT_EQUALS(d.id(),reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_id_2() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_2( )
  {
    Device d(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS(d.id(),reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_get_valid_id_1() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_1( )
  {
    Device d(reinterpret_cast<cl_device_id>(NULL));
    TS_ASSERT_THROWS(d.get_valid_id(), DIMBO_CL_EXCEPTION(Uninitialized_Device));
  }
  /** // doc: test_get_valid_id_2() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_2( )
  {
    Device d(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS(d.get_valid_id(),reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_get_info_wrong_id() {{{
   * \brief Test get_info(CL_DEVICE_PROFILE, ...) on device object having wrong id.
   */ // }}}
  void test_get_info_wrong_id( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(reinterpret_cast<cl_device_id>(0x34556ul));
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PROFILE, 0, NULL, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_DEVICE>);
  }
  /** // doc: test_get_info_0() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test_get_info_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(0, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_1() {{{
   * \brief Test get_info(CL_DEVICE_PROFILE, 1, &value, NULL).
   */ // }}}
  void test_get_info_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    char value[1];
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PROFILE, 1, &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_type_0() {{{
   * \brief Test get_info(CL_DEVICE_TYPE, 0, NULL, &size).
   */ // }}}
  void test_get_info_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_TYPE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_type));
  }
  /** // doc: test_get_info_type_1() {{{
   * \brief Test get_info(CL_DEVICE_TYPE, ...).
   */ // }}}
  void test_get_info_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_type value;
    d.get_info(CL_DEVICE_TYPE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_DEVICE_TYPE_CPU);
  }
  /** // doc: test_get_info_vendor_id_0() {{{
   * \brief Test get_info(CL_DEVICE_VENDOR_ID, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_id_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_VENDOR_ID, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_vendor_id_1() {{{
   * \brief Test get_info(CL_DEVICE_VENDOR_ID, ...).
   */ // }}}
  void test_get_info_vendor_id_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_VENDOR_ID, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0x1002);
  }
  /** // doc: test_get_info_vendor_id_2() {{{
   * \brief Test get_info(CL_DEVICE_VENDOR_ID, ...).
   */ // }}}
  void test_get_info_vendor_id_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_VENDOR_ID, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0x10de);
  }
  /** // doc: test_get_info_max_compute_units_0() {{{
   * \brief Test get_info(CL_DEVICE_MAX_COMPUTE_UNITS, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_compute_units_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_COMPUTE_UNITS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_compute_units_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_COMPUTE_UNITS, ...).
   */ // }}}
  void test_get_info_max_compute_units_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_max_compute_units_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_COMPUTE_UNITS, ...).
   */ // }}}
  void test_get_info_max_compute_units_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 30);
  }
  /** // doc: test_get_info_max_work_item_dimensions_0() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_work_item_dimensions_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_work_item_dimensions_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, ...).
   */ // }}}
  void test_get_info_max_work_item_dimensions_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 3);
  }
  /** // doc: test_get_info_max_work_item_dimensions_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, ...).
   */ // }}}
  void test_get_info_max_work_item_dimensions_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 3);
  }
  /** // doc: test_get_info_max_work_item_sizes_0() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_ITEM_SIZES, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_work_item_sizes_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_WORK_ITEM_SIZES, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 3 * sizeof(size_t));
  }
  /** // doc: test_get_info_max_work_item_sizes_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_ITEM_SIZES, ...).
   */ // }}}
  void test_get_info_max_work_item_sizes_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value[3];
    d.get_info(CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], 1024);
    TS_ASSERT_EQUALS(value[1], 1024);
    TS_ASSERT_EQUALS(value[2], 1024);
  }
  /** // doc: test_get_info_max_work_item_sizes_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_ITEM_SIZES, ...).
   */ // }}}
  void test_get_info_max_work_item_sizes_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value[3];
    d.get_info(CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], 512);
    TS_ASSERT_EQUALS(value[1], 512);
    TS_ASSERT_EQUALS(value[2], 64);
  }
  /** // doc: test_get_info_max_work_group_size_0() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_GROUP_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_work_group_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_WORK_GROUP_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_max_work_group_size_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_GROUP_SIZE, ...).
   */ // }}}
  void test_get_info_max_work_group_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1024);
  }
  /** // doc: test_get_info_max_work_group_size_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WORK_GROUP_SIZE, ...).
   */ // }}}
  void test_get_info_max_work_group_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 512);
  }
  /** // doc: test_get_info_preferred_vector_width_char_0() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_char_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_char_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_char_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_preferred_vector_width_char_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_char_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_short_0() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_short_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_short_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_short_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_preferred_vector_width_short_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_short_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_int_0() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_int_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_int_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_int_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_preferred_vector_width_int_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_int_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_long_0() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_long_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_long_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_long_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_preferred_vector_width_long_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_long_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_float_0() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_float_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_float_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_float_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_preferred_vector_width_float_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_float_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_double_0() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_double_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_double_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_double_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_preferred_vector_width_double_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_double_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_half_0() {{{ * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF, 0, NULL, &size).  */ // }}}
  void test_get_info_preferred_vector_width_half_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_half_1() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_half_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_preferred_vector_width_half_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_half_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_native_vector_width_char_0() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_char_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_char_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR, ...).
   */ // }}}
  void test_get_info_native_vector_width_char_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_native_vector_width_char_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR, ...).
   */ // }}}
  void test_get_info_native_vector_width_char_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_short_0() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_short_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_short_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT, ...).
   */ // }}}
  void test_get_info_native_vector_width_short_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_native_vector_width_short_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT, ...).
   */ // }}}
  void test_get_info_native_vector_width_short_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_int_0() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_int_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_int_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT, ...).
   */ // }}}
  void test_get_info_native_vector_width_int_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_native_vector_width_int_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT, ...).
   */ // }}}
  void test_get_info_native_vector_width_int_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_long_0() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_long_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_long_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG, ...).
   */ // }}}
  void test_get_info_native_vector_width_long_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_native_vector_width_long_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG, ...).
   */ // }}}
  void test_get_info_native_vector_width_long_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_float_0() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_float_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_float_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT, ...).
   */ // }}}
  void test_get_info_native_vector_width_float_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_native_vector_width_float_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT, ...).
   */ // }}}
  void test_get_info_native_vector_width_float_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_double_0() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_double_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_double_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, ...).
   */ // }}}
  void test_get_info_native_vector_width_double_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_native_vector_width_double_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, ...).
   */ // }}}
  void test_get_info_native_vector_width_double_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_half_0() {{{ * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF, 0, NULL, &size).  */ // }}}
  void test_get_info_native_vector_width_half_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_half_1() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF, ...).
   */ // }}}
  void test_get_info_native_vector_width_half_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_native_vector_width_half_2() {{{
   * \brief Test get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF, ...).
   */ // }}}
  void test_get_info_native_vector_width_half_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_max_clock_frequency_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_CLOCK_FREQUENCY, 0, NULL, &size).  */ // }}}
  void test_get_info_max_clock_frequency_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_CLOCK_FREQUENCY, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_clock_frequency_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_CLOCK_FREQUENCY, ...).
   */ // }}}
  void test_get_info_max_clock_frequency_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2401);
  }
  /** // doc: test_get_info_max_clock_frequency_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_CLOCK_FREQUENCY, ...).
   */ // }}}
  void test_get_info_max_clock_frequency_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1296);
  }
  /** // doc: test_get_info_address_bits_0() {{{ * \brief Test get_info(CL_DEVICE_ADDRESS_BITS, 0, NULL, &size).  */ // }}}
  void test_get_info_address_bits_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_ADDRESS_BITS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_address_bits_1() {{{
   * \brief Test get_info(CL_DEVICE_ADDRESS_BITS, ...).
   */ // }}}
  void test_get_info_address_bits_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_ADDRESS_BITS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 64);
  }
  /** // doc: test_get_info_address_bits_2() {{{
   * \brief Test get_info(CL_DEVICE_ADDRESS_BITS, ...).
   */ // }}}
  void test_get_info_address_bits_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_ADDRESS_BITS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 32);
  }
  /** // doc: test_get_info_max_mem_alloc_size_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_MEM_ALLOC_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_max_mem_alloc_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_MEM_ALLOC_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_max_mem_alloc_size_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_MEM_ALLOC_SIZE, ...).
   */ // }}}
  void test_get_info_max_mem_alloc_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4214191104ul);
  }
  /** // doc: test_get_info_max_mem_alloc_size_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_MEM_ALLOC_SIZE, ...).
   */ // }}}
  void test_get_info_max_mem_alloc_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1073692672ul);
  }
  /** // doc: test_get_info_image_support_0() {{{ * \brief Test get_info(CL_DEVICE_IMAGE_SUPPORT, 0, NULL, &size).  */ // }}}
  void test_get_info_image_support_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE_SUPPORT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_image_support_1() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_SUPPORT, ...).
   */ // }}}
  void test_get_info_image_support_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_IMAGE_SUPPORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_image_support_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_SUPPORT, ...).
   */ // }}}
  void test_get_info_image_support_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(CL_DEVICE_IMAGE_SUPPORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_max_read_image_args_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_READ_IMAGE_ARGS, 0, NULL, &size).  */ // }}}
  void test_get_info_max_read_image_args_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_READ_IMAGE_ARGS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_read_image_args_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_READ_IMAGE_ARGS, ...).
   */ // }}}
  void test_get_info_max_read_image_args_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_READ_IMAGE_ARGS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_max_read_image_args_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_READ_IMAGE_ARGS, ...).
   */ // }}}
  void test_get_info_max_read_image_args_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_READ_IMAGE_ARGS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_max_write_image_args_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, 0, NULL, &size).  */ // }}}
  void test_get_info_max_write_image_args_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_write_image_args_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, ...).
   */ // }}}
  void test_get_info_max_write_image_args_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_max_write_image_args_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, ...).
   */ // }}}
  void test_get_info_max_write_image_args_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_WRITE_IMAGE_ARGS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_image2d_max_width_0() {{{ * \brief Test get_info(CL_DEVICE_IMAGE2D_MAX_WIDTH, 0, NULL, &size).  */ // }}}
  void test_get_info_image2d_max_width_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE2D_MAX_WIDTH, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image2d_max_width_1() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE2D_MAX_WIDTH, ...).
   */ // }}}
  void test_get_info_image2d_max_width_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE2D_MAX_WIDTH, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8192);
  }
  /** // doc: test_get_info_image2d_max_width_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE2D_MAX_WIDTH, ...).
   */ // }}}
  void test_get_info_image2d_max_width_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE2D_MAX_WIDTH, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4096);
  }
  /** // doc: test_get_info_image2d_max_height_0() {{{ * \brief Test get_info(CL_DEVICE_IMAGE2D_MAX_HEIGHT, 0, NULL, &size).  */ // }}}
  void test_get_info_image2d_max_height_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE2D_MAX_HEIGHT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image2d_max_height_1() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE2D_MAX_HEIGHT, ...).
   */ // }}}
  void test_get_info_image2d_max_height_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE2D_MAX_HEIGHT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8192);
  }
  /** // doc: test_get_info_image2d_max_height_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE2D_MAX_HEIGHT, ...).
   */ // }}}
  void test_get_info_image2d_max_height_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE2D_MAX_HEIGHT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16383);
  }
  /** // doc: test_get_info_image3d_max_width_0() {{{ * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_WIDTH, 0, NULL, &size).  */ // }}}
  void test_get_info_image3d_max_width_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_WIDTH, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image3d_max_width_1() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_WIDTH, ...).
   */ // }}}
  void test_get_info_image3d_max_width_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_WIDTH, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_width_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_WIDTH, ...).
   */ // }}}
  void test_get_info_image3d_max_width_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_WIDTH, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_height_0() {{{ * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_HEIGHT, 0, NULL, &size).  */ // }}}
  void test_get_info_image3d_max_height_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_HEIGHT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image3d_max_height_1() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_HEIGHT, ...).
   */ // }}}
  void test_get_info_image3d_max_height_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_HEIGHT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_height_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_HEIGHT, ...).
   */ // }}}
  void test_get_info_image3d_max_height_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_HEIGHT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_depth_0() {{{ * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_DEPTH, 0, NULL, &size).  */ // }}}
  void test_get_info_image3d_max_depth_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_DEPTH, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image3d_max_depth_1() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_DEPTH, ...).
   */ // }}}
  void test_get_info_image3d_max_depth_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_DEPTH, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_depth_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE3D_MAX_DEPTH, ...).
   */ // }}}
  void test_get_info_image3d_max_depth_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE3D_MAX_DEPTH, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_max_samplers_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_SAMPLERS, 0, NULL, &size).  */ // }}}
  void test_get_info_max_samplers_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_SAMPLERS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_samplers_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_SAMPLERS, ...).
   */ // }}}
  void test_get_info_max_samplers_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_SAMPLERS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_max_samplers_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_SAMPLERS, ...).
   */ // }}}
  void test_get_info_max_samplers_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_SAMPLERS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_max_parameter_size_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_PARAMETER_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_max_parameter_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_PARAMETER_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_max_parameter_size_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_PARAMETER_SIZE, ...).
   */ // }}}
  void test_get_info_max_parameter_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_MAX_PARAMETER_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4096);
  }
  /** // doc: test_get_info_max_parameter_size_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_PARAMETER_SIZE, ...).
   */ // }}}
  void test_get_info_max_parameter_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_MAX_PARAMETER_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4352);
  }
  /** // doc: test_get_info_mem_base_addr_align_0() {{{ * \brief Test get_info(CL_DEVICE_MEM_BASE_ADDR_ALIGN, 0, NULL, &size).  */ // }}}
  void test_get_info_mem_base_addr_align_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MEM_BASE_ADDR_ALIGN, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_mem_base_addr_align_1() {{{
   * \brief Test get_info(CL_DEVICE_MEM_BASE_ADDR_ALIGN, ...).
   */ // }}}
  void test_get_info_mem_base_addr_align_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MEM_BASE_ADDR_ALIGN, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1024);
  }
  /** // doc: test_get_info_mem_base_addr_align_2() {{{
   * \brief Test get_info(CL_DEVICE_MEM_BASE_ADDR_ALIGN, ...).
   */ // }}}
  void test_get_info_mem_base_addr_align_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MEM_BASE_ADDR_ALIGN, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_min_data_type_align_size_0() {{{ * \brief Test get_info(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_min_data_type_align_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_min_data_type_align_size_1() {{{
   * \brief Test get_info(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, ...).
   */ // }}}
  void test_get_info_min_data_type_align_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_min_data_type_align_size_2() {{{
   * \brief Test get_info(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, ...).
   */ // }}}
  void test_get_info_min_data_type_align_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_single_fp_config_0() {{{ * \brief Test get_info(CL_DEVICE_SINGLE_FP_CONFIG, 0, NULL, &size).  */ // }}}
  void test_get_info_single_fp_config_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_SINGLE_FP_CONFIG, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_fp_config));
  }
  /** // doc: test_get_info_single_fp_config_1() {{{
   * \brief Test get_info(CL_DEVICE_SINGLE_FP_CONFIG, ...).
   */ // }}}
  void test_get_info_single_fp_config_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_fp_config value;
    d.get_info(CL_DEVICE_SINGLE_FP_CONFIG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA);
  }
  /** // doc: test_get_info_single_fp_config_2() {{{
   * \brief Test get_info(CL_DEVICE_SINGLE_FP_CONFIG, ...).
   */ // }}}
  void test_get_info_single_fp_config_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_fp_config value;
    d.get_info(CL_DEVICE_SINGLE_FP_CONFIG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA);
  }
  /** // doc: test_get_info_global_mem_cache_type_0() {{{ * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_cache_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_mem_cache_type));
  }
  /** // doc: test_get_info_global_mem_cache_type_1() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, ...).
   */ // }}}
  void test_get_info_global_mem_cache_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_mem_cache_type value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_READ_WRITE_CACHE);
  }
  /** // doc: test_get_info_global_mem_cache_type_2() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, ...).
   */ // }}}
  void test_get_info_global_mem_cache_type_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_mem_cache_type value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_NONE);
  }
  /** // doc: test_get_info_global_mem_cacheline_size_0() {{{ * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_cacheline_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_global_mem_cacheline_size_1() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, ...).
   */ // }}}
  void test_get_info_global_mem_cacheline_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 64);
  }
  /** // doc: test_get_info_global_mem_cacheline_size_2() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, ...).
   */ // }}}
  void test_get_info_global_mem_cacheline_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_global_mem_cache_size_0() {{{ * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_cache_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_global_mem_cache_size_1() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, ...).
   */ // }}}
  void test_get_info_global_mem_cache_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 32768ul);
  }
  /** // doc: test_get_info_global_mem_cache_size_2() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, ...).
   */ // }}}
  void test_get_info_global_mem_cache_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_global_mem_size_0() {{{ * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_GLOBAL_MEM_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_global_mem_size_1() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_SIZE, ...).
   */ // }}}
  void test_get_info_global_mem_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16856764416ul);
  }
  /** // doc: test_get_info_global_mem_size_2() {{{
   * \brief Test get_info(CL_DEVICE_GLOBAL_MEM_SIZE, ...).
   */ // }}}
  void test_get_info_global_mem_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4294770688ul);
  }
  /** // doc: test_get_info_max_constant_buffer_size_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_max_constant_buffer_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_max_constant_buffer_size_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, ...).
   */ // }}}
  void test_get_info_max_constant_buffer_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_max_constant_buffer_size_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, ...).
   */ // }}}
  void test_get_info_max_constant_buffer_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_max_constant_args_0() {{{ * \brief Test get_info(CL_DEVICE_MAX_CONSTANT_ARGS, 0, NULL, &size).  */ // }}}
  void test_get_info_max_constant_args_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_MAX_CONSTANT_ARGS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_constant_args_1() {{{
   * \brief Test get_info(CL_DEVICE_MAX_CONSTANT_ARGS, ...).
   */ // }}}
  void test_get_info_max_constant_args_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_CONSTANT_ARGS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_max_constant_args_2() {{{
   * \brief Test get_info(CL_DEVICE_MAX_CONSTANT_ARGS, ...).
   */ // }}}
  void test_get_info_max_constant_args_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(CL_DEVICE_MAX_CONSTANT_ARGS, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 9);
  }
  /** // doc: test_get_info_local_mem_type_0() {{{ * \brief Test get_info(CL_DEVICE_LOCAL_MEM_TYPE, 0, NULL, &size).  */ // }}}
  void test_get_info_local_mem_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_LOCAL_MEM_TYPE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_local_mem_type));
  }
  /** // doc: test_get_info_local_mem_type_1() {{{
   * \brief Test get_info(CL_DEVICE_LOCAL_MEM_TYPE, ...).
   */ // }}}
  void test_get_info_local_mem_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_local_mem_type value;
    d.get_info(CL_DEVICE_LOCAL_MEM_TYPE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_GLOBAL);
  }
  /** // doc: test_get_info_local_mem_type_2() {{{
   * \brief Test get_info(CL_DEVICE_LOCAL_MEM_TYPE, ...).
   */ // }}}
  void test_get_info_local_mem_type_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_local_mem_type value;
    d.get_info(CL_DEVICE_LOCAL_MEM_TYPE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_LOCAL);
  }
  /** // doc: test_get_info_local_mem_size_0() {{{ * \brief Test get_info(CL_DEVICE_LOCAL_MEM_SIZE, 0, NULL, &size).  */ // }}}
  void test_get_info_local_mem_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_LOCAL_MEM_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_local_mem_size_1() {{{
   * \brief Test get_info(CL_DEVICE_LOCAL_MEM_SIZE, ...).
   */ // }}}
  void test_get_info_local_mem_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(CL_DEVICE_LOCAL_MEM_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 32768);
  }
  /** // doc: test_get_info_local_mem_size_2() {{{
   * \brief Test get_info(CL_DEVICE_LOCAL_MEM_SIZE, ...).
   */ // }}}
  void test_get_info_local_mem_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(CL_DEVICE_LOCAL_MEM_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16384);
  }
  /** // doc: test_get_info_error_correction_support_0() {{{ * \brief Test get_info(CL_DEVICE_ERROR_CORRECTION_SUPPORT, 0, NULL, &size).  */ // }}}
  void test_get_info_error_correction_support_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_ERROR_CORRECTION_SUPPORT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_error_correction_support_1() {{{
   * \brief Test get_info(CL_DEVICE_ERROR_CORRECTION_SUPPORT, ...).
   */ // }}}
  void test_get_info_error_correction_support_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_ERROR_CORRECTION_SUPPORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_error_correction_support_2() {{{
   * \brief Test get_info(CL_DEVICE_ERROR_CORRECTION_SUPPORT, ...).
   */ // }}}
  void test_get_info_error_correction_support_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(CL_DEVICE_ERROR_CORRECTION_SUPPORT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_host_unified_memory_0() {{{ * \brief Test get_info(CL_DEVICE_HOST_UNIFIED_MEMORY, 0, NULL, &size).  */ // }}}
  void test_get_info_host_unified_memory_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_HOST_UNIFIED_MEMORY, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_host_unified_memory_1() {{{
   * \brief Test get_info(CL_DEVICE_HOST_UNIFIED_MEMORY, ...).
   */ // }}}
  void test_get_info_host_unified_memory_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_HOST_UNIFIED_MEMORY, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_host_unified_memory_2() {{{
   * \brief Test get_info(CL_DEVICE_HOST_UNIFIED_MEMORY, ...).
   */ // }}}
  void test_get_info_host_unified_memory_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(CL_DEVICE_HOST_UNIFIED_MEMORY, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_profiling_timer_resolution_0() {{{ * \brief Test get_info(CL_DEVICE_PROFILING_TIMER_RESOLUTION, 0, NULL, &size).  */ // }}}
  void test_get_info_profiling_timer_resolution_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PROFILING_TIMER_RESOLUTION, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_profiling_timer_resolution_1() {{{
   * \brief Test get_info(CL_DEVICE_PROFILING_TIMER_RESOLUTION, ...).
   */ // }}}
  void test_get_info_profiling_timer_resolution_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_PROFILING_TIMER_RESOLUTION, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_profiling_timer_resolution_2() {{{
   * \brief Test get_info(CL_DEVICE_PROFILING_TIMER_RESOLUTION, ...).
   */ // }}}
  void test_get_info_profiling_timer_resolution_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(CL_DEVICE_PROFILING_TIMER_RESOLUTION, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1000);
  }
  /** // doc: test_get_info_endian_little_0() {{{ * \brief Test get_info(CL_DEVICE_ENDIAN_LITTLE, 0, NULL, &size).  */ // }}}
  void test_get_info_endian_little_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_ENDIAN_LITTLE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_endian_little_1() {{{
   * \brief Test get_info(CL_DEVICE_ENDIAN_LITTLE, ...).
   */ // }}}
  void test_get_info_endian_little_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_ENDIAN_LITTLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_endian_little_2() {{{
   * \brief Test get_info(CL_DEVICE_ENDIAN_LITTLE, ...).
   */ // }}}
  void test_get_info_endian_little_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(CL_DEVICE_ENDIAN_LITTLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_available_0() {{{ * \brief Test get_info(CL_DEVICE_AVAILABLE, 0, NULL, &size).  */ // }}}
  void test_get_info_available_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_AVAILABLE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_available_1() {{{
   * \brief Test get_info(CL_DEVICE_AVAILABLE, ...).
   */ // }}}
  void test_get_info_available_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_AVAILABLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_available_2() {{{
   * \brief Test get_info(CL_DEVICE_AVAILABLE, ...).
   */ // }}}
  void test_get_info_available_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(CL_DEVICE_AVAILABLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_compiler_available_0() {{{ * \brief Test get_info(CL_DEVICE_COMPILER_AVAILABLE, 0, NULL, &size).  */ // }}}
  void test_get_info_compiler_available_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_COMPILER_AVAILABLE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_compiler_available_1() {{{
   * \brief Test get_info(CL_DEVICE_COMPILER_AVAILABLE, ...).
   */ // }}}
  void test_get_info_compiler_available_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_COMPILER_AVAILABLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_compiler_available_2() {{{
   * \brief Test get_info(CL_DEVICE_COMPILER_AVAILABLE, ...).
   */ // }}}
  void test_get_info_compiler_available_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(CL_DEVICE_COMPILER_AVAILABLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_execution_capabilities_0() {{{
   *  \brief Test get_info(CL_DEVICE_EXECUTION_CAPABILITIES, 0, NULL, &size).
   */ // }}}
  void test_get_info_execution_capabilities_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_EXECUTION_CAPABILITIES, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_exec_capabilities));
  }
  /** // doc: test_get_info_execution_capabilities_1() {{{
   * \brief Test get_info(CL_DEVICE_EXECUTION_CAPABILITIES, ...).
   */ // }}}
  void test_get_info_execution_capabilities_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_exec_capabilities value;
    d.get_info(CL_DEVICE_EXECUTION_CAPABILITIES, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL);
  }
  /** // doc: test_get_info_execution_capabilities_2() {{{
   * \brief Test get_info(CL_DEVICE_EXECUTION_CAPABILITIES, ...).
   */ // }}}
  void test_get_info_execution_capabilities_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_exec_capabilities value;
    d.get_info(CL_DEVICE_EXECUTION_CAPABILITIES, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_EXEC_KERNEL);
  }
  /** // doc: test_get_info_queue_properties_0() {{{ * \brief Test get_info(CL_DEVICE_QUEUE_PROPERTIES, 0, NULL, &size).  */ // }}}
  void test_get_info_queue_properties_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_QUEUE_PROPERTIES, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_command_queue_properties));
  }
  /** // doc: test_get_info_queue_properties_1() {{{
   * \brief Test get_info(CL_DEVICE_QUEUE_PROPERTIES, ...).
   */ // }}}
  void test_get_info_queue_properties_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_command_queue_properties value;
    d.get_info(CL_DEVICE_QUEUE_PROPERTIES, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_QUEUE_PROFILING_ENABLE);
  }
  /** // doc: test_get_info_queue_properties_2() {{{
   * \brief Test get_info(CL_DEVICE_QUEUE_PROPERTIES, ...).
   */ // }}}
  void test_get_info_queue_properties_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_command_queue_properties value;
    d.get_info(CL_DEVICE_QUEUE_PROPERTIES, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE);
  }
  /** // doc: test_get_info_platform_0() {{{ * \brief Test get_info(CL_DEVICE_PLATFORM, 0, NULL, &size).  */ // }}}
  void test_get_info_platform_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PLATFORM, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_platform_id));
  }
  /** // doc: test_get_info_platform_1() {{{
   * \brief Test get_info(CL_DEVICE_PLATFORM, ...).
   */ // }}}
  void test_get_info_platform_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_platform_id value;
    d.get_info(CL_DEVICE_PLATFORM, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, T::Newton_clGetPlatformIDs::platforms[0]);
  }
  /** // doc: test_get_info_platform_2() {{{
   * \brief Test get_info(CL_DEVICE_PLATFORM, ...).
   */ // }}}
  void test_get_info_platform_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_platform_id value;
    d.get_info(CL_DEVICE_PLATFORM, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_info_name_0() {{{
   * \brief Test get_info(CL_DEVICE_NAME, 0, NULL, &size).
   */ // }}}
  void test_get_info_name_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DEVICE_NAME, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 48);
  }
  /** // doc: test_get_info_name_1() {{{
   * \brief Test get_info(CL_DEVICE_NAME, 0, NULL, &size).
   */ // }}}
  void test_get_info_name_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(CL_DEVICE_NAME, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 12);
  }
//  /** // doc: test_get_info_name_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_name_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[48];
    p.get_info(CL_DEVICE_NAME, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
  }
//  /** // doc: test_get_info_name_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_name_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[12];
    p.get_info(CL_DEVICE_NAME, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "Tesla C1060");
  }
  /** // doc: test_get_info_vendor_0() {{{
   * \brief Test get_info(CL_DEVICE_VENDOR, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DEVICE_VENDOR, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
  /** // doc: test_get_info_vendor_1() {{{
   * \brief Test get_info(CL_DEVICE_VENDOR, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(CL_DEVICE_VENDOR, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 19);
  }
//  /** // doc: test_get_info_vendor_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_vendor_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[13];
    p.get_info(CL_DEVICE_VENDOR, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "GenuineIntel");
  }
//  /** // doc: test_get_info_vendor_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_vendor_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[20];
    p.get_info(CL_DEVICE_VENDOR, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "NVIDIA Corporation");
  }
  /** // doc: test_get_info_driver_version_0() {{{
   * \brief Test get_info(CL_DEVICE_DRIVER_VERSION, 0, NULL, &size).
   */ // }}}
  void test_get_info_driver_version_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DRIVER_VERSION, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 14);
  }
  /** // doc: test_get_info_driver_version_1() {{{
   * \brief Test get_info(CL_DEVICE_DRIVER_VERSION, 0, NULL, &size).
   */ // }}}
  void test_get_info_driver_version_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(CL_DRIVER_VERSION, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 7);
  }
//  /** // doc: test_get_info_driver_version_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_driver_version_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[14];
    p.get_info(CL_DRIVER_VERSION, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "1348.4 (sse2)");
  }
//  /** // doc: test_get_info_driver_version_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_driver_version_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[7];
    p.get_info(CL_DRIVER_VERSION, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "319.76");
  }
  /** // doc: test_get_info_driver_profile_0() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_PROFILE, 0, NULL, &size).
   */ // }}}
  void test_get_info_driver_profile_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DEVICE_PROFILE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
  /** // doc: test_get_info_device_profile_1() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_PROFILE, 0, NULL, &size).
   */ // }}}
  void test_get_info_device_profile_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(CL_DEVICE_PROFILE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
//  /** // doc: test_get_info_device_profile_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_device_profile_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[13];
    p.get_info(CL_DEVICE_PROFILE, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "FULL_PROFILE");
  }
//  /** // doc: test_get_info_device_profile_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_device_profile_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[13];
    p.get_info(CL_DEVICE_PROFILE, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "FULL_PROFILE");
  }
  /** // doc: test_get_info_version_0() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_VERSION, 0, NULL, &size).
   */ // }}}
  void test_get_info_version_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DEVICE_VERSION, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 28);
  }
  /** // doc: test_get_info_version_1() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_VERSION, 0, NULL, &size).
   */ // }}}
  void test_get_info_version_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(CL_DEVICE_VERSION, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 16);
  }
//  /** // doc: test_get_info_version_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_version_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[28];
    p.get_info(CL_DEVICE_VERSION, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "OpenCL 1.2 AMD-APP (1348.4)");
  }
//  /** // doc: test_get_info_version_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_version_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[16];
    p.get_info(CL_DEVICE_VERSION, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "OpenCL 1.0 CUDA");
  }
  /** // doc: test_get_info_extensions_0() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_EXTENSIONS, 0, NULL, &size).
   */ // }}}
  void test_get_info_extensions_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DEVICE_EXTENSIONS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 416);
  }
  /** // doc: test_get_info_extensions_1() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_EXTENSIONS, 0, NULL, &size).
   */ // }}}
  void test_get_info_extensions_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(CL_DEVICE_EXTENSIONS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 281);
  }
//  /** // doc: test_get_info_extensions_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_extensions_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[416];
    p.get_info(CL_DEVICE_EXTENSIONS, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "cl_khr_fp64 cl_amd_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_byte_addressable_store cl_khr_gl_sharing cl_ext_device_fission cl_amd_device_attribute_query cl_amd_vec3 cl_amd_printf cl_amd_media_ops cl_amd_media_ops2 cl_amd_popcnt");
  }
//  /** // doc: test_get_info_extensions_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_extensions_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[281];
    p.get_info(CL_DEVICE_EXTENSIONS, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll  cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_fp6");
  }
  /** // doc: test_get_info_double_fp_config_0() {{{
   *  \brief Test get_info(CL_DEVICE_DOUBLE_FP_CONFIG, 0, NULL, &size).
   */ // }}}
  void test_get_info_double_fp_config_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_DOUBLE_FP_CONFIG, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_fp_config));
  }
  /** // doc: test_get_info_double_fp_config_1() {{{
   *  \brief Test get_info(CL_DEVICE_DOUBLE_FP_CONFIG, 0, NULL, &size).
   */ // }}}
  void test_get_info_double_fp_config_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_DOUBLE_FP_CONFIG, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_double_fp_config_2() {{{
   * \brief Test get_info(CL_DEVICE_DOUBLE_FP_CONFIG, ...).
   */ // }}}
  void test_get_info_double_fp_config_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_fp_config value;
    d.get_info(CL_DEVICE_DOUBLE_FP_CONFIG, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA);
  }
  /** // doc: test_get_info_double_fp_config_3() {{{
   * \brief Test get_info(CL_DEVICE_DOUBLE_FP_CONFIG, ...).
   */ // }}}
  void test_get_info_double_fp_config_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_fp_config value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_DOUBLE_FP_CONFIG, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_linker_available_0() {{{
   *  \brief Test get_info(CL_DEVICE_LINKER_AVAILABLE, 0, NULL, &size).
   */ // }}}
  void test_get_info_linker_available_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_LINKER_AVAILABLE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_linker_available_1() {{{
   *  \brief Test get_info(CL_DEVICE_LINKER_AVAILABLE, 0, NULL, &size).
   */ // }}}
  void test_get_info_linker_available_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_LINKER_AVAILABLE, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_linker_available_2() {{{
   * \brief Test get_info(CL_DEVICE_LINKER_AVAILABLE, ...).
   */ // }}}
  void test_get_info_linker_available_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_LINKER_AVAILABLE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_FALSE);
  }
  /** // doc: test_get_info_linker_available_3() {{{
   * \brief Test get_info(CL_DEVICE_LINKER_AVAILABLE, ...).
   */ // }}}
  void test_get_info_linker_available_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_LINKER_AVAILABLE, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_built_in_kernels_0() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_BUILT_IN_KERNELS, 0, NULL, &size).
   */ // }}}
  void test_get_info_built_in_kernels_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(CL_DEVICE_BUILT_IN_KERNELS, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 1);
  }
  /** // doc: test_get_info_built_in_kernels_1() {{{
   * \brief Test get_info(CL_DEVICE_DEVICE_BUILT_IN_KERNELS, 0, NULL, &size).
   */ // }}}
  void test_get_info_built_in_kernels_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(p.get_info(CL_DEVICE_BUILT_IN_KERNELS, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
//  /** // doc: test_get_info_built_in_kernels_2() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_built_in_kernels_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[1];
    p.get_info(CL_DEVICE_BUILT_IN_KERNELS, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "");
  }
//  /** // doc: test_get_info_built_in_kernels_3() {{{
//   * \brief Test get_info(CL_DEVICE_PROFILE, ...).
//   */ // }}}
  void test_get_info_built_in_kernels_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[1];
    TS_ASSERT_THROWS(p.get_info(CL_DEVICE_BUILT_IN_KERNELS, sizeof(value), value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_max_buffer_size_0() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_buffer_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image_max_buffer_size_1() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_buffer_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_max_buffer_size_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, ...).
   */ // }}}
  void test_get_info_image_max_buffer_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_image_max_buffer_size_3() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, ...).
   */ // }}}
  void test_get_info_image_max_buffer_size_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_max_array_size_0() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_array_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image_max_array_size_1() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_array_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_max_array_size_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, ...).
   */ // }}}
  void test_get_info_image_max_array_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image_max_array_size_3() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, ...).
   */ // }}}
  void test_get_info_image_max_array_size_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_parent_device_id_0() {{{
   *  \brief Test get_info(CL_DEVICE_PARENT_DEVICE, 0, NULL, &size).
   */ // }}}
  void test_get_info_parent_device_id_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PARENT_DEVICE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_id));
  }
  /** // doc: test_get_info_parent_device_id_1() {{{
   *  \brief Test get_info(CL_DEVICE_PARENT_DEVICE, 0, NULL, &size).
   */ // }}}
  void test_get_info_parent_device_id_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARENT_DEVICE, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_parent_device_id_2() {{{
   * \brief Test get_info(CL_DEVICE_PARENT_DEVICE, ...).
   */ // }}}
  void test_get_info_parent_device_id_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_id value;
    d.get_info(CL_DEVICE_PARENT_DEVICE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_get_info_parent_device_id_3() {{{
   * \brief Test get_info(CL_DEVICE_PARENT_DEVICE, ...).
   */ // }}}
  void test_get_info_parent_device_id_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_id value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARENT_DEVICE, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_max_sub_devices_0() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_max_sub_devices_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_partition_max_sub_devices_1() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_max_sub_devices_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_max_sub_devices_2() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, ...).
   */ // }}}
  void test_get_info_partition_max_sub_devices_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_partition_max_sub_devices_3() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, ...).
   */ // }}}
  void test_get_info_partition_max_sub_devices_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_MAX_SUB_DEVICES, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_properties_0() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_PROPERTIES, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_properties_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PARTITION_PROPERTIES, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 3 * sizeof(cl_device_partition_property));
  }
  /** // doc: test_get_info_partition_properties_1() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_PROPERTIES, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_properties_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_PROPERTIES, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_properties_2() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_PROPERTIES, ...).
   */ // }}}
  void test_get_info_partition_properties_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_partition_property value[3];
    d.get_info(CL_DEVICE_PARTITION_PROPERTIES, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], CL_DEVICE_PARTITION_EQUALLY);
    TS_ASSERT_EQUALS(value[1], CL_DEVICE_PARTITION_BY_COUNTS);
    TS_ASSERT_EQUALS(value[2], CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN);
  }
  /** // doc: test_get_info_partition_properties_3() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_PROPERTIES, ...).
   */ // }}}
  void test_get_info_partition_properties_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_partition_property value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_PROPERTIES, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_affinity_domain_0() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_affinity_domain_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_affinity_domain));
  }
  /** // doc: test_get_info_partition_affinity_domain_1() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_affinity_domain_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_affinity_domain_2() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, ...).
   */ // }}}
  void test_get_info_partition_affinity_domain_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_affinity_domain value;
    d.get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE
                          | CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE
                          | CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE
                          | CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE);
  }
  /** // doc: test_get_info_partition_affinity_domain_3() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, ...).
   */ // }}}
  void test_get_info_partition_affinity_domain_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_affinity_domain value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_AFFINITY_DOMAIN, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_type_0() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_TYPE, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PARTITION_TYPE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 0 * sizeof(cl_device_partition_property));
  }
  /** // doc: test_get_info_partition_type_1() {{{
   *  \brief Test get_info(CL_DEVICE_PARTITION_TYPE, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_TYPE, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_partition_type_2() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_TYPE, ...).
   */ // }}}
  void test_get_info_partition_type_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_partition_property value[1] = { 0x1234 };
    d.get_info(CL_DEVICE_PARTITION_TYPE, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], 0x1234 ); // unchanged
  }
  /** // doc: test_get_info_partition_type_3() {{{
   * \brief Test get_info(CL_DEVICE_PARTITION_TYPE, ...).
   */ // }}}
  void test_get_info_partition_type_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_partition_property value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PARTITION_TYPE, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_reference_count_0() {{{
   *  \brief Test get_info(CL_DEVICE_REFERENCE_COUNT, 0, NULL, &size).
   */ // }}}
  void test_get_info_reference_count_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_REFERENCE_COUNT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_reference_count_1() {{{
   *  \brief Test get_info(CL_DEVICE_REFERENCE_COUNT, 0, NULL, &size).
   */ // }}}
  void test_get_info_reference_count_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_REFERENCE_COUNT, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_reference_count_2() {{{
   * \brief Test get_info(CL_DEVICE_REFERENCE_COUNT, ...).
   */ // }}}
  void test_get_info_reference_count_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_REFERENCE_COUNT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_reference_count_3() {{{
   * \brief Test get_info(CL_DEVICE_REFERENCE_COUNT, ...).
   */ // }}}
  void test_get_info_reference_count_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_REFERENCE_COUNT, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_preferred_interop_user_sync_0() {{{
   *  \brief Test get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_preferred_interop_user_sync_1() {{{
   *  \brief Test get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_preferred_interop_user_sync_2() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, ...).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_TRUE);
  }
  /** // doc: test_get_info_preferred_interop_user_sync_3() {{{
   * \brief Test get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, ...).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_printf_buffer_size_0() {{{
   *  \brief Test get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_printf_buffer_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_printf_buffer_size_1() {{{
   *  \brief Test get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, 0, NULL, &size).
   */ // }}}
  void test_get_info_printf_buffer_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_printf_buffer_size_2() {{{
   * \brief Test get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, ...).
   */ // }}}
  void test_get_info_printf_buffer_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_printf_buffer_size_3() {{{
   * \brief Test get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, ...).
   */ // }}}
  void test_get_info_printf_buffer_size_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_PRINTF_BUFFER_SIZE, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_pitch_alignment_0() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_pitch_alignment_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_image_pitch_alignment_1() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_pitch_alignment_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_pitch_alignment_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, ...).
   */ // }}}
  void test_get_info_image_pitch_alignment_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_image_pitch_alignment_3() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, ...).
   */ // }}}
  void test_get_info_image_pitch_alignment_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_PITCH_ALIGNMENT, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_base_address_alignment_0() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_base_address_alignment_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_image_base_address_alignment_1() {{{
   *  \brief Test get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_base_address_alignment_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, 0, NULL, &size), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_info_image_base_address_alignment_2() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, ...).
   */ // }}}
  void test_get_info_image_base_address_alignment_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_image_base_address_alignment_3() {{{
   * \brief Test get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, ...).
   */ // }}}
  void test_get_info_image_base_address_alignment_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT, sizeof(value), &value, NULL), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_type_1() {{{
   * \brief Test get_type()
   */ // }}}
  void test_get_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_type(), CL_DEVICE_TYPE_CPU);
  }
  /** // doc: test_get_type_2() {{{
   * \brief Test get_type()
   */ // }}}
  void test_get_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_type(), CL_DEVICE_TYPE_GPU);
  }
  /** // doc: test_get_vendor_id_1() {{{
   * \brief Test get_vendor_id()
   */ // }}}
  void test_get_vendor_id_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_vendor_id(), 0x1002);
  }
  /** // doc: test_get_vendor_id_2() {{{
   * \brief Test get_vendor_id()
   */ // }}}
  void test_get_vendor_id_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_vendor_id(), 0x10de);
  }
  /** // doc: test_get_max_compute_units_1() {{{
   * \brief Test get_max_compute_units()
   */ // }}}
  void test_get_max_compute_units_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_compute_units(), 16);
  }
  /** // doc: test_get_max_compute_units_2() {{{
   * \brief Test get_max_compute_units()
   */ // }}}
  void test_get_max_compute_units_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_compute_units(), 30);
  }
  /** // doc: test_get_max_work_item_dimensions_1() {{{
   * \brief Test get_max_work_item_dimensions()
   */ // }}}
  void test_get_max_work_item_dimensions_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_work_item_dimensions(), 3);
  }
  /** // doc: test_get_max_work_item_dimensions_2() {{{
   * \brief Test get_max_work_item_dimensions()
   */ // }}}
  void test_get_max_work_item_dimensions_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_work_item_dimensions(), 3);
  }
  /** // doc: test_get_max_work_item_sizes_1() {{{
   * \brief Test get_max_work_item_sizes()
   */ // }}}
  void test_get_max_work_item_sizes_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t sizes[3] = {1024, 1024, 1024};
    TS_ASSERT_EQUALS(d.get_max_work_item_sizes(), std::vector<size_t>(sizes,sizes+3));
  }
  /** // doc: test_get_max_work_item_sizes_2() {{{
   * \brief Test get_max_work_item_sizes()
   */ // }}}
  void test_get_max_work_item_sizes_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t sizes[3] = {512, 512, 64};
    TS_ASSERT_EQUALS(d.get_max_work_item_sizes(), std::vector<size_t>(sizes,sizes+3));
  }
  /** // doc: test_get_max_work_group_size_1() {{{
   * \brief Test get_max_work_group_size()
   */ // }}}
  void test_get_max_work_group_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_work_group_size(), 1024);
  }
  /** // doc: test_get_max_work_group_size_2() {{{
   * \brief Test get_max_work_group_size()
   */ // }}}
  void test_get_max_work_group_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_work_group_size(), 512);
  }
  /** // doc: test_get_preferred_vector_width_char_1() {{{
   * \brief Test get_preferred_vector_width_char()
   */ // }}}
  void test_get_preferred_vector_width_char_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_char(), 16);
  }
  /** // doc: test_get_preferred_vector_width_char_2() {{{
   * \brief Test get_preferred_vector_width_char()
   */ // }}}
  void test_get_preferred_vector_width_char_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_char(), 1);
  }
  /** // doc: test_get_preferred_vector_width_short_1() {{{
   * \brief Test get_preferred_vector_width_short()
   */ // }}}
  void test_get_preferred_vector_width_short_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_short(), 8);
  }
  /** // doc: test_get_preferred_vector_width_short_2() {{{
   * \brief Test get_preferred_vector_width_short()
   */ // }}}
  void test_get_preferred_vector_width_short_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_short(), 1);
  }
  /** // doc: test_get_preferred_vector_width_int_1() {{{
   * \brief Test get_preferred_vector_width_int()
   */ // }}}
  void test_get_preferred_vector_width_int_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_int(), 4);
  }
  /** // doc: test_get_preferred_vector_width_int_2() {{{
   * \brief Test get_preferred_vector_width_int()
   */ // }}}
  void test_get_preferred_vector_width_int_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_int(), 1);
  }
  /** // doc: test_get_preferred_vector_width_long_1() {{{
   * \brief Test get_preferred_vector_width_long()
   */ // }}}
  void test_get_preferred_vector_width_long_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_long(), 2);
  }
  /** // doc: test_get_preferred_vector_width_long_2() {{{
   * \brief Test get_preferred_vector_width_long()
   */ // }}}
  void test_get_preferred_vector_width_long_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_long(), 1);
  }
  /** // doc: test_get_preferred_vector_width_float_1() {{{
   * \brief Test get_preferred_vector_width_float()
   */ // }}}
  void test_get_preferred_vector_width_float_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_float(), 4);
  }
  /** // doc: test_get_preferred_vector_width_float_2() {{{
   * \brief Test get_preferred_vector_width_float()
   */ // }}}
  void test_get_preferred_vector_width_float_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_float(), 1);
  }
  /** // doc: test_get_preferred_vector_width_double_1() {{{
   * \brief Test get_preferred_vector_width_double()
   */ // }}}
  void test_get_preferred_vector_width_double_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_double(), 2);
  }
  /** // doc: test_get_preferred_vector_width_double_2() {{{
   * \brief Test get_preferred_vector_width_double()
   */ // }}}
  void test_get_preferred_vector_width_double_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_double(), 1);
  }
  /** // doc: test_get_preferred_vector_width_half_1() {{{
   * \brief Test get_preferred_vector_width_half()
   */ // }}}
  void test_get_preferred_vector_width_half_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_half(), 2);
  }
  /** // doc: test_get_preferred_vector_width_half_2() {{{
   * \brief Test get_preferred_vector_width_half()
   */ // }}}
  void test_get_preferred_vector_width_half_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_half(), 0);
  }
  /** // doc: test_get_native_vector_width_char_1() {{{
   * \brief Test get_native_vector_width_char()
   */ // }}}
  void test_get_native_vector_width_char_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_char(), 16);
  }
  /** // doc: test_get_native_vector_width_char_2() {{{
   * \brief Test get_native_vector_width_char()
   */ // }}}
  void test_get_native_vector_width_char_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_char(), 1);
  }
  /** // doc: test_get_native_vector_width_short_1() {{{
   * \brief Test get_native_vector_width_short()
   */ // }}}
  void test_get_native_vector_width_short_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_short(), 8);
  }
  /** // doc: test_get_native_vector_width_short_2() {{{
   * \brief Test get_native_vector_width_short()
   */ // }}}
  void test_get_native_vector_width_short_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_short(), 1);
  }
  /** // doc: test_get_native_vector_width_int_1() {{{
   * \brief Test get_native_vector_width_int()
   */ // }}}
  void test_get_native_vector_width_int_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_int(), 4);
  }
  /** // doc: test_get_native_vector_width_int_2() {{{
   * \brief Test get_native_vector_width_int()
   */ // }}}
  void test_get_native_vector_width_int_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_int(), 1);
  }
  /** // doc: test_get_native_vector_width_long_1() {{{
   * \brief Test get_native_vector_width_long()
   */ // }}}
  void test_get_native_vector_width_long_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_long(), 2);
  }
  /** // doc: test_get_native_vector_width_long_2() {{{
   * \brief Test get_native_vector_width_long()
   */ // }}}
  void test_get_native_vector_width_long_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_long(), 1);
  }
  /** // doc: test_get_native_vector_width_float_1() {{{
   * \brief Test get_native_vector_width_float()
   */ // }}}
  void test_get_native_vector_width_float_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_float(), 4);
  }
  /** // doc: test_get_native_vector_width_float_2() {{{
   * \brief Test get_native_vector_width_float()
   */ // }}}
  void test_get_native_vector_width_float_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_float(), 1);
  }
  /** // doc: test_get_native_vector_width_double_1() {{{
   * \brief Test get_native_vector_width_double()
   */ // }}}
  void test_get_native_vector_width_double_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_double(), 2);
  }
  /** // doc: test_get_native_vector_width_double_2() {{{
   * \brief Test get_native_vector_width_double()
   */ // }}}
  void test_get_native_vector_width_double_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_double(), 1);
  }
  /** // doc: test_get_native_vector_width_half_1() {{{
   * \brief Test get_native_vector_width_half()
   */ // }}}
  void test_get_native_vector_width_half_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_half(), 2);
  }
  /** // doc: test_get_native_vector_width_half_2() {{{
   * \brief Test get_native_vector_width_half()
   */ // }}}
  void test_get_native_vector_width_half_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_half(), 0);
  }
  /** // doc: test_get_max_clock_frequency_1() {{{
   * \brief Test get_max_clock_frequency()
   */ // }}}
  void test_get_max_clock_frequency_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_clock_frequency(), 2401);
  }
  /** // doc: test_get_max_clock_frequency_2() {{{
   * \brief Test get_max_clock_frequency()
   */ // }}}
  void test_get_max_clock_frequency_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_clock_frequency(), 1296);
  }
  /** // doc: test_get_address_bits_1() {{{
   * \brief Test get_address_bits()
   */ // }}}
  void test_get_address_bits_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_address_bits(), 64);
  }
  /** // doc: test_get_address_bits_2() {{{
   * \brief Test get_address_bits()
   */ // }}}
  void test_get_address_bits_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_address_bits(), 32);
  }
  /** // doc: test_get_max_mem_alloc_size_1() {{{
   * \brief Test get_max_mem_alloc_size()
   */ // }}}
  void test_get_max_mem_alloc_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_mem_alloc_size(), 4214191104ul);
  }
  /** // doc: test_get_max_mem_alloc_size_2() {{{
   * \brief Test get_max_mem_alloc_size()
   */ // }}}
  void test_get_max_mem_alloc_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_mem_alloc_size(), 1073692672ul);
  }
  /** // doc: test_get_image_support_1() {{{
   * \brief Test get_image_support()
   */ // }}}
  void test_get_image_support_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_support(), CL_TRUE);
  }
  /** // doc: test_get_image_support_2() {{{
   * \brief Test get_image_support()
   */ // }}}
  void test_get_image_support_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image_support(), CL_TRUE);
  }
  /** // doc: test_get_max_read_image_args_1() {{{
   * \brief Test get_max_read_image_args()
   */ // }}}
  void test_get_max_read_image_args_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_read_image_args(), 128);
  }
  /** // doc: test_get_max_read_image_args_2() {{{
   * \brief Test get_max_read_image_args()
   */ // }}}
  void test_get_max_read_image_args_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_read_image_args(), 128);
  }
  /** // doc: test_get_max_write_image_args_1() {{{
   * \brief Test get_max_write_image_args()
   */ // }}}
  void test_get_max_write_image_args_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_write_image_args(), 8);
  }
  /** // doc: test_get_max_write_image_args_2() {{{
   * \brief Test get_max_write_image_args()
   */ // }}}
  void test_get_max_write_image_args_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_write_image_args(), 8);
  }
  /** // doc: test_get_image2d_max_width_1() {{{
   * \brief Test get_image2d_max_width()
   */ // }}}
  void test_get_image2d_max_width_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image2d_max_width(), 8192);
  }
  /** // doc: test_get_image2d_max_width_2() {{{
   * \brief Test get_image2d_max_width()
   */ // }}}
  void test_get_image2d_max_width_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image2d_max_width(), 4096);
  }
  /** // doc: test_get_image2d_max_height_1() {{{
   * \brief Test get_image2d_max_height()
   */ // }}}
  void test_get_image2d_max_height_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image2d_max_height(), 8192);
  }
  /** // doc: test_get_image2d_max_height_2() {{{
   * \brief Test get_image2d_max_height()
   */ // }}}
  void test_get_image2d_max_height_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image2d_max_height(), 16383);
  }
  /** // doc: test_get_image3d_max_width_1() {{{
   * \brief Test get_image3d_max_width()
   */ // }}}
  void test_get_image3d_max_width_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image3d_max_width(), 2048);
  }
  /** // doc: test_get_image3d_max_width_2() {{{
   * \brief Test get_image3d_max_width()
   */ // }}}
  void test_get_image3d_max_width_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image3d_max_width(), 2048);
  }
  /** // doc: test_get_image3d_max_height_1() {{{
   * \brief Test get_image3d_max_height()
   */ // }}}
  void test_get_image3d_max_height_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image3d_max_height(), 2048);
  }
  /** // doc: test_get_image3d_max_height_2() {{{
   * \brief Test get_image3d_max_height()
   */ // }}}
  void test_get_image3d_max_height_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image3d_max_height(), 2048);
  }
  /** // doc: test_get_image3d_max_depth_1() {{{
   * \brief Test get_image3d_max_depth()
   */ // }}}
  void test_get_image3d_max_depth_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image3d_max_depth(), 2048);
  }
  /** // doc: test_get_image3d_max_depth_2() {{{
   * \brief Test get_image3d_max_depth()
   */ // }}}
  void test_get_image3d_max_depth_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image3d_max_depth(), 2048);
  }
  /** // doc: test_get_max_samplers_1() {{{
   * \brief Test get_max_samplers()
   */ // }}}
  void test_get_max_samplers_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_samplers(), 16);
  }
  /** // doc: test_get_max_samplers_2() {{{
   * \brief Test get_max_samplers()
   */ // }}}
  void test_get_max_samplers_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_samplers(), 16);
  }
  /** // doc: test_get_max_parameter_size_1() {{{
   * \brief Test get_max_parameter_size()
   */ // }}}
  void test_get_max_parameter_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_parameter_size(), 4096);
  }
  /** // doc: test_get_max_parameter_size_2() {{{
   * \brief Test get_max_parameter_size()
   */ // }}}
  void test_get_max_parameter_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_parameter_size(), 4352);
  }
  /** // doc: test_get_mem_base_addr_align_1() {{{
   * \brief Test get_mem_base_addr_align()
   */ // }}}
  void test_get_mem_base_addr_align_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_mem_base_addr_align(), 1024);
  }
  /** // doc: test_get_mem_base_addr_align_2() {{{
   * \brief Test get_mem_base_addr_align()
   */ // }}}
  void test_get_mem_base_addr_align_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_mem_base_addr_align(), 2048);
  }
  /** // doc: test_get_min_data_type_align_size_1() {{{
   * \brief Test get_min_data_type_align_size()
   */ // }}}
  void test_get_min_data_type_align_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_min_data_type_align_size(), 128);
  }
  /** // doc: test_get_min_data_type_align_size_2() {{{
   * \brief Test get_min_data_type_align_size()
   */ // }}}
  void test_get_min_data_type_align_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_min_data_type_align_size(), 128);
  }
  /** // doc: test_get_single_fp_config_1() {{{
   * \brief Test get_single_fp_config()
   */ // }}}
  void test_get_single_fp_config_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_single_fp_config(), CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA);
  }
  /** // doc: test_get_single_fp_config_2() {{{
   * \brief Test get_single_fp_config()
   */ // }}}
  void test_get_single_fp_config_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_single_fp_config(), CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA);
  }
  /** // doc: test_get_global_mem_cache_type_1() {{{
   * \brief Test get_global_mem_cache_type()
   */ // }}}
  void test_get_global_mem_cache_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_type(), CL_READ_WRITE_CACHE);
  }
  /** // doc: test_get_global_mem_cache_type_2() {{{
   * \brief Test get_global_mem_cache_type()
   */ // }}}
  void test_get_global_mem_cache_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_type(), CL_NONE);
  }
  /** // doc: test_get_global_mem_cacheline_size_1() {{{
   * \brief Test get_global_mem_cacheline_size()
   */ // }}}
  void test_get_global_mem_cacheline_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_cacheline_size(), 64);
  }
  /** // doc: test_get_global_mem_cacheline_size_2() {{{
   * \brief Test get_global_mem_cacheline_size()
   */ // }}}
  void test_get_global_mem_cacheline_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_cacheline_size(), 0);
  }
  /** // doc: test_get_global_mem_cache_size_1() {{{
   * \brief Test get_global_mem_cache_size()
   */ // }}}
  void test_get_global_mem_cache_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_size(), 32768ul);
  }
  /** // doc: test_get_global_mem_cache_size_2() {{{
   * \brief Test get_global_mem_cache_size()
   */ // }}}
  void test_get_global_mem_cache_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_size(), 0);
  }
  /** // doc: test_get_global_mem_size_1() {{{
   * \brief Test get_global_mem_size()
   */ // }}}
  void test_get_global_mem_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_size(), 16856764416ul);
  }
  /** // doc: test_get_global_mem_size_2() {{{
   * \brief Test get_global_mem_size()
   */ // }}}
  void test_get_global_mem_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_size(), 4294770688ul);
  }
  /** // doc: test_get_max_constant_buffer_size_1() {{{
   * \brief Test get_max_constant_buffer_size()
   */ // }}}
  void test_get_max_constant_buffer_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_constant_buffer_size(), 65536);
  }
  /** // doc: test_get_max_constant_buffer_size_2() {{{
   * \brief Test get_max_constant_buffer_size()
   */ // }}}
  void test_get_max_constant_buffer_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_constant_buffer_size(), 65536);
  }
  /** // doc: test_get_max_constant_args_1() {{{
   * \brief Test get_max_constant_args()
   */ // }}}
  void test_get_max_constant_args_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_constant_args(), 8);
  }
  /** // doc: test_get_max_constant_args_2() {{{
   * \brief Test get_max_constant_args()
   */ // }}}
  void test_get_max_constant_args_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_constant_args(), 9);
  }
  /** // doc: test_get_local_mem_type_1() {{{
   * \brief Test get_local_mem_type()
   */ // }}}
  void test_get_local_mem_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_local_mem_type(), CL_GLOBAL);
  }
  /** // doc: test_get_local_mem_type_2() {{{
   * \brief Test get_local_mem_type()
   */ // }}}
  void test_get_local_mem_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_local_mem_type(), CL_LOCAL);
  }
  /** // doc: test_get_local_mem_size_1() {{{
   * \brief Test get_local_mem_size()
   */ // }}}
  void test_get_local_mem_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_local_mem_size(), 32768);
  }
  /** // doc: test_get_local_mem_size_2() {{{
   * \brief Test get_local_mem_size()
   */ // }}}
  void test_get_local_mem_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_local_mem_size(), 16384);
  }
  /** // doc: test_get_error_correction_support_1() {{{
   * \brief Test get_error_correction_support()
   */ // }}}
  void test_get_error_correction_support_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_error_correction_support(), CL_FALSE);
  }
  /** // doc: test_get_error_correction_support_2() {{{
   * \brief Test get_error_correction_support()
   */ // }}}
  void test_get_error_correction_support_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_error_correction_support(), CL_FALSE);
  }
  /** // doc: test_get_host_unified_memory_1() {{{
   * \brief Test get_host_unified_memory()
   */ // }}}
  void test_get_host_unified_memory_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_host_unified_memory(), CL_TRUE);
  }
  /** // doc: test_get_host_unified_memory_2() {{{
   * \brief Test get_host_unified_memory()
   */ // }}}
  void test_get_host_unified_memory_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_host_unified_memory(), CL_FALSE);
  }
  /** // doc: test_get_profiling_timer_resolution_1() {{{
   * \brief Test get_profiling_timer_resolution()
   */ // }}}
  void test_get_profiling_timer_resolution_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_profiling_timer_resolution(), 1);
  }
  /** // doc: test_get_profiling_timer_resolution_2() {{{
   * \brief Test get_profiling_timer_resolution()
   */ // }}}
  void test_get_profiling_timer_resolution_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_profiling_timer_resolution(), 1000);
  }
  /** // doc: test_get_endian_little_1() {{{
   * \brief Test get_endian_little()
   */ // }}}
  void test_get_endian_little_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_endian_little(), CL_TRUE);
  }
  /** // doc: test_get_endian_little_2() {{{
   * \brief Test get_endian_little()
   */ // }}}
  void test_get_endian_little_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_endian_little(), CL_TRUE);
  }
  /** // doc: test_get_available_1() {{{
   * \brief Test get_available()
   */ // }}}
  void test_get_available_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_available(), CL_TRUE);
  }
  /** // doc: test_get_available_2() {{{
   * \brief Test get_available()
   */ // }}}
  void test_get_available_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_available(), CL_TRUE);
  }
  /** // doc: test_get_compiler_available_1() {{{
   * \brief Test get_compiler_available()
   */ // }}}
  void test_get_compiler_available_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_compiler_available(), CL_TRUE);
  }
  /** // doc: test_get_compiler_available_2() {{{
   * \brief Test get_compiler_available()
   */ // }}}
  void test_get_compiler_available_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_compiler_available(), CL_TRUE);
  }
  /** // doc: test_get_execution_capabilities_1() {{{
   * \brief Test get_execution_capabilities()
   */ // }}}
  void test_get_execution_capabilities_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_execution_capabilities(), CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL);
  }
  /** // doc: test_get_execution_capabilities_2() {{{
   * \brief Test get_execution_capabilities()
   */ // }}}
  void test_get_execution_capabilities_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_execution_capabilities(), CL_EXEC_KERNEL);
  }
  /** // doc: test_get_queue_properties_1() {{{
   * \brief Test get_queue_properties()
   */ // }}}
  void test_get_queue_properties_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_queue_properties(), CL_QUEUE_PROFILING_ENABLE);
  }
  /** // doc: test_get_queue_properties_2() {{{
   * \brief Test get_queue_properties()
   */ // }}}
  void test_get_queue_properties_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_queue_properties(), CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE);
  }
  /** // doc: test_get_platform_id_1() {{{
   * \brief Test get_platform_id()
   */ // }}}
  void test_get_platform_id_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_platform_id(), T::Newton_clGetPlatformIDs::platforms[0]);
  }
  /** // doc: test_get_platform_id_2() {{{
   * \brief Test get_platform_id()
   */ // }}}
  void test_get_platform_id_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_platform_id(), T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_name_1() {{{
   * \brief Test get_name()
   */ // }}}
  void test_get_name_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
  }
  /** // doc: test_get_name_2() {{{
   * \brief Test get_name()
   */ // }}}
  void test_get_name_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_name(), "Tesla C1060");
  }
  /** // doc: test_get_vendor_1() {{{
   * \brief Test get_vendor()
   */ // }}}
  void test_get_vendor_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_vendor(), "GenuineIntel");
  }
  /** // doc: test_get_vendor_2() {{{
   * \brief Test get_vendor()
   */ // }}}
  void test_get_vendor_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_vendor(), "NVIDIA Corporation");
  }
  /** // doc: test_get_driver_version_1() {{{
   * \brief Test get_driver_version()
   */ // }}}
  void test_get_driver_version_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_driver_version(), "1348.4 (sse2)");
  }
  /** // doc: test_get_driver_version_2() {{{
   * \brief Test get_driver_version()
   */ // }}}
  void test_get_driver_version_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_driver_version(), "319.76");
  }
  /** // doc: test_get_profile_1() {{{
   * \brief Test get_profile()
   */ // }}}
  void test_get_profile_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
  }
  /** // doc: test_get_profile_2() {{{
   * \brief Test get_profile()
   */ // }}}
  void test_get_profile_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
  }
  /** // doc: test_get_version_1() {{{
   * \brief Test get_version()
   */ // }}}
  void test_get_version_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_get_version_2() {{{
   * \brief Test get_version()
   */ // }}}
  void test_get_version_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_get_opencl_c_version_1() {{{
   * \brief Test get_opencl_c_version()
   */ // }}}
  void test_get_opencl_c_version_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_opencl_c_version(), "OpenCL C 1.2");
  }
  /** // doc: test_get_opencl_c_version_2() {{{
   * \brief Test get_opencl_c_version()
   */ // }}}
  void test_get_opencl_c_version_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_opencl_c_version(), "OpenCL C 1.1");
  }
  /** // doc: test_get_extensions_1() {{{
   * \brief Test get_extensions()
   */ // }}}
  void test_get_extensions_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_extensions(), "cl_khr_fp64 cl_amd_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_byte_addressable_store cl_khr_gl_sharing cl_ext_device_fission cl_amd_device_attribute_query cl_amd_vec3 cl_amd_printf cl_amd_media_ops cl_amd_media_ops2 cl_amd_popcnt");
  }
  /** // doc: test_get_extensions_2() {{{
   * \brief Test get_extensions()
   */ // }}}
  void test_get_extensions_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll  cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_fp6");
  }
  /** // doc: test_get_double_fp_config_1() {{{
   * \brief Test get_double_fp_config()
   */ // }}}
  void test_get_double_fp_config_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_double_fp_config(), CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA);
  }
  /** // doc: test_get_double_fp_config_2() {{{
   * \brief Test get_double_fp_config()
   */ // }}}
  void test_get_double_fp_config_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_double_fp_config(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_linker_available_1() {{{
   * \brief Test get_linker_available()
   */ // }}}
  void test_get_linker_available_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_linker_available(), CL_FALSE);
  }
  /** // doc: test_get_linker_available_2() {{{
   * \brief Test get_linker_available()
   */ // }}}
  void test_get_linker_available_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_linker_available(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_built_in_kernels_1() {{{
   * \brief Test get_built_in_kernels()
   */ // }}}
  void test_get_built_in_kernels_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_built_in_kernels(), "");
  }
  /** // doc: test_get_built_in_kernels_2() {{{
   * \brief Test get_built_in_kernels()
   */ // }}}
  void test_get_built_in_kernels_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_built_in_kernels(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_image_max_buffer_size_1() {{{
   * \brief Test get_image_max_buffer_size()
   */ // }}}
  void test_get_image_max_buffer_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_max_buffer_size(), 65536);
  }
  /** // doc: test_get_image_max_buffer_size_2() {{{
   * \brief Test get_image_max_buffer_size()
   */ // }}}
  void test_get_image_max_buffer_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_max_buffer_size(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_image_max_array_size_1() {{{
   * \brief Test get_image_max_array_size()
   */ // }}}
  void test_get_image_max_array_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_max_array_size(), 2048);
  }
  /** // doc: test_get_image_max_array_size_2() {{{
   * \brief Test get_image_max_array_size()
   */ // }}}
  void test_get_image_max_array_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_max_array_size(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_parent_device_id_1() {{{
   * \brief Test get_parent_device_id()
   */ // }}}
  void test_get_parent_device_id_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_parent_device_id(), reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_get_parent_device_id_2() {{{
   * \brief Test get_parent_device_id()
   */ // }}}
  void test_get_parent_device_id_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_parent_device_id(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_partition_max_sub_devices_1() {{{
   * \brief Test get_partition_max_sub_devices()
   */ // }}}
  void test_get_partition_max_sub_devices_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_partition_max_sub_devices(), 16);
  }
  /** // doc: test_get_partition_max_sub_devices_2() {{{
   * \brief Test get_partition_max_sub_devices()
   */ // }}}
  void test_get_partition_max_sub_devices_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_max_sub_devices(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_partition_properties_1() {{{
   * \brief Test get_partition_properties()
   */ // }}}
  void test_get_partition_properties_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_partition_property const props[3] = {
      CL_DEVICE_PARTITION_EQUALLY,
      CL_DEVICE_PARTITION_BY_COUNTS,
      CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN
    };
    TS_ASSERT_EQUALS(d.get_partition_properties(), std::vector<cl_device_partition_property>(props,props+3));
  }
  /** // doc: test_get_partition_properties_2() {{{
   * \brief Test get_partition_properties()
   */ // }}}
  void test_get_partition_properties_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_properties(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_partition_affinity_domain_1() {{{
   * \brief Test get_partition_affinity_domain()
   */ // }}}
  void test_get_partition_affinity_domain_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_partition_affinity_domain(),
                      CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE
                    | CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE
                    | CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE
                    | CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE);
  }
  /** // doc: test_get_partition_affinity_domain_2() {{{
   * \brief Test get_partition_affinity_domain()
   */ // }}}
  void test_get_partition_affinity_domain_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_affinity_domain(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_partition_type_1() {{{
   * \brief Test get_partition_type()
   */ // }}}
  void test_get_partition_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_partition_type(), std::vector<cl_device_partition_property>());
  }
  /** // doc: test_get_partition_type_2() {{{
   * \brief Test get_partition_type()
   */ // }}}
  void test_get_partition_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_type(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_reference_count_1() {{{
   * \brief Test get_reference_count()
   */ // }}}
  void test_get_reference_count_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_reference_count(), 1);
  }
  /** // doc: test_get_reference_count_2() {{{
   * \brief Test get_reference_count()
   */ // }}}
  void test_get_reference_count_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_reference_count(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_preferred_interop_user_sync_1() {{{
   * \brief Test get_preferred_interop_user_sync()
   */ // }}}
  void test_get_preferred_interop_user_sync_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_interop_user_sync(), CL_TRUE);
  }
  /** // doc: test_get_preferred_interop_user_sync_2() {{{
   * \brief Test get_preferred_interop_user_sync()
   */ // }}}
  void test_get_preferred_interop_user_sync_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_preferred_interop_user_sync(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_printf_buffer_size_1() {{{
   * \brief Test get_printf_buffer_size()
   */ // }}}
  void test_get_printf_buffer_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_printf_buffer_size(), 65536);
  }
  /** // doc: test_get_printf_buffer_size_2() {{{
   * \brief Test get_printf_buffer_size()
   */ // }}}
  void test_get_printf_buffer_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_printf_buffer_size(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_image_pitch_alignment_1() {{{
   * \brief Test get_image_pitch_alignment()
   */ // }}}
  void test_get_image_pitch_alignment_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_pitch_alignment(), 0);
  }
  /** // doc: test_get_image_pitch_alignment_2() {{{
   * \brief Test get_image_pitch_alignment()
   */ // }}}
  void test_get_image_pitch_alignment_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_pitch_alignment(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
  /** // doc: test_get_image_base_address_alignment_1() {{{
   * \brief Test get_image_base_address_alignment()
   */ // }}}
  void test_get_image_base_address_alignment_1()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_base_address_alignment(), 0);
  }
  /** // doc: test_get_image_base_address_alignment_2() {{{
   * \brief Test get_image_base_address_alignment()
   */ // }}}
  void test_get_image_base_address_alignment_2()
  {
    T::Newton_clGetDeviceInfo mock;
    Device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_base_address_alignment(), Dimbo::Cl::Cl_Error_No<CL_INVALID_VALUE>);
  }
};

#endif /* DIMBO_CL_DEVICE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
