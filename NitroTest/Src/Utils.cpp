#include "Utils.h"

#include "ExceptionEx.h"

OpenFile::OpenFile(std::string fileName)
{
   m_file.open(fileName);
   if (m_file.bad() || m_file.fail())
      throw file_notfound(fileName);
}

OpenFile::~OpenFile()
{
   m_file.close();
}

void OpenFile::GetLines(std::vector<std::string>& lines)
{
   std::string line;
   while (std::getline(m_file, line))
      lines.push_back(std::move(std::string(line)));
}

WriteFile::WriteFile(std::string fileName)
{
   m_file.open(fileName, std::ofstream::out | std::ofstream::trunc);
   if (m_file.bad() || m_file.fail())
      throw file_notfound(fileName);
}

WriteFile::~WriteFile()
{
   m_file.close();
}

void WriteFile::Write(const std::ostringstream& os)
{
   m_file << os.str();
}
