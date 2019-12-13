//|*******|//
//|include|//
//|*******|//
#include "Retry.h"

Retry::Retry()
{
	m_texhandle = LoadGraph("asset/Retry.png");
	_SizeX = (SCREEN_X - TEX_X) / 2;
	_SizeY = (SCREEN_Y - TEX_Y) / 2;
}

void Retry::Draw()
{
	DrawGraph(_X* OBJ_SIZE + _SizeX, _Y* OBJ_SIZE + _SizeY, m_texhandle, TRUE);
}

void Retry::Create(int PosX, int PosY)
{
	_X = PosX;
	_Y = PosY;
}


