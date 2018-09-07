// functions.cpp

#include "functions.hpp"

float angle(const ::QPointF &pos1, const ::QPointF &pos2) {
  float a = pos2.y() - pos1.y();
  float b = pos2.x() - pos1.x();

  if (!b) {
    return (a > 0) ? 90 : 270;
  }

  auto angle = std::atan(a / b) * 180.f / 3.14f;

  return (b > 0) ? angle : 180.f + angle;
}
