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

/** // doc: dimbo/swig/dimbo/util/obid_ref.swg {{{ 
 * \file dimbo/swig/dimbo/util/obid_ref.swg
 * \todo Write documentation
 */ // }}}

%{
#include <dimbo/util/obid_ref.hpp>
%}

%include <dimbo/util/obid_iter_class.swg>

namespace Dimbo {

template <class ObIterT, class IdIterT, class ObIterC, class IdIterC>
class ObId_Ref
{
/*
private:
  typedef typename std::iterator_traits<ObIterT>::value_type ObT;
  typedef typename std::iterator_traits<IdIterT>::value_type IdT;
public:
  typedef ObT ob_value_type;
  typedef IdT id_value_type;
  typedef ObId_Iter<ObIterT,IdIterT,ObIterC,IdIterC> iterator;
  typedef typename iterator::value_type value_type;
  typedef typename iterator::adj_value_type adj_value_type;
*/
private:
  //iterator _iter;
  ObId_Ref();
/*
public:
  ObId_Ref(iterator it);
  ObId_Ref(ObId_Ref const& rhs);
  template<class ValT1>
  ObId_Ref const& operator = (ValT1 ob) const;

  operator value_type () const;
  explicit operator adj_value_type () const;
  iterator operator& () const;
*/
};

} /* namespace Dimbo */

%include <dimbo/util/obid_iter_methods.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
