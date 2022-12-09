#include "Enemy.h"
#include "Map.h"
#include "Slash.h"
#include "AnimData.h"

void Enemy::StateIdle() {
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;
	//プレイヤーを探索
	Base* player = Base::FindObject(eType_Player);

	//左移動
	if (player->m_pos.x < m_pos.x - 64) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}
	//右移動
	if (player->m_pos.x > m_pos.x + 64) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	if (player->m_pos.x > m_pos.x + 64) {
		//攻撃状態へ移行
		m_state = eState_Attack;
		m_attack_no++;
	}
	if (move_flag) {
		//走るアニメーション
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	}
	//カウント０で待機状態へ
	if (--m_cnt <= 0) {
		//待機時間３秒～５秒
		m_cnt = rand() % 120 + 180;
		m_state = eState_Wait;
	}
}

void Enemy::StateWait(){
	//待機アニメーション
	m_img.ChangeAnimation(eAnimIdle);
	//カウント０で通常状態
	if (--m_cnt <= 0) {
		//待機時間３秒～５秒
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
	//画像複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 140);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
	//当たり判定用矩形設定
	m_rect = CRect(-80, -70, -40, 0);
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//ヒットポイント
	m_hp = 100;
}

void Enemy::Update(){
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//待機アニメーション
	m_img.SetPos(m_pos);
	//アニメーション更新
	m_img.UpdateAnimation();
}

void Enemy::Draw(){
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定用矩形の表示
	DrawRect();
}

void Enemy::Collision(Base* b) {
	switch (b->m_type) {
		//攻撃オブジェクトとの判定
	case eType_Player_Attack:
		//Slash型へキャスト、型変換出来たら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//同じ攻撃の連続ダメージ防止
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
		//Field型へキャスト、型変換出来たら
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->ColisionMap(CVector2D(m_pos.x, m_pos_old.y),m_rect);
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->ColisionMap(CVector2D(m_pos_old.x, m_pos.y),m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
				}
			}
			break;
		}
	}


