//
// Created by ben on 2/02/22.
//

#include "toolbar.h"
#include <QPushButton>
#include <QLabel>

Toolbar::Toolbar() : m_gridlayout() {
  setLayout(&m_gridlayout);
  QPushButton* bnPencil = new QPushButton(this);
  QPushButton* bnFill = new QPushButton(this);
  QPushButton* bnPaintbrush = new QPushButton(this);
  bnFill->setIcon(QIcon(":/icons/fill-bucket.png"));
  bnFill->setIconSize({64,64});
  bnPencil->setIcon(QIcon(":/icons/pencil.png"));
  bnPencil->setIconSize({64,64});
  bnPencil->setMinimumSize(32,32);
  bnFill->setMinimumSize(64,64);
  bnPencil->resize(32,32);
  bnPaintbrush->setIcon(QIcon(":/icons/paintbrush.png"));
  bnPaintbrush->setIconSize({64,64});
//  setStyleSheet("QWidget { background-image: url(\":/icons/fill-bucket.png\"); }");
//  QLabel* l = new QLabel("Hello",this);
  m_gridlayout.addWidget(bnPencil, 0,0);
  m_gridlayout.addWidget(bnFill, 0,1);
  m_gridlayout.addWidget(bnPaintbrush,1,0);
  QSpacerItem *spacer = new QSpacerItem(20,40,QSizePolicy::Minimum, QSizePolicy::Expanding);
  m_gridlayout.addItem(spacer, 2,0, 1,2);

}
