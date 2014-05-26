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
#include <dimbo/clinfo/platform_layer_info_fixtures.hpp>

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
    Platform_Layer_Info pli(Platform_Layer_Info_Fixtures::_1());

    TS_ASSERT_EQUALS(pli.platforms().size(), 2);

    Const_Platform_Info_Ptr p1(pli.platforms()[0]);
    Const_Platform_Info_Ptr p2(pli.platforms()[1]);

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

    // peek some functions via the const Platform_Layer_Info object
    Platform_Layer_Info const& cpli = pli;
    TS_ASSERT_EQUALS(cpli.platforms()[0]->name(),"platform 1");
    TS_ASSERT_EQUALS(cpli.platforms()[1]->name(),"platform 2");

    TS_ASSERT_EQUALS(cpli.devices()[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(cpli.devices()[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(cpli.devices()[2]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(cpli.devices()[3]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(cpli.devices(p1)[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(cpli.devices(p1)[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(cpli.devices(p2)[0]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(cpli.devices(p2)[1]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(cpli.platform(cpli.devices()[0]), p1);
    TS_ASSERT_EQUALS(cpli.platform(cpli.devices()[1]), p1);
    TS_ASSERT_EQUALS(cpli.platform(cpli.devices()[2]), p2);
    TS_ASSERT_EQUALS(cpli.platform(cpli.devices()[3]), p2);
  }
  /** // doc: test_remove_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_remove_device( )
  {
    Platform_Layer_Info pli(Platform_Layer_Info_Fixtures::_1());

    pli.remove(pli.devices(pli.platforms()[1])[0]);
    TS_ASSERT_EQUALS(pli.devices().size(), 3);
    TS_ASSERT_EQUALS(pli.devices()[0]->name(),"platform 1 device 1")
    TS_ASSERT_EQUALS(pli.devices()[1]->name(),"platform 1 device 2")
    TS_ASSERT_EQUALS(pli.devices()[2]->name(),"platform 2 device 2")

    pli.remove(pli.platforms()[0]);
    TS_ASSERT_EQUALS(pli.devices().size(), 1);
    TS_ASSERT_EQUALS(pli.platforms().size(), 1);
    TS_ASSERT_EQUALS(pli.devices()[0]->name(),"platform 2 device 2");

    pli.remove(pli.devices()[0]);
    TS_ASSERT(pli.devices().empty());
    TS_ASSERT(pli.platforms().empty());
  }
  /** // doc: test_clear() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear( )
  {
    Platform_Layer_Info pli(Platform_Layer_Info_Fixtures::_1());
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
    pli = Platform_Layer_Info_Fixtures::_1();
    TS_ASSERT(!pli.empty());
    pli.clear();
    TS_ASSERT(pli.empty());
  }
};

#endif /* DIMBO_CLINFO_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
