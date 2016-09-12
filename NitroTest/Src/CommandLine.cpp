#include "CommandLine.h"

#include "ExceptionEx.h"

void CommandLine::Parse(int argc, char* argv[])
{
   if (argc == 2)
   {
      std::string argv0 = argv[0];
      std::size_t fnd0 = argv0.find_last_of("/\\");
      if (fnd0 != std::string::npos)
      {
         m_currentPath = argv0.substr(0, fnd0 + 1);
         m_fileName = argv0.substr(fnd0 + 1);
      }
      std::string argv1 = argv[1];
      std::size_t fnd1 = argv1.find_last_of("/\\");
      if (fnd1 != std::string::npos)
         m_fileName = argv1;
      else
         m_fileName = m_currentPath + argv1;
   }
   else
      throw bad_arg();
};
