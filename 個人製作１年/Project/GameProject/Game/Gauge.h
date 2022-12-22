#pragma once
#include "../Base/Base.h"
class Gauge :public Base {
private:
	float m_par;
	int m_gauge_type;
	CImage m_img;
public:
	Gauge(int gauge_type);
	void Draw();
	void SetValue(float par);
};
