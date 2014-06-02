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

// dimbo/app/options/rethrow.hpp

/** // doc: dimbo/app/options/rethrow.hpp {{{
 * \file dimbo/app/options/rethrow.hpp
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_OPTIONS_RETHROW_HPP_INCLUDED
#define DIMBO_APP_OPTIONS_RETHROW_HPP_INCLUDED

#include <dimbo/app/options/exceptions.hpp>
#include <dimbo/app/options/throw.hpp>

/** // doc: DIMBO_APP_OPTIONS_RETHROW {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_APP_OPTIONS_RETHROW(__ex,__as) \
  catch(boost::program_options::__ex const& e) { \
    DIMBO_APP_OPTIONS_THROW(__as,e); \
  }

/** // doc: DIMBO_APP_OPTIONS_RETHROW_ALL {{{
 * \todo Write documentation
 */ // }}}
#define DIMBO_APP_OPTIONS_RETHROW_ALL() \
  DIMBO_APP_OPTIONS_RETHROW(too_many_positional_options_error, Too_Many_Positional_Options) \
  DIMBO_APP_OPTIONS_RETHROW(invalid_command_line_syntax, Invalid_Command_Line_Syntax) \
  DIMBO_APP_OPTIONS_RETHROW(reading_file, Reading_Options_File) \
  DIMBO_APP_OPTIONS_RETHROW(multiple_values, Multiple_Values) \
  DIMBO_APP_OPTIONS_RETHROW(multiple_occurrences, Multiple_Occurrences) \
  DIMBO_APP_OPTIONS_RETHROW(required_option, Required_Option) \
  DIMBO_APP_OPTIONS_RETHROW(unknown_option, Unknown_Option) \
  DIMBO_APP_OPTIONS_RETHROW(ambiguous_option, Ambiguous_Optin) \
  DIMBO_APP_OPTIONS_RETHROW(invalid_config_file_syntax, Invalid_Config_File_Syntax) \
  DIMBO_APP_OPTIONS_RETHROW(invalid_command_line_syntax, Invalid_Command_Line_Syntax) \
  DIMBO_APP_OPTIONS_RETHROW(invalid_option_value, Invalid_Option_Value) \
  DIMBO_APP_OPTIONS_RETHROW(invalid_bool_value, Invalid_Bool_Value)

#endif /* DIMBO_APP_OPTIONS_RETHROW_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
