//|*******|//
//|include|//
//|*******|//
#include "MapName.h"
#include"ReportMapNumber.h"

MapName::MapName()
{
	Create(-1, 1);
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 3);
}

void MapName::Update()
{

}

void MapName::Draw()
{

	DrawStringToHandle(m_posX* OBJ_SIZE + m_sizeX, m_posY,
		ReportMapNumber::GetInstance()->GetMapInfo().c_str(),
		GetColor(255,0,255),m_fonthandle);	

}

void MapName::Create(int x, int y)
{
	m_posX = x;
	m_posY = y;

	m_sizeX = (SCREEN_X - (ReportMapNumber::GetInstance()->GetMapInfo().length()))/2;
	m_sizeY = (SCREEN_Y - 1) / 2;

}

