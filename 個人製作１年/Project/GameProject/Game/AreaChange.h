#pragma once

#include "../Base/Base.h"

/// <summary>
/// エリアチェンジ用判定オブジェクト
/// </summary>
class AreaChange : public Base {
public:
	int m_stage;					//移動先のエリア番号
	CVector2D m_nextplayerpos;		//移動後のプレイヤーの位置
public:
	/// コンストラクタ
	/// <param name="nextArea">移動先のエリア番号</param>
	/// <param name="rect">当たり判定矩形</param>
	/// <param name="nextplayerpos">移動後のプレイヤーの位置</param>
	AreaChange(int stage, const CRect& rect, const CVector2D& nextplayerpos);
	/// デストラクタ
	~AreaChange();
	/// 描画
	void Draw();
};
