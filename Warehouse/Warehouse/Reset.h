#pragma once
//|*******|//
//|include|//
//|*******|//
#include"UiParts.h"

//|*******|//
//|define |//
//|*******|//


class Reset :public UiParts
{
public:
	Reset();
	~Reset() { DeleteGraph(m_texhandle); };

	void Draw()override;
	void Create(int PosX, int PosY)override;
	PARTSTYPE GetType()override { return PARTSTYPE::RESET; };
	int GetPosX()override { return _X; };
	int GetPosY()override { return _Y; };

private:

	std::string m_menu = "Reset";
};

