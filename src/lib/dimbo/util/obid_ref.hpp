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

// dimbo/util/obid_ref.hpp

/** // doc: dimbo/util/obid_ref.hpp {{{
 * \file dimbo/util/obid_ref.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_UTIL_OBID_REF_HPP_INCLUDED
#define DIMBO_UTIL_OBID_REF_HPP_INCLUDED

#include <dimbo/util/obid_iter_class.hpp>
#include <iterator>

namespace Dimbo {

template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
class ObId_Ref
{
private:
  typedef typename std::iterator_traits<ObIterT>::value_type ObT;
  typedef typename std::iterator_traits<IdIterT>::value_type IdT;
public:
  typedef ObT ob_value_type;
  typedef IdT id_value_type;
  typedef ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> iterator;
  typedef typename iterator::value_type value_type;
  typedef typename iterator::adj_value_type adj_value_type;
private:
  iterator _iter;
  ObId_Ref();
public:
  ObId_Ref(iterator it)
    : _iter(it)
  {
  }
  ObId_Ref(ObId_Ref const& rhs)
    : _iter(rhs._iter)
  {
  }
  template<class ValT1>
  ObId_Ref const& operator = (ValT1 ob) const
  {
    this->_iter.write_id(ob);
    return *this;
  }
  operator value_type () const
  {
    return *(this->_iter.get_iter());
  }
  explicit operator adj_value_type () const
  {
    return *(this->_iter.get_adj_iter());
  }
  iterator operator& () const
  {
    return this->_iter;
  }
};

} /* namespace Dimbo */

#include <dimbo/util/obid_iter_methods.hpp>

#endif /* DIMBO_UTIL_OBID_REF_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
