// shiep.cpp

#include "shiep.hpp"
#include "functions.hpp"
#include <QPainter>
#include "asteroids.hpp"
#include "explosition.hpp"
#include <QGraphicsScene>

asteroids::shiep::shiep(::QGraphicsItem *parent)
    : ::QGraphicsPixmapItem{parent}, health_{20} {
  auto shiep_image = ::QPixmap{":/image/space_shiep.png"};
  this->setPixmap(shiep_image);

  auto image_size = shiep_image.size();
  ::QPointF offset{-image_size.width() / 2., -image_size.height() / 2.};
  this->setOffset(offset);

  bow_ = ::QPointF{-offset.x(), 0};
}

int asteroids::shiep::type() const { return OBJECT_TYPE::SHIEP; }

::QPointF asteroids::shiep::bow() const {
  return this->mapToScene(bow_);
}

float asteroids::shiep::angle() const { return angle_; }

void asteroids::shiep::set_angle_to(const ::QPointF &pos) {
  angle_ = ::angle(OBJECT_CENTER, pos);
  this->setRotation(angle_);
}

void asteroids::shiep::hit() {
  --health_;
  if (!health_) {
    health_ = 20;
//  this->deleteLater();
    auto blow = new asteroids::explosition{this->scenePos(),
                                           this->boundingRect().width()};
    this->scene()->addItem(blow);
  }
}
