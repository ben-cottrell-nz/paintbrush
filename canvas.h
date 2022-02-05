#ifndef CANVAS_H
#define CANVAS_H

#include <QObject>
#include <QFrame>
#include <QPixmap>
#include <QImage>
#include <QPoint>

class Canvas : public QFrame {
 Q_OBJECT
 public:
  explicit Canvas(QWidget *parent = nullptr);
  const int BORDER = 16;
  const int BORDER_HANDLE = BORDER * 0.5;
  const int PADDING = 16;
 protected:
  void paintEvent(QPaintEvent*);
  void mousePressEvent(QMouseEvent*);
  void mouseReleaseEvent(QMouseEvent*);
  void mouseMoveEvent(QMouseEvent*);
 signals:
  void canvasSizeChanged(int&,int&);
 private:
  int m_width, m_height;
  QPoint m_cornerHandlePos[4];
  QPoint m_cornerLastHandlePos[4];
  bool m_cornerMouseDown[4] = {false,false,false,false};
  double m_zoom;
  QImage m_bitmap;

};

#endif // CANVAS_H
