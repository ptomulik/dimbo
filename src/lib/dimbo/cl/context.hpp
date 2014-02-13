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

// dimbo/cl/context.hpp

/** // doc: dimbo/cl/context.hpp {{{
 * \file dimbo/cl/context.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CONTEXT_HPP_INCLUDED
#define DIMBO_CL_CONTEXT_HPP_INCLUDED

#include <dimbo/cl/context_properties.hpp>
#include <dimbo/cl/devices.hpp>

#include <dimbo/cl/exceptions/decl_logic_error.hpp>
#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/exceptions/uninitialized_context.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_available.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_found.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_context.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device_type.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_platform.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>

#include <vector>

namespace Dimbo {
namespace Cl {

/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief List of exceptions that might be thrown by
 *        Dimbo::Cl::get_context_info()
 */ // }}}
#define DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief List of exceptions that might be thrown by
 *        Dimbo::Cl::Context::get_info()
 */ // }}}
#define DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS \
            DIMBO_CL_EXCEPTION(Uninitialized_Context) \
          , DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief List of exceptions that might be thrown by
 *        Dimbo::Cl::create_context()
 */ // }}}
#define DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_PLATFORM) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_DEVICE) \
          , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_AVAILABLE) \
          , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief List of exceptions that might be thrown by
 *        Dimbo::Cl::create_context_from_type()
 */ // }}}
#define DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_PLATFORM) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
          , DIMBO_CL_CL_ERROR_NO(CL_INVALID_DEVICE_TYPE) \
          , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_AVAILABLE) \
          , DIMBO_CL_CL_ERROR_NO(CL_DEVICE_NOT_FOUND) \
          , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
          , DIMBO_CL_OTHER_CL_ERROR
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief List of exceptions that might be thrown by
 *        Dimbo::Cl::Context::Context(Dimbo::Cl::Context_Properties const&,Dimbo::Cl::Devices const&,void(*)(const char*,const void*,size_t,void*),void*)
 */ // }}}
#define DIMBO_CL_CONTEXT_CREATE_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) \
          , DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS
/** // doc: DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief List of exceptions that might be thrown by
 *        Dimbo::Cl::Context::Context(Dimbo::Cl::Context_Properties const&,cl_device_type,void(*)(const char*,const void*,size_t,void*),void*)
 */ // }}}
#define DIMBO_CL_CONTEXT_CREATE_FROM_TYPE_EXCEPTIONS \
            DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) \
          , DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS

/** // doc: Context {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief Proxy to OpenCL context.
 *
 * This class represents OpenCL context and forwards basic operations on
 * contexts to OpenCL platform layer. It encapsulates a \c cl_context handle
 * and supports following operations:
 *
 * - context creation (constructors), by calling internally
 *   \c clCreateContext() and \c clCreateContextFromType(),
 * - automatic reference count management by using internally
 *   \c clRetainContext() and \c clReleaseContext(),
 * - retrieving context information from OpenCL (via class methods),
 *   by invoking internally \c clGetContextInfo().
 *
 * \note Because a Context object maintains internally reference count for
 *       its \c cl_context handle, the \c cl_context handle is hidden
 *       from users (private). This is intentional, the intent is to force the
 *       usage of Context objects to achieve consistency in the reference count
 *       management. If you need the \c cl_context_id for your own operations,
 *       just derive a new class from the Context and use Context::ctx()
 *       or Context::get_valid_ctx() to retrieve the \c cl_context handle from
 *       Context base class.
 *
 * \note There are constructors which create new OpenCL context (a costly
 *       operation). However, assignment operator and copy constructors just
 *       copy the \cl_context handle held by another Context object and modify
 *       reference count appropriately. To verify if two Context objects
 *       refer to the same OpenCL context use \c == operator (or \c !=
 *       operator).
 *
 * \note An OpenCL context (identified by \c cl_context handle) is not released
 *       until there is at least one Context object encapsulating its handle.
 *       On the other hand - the context may get released by OpenCL when last
 *       proxy Context object gets deleted (the ~Context() destructor
 *       decreases reference count for its \c cl_context handle with \c
 *       clReleaseContext()).
 */ // }}}
class Context
{
private:
  cl_context  _ctx;
  Context();
protected:
  /** // doc: ctx() {{{
   * \brief   Get \c cl_context handle held by \c this object.
   *
   * \return  The \c cl_context handle held by \c this object.
   */ // }}}
  cl_context ctx() const
    throw( );
  /** // doc: get_valid_ctx() {{{
   * \brief   Check if \c this object is initialized and return \c cl_context
   *          handle held by this object.
   *
   * \return  The \c cl_context handle to OpenCL context encapsulated within
   *          this object.
   *
   * \exception DIMBO_CL_EXCEPTION(Uninitialized_Context) when trying to
   *          retrieve \c cl_context from uninitialized Context object.
   */ // }}}
  cl_context get_valid_ctx() const
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Context) );
  /** // doc: _sdoc: _set_id() {{{
   * \brief Set new \c cl_context handle to this object
   *
   * \param ctx
   *    A \c cl_context handle to OpenCL context. It must be a valid handle if
   *    \c retain_new is true.
   * \param retain_new
   *    If \c true, the reference count for \c ctx gets increased,
   * \param release_old
   *    If \c true, the reference count for old identifier encapsulated to this
   *    end by the object gets decreased,
   *
   * \exception DIMBO_CL_CL_ERROR(CL_INVALID_CONTEXT)
   *    thrown when the \c retain_new is true and \c ctx is not a valid
   *    \c cl_context handle or when \c release_old is \c true and \c this
   *    object holds an invalid \c cl_context handle.
   */ // }}}
  void _set_id(cl_context ctx, bool retain_new, bool release_old)
    throw( DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
public:
  /** // doc: ~Context() {{{
   * \brief Destructor
   *
   * Internally decreases reference count for this context.
   */ // }}}
  virtual ~Context() throw();
  /** // doc: Context(props, devs[, pfn_notify[, user_data]]) {{{
   * \brief Constructor - create new OpenCL context (costly).
   *
   * \param props
   *    A Context_Properties object which defines properties of newly created
   *    context.
   * \param devs
   *    A Dimbo::Cl::Devices object which provides a list of (unique) devices
   *    or sub-devices for use with this context.
   * \param pfn_notify
   *    A callback function that can be registered by the application. This
   *    callback function will be used by the OpenCL implementation to report
   *    information on errors during context creation as well as errors that
   *    occur at runtime in this context. This callback function may be called
   *    asynchronously by the OpenCL implementation. It is the application’s
   *    responsibility to ensure that the callback function is thread-safe. The
   *    parameters to this callback function are:
   *      - \c errinfo is a pointer to an error string,
   *      - \c private_info and \c cb represent a pointer to binary data that
   *        is returned by the OpenCL implementation that can be used to log
   *        additional information helpful in debugging the error,
   *      - \c user_data is a pointer to user supplied data.
   * \param user_data
   *    Will be passed as the \c user_data argument when \c pfn_notify is
   *    called. \c user_data can be NULL.
   *
   * This constructor calls \c clCreateContext() to create new OpenCL context
   * and stores the returned \c cl_context handle to the newly created Context
   * object.
   *
   * In case of errors, this constructor may throw one of the exceptions
   * defined by \ref DIMBO_CL_CONTEXT_CREATE_EXCEPTIONS constant.
   */ // }}}
  Context(Context_Properties const& props, Devices const& devs,
          void(*pfn_notify)(const char* errinfo,
                            const void* private_info, size_t cb,
                            void* user_data) = NULL,
          void* user_data = NULL)
    throw( DIMBO_CL_CONTEXT_CREATE_EXCEPTIONS );
  /** // doc: Context() {{{
   * \brief Constructor - create new OpenCL context (costly).
   *
   * \param props
   *    A Context_Properties object which defines properties of newly created
   *    context.
   * \param device_type
   *     A bit-field that identifies the type of device, e.g. (combination of)
   *     \c CL_DEVICE_TYPE_CPU, \c CL_DEVICE_TYPE_GPU and so on. For the list
   *     of all valid device types consult the OpenCL standard.
   * \param pfn_notify
   *    A callback function that can be registered by the application. This
   *    callback function will be used by the OpenCL implementation to report
   *    information on errors during context creation as well as errors that
   *    occur at runtime in this context. This callback function may be called
   *    asynchronously by the OpenCL implementation. It is the application’s
   *    responsibility to ensure that the callback function is thread-safe. The
   *    parameters to this callback function are:
   *      - \c errinfo is a pointer to an error string,
   *      - \c private_info and \c cb represent a pointer to binary data that
   *        is returned by the OpenCL implementation that can be used to log
   *        additional information helpful in debugging the error,
   *      - \c user_data is a pointer to user supplied data.
   * \param user_data
   *    Will be passed as the \c user_data argument when \c pfn_notify is
   *    called. \c user_data can be NULL.
   *
   * This constructor calls \c clCreateContextFromType() to create new OpenCL
   * context and stores the returned \c cl_context handle to the newly created
   * Context object.
   *
   * In case of errors, this constructor may throw one of the exceptions
   * defined by \ref DIMBO_CL_CONTEXT_CREATE_FROM_TYPE_EXCEPTIONS constant.
   */ // }}}
  Context(Context_Properties const& properties,
          cl_device_type device_type,
          void(*pfn_notify)(const char* errinfo,
                            const void* private_info,
                            size_t cb,
                            void* user_data) = NULL,
          void* user_data = NULL)
    throw( DIMBO_CL_CONTEXT_CREATE_FROM_TYPE_EXCEPTIONS );
  /** // doc: Context(rhs) {{{
   * \brief Copy constructor (reference copy).
   *
   * \param rhs
   *    Another Context object to be assigned to this object.
   *
   * \exception DIMBO_CL_EXCEPTION(Uninitialized_Context)
   *    thrown when \c rhs is uninitialized.
   * \exception DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT)
   *    thrown when \c rhs holds a \c cl_context handle that is invalid.
   *
   * This constructor creates Context object referring to the same OpenCL
   * context as \c rhs does. After that, the newly created (this) object and
   * the \c rhs hold \c cl_context handle to the same OpenCL context. The
   * reference count for this handle is increased by one during
   * copy-construction by performing an internal call to \c clRetainContext().
   */ // }}}
  Context(Context const& rhs)
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Context)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
/* FIXME: develop more verbose constant name */
#ifndef SWIG
  /** // {{{
   * \brief Assignment operator
   *
   * \param rhs Another Context object to be assigned to this object
   *
   * \return Reference to this object
   *
   * \exception DIMBO_CL_EXCEPTION(Uninitialized_Context)
   *    thrown when the \c rhs object is in uninitialized state
   * \exception DIMBO_CL_EXCEPTION(CL_INVALID_CONTEXT)
   *    thrown when the \c rhs holds invalid \c cl_context handle
   *
   *  This operation copies the \c cl_context handle held by \c rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \c rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   */ // }}}
  Context& operator=(Context const& rhs)
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Context)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
#endif
  /** // {{{
   * \brief Compare this Context with another one
   *
   * \param rhs
   *    Another Context object to be compared to \c this object.
   *
   * \return
   *    Returns \c true if both, \c this and \c rhs, refer to the same OpenCL
   *    context, or \c false otherwise.
   */ // }}}
  bool operator == (Context const& rhs) const
    throw();
  /** // {{{
   * \brief Compare this Context with another one
   *
   * \param rhs
   *    Another Context object to be compared to \c this object.
   *
   * \return <tt>!(*this == rhs)</tt>
   */ // }}}
  bool operator != (Context const& rhs) const
    throw();
  /** // {{{
   * \brief Assignment
   *
   * \exception DIMBO_CL_EXCEPTION(Uninitialized_Context)
   *    thrown when \c rhs is an uninitialized Context object.
   * \exception DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT)
   *    thrown when \c rhs holds a \c cl_context handle that is invalid.
   *
   *  This operation copies the \c cl_context handle held by \c rhs
   *  to \c this object and maintains reference count appropriately. The
   *  reference count for handle originating from \c rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  handle held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   */ // }}}
  void assign(Context const& rhs)
    throw( DIMBO_CL_EXCEPTION(Uninitialized_Context)
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_CONTEXT) );
  /** // {{{
   * \brief   Is this object properly initialized?
   *
   * \return  Returns \c true if \c this object is initialized or false
   *          otherwise.
   */ // }}}
  bool is_initialized() const
    throw()
  {
    return (this->_ctx != NULL);
  }
  /** // doc: get_info() {{{
   * \brief Get certain context information from OpenCL platform layer.
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     It may be for example \c CL_CONTEXT_REFERENCE_COUNT, \c
   *     CL_CONTEXT_NUM_DEVICES and so on. The complete list of allowed
   *     parameter names may be found in the OpenCL specification.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \c value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \c clGetContextInfo()).
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \c value is NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \c value. If
   *    \c value_size_ret is NULL, it is ignored.
   *
   * This function calls internally \c clGetContextInfo().
   *
   * In case of errors, this function throws one of the exceptions defined by
   * \ref DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS constant.
   */ // }}}
  void get_info(cl_context_info name, size_t value_size, void* value,
                size_t* value_size_ret) const
    throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_reference_count() {{{
   * \brief   Get reference count for the OpenCL context referred to by
   *          \c this object.
   *
   * \return  The reference count for the OpenCL context referred to by
   *          \c this object as returned by
   *          \c clGetContextInfo(this->_ctx,CL_CONTEXT_REFERENCE_COUNT,...)
   *
   * In case of errors, the method throws one of the exceptions defined
   * by \ref DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS constant.
   */ // }}}
  cl_uint get_reference_count() const
    throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_reference_count() {{{
   * \brief   Get the number of devices in context.
   *
   * \return  The number of devices in context, as returned by
   *          \clGetContextInfo(this->_ctx,CL_CONTEXT_NUM_DEVICES,...)
   *
   * In case of errors, the method throws one of the exceptions defined
   * by \ref DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS constant.
   */ // }}}
  cl_uint get_num_devices() const
    throw( DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_devices() {{{
   * \brief Get the list of devices in context.
   *
   * \return A Dimbo::Cl::Devices object with all devices in this context.
   *
   * The returned result contains devices as returned by the call
   * \c clGetContextInfo(this->_ctx,CL_CONTEXT_DEVICES,...).
   *
   * In case of errors, this method throws DIMBO_CL_EXCEPTION(Bad_Alloc)
   * or one of the exceptions defined by
   * \ref DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS constant.
   */ // }}}
  Devices get_devices() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
  /** // doc: get_properties() {{{
   * \brief Get context properties specified at context creation.
   *
   * \return Properties of this OpenCL context.
   *
   * In case of errors, this method throws DIMBO_CL_EXCEPTION(Bad_Alloc)
   * or one of the exceptions defined by
   * \ref DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS constant.
   */ // }}}
  Context_Properties get_properties() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_CONTEXT_GET_INFO_EXCEPTIONS );
};
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 *
 * \brief Get context info for OpenCL context.
 *
 * \param context
 *    Specifies the OpenCL context being queried
 * \param name
 *    An enumeration constant that specifies the information to query
 * \param value_size
 *    Specifies the size in bytes of memory pointed to by \c value. This
 *    size must be greater than or equal to the size of return type as
 *    described in the OpenCL standard (see documentation of
 *    \c clGetContextInfo()).
 * \param value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \c value is \c NULL, it is ignored.
 * \param value_size_ret
 *    Returns the actual size in bytes of data being queried by \c value.
 *    If \c value_size_ret is \c NULL, it is ignored.
 *
 * In case of error, this function throws one of the exceptions defined
 * by \ref DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS constant.
 */ // }}}
void
get_context_info(cl_context context, cl_context_info name,
                 size_t value_size, void *value,
                 size_t* value_size_ret)
  throw( DIMBO_CL_GET_CONTEXT_INFO_EXCEPTIONS );
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
cl_context
create_context(const cl_context_properties* properties,
               cl_uint num_devices,
               const cl_device_id* devices,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data)
  throw( DIMBO_CL_CREATE_CONTEXT_EXCEPTIONS );
/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \todo Write documentation
 */ // }}}
cl_context
create_context_from_type(const cl_context_properties* properties,
               cl_device_type device_type,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data)
  throw( DIMBO_CL_CREATE_CONTEXT_FROM_TYPE_EXCEPTIONS );
} /* namespace Cl */
} /* namespace Dimbo */

#endif /* DIMBO_CL_CONTEXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
