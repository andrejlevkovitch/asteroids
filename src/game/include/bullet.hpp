// bullet.hpp

#pragma once

#include <QGraphicsPixmapItem>

namespace asteroids {
class bullet : public ::QObject, public ::QGraphicsPixmapItem {
public:
  Q_OBJECT
  static const ::QPointF &SPEED();
  static std::chrono::milliseconds MOMENT();

private:
  ::QTimer *timer_;
  float angle_;

public:
  bullet(const ::QPointF &pos, float angle, ::QGraphicsItem *parent = nullptr);
  int type() const override;

protected slots:
  void flying();
};
}; // namespace asteroids
