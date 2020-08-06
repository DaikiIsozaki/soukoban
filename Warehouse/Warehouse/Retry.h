#pragma once
//|*******|//
//|include|//
//|*******|//
#include"UiParts.h"

//|*******|//
//|define |//
//|*******|//


class Retry :public UiParts
{
public:
	Retry();
	~Retry() { DeleteGraph(m_texhandle); };

	void Draw()override;
	void Create(int PosX, int PosY)override;
	PARTSTYPE GetType()override { return PARTSTYPE::RETRY; };
	int GetPosX()override { return m_posX; };
	int GetPosY()override { return m_posY; };
};

