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

// dimbo/util/obid_id.hpp

/** // doc: dimbo/util/obid_id.hpp {{{ 
 * \file dimbo/util/obid_id.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_UTIL_OBID_ID_HPP_INCLUDED
#define DIMBO_UTIL_OBID_ID_HPP_INCLUDED

namespace Dimbo {

/** // {{{ struct obid_id_undefined_tag
 * \todo Write documentation
 */ //  }}} 
struct obid_id_undefined_tag;

/** // {{{ struct obid_id
 * \todo Write documentation
 */ //  }}} 
template <typename ObT> struct obid_id 
{
  typedef obid_id_undefined_tag type;
};
template <typename ObT> struct obid_id<const ObT>
{
  typedef typename obid_id<ObT>::type type;
};
template <typename ObT> struct obid_id<const ObT&>
{
  typedef typename obid_id<ObT>::type type;
};

} // namespace Dimbo {
#endif /* DIMBO_UTIL_OBID_ID_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
