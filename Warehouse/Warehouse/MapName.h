#pragma once
//|*******|//
//|include|//
//|*******|//
#include "UI.h"

//|*******|//
//|define |//
//|*******|//


class MapName :public UI
{
public:
	MapName();
	~MapName() { DeleteFontToHandle(m_fonthandle); };

	void Update()override;
	void Draw()override;

private:
	void Create(int x, int y);
};

