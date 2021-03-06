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

// dimbo/protobuf/clinfo/device_info.hpp

/** // doc: dimbo/protobuf/clinfo/device_info.hpp {{{
 * \file dimbo/protobuf/clinfo/device_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_HPP_INCLUDED
#define DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_HPP_INCLUDED

#include <dimbo/clinfo/device_query.hpp>
#include <dimbo/protobuf/clinfo/device_query.pb.h>

namespace Dimbo {
namespace Protobuf {

/** // doc: write(buf,obj) {{{
 * \todo Write documentation
 */ // }}}
void write(Dimbo::Protobuf::Clinfo::Device_Query& buf,
           Dimbo::Clinfo::Device_Query const& obj);
/** // doc: read(buf,obj) {{{
 * \todo Write documentation
 */ // }}}
void read(Dimbo::Protobuf::Clinfo::Device_Query const& buf,
          Dimbo::Clinfo::Device_Query& obj);

} /* namesapce Protobuf */
} /* namespace Dimbo */

/** doc: operator<< (buf,obj) {{{
 * \todo Write documentation
 */ // }}}
Dimbo::Protobuf::Clinfo::Device_Query&
operator<<(Dimbo::Protobuf::Clinfo::Device_Query& buf,
           Dimbo::Clinfo::Device_Query const& obj);
/** doc: operator>> (buf,obj) {{{
 * \todo Write documentation
 */ // }}}
Dimbo::Protobuf::Clinfo::Device_Query const&
operator>>(Dimbo::Protobuf::Clinfo::Device_Query const& buf,
           Dimbo::Clinfo::Device_Query& obj);

#endif /* DIMBO_PROTOBUF_CLINFO_DEVICE_QUERY_HPP_INCLUDED  */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
