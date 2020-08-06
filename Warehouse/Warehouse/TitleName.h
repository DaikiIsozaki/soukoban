#pragma once
//|*******|//
//|include|//
//|*******|//
#include "UI.h"

//|*******|//
//|define |//
//|*******|//




class TitleName :public UI
{
public:
	TitleName();
	~TitleName() { DeleteFontToHandle(m_fonthandle); };

	void Update()override;
	void Draw()override;
	
private:
	void Create(int x, int y);
	std::string m_titleName = "����������\n���q�ɔԁ�\n����������";
	/*
	����������
	���q�ɔԁ�
	����������
	*/
	

	int m_frame = 0;
};

