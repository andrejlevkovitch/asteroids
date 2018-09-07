// shiep.hpp

#pragma once

#include <QGraphicsPixmapItem>

namespace asteroids {
class shiep : public ::QObject, public ::QGraphicsPixmapItem {
private:
  float angle_;
  ::QPointF bow_;
  int health_;

public:
  shiep(::QGraphicsItem *parent = nullptr);
  int type() const override;

  ::QPointF bow() const;
  void set_angle_to(const ::QPointF &pos);
  float angle() const;
  void hit();
};
}; // namespace asteroids
