#include "Title.h"
#include "../Game/Game.h"

Title::Title():Base(eType_Scene),m_title_text("C:\\Windows\\Fonts\\msgothic.ttc",64) {
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title(){

}

void Title::Update(){
	//�{�^���P�Ń^�C�g����j��
	if (PUSH(CInput::eButton1)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Game());
	}
}

void Title::Draw(){
	m_img.Draw();
	//�����\��
	m_title_text.Draw(200, 100, 0, 0, 0, "Title");
}
