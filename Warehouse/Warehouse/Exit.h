#pragma once
//|*******|//
//|include|//
//|*******|//
#include"UiParts.h"

//|*******|//
//|define |//
//|*******|//


class Exit :public UiParts
{
public:
	Exit() ;
	~Exit() { DeleteGraph(m_texhandle); };

	void Draw()override;
	void Create(int PosX, int PosY)override;
	PARTSTYPE GetType()override { return PARTSTYPE::EXIT; };
	int GetPosX()override { return _X; };
	int GetPosY()override { return _Y; };

private:
	
	std::string m_menu = "Exit";
};

