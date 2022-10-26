#include "Enemy.h"
#include"AnimData.h" 
#include"Field.h"
#include"Slash.h"

Enemy::Enemy(const CVector2D& p, bool flip):Base(eType_Enemy){
		//�摜����
		m_img = COPY_RESOURCE("Enemy", CImage);
		//�Đ��A�j���[�V�����ݒ�
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		m_pos = p;
		//���S�ʒu�ݒ�
		m_img.SetCenter(128, 224);
		//�����蔻��p��`�ݒ�
		m_rect = CRect(-32, -128, 32, 0);
		//���]�t���O
		m_flip = flip;
}

void Enemy::StateIdle(){
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);
	
	/*����m�F��R�����g��
	//���ړ�
	if(player->m_pos.x<m_pos.x-64){
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (player->m_pos.x > m_pos.x + 64) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
	}
	*/
	if (move_flag) {
		//����A�j���[�V����
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	}

}
void Enemy::StateAttck(){

}
void Enemy::StateDamage(){

}
void Enemy::StateDown(){

}

void Enemy::Update(){
	switch (m_state) {
		//
	case eState_Idle:
		StateIdle();
		break;
	}
	
	//	�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Enemy::Draw(){
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻��p�̋�`�̕\��
	DrawRect();
}

void Enemy::Collision(Base*b){
	switch (b->m_type) {
	case eType_Player_Attack:
		//
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//
				m_damage_no = s ->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
		break;
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��ł�����
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɂ�������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
		break;
	}

}

