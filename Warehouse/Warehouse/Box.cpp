//|*******|//
//|include|//
//|*******|//
#include "Box.h"
#include"HitMove.h"
#include"main.h"


Box::Box()
{
	m_ghandle = LoadGraph("asset/Box.png");
	m_ghandle2 = LoadGraph("asset/Box_Goal.png");
}

void Box::Init()
{
	
}

void Box::Uninit()
{
	
}

void Box::Update()
{
	
}

void Box::Draw()
{
	if (HitMove::Get_Instance()->Hit(this))
	{
		DrawGraph(m_positionX* OBJ_SIZE + m_sizeX, m_positionY* OBJ_SIZE + m_sizeY, m_ghandle2,FALSE);
		m_bHit = true;
	}
	else
	{
		DrawGraph((m_positionX* OBJ_SIZE + m_sizeX), m_positionY* OBJ_SIZE + m_sizeY, m_ghandle, FALSE);
		/*DrawString(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, "¡", GetColor(255, 255, 255));*/
		m_bHit = false;
	}
}

void Box::Move(int move_x, int move_y)
{

	if(HitMove::Get_Instance()->MoveOther(this,move_x,move_y))
	{
		m_positionX += move_x;
		m_positionY += move_y;
	}	
}

void Box::Create(int x, int y, int sizeX, int sizeY)
{
	m_positionX = x;
	m_positionY = y;
	m_sizeX = sizeX;
	m_sizeY = sizeY;

}

void Box::Destroy()
{

}


