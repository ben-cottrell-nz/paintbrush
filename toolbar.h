//
// Created by ben on 2/02/22.
//

#ifndef PAINTBRUSH__TOOLBAR_H_
#define PAINTBRUSH__TOOLBAR_H_

#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWindow>

class Toolbar : public QWidget
{
	Q_OBJECT
public:
	Toolbar();
	enum ToolMode {
		PENCIL,
		PAINTBRUSH,
		FILL
	};
signals:
	void toolChanged(ToolMode);
private:
	QGridLayout m_gridlayout;

};

#endif //PAINTBRUSH__TOOLBAR_H_
