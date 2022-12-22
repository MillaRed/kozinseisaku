#pragma once
#include "../Base/Base.h"
class Gauge;
class Player :public Base {
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	//��ԕϐ�
	int m_state;
	CImage m_img;
	int jumpcount = 0;
	//���]�t���O
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	int m_hp;
	int m_max_hp;
	Gauge* m_gauge;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�G���A�`�F���W�t���O
	bool m_enable_area_change;
	//�G���A�`�F���W�I�u�W�F�N�g�ɐG��Ă���t���O
	bool m_hit_area_change;

	//�e��Ԃł̋���
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
