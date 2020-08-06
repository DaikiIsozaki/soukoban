#pragma once
//|*******|//
//|include|//
//|*******|//
#include"UiParts.h"

//|*******|//
//|define |//
//|*******|//

class Back :public UiParts
{
public:
	Back();
	~Back() { DeleteGraph(m_texhandle); };

	void Draw()override;
	void Create(int PosX, int PosY)override;
	PARTSTYPE GetType()override { return PARTSTYPE::BACK; };
	int GetPosX()override { return m_posX; };
	int GetPosY()override { return m_posY; };

private:
	std::string m_menu = "Back";
};

