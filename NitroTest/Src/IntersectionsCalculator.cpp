#include <algorithm>

#include "IntersectionsCalculator.h"

void IntersectionsCalculator::FindIntersections(const std::list<Rectangle>& rectangles, std::list<Intersection>& intersections) const
{
   std::list<Intersection> intscBtwnRect;
   for (std::list<Rectangle>::const_iterator r_cur = rectangles.begin(); r_cur != rectangles.end(); ++r_cur)
   {
      for (std::list<Rectangle>::const_iterator r_next = std::next(r_cur); r_next != rectangles.end(); ++r_next)
      { 
         if (SearchIntersection(r_cur->GetPtL(), r_cur->GetPtR(), r_next->GetPtL(), r_next->GetPtR()))
         {
            int x = 0; int y = 0; int w = 0; int h = 0;
            ComputeIntersection(r_cur->GetPtL(), r_cur->GetPtR(), r_next->GetPtL(), r_next->GetPtR(), x, y, w, h);
            intscBtwnRect.push_back(Intersection(x, y, w, h, std::move(std::list<int>{ r_cur->GetNo(), r_next->GetNo() })));
         }
      }
   }

   std::list<std::list<Intersection>> intermediateLists;
   if (intscBtwnRect.size() > 0)
   {
      intermediateLists.push_back(std::move(intscBtwnRect));
      for (;;)
      {
         std::list<Intersection> intscBtwnIntsc;
         if (FindIntersections(intermediateLists.back(), intscBtwnIntsc))
            intermediateLists.push_back(std::move(intscBtwnIntsc));
         else
            break;
      }
   }

   MergeLists(intermediateLists, intersections);
}

bool IntersectionsCalculator::FindIntersections(const std::list<Intersection>& intersections, std::list<Intersection>& intscBtwnIntsc) const
{
   std::list<std::list<int>> nosStash;

   for (std::list<Intersection>::const_iterator i_cur = intersections.begin(); i_cur != intersections.end(); ++i_cur)
   {
      for (std::list<Intersection>::const_iterator i_next = std::next(i_cur); i_next != intersections.end(); ++i_next)
      {
         if (IsValidIntersection(i_cur->GetNos(), i_next->GetNos(), nosStash))
         {
            if (SearchIntersection(i_cur->GetPtL(), i_cur->GetPtR(), i_next->GetPtL(), i_next->GetPtR()))
            {
               int x = 0; int y = 0; int w = 0; int h = 0;
               ComputeIntersection(i_cur->GetPtL(), i_cur->GetPtR(), i_next->GetPtL(), i_next->GetPtR(), x, y, w, h);
               intscBtwnIntsc.push_back(Intersection(x, y, w, h, nosStash.back()));
            }
         }
      }
   }

   return intscBtwnIntsc.size() > 0;
}

bool IntersectionsCalculator::SearchIntersection(Point l1, Point r1, Point l2, Point r2) const
{
   if ((std::max(l1.x, l2.x) < std::min(r1.x, r2.x)) && ((std::max(l1.y, l2.y) < std::min(r1.y, r2.y))))
      return true;
   else
      return false;
}

void IntersectionsCalculator::ComputeIntersection(Point l1, Point r1, Point l2, Point r2, int& x, int& y, int& w, int& h) const
{
   x = std::max(l1.x, l2.x);
   y = std::max(l1.y, l2.y);
   w = std::min(r1.x, r2.x) - std::max(l1.x, l2.x);
   h = std::min(r1.y, r2.y) - std::max(l1.y, l2.y);
}

bool IntersectionsCalculator::IsValidIntersection(const std::list<int>& nosFirst, const std::list<int>& nosSecond, std::list<std::list<int>>& nosStash) const
{
   std::list<int> newNos;
   newNos.insert(newNos.end(), nosFirst.begin(), nosFirst.end());
   newNos.insert(newNos.end(), nosSecond.begin(), nosSecond.end());
   newNos.sort();
   newNos.unique();

   if (newNos.size() > nosFirst.size() +1)
      return false;

   for (auto& nos : nosStash)
   {
      if (nos == newNos)
         return false;
   }

   nosStash.push_back(std::move(newNos));

   return true;
}

void IntersectionsCalculator::MergeLists(std::list<std::list<Intersection>>& lists, std::list<Intersection>& intersections) const
{
   for (auto& o : lists)
      intersections.insert(intersections.end(), o.begin(), o.end());
}
