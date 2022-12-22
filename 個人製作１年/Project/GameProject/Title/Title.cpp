#include "Title.h"
#include "../Game/Game.h"

Title::Title():Base(eType_Scene),m_title_text("C:\\Windows\\Fonts\\msgothic.ttc",100) {
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title(){

}

void Title::Update(){
	//ボタン１でタイトルを破棄
	if (PUSH(CInput::eButton1)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーン
		Base::Add(new Game());
	}
}

void Title::Draw(){
	m_img.Draw();
	//文字表示
	m_title_text.Draw(800, 300, 50, 50, 50, "Title");
}
