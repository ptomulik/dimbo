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

// /dimbo/protobuf/clinfo/platform_query_fixtures.hpp

/** // doc: /dimbo/protobuf/clinfo/platform_query_fixtures.hpp {{{
 * \file /dimbo/protobuf/clinfo/platform_query_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_PLATFORM_QUERY_FIXTURES_HPP_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_PLATFORM_QUERY_FIXTURES_HPP_INCLUDED

#include <dimbo/protobuf/clinfo/platform_query.hpp>

namespace Dimbo {
namespace Protobuf {
namespace Clinfo {

struct Device_Query_Fixtures
  {
    // This corresponds to Dimbo::Clinfo::Device_Query_Fixtures::_false()
    // see "dimbo/clinfo/platform_query_fixtures.hpp" under "src/test".
    static Device_Query _false()
    {
      Device_Query buf;
      buf.set_id_selected(false);
      buf.set_profile_selected(false);
      buf.set_version_selected(false);
      buf.set_name_selected(false);
      buf.set_vendor_selected(false);
      buf.set_extensions_selected(false);
      return buf;
    }
    // This corresponds to Dimbo::Clinfo::Device_Query_Fixtures::_true()
    // see "dimbo/clinfo/platform_query_fixtures.hpp" under "src/test".
    static Device_Query _true()
    {
      Device_Query buf;
      buf.set_id_selected(true);
      buf.set_profile_selected(true);
      buf.set_version_selected(true);
      buf.set_name_selected(true);
      buf.set_vendor_selected(true);
      buf.set_extensions_selected(true);
      return buf;
    }
  };

} /* namespace Clinfo */
} /* namespace Protobuf */
} /* namespace Dimbo */

#endif /* DIMBO_PROTOBUF_CLINFO_PLATFORM_QUERY_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
