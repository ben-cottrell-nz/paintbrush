//
// Created by ben on 7/02/22.
//

#ifndef PAINTBRUSH__COLORPALETTE_H_
#define PAINTBRUSH__COLORPALETTE_H_

#include <QWidget>

class ColorPalette : public QWidget
{
	Q_OBJECT
public:
	ColorPalette(QWidget* p = nullptr) : QWidget(p)
	{

	}
 signals:
	void colorChanged(QColor);
};

#endif //PAINTBRUSH__COLORPALETTE_H_
