#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class OpenFile {
public:
   OpenFile(std::string fileName);
   ~OpenFile();

   OpenFile(const OpenFile& cp) = delete;
   OpenFile& operator=(const OpenFile& cp) = delete;

   OpenFile(OpenFile&& mv) = delete;
   OpenFile& operator=(OpenFile&& mv) = delete;

   void GetLines(std::vector<std::string>& lines);

private:
   std::ifstream m_file;
};

class WriteFile {
public:
   WriteFile(std::string fileName);
   ~WriteFile();

   WriteFile(const WriteFile& cp) = delete;
   WriteFile& operator=(const WriteFile& cp) = delete;

   WriteFile(OpenFile&& mv) = delete;
   WriteFile& operator=(OpenFile&& mv) = delete;

   void Write(const std::ostringstream& os);

private:
   std::ofstream m_file;
};
