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
	std::string m_titleName = "Å°Å°Å°Å°Å°\nÅ°ëqå…î‘Å°\nÅ°Å°Å°Å°Å°";
	/*
	Å°Å°Å°Å°Å°
	Å°ëqå…î‘Å°
	Å°Å°Å°Å°Å°
	*/
	

	int frame = 0;
};

