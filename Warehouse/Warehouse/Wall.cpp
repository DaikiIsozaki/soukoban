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
	DrawGraph(m_positionX* OBJ_SIZE + m_sizeX, m_positionY* OBJ_SIZE + m_sizeY, m_ghandle, FALSE);
}

void Wall::Create(int x, int y, int sizeX, int sizeY)
{
	m_positionX = x;
	m_positionY = y;
	m_sizeX = sizeX;
	m_sizeY = sizeY;
}

void Wall::Destroy()
{

}
