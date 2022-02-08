//
// Created by ben on 7/02/22.
//

#include "colorpalette.h"
#include <QPushButton>
#include <QLabel>
ColorPalette::ColorPalette(QWidget* p) : QWidget(p)
{
	for (int r=0;r < 2;r++) {
		for (int c=0; c < 8; c++) {
			QPushButton* bn = new QPushButton(this);
			QPalette pal = bn->palette();
			pal.setColor(QPalette::ColorRole::Button, m_palCols[c+(r*3)]);
			bn->setPalette(pal);
			bn->setProperty("color",m_palCols[c+(r*3)]);
			connect(bn, &QPushButton::pressed, this, [bn, this](){
				emit colorChanged(bn->property("color").value<QColor>());
			});)
			m_gridLayout.addWidget(bn,r,c);
		}
	}
	setLayout(&m_gridLayout);

}
