#pragma once
//|*******|//
//|include|//
//|*******|//
#include "UI.h"

//|*******|//
//|define |//
//|*******|//


////�X�e�b�v���ɉ����ă��C�t���ꏏ�ɕ\������//
class Steps :public UI
{
public:
	Steps();
	~Steps() { DeleteFontToHandle(m_fonthandle); };

	void Update()override;
	void Draw()override;
	void Create(int x, int y,bool result);

private:
	
	////�����\��//
	std::string m_steps_player	= "�X�e�b�v��:";
	std::string m_stepsnum_player;
	////�c�C�\��//
	std::string m_life_player	= "���C�t�@:";
	std::string m_lifenum_player;

	
};

