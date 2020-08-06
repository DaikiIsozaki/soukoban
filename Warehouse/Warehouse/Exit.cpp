//|*******|//
//|include|//
//|*******|//
#include "Exit.h"

Exit::Exit()
{
	m_texhandle = LoadGraph("asset/Exit.png");
	m_sizeX = (SCREEN_X - TEX_X) / 2;
	m_sizeY = (SCREEN_Y - TEX_Y) / 2;
}

void Exit::Draw()
{
	DrawGraph(m_posX* OBJ_SIZE + m_sizeX, m_posY* OBJ_SIZE + m_sizeY, m_texhandle, TRUE);
}

void Exit::Create(int posX, int posY)
{
	m_posX = posX;
	m_posY = posY;
	
}
