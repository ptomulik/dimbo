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

/** // doc: dimbo/swig/python/dimbo/util/obid_vec.swg {{{
 * \file dimbo/swig/python/dimbo/util/obid_vec.swg
 * \todo Write documentation
 */ // }}}

%fragment("DimboObIdVecTraits","header",fragment="StdSequenceTraits")
%{
  namespace swig {
    template <class ObT>
    struct traits_asptr<Dimbo::ObId_Vec<ObT> >  {
      static int asptr(PyObject *obj, Dimbo::ObId_Vec<ObT> **vec) {
	      return traits_asptr_stdseq<Dimbo::ObId_Vec<ObT> >::asptr(obj, vec);
      }
    };

    template <class ObT>
    struct traits_from<Dimbo::ObId_Vec<ObT> > {
      static PyObject *from(const Dimbo::ObId_Vec<ObT>& vec) {
	      return traits_from_stdseq<Dimbo::ObId_Vec<ObT> >::from(vec);
      }
    };
  }
%}

%include <dimbo/util/obid_vec_common.swg>
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
