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
	if (m_frame % 5 == 0)
	{
		m_randomcolor.r = rand() % MAX_COLOR;
		m_randomcolor.g = rand() % MAX_COLOR;
		m_randomcolor.b = rand() % MAX_COLOR;
	}
	m_frame++;
}

void TitleName::Draw()
{
	

	DrawStringToHandle(m_posX* FONT_SIZE + m_sizeX, m_posY* FONT_SIZE + m_sizeY - 50,
				m_titleName.c_str(),
				GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);
	
	
}

void TitleName::Create(int x, int y)
{
	m_posX = x;
	m_posY = y;

	m_sizeX = (SCREEN_X - (5 * FONT_SIZE))/2;////5Åcï\é¶Ç∑ÇÈstringÇÃ1óÒÇÃï∂éöêî
	m_sizeY = (SCREEN_Y - 1 ) / 2;
}
