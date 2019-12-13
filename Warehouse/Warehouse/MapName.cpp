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

	DrawStringToHandle(_X* OBJ_SIZE + _SizeX, _Y,
		ReportMapNumber::GetInstance()->GetMapInfo().c_str(),
		GetColor(255,0,255),m_fonthandle);	

}

void MapName::Create(int x, int y)
{
	_X = x;
	_Y = y;

	_SizeX = (SCREEN_X - (ReportMapNumber::GetInstance()->GetMapInfo().length()))/2;
	_SizeY = (SCREEN_Y - 1) / 2;

}

