#pragma once
//|*******|//
//|include|//
//|*******|//
#include "Object.h"

//|*******|//
//|define |//
//|*******|//

class Box :public Object
{
public:
	Box();
	~Box() { DeleteGraph(m_ghandle); DeleteGraph(m_ghandle2);};

	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Move(int move_x, int move_y);
	void Create(int x, int y, int sizeX, int sizeY);
	void Destroy();

	int Get_PosX() { return m_positionX; };
	int Get_PosY() { return m_positionY; };
	int Get_OldPosX() { return m_oldPosX; };
	int Get_OldPosY() { return m_oldPosY; };

	

	OBJTYPE Get_Type() { return OBJTYPE::BOX; };

	int Get_Step() { return m_steps; };//” ‚ÌˆÚ“®•à”‚ğ‚ ‚°‚é
	
private:
	int m_ghandle = 0;
	int m_ghandle2 = 0;
	
};

