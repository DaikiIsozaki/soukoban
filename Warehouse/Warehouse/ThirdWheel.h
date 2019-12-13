#pragma once
//|*******|//
//|include|//
//|*******|//
#include <random>
#include "Object.h"

//|*******|//
//|define |//
//|*******|//


class ThirdWheel :public Object
{
public:
	ThirdWheel();
	~ThirdWheel() {DeleteGraph(m_ghandle);};

	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Move(int move_x, int move_y);
	void Create(int x, int y, int sizeX, int sizeY);
	void Destroy();

	int Get_PosX() { return _PositionX; };
	int Get_PosY() { return _PositionY; };

	OBJTYPE Get_Type() { return THIRDWHEEL; };

private:
	int m_ghandle = 0;
	int m_ghandle2 = 0;
	int m_fidgetingX = 0;//��������X
	int m_fidgetingY = 0;//��������Y
	int m_fidgeting_frame = 0;//�������������t���[��
	int m_moveframe = 0;
};

