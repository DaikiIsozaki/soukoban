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
	int GetPosX()override { return _X; };
	int GetPosY()override { return _Y; };

private:
	std::string m_menu = "Back";
};

