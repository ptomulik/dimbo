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

// dimbo/clinfo/platform_layer_info.t.h

/** // doc: dimbo/clinfo/platform_layer_info.t.h {{{
 * \file dimbo/clinfo/platform_layer_info.t.h
 * \brief Unit tests for Dimbo::Clinfo::Platform_Layer_Info
 */ // }}}
#ifndef DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED
#define DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/clinfo/platform_layer_info.hpp>

namespace Dimbo { namespace Clinfo { class Platform_Layer_Info_TestSuite; } }

/** // doc: class Dimbo::Clinfo::Platform_Layer_Info_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Clinfo::Platform_Layer_Info_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(Platform_Layer_Info p);
    TS_ASSERT(Platform_Layer_Info().platforms().empty());
    TS_ASSERT(Platform_Layer_Info().devices().empty());
  }
  /** // doc: test_mapping_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_mapping_1( )
  {
    Platform_Info_Ptr p1(new Platform_Info());
    Platform_Info_Ptr p2(new Platform_Info());
    Device_Info_Ptr d11(new Device_Info());
    Device_Info_Ptr d12(new Device_Info());
    Device_Info_Ptr d21(new Device_Info());
    Device_Info_Ptr d22(new Device_Info());

    p1->set_name("platform 1");
    p2->set_name("platform 2");

    d11->set_name("platform 1 device 1");
    d12->set_name("platform 1 device 2");
    d21->set_name("platform 2 device 1");
    d22->set_name("platform 2 device 2");

    Platform_Layer_Info pli;
    pli.push_back(d11,p1);
    pli.push_back(d12,p1);
    pli.push_back(d21,p2);
    pli.push_back(d22,p2);

    TS_ASSERT_EQUALS(pli.platforms().size(), 2);
    TS_ASSERT_EQUALS(pli.devices().size(), 4);
    TS_ASSERT_EQUALS(pli.devices(p1).size(), 2);
    TS_ASSERT_EQUALS(pli.devices(p2).size(), 2);

    TS_ASSERT_EQUALS(pli.platforms()[0]->name(),"platform 1");
    TS_ASSERT_EQUALS(pli.platforms()[1]->name(),"platform 2");

    TS_ASSERT_EQUALS(pli.devices()[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(pli.devices()[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(pli.devices()[2]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(pli.devices()[3]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(pli.devices(p1)[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(pli.devices(p1)[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(pli.devices(p2)[0]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(pli.devices(p2)[1]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(pli.platform(pli.devices()[0]), p1);
    TS_ASSERT_EQUALS(pli.platform(pli.devices()[1]), p1);
    TS_ASSERT_EQUALS(pli.platform(pli.devices()[2]), p2);
    TS_ASSERT_EQUALS(pli.platform(pli.devices()[3]), p2);
  }
  /** // doc: test_remove_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_remove_device( )
  {
    Platform_Info_Ptr p1(new Platform_Info());
    Platform_Info_Ptr p2(new Platform_Info());
    Device_Info_Ptr d11(new Device_Info());
    Device_Info_Ptr d12(new Device_Info());
    Device_Info_Ptr d21(new Device_Info());
    Device_Info_Ptr d22(new Device_Info());

    p1->set_name("platform 1");
    p2->set_name("platform 2");

    d11->set_name("platform 1 device 1");
    d12->set_name("platform 1 device 2");
    d21->set_name("platform 2 device 1");
    d22->set_name("platform 2 device 2");

    Platform_Layer_Info pli;
    pli.push_back(d11,p1);
    pli.push_back(d12,p1);
    pli.push_back(d21,p2);
    pli.push_back(d22,p2);

    pli.remove(d21);
    TS_ASSERT_EQUALS(pli.devices().size(), 3);
    TS_ASSERT_EQUALS(pli.devices()[0]->name(),"platform 1 device 1")
    TS_ASSERT_EQUALS(pli.devices()[1]->name(),"platform 1 device 2")
    TS_ASSERT_EQUALS(pli.devices()[2]->name(),"platform 2 device 2")

    pli.remove(p1);
    TS_ASSERT_EQUALS(pli.devices().size(), 1);
    TS_ASSERT_EQUALS(pli.platforms().size(), 1);
    TS_ASSERT_EQUALS(pli.devices()[0]->name(),"platform 2 device 2");

    pli.remove(d22);
    TS_ASSERT(pli.devices().empty());
    TS_ASSERT(pli.platforms().empty());
  }
  /** // doc: test_clear() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear( )
  {
    Platform_Layer_Info pli;
    Platform_Info_Ptr pi(new Platform_Info());
    pli.push_back(Device_Info_Ptr(new Device_Info()), pi);
    pli.push_back(Device_Info_Ptr(new Device_Info()), pi);
    pli.clear();
    TS_ASSERT(pli.platforms().empty());
    TS_ASSERT(pli.devices().empty());
  }
  /** // doc: test_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_empty( )
  {
    Platform_Layer_Info pli;
    TS_ASSERT(pli.empty());
    Platform_Info_Ptr pi(new Platform_Info());
    pli.push_back(Device_Info_Ptr(new Device_Info()), pi);
    pli.push_back(Device_Info_Ptr(new Device_Info()), pi);
    TS_ASSERT(!pli.empty());
    pli.clear();
    TS_ASSERT(pli.empty());
  }
};

#endif /* DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
