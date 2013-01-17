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

// dimbo/cl/util/obid_vec.hpp

/** // doc: dimbo/cl/util/obid_vec.hpp {{{ 
 * \file dimbo/cl/util/obid_vec.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_UTIL_OBID_VEC_HPP_INCLUDED
#define DIMBO_UTIL_OBID_VEC_HPP_INCLUDED

#include <dimbo/util/obid_ref.hpp>
#include <dimbo/util/obid_iter.hpp>
#include <dimbo/util/obid_id.hpp>
#include <dimbo/util/conv_iter.hpp>

#include <vector>
#include <iterator>
#include <algorithm>

namespace Dimbo {

/** // doc: class ObId_Vec {{{
 * \todo Write documentation
 */ // }}}
template <class ObT
         , class IdT = typename obid_id<ObT>::type
         , class ObAlloc = std::allocator<ObT>
         , class IdAlloc = std::allocator<IdT> 
         >
class ObId_Vec
{
public:

  // vector of identifiers
  typedef ObT ob_value_type;
  typedef ObAlloc ob_allocator_type;
  typedef std::vector<ObT, ObAlloc> ob_vector;
  typedef typename ob_vector::iterator ob_iterator;
  typedef typename ob_vector::const_iterator ob_const_iterator;
  typedef typename ob_vector::size_type ob_size_type;

  typedef typename std::iterator_traits<ob_iterator>::difference_type ob_difference_type;
  typedef typename std::iterator_traits<ob_iterator>::reference ob_reference;
  typedef typename std::iterator_traits<ob_const_iterator>::reference ob_const_reference;
  typedef typename std::iterator_traits<ob_iterator>::pointer ob_pointer;
  typedef typename std::iterator_traits<ob_const_iterator>::pointer ob_const_pointer;

  // vector of objects
  typedef IdT id_value_type;
  typedef IdAlloc id_allocator_type;
  typedef std::vector<IdT, IdAlloc> id_vector;
  typedef typename id_vector::iterator id_iterator;
  typedef typename id_vector::const_iterator id_const_iterator;
  typedef typename id_vector::size_type id_size_type;

  typedef typename std::iterator_traits<id_iterator>::difference_type id_difference_type;
  typedef typename std::iterator_traits<id_iterator>::reference id_reference;
  typedef typename std::iterator_traits<id_const_iterator>::reference id_const_reference;
  typedef typename std::iterator_traits<id_iterator>::pointer id_pointer;
  typedef typename std::iterator_traits<id_const_iterator>::pointer id_const_pointer;

  typedef ObId_Iter < ob_iterator
                    , id_iterator
                    , ob_const_iterator
                    , id_const_iterator > iterator;
  typedef ObId_Iter < ob_const_iterator
                    , id_const_iterator
                    , ob_const_iterator
                    , id_const_iterator > const_iterator;

  // iterator decides what are value_type, reference and so on
  typedef typename iterator::reference reference;
  typedef typename const_iterator::reference const_reference;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef typename iterator::value_type value_type;
  typedef typename iterator::pointer pointer;
  typedef typename iterator::difference_type difference_type;

  typedef ob_size_type size_type;
  typedef ob_allocator_type allocator_type;
private:
  ob_vector _obs;
  id_vector _ids;

public:
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(ob_allocator_type const& ob_alloc = ob_allocator_type(),
                    id_allocator_type const& id_alloc = id_allocator_type()) 
    : _obs(ob_alloc), _ids(id_alloc) 
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(size_type n, value_type const& val = value_type(),
                    ob_allocator_type const& ob_alloc = ob_allocator_type(),
                    id_allocator_type const& id_alloc = id_allocator_type())
    : _obs(n, ob_value_type(val), ob_alloc),
      _ids(n, id_value_type(val), id_alloc)
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  template <class InputIterator>
  ObId_Vec(InputIterator first, InputIterator last, 
           ob_allocator_type const& ob_alloc = ob_allocator_type(),
           id_allocator_type const& id_alloc = id_allocator_type())
    : _obs(ob_alloc), _ids(id_alloc)
  {
    this->assign(first, last);
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  ObId_Vec(ObId_Vec const & x)
    : _obs(x._obs), _ids(x._ids)
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(ob_vector const & obs, 
                    ob_allocator_type const& ob_alloc = ob_allocator_type(), 
                    id_allocator_type const& id_alloc = id_allocator_type())
    : _obs(ob_alloc), _ids(id_alloc)
  {
    this->assign(obs.begin(), obs.end());
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(id_vector const & ids,
                    ob_allocator_type const& ob_alloc = ob_allocator_type(), 
                    id_allocator_type const& id_alloc = id_allocator_type())
    : _obs(ob_alloc), _ids(id_alloc)
  {
    this->assign(ids.begin(), ids.end());
  }
  /** // doc: ~ObId_Vec() {{{
   * \todo Write documentation 
   */ // }}}
  ~ObId_Vec()
  {
  }
  /** // doc: operator=() {{{
   * \todo Write documentation
   */ // }}}
  ObId_Vec& operator = (ob_vector const& rhs)
  {
    assign(rhs.begin(), rhs.end());
    return *this;
  }
  /** // doc: operator=() {{{
   * \todo Write documentation
   */ // }}}
  ObId_Vec& operator = (id_vector const& rhs)
  {
    assign(rhs.begin(), rhs.end());
    return *this;
  }
  /** // doc: operator=() {{{
   * \todo Write documentation
   */ // }}}
  ObId_Vec& operator = (ObId_Vec const& rhs)
  {
    assign(rhs.begin(), rhs.end());
    return *this;
  }
  /** // doc: begin() {{{
   * \todo Write documentation
   */ // }}}
  iterator begin()
  {
    return iterator(this->_obs.begin(), this->_ids.begin());
  }
  /** // doc: begin() const {{{
   * \todo Write documentation
   */ // }}}
  const_iterator begin() const
  {
    return const_iterator(this->_obs.begin(), this->_ids.begin());
  }
  /** // doc: end() {{{
   * \todo Write documentation
   */ // }}}
  iterator end()
  {
    return iterator(this->_obs.end(), this->_ids.end());
  }
  /** // doc: end() const {{{
   * \todo Write documentation
   */ // }}}
  const_iterator end() const
  {
    return const_iterator(this->_obs.end(), this->_ids.end());
  }
  /** // doc: rbegin() {{{
   * \todo Write documentation
   */ // }}}
  reverse_iterator rbegin()
  {
    return reverse_iterator(--(this->end()));
  }
  /** // doc: rbegin() const {{{
   * \todo Write documentation
   */ // }}}
  const_reverse_iterator rbegin() const
  {
    return const_reverse_iterator(--(this->end()));
  }
  /** // doc: rend() {{{
   * \todo Write documentation
   */ // }}}
  reverse_iterator rend()
  {
    return reverse_iterator(--(this->begin()));
  }
  /** // doc: rend() const {{{
   * \todo Write documentation
   */ // }}}
  const_reverse_iterator rend() const
  {
    return const_reverse_iterator(--(this->begin()));
  }
  /** // doc: size() const {{{
   * \todo Write documentation
   */ // }}}
  size_type size() const
  {
    // FIXME: assert(_obs.dize() == _ids.size())
    return std::min(this->_obs.size(), this->_ids.size());
  }
  /** // doc: max_size() const {{{
   * \todo Write documentation
   */ // }}}
  size_type max_size() const
  {
    return std::min(this->_obs.max_size(), this->_ids.max_size());
  }
  /** // doc: resize() {{{
   * \todo Write documentation
   */ // }}}
  void resize(size_type n, value_type val = value_type())
  {
    this->_obs.resize(n, ob_value_type(val));
    this->_ids.resize(n, id_value_type(val));
  }
  /** // doc: capacity() const {{{
   * \todo Write documentation
   */ // }}}
  size_type capacity() const
  {
    return std::min(this->_obs.capacity(), this->_ids.capacity());
  }
  /** // doc: empty() const {{{
   * \todo Write documentation
   */ // }}}
  bool empty() const
  {
    // FIXME: assert( !xor(_obs.empty(), _ids.empty()) )
    return (this->_obs.empty() || this->_ids.empty());
  }
  /** // doc: reserve() {{{
   * \todo Write documentation
   */ // }}}
  void reserve(size_type n)
  {
    this->_obs.reserve(n);
    this->_ids.reserve(n);
  }
  /** // doc: at(n) {{{
   * \todo Write documentation
   */ // }}}
  reference at(difference_type n)
  {
    return *(iterator(this->_obs.begin(), this->_ids.begin()) + n);
  }
  /** // doc: at(n) const {{{
   * \todo Write documentation
   */ // }}}
  const_reference at(difference_type n) const
  {
    return *(const_iterator(this->_obs.begin(), this->_ids.begin()) + n);
  }
  /** // doc: operator[](n) {{{
   * \todo Write documentation
   */ // }}}
  reference operator[](difference_type n)
  {
    return this->at(n);
  }
  /** // doc: operator[](n) const {{{
   * \todo Write documentation
   */ // }}}
  const_reference operator[](difference_type n) const
  {
    return this->at(n);
  }
  /** // doc: front() {{{
   * \todo Write documentation
   */ // }}}
  reference front()
  {
    return this->at(0);
  }
  /** // doc: front() const {{{
   * \todo Write documentation
   */ // }}}
  const_reference front() const
  {
    return this->at(0);
  }
  /** // doc: back() {{{
   * \todo Write documentation
   */ // }}}
  reference back()
  {
    return this->at(this->size()-1);
  }
  /** // doc: back() const {{{
   * \todo Write documentation
   */ // }}}
  const_reference back() const
  {
    return this->at(this->size()-1);
  }
  /** // doc: assign() const {{{
   * \todo Write documentation
   */ // }}}
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last)
  {
    this->_obs.assign(Conv_Iter<InputIterator,ob_value_type>(first),
                      Conv_Iter<InputIterator,ob_value_type>(last));
    this->_ids.assign(Conv_Iter<InputIterator,id_value_type>(first),
                      Conv_Iter<InputIterator,id_value_type>(last));
  }
  /** // doc: assign() const {{{
   * \todo Write documentation
   */ // }}}
  void assign(size_type n, value_type const& val)
  {
    this->_obs.assign(n, ob_value_type(val));
    this->_ids.assign(n, id_value_type(val));
  }
  /** // doc: push_back() const {{{
   * \todo Write documentation
   */ // }}}
  void push_back(value_type const& val)
  {
    this->_obs.push_back(ob_value_type(val));
    this->_ids.push_back(id_value_type(val));
  }
  /** // doc: pop_back() const {{{
   * \todo Write documentation
   */ // }}}
  void pop_back()
  {
    this->_obs.pop_back();
    this->_ids.pop_back();
  }
  /** // doc: insert() const {{{
   * \todo Write documentation
   */ // }}}
  iterator insert(iterator pos, value_type const& val)
  {
    difference_type i = pos - this->begin();
    return iterator( this->_obs.insert(this->_obs.begin() + i, 
                                       ob_value_type(val))
                   , this->_ids.insert(this->_ids.begin() + i,
                                       id_value_type(val)) );
  }
  /** // doc: insert() const {{{
   * \todo Write documentation
   */ // }}}
  void insert(iterator pos, size_type n, value_type const& val)
  {
    difference_type i = pos - this->begin();
    this->_obs.insert(this->_obs.begin() + i, ob_value_type(val));
    this->_ids.insert(this->_ids.begin() + i, id_value_type(val));
  }
  /** // doc: insert() const {{{
   * \todo Write documentation
   */ // }}}
  template <class InputIterator>
  void insert(iterator pos, InputIterator first, InputIterator last)
  {
    difference_type i = pos - this->begin();
    this->_obs.insert(
      this->_obs.begin() + i, 
      Conv_Iter<InputIterator,ob_value_type>(first),
      Conv_Iter<InputIterator,ob_value_type>(last)
    );
    this->_ids.insert(
      this->_ids.begin() + i, 
      Conv_Iter<InputIterator,id_value_type>(first),
      Conv_Iter<InputIterator,id_value_type>(last)
    );
  }
  /** // doc: erase() const {{{
   * \todo Write documentation
   */ // }}}
  iterator erase(iterator pos)
  {
    difference_type i = pos - this->begin();
    return iterator( this->_obs.erase(this->_obs.begin() + i),
                     this->_ids.erase(this->_ids.begin() + i) );
  }
  /** // doc: erase() const {{{
   * \todo Write documentation
   */ // }}}
  iterator erase(iterator first, iterator last)
  {
    difference_type i_f = first- this->begin();
    difference_type i_l = last - this->begin();
    return iterator(
      this->_obs.erase(this->_obs.begin() + i_f, this->_obs.begin() + i_l),
      this->_ids.erase(this->_ids.begin() + i_f, this->_ids.begin() + i_l) 
    );
  }
  /** // doc: swap() const {{{
   * \todo Write documentation
   */ // }}}
  void swap(ObId_Vec& x)
  {
    this->_obs.swap(x._obs);
    this->_ids.swap(x._ids);
  }
  /** // doc: clear() const {{{
   * \todo Write documentation
   */ // }}}
  void clear()
  {
    this->_obs.clear();
    this->_ids.clear();
  }
  /** // doc: get_allocator() const {{{
   * \todo Write documentation
   */ // }}}
  allocator_type get_ob_allocator() const
  {
    return this->_obs.get_allocator();
  }
  /** // doc: get_allocator() const {{{
   * \todo Write documentation
   */ // }}}
  allocator_type get_id_allocator() const
  {
    return this->_ids.get_allocator();
  }
  /** // doc: get_allocator() const {{{
   * \todo Write documentation
   */ // }}}
  allocator_type get_allocator() const
  {
    return this->get_ob_allocator();
  }
  /** // doc: ids() const {{{
   * \todo Write documentation
   */ // }}}
  ob_vector const& obs() const
  {
    return this->_obs;
  }
  /** // doc: obs() const {{{
   * \todo Write documentation
   */ // }}}
  id_vector const& ids() const
  {
    return this->_ids;
  }
};

} // namespace Dimbo

/** // doc: operator == () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
bool operator == (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& lhs,
                  Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& rhs)
{
  return static_cast<std::vector<IdT,IdAlloc> const&>(lhs)
     ==  static_cast<std::vector<IdT,IdAlloc> const&>(rhs);
}
/** // doc: operator != () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
bool operator != (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& lhs,
                  Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& rhs)
{
  return static_cast<std::vector<IdT,IdAlloc> const&>(lhs)
     !=  static_cast<std::vector<IdT,IdAlloc> const&>(rhs);
}
/** // doc: operator < () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
bool operator < (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& lhs,
                 Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& rhs)
{
  return static_cast<std::vector<IdT,IdAlloc> const&>(lhs)
      <  static_cast<std::vector<IdT,IdAlloc> const&>(rhs);
}
/** // doc: operator <= () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
bool operator <= (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& lhs,
                  Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& rhs)
{
  return static_cast<std::vector<IdT,IdAlloc> const&>(lhs)
      <= static_cast<std::vector<IdT,IdAlloc> const&>(rhs);
}
/** // doc: operator > () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
bool operator > (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& lhs,
                 Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& rhs)
{
  return static_cast<std::vector<IdT,IdAlloc> const&>(lhs)
      >  static_cast<std::vector<IdT,IdAlloc> const&>(rhs);
}
/** // doc: operator >= () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
bool operator >= (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& lhs, 
                  Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc> const& rhs)
{
  return static_cast<std::vector<IdT,IdAlloc> const&>(lhs)
      >= static_cast<std::vector<IdT,IdAlloc> const&>(rhs);
}

/** // doc: operator >= () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc, class IdAlloc>
void swap (Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc>& x,
           Dimbo::ObId_Vec<ObT,IdT,ObAlloc,IdAlloc>& y)
{
  x.swap(y);
}

#endif /* DIMBO_UTIL_OBID_VEC_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
