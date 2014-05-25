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

// dimbo/format/clinfo/device_info.hpp

/** // doc: dimbo/format/clinfo/device_info.hpp {{{
 * @file dimbo/format/clinfo/device_info.hpp
 * @todo Write documentation
 */ // }}}
#ifndef DIMBO_FORMAT_CLINFO_DEVICE_INFO_HPP_INCLUDED
#define DIMBO_FORMAT_CLINFO_DEVICE_INFO_HPP_INCLUDED

#include <dimbo/clinfo/device_info.hpp>
#include <iosfwd>

namespace Dimbo {
namespace Format {

/** // doc: write(os, info, pre) {{{
 * \todo Write documentation
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Clinfo::Device_Info const& info, int ind);
/** // doc: write(os, info) {{{
 * \todo Write documentation
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Clinfo::Device_Info const& info);

} /* namespace Format */
} /* namespace Dimbo */

/** // doc: os << info {{{
 * \todo Write documentation
 */ // }}}
template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , Dimbo::Clinfo::Device_Info const& info);

#endif /* DIMBO_FORMAT_CLINFO_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
