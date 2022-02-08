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
	const QColor m_palCols[16] = {
		Qt::black,
		Qt::white,
		Qt::darkGray,
		Qt::gray,
		Qt::red,
		Qt::green,
		Qt::blue,
		Qt::cyan,
		Qt::magenta,
		Qt::yellow,
		Qt::darkRed,
		Qt::darkGreen,
		Qt::darkBlue,
		Qt::darkCyan,
		Qt::darkMagenta,
		Qt::darkYellow,
	};
 signals:
	void colorChanged(QColor);
};

#endif //PAINTBRUSH__COLORPALETTE_H_
