//|*******|//
//|include|//
//|*******|//
#include "Retry.h"

Retry::Retry()
{
	m_texhandle = LoadGraph("asset/Retry.png");
	m_sizeX = (SCREEN_X - TEX_X) / 2;
	m_sizeY = (SCREEN_Y - TEX_Y) / 2;
}

void Retry::Draw()
{
	DrawGraph(m_posX* OBJ_SIZE + m_sizeX, m_posY* OBJ_SIZE + m_sizeY, m_texhandle, TRUE);
}

void Retry::Create(int PosX, int PosY)
{
	m_posX = PosX;
	m_posY = PosY;
}


