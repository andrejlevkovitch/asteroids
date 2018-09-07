// asteroid.hpp

#pragma once

#include <QGraphicsPixmapItem>

class QTimer;

namespace asteroids {
class asteroid : public ::QObject, public ::QGraphicsPixmapItem {
  Q_OBJECT
public:
  static const ::QPointF &SPEED();
  static std::chrono::milliseconds MOMENT();
  enum Type{MINI, MIDI, BIG, SIZE};

private:
  int health_;
  float angle_;
  ::QTimer *timer_;
  Type type_;

public:
  asteroid(::QGraphicsItem *parent = nullptr);
  int type() const override;

  void hit();

protected slots:
  void flying();
};
}; // namespace asteroids
