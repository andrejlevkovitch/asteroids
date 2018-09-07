// general_window.cpp

#include "general_window.hpp"
#include "scene.hpp"
#include <QBoxLayout>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>

#include <QDebug>

asteroids::general_window::general_window(::QWidget *parent) : ::QWidget{parent}, scene_{nullptr} {
  scene_ = new asteroids::scene{this};
  auto view = new ::QGraphicsView;
  view->setScene(scene_);
  view->setMouseTracking(true);
  view->setRenderHint(::QPainter::Antialiasing, true);

  auto general_layout = new ::QVBoxLayout;
  {
    auto menu_bar = new ::QMenuBar;
    auto tool_bar = new ::QToolBar;
    auto status_bar = new ::QStatusBar;

    general_layout->addWidget(menu_bar);
    general_layout->addWidget(tool_bar);
    general_layout->addWidget(view);
    general_layout->addWidget(status_bar);
  }
  this->setLayout(general_layout);

  ::qDebug() << "g_win created";
}
