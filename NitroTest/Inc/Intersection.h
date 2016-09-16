#pragma once

#include <list>

#include "Rectangle.h"

class Intersection : public Rectangle
{
public:
   Intersection(int x, int y, int w, int h, std::list<int> nos)
      : Rectangle(x, y, w, h, -1),
      m_nos(std::move(nos))
   {};
   ~Intersection() = default;

   Intersection(const Intersection& cp)
      : Rectangle(cp),
      m_nos(cp.m_nos)
   {};
   Intersection& operator=(const Intersection& cp)
   {
      Rectangle::operator=(cp);
      m_nos = cp.m_nos;
      return *this;
   };

   Intersection(Intersection&& mv)
      : Rectangle(std::move(mv)),
      m_nos(std::move(mv.m_nos))
   {};
   Intersection& operator=(Intersection&& mv)
   {
      Rectangle::operator=(std::move(mv));
      m_nos = std::move(mv.m_nos);
      return *this;
   };

   const std::list<int>& GetNos() const { return m_nos; };

private:
   std::list<int> m_nos;
};
