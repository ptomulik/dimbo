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

// dimbo/app/clinfo/main.cpp

/** // doc: dimbo/app/clinfo/main.cpp {{{
 * \file dimbo/app/clinfo/main.cpp
 * \todo Write documentation
 */ // }}}
#include <dimbo/cl/platform.hpp>
#include <dimbo/cl/platform_info.hpp>
#include <dimbo/app/clinfo/main.hpp>
#include <dimbo/app/clinfo/create_query.hpp>
#include <dimbo/format/cl/platform_layer_info.hpp>
//#include <dimbo/format/cl/platform_info.hpp>
//#include <dimbo/format/cl/device_info.hpp>
#include <dimbo/cl/platform_layer.hpp>
#include <dimbo/cl/platform_layer_info.hpp>

#include <dimbo/config.h>
#define DIMBO_GETTEXT_DOMAIN LIBDIMBO_CLINFO_GETTEXT_DOMAIN
#include <dimbo/gettext.hpp>

#include <boost/program_options/parsers.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace Dimbo {
namespace App {
namespace Clinfo {

static bool
process_help_options( Dimbo::App::Options::Options_Map const& om
                    , Dimbo::App::Clinfo::Options_Description const& od )
{
  if(om.count("help") || om.count("help-detail") || om.count("help-platform")
     || om.count("help-device") )
    {
      std::cout << _("Usage: ") << "dimbo-clinfo [options]"
                << std::endl << std::endl;
    }
  if(om.count("help"))
    {
      std::cout << od.common_options() << std::endl;
      std::cout << od.output_options() << std::endl;
      std::cout << od.platform_general_options() << std::endl;
      std::cout << od.device_general_options() << std::endl;
      return true;
    }
  if(om.count("help-detail"))
    {
      std::cout << od << std::endl;
      return true;
    }
  if(om.count("help-platform"))
    {
      std::cout << od.platform_general_options() << std::endl;
      std::cout << od.platform_detail_options() << std::endl;
      return true;
    }
  if(om.count("help-device"))
    {
      std::cout << od.device_general_options() << std::endl;
      std::cout << od.device_detail_options() << std::endl;
      return true;
    }
  return false;
}

template<class Archive> static void
serialize_platform_layer( Archive& ar
                        , Dimbo::Cl::Platform_Query const& platform_query
                        , Dimbo::Cl::Device_Query const& device_query )
{
  using Dimbo::Cl::Platform_Layer;
  using Dimbo::Cl::Platform_Layer_Info;

  Platform_Layer layer;
  Platform_Layer_Info info;
  info.query(layer, platform_query, device_query);

  ar << boost::serialization::make_nvp("platform_layer_info", info);
}

template<class Ostream> static void
display_platform_layer( Ostream& os
                      , Dimbo::Cl::Platform_Query const& platform_query
                      , Dimbo::Cl::Device_Query const& device_query
                      , int indent )
{
  using Dimbo::Cl::Platform_Layer;
  using Dimbo::Cl::Platform_Layer_Info;

  Platform_Layer layer;
  Platform_Layer_Info info;
  info.query(layer, platform_query, device_query);

  Dimbo::Format::write(os, info, indent);
}

Main::
Main()
  : Dimbo::App::Main()
{
  this->_init_main();
}

Main::
Main(int argc, char const* argv[])
  : Dimbo::App::Main()
{
  this->_init_main();
  this->init(argc,argv);
}

Main::
~Main()
{
}

int Main::
run()
{
  if(process_help_options(this->options_map(), this->options_description()))
    return EXIT_SUCCESS;

  bool xml = false;
  if(this->options_map().count("format"))
    {
      if(this->options_map()["format"].as<std::string>() == "xml")
        xml = true;
    }

  if(xml)
    { boost::archive::xml_oarchive ar(std::cout);
      serialize_platform_layer( ar
                              , create_platform_query(this->options_map())
                              , create_device_query(this->options_map()));
    }
  else
    {
      int indent = 2;
      if(this->options_map().count("indent"))
        indent = this->options_map()["indent"].as<int>();
      display_platform_layer( std::cout
                            , create_platform_query(this->options_map())
                            , create_device_query(this->options_map())
                            , indent );
    }
  return EXIT_SUCCESS;
}

void Main::
init(int argc, char const* argv[])
{
  using boost::program_options::parse_command_line;
  using boost::program_options::notify;
  using boost::program_options::store;

  this->_options_map.clear();
  store(parse_command_line(argc, argv, this->options_description()),
        this->_options_map);
  notify(this->_options_map);
}

void Main::
_init_main()
{
}

int
run(int argc, char const* argv[])
{
  Main clinfo(argc,argv);
  return clinfo.run();
}

} /* namespace Clinfo */
} /* namespace App */
} /* namespace Dimbo */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
