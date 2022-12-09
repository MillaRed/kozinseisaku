#include "Enemy.h"
#include "Map.h"
#include "Slash.h"
#include "AnimData.h"

void Enemy::StateIdle() {
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);

	//���ړ�
	if (player->m_pos.x < m_pos.x - 64) {
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
	if (player->m_pos.x > m_pos.x + 64) {
		//�U����Ԃֈڍs
		m_state = eState_Attack;
		m_attack_no++;
	}
	if (move_flag) {
		//����A�j���[�V����
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	}
	//�J�E���g�O�őҋ@��Ԃ�
	if (--m_cnt <= 0) {
		//�ҋ@���ԂR�b�`�T�b
		m_cnt = rand() % 120 + 180;
		m_state = eState_Wait;
	}
}

void Enemy::StateWait(){
	//�ҋ@�A�j���[�V����
	m_img.ChangeAnimation(eAnimIdle);
	//�J�E���g�O�Œʏ���
	if (--m_cnt <= 0) {
		//�ҋ@���ԂR�b�`�T�b
		m_cnt = rand() % 120 + 180;
		m_state = eState_Idle;
	}
}

void Enemy::StateAttack()
{
}

void Enemy::StateDamage()
{
}

void Enemy::StateDown()
{
}

Enemy::Enemy(const CVector2D& p, bool flip):Base(eType_Enemy){
	//�摜����
	m_img = COPY_RESOURCE("Enemy", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos_old = m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 140);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = true;
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-80, -70, -40, 0);
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//�q�b�g�|�C���g
	m_hp = 100;
}

void Enemy::Update(){
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//�ҋ@�A�j���[�V����
	m_img.SetPos(m_pos);
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
	//�����蔻��p��`�̕\��
	DrawRect();
}

void Enemy::Collision(Base* b) {
	switch (b->m_type) {
		//�U���I�u�W�F�N�g�Ƃ̔���
	case eType_Player_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��o������
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//�����U���̘A���_���[�W�h�~
				m_damage_no = s->GetAttackNo();
				m_hp - 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
			break;
		}
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��o������
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->ColisionMap(CVector2D(m_pos.x, m_pos_old.y),m_rect);
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->ColisionMap(CVector2D(m_pos_old.x, m_pos.y),m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
				}
			}
			break;
		}
	}


