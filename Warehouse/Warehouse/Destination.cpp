//|*******|//
//|include|//
//|*******|//
#include "Destination.h"
#include"HitMove.h"
#include"Box.h"
#include"main.h"

void Destination::Init()
{

}

void Destination::Uninit()
{
	
}

void Destination::Update()
{
	
}

void Destination::Draw()
{
	_bHit = false;
	if (!HitMove::Get_Instance()->Hit(this))
	{
		DrawGraph((_PositionX* OBJ_SIZE + _SizeX), _PositionY* OBJ_SIZE + _SizeY, m_ghandle, TRUE);
	}
	else _bHit = true;
}

void Destination::Create(int x, int y, int sizeX, int sizeY)
{
	_PositionX = x;
	_PositionY = y;
	_SizeX = sizeX;
	_SizeY = sizeY;
}


void Destination::Destroy()
{
}
