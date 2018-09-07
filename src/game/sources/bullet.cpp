// bullet.cpp

#include "bullet.hpp"
#include "asteroid.hpp"
#include "asteroids.hpp"
#include "explosition.hpp"
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>

#include <QDebug>

const ::QPointF &asteroids::bullet::SPEED() {
  static const ::QPointF retval{4, 0};
  return retval;
}

std::chrono::milliseconds asteroids::bullet::MOMENT() {
  static const std::chrono::milliseconds retval{30};
  return retval;
}

asteroids::bullet::bullet(const ::QPointF &pos, float angle,
                          ::QGraphicsItem *parent)
    : ::QGraphicsPixmapItem{parent}, timer_{new ::QTimer}, angle_{angle} {
  auto bullet_image = ::QPixmap{":/image/bullet.png"};
  this->setPixmap(bullet_image);

  auto bullet_size = bullet_image.size();
  ::QPointF offset{-bullet_size.width() / 2., -bullet_size.height() / 2.};
  this->setOffset(offset);
  this->setRotation(angle_);
  this->setPos(pos);

  connect(timer_, &::QTimer::timeout, this, &bullet::flying);
  timer_->start(MOMENT());
}

int asteroids::bullet::type() const { return OBJECT_TYPE::BULLET; }

void asteroids::bullet::flying() {
  auto cur_pos = this->mapToScene(OBJECT_CENTER + SPEED());
  if (!SCENE_RECT.contains(cur_pos)) {
    this->deleteLater();
    return;
  }
  this->setPos(cur_pos);
  auto item_list = this->collidingItems();
  if (!item_list.isEmpty()) {
    for (auto &i : item_list) {
      if (i->type() == OBJECT_TYPE::ASTEROID) {
        this->deleteLater();
        dynamic_cast<asteroid *>(i)->hit();
        auto blow =
            new explosition{this->scenePos(), this->boundingRect().width()};
        this->scene()->addItem(blow);
        return;
      }
    }
  }
  timer_->start(MOMENT());
}
