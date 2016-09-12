#pragma

#include <list>

#include "Rectangle.h"
#include "Intersection.h"

class IntersectionsCalculator
{
public:
   IntersectionsCalculator() = default;
   ~IntersectionsCalculator() = default;

   IntersectionsCalculator(const IntersectionsCalculator& cp) = delete;
   IntersectionsCalculator& operator=(const IntersectionsCalculator& cp) = delete;

   IntersectionsCalculator(IntersectionsCalculator&& mv) = delete;
   IntersectionsCalculator& operator=(IntersectionsCalculator&& mv) = delete;

   void FindIntersections(const std::list<Rectangle>& rectangles, std::list<Intersection>& intersections) const;

private:
   bool FindIntersections(const std::list<Intersection>& intersections, std::list<Intersection>& newIntersections) const;
   bool SearchIntersection(Point l1, Point r1, Point l2, Point r2) const;
   void ComputeIntersection(Point l1, Point r1, Point l2, Point r2, int& x, int& y, int& w, int& h) const;
   bool IsValidIntersection(const std::list<int>& curNos, const std::list<int>& nextNos, std::list<std::list<int>>& nosStash) const;
   void MergeLists(std::list<std::list<Intersection>>& lists, std::list<Intersection>& intersections) const;
};
