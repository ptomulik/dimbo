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

// dimbo/cl/device.hpp

/** // doc: dimbo/cl/device.hpp {{{
 * \file dimbo/cl/device.hpp
 *
 * This file contains definition of Dimbo::Cl::Device class which provides
 * proxy object to access locally available OpenCL device.
 */ // }}}
#ifndef DIMBO_CL_DEVICE_HPP_INCLUDED
#define DIMBO_CL_DEVICE_HPP_INCLUDED

#include <dimbo/cl/exceptions/bad_alloc.hpp>
#include <dimbo/cl/exceptions/uninitialized_device.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_resources.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>

#include <vector>
#include <string>

namespace Dimbo {
namespace Cl {

/** // doc: DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \def DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS
 * \brief Exceptions that may be thrown by Dimbo::Cl::get_device_info()
 *        functions.
 *
 *  The listed exceptions correspond to the followind OpenCL errors:
 *
 *  - \c CL_INVALID_DEVICE,
 *  - \c CL_INVALID_VALUE,
 *  - \c CL_OUT_OF_RESOURCES (first mentioned in OpenCL v1.1),
 *  - \c CL_OUT_OF_HOST_MEMORY (first mentioned in OpenCL v1.1)
 */ // }}}
#define DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS \
           DIMBO_CL_CL_ERROR_NO(CL_INVALID_DEVICE) \
         , DIMBO_CL_CL_ERROR_NO(CL_INVALID_VALUE) \
         , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_RESOURCES) \
         , DIMBO_CL_CL_ERROR_NO(CL_OUT_OF_HOST_MEMORY) \
         , DIMBO_CL_OTHER_CL_ERROR

/** // doc: DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief Exceptions that may be thrown by Dimbo::Cl::Device::get_info()
 *        method, and several other related methods of Dimbo::Cl::Device.
 * \def DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS
 */ // }}}
#define DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS \
           DIMBO_CL_EXCEPTION(Uninitialized_Device) \
         , DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS

/** // doc: Device {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief Proxy object to access OpenCL device information.
 *
 * \note The class has no virtual destructor to not bloat the objects with
 *       virtual tables.
 *
 * This is lightweight object, in fact it carries only \c cl_device_id
 * identifier.
 *
 * This class provides access to OpenCL device information equivalent to
 * that offered by OpenCL's \c clGetDeviceInfo() function. Compared to
 * \c clGetDeviceInfo() it has simplified usage and replaces error codes
 * returned by OpenCL calls with exceptions defined within DIMBO library
 * (see Dimbo::Cl::Cl_Error). It also uses std::string and std::vector instead
 * of raw \c char* buffers and other C pointers.
 *
 * Depending on the OpenCL version, the following device info may be queried:
 *
 * | MACRO                                                | 1.0     | 1.1     | 1.2     |
 * | ---------------------------------------------------- | ------- | ------- | ------- |
 * | CL_DEVICE_TYPE                                       | &radic; | &radic; | &radic; |
 * | CL_DEVICE_VENDOR_ID                                  | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_COMPUTE_UNITS                          | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS                   | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_WORK_GROUP_SIZE                        | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_WORK_ITEM_SIZES                        | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR                | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT               | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT                 | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG                | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT               | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE              | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_CLOCK_FREQUENCY                        | &radic; | &radic; | &radic; |
 * | CL_DEVICE_ADDRESS_BITS                               | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_READ_IMAGE_ARGS                        | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_WRITE_IMAGE_ARGS                       | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_MEM_ALLOC_SIZE                         | &radic; | &radic; | &radic; |
 * | CL_DEVICE_IMAGE2D_MAX_WIDTH                          | &radic; | &radic; | &radic; |
 * | CL_DEVICE_IMAGE2D_MAX_HEIGHT                         | &radic; | &radic; | &radic; |
 * | CL_DEVICE_IMAGE3D_MAX_WIDTH                          | &radic; | &radic; | &radic; |
 * | CL_DEVICE_IMAGE3D_MAX_HEIGHT                         | &radic; | &radic; | &radic; |
 * | CL_DEVICE_IMAGE3D_MAX_DEPTH                          | &radic; | &radic; | &radic; |
 * | CL_DEVICE_IMAGE_SUPPORT                              | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_PARAMETER_SIZE                         | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_SAMPLERS                               | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MEM_BASE_ADDR_ALIGN                        | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE                   | &radic; | &radic; | &radic; |
 * | CL_DEVICE_SINGLE_FP_CONFIG                           | &radic; | &radic; | &radic; |
 * | CL_DEVICE_GLOBAL_MEM_CACHE_TYPE                      | &radic; | &radic; | &radic; |
 * | CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE                  | &radic; | &radic; | &radic; |
 * | CL_DEVICE_GLOBAL_MEM_CACHE_SIZE                      | &radic; | &radic; | &radic; |
 * | CL_DEVICE_GLOBAL_MEM_SIZE                            | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE                   | &radic; | &radic; | &radic; |
 * | CL_DEVICE_MAX_CONSTANT_ARGS                          | &radic; | &radic; | &radic; |
 * | CL_DEVICE_LOCAL_MEM_TYPE                             | &radic; | &radic; | &radic; |
 * | CL_DEVICE_LOCAL_MEM_SIZE                             | &radic; | &radic; | &radic; |
 * | CL_DEVICE_ERROR_CORRECTION_SUPPORT                   | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PROFILING_TIMER_RESOLUTION                 | &radic; | &radic; | &radic; |
 * | CL_DEVICE_ENDIAN_LITTLE                              | &radic; | &radic; | &radic; |
 * | CL_DEVICE_AVAILABLE                                  | &radic; | &radic; | &radic; |
 * | CL_DEVICE_COMPILER_AVAILABLE                         | &radic; | &radic; | &radic; |
 * | CL_DEVICE_EXECUTION_CAPABILITIES                     | &radic; | &radic; | &radic; |
 * | CL_DEVICE_QUEUE_PROPERTIES                           | &radic; | &radic; | &radic; |
 * | CL_DEVICE_NAME                                       | &radic; | &radic; | &radic; |
 * | CL_DEVICE_VENDOR                                     | &radic; | &radic; | &radic; |
 * | CL_DRIVER_VERSION                                    | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PROFILE                                    | &radic; | &radic; | &radic; |
 * | CL_DEVICE_VERSION                                    | &radic; | &radic; | &radic; |
 * | CL_DEVICE_EXTENSIONS                                 | &radic; | &radic; | &radic; |
 * | CL_DEVICE_PLATFORM                                   | &radic; | &radic; | &radic; |
 * | CL_DEVICE_DOUBLE_FP_CONFIG                           |         |         | &radic; |
 * | CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF                |         | &radic; | &radic; |
 * | CL_DEVICE_HOST_UNIFIED_MEMORY                        |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR                   |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT                  |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_INT                    |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG                   |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT                  |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE                 |         | &radic; | &radic; |
 * | CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF                   |         | &radic; | &radic; |
 * | CL_DEVICE_OPENCL_C_VERSION                           |         | &radic; | &radic; |
 * | CL_DEVICE_LINKER_AVAILABLE                           |         |         | &radic; |
 * | CL_DEVICE_BUILT_IN_KERNELS                           |         |         | &radic; |
 * | CL_DEVICE_IMAGE_MAX_BUFFER_SIZE                      |         |         | &radic; |
 * | CL_DEVICE_IMAGE_MAX_ARRAY_SIZE                       |         |         | &radic; |
 * | CL_DEVICE_PARENT_DEVICE                              |         |         | &radic; |
 * | CL_DEVICE_PARTITION_MAX_SUB_DEVICES                  |         |         | &radic; |
 * | CL_DEVICE_PARTITION_PROPERTIES                       |         |         | &radic; |
 * | CL_DEVICE_PARTITION_AFFINITY_DOMAIN                  |         |         | &radic; |
 * | CL_DEVICE_PARTITION_TYPE                             |         |         | &radic; |
 * | CL_DEVICE_REFERENCE_COUNT                            |         |         | &radic; |
 * | CL_DEVICE_PREFERRED_INTEROP_USER_SYNC                |         |         | &radic; |
 * | CL_DEVICE_PRINTF_BUFFER_SIZE                         |         |         | &radic; |
 * | CL_DEVICE_IMAGE_PITCH_ALIGNMENT                      |         |         | &radic; |
 * | CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT               |         |         | &radic; |
 */ // }}}
class Device
{
private:
  cl_device_id _device_id;
public:
  /** // {{{
   * \brief Default constructor
   *
   * Sets internal device ID to NULL, so this proxy object is regardes as
   * uninitialized (get_initilized() returns \c false).
   */ // }}}
  Device() throw()
    :_device_id(NULL)
  {
  }
  /** // {{{
   * \brief Copy constructor
   *
   * Sets internal device ID to the device ID of the other proxy object (rhs).
   */ // }}}
  Device(Device const& rhs) throw()
    : _device_id(rhs.id())
  {
  }
  /** // {{{
   * \brief Converting constructor.
   *
   * Sets internal device ID to the value provided by caller.
   */ // }}}
  explicit Device(cl_device_id devid) throw()
    : _device_id(devid)
  {
  }
  /** // {{{
   * \brief Destructor
   */ // }}}
  ~Device()
  {
  }
/* FIXME: develop more verbose macro name */
#ifndef SWIG
  /** // {{{
   * \brief Assignment operator.
   * \return Reference to this object.
   */ // }}}
  Device& operator=(Device const& rhs)
    throw(DIMBO_CL_EXCEPTION(Uninitialized_Device))
  {
    this->assign(rhs);
    return *this;
  }
  /** // {{{
   * \brief Explicit conversion to \c cl_device_id identifier.
   * \return %Device identifier of type \c cl_device_id.
   */ // }}}
  explicit operator cl_device_id () const
  {
    return this->_device_id;
  }
#endif
  /** // {{{
   * \brief Assignment.
   *
   * Assigns device ID of other Device proxy object to this object.
   */ // }}}
  void assign(Device const& rhs) throw()
  {
    if(&rhs != this)
      {
        this->_device_id = rhs.id();
      }
  }
  /** // {{{
   * \brief Checks if the proxy object is initialized.
   * \return True if object is initialized (id is not NULL) or false otherwise.
   */ // }}}
  bool is_initialized() const throw()
  {
    return (this->_device_id != NULL);
  }
  /** // {{{
   * \brief Get device ID of the proxied OpenCL device.
   * \return The ID of OpenCL device represented by this proxy object (or NULL
   *         if the object is not iniatilized).
   */ // }}}
  cl_device_id id() const
    throw()
  {
    return this->_device_id;
  }
  /** // {{{
   * \brief Verify and return the device ID.
   * \return The ID of OpenCL device represented by this proxy object.
   * \exception DIMBO_CL_EXCEPTION(Uninitialized_Device) In case the object is
   *    not initialized (is_initialized() returned \c false).
   */ // }}}
  cl_device_id get_valid_id() const
    throw(DIMBO_CL_EXCEPTION(Uninitialized_Device));
  /** // {{{
   * \brief Get certain information from device.
   * \param name
   *    An enumeration constant that identifies the device information being
   *    queried. It can be one of the values as specified in the OpenCL
   *    specification (\c clGetDeviceInfo()).
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \c param_value.
   *    This size in bytes must be greater than or equal to size of return type
   *    specified in the OpenCL specification (\c clGetDeviceInfo()).
   * \param value
   *    A pointer to memory location where appropriate values for a given
   *    \c param_name as specified in the OpenCL specification
   *    (\c clGetDeviceInfo()) will be returned. If \c param_value is \c NULL,
   *    it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \c
   *    param_value. If \c param_value_size_ret is \c NULL, it is ignored
   *
   * The call to this function yields same information as call to
   * \c clGetDeviceInfo(this->id(),name,value_size,value,value_size_ret).
   *
   * In case of error, this method throws one of the exceptions defined by
   * DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS.
   */ // }}}
  void get_info( cl_device_info name, size_t value_size, void* value,
                 size_t* value_size_ret) const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   *  \brief Get \c CL_DEVICE_TYPE information.
   *  \return The OpenCL device type. It may be for example
   *      \c CL_DEVICE_TYPE_CPU, \c CL_DEVICE_TYPE_GPU, or other value defined
   *      by OpenCL specification (depending on OpenCL version).
   */ // }}}
  cl_device_type get_type() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_VENDOR information.
   * \return A unique device vendor identifier. An example of a unique device
   *    identifier could be the PCIe ID
   */ // }}}
  cl_uint get_vendor_id() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_COMPUTE_UNITS information.
   * \return The number of parallel compute cores on the OpenCL device. The
   *    minimum value is 1.
   */ // }}}
  cl_uint get_max_compute_units() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS information.
   * \return Maximum dimensions that specify the global and local work-item IDs
   *    used by the data parallel execution model. The minimum value is 3.
   */ // }}}
  cl_uint get_max_work_item_dimensions() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WORK_GROUP_SIZE information.
   * \return Maximum number of work-items in a work-group executing a kernel
   *    using the data parallel execution model. The minimum value is \c 1.
   */ // }}}
  size_t get_max_work_group_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WORK_ITEM_SIZES information.
   * \return Maximum number of work-items that can be specified in each
   *    dimension of the work-group to \c clEnqueueNDRangeKernel. Returns \c n
   *    \c size_t entries, where \c n is the value returned by the query for \c
   *    CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS. The minimum value is
   *    \c (1,\c 1, \c 1).
   */ // }}}
  std::vector<size_t> get_max_work_item_sizes() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR information.
   * \return Preferred native vector width size for built-in \c char scalar
   *    when put into vector. The vector width is defined as the number of \c
   *    char elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_char() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT information.
   * \return Preferred native vector width size for built-in \c short scalar
   *    when put into vector. The vector width is defined as the number of \c
   *    short elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_short() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT information.
   * \return Preferred native vector width size for built-in \c int scalar
   *    when put into vector. The vector width is defined as the number of
   *    \c int elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_int() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG information.
   * \return Preferred native vector width size for built-in \c long scalar
   *    when put longo vector. The vector width is defined as the number of
   *    \c long elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_long() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT information.
   * \return Preferred native vector width size for built-in \c float scalar
   *    when put floato vector. The vector width is defined as the number of
   *    \c float elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_float() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE information.
   * \return Preferred native vector width size for built-in \c double scalar
   *    when put doubleo vector. The vector width is defined as the number of
   *    \c double elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_double() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_CLOCK_FREQUENCY information.
   * \return Maximum configured clock frequency of the device in MHz.
   */ // }}}
  cl_uint get_max_clock_frequency() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_ADDRESS_BITS information.
   * \return The default compute device address space size specified as an
   *    unsigned integer value in bits (e.g. 32 or 64 bits).
   */ // }}}
  cl_uint get_address_bits() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_MEM_ALLOC_SIZE information.
   * \return Max size of memory object allocation in bytes. The minimum value
   *    is max (1/4th of CL_DEVICE_GLOBAL_MEM_SIZE, 128*1024*1024)
   */ // }}}
  cl_ulong get_max_mem_alloc_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE_SUPPORT information.
   * \return CL_TRUE if images are supported by the OpenCL device and CL_FALSE
   *    otherwise.
   */ // }}}
  cl_bool get_image_support() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_READ_IMAGE_ARGS information.
   * \return Max number of simultaneous image objects that can be read by a
   *    kernel. The minimum value is 128 if \c CL_DEVICE_IMAGE_SUPPORT is
   *    \c CL_TRUE.
   */ // }}}
  cl_uint get_max_read_image_args() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WRITE_IMGE_ARGS information.
   * \return Max number of simultaneous image objects that can be written to by
   * a kernel. The minimum value is 8 if \c CL_DEVICE_IMAGE_SUPPORT is
   * \c CL_TRUE.
   */ // }}}
  cl_uint get_max_write_image_args() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE2D_MAX_WIDTH information.
   * \return Max width of 2D image in pixels. The minimum value is 8192 if \c
   *    CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image2d_max_width() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE2D_MAX_HEIGHT information.
   * \return Max height of 2D image in pixels. The minimum value is 8192 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image2d_max_height() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE3D_MAX_WIDTH information.
   * \return Max width of 3D image in pixels. The minimum value is 2048 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image3d_max_width() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE3D_MAX_HEIGHT information.
   * \return Max height of 3D image in pixels. The minimum value is 2048 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image3d_max_height() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE3D_MAX_DEPTH information.
   * \return Max depth of 3D image in pixels. The minimum value is 2048 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image3d_max_depth() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_SAMPLERS information.
   * \return Maximum number of samplers that can be used in a kernel. The
   *    minimum value is 16 if \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  cl_uint get_max_samplers() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_PARAMETER_SIZE information.
   * \return Max size in bytes of the arguments that can be passed to a kernel.
   *    The minimum value is 1024. For this minimum value, only a maximum of
   *    128 arguments can be passed to a kernel.
   */ // }}}
  size_t get_max_parameter_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MEM_BASE_ADDR_ALIGN information.
   * \return Describes the alignment in bits of the base address of any
   *    allocated memory object.
   */ // }}}
  cl_uint get_mem_base_addr_align() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE information.
   * \return The smallest alignment in bytes which can be used for any data
   *    type.
   */ // }}}
  cl_uint get_min_data_type_align_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get CL_DEVICE_SINGLE_FP_CONFIG information
   * \return Value of type cl_device_fp_config.
   *
   * The returned value describes single precision floating-point capability of
   * the device. This is a bit-field that describes one or more of the
   * following values:
   *
   * - \c CL_FP_DENORM - denorms are supported,
   * - \c CL_FP_INF_NAN - INF and quiet NaNs are supported,
   * - \c CL_FP_ROUND_TO_NEAREST - round to nearest even rounding mode
   *   supported,
   * - \c CL_FP_ROUND_TO_ZERO - round to zero rounding mode supported
   * - \c CL_FP_ROUND_TO_INF - round to +ve and -ve infinity rounding modes
   *   supported
   * - \c CL_FP_FMA - IEEE754-2008 fused multiply-add is supported
   * - \c CL_FP_SOFT_FLOAT - Basic floating-point operations (such as addition,
   *   subtraction, multiplication) are implemented in software.
   *
   * The mandated minimum floating-point capability is
   * \c CL_FP_ROUND_TO_NEAREST \c | \c CL_FP_INF_NAN.
   */ // }}}
  cl_device_fp_config get_single_fp_config() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_CACHE_TYPE information.
   * \return Type of global memory cache supported. Possible values are:
   *    \c CL_NONE, \c CL_READ_ONLY_CACHE, and \c CL_READ_WRITE_CACHE.
   */ // }}}
  cl_device_mem_cache_type get_global_mem_cache_type() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE information.
   * \return Size of global memory cache line in bytes.
   */ // }}}
  cl_uint get_global_mem_cacheline_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_CACHE_SIZE information.
   * \return Type of global memory cache supported. Possible values are:
   *    \c CL_NONE, \c CL_READ_ONLY_CACHE, and \c CL_READ_WRITE_CACHE.
   */ // }}}
  cl_ulong get_global_mem_cache_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_SIZE information.
   * \return Size of global device memory in bytes.
   */ // }}}
  cl_ulong get_global_mem_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE information.
   * \return Max size in bytes of a constant buffer allocation. The minimum
   *         value is 64KB.
   */ // }}}
  cl_ulong get_max_constant_buffer_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_CONSTANT_ARGS information.
   * \return Max number of arguments declared with the \c __constant qualifier
   *    in a kernel. The minimum value is 8.
   */ // }}}
  cl_uint get_max_constant_args() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_LOCAL_MEM_TYPE information.
   * \return Type of local memory supported. This can be set to \c CL_LOCAL
   *    implying dedicated local memory storage such as \c SRAM, or
   *    \c CL_GLOBAL.
   */ // }}}
  cl_device_local_mem_type get_local_mem_type() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_LOCAL_MEM_SIZE information.
   * \return Size of local memory arena in bytes. The minimum value is 32 KB.
   */ // }}}
  cl_ulong get_local_mem_size() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_ERROR_CORRECTION_SUPPORT information.
   * \return \c CL_TRUE if the device implements error correction for all
   *    accesses to compute device memory (global and constant);
   *    \c CL_FALSE if * the device does not implement such error correction.
   */ // }}}
  cl_bool get_error_correction_support() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PROFILING_TIMER_RESOLUTION information.
   * \return Describes the resolution of device timer. This is measured in
   *    nanoseconds.
   */ // }}}
  size_t get_profiling_timer_resolution() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_ENDIAN_LITTLE information.
   * \return \c CL_TRUE if the OpenCL device is a little endian device and \c
   *    CL_FALSE otherwise.
   */ // }}}
  cl_bool get_endian_little() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_AVAILABLE information.
   * \return CL_TRUE if the device is available and CL_FALSE if the device is
   *  not available.
   */ // }}}
  cl_bool get_available() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_COMPILER_AVAILABLE information.
   * \return \c CL_FALSE if the implementation does not have a compiler
   *    available to compile the program source; \c CL_TRUE if the compiler is
   *    available. This can be \c CL_FALSE for the embedded platform profile
   *    only.
   */ // }}}
  cl_bool get_compiler_available() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \todo Get \c CL_DEVICE_EXECUTION_CAPABILITIES information.
   * \return Value of type: \c cl_device_exec_capabilities
   *
   * The returned value describes the execution capabilities of the device.
   * This is a bit-field that describes one or more of the following values:
   *
   * - \c CL_EXEC_KERNEL - The OpenCL device can execute OpenCL kernels.
   * - \c CL_EXEC_NATIVE_KERNEL - The OpenCL device can execute native kernels.
   *
   * The mandated minimum capability is \c CL_EXEC_KERNEL.
   */ // }}}
  cl_device_exec_capabilities get_execution_capabilities() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_QUEUE_PROPERTIES information.
   * \return Value of type: \c cl_command_queue_properties.
   *
   * The returned value describes the command-queue properties supported by the
   * device. This is a bit-field that describes one or more of the following
   * values:
   *
   * - CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE
   * - CL_QUEUE_PROFILING_ENABLE
   *
   * These properties are described in the table for clCreateCommandQueue in
   * OpenCL specification. The mandated minimum capability is
   * \c CL_QUEUE_PROFILING_ENABLE.
   */ // }}}
  cl_command_queue_properties get_queue_properties() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NAME information.
   * \return %Device name string.
   */ // }}}
  std::string get_name() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get CL_DEVICE_VENDOR information.
   * \return Vendor name string.
   */ // }}}
  std::string get_vendor() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DRIVER_VERSION information.
   * \return OpenCL software driver version string in the form
   *    \c major_number.minor_number.
   */ // }}}
  std::string get_driver_version() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PROFILE information.
   * \return OpenCL profile string.
   *
   * Returns the profile name supported by the device (see note). The profile
   * name returned can be one of the following strings:
   *
   * - \c FULL_PROFILE - if the device supports the OpenCL specification
   *   (functionality defined as part of the core specification and does not
   *   require any extensions to be supported).
   * - \c EMBEDDED_PROFILE - if the device supports the OpenCL embedded
   *   profile.
   */ // }}}
  std::string get_profile() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_VERSION
   * \return OpenCL version string.
   *
   * Returns the OpenCL version supported by the device. This version string
   * has the following format:
   * <verbatim>OpenCL<space><major_version.minor_version><space><vendor-specific information></verbatim>
   */ // }}}
  std::string get_version() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_EXTENSIONS information.
   * \return Returns a space-separated list of extension names.
   *
   * The list of extension names returned is defined by OpenCL standard and
   * depends on OpenCL version.
   */ // }}}
  std::string get_extensions() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PLATFORM information.
   * \return ID of the platform associated with this device.
   */ // }}}
  cl_platform_id get_platform_id() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF information.
   * \return Preferred native vector width size for built-in \c half scalar
   *    when put halfo vector. The vector width is defined as the number of
   *    \c half elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_half() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_HOST_UNIFIED_MEMORY information.
   * \return \c CL_TRUE if the device and the host have a unified memory
   *    subsystem; \c CL_FALSE otherwise
   */ // }}}
  cl_bool get_host_unified_memory() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_char() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_short() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_INT information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_int() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_long() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_float() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_double() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_half() const
    throw( DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Get \c CL_DEVICE_OPENCL_C_VERSION information.
   * \return OpenCL C version string.
   *
   * Returns the highest OpenCL C version supported by the compiler for this
   * device. This version string has the following format:
   * <verbatim>OpenCL<space>C<space><major_version.minor_version><space><vendor-specific information></verbatim>
   */ // }}}
  std::string get_opencl_c_version() const
    throw( DIMBO_CL_EXCEPTION(Bad_Alloc)
         , DIMBO_CL_DEVICE_GET_INFO_EXCEPTIONS );
  /** // {{{
   * \brief Equal-to overloade operator.
   */ // }}}
  bool operator == (Device const& x) const
  {
    return x.id() == this->id();
  }
  /** // {{{
   * \brief Non equal-to overloade operator.
   */ // }}}
  bool operator != (Device const& x) const
  {
    return x.id() != this->id();
  }
};

/** // {{{
 * \ingroup Dimbo_Cl_Platform
 * \brief Get certain information from device.
 * \param device
 *    %Device identifier of type cl_device_id.
 * \param name
 *    An enumeration constant that identifies the device information being
 *    queried. It can be one of the values as specified in the OpenCL
 *    specification (\c clGetDeviceInfo()).
 * \param value_size
 *    Specifies the size in bytes of memory pointed to by \c param_value.
 *    This size in bytes must be greater than or equal to size of return type
 *    specified in the OpenCL specification (\c clGetDeviceInfo()).
 * \param value
 *    A pointer to memory location where appropriate values for a given
 *    \c param_name as specified in the OpenCL specification
 *    (\c clGetDeviceInfo()) will be returned. If \c param_value is \c NULL, it
 *    is ignored.
 * \param value_size_ret
 *    Returns the actual size in bytes of data being queried by \c
 *    param_value. If \c param_value_size_ret is \c NULL, it is ignored
 *
 * The call to this function yields same information as call to
 * \c clGetDeviceInfo(device,name,value_size,value,value_size_ret).
 *
 * In case of error, this method throws one of the exceptions defined by
 * DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS.
 */ // }}}
void
get_device_info( cl_device_id device, cl_device_info name, size_t value_size,
                 void* value, size_t* value_size_ret)
  throw( DIMBO_CL_GET_DEVICE_INFO_EXCEPTIONS );

} // namespace Cl {
} // namespace Dimbo {

#include <dimbo/util/obid_id.hpp>
namespace Dimbo {
template<> struct obid_id<Dimbo::Cl::Device>
{
  typedef cl_device_id type;
};
} /* namespace Dimbo */

#endif /* DIMBO_CL_DEVICE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
