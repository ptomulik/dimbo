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

/** // doc: dimbo/boost/archive/xml_iarchive.swg {{{
 * \file dimbo/boost/archive/xml_iarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <dimbo/std/iostream_mod.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <dimbo/clinfo/device_info.hpp>
#include <boost/serialization/shared_ptr.hpp>
%}

%import <dimbo/std/iostream_mod.i>
%include <dimbo/boost/archive/detail/interface_iarchive.swg>

namespace boost {
namespace archive {
class xml_iarchive;
%template(interface_iarchive_T_xml_iarchive) detail::interface_iarchive<xml_iarchive>;
class xml_iarchive 
  : public detail::interface_iarchive<xml_iarchive>
  {
  public:
    xml_iarchive(std::istream &os, unsigned int flags = 0);
   ~xml_iarchive();
  };
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
