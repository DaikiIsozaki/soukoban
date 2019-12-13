#pragma once
//|*******|//
//|include|//
//|*******|//
#include "UI.h"

//|*******|//
//|define |//
//|*******|//

class EndName :public UI
{
public:
	EndName();
	~EndName() { DeleteFontToHandle(m_fonthandle); };

	void Update()override;
	void Draw()override;

private:
	void Create(int x, int y);

	std::string m_endName = "■■■■■■■■■■■\n■全ステージクリアー■\n■■■■■■■■■■■";
	/*
	■■■■■■■■■■■
	■全ステージクリアー■
	■■■■■■■■■■■
	*/
};

