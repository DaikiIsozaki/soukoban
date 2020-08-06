#pragma once
//|*******|//
//|include|//
//|*******|//
#include "Object.h"

//|*******|//
//|define |//
//|*******|//


class Destination :public Object
{
public:
	Destination() { m_ghandle = LoadGraph("asset/Goal2.png"); };
	~Destination() { DeleteGraph(m_ghandle); };

	void Init();
	void Uninit();
	void Update( );
	void Draw();
	void Move(int move_x, int move_y) {};
	void Create(int x, int y, int sizeX, int sizeY);
	void Destroy();

	int Get_PosX() { return m_positionX; };
	int Get_PosY() { return m_positionY; };

	bool GetHitbool() { return m_bHit; };

	OBJTYPE Get_Type() { return OBJTYPE::DESTINATION; };

private:
	int m_ghandle = 0;
};

