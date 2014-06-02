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

// dimbo/app/options/exceptions.t.h

/** // doc: dimbo/app/options/exceptions.t.h {{{
 * \file dimbo/app/options/exceptions.t.h
 * \todo Write documentation
 */ // }}}
#ifndef DIMBO_APP_OPTIONS_EXCEPTIONS_T_H_INCLUDED
#define DIMBO_APP_OPTIONS_EXCEPTIONS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <dimbo/app/options/exceptions.hpp>
#include <dimbo/app/options/rethrow.hpp>

namespace Dimbo { namespace App { namespace Options { class Exceptions_TestSuite; } } }

/** // doc: class Dimbo::App::Options::Exceptions_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class Dimbo::App::Options::Exceptions_TestSuite : public CxxTest::TestSuite
{
protected:
  void rethrow_ambiguous_option()
  {
    char const* tmp[] = { "-a", "-b", "-c" };
    std::vector<std::string> xalternatives(tmp,tmp+3);
    try { throw boost::program_options::ambiguous_option(xalternatives); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_bool_value()
  {
    try { throw boost::program_options::invalid_bool_value("bleah bleah"); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_command_line_style()
  {
    try { throw boost::program_options::invalid_command_line_style("bleah bleah"); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_command_line_syntax()
  {
    boost::program_options::invalid_syntax::kind_t const kind =
      boost::program_options::invalid_syntax::long_not_allowed;
    try { throw boost::program_options::invalid_command_line_syntax(kind); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_config_file_syntax()
  {
    boost::program_options::invalid_syntax::kind_t const kind =
      boost::program_options::invalid_syntax::long_not_allowed;
    try { throw boost::program_options::invalid_config_file_syntax("bleah bleah", kind); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_option_value()
  {
    try { throw boost::program_options::invalid_option_value("bleah bleah"); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_multiple_occurrences()
  {
    try { throw boost::program_options::multiple_occurrences(); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_multiple_values()
  {
    try { throw boost::program_options::multiple_values(); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_reading_file()
  {
    try { throw boost::program_options::reading_file("bleah bleah"); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_required_option()
  {
    try { throw boost::program_options::required_option("bleah bleah"); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_too_many_positional_options_error()
  {
    try { throw boost::program_options::too_many_positional_options_error(); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_unknown_option()
  {
    try { throw boost::program_options::unknown_option(); }
    DIMBO_APP_OPTIONS_RETHROW_ALL()
  }
public:
  /** // doc: test_rethrow_ambiguous_option() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_ambiguous_option( )
  {
    TS_ASSERT_THROWS(rethrow_ambiguous_option(), DIMBO_APP_OPTIONS_EXCEPTION(Ambiguous_Option));
  }
  /** // doc: test_rethrow_invalid_bool_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_bool_value( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_bool_value(), DIMBO_APP_OPTIONS_EXCEPTION(Invalid_Bool_Option_Value));
  }
  /** // doc: test_rethrow_invalid_command_line_style() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_command_line_style( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_command_line_style(), DIMBO_APP_OPTIONS_EXCEPTION(Invalid_Command_Line_Style));
  }
  /** // doc: test_rethrow_invalid_command_line_syntax() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_command_line_syntax( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_command_line_syntax(), DIMBO_APP_OPTIONS_EXCEPTION(Invalid_Command_Line_Syntax));
  }
  /** // doc: test_rethrow_invalid_config_file_syntax() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_config_file_syntax( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_config_file_syntax(), DIMBO_APP_OPTIONS_EXCEPTION(Invalid_Config_File_Syntax));
  }
  /** // doc: test_rethrow_invalid_option_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_option_value( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_option_value(), DIMBO_APP_OPTIONS_EXCEPTION(Invalid_Option_Value));
  }
  /** // doc: test_rethrow_multiple_occurrences() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_multiple_occurrences( )
  {
    TS_ASSERT_THROWS(rethrow_multiple_occurrences(), DIMBO_APP_OPTIONS_EXCEPTION(Multiple_Option_Occurrences));
  }
  /** // doc: test_rethrow_multiple_values() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_multiple_values( )
  {
    TS_ASSERT_THROWS(rethrow_multiple_values(), DIMBO_APP_OPTIONS_EXCEPTION(Multiple_Option_Values));
  }
  /** // doc: test_rethrow_reading_file() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_reading_file( )
  {
    TS_ASSERT_THROWS(rethrow_reading_file(), DIMBO_APP_OPTIONS_EXCEPTION(Reading_Options_File));
  }
  /** // doc: test_rethrow_required_option() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_required_option( )
  {
    TS_ASSERT_THROWS(rethrow_required_option(), DIMBO_APP_OPTIONS_EXCEPTION(Required_Option));
  }
  /** // doc: test_rethrow_too_many_positional_options_error() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_too_many_positional_options_error( )
  {
    TS_ASSERT_THROWS(rethrow_too_many_positional_options_error(), DIMBO_APP_OPTIONS_EXCEPTION(Too_Many_Positional_Options));
  }
  /** // doc: test_rethrow_unknown_option() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_unknown_option( )
  {
    TS_ASSERT_THROWS(rethrow_unknown_option(), DIMBO_APP_OPTIONS_EXCEPTION(Unknown_Option));
  }
};

#endif /* DIMBO_APP_OPTIONS_EXCEPTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
