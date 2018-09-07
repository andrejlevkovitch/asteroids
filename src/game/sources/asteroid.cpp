// asteroid.cpp

#include "asteroid.hpp"
#include "asteroids.hpp"
#include "explosition.hpp"
#include "shiep.hpp"
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <random>

#include <QDebug>

const ::QPointF &asteroids::asteroid::SPEED() {
  static const ::QPointF retval{3, 0};
  return retval;
}

std::chrono::milliseconds asteroids::asteroid::MOMENT() {
  std::chrono::milliseconds retval{50};
  return retval;
}

asteroids::asteroid::asteroid(::QGraphicsItem *parent)
    : ::QGraphicsPixmapItem{parent}, health_{}, angle_{}, timer_{new ::QTimer} {
  static std::random_device rd;
  static std::default_random_engine de{rd()};

  std::uniform_int_distribution<int> dist{0, Type::SIZE - 1};
  ::QPixmap asteroid_image{};
  switch (dist(de)) {
  case MINI:
    asteroid_image = {":/image/stone3.png"};
    health_ = 1;
    type_ = MINI;
    break;
  case MIDI:
    asteroid_image = {":/image/stone2.png"};
    health_ = 5;
    type_ = MIDI;
    break;
  case BIG:
    asteroid_image = {":/image/stone1.png"};
    health_ = 10;
    type_ = BIG;
    break;
  default:
    break;
  };
  this->setPixmap(asteroid_image);

  auto asteroid_size = asteroid_image.size();
  ::QPointF offset{-asteroid_size.width() / 2., -asteroid_size.height() / 2.};
  this->setOffset(offset);

  std::uniform_int_distribution<int> dist_angle{0, 359};
  angle_ = dist_angle(de);
  this->setRotation(angle_);

  ::QPointF begin_pos{};
  std::uniform_int_distribution<int> dist_hw{0, 1};
  if (dist_hw(de)) {
    std::uniform_int_distribution<int> dist_height(-SCENE_SIZE.height() / 2,
                                                   SCENE_SIZE.height() / 2 - 1);
    if (dist_hw(de)) {
      begin_pos += ::QPointF(SCENE_SIZE.width() / 2, dist_height(de));
    } else {
      begin_pos += ::QPointF(-SCENE_SIZE.width() / 2, dist_height(de));
    }
  } else {
    std::uniform_int_distribution<int> dist_with(-SCENE_SIZE.width() / 2,
                                                 SCENE_SIZE.width() / 2 - 1);
    if (dist_hw(de)) {
      begin_pos += ::QPointF(dist_with(de), SCENE_SIZE.height() / 2);
    } else {
      begin_pos += ::QPointF(dist_with(de), -SCENE_SIZE.height() / 2);
    }
  }
  this->setPos(begin_pos);

  connect(timer_, &::QTimer::timeout, this, &asteroid::flying);
  this->flying();
}

int asteroids::asteroid::type() const { return OBJECT_TYPE::ASTEROID; }

void asteroids::asteroid::hit() {
  --health_;
  if (!health_) {
    this->deleteLater();
    auto blow = new asteroids::explosition{this->scenePos(),
                                           this->boundingRect().width()};
    this->scene()->addItem(blow);
  }
}

void asteroids::asteroid::flying() {
  ::QPointF current_pos{OBJECT_CENTER + SPEED()};
  current_pos = this->mapToScene(current_pos);

  if (!SCENE_RECT.contains(current_pos)) {
    this->deleteLater();
  }
  this->setPos(current_pos);

  auto item_list = this->collidingItems();
  if (!item_list.isEmpty()) {
    for (auto &i : item_list) {
      if (i->type() == OBJECT_TYPE::ASTEROID) {
        this->hit();
///     if (health_) {
///       auto another_body = dynamic_cast<asteroids::asteroid *>(i);
///       if (another_body) {
///         switch (another_body->type_) {
///         case MIDI:
///           if (this->type_ == MIDI) {
///             this->angle_ -= another_body->angle_;
///             another_body->angle_ -= this->angle_;
///           } else if (this->type_ == BIG) {
///             another_body->angle_ -= this->angle_;
///           }
///           break;
///         case BIG:
///           if (this->type_ == MIDI) {
///             this->angle_ -= another_body->angle_;
///           } else if (this->type_ == BIG) {
///             this->angle_ -= another_body->angle_;
///             another_body->angle_ -= this->angle_;
///           }
///           break;
///         default:
///           break;
///         }
///         this->setRotation(angle_);
///         another_body->setRotation(another_body->angle_);
///       }
///     }
      }
      if (i->type() == OBJECT_TYPE::SHIEP) {
        this->hit();
        auto shiep = dynamic_cast<asteroids::shiep *>(i);
        if (shiep) {
          shiep->hit();
        }
      }
    }
  }

  timer_->start(MOMENT());
}
