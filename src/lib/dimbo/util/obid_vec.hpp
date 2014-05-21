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

#include <dimbo/util/obid_id.hpp>
#include <dimbo/util/conv_iter.hpp>

#include <vector>
#include <iterator>
#include <algorithm>

namespace Dimbo {

/** // doc: class ObId_Vec {{{
 * \todo Write documentation
 */ // }}}
template < class ObT
         , class IdT = typename obid_id<ObT>::type
         , class ObAlloc = std::allocator<ObT>
         >
class ObId_Vec
{
public:

  // vector of objects
  typedef std::vector<ObT, ObAlloc> ob_vector;

  typedef ObT value_type;
  typedef ObAlloc allocator_type;
  typedef typename std::vector<ObT, ObAlloc>::iterator iterator;
  typedef typename std::vector<ObT, ObAlloc>::const_iterator const_iterator;
  typedef typename std::vector<ObT, ObAlloc>::reverse_iterator reverse_iterator;
  typedef typename std::vector<ObT, ObAlloc>::const_reverse_iterator const_reverse_iterator;
  typedef typename std::vector<ObT, ObAlloc>::size_type size_type;
  typedef typename iterator::reference reference;
  typedef typename const_iterator::reference const_reference;
  typedef typename iterator::pointer pointer;
  typedef typename iterator::difference_type difference_type;

  typedef IdT id_value_type;

private:
  ob_vector _obs;

public:
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(allocator_type const& alloc = allocator_type())
    : _obs(alloc)
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(size_type n, value_type const& val = value_type(),
                    allocator_type const& alloc = allocator_type())
    : _obs(n, val, alloc)
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  template <class InputIterator>
  ObId_Vec(InputIterator first, InputIterator last,
           allocator_type const& alloc = allocator_type())
    : _obs(alloc)
  {
    this->assign(first, last);
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  ObId_Vec(ObId_Vec const & x)
    : _obs(x._obs)
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  explicit ObId_Vec(ob_vector const & obs,
                    allocator_type const& alloc = allocator_type())
    : _obs(obs.begin(), obs.end(), alloc)
  {
  }
  /** // doc: ObId_Vec() {{{
   * \todo Write documentation
   */ // }}}
  template <class IdAlloc>
  explicit ObId_Vec(std::vector<id_value_type, IdAlloc> const & ids,
                    allocator_type const& alloc = allocator_type())
    : _obs(alloc)
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
    this->assign(rhs.begin(), rhs.end());
    return *this;
  }
  /** // doc: operator=() {{{
   * \todo Write documentation
   */ // }}}
  template <class IdAlloc>
  ObId_Vec& operator = (std::vector<id_value_type, IdAlloc> const& rhs)
  {
    this->assign(rhs.begin(), rhs.end());
    return *this;
  }
  /** // doc: operator=() {{{
   * \todo Write documentation
   */ // }}}
  ObId_Vec& operator = (ObId_Vec const& rhs)
  {
    this->assign(rhs.begin(), rhs.end());
    return *this;
  }
  /** // doc: begin() {{{
   * \todo Write documentation
   */ // }}}
  iterator begin()
  {
    return iterator(this->_obs.begin());
  }
  /** // doc: begin() const {{{
   * \todo Write documentation
   */ // }}}
  const_iterator begin() const
  {
    return const_iterator(this->_obs.begin());
  }
  /** // doc: end() {{{
   * \todo Write documentation
   */ // }}}
  iterator end()
  {
    return iterator(this->_obs.end());
  }
  /** // doc: end() const {{{
   * \todo Write documentation
   */ // }}}
  const_iterator end() const
  {
    return const_iterator(this->_obs.end());
  }
  /** // doc: rbegin() {{{
   * \todo Write documentation
   */ // }}}
  reverse_iterator rbegin()
  {
    return this->_obs.rbegin();
  }
  /** // doc: rbegin() const {{{
   * \todo Write documentation
   */ // }}}
  const_reverse_iterator rbegin() const
  {
    return this->_obs.rbegin();
  }
  /** // doc: rend() {{{
   * \todo Write documentation
   */ // }}}
  reverse_iterator rend()
  {
    return this->_obs.rend();
  }
  /** // doc: rend() const {{{
   * \todo Write documentation
   */ // }}}
  const_reverse_iterator rend() const
  {
    return this->_obs.rend();
  }
  /** // doc: size() const {{{
   * \todo Write documentation
   */ // }}}
  size_type size() const
  {
    return this->_obs.size();
  }
  /** // doc: max_size() const {{{
   * \todo Write documentation
   */ // }}}
  size_type max_size() const
  {
    return this->_obs.max_size();
  }
  /** // doc: resize() {{{
   * \todo Write documentation
   */ // }}}
  void resize(size_type n, value_type val = value_type())
  {
    this->_obs.resize(n, val);
  }
  /** // doc: capacity() const {{{
   * \todo Write documentation
   */ // }}}
  size_type capacity() const
  {
    return this->_obs.capacity();
  }
  /** // doc: empty() const {{{
   * \todo Write documentation
   */ // }}}
  bool empty() const
  {
    return this->_obs.empty();
  }
  /** // doc: reserve() {{{
   * \todo Write documentation
   */ // }}}
  void reserve(size_type n)
  {
    this->_obs.reserve(n);
  }
  /** // doc: at(n) {{{
   * \todo Write documentation
   */ // }}}
  reference at(difference_type n)
  {
    return this->_obs.at(n);
  }
  /** // doc: at(n) const {{{
   * \todo Write documentation
   */ // }}}
  const_reference at(difference_type n) const
  {
    return this->_obs.at(n);
  }
  /** // doc: operator[](n) {{{
   * \todo Write documentation
   */ // }}}
  reference operator[](difference_type n)
  {
    return this->_obs[n];
  }
  /** // doc: operator[](n) const {{{
   * \todo Write documentation
   */ // }}}
  const_reference operator[](difference_type n) const
  {
    return this->_obs[n];
  }
  /** // doc: front() {{{
   * \todo Write documentation
   */ // }}}
  reference front()
  {
    return this->_obs.front();
  }
  /** // doc: front() const {{{
   * \todo Write documentation
   */ // }}}
  const_reference front() const
  {
    return this->_obs.front();
  }
  /** // doc: back() {{{
   * \todo Write documentation
   */ // }}}
  reference back()
  {
    return this->_obs.back();
  }
  /** // doc: back() const {{{
   * \todo Write documentation
   */ // }}}
  const_reference back() const
  {
    return this->_obs.back();
  }
  /** // doc: assign() const {{{
   * \todo Write documentation
   */ // }}}
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last)
  {
    this->_obs.assign(Conv_Iter<InputIterator,value_type>(first),
                      Conv_Iter<InputIterator,value_type>(last));
  }
  /** // doc: assign() const {{{
   * \todo Write documentation
   */ // }}}
  void assign(size_type n, value_type const& val)
  {
    this->_obs.assign(n, val);
  }
  /** // doc: push_back() const {{{
   * \todo Write documentation
   */ // }}}
  void push_back(value_type const& val)
  {
    this->_obs.push_back(val);
  }
  /** // doc: pop_back() const {{{
   * \todo Write documentation
   */ // }}}
  void pop_back()
  {
    this->_obs.pop_back();
  }
  /** // doc: insert() const {{{
   * \todo Write documentation
   */ // }}}
  iterator insert(iterator pos, value_type const& val)
  {
    return this->_obs.insert(pos,val);
  }
  /** // doc: insert() const {{{
   * \todo Write documentation
   */ // }}}
  void insert(iterator pos, size_type n, value_type const& val)
  {
    this->_obs.insert(pos, n, val);
  }
  /** // doc: insert() const {{{
   * \todo Write documentation
   */ // }}}
  template <class InputIterator>
  void insert(iterator pos, InputIterator first, InputIterator last)
  {
    this->_obs.insert(pos, Conv_Iter<InputIterator,value_type>(first),
                           Conv_Iter<InputIterator,value_type>(last));
  }
  /** // doc: erase() const {{{
   * \todo Write documentation
   */ // }}}
  iterator erase(iterator pos)
  {
    return this->_obs.erase(pos);
  }
  /** // doc: erase() const {{{
   * \todo Write documentation
   */ // }}}
  iterator erase(iterator first, iterator last)
  {
    return this->_obs.erase(first,last);
  }
  /** // doc: swap() const {{{
   * \todo Write documentation
   */ // }}}
  void swap(ObId_Vec& x)
  {
    this->_obs.swap(x._obs);
  }
  /** // doc: clear() const {{{
   * \todo Write documentation
   */ // }}}
  void clear()
  {
    this->_obs.clear();
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
  allocator_type get_allocator() const
  {
    return this->get_ob_allocator();
  }
};

} // namespace Dimbo

#if 0
/** // doc: operator == () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc/*, class IdAlloc*/>
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
#endif
/** // doc: operator >= () {{{
 * \todo Write documentation
 */ // }}}
template <class ObT, class IdT, class ObAlloc>
void swap (Dimbo::ObId_Vec<ObT,IdT,ObAlloc>& x,
           Dimbo::ObId_Vec<ObT,IdT,ObAlloc>& y)
{
  x.swap(y);
}

#endif /* DIMBO_UTIL_OBID_VEC_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
