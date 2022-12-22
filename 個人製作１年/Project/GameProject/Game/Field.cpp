#include "Field.h"

Field::Field():Base(eType_Field) {
	m_town = COPY_RESOURCE("Town", CImage);
	m_foreground = COPY_RESOURCE("ForeGround", CImage);
	m_haikei = COPY_RESOURCE("haikei", CImage);
	m_ground_y = 540;
}

void Field::Draw(){
	float sc;
	sc = m_scroll.x / 4;
	m_town.SetRect(sc, 0, sc + 1280, 720);
	m_haikei.Draw();
	//m_town.Draw();
	 
	sc = m_scroll.x;
	m_foreground.SetRect(sc, 0, sc + 1280, 720);
	//m_foreground.Draw();
}
