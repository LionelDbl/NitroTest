#pragma once

#include <string>

class CommandLine
{
public:
   CommandLine() = default;
   ~CommandLine() = default;

   CommandLine(const CommandLine& cp) = delete;
   CommandLine& operator=(const CommandLine& cp) = delete;

   CommandLine(CommandLine&& mv) = delete;
   CommandLine& operator=(CommandLine&& mv) = delete;

   void Parse(int argc, char* argv[]);
   std::string GetFileName() const {
      return m_fileName;
   };
   std::string GetExecName() const {
      return m_execName;
   };
   std::string GetCurrentPath() const {
      return m_currentPath;
   };

private:
   std::string m_fileName;
   std::string m_execName;
   std::string m_currentPath;
};
