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
#include <dimbo/app/clinfo/main.hpp>
#include <dimbo/app/clinfo/create_query.hpp>

#include <dimbo/cl/platform_layer.hpp>
#include <dimbo/clinfo/platform_layer_info.hpp>
#include <dimbo/serialization/clinfo/platform_layer_info.hpp>
#include <dimbo/format/clinfo/platform_layer_info.hpp>

#include <dimbo/config.h>
#define DIMBO_GETTEXT_DOMAIN LIBDIMBO_APP_CLINFO_GETTEXT_DOMAIN
#include <dimbo/gettext.hpp>

#include <boost/program_options/parsers.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
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
      std::cout << od.io_options() << std::endl;
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
  using Dimbo::Clinfo::Platform_Layer_Info;
  using boost::serialization::make_nvp;
  struct noop { void operator()(...) const{}; };

  enum Output_Format {
    of_human,   // Human-readable text 
    of_xml,     // Serialized to XML
    of_text,    // Serialized to text
    of_bin      // Serializaed to binary form
  };
  enum Input_Format {
    if_xml,     // Serialized to XML
    if_text,    // Serialized to text
    if_bin      // Serializaed to binary form
  };
  Output_Format oformat = of_text;

  if(process_help_options(this->options_map(), this->options_description()))
    return EXIT_SUCCESS;

  Platform_Layer_Info platform_layer_info;

  if(this->options_map().count("input"))
    {
      Input_Format iformat = if_xml;
      if(this->options_map().count("input-format"))
        {
          if(this->options_map()["input-format"].as<std::string>() == "xml")
            iformat = if_xml;
          else if(this->options_map()["input-format"].as<std::string>() == "text")
            iformat = if_text;
          else if(this->options_map()["input-format"].as<std::string>() == "bin")
            iformat = if_bin;
        }

      std::string ifile(this->options_map()["input"].as<std::string>());
      boost::shared_ptr<std::istream> ifs;
      if(ifile == "-")
        ifs.reset(&std::cin, noop());
      else
        ifs.reset(new std::ifstream(ifile));

      switch(iformat)
        {
          case if_text:
            { 
              boost::archive::text_iarchive ar(*ifs);
              ar >> make_nvp("platform_layer_info", platform_layer_info);
            }
            break;
          case if_bin:
            { 
              boost::archive::binary_iarchive ar(*ifs);
              ar >> make_nvp("platform_layer_info", platform_layer_info);
            }
            break;
          default:
            { 
              boost::archive::xml_iarchive ar(*ifs);
              ar >> make_nvp("platform_layer_info", platform_layer_info);
            }
            break;
        }
    }
  else
    {
      using Dimbo::Cl::Platform_Layer;
      using Dimbo::Clinfo::Platform_Query;
      using Dimbo::Clinfo::Device_Query;
      using Dimbo::Cl::query_platform_info;
      platform_layer_info = query_platform_layer_info(
          Platform_Layer(), 
          create_platform_query(this->options_map()),
          create_device_query(this->options_map())
     );
    }

  if(this->options_map().count("output-format"))
    {
      if(this->options_map()["output-format"].as<std::string>() == "human")
        oformat = of_human;
      else if(this->options_map()["output-format"].as<std::string>() == "xml")
        oformat = of_xml;
      else if(this->options_map()["output-format"].as<std::string>() == "text")
        oformat = of_text;
      else if(this->options_map()["output-format"].as<std::string>() == "bin")
        oformat = of_bin;
    }

  boost::shared_ptr<std::ostream> ofs;
  if(this->options_map().count("output"))
    {
      std::string ofile(this->options_map()["output"].as<std::string>());
      if(ofile == "-")
        ofs.reset(&std::cout, noop());
      else
        ofs.reset(new std::ofstream(ofile));
    }
  else
    ofs.reset(&std::cout, noop());


  switch(oformat)
    {
      case of_xml:
        { 
          boost::archive::xml_oarchive ar(*ofs);
          ar << make_nvp("platform_layer_info", platform_layer_info);
        }
        break;
      case of_text:
        { 
          boost::archive::text_oarchive ar(*ofs);
          ar << make_nvp("platform_layer_info", platform_layer_info);
        }
        break;
      case of_bin:
        { 
          boost::archive::binary_oarchive ar(*ofs);
          ar << make_nvp("platform_layer_info", platform_layer_info);
        }
        break;
      default:
        {
          int indent = 2;
          if(this->options_map().count("indent"))
            indent = this->options_map()["indent"].as<int>();
          Dimbo::Format::write(*ofs, platform_layer_info, indent);
        }
        break;
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
