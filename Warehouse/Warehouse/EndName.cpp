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
	

	DrawStringToHandle(m_posX* FONT_SIZE + m_sizeX, m_posY* FONT_SIZE + m_sizeY - 50,
		m_endName.c_str(),
		GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);
	
}

void EndName::Create(int x, int y)
{
	m_posX = x;
	m_posY = y;

	int a=m_endName.length();
	m_sizeX = (SCREEN_X - (11*FONT_SIZE))/2;////11Åcï\é¶Ç∑ÇÈstringÇÃ1óÒÇÃï∂éöêî
	m_sizeY = (SCREEN_Y - 1) / 2;
}

