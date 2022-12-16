#include "Game.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Boss.h"
#include "GameData.h"
#include "Field.h"
#include "../Title/Title.h"
#include "../Title/Gameclear.h"
#include "../Title/GameOver.h"

Game::Game():Base(eType_Scene) {
	//�}�b�v�̐���
	Base::Add(new Map(1,CVector2D(400, 500)));
	//�v���C���[�̐���
	Base::Add(new Player(CVector2D(400, 500), false));
	//
	Base::Add(new Enemy(CVector2D(600, 800), false));
	//�{�X�̐���
	Base::Add(new Boss(CVector2D(600, 600),false));
}

Game::~Game(){

}

void Game::Update(){
	//�{�X�����Ȃ���΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Boss)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���N���A�V�[��
		Base::Add(new GameClear());
	}
	//�v���C���[���S�@�Q�[���V�[���I��
	if (!Base::FindObject(eType_Player)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���I�[�o�[�V�[��
		Base::Add(new GameOver());
	}
}
