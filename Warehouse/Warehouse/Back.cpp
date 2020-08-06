//|*******|//
//|include|//
//|*******|//
#include "Back.h"



Back::Back()
{
	m_texhandle = LoadGraph("asset/TitleBack.png");
	m_sizeX = (SCREEN_X - TEX_X) / 2;
	m_sizeY = (SCREEN_Y - TEX_Y) / 2;
}

void Back::Draw()
{
	DrawGraph(m_posX* OBJ_SIZE + m_sizeX, m_posY* OBJ_SIZE + m_sizeY, m_texhandle, TRUE);

}

void Back::Create(int PosX, int PosY)
{
	m_posX = PosX;
	m_posY = PosY;
}
