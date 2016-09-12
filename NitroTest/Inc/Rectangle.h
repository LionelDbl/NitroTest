#pragma once

#include <utility>

struct Point
{
   int x;
   int y;
};

class Rectangle
{
public:
   Rectangle(int x, int y, int w, int h, int no);
   virtual ~Rectangle() = default;

   Rectangle(const Rectangle& cp)
      : m_x(cp.m_x),
      m_y(cp.m_y),
      m_w(cp.m_w),
      m_h(cp.m_h),
      m_no(cp.m_no)
   {};
   Rectangle& operator=(const Rectangle& cp)
   {
      m_x = cp.m_x;
      m_y = cp.m_y;
      m_w = cp.m_w;
      m_h = cp.m_h;
      m_no = cp.m_no;
      return *this;
   };

   Rectangle(Rectangle&& mv)
      : m_x(std::move(mv.m_x)),
      m_y(std::move(mv.m_y)),
      m_w(std::move(mv.m_w)),
      m_h(std::move(mv.m_h)),
      m_no(std::move(mv.m_no))
   {};
   Rectangle& operator=(Rectangle&& mv)
   {
      m_x = std::move(mv.m_x);
      m_y = std::move(mv.m_y);
      m_w = std::move(mv.m_w);
      m_h = std::move(mv.m_h);
      m_no = std::move(mv.m_no);
      return *this;
   };

   Point GetPtL() const { return Point{ m_x, m_y }; };
   Point GetPtR() const { return Point{ m_x + m_w, m_y + m_h }; };
   int GetWidth() const { return m_w; };
   int GetHeight() const { return m_h; };
   int GetNo() const { return m_no; }

private:
   int m_x;
   int m_y;
   int m_w;
   int m_h;
   int m_no;
};