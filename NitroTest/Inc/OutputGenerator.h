#pragma once

#include <sstream>

#include "Rectangle.h"
#include "Intersection.h"

class OutputGenerator
{
public:
   OutputGenerator(const std::string fileName) : m_fileName(fileName) {};
   ~OutputGenerator() = default;

   OutputGenerator(const OutputGenerator& cp) = delete;
   OutputGenerator& operator=(const OutputGenerator& cp) = delete;

   OutputGenerator(OutputGenerator&& mv) = delete;
   OutputGenerator& operator=(OutputGenerator&& mv) = delete;

   void Generate(const std::list<Rectangle>& rectangles, const std::list<Intersection>& intersections) const;

private:
   void FormatLines(const std::list<Rectangle>& rectangles, const std::list<Intersection>& intersections, std::ostringstream& os) const;
   std::string FormatRectangleLine(const Rectangle& rectangle) const;
   std::string FormatIntersectionLine(const Intersection& intersection) const;

   std::string m_fileName;
};
