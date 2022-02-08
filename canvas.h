#ifndef CANVAS_H
#define CANVAS_H

#include <QObject>
#include <QFrame>
#include <QPixmap>
#include <QImage>
#include <QPoint>
#include <QQueue>
#include "toolbar.h"

class Canvas : public QFrame
{
 Q_OBJECT
 public:
	using ToolMode = Toolbar::ToolMode;
	explicit Canvas(QWidget* parent = nullptr);
	const int BORDER = 16;
	const int BORDER_HANDLE = BORDER * 0.5;
	const int PADDING = 16;
	ToolMode toolMode();
	void setToolMode(ToolMode);
	void setFGColor(QColor);
 protected:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
 signals:
	void canvasSizeChanged(int&, int&);
 private:
	void resize(int,int);
	ToolMode m_toolMode;
	QCursor m_curPencil, m_curFill, m_curPaintbrush;
	int m_width, m_height;
	QColor m_fgColor;
	QColor m_bgColor;
	QPoint m_cornerHandlePos[4];
	QPoint m_cornerLastHandlePos[4];
	QPoint m_drawingPos;
	bool m_mouseDrawing = false;
	QPoint m_lastMousePos = {0,0};
	bool m_cornerMouseDown[4] = { false, false, false, false };
	QPainter* m_bmpPaint;
	bool m_mouseDown;
	int m_radius;
	double m_zoom;
	QImage m_bitmap;

};

#endif // CANVAS_H
