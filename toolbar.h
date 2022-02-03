//
// Created by ben on 2/02/22.
//

#ifndef PAINTBRUSH__TOOLBAR_H_
#define PAINTBRUSH__TOOLBAR_H_

#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWindow>

class Toolbar : public QWidget {
 public:
  Toolbar();
 private:
  QGridLayout m_gridlayout;
};

#endif //PAINTBRUSH__TOOLBAR_H_
