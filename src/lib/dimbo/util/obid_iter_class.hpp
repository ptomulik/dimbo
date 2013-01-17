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

// dimbo/util/obid_iter_class.hpp

/** // doc: dimbo/util/obid_iter_class.hpp {{{ 
 * \file dimbo/util/obid_iter_class.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_UTIL_OBID_ITER_CLASS_HPP_INCLUDED
#define DIMBO_UTIL_OBID_ITER_CLASS_HPP_INCLUDED

#include <iterator>

namespace Dimbo {

template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
class ObId_Ref;

template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
class ObId_Iter 
#if 0
  : public std::iterator < 
    std::random_access_iterator_tag                         // category
  , typename std::iterator_traits<IdIterT>::value_type      // value_type
  , typename std::iterator_traits<IdIterT>::difference_type // difference_type
  , IdIterT*                                                // pointer_type
  , ObId_Ref<ObIterT,IdIterT,ObIterC,IdIterC>               // reference_type
  >
#endif
{
private:
  typedef typename std::iterator_traits<ObIterT>::difference_type ObDiffT;
  typedef typename std::iterator_traits<ObIterT>::value_type      ObT;
  typedef typename std::iterator_traits<ObIterT>::pointer         ObPtrT;
  typedef typename std::iterator_traits<ObIterC>::pointer         ObPtrC;
  typedef typename std::iterator_traits<ObIterT>::reference       ObRefT;
  typedef typename std::iterator_traits<ObIterC>::reference       ObRefC;

  typedef typename std::iterator_traits<IdIterT>::difference_type IdDiffT;
  typedef typename std::iterator_traits<IdIterT>::value_type      IdT;
  typedef typename std::iterator_traits<IdIterT>::pointer         IdPtrT;
  typedef typename std::iterator_traits<IdIterC>::pointer         IdPtrC;
  typedef typename std::iterator_traits<IdIterT>::reference       IdRefT;
  typedef typename std::iterator_traits<IdIterC>::reference       IdRefC;

public:

  typedef std::random_access_iterator_tag iterator_category;

  typedef ObIterT   ob_iterator;
  typedef ObIterC   ob_const_iterator;
  typedef ObDiffT   ob_difference_type;
  typedef ObT       ob_value_type;
  typedef ObPtrT    ob_pointer;
  typedef ObPtrC    ob_const_pointer;
  typedef ObRefT    ob_reference;
  typedef ObRefC    ob_const_reference;

  typedef IdIterT   id_iterator;
  typedef IdIterC   id_const_iterator;
  typedef IdDiffT   id_difference_type;
  typedef IdT       id_value_type;
  typedef IdPtrT    id_pointer;
  typedef IdPtrC    id_const_pointer;
  typedef IdRefT    id_reference;
  typedef IdRefC    id_const_reference;

  typedef ObDiffT   difference_type;
  typedef ObPtrT    pointer;
  typedef ObT       value_type;
  typedef ObIterT   iterator;
  typedef ObIterC   const_iterator;

  typedef IdDiffT   adj_difference_type;
  typedef IdPtrT    adj_pointer;
  typedef IdT       adj_value_type;
  typedef IdIterT   adj_iterator;
  typedef IdIterC   adj_const_iterator;

  ob_iterator _ob_iter;
  id_iterator _id_iter;

  typedef ObId_Ref<ObIterT,IdIterT,ObIterC,IdIterC> reference;

public:

  ObId_Iter() 
    : _ob_iter(), _id_iter()
  {
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  ObId_Iter(ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs)
    : _ob_iter(rhs._ob_iter), _id_iter(rhs._id_iter)
  {
  }

  ObId_Iter(ObIterT obi, IdIterT idi)
    : _ob_iter(obi), _id_iter(idi)
  {
  }
// FIXME: develop more verbose constant here
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  ObId_Iter& operator = (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) 
  {
    this->_ob_iter = rhs._ob_iter; 
    this->_id_iter = rhs._id_iter; 
    return this;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  bool operator == (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) const
  {
    return this->_ob_iter == rhs._ob_iter;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  bool operator != (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) const
  {
    return this->_ob_iter != rhs._ob_iter;
  }
  reference operator* () const;
  ob_const_iterator operator -> () const
  {
    return ob_const_iterator(this->_ob_iter);
  }
  ObId_Iter& operator ++ ()
  {
    ++this->_ob_iter;
    ++this->_id_iter;
    return *this;
  }
  ObId_Iter& operator -- ()
  {
    --this->_ob_iter;
    --this->_id_iter;
    return *this;
  }
  ObId_Iter operator ++ (int)
  {
    ObId_Iter it(*this);
    ++this->_ob_iter;
    ++this->_id_iter;
    return it;
  }
  ObId_Iter operator -- (int)
  {
    ObId_Iter it(*this);
    --this->_ob_iter;
    --this->_id_iter;
    return it;
  }
  ObId_Iter& advance(difference_type n)
  {
    this->_ob_iter += n;
    this->_id_iter += n;
    return *this;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  difference_type operator- (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& b) const
  {
    return this->_ob_iter - b._ob_iter;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  bool operator < (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) const
  {
    return this->_ob_iter < rhs._ob_iter;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  bool operator > (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) const
  {
    return this->_ob_iter > rhs._ob_iter;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  bool operator <= (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) const
  {
    return this->_ob_iter <= rhs._ob_iter;
  }
  template <class ObIterT1, class IdIterT1, class ObIterC1, class IdIterC1>
  bool operator >= (ObId_Iter<ObIterT1,IdIterT1,ObIterC1,IdIterC1> const& rhs) const
  {
    return this->_ob_iter >= rhs._ob_iter;
  }
  reference operator [] (difference_type n) const;
  void write_ob(id_value_type const& id) const
  {
    *(this->_ob_iter) = ob_value_type(id);
    *(this->_id_iter) = id_value_type(id);
  }
  void write_id(ob_value_type const& ob) const
  {
    *(this->_ob_iter) = ob_value_type(ob);
    *(this->_id_iter) = id_value_type(ob);
  }
  ob_const_iterator get_id_iter() const
  {
    return this->_ob_iter;
  }
  id_const_iterator get_ob_iter() const
  {
    return this->_id_iter;
  }
  const_iterator get_iter() const
  {
    return this->_ob_iter;
  }
  adj_const_iterator get_adj_iter() const
  {
    return this->_id_iter;
  }
  explicit operator ob_const_iterator() const
  {
    return this->_ob_iter;
  }
  explicit operator id_const_iterator() const
  {
    return this->_id_iter;
  }
};

} /* namespace Dimbo */

#endif /* DIMBO_UTIL_OBID_ITER_CLASS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
