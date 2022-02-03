//
// Created by ben on 2/02/22.
//

#ifndef PAINTBRUSH__MAINWINDOW_H_
#define PAINTBRUSH__MAINWINDOW_H_

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QDockWidget>
#include "toolbar.h"
#include "canvas.h"

class MainWindow : public QMainWindow {
 public:
  MainWindow();
  ~MainWindow();
 private:
  QDockWidget m_dock;
  QWidget m_centralWidget;
  Toolbar m_toolbar;
  Canvas m_canvas;
};

#endif //PAINTBRUSH__MAINWINDOW_H_
