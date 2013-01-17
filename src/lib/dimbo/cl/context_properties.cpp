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

// dimbo/cl/context_properties.cpp 

/** // doc: dimbo/cl/context_properties.cpp {{{
 * \file dimbo/cl/context_properties.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/context_properties.hpp>

#include <dimbo/cl/throw.hpp>
#include <boost/none.hpp>

namespace Dimbo {
namespace Cl {
/* ----------------------------------------------------------------------- */
Context_Properties::
Context_Properties()
{
}
/* ----------------------------------------------------------------------- */
Context_Properties::
Context_Properties(Context_Properties const& rhs)
{
  this->assign(rhs);
}
/* ----------------------------------------------------------------------- */
Context_Properties::
Context_Properties(cl_context_properties const* props, size_t maxlen)
    throw(DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS)
{
  this->assign_array(props, maxlen);
}
/* ----------------------------------------------------------------------- */
Context_Properties::
Context_Properties(std::vector<cl_context_properties> const& props)
  throw(DIMBO_CL_CONTEXT_PROPERTIES_ASSIGN_ARRAY_EXCEPTIONS)
{
  this->assign_array(&props[0], props.size());
}
/* ----------------------------------------------------------------------- */
Context_Properties::
~Context_Properties()
{
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
clear()
{
  this->clear_platform_id();
  this->clear_interop_user_sync();
}
/* ----------------------------------------------------------------------- */
Context_Properties& Context_Properties::
operator = (Context_Properties const& rhs)
{
  this->assign(rhs);
  return *this;
}
/* ----------------------------------------------------------------------- */
bool Context_Properties::
operator == (Context_Properties const& rhs) const
{
  return this->_platform_id == rhs._platform_id
      && this->_interop_user_sync == rhs._interop_user_sync;
}
/* ----------------------------------------------------------------------- */
bool Context_Properties::
operator != (Context_Properties const& rhs) const
{
  return ! (*this == rhs);
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
assign(Context_Properties const& rhs)
{
  // NOTE: don't use get_xxx() without has_xxx()!
  this->_platform_id = rhs._platform_id;
  this->_interop_user_sync = rhs._interop_user_sync;
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
assign_array(cl_context_properties const* props, size_t size)
  throw( DIMBO_CL_EXCEPTION(Length_Error)
       , DIMBO_CL_EXCEPTION(Invalid_Argument) )
{
  cl_context_properties name;
  cl_context_properties value;

  if(!props && size)
    DIMBO_CL_THROW(Length_Error);

  // temporary object, to keep this one unchanged in case we must 
  // throw an exception
  Context_Properties cp; 
  while(size && *props)
    {
      name = *props++; --size;
      if(!size) DIMBO_CL_THROW(Length_Error);
      value = *props++; --size;
      switch(name)
        {
          case CL_CONTEXT_PLATFORM:
            if(cp.has_platform_id()) DIMBO_CL_THROW(Invalid_Argument);
            cp.set_platform_id((cl_platform_id)value);
            break;
          case CL_CONTEXT_INTEROP_USER_SYNC: 
            if(cp.has_interop_user_sync()) DIMBO_CL_THROW(Invalid_Argument);
            cp.set_interop_user_sync((cl_bool)value);
            break;
          default: DIMBO_CL_THROW(Invalid_Argument);
        }
    }
  this->assign(cp);
}
/* ----------------------------------------------------------------------- */
bool Context_Properties::
has_platform() const
{
  return this->_platform_id;
}
/* ----------------------------------------------------------------------- */
bool Context_Properties::
has_platform_id() const
{
  return this->_platform_id;
}
/* ----------------------------------------------------------------------- */
bool Context_Properties::
has_interop_user_sync() const
{
  return this->_interop_user_sync;
}
/* ----------------------------------------------------------------------- */
Platform Context_Properties::
platform() const
  throw(DIMBO_CL_EXCEPTION(Uninitialized))
{
  return Platform(this->platform_id());
}
/* ----------------------------------------------------------------------- */
cl_platform_id Context_Properties::
platform_id() const
  throw(DIMBO_CL_EXCEPTION(Uninitialized))
{
  if(!this->has_platform_id()) DIMBO_CL_THROW(Uninitialized);
  return *(this->_platform_id);
}
/* ----------------------------------------------------------------------- */
cl_bool Context_Properties::
interop_user_sync() const 
  throw(DIMBO_CL_EXCEPTION(Uninitialized))
{
  if(!this->has_interop_user_sync()) DIMBO_CL_THROW(Uninitialized);
  return *(this->_interop_user_sync);
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
set_platform(Platform const& platform)
{
  this->set_platform_id(platform.id());
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
set_platform_id(cl_platform_id id)
{
  this->_platform_id = id;
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
set_interop_user_sync(cl_bool ius)
{
  this->_interop_user_sync = ius;
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
clear_platform_id()
{
  this->_platform_id = boost::none_t();
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
clear_interop_user_sync()
{
  this->_interop_user_sync = boost::none_t();
}
/* ----------------------------------------------------------------------- */
size_t Context_Properties::
array_size() const
{
  size_t size = 1;
  if(this->has_platform_id()) size += 2;
  if(this->has_interop_user_sync()) size += 2;
  return size;
}
/* ----------------------------------------------------------------------- */
void Context_Properties::
fill_array(cl_context_properties* properties, size_t size) const
  throw( DIMBO_CL_EXCEPTION(Invalid_Argument)
       , DIMBO_CL_EXCEPTION(Not_Enough_Space) )
{
  if(properties == NULL)
    DIMBO_CL_THROW(Invalid_Argument);
  if(size < this->array_size())
    DIMBO_CL_THROW(Not_Enough_Space);
  size_t i = 0;
  if(this->has_platform_id())
    {
      properties[i++] = (cl_context_properties) CL_CONTEXT_PLATFORM;
      properties[i++] = (cl_context_properties) this->platform_id();
    }
  if(this->has_interop_user_sync())
    {
      properties[i++] = (cl_context_properties) CL_CONTEXT_INTEROP_USER_SYNC;
      properties[i++] = (cl_context_properties) this->interop_user_sync();
    }
  properties[i++] = 0; // trailing zero
}
/* ----------------------------------------------------------------------- */
} /* namespace Cl */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
