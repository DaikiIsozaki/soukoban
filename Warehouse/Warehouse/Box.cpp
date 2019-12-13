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
		DrawGraph(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, m_ghandle2,FALSE);
		_bHit = true;
	}
	else
	{
		DrawGraph((_PositionX* OBJ_SIZE + _SizeX), _PositionY* OBJ_SIZE + _SizeY, m_ghandle, FALSE);
		/*DrawString(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, "¡", GetColor(255, 255, 255));*/
		_bHit = false;
	}
}

void Box::Move(int move_x, int move_y)
{

	if(HitMove::Get_Instance()->MoveOther(this,move_x,move_y))
	{
		_PositionX += move_x;
		_PositionY += move_y;
	}	
}

void Box::Create(int x, int y, int sizeX, int sizeY)
{
	_PositionX = x;
	_PositionY = y;
	_SizeX = sizeX;
	_SizeY = sizeY;

}

void Box::Destroy()
{

}


