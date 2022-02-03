#include <QPainter>
#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}, m_zoom(1)
{

}
void Canvas::paintEvent(QPaintEvent *e) {
  QPainter p(this);
  p.fillRect(10,10, m_width, m_height,QColor(255,255,255));
  QWidget::paintEvent(e);
}
