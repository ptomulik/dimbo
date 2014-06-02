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

// dimbo/cl/other_cl_error.hpp

/** // doc: dimbo/cl/other_cl_error.hpp {{{
 * \file dimbo/cl/other_cl_error.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_OTHER_CL_ERROR_HPP_INCLUDED
#define DIMBO_CL_OTHER_CL_ERROR_HPP_INCLUDED

#include <dimbo/cl/cl_error.hpp>
#include <exception>

namespace Dimbo {
namespace Cl {

/** // {{{
 * \todo Write documentation
 */ // }}}
class Other_Cl_Error
  : public Dimbo::Standardized_Exception<Cl_Error, std::exception>
  {
  private:
    cl_int _cl_error;
  public:
    /** // {{{
     * \todo Write documentation
     */ // }}}
    Other_Cl_Error(Other_Cl_Error const& e) throw()
      : Standardized_Exception(e)
      , _cl_error(e.cl_error()) { }
    /** // {{{
     * \todo Write documentation
     */ // }}}
    Other_Cl_Error(cl_int e, Debug_Info const& debug_info) throw()
      : Standardized_Exception(debug_info)
      ,  _cl_error(e) { }
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual ~Other_Cl_Error() throw() {}
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual char const* what() const throw()
    {
      return "other error";
    }
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual cl_int cl_error() const throw()
    {
      return this->_cl_error;
    }
  };

} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_OTHER_CL_ERROR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
