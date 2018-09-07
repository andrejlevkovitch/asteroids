// explosition.cpp

#include "explosition.hpp"

#include <QDebug>

std::chrono::milliseconds asteroids::explosition::MOMENT() {
  static const std::chrono::milliseconds retval{100};
  return retval;
}

asteroids::explosition::explosition(const ::QPointF &pos, qreal size,
                                    ::QGraphicsItem *parent)
    : ::QGraphicsPixmapItem{parent}, sprite_{":/image/blow.png"}, cur_pos_{},
      size_(size) {
  connect(&timer_, &::QTimer::timeout, this, &explosition::blow);

  this->setPos(pos);
  this->setOffset(-size_ / 2, -size_ / 2);
  this->blow();
}

void asteroids::explosition::blow() {
  if (cur_pos_ >= sprite_.width()) {
    this->deleteLater();
    return;
  }
  this->setPixmap(sprite_.copy(cur_pos_, 0, sprite_.height(), sprite_.height())
                      .scaled(size_, size_, Qt::KeepAspectRatio));
  cur_pos_ += sprite_.height();
  timer_.start(MOMENT());
}
