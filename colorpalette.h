//
// Created by ben on 7/02/22.
//

#ifndef PAINTBRUSH__COLORPALETTE_H_
#define PAINTBRUSH__COLORPALETTE_H_

#include <QWidget>
#include <QGridLayout>

class ColorPalette : public QWidget
{
	Q_OBJECT
public:
	ColorPalette(QWidget* p);
 private:
	QGridLayout m_gridLayout;
 signals:
	void colorChanged(QColor);
};

#endif //PAINTBRUSH__COLORPALETTE_H_
