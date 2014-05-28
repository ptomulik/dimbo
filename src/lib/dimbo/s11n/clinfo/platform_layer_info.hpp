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

// dimbo/s11n/clinfo/platform_layer_info.hpp

/** // doc: dimbo/s11n/clinfo/platform_layer_info.hpp {{{
 * \file dimbo/s11n/clinfo/platform_layer_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_S11N_CLINFO_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define DIMBO_S11N_CLINFO_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <dimbo/clinfo/platform_layer_info.hpp>
#include <boost/serialization/version.hpp>

// FIXME: replace with more verbose constant, e.g. DIMBO_USE_BOOST_SERIALIZATION
#ifndef SWIG
BOOST_CLASS_VERSION( Dimbo::Clinfo::Platform_Layer_Info
                   , Dimbo::Clinfo::Platform_Layer_Info::class_version )
#endif

namespace boost {
namespace serialization {

/** // doc: serialize(ar,obj,ver) {{{
 * \todo Write documentation
 */ // }}}
template<class Archive>
void serialize(Archive& ar, Dimbo::Clinfo::Platform_Layer_Info& obj, const unsigned int ver);

} /* namespace serialization */
} /* namespace boost */

#endif /* DIMBO_S11N_CLINFO_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
