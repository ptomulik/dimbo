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

/** // doc: dimbo/swig/dimbo/util/obid_vec_common.swg {{{
 * \file dimbo/swig/dimbo/util/obid_vec_common.swg
 * \todo Write documentation
 */ // }}}

%{
#include <dimbo/util/obid_vec.hpp>
%}

//%include <dimbo/util/obid_iter.swg>
//%include <dimbo/util/obid_ref.swg>
%include <dimbo/util/obid_id.swg>

%include <std/std_vector.i>

namespace Dimbo {

template< class ObT
        , class IdT = typename obid_id<ObT>::type
        , class ObAlloc = std::allocator<ObT> >
class ObId_Vec
{
public:
  typedef ObT value_type;
  typedef ObT& reference;
  typedef ObT const& const_reference;
  typedef ObT* pointer;
  typedef ObT const* const_pointer;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;
public:

  %traits_swigtype(ObT);
  %traits_enum(ObT);

  %fragment(SWIG_Traits_frag(Dimbo::ObId_Vec<ObT,IdT,ObAlloc>), "header",
    fragment=SWIG_Traits_frag(ObT),
    fragment="DimboObIdVecTraits") {
      namespace swig {
        template <> struct traits<Dimbo::ObId_Vec<ObT,IdT,ObAlloc> > {
          typedef value_category category;
          static const char* type_name() {
            return "Dimbo::ObId_Vec<" #ObT " >";
        }
      };
    }
  }
  %ignore get_allocator; // we have two allocators actually
  %typemap_traits_ptr(SWIG_TYPECHECK_VECTOR, Dimbo::ObId_Vec<ObT,IdT,ObAlloc>);
#ifdef %swig_vector_methods_val
  %swig_vector_methods_val(Dimbo::ObId_Vec<ObT,IdT,ObAlloc>);
#endif

  %std_vector_methods_val(ObId_Vec);
};

} // namespace Dimbo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
