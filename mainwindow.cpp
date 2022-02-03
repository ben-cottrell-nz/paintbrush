//
// Created by ben on 2/02/22.
//

#include "mainwindow.h"
#include <QStatusBar>
#include <QLabel>
#include <QMenuBar>
MainWindow::MainWindow() : m_toolbar(), m_dock(), m_canvas(this){
  resize(1024,768);
  setCentralWidget(&m_canvas);
  addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, &m_dock);
  m_dock.setWidget(&m_toolbar);
//  QLabel* dockTitleLabel = new QLabel(this);
//  dockTitleLabel->setText("Tools");
//  m_dock.setTitleBarWidget(dockTitleLabel);
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
MainWindow::~MainWindow() {

}
