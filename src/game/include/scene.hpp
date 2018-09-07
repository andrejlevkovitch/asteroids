// scene.hpp

#pragma once

#include <QGraphicsScene>

class QTimer;

namespace asteroids {
class shiep;

class scene : public ::QGraphicsScene {
  Q_OBJECT
private:
  shiep *shiep_;
  ::QTimer *timer_;

public:
  scene(::QObject *parent = nullptr);
  void mouseMoveEvent(::QGraphicsSceneMouseEvent *event) override;
  void mousePressEvent(::QGraphicsSceneMouseEvent *event) override;

  protected slots:
    void denger_generator();
};
}; // namespace asteroids
