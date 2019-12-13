//|*******|//
//|include|//
//|*******|//
#include "Next.h"

Next::Next()
{
	m_texhandle = LoadGraph("asset/Next.png");
	_SizeX = (SCREEN_X - TEX_X) / 2;
	_SizeY = (SCREEN_Y - TEX_Y) / 2;
}

void Next::Draw()
{
	DrawGraph(_X* OBJ_SIZE + _SizeX, _Y* OBJ_SIZE + _SizeY, m_texhandle, TRUE);
}

void Next::Create(int PosX, int PosY)
{
	_X = PosX;
	_Y = PosY;
}
