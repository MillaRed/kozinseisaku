#include "Player.h"
#include "AnimData.h"
#include "Field.h"
#include "Slash.h"
#include "Map.h"
#include "Gauge.h"
#include "AreaChange.h"

void Player::StateIdle() {
	//移動量
	const float move_speed = 6;
	//ジャンプ力
	const float jump_pow = 15;
	//移動フラグ
	bool move_flag = false;
	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//攻撃
	if (PUSH(CInput::eButton1)) {
		//攻撃状態へ移行
		m_state = eState_Attack;
		m_attack_no++;
	}
	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//移動中なら
	else {
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}

void Player::StateAttack(){
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}

void Player::StateDamage(){
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player::StateDown(){
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}

Player::Player(const CVector2D& p,bool flip):Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old=m_pos = p;
	//中心位置設定
	m_img.SetCenter(126, 190);
	//当たり判定用矩形設定
	m_rect = CRect(-50, -90, 0, 0);
	//ゲージ生成
	Base::Add(m_gauge = new Gauge(0));
	//HP設定
	m_hp = m_max_hp = 200;
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = false;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;

	m_enable_area_change = true;
	m_hit_area_change = false;
}

Player::~Player() {
	//ゲージ削除
	if (m_gauge)
		m_gauge->SetKill();
}

void Player::Update(){
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
	//アニメーション更新
	m_img.UpdateAnimation();
	//スクロール値の設定
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;

	//
	//
	if (!m_enable_area_change && !m_hit_area_change)
		m_enable_area_change = true;
	m_hit_area_change = false;
	//ゲージ更新
	m_gauge->SetValue((float)m_hp / m_max_hp);
	m_gauge->m_pos = CVector2D(0, 0);
}

void Player::Draw(){
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形表示
	DrawRect();
}

void Player::Collision(Base* b){
	switch (b->m_type){
	case eType_AreaChange:
		if (Base::CollisionRect(this, b)) {
			//エリアチェンジに触れている
			m_hit_area_change = true;
			//エリアチェンジ可能なら
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//マップとエリアチェンジオブジェクトを削除
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					//次のマップを生成
					Base::Add(new Map(a->m_stage, a->m_nextplayerpos));
					//エリアチェンジ一時不許可
					m_enable_area_change = false;
				}
			}
		}
	case  eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->ColisionMap(CVector2D(m_pos.x, m_pos_old.y),m_rect);
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->ColisionMap(CVector2D(m_pos_old.x, m_pos.y),m_rect);
			if (t != 0) {
				//地面の高さに戻す
				m_pos.y = m_pos_old.y;
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグ
				m_is_ground = true;
			}
		}
		break;
		}
}
