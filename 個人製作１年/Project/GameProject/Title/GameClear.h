#pragma once
#include "../Base/Base.h"

class GameClear :public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_GameClear_text;
public:
	GameClear();
	~GameClear();
	void Update();
	void Draw();
	bool pull;
};
