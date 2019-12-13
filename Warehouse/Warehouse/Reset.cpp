//|*******|//
//|include|//
//|*******|//
#include "Reset.h"

Reset::Reset()
{
	m_texhandle = LoadGraph("asset/Reset.png");
	_SizeX = (SCREEN_X - TEX_X) / 2;
	_SizeY = (SCREEN_Y - TEX_Y) / 2;
}

void Reset::Draw()
{
	DrawGraph(_X* OBJ_SIZE + _SizeX, _Y* OBJ_SIZE + _SizeY, m_texhandle, TRUE);
}

void Reset::Create(int posX, int posY)

{
	_X = posX;
	_Y = posY;
}

