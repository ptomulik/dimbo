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

// dimbo/serialization/clinfo/device_info.hpp

/** // doc: dimbo/serialization/clinfo/device_info.hpp {{{
 * \file dimbo/serialization/clinfo/device_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_SERIALIZATION_CLINFO_DEVICE_INFO_HPP_INCLUDED
#define DIMBO_SERIALIZATION_CLINFO_DEVICE_INFO_HPP_INCLUDED

#include <dimbo/clinfo/device_info.hpp>
#include <boost/serialization/version.hpp>

// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
BOOST_CLASS_VERSION( Dimbo::Clinfo::Device_Info
                   , Dimbo::Clinfo::Device_Info::class_version )
#endif

namespace Dimbo {
namespace Clinfo {

/** // doc: serialize(ar,obj,ver) {{{
 * \todo Write documentation
 */ // }}}
template<class Archive>
void serialize(Archive& ar, Device_Info& obj, const unsigned int ver);

} /* namespace Clinfo */
} /* namespace Dimbo */

#endif /* DIMBO_SERIALIZATION_CLINFO_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
