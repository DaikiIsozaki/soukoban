//|*******|//
//|include|//
//|*******|//

#include "TitleName.h"

TitleName::TitleName()
{
	Create(0,-2);	
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 3);
}

void TitleName::Update()
{
	if (frame % 5 == 0)
	{
		m_randomcolor.r = rand() % MAX_COLOR;
		m_randomcolor.g = rand() % MAX_COLOR;
		m_randomcolor.b = rand() % MAX_COLOR;
	}
	frame++;
}

void TitleName::Draw()
{
	

	DrawStringToHandle(_X* FONT_SIZE + _SizeX, _Y* FONT_SIZE + _SizeY - 50,
				m_titleName.c_str(),
				GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);
	
	
}

void TitleName::Create(int x, int y)
{
	_X = x;
	_Y = y;

	_SizeX = (SCREEN_X - (5 * FONT_SIZE))/2;////5Åcï\é¶Ç∑ÇÈstringÇÃ1óÒÇÃï∂éöêî
	_SizeY = (SCREEN_Y - 1 ) / 2;
}
