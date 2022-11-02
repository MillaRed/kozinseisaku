#pragma once
#include "../Base/Base.h"

//マップ横のチップ数
#define MAP_WIDTH     40
//マップの縦のチップ数
#define MAP_HEIGHT    22
//マップチップの大きさ
#define MAP_TIP_SIZE  32

class Map :public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
};
