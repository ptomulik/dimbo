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

// dimbo/cl/cl_error.hpp

/** // doc:  dimbo/cl/cl_error.hpp {{{
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CL_ERROR_HPP_INCLUDED
#define DIMBO_CL_CL_ERROR_HPP_INCLUDED


/* Dimbo includes */
#include <dimbo/cl/exception.hpp>
#include <CL/cl.h>

namespace Dimbo {
/** // {{{
 * \todo Write documentation (look for better place for it)
 */ // }}}
namespace Cl {
/** // {{{
 * \class Dimbo::Cl::Cl_Error
 * \brief Dimbo OpenCL exception.
 *
 * \attention
 * Do not derive from this class. Use Dimbo::Standardized_Exception template
 * class instead.
 *
 * \note
 * This is dummy class, concrete exceptions should derive also from concrete
 * standard exception(s) using multiple inheritance.
 *
 * \todo Write documentation
 */ // }}}
class Cl_Error
  : public Exception
  {
  public:
    /** // {{{
     * \todo Write documentation
     */ // }}}
    explicit Cl_Error(Cl_Error const& e)
      : Exception(e) { }
    /** // {{{
     * \brief Constructor
     *
     * This constructor stores into Dimbo::Exception the reference to exception
     * source in source code.
     */ // }}}
    explicit Cl_Error(Src_At const& at) throw()
      : Exception(at) { }
    /** // doc: ~Cl_Error {{{
     * \todo Write documentation
     */ // }}}
    virtual ~Cl_Error() throw() {}
    /** // {{{
     * \todo Write documentation
     */ // }}}
    virtual cl_int cl_error() const throw() = 0;
  };

} /* namespace Cl */
} /* namespace Dimbo */

#endif
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
