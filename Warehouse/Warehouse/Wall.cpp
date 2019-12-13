//|*******|//
//|include|//
//|*******|//
#include "Wall.h"
#include"HitMove.h"
#include"main.h"

void Wall::Init()
{
	
}

void Wall::Uninit()
{

}

void Wall::Update()
{
	
}

void Wall::Draw()
{
	/*DrawString(_PositionX* OBJ_SIZE+_SizeX, _PositionY* OBJ_SIZE+_SizeY, "Åû", GetColor(255, 255, 255));*/
	DrawGraph(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, m_ghandle, FALSE);
}

void Wall::Create(int x, int y, int sizeX, int sizeY)
{
	_PositionX = x;
	_PositionY = y;
	_SizeX = sizeX;
	_SizeY = sizeY;
}

void Wall::Destroy()
{

}
