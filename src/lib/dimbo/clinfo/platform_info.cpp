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

// dimbo/clinfo/platform_info.cpp

/** // doc: dimbo/clinfo/platform_info.cpp {{{
 * @file dimbo/clinfo/platform_info.cpp
 * @todo Write documentation
 */ // }}}
#include <dimbo/clinfo/platform_info.hpp>
#include <dimbo/clinfo/throw.hpp>

namespace Dimbo {
namespace Clinfo {

/* ------------------------------------------------------------------------ */
Platform_Info::
Platform_Info()
{
  _init();
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear()
{
  this->_clear();
  return *this;
}
/* ------------------------------------------------------------------------ */
bool Platform_Info::
cmp(Platform_Info const& rhs) const
  throw()
{
  return ((this->_id == rhs._id)
      && ((this->_profile == rhs._profile))
      && ((this->_version == rhs._version))
      && ((this->_name == rhs._name))
      && ((this->_vendor == rhs._vendor))
      && ((this->_extensions == rhs._extensions)));
}
// getters {{{
/* ------------------------------------------------------------------------ */
unsigned long Platform_Info::
id() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_id()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_id.get();
}
/* ------------------------------------------------------------------------ */
std::string const& Platform_Info::
profile() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_profile()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_profile.get();
}
/* ------------------------------------------------------------------------ */
std::string const& Platform_Info::
version() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_version()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_version.get();
}
/* ------------------------------------------------------------------------ */
std::string const& Platform_Info::
name() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_name()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_name.get();
}
/* ------------------------------------------------------------------------ */
std::string const& Platform_Info::
vendor() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_vendor()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_vendor.get();
}
/* ------------------------------------------------------------------------ */
std::string const& Platform_Info::
extensions() const
  throw(DIMBO_CLINFO_EXCEPTION(Uninitialized_Value))
{
  if(!this->has_extensions()) { DIMBO_CLINFO_THROW(Uninitialized_Value); }
  return this->_extensions.get();
}
/* ------------------------------------------------------------------------ */
// }}}
// setters {{{
Platform_Info& Platform_Info::
set_id(unsigned long val) throw()
{
  this->_id = val;
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
set_profile(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_profile = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
set_version(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_version = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
set_name(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_name = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
set_vendor(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_vendor = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
set_extensions(std::string const& val)
  throw(DIMBO_CLINFO_EXCEPTION(Bad_Alloc), DIMBO_CLINFO_EXCEPTION(Length_Error))
{
  try { this->_extensions = val; }
  catch(std::bad_alloc const&) { DIMBO_CLINFO_THROW(Bad_Alloc); }
  catch(std::length_error const&) { DIMBO_CLINFO_THROW(Length_Error); }
  return *this;
}
// }}}
// cleaners {{{
Platform_Info& Platform_Info::
clear_id() throw()
{
  this->_id = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear_profile() throw()
{
  this->_profile = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear_version() throw()
{
  this->_version = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear_name() throw()
{
  this->_name = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear_vendor() throw()
{
  this->_vendor = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
Platform_Info& Platform_Info::
clear_extensions()
throw()
{
  this->_extensions = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
// }}}
// presence {{{
bool Platform_Info::
has_id() const throw()
{
  return this->_id.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool Platform_Info::
has_profile() const throw()
{
  return this->_profile.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool Platform_Info::
has_version() const throw()
{
  return this->_version.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool Platform_Info::
has_name() const throw()
{
  return this->_name.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool Platform_Info::
has_vendor() const throw()
{
  return this->_vendor.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool Platform_Info::
has_extensions() const throw()
{
  return this->_extensions.is_initialized();
}
// }}}
/* ------------------------------------------------------------------------ */
void Platform_Info::
_init()
{
  this->_clear();
}
/* ------------------------------------------------------------------------ */
void Platform_Info::
_clear()
{
  this->_id = boost::none;
  this->_profile = boost::none;
  this->_version = boost::none;
  this->_name = boost::none;
  this->_vendor = boost::none;
  this->_extensions = boost::none;
}
/* ------------------------------------------------------------------------ */
} /* namespace Clinfo */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
