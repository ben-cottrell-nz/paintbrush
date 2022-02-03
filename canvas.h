#ifndef CANVAS_H
#define CANVAS_H

#include <QObject>
#include <QWidget>

class Canvas : public QWidget {
 Q_OBJECT
 public:
  explicit Canvas(QWidget *parent = nullptr);
 protected:
  void paintEvent(QPaintEvent*);
 signals:
 private:
  int m_width, m_height;
  double m_zoom;

};

#endif // CANVAS_H
