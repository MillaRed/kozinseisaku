#pragma once
#include "../Base/Base.h"
#include "GameData.h"

//マップ横のチップ数
#define MAP_WIDTH     40
//マップの縦のチップ数
#define MAP_HEIGHT    22
//マップチップの大きさ
#define MAP_TIP_SIZE  96

class Map :public Base {
private:
	CImage m_img;
	int m_map_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Map(int stage,const CVector2D&nextplayerpos);
	void Draw();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);
	void SetTip(const CVector2D& pos, int t);
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
	int ColisionMap(const CVector2D& pos, const CRect& rect);
};
