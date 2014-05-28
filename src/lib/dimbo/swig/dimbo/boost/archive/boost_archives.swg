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

/** // doc: dimbo/boost/archive/boost_archives.swg {{{
 * \file dimbo/boost/archive/boost_archives.swg
 * \todo Write documentation
 */ // }}}

%include <dimbo/boost/archive/text_iarchive.swg>
%include <dimbo/boost/archive/text_oarchive.swg>
%include <dimbo/boost/archive/xml_iarchive.swg>
%include <dimbo/boost/archive/xml_oarchive.swg>
%include <dimbo/boost/archive/binary_iarchive.swg>
%include <dimbo/boost/archive/binary_oarchive.swg>

%include <dimbo/boost/serialization/nvp.swg>

%define DIMBO_EXTEND_BOOST_TEXT_OARCHIVE(__klass)
%extend boost::archive::detail::interface_oarchive<boost::archive::text_oarchive> {
  %template() operator<< < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define DIMBO_EXTEND_BOOST_XML_OARCHIVE(__klass)
%extend boost::archive::detail::interface_oarchive<boost::archive::xml_oarchive> {
  %template() operator<< < boost::serialization::nvp< __klass > const >;
  %template() operator& < boost::serialization::nvp< __klass > const >;
}
%enddef

%define DIMBO_EXTEND_BOOST_BINARY_OARCHIVE(__klass)
%extend boost::archive::detail::interface_oarchive<boost::archive::binary_oarchive> {
  %template() operator<< < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define DIMBO_EXTEND_BOOST_TEXT_IARCHIVE(__klass)
%extend boost::archive::detail::interface_iarchive<boost::archive::text_iarchive> {
  %template() operator>> < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define DIMBO_EXTEND_BOOST_XML_IARCHIVE(__klass)
%extend boost::archive::detail::interface_iarchive<boost::archive::xml_iarchive> {
  %template() operator>> < boost::serialization::nvp< __klass > const >;
  %template() operator& < boost::serialization::nvp< __klass > const >;
}
%enddef

%define DIMBO_EXTEND_BOOST_BINARY_IARCHIVE(__klass)
%extend boost::archive::detail::interface_iarchive<boost::archive::binary_iarchive> {
  %template() operator>> < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define DIMBO_EXTEND_BOOST_OARCHIVES(__klass)
DIMBO_EXTEND_BOOST_TEXT_OARCHIVE(__klass)
DIMBO_EXTEND_BOOST_XML_OARCHIVE(__klass)
DIMBO_EXTEND_BOOST_BINARY_OARCHIVE(__klass)
%enddef

%define DIMBO_EXTEND_BOOST_IARCHIVES(__klass)
DIMBO_EXTEND_BOOST_TEXT_IARCHIVE(__klass)
DIMBO_EXTEND_BOOST_XML_IARCHIVE(__klass)
DIMBO_EXTEND_BOOST_BINARY_IARCHIVE(__klass)
%enddef

%define DIMBO_EXTEND_BOOST_ARCHIVES(__klass)
// TODO: move the commented-out code to its appropriate place. Also, see what
// can we do to have the nvp working (currently it's not well recognized by
// swig, and "no destructor found" warning is displayed by python).
//%template(make_nvp) boost::serialization::make_nvp< __klass >;
//%template(make_nvp) boost::serialization::make_nvp< DIMBO_SHARED_PTR(__klass) >;
DIMBO_EXTEND_BOOST_IARCHIVES(__klass);
DIMBO_EXTEND_BOOST_OARCHIVES(__klass);
%enddef

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
