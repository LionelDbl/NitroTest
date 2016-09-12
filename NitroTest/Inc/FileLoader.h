#pragma once

#include <string>
#include <list>
#include <vector>

#include "Rectangle.h"

class FileLoader
{
public:
   FileLoader() = default;
   ~FileLoader() = default;

   FileLoader(const FileLoader& cp) = delete;
   FileLoader& operator=(const FileLoader& cp) = delete;

   FileLoader(FileLoader&& mv) = delete;
   FileLoader& operator=(FileLoader&& mv) = delete;

   void ExtractRectangles(const std::string& fileName, std::list<Rectangle>& rectangles) const;

private:
   void GetLinesFromFile(const std::string& fileName, std::vector<std::string>& lines) const;
   void ExtractRectangles(std::vector<std::string>& lines, std::list<Rectangle>& rectangles) const;
   void CheckCurlyBracketsRules(std::vector<std::string>& lines) const;
   void CheckSquareBracketsRules(std::vector<std::string>& lines) const;
   void CheckDataRules(std::vector<std::string>& lines, std::list<Rectangle>& rectangles) const;
};
