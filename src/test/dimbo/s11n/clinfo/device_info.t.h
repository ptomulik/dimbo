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

// dimbo/clinfo/device_info.t.h

/** // doc: dimbo/clinfo/device_info.t.h {{{
 * \file dimbo/clinfo/device_info.t.h
 * \brief Unit tests for Dimbo::Clinfo::Device_Info
 */ // }}}
#ifndef DIMBO_S11N_CLINFO_DEVICE_INFO_T_H_INCLUDED
#define DIMBO_S11N_CLINFO_DEVICE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/s11n/clinfo/device_info.hpp>
#include <dimbo/clinfo/device_info_fixtures.hpp>

// For serialization
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <sstream>

namespace Dimbo { namespace Clinfo { class Device_Info_Serialization_TestSuite; } }

/** // doc: class Dimbo::Clinfo::Device_Info_Serialization_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::Clinfo::Device_Info_Serialization_TestSuite : public CxxTest::TestSuite
{
public:
//  /** // doc: test_serialize_text() {{{
//   * \todo Write documentation
//   */ // }}}
  void test_serialize_text( )
  {
    Device_Info orig(Device_Info_Fixtures::_1());
    Device_Info info;

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << orig;

    boost::archive::text_iarchive ia(ss);
    ia >> info;

    TS_ASSERT_EQUALS(info, orig);
  }
//  /** // doc: test_serialize_xml() {{{
//   * \todo Write documentation
//   */ // }}}
  void test_serialize_xml( )
  {
    using boost::serialization::make_nvp;
    Device_Info orig(Device_Info_Fixtures::_1());
    Device_Info info;

    std::stringstream ss;

    boost::archive::xml_oarchive oa(ss);
    oa << make_nvp("device_info", orig);

    boost::archive::xml_iarchive ia(ss);
    ia >> make_nvp("device_info", info);

    TS_ASSERT_EQUALS(info, orig);
  }
//  /** // doc: test_serialize_binary() {{{
//   * \todo Write documentation
//   */ // }}}
  void test_serialize_binary( )
  {
    Device_Info orig(Device_Info_Fixtures::_1());
    Device_Info info;

    std::stringstream ss;

    boost::archive::binary_oarchive oa(ss);
    oa << orig;

    boost::archive::binary_iarchive ia(ss);
    ia >> info;

    TS_ASSERT_EQUALS(info, orig);
  }
};

#endif /* DIMBO_S11N_CLINFO_DEVICE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
