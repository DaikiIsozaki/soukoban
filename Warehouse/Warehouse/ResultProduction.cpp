#include "ResultProduction.h"
#include"ReportScore.h"

bool ResultProduction::LifeCheck()
{
	if (ReportScore::GetInstance()->GetLife() <= 0)
	{
		m_crearcheck = false;
	}
	return m_crearcheck;
}

ResultProduction::ResultProduction()
{
	_X = 0;
	_Y = -2;
	_SizeX = ((SCREEN_X - (5 * FONT_SIZE))) / 2;////5c•\Ž¦‚·‚éstring‚Ì1—ñ‚Ì•¶Žš”
	_SizeY = (SCREEN_Y - 1) / 2;
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 2);
}

void ResultProduction::Update()
{
	if (frame % 5 == 0)
	{
		m_randomcolor.r = rand() % MAX_COLOR;
		m_randomcolor.g = rand() % MAX_COLOR;
		m_randomcolor.b = rand() % MAX_COLOR;
	}
	frame++;
}

void ResultProduction::Draw()
{	
	if (m_crearcheck)
	{
	
		DrawStringToHandle(_X* FONT_SIZE + _SizeX, _Y* FONT_SIZE + _SizeY - 50,
			m_resultproduce.c_str(),
			GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);

	}
	else
	{
		DrawStringToHandle(_X* FONT_SIZE + _SizeX, _Y* FONT_SIZE + _SizeY - 50,
			m_resultproduce2.c_str(),
			GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);
		
	}
}
