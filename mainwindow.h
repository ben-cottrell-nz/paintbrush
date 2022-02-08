//
// Created by ben on 2/02/22.
//

#ifndef PAINTBRUSH__MAINWINDOW_H_
#define PAINTBRUSH__MAINWINDOW_H_

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QDockWidget>
#include <QScrollArea>
#include "toolbar.h"
#include "canvas.h"
#include "colorpalette.h"

class MainWindow : public QMainWindow
{
 public:
	MainWindow();
	~MainWindow();
 protected:
	void resizeEvent(QResizeEvent*);
 private:
	friend class Canvas;
	QScrollArea* m_scrollArea;
	QDockWidget m_dock;
	QDockWidget m_dockBottom;
	QWidget m_centralWidget;
	ColorPalette m_palette;
	Toolbar m_toolbar;
	Canvas m_canvas;
};

#endif //PAINTBRUSH__MAINWINDOW_H_
