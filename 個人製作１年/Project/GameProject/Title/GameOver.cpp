#include "GameOver.h"
#include "Title.h"
#include "../Game/Game.h"

GameOver::GameOver():Base(eType_GameOver),m_GameOver_text("C:\\Windows\\Fonts\\msgothic.ttc",64) {
	m_img = COPY_RESOURCE("GameOver",CImage);
}

GameOver::~GameOver(){

}

void GameOver::Update(){
	//ボタン１でゲームオーバー画面を破棄
	if (PUSH(CInput::eButton1)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーン
		Base::Add(new Title());
	}
}

void GameOver::Draw(){
	m_img.Draw();
	//文字表示
	m_GameOver_text.Draw(400, 200, 0, 0, 0, "GameOver");
}
