#include "Rectangle.h"

#include "ExceptionEx.h"

Rectangle::Rectangle(int x, int y, int w, int h, int no)
   : m_x(x), m_y(y), m_w(w), m_h(h), m_no(no)
{
   if (m_h == 0 || m_no == 0)
      throw dim_notvalid();
}
