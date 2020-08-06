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
	m_bHit = false;
	if (!HitMove::Get_Instance()->Hit(this))
	{
		DrawGraph((m_positionX* OBJ_SIZE + m_sizeX), m_positionY* OBJ_SIZE + m_sizeY, m_ghandle, TRUE);
	}
	else m_bHit = true;
}

void Destination::Create(int x, int y, int sizeX, int sizeY)
{
	m_positionX = x;
	m_positionY = y;
	m_sizeX = sizeX;
	m_sizeY = sizeY;
}


void Destination::Destroy()
{
}
