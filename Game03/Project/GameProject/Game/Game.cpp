#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene)
{
	
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(0, 540), false));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 1, 540), true));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 2, 540), true));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 3, 540), true));


}

Game::~Game(){
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update()
{
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}

