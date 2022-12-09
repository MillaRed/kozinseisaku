#pragma once
#include "../Base/Base.h"

class GameOver :public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_GameOver_text;
public:
	GameOver();
	~GameOver();
	void Update();
	void Draw();
};
