//  copyright_check implementation  ------------------------------------------------//

//  Copyright Beman Dawes 2002.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "copyright_check.hpp"

namespace
{
  const char* copyright[] = {
    "(C)", "(c)",
    "Copyright",
    "copyright",
    NULL
  };
} // unnamed namespace

namespace boost
{
  namespace inspect
  {
   copyright_check::copyright_check() : m_files_with_errors(0)
   {
   }

   void copyright_check::inspect(
      const string & library_name,
      const path & full_path,   // example: c:/foo/boost/filesystem/path.hpp
      const string & contents )     // contents of file to be inspected
    {
      if (contents.find( "boostinspect:" "nocopyright" ) != string::npos) return;

      for (const char** ptr = copyright; *ptr; ++ptr)
      {
        if (contents.find( *ptr ) != string::npos) return;
      }

      ++m_files_with_errors;
      error( library_name, full_path, name() );
    }
  } // namespace inspect
} // namespace boost


