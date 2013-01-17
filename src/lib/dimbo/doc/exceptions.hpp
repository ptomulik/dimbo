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
/** // doc: \group Dimbo_Exception  {{{
 * \defgroup Dimbo_Exception Exceptions in Dimbo
 *
 * This module introduces Dimbo exceptions.
 *
 * \section Dimbo_Exception_user_view User's view
 *
 * %Dimbo uses exceptions to report failures and other errors. A hierarchy of
 * exception classes is developed within %Dimbo to represent most exceptions
 * thrown from its functions. In addition to these, other types of exceptions
 * may be raised by external libraries used by %Dimbo. The exception hierarchy
 * described here are exceptions that have origin in %Dimbo. This hierarchy may
 * be easily extended when new exceptions are needed.
 *
 * From user's view, the exceptions are categorized as follows:
 * - Dimbo::Exception
 *   - Dimbo::Cl::Exception
 *     - Dimbo::Cl::Cl_Error
 *       - Dimbo::Cl::Cl_Error_No<CL_DEVICE_NOT_FOUND>
 *       - Dimbo::Cl::Cl_Error_No<CL_INVALID_DEVICE>
 *       - ...
 *     - Dimbo::Cl::Exception_Uninitialized_Platform
 *     - Dimbo::Cl::Exception_Uninitialized_Device
 *   - ...
 *
 * When handling exception, the user may wish to catch all %Dimbo exceptions
 * (and ignore others):
 * @code
 *   try {
 *     ...
 *   } catch(const Dimbo::Exception& e) {
 *     ...
 *   }
 * @endcode
 * or he may wish to handle only exceptions that fall to predefined `categry'
 * in %Dimbo - for example exceptions raised when invoking OpenCL functions 
 * (error codes returned from OpenCL functions converted to exception classes)
 * @code
 *   try {
 *     ...
 *   } catch (const Dimbo::Cl::Cl_Error& e) {
 *     ...
 *   }
 * @endcode
 * Other groups of exceptions might be handled in similar way. When necessary,
 * the exceptions might be tracked down up to single error code:
 * @code
 *   try {
 *     ...
 *   } catch (const Dimbo::Cl::Cl_Error_No<CL_DEVICE_NOT_FOUND>& e) {
 *     ...
 *   }
 * @endcode
 *
 * Each %Dimbo exception has one of the standard exceptions as its base class,
 * for example std::exception, std::runtime_error or std::logic_error. So, the
 * following code
 * @code
 *   try {
 *    ...
 *   } catch (const std::exception& e) {
 *     // Dimbo exceptions also fall here ...
 *   }
 * @endcode
 * will catch all standard exceptions and %Dimbo exceptions.
 *
 * When handling %Dimbo exception, the standard interface is available via
 * the method Dimbo::Exception::std_except().
 * @code
 * try {
 *  ...
 * } catch (const Dimbo::Exception& e) {
 *   std::cout << e.std_except().what() << std::endl;
 * }
 * @endcode
 *
 * Every exception in %Dimbo has Dimbo::Exception as its top level base class.
 * If we call it the `root' of all %Dimbo exceptions, then new `branches' can
 * be started by defining classes derived from Dimbo::Exception (see section
 * \ref Dimbo_Exception_developer_view).
 *
 *
 * Below we provide several simple examples, about how the %Dimbo exceptions 
 * might be handled.
 *
 * @code
 * // Catch all Dimbo exceptions
 * try {
 *   // Dimbo calls
 * } catch (const Dimbo::Exception& e) {
 *   // Catch all Dimbo exceptions
 *   std::cout << "File:" << e.at().file() << std::endl; 
 *   std::cout << "Line:" << e.at().line() << std::endl; 
 *   std::cout << "Function:" << e.at().function() << std::endl; 
 *   std::cout << e.std_except().what() << std::endl; 
 * }
 * @endcode
 *
 * @code
 * // Catch exceptions from Dimbo::Cl branch only
 * try {
 *   // Dimbo calls
 * } catch (const Dimbo::Cl::Exception& e) {
 *   // Catch only Dimbo CL exceptions
 *   std::cout << "File:" << e.at().file() << std::endl; 
 *   std::cout << "Line:" << e.at().line() << std::endl; 
 *   std::cout << "Function:" << e.at().function() << std::endl; 
 *   std::cout << e.std_except().what() << std::endl; 
 * }
 * @endcode
 *
 * @code
 * try {
 *   try {
 *     // Dimbo calls
 *   } catch (const Dimbo::Exception & e) {
 *     // Print source information and rethrow the exception
 *     std::cout << "File:" << e.at().file() << std::endl; 
 *     std::cout << "Line:" << e.at().line() << std::endl; 
 *     std::cout << "Function:" << e.at().function() << std::endl; 
 *     throw;
 *   }
 * } catch(const std::exception& e) {
 *   // Dimbo exceptions are also derived from standard hierarchy, so
 *   // here we'll catch also the rethrown Dimbo::Exceptions
 *   std::cout << e.what() << std::endl;
 * }
 * @endcode
 *
 * \section Dimbo_Exception_developer_view Developer's view
 *
 * Developers should derive new exceptions from Dimbo::Standardized_Exception.
 * Whenever a new `category' of exceptions have to be implemented, new base
 * class for the category should be defined (the branch base). For example, the
 * \c libdimbo_cl library (an interface to OpenCL) defines its own
 * Dimbo::Cl::Exception, which is the base for all exceptions raised by
 * functions that belong to Dimbo::Cl namespace.  You may see several such
 * branches in other parts of %Dimbo library.
 *
 * For quick start we'll follow a \ref new_exception.cpp example.
 * In this example we include followig headers
 * \snippet new_exception.cpp Includes
 *
 * Assume, we have to create a new category of %Dimbo exceptions under
 * Dimbo::Foo namespace.
 * \snippet new_exception.cpp Namespaces_Start
 * 
 * Now we define within our namespace a new class, which will be used as a
 * beginning of our branch and will fund a base for our new exceptions.
 * \snippet new_exception.cpp Exception
 *
 * \note
 * We have no default constructor in Dimbo::Foo::Exception. This is, because
 * the base class  Dimbo::Exception has private default constructor (it's not
 * default-constructible). The reason is to force developers to initialize each
 * exception at very beginning with the information about the exception 
 * origin (source file name, line number, function name). A special class
 * Dimbo::Src_At keeps this information encapsulated and macro \ref DIMBO_HERE
 * is provided to facilitate exception initialization.
 *
 * We'll use intermediate template class Dimbo::Standardized_Exception 
 * to glue each newly defined exception with selected standard exception.
 * The template has three parameters. First one is the name of a base class,
 * that we want to use (the branch). Second parameter is a placeholder for the
 * name of a standard exception class that will be attached to our exception 
 * (it may be for exampe std::exception, or std::logic_error). Third template
 * parameter defines what type of argument must be provided to the constructor
 * of StdClass. For known standard exceptions, the type is computed by
 * metafunction Dimbo::Detail::std_except_ctor_arg. Currently the standard
 * exceptions fall into two categories: these whose constructor needs
 * std::string as an argument, and these whose constructors must be called
 * without arguments.
 *
 * Let's define two classes, Dimbo::Foo::Exception1 and Dimbo::Foo::Exception2
 * that will represent two concrete exceptions
 * \snippet new_exception.cpp Exception1
 * \snippet new_exception.cpp Exception2
 *
 * That's all. Close namespaces
 * \snippet new_exception.cpp Namespaces_End
 * and we can test our new exceptions with the following program
 * \snippet new_exception.cpp Test
 *
 * The output from above program will be as follows
 * \verbatim
   user@host:$ ./new_exception 
   foo exception: src/lib/dimbo/examples/new_exception/new_exception.cpp:134:Exception1 domain error
   std exception: Exception1 domain error
   foo exception: src/lib/dimbo/examples/new_exception/new_exception.cpp:150:std::bad_alloc
   std exception: std::bad_alloc \endverbatim
 *
 * This complete example should give basic understanding about %Dimbo
 * exceptions. More information about exceptions may be inferred from file and
 * class documentation. Note, that instead of declaring exception classes by
 * hand, an utility macros might be defined for that.
 *
 * \see dimbo/exception.hpp
 * \see dimbo/src_at.hpp
 * \see Dimbo::Exception,
 * \see Dimbo::Standardized_Exception.
 */ // }}}
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
