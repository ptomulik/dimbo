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

// dimbo/format/clinfo/platform_query.cpp

/** // doc: dimbo/format/clinfo/platform_query.cpp {{{
 * @file dimbo/format/clinfo/platform_query.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/format/clinfo/platform_query.hpp>
#include <dimbo/format/autosep.hpp>
#include <ostream>
#include <string>

template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

/* Name-pointer pair */
struct Npp
{
  const char* name;
  bool (Dimbo::Clinfo::Platform_Query::*ptr) () const;
};
#define NPP(name) { #name, &Dimbo::Clinfo::Platform_Query::name ## _selected}

static Npp npps[] =
{
  NPP(id)
, NPP(profile)
, NPP(version)
, NPP(name)
, NPP(vendor)
, NPP(extensions)
};

namespace Dimbo {
namespace Format {

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Clinfo::Platform_Query const& query, int ind)
{
  Autosep<const char*> as("\n");
  std::string pre(ind, ' ');
  for(int i=0; i<(int)(sizeof(npps)/sizeof(*npps));++i) {
    if((query.*(npps[i].ptr))())
      os << as << pre << npps[i].name;
  }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, Dimbo::Clinfo::Platform_Query const& query)
{
  return write(os, query, 0);
}

} /* namespace Format */
} /* namespace Dimbo */

template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , Dimbo::Clinfo::Platform_Query const& query)
{
  return Dimbo::Format::write(os, query);
}

// Instantiate our operator for several types.
template std::basic_ostream<char>&
operator << ( std::basic_ostream<char>& os
            , Dimbo::Clinfo::Platform_Query const& query );
template std::basic_ostream<wchar_t>&
operator << ( std::basic_ostream<wchar_t>& os
            , Dimbo::Clinfo::Platform_Query const& query );

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
