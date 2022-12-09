#pragma once
#include "../Base/Base.h"

class Boss :public Base {
private:
	//状態
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
	};
	CImage m_img;
	//状態変数
	int m_state;
	int m_cnt;
	//反転フラグ
	bool m_flip;
	//着地フラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;
	//ヒットポイント
	int m_hp;
	//各状態での挙動
	void StateIdle();
	void StateWait();
	void StateAttack();
	void StateDamege();
	void StateDown();
public:
	Boss(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
