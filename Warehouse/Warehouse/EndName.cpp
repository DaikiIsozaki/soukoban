//|*******|//
//|include|//
//|*******|//

#include "EndName.h"

EndName::EndName()
{
	Create(0, -2);
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 2);
}

void EndName::Update()
{
}

void EndName::Draw()
{
	

	DrawStringToHandle(_X* FONT_SIZE + _SizeX, _Y* FONT_SIZE + _SizeY - 50,
		m_endName.c_str(),
		GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);
	
}

void EndName::Create(int x, int y)
{
	_X = x;
	_Y = y;

	int a=m_endName.length();
	_SizeX = (SCREEN_X - (11*FONT_SIZE))/2;////11Åcï\é¶Ç∑ÇÈstringÇÃ1óÒÇÃï∂éöêî
	_SizeY = (SCREEN_Y - 1) / 2;
}

