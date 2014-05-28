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
#ifndef DIMBO_S11N_CLINFO_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED
#define DIMBO_S11N_CLINFO_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED

#include <dimbo/s11n/clinfo/platform_layer_info.hpp>
#include <dimbo/s11n/clinfo/platform_info.hpp>
#include <dimbo/s11n/clinfo/device_info.hpp>
#include <dimbo/s11n/shared_ptr.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>

namespace Dimbo {
namespace Clinfo {

/* ------------------------------------------------------------------------ */
template<class Archive>
void _serialize(Archive& ar, Platform_Layer_Info& obj, const unsigned int)
{
  using boost::serialization::make_nvp;
  ar & make_nvp("bimap", obj._bimap);
}
/* ------------------------------------------------------------------------ */

} /* namespace Clinfo */
} /* namespace Dimbo */

namespace boost {
namespace serialization {

/* ------------------------------------------------------------------------ */
template <class Archive>
void serialize(Archive& ar, Dimbo::Clinfo::Platform_Layer_Info& obj, const unsigned int ver)
{
  Dimbo::Clinfo::_serialize(ar, obj, ver);
}
/* ------------------------------------------------------------------------ */

} /* namespace boost */
} /* namespace serialization */

#endif /* DIMBO_S11N_CLINFO_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
