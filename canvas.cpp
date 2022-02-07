#include <QPainter>
#include "canvas.h"
#include <QMouseEvent>
#include <QGridLayout>

Canvas::Canvas(QWidget* parent) : QFrame{ parent },
								  m_zoom(1),
								  m_width(472),
								  m_height(567),
								  m_bitmap(m_width, m_height, QImage::Format_ARGB32)
{
	m_cornerHandlePos[0] = { BORDER_HANDLE, BORDER_HANDLE };
	m_cornerHandlePos[1] = { m_width + BORDER, BORDER_HANDLE };
	m_cornerHandlePos[2] = { BORDER_HANDLE, m_height + BORDER };
	m_cornerHandlePos[3] = { m_width + BORDER, m_height + BORDER };
	m_curPencil = QCursor(QPixmap(":/cursor/pencil.xpm"), 0, 0);
	m_curFill = QCursor(QPixmap(":/cursor/fill.xpm"), 0, 0);
	m_curPaintbrush = QCursor(QPixmap(":/cursor/paintbrush.xpm"), 0, 0);
	m_drawingColor = QColor(0, 0, 0);
	m_bmpPaint = new QPainter(&m_bitmap);
	m_bmpPaint->fillRect(0, 0, m_width, m_height, QColor(255, 255, 255));
}
void Canvas::paintEvent(QPaintEvent* e)
{
	QPainter p(this);
	//frame rectangle
	p.drawRect(rect());
	//draw the document
	p.drawImage(QRect{ PADDING, PADDING, m_bitmap.width(), m_bitmap.height() }, m_bitmap);
	//draw the handles
	//top
	p.fillRect(m_cornerHandlePos[0].x(),
		m_cornerHandlePos[0].y(),
		BORDER_HANDLE,
		BORDER_HANDLE,
		Qt::GlobalColor::black);;
	p.fillRect(m_cornerHandlePos[1].x(),
		m_cornerHandlePos[1].y(),
		BORDER_HANDLE,
		BORDER_HANDLE,
		Qt::GlobalColor::black);;
	p.fillRect(m_cornerHandlePos[2].x(),
		m_cornerHandlePos[2].y(),
		BORDER_HANDLE,
		BORDER_HANDLE,
		Qt::GlobalColor::black);;
	p.fillRect(m_cornerHandlePos[3].x(),
		m_cornerHandlePos[3].y(),
		BORDER_HANDLE,
		BORDER_HANDLE,
		Qt::GlobalColor::black);;
}
void Canvas::mousePressEvent(QMouseEvent* e)
{
	//test the bottom, right side and right corner, update m_cornerMouseDown
	//x..1
	//2..3
	m_mouseDown = true;
	if ((e->pos().x() > m_cornerHandlePos[1].x() && e->pos().x() < m_cornerHandlePos[1].x() + BORDER_HANDLE)
		&& (e->pos().y() > m_cornerHandlePos[1].y() && e->pos().y() < m_cornerHandlePos[1].y() + BORDER_HANDLE))
	{
		m_cornerMouseDown[1] = true;
		m_cornerLastHandlePos[1] = m_cornerHandlePos[1];
	}
	if ((e->pos().x() > m_cornerHandlePos[2].x() && e->pos().x() < m_cornerHandlePos[2].x() + BORDER_HANDLE)
		&& (e->pos().y() > m_cornerHandlePos[2].y() && e->pos().y() < m_cornerHandlePos[2].y() + BORDER_HANDLE))
	{
		m_cornerMouseDown[2] = true;
		m_cornerLastHandlePos[2] = m_cornerHandlePos[2];
	}
	if ((e->pos().x() > m_cornerHandlePos[3].x() && e->pos().x() < m_cornerHandlePos[3].x() + BORDER_HANDLE)
		&& (e->pos().y() > m_cornerHandlePos[3].y() && e->pos().y() < m_cornerHandlePos[3].y() + BORDER_HANDLE))
	{
		m_cornerMouseDown[3] = true;
		m_cornerLastHandlePos[3] = m_cornerHandlePos[3];
	}
}
void Canvas::mouseReleaseEvent(QMouseEvent*)
{
	m_mouseDown = false;
	m_cornerMouseDown[0] = false;
	m_cornerMouseDown[1] = false;
	m_cornerMouseDown[2] = false;
	m_cornerMouseDown[3] = false;
}
void Canvas::mouseMoveEvent(QMouseEvent* e)
{
	if (m_cornerMouseDown[1])
	{
		m_cornerHandlePos[1].setX(e->pos().x() - m_cornerLastHandlePos[1].x());
	}
	else if (m_cornerMouseDown[2])
	{
		m_cornerHandlePos[2].setY(e->pos().y() - m_cornerLastHandlePos[2].y());
	}
	else if (m_cornerMouseDown[3])
	{
//	m_cornerHandlePos[3].setX(e->pos().x() - m_cornerLastHandlePos[3].x());
		m_cornerHandlePos[3].setX(e->pos().x());
		m_cornerHandlePos[3].setY(e->pos().y());
		m_width = e->pos().x() - PADDING;
		m_height = e->pos().y() - PADDING;
		m_cornerHandlePos[1].setX(m_width + BORDER);
		m_cornerHandlePos[2].setY(m_height + BORDER);
		emit canvasSizeChanged(m_width, m_height);
		resize(m_width, m_height);
	}
	else
	{
		if (m_mouseDown)
		{
			if (m_toolMode == ToolMode::PENCIL)
			{
				m_bmpPaint->drawEllipse(e->pos().operator-=({ 5, 5 }), 5, 5);
//				m_drawPoints.enqueue(e->pos());
////				qDebug() << qAbs(pow(m_lastMousePos.x(),2)-pow(m_lastMousePos.y(),2));
//				if (qAbs(m_lastMousePos.x() - e->pos().x()) < 3 && qAbs(m_lastMousePos.y() - e->pos().y()) < 3)
//				{
//					while (!m_drawPoints.isEmpty())
//					{
//						m_bmpPaint->drawEllipse(m_drawPoints.dequeue().operator-=({ 5, 5 }), 5, 5);
//					}
//				}
			}
			m_lastMousePos = e->pos();
		}
	}
	update();
}
Canvas::ToolMode Canvas::toolMode()
{
	return m_toolMode;
}
void Canvas::setToolMode(ToolMode a)
{
	switch (a)
	{
	case ToolMode::PENCIL:
		setCursor(m_curPencil);
		break;
	case ToolMode::FILL:
		setCursor(m_curFill);
		break;
	case ToolMode::PAINTBRUSH:
		setCursor(m_curPaintbrush);
		break;
	}
	m_toolMode = a;
}
void Canvas::resize(int w, int h)
{
	QImage imageSized(w,h,m_bitmap.format());
	imageSized.fill(QColor(255,255,255));
	QPainter p(&imageSized);
	p.drawImage(m_bitmap.rect(),m_bitmap);
	m_bitmap = imageSized;
}
