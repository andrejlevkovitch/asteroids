// explosition.hpp

#pragma once

#include <QGraphicsPixmapItem>
#include <QTimer>

namespace asteroids {
class explosition : public ::QObject, public ::QGraphicsPixmapItem {
  Q_OBJECT
public:
  static std::chrono::milliseconds MOMENT();
//enum class Type { MINI, MIDI, BIG, SIZE };

private:
  ::QPixmap sprite_;
  QTimer timer_;
  int cur_pos_;
  int size_;

public:
  explosition(const ::QPointF &pos, qreal size,
              ::QGraphicsItem *parent = nullptr);

protected slots:
  void blow();
};
}; // namespace asteroids
