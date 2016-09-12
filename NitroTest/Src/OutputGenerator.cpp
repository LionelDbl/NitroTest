#include <regex>

#include "OutputGenerator.h"

#include "Utils.h"

const std::string InputLine = "Input:";
const std::string rectangleFmt = "\t%5: Rectangle at (%1,%2), w=%3, h=%4.";
const std::string intersectionLine = "Intersections";
const std::string intersectionFmt = "\tBetween rectangle %6 at (%1, %2), w = %3, h = %4.";

void OutputGenerator::Generate(const std::list<Rectangle>& rectangles, const std::list<Intersection>& intersections) const
{
   std::ostringstream os;
   FormatLines(rectangles, intersections, os);

   WriteFile file(m_fileName);
   file.Write(os);
}

void OutputGenerator::FormatLines(const std::list<Rectangle>& rectangles, const std::list<Intersection>& intersections, std::ostringstream& os) const
{
   os << InputLine << std::endl;
   for (const auto& o : rectangles)
      os << FormatRectangleLine(o) << std::endl;
   os << std::endl;
   os << intersectionLine << std::endl;
   for (std::list<Intersection>::const_iterator it = intersections.begin(); it != intersections.end(); ++it)
   {
      os << FormatIntersectionLine(*it);
      if (std::next(it) != intersections.end())
          os << std::endl;
   }
}

std::string OutputGenerator::FormatRectangleLine(const Rectangle& rectangle) const
{
   std::string str(rectangleFmt);
   str = std::regex_replace(str, std::regex("\\%1"), std::to_string(rectangle.GetPtL().x));
   str = std::regex_replace(str, std::regex("\\%2"), std::to_string(rectangle.GetPtL().y));
   str = std::regex_replace(str, std::regex("\\%3"), std::to_string(rectangle.GetWidth()));
   str = std::regex_replace(str, std::regex("\\%4"), std::to_string(rectangle.GetHeight()));
   str = std::regex_replace(str, std::regex("\\%5"), std::to_string(rectangle.GetNo()));
   return str;
}

std::string OutputGenerator::FormatIntersectionLine(const Intersection& intersection) const
{
   std::string str(intersectionFmt);
   str = std::regex_replace(str, std::regex("\\%1"), std::to_string(intersection.GetPtL().x));
   str = std::regex_replace(str, std::regex("\\%2"), std::to_string(intersection.GetPtL().y));
   str = std::regex_replace(str, std::regex("\\%3"), std::to_string(intersection.GetWidth()));
   str = std::regex_replace(str, std::regex("\\%4"), std::to_string(intersection.GetHeight()));
   std::ostringstream nosStr;
   for (std::list<int>::const_iterator it = intersection.GetNos().begin(); it != intersection.GetNos().end(); ++it)
   {
      if (it == intersection.GetNos().begin())
         nosStr << *it;
      else
      {
         if (std::next(it) != intersection.GetNos().end())
            nosStr << ", ";
         else
            nosStr << " and ";
         nosStr << *it;
      }
   }
   str = std::regex_replace(str, std::regex("\\%6"), nosStr.str());
   return str;
}
