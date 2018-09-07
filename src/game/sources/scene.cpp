// scene.cpp

#include "scene.hpp"
#include "asteroid.hpp"
#include "asteroids.hpp"
#include "bullet.hpp"
#include "shiep.hpp"
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <cmath>
#include <random>

#include <QDebug>

asteroids::scene::scene(::QObject *parent)
    : ::QGraphicsScene{parent}, shiep_{new asteroids::shiep},
      timer_{new ::QTimer} {
  connect(timer_, &::QTimer::timeout, this, &scene::denger_generator);

  this->setSceneRect(SCENE_RECT);

  this->addItem(shiep_);

  this->denger_generator();

  ::qDebug() << "scene_created";
}

void asteroids::scene::mouseMoveEvent(::QGraphicsSceneMouseEvent *event) {
  shiep_->set_angle_to(event->scenePos());
}

void asteroids::scene::mousePressEvent(::QGraphicsSceneMouseEvent *event) {
  auto bullet = new asteroids::bullet{shiep_->bow(), shiep_->angle()};
  this->addItem(bullet);
}

void asteroids::scene::denger_generator() {
  static std::random_device rd;
  static std::default_random_engine re{rd()};
  std::uniform_int_distribution<int> dist{
      DENGER_TIME_RANGE.first, DENGER_TIME_RANGE.second};

  auto asteroid = new asteroids::asteroid;
  this->addItem(asteroid);

  timer_->start(dist(re));
}
