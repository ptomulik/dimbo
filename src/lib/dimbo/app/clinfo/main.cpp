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
#include <dimbo/s11n/clinfo/platform_layer_info.hpp>
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

enum IO_Format {
  iof_uff,          // User-friendly format (only for output)
  iof_txt,          // boost::archive::text_(io)archive,
  iof_xml,          // boost::archive::xml_(io)archive,
  iof_bin,          // boost::archive::binary_(io)archive
  iof_unknown = -1  // Unknown format
};

using Dimbo::App::Options::Options_Map;
using Dimbo::Clinfo::Platform_Layer_Info;

static bool
process_help_options( Options_Map const& om, Options_Description const& od )
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

static IO_Format
determine_io_format(std::string const& opt)
{
  if(opt == "uff")
    return iof_uff;
  else if(opt == "txt")
    return iof_txt;
  else if(opt == "xml")
    return iof_xml;
  else if(opt == "bin")
    return iof_bin;
  else
    return iof_unknown;
}

template<class Archive>
static void
load_from_archive(std::istream& ifs, Platform_Layer_Info& obj)
{
  Archive ar(ifs);
  ar >> boost::serialization::make_nvp("platform_layer_info", obj);
}

template<class Archive>
static void
save_to_archive(std::ostream& ofs, Platform_Layer_Info const& obj)
{
  Archive ar(ofs);
  ar << boost::serialization::make_nvp("platform_layer_info", obj);
}

static Platform_Layer_Info
read_from_istream(std::istream& ifs, IO_Format fmt)
{
  using namespace boost::archive;
  Platform_Layer_Info pli;
  switch(fmt)
    {
      case iof_txt:
        load_from_archive<text_iarchive>(ifs, pli);
        break;
      case iof_xml:
        load_from_archive<xml_iarchive>(ifs, pli);
        break;
      case iof_bin:
        load_from_archive<binary_iarchive>(ifs, pli);
        break;
      default:
        // FIXME: throw error? unsupported format for output
        break;
    }
  return pli;
}

static void
write_to_ostream( Platform_Layer_Info const& pli
                 , std::ostream& ofs
                 , IO_Format fmt
                 , int indent )
{
  using namespace boost::archive;
  switch(fmt)
    {
      case iof_uff:
        Dimbo::Format::write(ofs, pli, indent);
        break;
      case iof_txt:
        save_to_archive<text_oarchive>(ofs, pli);
        break;
      case iof_xml:
        save_to_archive<xml_oarchive>(ofs, pli);
        break;
      case iof_bin:
        save_to_archive<binary_oarchive>(ofs, pli);
        break;
      default:
        // FIXME: throw error? unsupported format for output
        break;
    }
}

static Shared_Ptr<std::istream>
determine_input(Options_Map const& om)
{
  if(om.count("input"))
    {
      std::string file(om["input"].as<std::string>());

      if(file == "-")
        return Shared_Ptr<std::istream>(&std::cin);
      else
        return Shared_Ptr<std::istream>(new std::ifstream(file));
    }
  else
    return Shared_Ptr<std::istream>();
}

static Shared_Ptr<std::ostream>
determine_output(Options_Map const& om)
{
  struct noop { void operator()(...) const{}; };
  IO_Format fmt;

  Shared_Ptr<std::ostream> ofs;
  if(om.count("output"))
    {
      std::string file(om["output"].as<std::string>());
      if(file == "-")
        {
          ofs.reset(&std::cout, noop());
          fmt = iof_uff; // default for stdout
        }
      else
        {
          ofs.reset(new std::ofstream(file));
          fmt = iof_xml; // default for file
        }
    }
  else
    {
      ofs.reset(&std::cout, noop());
      fmt = iof_uff; // default for stdout
    }

  if(om.count("output-format"))
    {
      fmt = determine_io_format(om["output-format"].as<std::string>());
      if(fmt == iof_unknown)
        {
          // FIXME: throw an exception?
        }
    }

  return ofs;
}

static IO_Format
determine_output_format(Options_Map const& om)
{
  IO_Format fmt;

  // First, establish default value
  if(om.count("output"))
    {
      std::string file(om["output"].as<std::string>());
      if(file == "-")
        fmt = iof_uff; // default for stdout
      else
        fmt = iof_xml; // default for file
    }
  else
    fmt = iof_uff; // default for stdout

  // then eventually overwrite with user's choice
  if(om.count("output-format"))
    {
      fmt = determine_io_format(om["output-format"].as<std::string>());
      if(fmt == iof_unknown)
        {
          // FIXME: throw an exception?
        }
    }

  return fmt;
}

static Platform_Layer_Info
retrieve_info(Options_Map const& om)
{
  Shared_Ptr<std::istream> ifs(determine_input(om));
  if(ifs)
    {
      IO_Format fmt = iof_xml;
      if(om.count("input-format"))
        {
          fmt = determine_io_format(om["input-format"].as<std::string>());
          if(fmt == iof_unknown)
            {
              // FIXME: throw error? unsupported format ...
            }
        }
      return read_from_istream(*ifs, fmt);
    }
  else
    {
      return Dimbo::Cl::query_platform_layer_info(
          Dimbo::Cl::Platform_Layer(), 
          create_platform_query(om),
          create_device_query(om)
     );
    }
}

static void
output_info(Platform_Layer_Info const& pli, Options_Map const& om)
{
  Shared_Ptr<std::ostream> ofs(determine_output(om));

  int indent = 2;
  if(om.count("indent"))
    indent = om["indent"].as<int>();

  write_to_ostream(pli, *ofs, determine_output_format(om), indent);
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
  Options_Map const& om = this->options_map();
  Options_Description const& od = this->options_description();

  if(process_help_options(om, od))
    return EXIT_SUCCESS;

  output_info(retrieve_info(om), om);

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
