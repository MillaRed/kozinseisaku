#include "GameClear.h"
#include "Title.h"
#include "../Game/Game.h"

GameClear::GameClear():Base(eType_GameClear),m_GameClear_text("C:\\Windows\\Fonts\\msgothic.ttc",80) {
	m_img = COPY_RESOURCE("GameClear", CImage);
	pull = false;
}

GameClear::~GameClear(){
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーン
	Base::Add(new Title());
}

void GameClear::Update(){
	//ボタン１でクリア画面を破棄
	if (PUSH(CInput::eButton1)) {
			if (pull == true)SetKill();
		}
		else
			pull = true;
	}


void GameClear::Draw(){
	m_img.Draw();
	//文字表示
	m_GameClear_text.Draw(450, 200, 0, 0, 0, "GameClear!!");
}
