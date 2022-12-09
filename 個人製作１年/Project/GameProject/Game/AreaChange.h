#pragma once

#include "../Base/Base.h"

/// <summary>
/// �G���A�`�F���W�p����I�u�W�F�N�g
/// </summary>
class AreaChange : public Base {
public:
	int m_stage;					//�ړ���̃G���A�ԍ�
	CVector2D m_nextplayerpos;		//�ړ���̃v���C���[�̈ʒu
public:
	/// �R���X�g���N�^
	/// <param name="nextArea">�ړ���̃G���A�ԍ�</param>
	/// <param name="rect">�����蔻���`</param>
	/// <param name="nextplayerpos">�ړ���̃v���C���[�̈ʒu</param>
	AreaChange(int stage, const CRect& rect, const CVector2D& nextplayerpos);
	/// �f�X�g���N�^
	~AreaChange();
	/// �`��
	void Draw();
};
