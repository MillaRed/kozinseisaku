#pragma once
#include "../Base/Base.h"
class Gauge;
class Player :public Base {
	//状態
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	//状態変数
	int m_state;
	CImage m_img;
	int jumpcount = 0;
	//反転フラグ
	bool m_flip;
	//着地フラグ
	bool m_is_ground;
	int m_hp;
	int m_max_hp;
	Gauge* m_gauge;
	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;
	//エリアチェンジフラグ
	bool m_enable_area_change;
	//エリアチェンジオブジェクトに触れているフラグ
	bool m_hit_area_change;

	//各状態での挙動
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
public:
	Player(const CVector2D& p,bool flip);
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);
};
