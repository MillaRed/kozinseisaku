#include "Field.h"

Field::Field():Base(eType_Field) {
	m_sky = COPY_RESOURCE("Sky", CImage);
	m_town = COPY_RESOURCE("Town", CImage);
	m_foreground = COPY_RESOURCE("ForeGround", CImage);
	m_ground_y = 540;
}

void Field::Draw(){
	//m_sky.Draw();
	//m_town.Draw();
	//m_foreground.Draw();
}
