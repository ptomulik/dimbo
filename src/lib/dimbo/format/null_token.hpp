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

// dimbo/format/null_token.hpp

/** // doc: dimbo/format/null_token.hpp {{{
 * @file dimbo/format/null_token.hpp
 * @todo Write documentation
 */ // }}}
#ifndef DIMBO_FORMAT_NULL_TOKEN_HPP_INCLUDED
#define DIMBO_FORMAT_NULL_TOKEN_HPP_INCLUDED

namespace Dimbo {
namespace Format {

/** // doc: class Null_Token {{{
 * @todo Write documentation
 */ // }}}
struct Null_Token { };
extern const Null_Token null_token;

} /* namespace Format */
} /* namespace Dimbo */

#include <iosfwd>

/** // doc: os << Null_Token {{{
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , Dimbo::Format::Null_Token )
{
  return os;
}

#endif /* DIMBO_FORMAT_NULL_TOKEN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
