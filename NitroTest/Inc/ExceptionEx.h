#pragma once

#include <exception>
#include <string>

class bad_arg : public std::exception
{
public:
   bad_arg() : std::exception() {};
   ~bad_arg() = default;
};

class file_notfound : public std::exception
{
public:
   file_notfound(const std::string& fileName) : std::exception(), m_fileName(fileName) {};
   ~file_notfound() = default;

   std::string GetFileName() const { return m_fileName; };

private:
   std::string m_fileName;
};

class file_notvalid : public std::exception
{
public:
   file_notvalid() : std::exception() {};
   ~file_notvalid() = default;
};

class dim_notvalid : public std::exception
{
public:
   dim_notvalid() : std::exception() {};
   ~dim_notvalid() = default;
};
