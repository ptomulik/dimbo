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

// dimbo/format/autosep.hpp

/** // doc: dimbo/format/autosep.hpp {{{ 
 * \file dimbo/format/autosep.hpp
 * \brief Contains template class Dimbo::Format::Autosep
 */ // }}}
#ifndef DIMBO_FORMAT_AUTOSEP_HPP_INCLUDED
#define DIMBO_FORMAT_AUTOSEP_HPP_INCLUDED

#include <ostream>

namespace Dimbo {
namespace Format {

/** // doc: class Autosep {{{
 * \ingroup Dimbo_Format
 *
 * \brief Automatic separator used to format strings representing lists,
 *        vectors and alike.
 *
 * \tparam SepT Type used for separator string (e.g. \c const \c char* or
 *         \c std::string).
 *
 * The Autosep object may be used to simplify task of writting out lists,
 * vectors, and other sequences to streams. The output() methods writes out the
 * separator to an output stream at its second and consecutive invocations
 * (first call prints nothing). The object may be used in expressions involving
 * operator \c <<.
 *
 * \b Example:
 * \snippet autosep1.cpp Program
 *
 */ // }}}
template<typename SepT>
class Autosep 
{
public:
  /** // doc: Autosep(sep) {{{
   * \brief Constructor
   *
   * \param sep Separator to be used by Autosep::output(), for example ","
   */ // }}}
  Autosep(SepT sep) : _sep(sep), _do_sep(false) { }
  /** // doc: output(os) {{{
   * \brief Output separator to a stream.
   * \param os Output stream used to output the separator to.
   * \return Output stream \c os.
   */ // }}}
  template<class Ostream>
  Ostream& output(Ostream& os) const
  {
    if(this->_do_sep)
      os << this->_sep;
    else
      this->_do_sep = true;
    return os;
  }
  /** // doc: reset() {{{
   * \brief Reset the Autosep to initial state. 
   *
   * Call this method to reset Autosep's state before reusing it to print
   * another sequence.
   *
   */ // }}}
  void reset() const
  {
    this->_do_sep = false;
  }
private:
  Autosep();
private:
  SepT _sep;
  mutable bool _do_sep;
};

/** // doc: autosep(sep) {{{
 * \ingroup Dimbo_Format
 *
 * \brief Create Autosep object (automatic separator).
 *
 * \tparam  SepT type of data used to represent automatic separator (e.g.
 *          const char* or std::string). It shall be deduced from \c sep
 *          argument.
 * \param   sep A value that will be used as a separator, for example \c ",".
 *
 * \return  An instance of Autosep<SepT>.
 *
 * This function is useful in expressions, where you don't have to declare
 * Autosep object by hand. The template parameter is deduced by C++ compiler.
 *
 * \b Example:
 *
 * \snippet autosep2.cpp Program
 */ // }}}
template<typename SepT>
Autosep<SepT> autosep(SepT sep)
{
  return Autosep<SepT>(sep);
}

} /* namespace Format */
} /* namespace Dimbo */

/** // doc: autosep(sep) {{{
 * \ingroup Dimbo_Format
 *
 * \brief Ouput Autosep to stream.
 * \tparam _CharT Same as in std::basic_string<_CharT, _Traits>, deduced from
 *         argument \c os.
 * \tparam _Traits Same as in std::basic_string<_CharT, _Traits>, deduced from
 *         argument \c os.
 * \tparam SepT Same as in Autosep<SepT>, deduced from argument \c as.
 * \param os Output stream.
 * \param as Dimbo::Format::Autosep object (auto-separator).
 * \return The reference provided by \c os argument
 *
 * This is template of overloaded operator \c << which outputs
 * Dimbo::Format::Autosep object to a stream.
 *
 */ // }}}
template<typename _CharT, typename _Traits, typename SepT>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , Dimbo::Format::Autosep<SepT> const& as)
{
  return as.output(os);
}
#endif /* DIMBO_FORMAT_AUTOSEP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
