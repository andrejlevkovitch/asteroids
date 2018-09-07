// asteroids.hpp

#pragma once

#include <QGraphicsItem>
#include <QRectF>

const ::QSizeF SCENE_SIZE{1600, 900};
const ::QRectF SCENE_RECT{-SCENE_SIZE.width() / 2., -SCENE_SIZE.height() / 2.,
                          SCENE_SIZE.width(), SCENE_SIZE.height()};
const ::QPointF SCENE_CENTR{0, 0};

const ::QPointF OBJECT_CENTER{0, 0};

enum OBJECT_TYPE {
  DEFAULT = ::QGraphicsItem::UserType,
  SHIEP,
  BULLET,
  ASTEROID,
  EXPLOSITION,
  SIZE
};

const std::pair<int, int> DENGER_TIME_RANGE{50, 500};
