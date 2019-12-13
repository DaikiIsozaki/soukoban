//|*******|//
//|include|//
//|*******|//
#include "Steps.h"

Steps::Steps()
{
	_X = _Y = _SizeX = _SizeY = 0;
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 3);
}

void Steps::Update()
{
	m_stepsnum_player = std::to_string(ReportScore::GetInstance()->GetPlayerSteps());
	m_lifenum_player = std::to_string(ReportScore::GetInstance()->GetLife());
}

void Steps::Draw()
{

	DrawStringToHandle(_X* FONT_SIZE + _SizeX, _Y* FONT_SIZE + _SizeY,
		(m_steps_player + m_stepsnum_player).c_str(), GetColor(255, 255, 255), m_fonthandle);
	DrawStringToHandle(_X* FONT_SIZE + _SizeX, _Y* FONT_SIZE + _SizeY + 50, 
		(m_life_player + m_lifenum_player).c_str(), GetColor(255, 255, 255), m_fonthandle);

}

void Steps::Create(int x, int y, bool result)
{	
	_X = x;
	_Y = y;

	if (result)
	{
		_SizeX = (SCREEN_X  - (6 * FONT_SIZE)) / 2;////6Åcï\é¶Ç∑ÇÈstringÇÃ1óÒÇÃï∂éöêî
		_SizeY = (SCREEN_Y - 1) / 2;
	}
}
