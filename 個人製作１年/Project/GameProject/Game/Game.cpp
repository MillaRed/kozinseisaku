#include "Game.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Boss.h"
#include "GameData.h"
#include "../Title/Title.h"
#include "../Title/Gameclear.h"
#include "../Title/GameOver.h"

Game::Game():Base(eType_Scene) {
	//マップの生成
	Base::Add(new Map(1,CVector2D(400, 500)));
	//プレイヤーの生成
	Base::Add(new Player(CVector2D(400, 500), false));
	//
	Base::Add(new Enemy(CVector2D(600, 800), false));
	//ボスの生成
	//Base::Add(new Boss(CVector2D(600, 600),false));
}

Game::~Game(){

}

void Game::Update(){
	//ボスがいなければゲームシーン終了
	/*if (!Base::FindObject(eType_Boss)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームクリアシーン
		Base::Add(new GameClear());
	}
	//プレイヤー死亡　ゲームシーン終了
	if (!Base::FindObject(eType_Player)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームオーバーシーン
		Base::Add(new GameOver());
	}*/
}
