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

// dimbo/util/conv_iter.hpp

/** // doc: dimbo/util/conv_iter.hpp {{{
 * \file dimbo/util/conv_iter.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_UTIL_CONV_ITER_HPP_INCLUDED
#define DIMBO_UTIL_CONV_ITER_HPP_INCLUDED


namespace Dimbo {

/** // {{{ doc: Conv_Iter
 *  \todo Write documentation
 */ // }}}
template <class Iter, class ValT>
class Conv_Iter : public Iter
{
public:
  typedef ValT value_type;
  Conv_Iter(Iter const& it)
    : Iter(it)
  {
  }
  value_type operator* () const
  {
    return value_type(Iter::operator*());
  }
};

} /* namespace Dimbo */

#endif /* DIMBO_UTIL_CONV_ITER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
