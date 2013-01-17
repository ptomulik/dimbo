/*
 * @COPYRIGHT@
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */

// dimbo/gettext.hpp

/** // doc: dimbo/gettext.hpp {{{
 * \file dimbo/gettext.hpp
 * \todo Write documentation 
 */ // }}}
#ifndef DIMBO_GETTEXT_HPP_INCLUDED
#define DIMBO_GETTEXT_HPP_INCLUDED

#include <dimbo/config.h>

#if !defined( DIMBO_ENABLE_NLS ) 
#  if defined( ENABLE_NLS ) && ENABLE_NLS
#    define DIMBO_ENABLE_NLS 1
#  else
#    define DIMBO_ENABLE_NLS 0
#  endif
#endif

#if !defined( DIMBO_USE_GETTEXT_DOMAINS )
# define DIMBO_USE_GETTEXT_DOMAINS 1
#endif


#define N_(__str) gettext_noop(__str)

#if DIMBO_ENABLE_NLS && HAVE_LIBINTL_H
#  include <libintl.h>
#  if DIMBO_USE_GETTEXT_DOMAINS && (defined DIMBO_GETTEXT_DOMAIN)
#    define _(msg) dgettext (DIMBO_GETTEXT_DOMAIN,msg)
#    define _n(msg1,msgn,n) dngettext (DIMBO_GETTEXT_DOMAIN,msg1,msgn,n)
#  else
#    define _(msg) gettext (msg)
#    define _n(msg1,msgn,n) ngettext (msg1,msgn,n)
#  endif
#else
#  define _(msg) (msg)
#  define _n(msg1,msgn,n) (((n) > 1 || (n) < -1) ? (msg1) : (msgn))
#  define textdomain(__dom)
#  define bindtextdomain(__pkg, __dir)
#endif

#ifndef gettext_noop
# define gettext_noop(__str) __str
#endif


#endif
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
