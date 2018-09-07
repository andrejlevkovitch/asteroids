// main.cpp

#include <QApplication>
#include "general_window.hpp"

int main(int argc, char *argv[]) {
  ::QApplication app(argc, argv);
  
  asteroids::general_window g_win;
  g_win.show();

  return app.exec();
}
