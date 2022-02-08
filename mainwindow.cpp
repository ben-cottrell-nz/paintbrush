//
// Created by ben on 2/02/22.
//

#include "mainwindow.h"
#include <QStatusBar>
#include <QLabel>
#include <QMenuBar>
#include <QScrollArea>
MainWindow::MainWindow() : m_toolbar(), m_dock(), m_palette(this), m_canvas(this)
{
	resize(1024, 768);
	m_scrollArea = new QScrollArea;
	setCentralWidget(m_scrollArea);
	m_scrollArea->setBackgroundRole(QPalette::Dark);
	m_scrollArea->setWidgetResizable(true);
	m_scrollArea->setWidget(&m_canvas);
	addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, &m_dock);
	addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, &m_dockBottom);
	m_dock.setWidget(&m_toolbar);
	m_dockBottom.setWidget(&m_palette);
	m_canvas.setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	connect(&m_canvas, &Canvas::canvasSizeChanged, this, [&](int& w, int& h)
	{
	  m_canvas.setFixedSize(w + m_canvas.PADDING + m_canvas.BORDER,
		  h + m_canvas.PADDING + m_canvas.BORDER);
	});
	m_canvas.setFixedSize(m_scrollArea->width(), m_scrollArea->height());
	connect(&m_palette, &ColorPalette::colorChanged, &m_canvas, &Canvas::setFGColor);
	connect(&m_toolbar, &Toolbar::toolChanged, &m_canvas,&Canvas::setToolMode);
	m_toolbar.setMaximumWidth(156);
	m_toolbar.setMinimumWidth(156);
	QStatusBar* statusBar = new QStatusBar();
	QMenuBar* menuBar = new QMenuBar(this);
	QMenu* fileMenu = new QMenu(this);
	QMenu* editMenu = new QMenu(this);
	QMenu* helpMenu = new QMenu(this);
	fileMenu->setTitle("File");
	editMenu->setTitle("Edit");
	helpMenu->setTitle("Help");
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(editMenu);
	menuBar->addMenu(helpMenu);
	setStatusBar(new QStatusBar(this));
	setMenuBar(menuBar);
	this->statusBar()->showMessage("Idle");
}
MainWindow::~MainWindow()
{

}
void MainWindow::resizeEvent(QResizeEvent* e)
{
	m_canvas.setFixedSize(m_scrollArea->width(), m_scrollArea->height());
}
