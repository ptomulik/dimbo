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

// dimbo/cl/context_properties.hpp

/** // doc: dimbo/cl/context_properties.hpp {{{
 * \file dimbo/cl/context_properties.hpp
 *
 * This file contains definition of Dimbo::Cl::Context_Properties class,
 * which encapsulates properties (\c cl_context_properties) used when creating
 * OpenCL contexts.
 */ // }}}
#ifndef DIMBO_CL_CONTEXT_PROPERTIES_HPP_INCLUDED
#define DIMBO_CL_CONTEXT_PROPERTIES_HPP_INCLUDED

//#include <dimbo/protobuf/cl/context_properties.pb.h>
#include <dimbo/cl/cl.hpp>
#include <dimbo/cl/platform.hpp>
#include <dimbo/cl/exceptions/invalid_argument.hpp>
#include <dimbo/cl/exceptions/length_error.hpp>
#include <dimbo/cl/exceptions/not_enough_space.hpp>
#include <dimbo/cl/exceptions/uninitialized.hpp>
#include <boost/optional.hpp>
#include <vector>

namespace Dimbo {
namespace Cl {

/** // {{{ DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE
 * \brief Static array size for context properties.
 *
 * This constant devices static size of array for OpenCL context properties
 * such that the array is able to contain all possible properties defined by
 * Context_Properties class.
 */ // }}}
#define DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE 5

/** // {{{ DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS
 * \brief List of exceptions that may be thrown by
 *        Context_Properties::assign_array() method.
 */ // }}}
#define DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS \
            DIMBO_CL_EXCEPTION(Length_Error) \
          , DIMBO_CL_EXCEPTION(Invalid_Argument)

/** // doc: class Context_Properties {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief Encapsulates OpenCL context properties.
 *
 * This class encapsulates a set of properties used by OpenCL when creating
 * OpenCL contexts (see the \c Contexts section in OpenCL specification).
 * Objects of type Context_Properties may be easily passed to the constructors
 * of Dimbo::Cl::Context class. Each property may be in "uninitialized" state,
 * in which case it is regarded as absent (not in set), or may have assigned
 * value. The properties handled by this object correspond to OpenCL context
 * properties described by the standard and are mentioned in the table below
 *
 * <table border=1>
 *  <tr>
 *    <th>\c cl_context_properties enum</th>
 *    <th>Check presence</th>
 *    <th>Get value</th>
 *    <th>Store value</th>
 *  </tr>
 *  <tr>
 *    <td>\c CL_CONTEXT_PLATFORM</td>
 *    <td>has_platform(), has_platform_id()</td>
 *    <td>platform(), platform_id()</td>
 *    <td>set_platform(), set_platform_id()</td>
 *  </tr>
 *  <tr>
 *    <td>\c CL_CONTEXT_INTEROP_USER_SYNC</td>
 *    <td>has_interop_user_sync()</td>
 *    <td>interop_user_sync()</td>
 *    <td>set_interop_user_sync()</td>
 *  </tr>
 * </table>
 *
 * \note
 * Before reading a property from this object (with e.g. platform_id()) always
 * check, if the propery is initialized. For this, use appropriate \c has_
 * method, for example has_platform_id(). If you'll try to access a property
 * that is is uninitialized, an exception will be raised.
 */ // }}}
class Context_Properties
{
private:
  boost::optional<cl_platform_id>  _platform_id;
  boost::optional<cl_bool> _interop_user_sync;
public:
  /** // doc: Context_Properties() {{{
   * \brief Default constructor.
   *
   * Creates an empty set of properties.
   */ // }}}
  Context_Properties();
  /** // doc: Context_Properties(Context_Properties const&) {{{
   * \brief Copy constructor.
   * \param rhs Another set of properties to be assigned to this object.
   *
   * Initializes this object with property values taken from \c rhs.
   */ // }}}
  Context_Properties(Context_Properties const& rhs);
  /** // doc: Context_Properties(...) {{{
   * \brief Ininitalize object from an array of properties.
   * \param props Pointer to array of properties.
   * \param size Size of the \c props array (may be greater than the size
   *    of actual content contained in array).
   *
   * This constructor takes a pointer to array of cl_context_properties and
   * assigns the properties encoded in the array to the object. The array
   * format is same as the format of \c properties for OpenCL functions
   * \c clCreateContext() and \c clCreateContextFromType(). The array should
   * contains a sequence of context property names, each one followed by its
   * corresponding value. See documentation of assign_array() for more
   * details.
   *
   * This constructor may throw exceptions specified by
   * DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS constant. See
   * documentation of assign_array() for details.
   */ // }}}
  explicit Context_Properties(cl_context_properties const* props,
          size_t size = DIMBO_CL_CONTEXT_PROPERTIES_ARRAY_SIZE)
    throw(DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS);
  /** // doc: Context_Properties(...){{{
   * \brief Ininitalize object form vector of properties.
   * \param props Vector with context properties.
   *
   * This constructor takes a reference to vector of cl_context_properties and
   * assigns the properties from vector to the object. The vector format
   * corresponds to the format of \c properties for OpenCL functions
   * \c clCreateContext() and \c clCreateContextFromType(). The vector should
   * contain a sequence of context property names each one followed by its
   * corresponding value. See documentation of assign_array() for more details.
   *
   * This constructor may throw exceptions specified by
   * DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS constant. See
   * documentation of assign_array() for details.
   */ // }}}
  explicit Context_Properties(std::vector<cl_context_properties> const& props)
    throw(DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS);
  /** // doc: ~Context_Properties() {{{
   * \brief Destructor
   */ // }}}
  virtual ~Context_Properties();
  /** // doc: clear() {{{
   * \brief Reset all the properties to "uninitialized" state.
   */ // }}}
  void clear();
#ifndef SWIG // FIXME: develop more verbose macro
  /** // doc: operator=() {{{
   * \brief Assignment operator
   * \param rhs Right hand size operand to assignment.
   * \return Reference to this object.
   */ // }}}
  Context_Properties& operator = (Context_Properties const& rhs);
#endif
  /** // doc: operator == () {{{
   * \brief Compare two sets of properties.
   * \param rhs Right hand side operand to the comparison.
   * \return Boolean value indicating if the compared sets are identical.
   *
   * This operator returns true if and only if two objects (*this and \c rhs)
   * have exactly same properties with exactly same values.
   */ // }}}
  bool operator == (Context_Properties const& rhs) const;
  /** // doc: operator != () {{{
   * \brief Oposite to operator == ().
   */ // }}}
  bool operator != (Context_Properties const& rhs) const;
  /** // doc: assign(Context_Properties& const rhs) {{{
   * \brief Assign all properties encapsulated by \c rhs to this object.
   * \param rhs Other object used which is to be assigned to this.
   */ // }}}
  void assign(Context_Properties const& rhs);
  /** // doc: assign_array(Context_Properties& const rhs) {{{
   * \brief Parse array of \c cl_context_properties and assign their values to
   *        this object.
   * \param props Pointer to an array of cl_context_properties.
   * \param size Size of the \c props array (may be greater than the size of
   *    actual content contained in array).
   *
   * \exception DIMBO_CL_EXCEPTION(Length_Error) if \c props is NULL but \c
   *            size is non-zero, or if \c size is such that it is not possible
   *            to fully parse all properties encoded in the array.
   * \exception DIMBO_CL_EXCEPTION(Invalid_Argument) if unsupported context
   *            property name is found in array or if there is property that
   *            appear twice in the array.
   *
   * The \c props argument specifies a list of context property names and their
   * corresponding values. Each property name is immediately followed by the
   * corresponding desired value. The list is terminated with 0. Up to \c size
   * elements from the array are processed.
   *
   * The list of supported properties is described the table below.
   *
   * <table border=1>
   *  <tr>
   *    <th>\c cl_context_properties enum</th>
   *    <th>Property value</th>
   *    <th>Description</th>
   *  </tr>
   *  <tr>
   *    <td>\c CL_CONTEXT_PLATFORM</td>
   *    <td>\c cl_platform_id</td>
   *    <td>Specifies the OpenCL platform to use.</td>
   *  </tr>
   *  <tr>
   *    <td>\c CL_CONTEXT_INTEROP_USER_SYNC</td>
   *    <td>\c cl_bool</td>
   *    <td>Specifies whether the user is responsible for synchronization
   *    between OpenCL and other APIs. See OpenCL specification for
   *    details</td>
   *  </tr>
   * </table>
   *
   * If the \c props is NULL and the \c size is zero, the object gets reset to
   * an empty state (all properties are uninitialized).
   *
   */ // }}}
  void assign_array(cl_context_properties const* props, size_t size)
    throw( DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS );
  /** // doc: has_platform() {{{
   * \brief Same as has_platform_id()
   * \return \c true, if this object has initialized the platform_id property
   *    or \c flase otherwise.
   */ // }}}
  bool has_platform() const;
  /** // doc: platform_id() {{{
   * \brief Check if the platform_id property is initialized.
   * \return \c true, if this object has initialized the platform_id property
   *    or \c flase otherwise.
   */ // }}}
  bool has_platform_id() const;
  /** // doc: interop_user_sync() {{{
   * \brief Check if the interop_user_sync property is initialized.
   * \return \c true, if this object has initailized the interop_user_sync
   *    property or \c flase otherwise.
   */ // }}}
  bool has_interop_user_sync() const;
  /** // doc: platform_id() {{{
   * \brief Get the platform stored as context property in this object.
   * \return A Platform object corresonding to platform ID encapsulated as a
   *    context property in this object.
   * \exception DIMBO_CL_EXCEPTION(Uninitialized) if the platform_id is not
   *    initialized ("not present") in this object.
   *
   *  The platform ID property corresponds to the OpenCL context property
   *  denoted by \c CL_CONTEXT_PLATFORM.
   */ // }}}
  Platform platform() const
    throw(DIMBO_CL_EXCEPTION(Uninitialized));
  /** // doc: platform_id() {{{
   * \brief Get the platform ID stored as context property in this object.
   * \return The platform ID stored as context property in this object.
   * \exception DIMBO_CL_EXCEPTION(Uninitialized) if the platform ID property
   *    is not initialized ("not present") in this object.
   *
   *  The platform ID property corresponds to the OpenCL context property
   *  denoted by \c CL_CONTEXT_PLATFORM.
   */ // }}}
  cl_platform_id platform_id() const
    throw(DIMBO_CL_EXCEPTION(Uninitialized));
  /** // doc: interop_user_sync() {{{
   * \brief Get the interop_user_sync property stored in this object.
   * \return The interop_user_sync property stored in this object.
   * \exception DIMBO_CL_EXCEPTION(Uninitialized) if the interop_user_sync is
   *    not initialized ("not present") in this object.
   *
   *  The interop_user_sync property corresponds to the OpenCL context property
   *  denoted by \c CL_CONTEXT_INTEROP_USER_SYNC.
   */ // }}}
  cl_bool interop_user_sync() const
    throw(DIMBO_CL_EXCEPTION(Uninitialized));
  /** // doc: set_platform(Platform) {{{
   * \todo Write documentation
   */ // }}}
  void set_platform(Platform const& platform);
  /** // doc: set_platform_id(cl_platform_id) {{{
   * \todo Write documentation
   */ // }}}
  void set_platform_id(cl_platform_id id);
  /** // doc: set_interop_user_sync(cl_interop_user_sync) {{{
   * \todo Write documentation
   */ // }}}
  void set_interop_user_sync(cl_bool ius);
  /** // doc: clear_platform_id(cl_platform_id) {{{
   * \todo Write documentation
   */ // }}}
  void clear_platform_id();
  /** // doc: clear_interop_user_sync(cl_interop_user_sync) {{{
   * \todo Write documentation
   */ // }}}
  void clear_interop_user_sync();
  /** // doc: fill_array(properties, size) const {{{
   * \todo Write documentation
   */ // }}}
  size_t array_size() const;
  /** // doc: fill_array(properties, size) const {{{
   * \todo Write documentation
   */ // }}}
  void fill_array(cl_context_properties* properties, size_t size) const
    throw( DIMBO_CL_EXCEPTION(Invalid_Argument)
         , DIMBO_CL_EXCEPTION(Not_Enough_Space) );
};
} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_CONTEXT_PROPERTIES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
