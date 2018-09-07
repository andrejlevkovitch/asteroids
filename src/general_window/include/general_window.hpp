// general_window.hpp

#pragma once

#include <QWidget>

namespace asteroids {
class scene;

class general_window : public ::QWidget {
  Q_OBJECT
private:
  scene *scene_;
public:
  general_window(::QWidget *parent = nullptr);
};
}; // namespace asteroids
