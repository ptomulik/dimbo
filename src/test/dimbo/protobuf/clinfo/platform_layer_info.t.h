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

// dimbo/protobuf/clinfo/platform_layer_info.t.h

/** // doc: dimbo/protobuf/clinfo/platform_layer_info.t.h {{{
 * \file dimbo/protobuf/clinfo/platform_layer_info.t.h
 * \brief Unit tests for Dimbo::Protobuf::Clinfo::Platform_Layer_Info
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED
#define DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/protobuf/clinfo/platform_layer_info.hpp>
#include <dimbo/protobuf/clinfo/platform_info.hpp>
#include <dimbo/protobuf/clinfo/device_info.hpp>
#include <dimbo/clinfo/platform_info_fixtures.hpp>
#include <dimbo/clinfo/device_info_fixtures.hpp>

namespace Dimbo { namespace Protobuf { namespace Clinfo { class Platform_Layer_Info_TestSuite; } } }

/** // doc: class Dimbo::Protobuf::Clinfo::Platform_Layer_Info_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Protobuf::Clinfo::Platform_Layer_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_write_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_empty()
  {
    Platform_Layer_Info buf;

    // Fill buffer with some garbage
    buf.add_device_platform_index(0);
    write(*(buf.add_device()), Dimbo::Clinfo::Device_Info_Fixtures::_1());
    write(*(buf.add_platform()), Dimbo::Clinfo::Platform_Info_Fixtures::_1());

    // Now, write empty object
    write(buf, Dimbo::Clinfo::Platform_Layer_Info());

    // Buffer should be empty again
    TS_ASSERT_EQUALS(buf.device_platform_index_size(), 0);
    TS_ASSERT_EQUALS(buf.device_size(), 0);
    TS_ASSERT_EQUALS(buf.platform_size(), 0);
  }
  /** // doc: test_write_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_write_1()
  {
    using Dimbo::Clinfo::Platform_Info_Ptr;
    using Dimbo::Clinfo::Device_Info_Ptr;

    Platform_Layer_Info buf;
    Dimbo::Clinfo::Platform_Layer_Info obj;

    Platform_Info_Ptr p1(new Dimbo::Clinfo::Platform_Info());
    Platform_Info_Ptr p2(new Dimbo::Clinfo::Platform_Info());
    Device_Info_Ptr d11(new Dimbo::Clinfo::Device_Info());
    Device_Info_Ptr d12(new Dimbo::Clinfo::Device_Info());
    Device_Info_Ptr d21(new Dimbo::Clinfo::Device_Info());
    Device_Info_Ptr d22(new Dimbo::Clinfo::Device_Info());

    p1->set_name("platform 1");
    p2->set_name("platform 2");
    d11->set_name("platform 1 device 1");
    d12->set_name("platform 1 device 2");
    d21->set_name("platform 2 device 1");
    d22->set_name("platform 2 device 2");

    obj.push_back(d11, p1);
    obj.push_back(d12, p1);
    obj.push_back(d21, p2);
    obj.push_back(d22, p2);

    // Now, write empty object
    write(buf, obj);

    // Buffer should be empty again
    TS_ASSERT_EQUALS(buf.device_platform_index_size(), 4);
    TS_ASSERT_EQUALS(buf.device_size(), 4);
    TS_ASSERT_EQUALS(buf.platform_size(), 2);
    TS_ASSERT_EQUALS(buf.device_platform_index(0),0);
    TS_ASSERT_EQUALS(buf.device_platform_index(1),0);
    TS_ASSERT_EQUALS(buf.device_platform_index(2),1);
    TS_ASSERT_EQUALS(buf.device_platform_index(3),1);
    TS_ASSERT_EQUALS(buf.platform(0).name(), p1->name());
    TS_ASSERT_EQUALS(buf.platform(1).name(), p2->name());
    TS_ASSERT_EQUALS(buf.device(0).name(), d11->name());
    TS_ASSERT_EQUALS(buf.device(1).name(), d12->name());
    TS_ASSERT_EQUALS(buf.device(2).name(), d21->name());
    TS_ASSERT_EQUALS(buf.device(3).name(), d22->name());
  }
  /** // doc: test_read_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_empty()
  {
    using Dimbo::Clinfo::Platform_Info_Ptr;
    using Dimbo::Clinfo::Device_Info_Ptr;

    Platform_Layer_Info buf;
    Dimbo::Clinfo::Platform_Layer_Info obj;

    obj.push_back(Device_Info_Ptr(new Dimbo::Clinfo::Device_Info()),
                  Platform_Info_Ptr(new Dimbo::Clinfo::Platform_Info()));
    TS_ASSERT(!obj.empty());

    // Now, read from empty buffer
    read(buf, obj);

    // The object should be empty
    TS_ASSERT(obj.empty());
  }
  /** // doc: test_read_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_read_1()
  {
    Platform_Layer_Info buf;
    Dimbo::Clinfo::Platform_Layer_Info obj;

    // Fill buffer with some garbage
    buf.add_device_platform_index(0);
    write(*(buf.add_device()), Dimbo::Clinfo::Device_Info_Fixtures::_1());
    write(*(buf.add_platform()), Dimbo::Clinfo::Platform_Info_Fixtures::_1());

    read(buf, obj);

    TS_ASSERT_EQUALS(obj.devices().size(), 1);
    TS_ASSERT_EQUALS(obj.platforms().size(), 1);
    TS_ASSERT_EQUALS(*(obj.devices()[0]), Dimbo::Clinfo::Device_Info_Fixtures::_1());
    TS_ASSERT_EQUALS(*(obj.platforms()[0]), Dimbo::Clinfo::Platform_Info_Fixtures::_1());
    TS_ASSERT_EQUALS(*(obj.platform(obj.devices()[0])), *(obj.platforms()[0]));
  }
};

#endif /* DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
