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

// dimbo/util/obid_iter_methods.hpp

/** // doc: dimbo/util/obid_iter_methods.hpp {{{ 
 * \file dimbo/util/obid_iter_methods.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_UTIL_OBID_ITER_METHODS_HPP_INCLUDED
#define DIMBO_UTIL_OBID_ITER_METHODS_HPP_INCLUDED

namespace Dimbo {

template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
typename ObId_Iter<ObIterT,IdIterT, ObIterC,IdIterC>::reference
ObId_Iter<ObIterT,IdIterT, ObIterC,IdIterC>::
operator* () const
{
  return reference(*this);
}
template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
typename ObId_Iter<ObIterT,IdIterT, ObIterC,IdIterC>::reference
ObId_Iter<ObIterT,IdIterT, ObIterC,IdIterC>::
operator [] (difference_type n) const
{
  ObId_Iter itn(*this);  
  return reference(itn.advance(n));
}

} // namespace Dimbo

template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>& 
operator += (Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>& it,
             typename Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>::difference_type n)
{
  return it.advance(n);
}
template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>& 
operator -= (Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>& it, 
             typename Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>::difference_type n)
{
  return it.advance(-n);
}
template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>
operator + (Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> const& a, 
            typename Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>::difference_type n)
{
  Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> x(a);
  x += n;
  return x;
}
template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>
operator + (typename Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>::difference_type n,
            Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> const& a)
{
  return a + n;
}
template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>
operator - (Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> const& a, 
            typename Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC>::difference_type n)
{
  Dimbo::ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> x(a);
  x -= n;
  return x;
}

#endif /* DIMBO_UTIL_OBID_ITER_METHODS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
