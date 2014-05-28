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

/** // doc: dimbo/shared_ptr.swg {{{
 * \file dimbo/shared_ptr.swg
 * \todo Write documentation
 */ // }}}

%{
#include <dimbo/shared_ptr.hpp>
%}

// NOTE: dimbo/shared_ptr.hpp uses alias template, which is not yet supported
//       by swig, so we replace the Dimbo::Shared_Ptr alias with
//       DIMBO_SHARED_PTR macro defined here
//%include <dimbo/shared_ptr.hpp>
%include <boost_shared_ptr.i>

#define DIMBO_SHARED_PTR(__t) boost::shared_ptr<__t>

// DIMBO_DECL_CLASS_SHARED_PTR1(__ns1,__klass)
// Having __ns1::__klass create wrappers for its shared_ptr, such that
// the following objects will be available to target language:
//
// * <__klass>_Ptr        (shared_ptr<__ns1::__klass>)
// * Const_<__klass>_Ptr  (shared_ptr<__ns1::__klass const>)
//
%define DIMBO_DECL_CLASS_SHARED_PTR1(__ns1,__klass)
%shared_ptr(__ns1::__klass);
namespace __ns1 {
  typedef DIMBO_SHARED_PTR(__ns1::__klass) __klass ## _Ptr;
  typedef DIMBO_SHARED_PTR(__ns1::__klass const) Const_ ## __klass ## _Ptr;
}
//%template(__klass ## _Ptr) DIMBO_SHARED_PTR(__ns1::__klass ## _Ptr);
//%template(Const_ ## __klass ## _Ptr) DIMBO_SHARED_PTR(__ns1::__klass ## _Ptr const);
%enddef

// DIMBO_DECL_CLASS_SHARED_PTR2(__ns1,__ns2,__klass)
// Having __ns1::__ns2::__klass create wrappers for its shared_ptr, such that
// the following objects will be available to target language:
//
// * <__klass>_Ptr        (shared_ptr<__ns1::__ns2::__klass>)
// * Const_<__klass>_Ptr  (shared_ptr<__ns1::__ns2::__klass const>)
//
%define DIMBO_DECL_CLASS_SHARED_PTR2(__ns1,__ns2,__klass)
%shared_ptr(__ns1::__ns2::__klass);
namespace __ns1 { namespace __ns2 {
  typedef DIMBO_SHARED_PTR(__ns1::__ns2::__klass) __klass ## _Ptr;
  typedef DIMBO_SHARED_PTR(__ns1::__ns2::__klass const) Const_ ## __klass ## _Ptr;
} }
//%template(__klass ## _Ptr) DIMBO_SHARED_PTR(__ns1::__ns2::__klass ## _Ptr);
//%template(Const_ ## __klass ## _Ptr) DIMBO_SHARED_PTR(__ns1::__ns2::__klass ## _Ptr const);
%enddef

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
