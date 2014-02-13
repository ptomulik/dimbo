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

// dimbo/cl/cl_errors.hpp

/** // doc: dimbo/cl/cl_errors.hpp {{{
 * \file dimbo/cl/cl_errors.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_CL_CL_ERRORS_HPP_INCLUDED
#define DIMBO_CL_CL_ERRORS_HPP_INCLUDED

#include <dimbo/cl/cl_errors/common.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_work_dimension.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_kernel.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_program_executable.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_global_offset.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_work_item_size.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_program.hpp>
#include <dimbo/cl/cl_errors/cl_compiler_not_available.hpp>
#include <dimbo/cl/cl_errors/cl_map_failure.hpp>
#include <dimbo/cl/cl_errors/cl_image_format_not_supported.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_gl_object.hpp>
#include <dimbo/cl/cl_errors/cl_mem_object_allocation_failure.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_buffer_size.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_kernel_name.hpp>
#include <dimbo/cl/cl_errors/cl_mem_copy_overlap.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_kernel_args.hpp>
#include <dimbo/cl/cl_errors/cl_image_format_mismatch.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_work_group_size.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_found.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_event.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_value.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_platform.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_context.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_sampler.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_kernel_definition.hpp>
#include <dimbo/cl/cl_errors/cl_device_not_available.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_arg_value.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_mip_level.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_host_memory.hpp>
#include <dimbo/cl/cl_errors/cl_build_program_failure.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_binary.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_host_ptr.hpp>
#include <dimbo/cl/cl_errors/cl_profiling_info_not_available.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_arg_index.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_arg_size.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_queue_properties.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device_type.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_operation.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_image_format_descriptor.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_command_queue.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_build_options.hpp>
#include <dimbo/cl/cl_errors/cl_out_of_resources.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_event_wait_list.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_global_work_size.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_mem_object.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_image_size.hpp>
#include <dimbo/cl/cl_errors/cl_invalid_device.hpp>
#include <dimbo/cl/cl_errors/other_cl_error.hpp>

#endif /* DIMBO_CL_CL_ERRORS_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
