#pragma once
//|*******|//
//|include|//
//|*******|//
#include"UiParts.h"

//|*******|//
//|define |//
//|*******|//


class Start :public UiParts
{
public:
	Start();
	~Start() { DeleteGraph(m_texhandle); };

	void Draw()override;
	void Create(int PosX, int PosY)override;
	PARTSTYPE GetType()override { return PARTSTYPE::START; };
	int GetPosX()override { return _X; };
	int GetPosY()override { return _Y; };

private:
	
	std::string m_menu = "Start";
};

