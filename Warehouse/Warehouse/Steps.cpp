//|*******|//
//|include|//
//|*******|//
#include "Steps.h"

Steps::Steps()
{
	m_posX = m_posY = m_sizeX = m_sizeY = 0;
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 3);
}

void Steps::Update()
{
	m_stepsnum_player = std::to_string(ReportScore::GetInstance()->GetPlayerSteps());
	m_lifenum_player = std::to_string(ReportScore::GetInstance()->GetLife());
}

void Steps::Draw()
{

	DrawStringToHandle(m_posX* FONT_SIZE + m_sizeX, m_posY* FONT_SIZE + m_sizeY,
		(m_steps_player + m_stepsnum_player).c_str(), GetColor(255, 255, 255), m_fonthandle);
	DrawStringToHandle(m_posX* FONT_SIZE + m_sizeX, m_posY* FONT_SIZE + m_sizeY + 50, 
		(m_life_player + m_lifenum_player).c_str(), GetColor(255, 255, 255), m_fonthandle);

}

void Steps::Create(int x, int y, bool result)
{	
	m_posX = x;
	m_posY = y;

	if (result)
	{
		m_sizeX = (SCREEN_X  - (6 * FONT_SIZE)) / 2;////6Åcï\é¶Ç∑ÇÈstringÇÃ1óÒÇÃï∂éöêî
		m_sizeY = (SCREEN_Y - 1) / 2;
	}
}
