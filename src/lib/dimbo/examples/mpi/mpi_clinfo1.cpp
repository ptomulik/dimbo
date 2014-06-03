/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */

/** // {{{
 * \file dimbo/examples/mpi/mpi_clinfo1.cpp
 * \todo Write file documentation
 */ // }}}
/** // {{{
 * \example mpi_clinfo1.cpp
 * \todo Write documentation
 */ // }}}
// [Program]
// [Includes]
#include <dimbo/cl/platform_layer.hpp>
#include <dimbo/clinfo/platform_layer_info.hpp>
#include <dimbo/protobuf/clinfo/platform_layer_info.hpp>
#include <dimbo/format/clinfo/platform_layer_info.hpp>
#include <boost/shared_array.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <iostream>
#include <string>
#include <mpi.h>
// [Includes]

void print_exception(Dimbo::Exception const&e)
{
  using namespace std;
  cerr << "Exception caught: " << endl;
  cerr << "  at: " << e.debug_info().file() <<":"<< e.debug_info().line() << endl;
  cerr << "  in: " << e.debug_info().function() << endl;
  cerr << " msg: " << e.std_except().what() << endl;
}

void print_exception(std::exception const&e)
{
  using namespace std;
  cerr << "Exception caught: " << e.what() << endl;
}

int main(int argc, char* argv[])
{
  int world_size; // size of the "world" communicator
  int world_rank; // rank (id) of this process within a rank
  int array_size;
  Dimbo::Clinfo::Platform_Layer_Info info;
  Dimbo::Protobuf::Clinfo::Platform_Layer_Info protobuf;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  if(world_rank == 0)
    {
      // Process 0 collects information from all others
      for(int i=1; i<world_size; ++i)
        {
          char* array = new char[1024];
          MPI_Recv(array, 1024, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          protobuf.ParseFromArray(array,1024);
          delete [] array;
          protobuf >> info;
          std::cout << "***** OBTAINED FROM PROCESS " << i << " *****" << std::endl;
          Dimbo::Format::write(std::cout, info, 2);
        }
    }
  else
    {
      // Other processes report their OpenCL platform info to process 0.
      // Retrieve info about local OpenCL devices
      info = Dimbo::Cl::query_platform_layer_info();
      // Put it into a protobuf buffer
      protobuf << info; 
      array_size = protobuf.ByteSize();
      char *array = new char[array_size];
      // serialize buffer to a plain array
      protobuf.SerializeToArray(array,array_size);
      // Send the array to process 0
      MPI_Send(array, array_size, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
      delete [] array;
    }

  MPI_Finalize();
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
