#include <regex>

#include "FileLoader.h"

#include "ExceptionEx.h"
#include "Utils.h"

void FileLoader::ExtractRectangles(const std::string& fileName, std::list<Rectangle>& rectangles) const
{
   std::vector<std::string> lines;
   GetLinesFromFile(fileName, lines);

   ExtractRectangles(lines, rectangles);
}

void FileLoader::GetLinesFromFile(const std::string& fileName, std::vector<std::string>& lines) const
{
   OpenFile file(fileName);
   file.GetLines(lines);
}

void FileLoader::ExtractRectangles(std::vector<std::string>& lines, std::list<Rectangle>& rectangles) const
{
   CheckCurlyBracketsRules(lines);
   CheckSquareBracketsRules(lines);
   CheckDataRules(lines, rectangles);
}

void FileLoader::CheckCurlyBracketsRules(std::vector<std::string>& lines) const
{
   if (lines.front() != "{" || lines.back() != "}")
      throw file_notvalid();
   if (!lines.empty())
      lines.erase(lines.begin());
   if (!lines.empty())
      lines.erase(lines.end() - 1);
}

void FileLoader::CheckSquareBracketsRules(std::vector<std::string>& lines) const
{
   if (lines.front() != "\t\"rects\": [" || lines.back() != "\t]")
      throw file_notvalid();
   if (!lines.empty())
      lines.erase(lines.begin());
   if (!lines.empty())
      lines.erase(lines.end() - 1);
}

void FileLoader::CheckDataRules(std::vector<std::string>& lines, std::list<Rectangle>& rectangles) const
{
   int idx = 1;
   for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); ++it)
   {
      std::regex rgx;
      if (std::next(it) != lines.end())
         rgx = R"(^\t\t\{"x": (\d+), "y": (\d+), "w": (\d+), "h": (\d+) \},)";
      else
         rgx = R"(^\t\t\{"x": (\d+), "y": (\d+), "w": (\d+), "h": (\d+) \})";

      std::smatch match;
      if (!std::regex_match(*it, match, rgx))
         throw file_notvalid();

      if (match.size() == 5)
      {
         int x = std::stoi(match[1]);
         int y = std::stoi(match[2]);
         int w = std::stoi(match[3]);
         int h = std::stoi(match[4]);
         rectangles.push_back(std::move(Rectangle(x, y, w, h, idx)));
      }
      else
         throw file_notvalid();

      if (idx > 1000)
         break;

      ++idx;
   }
}
