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
	m_posX = 0;
	m_posY = -2;
	m_sizeX = ((SCREEN_X - (5 * FONT_SIZE))) / 2;////5c•\Ž¦‚·‚éstring‚Ì1—ñ‚Ì•¶Žš”
	m_sizeY = (SCREEN_Y - 1) / 2;
	m_fonthandle = CreateFontToHandle(NULL, FONT_SIZE, 2);
}

void ResultProduction::Update()
{
	if (m_frame % 5 == 0)
	{
		m_randomcolor.r = rand() % MAX_COLOR;
		m_randomcolor.g = rand() % MAX_COLOR;
		m_randomcolor.b = rand() % MAX_COLOR;
	}
	m_frame++;
}

void ResultProduction::Draw()
{	
	if (m_crearcheck)
	{
	
		DrawStringToHandle(m_posX* FONT_SIZE + m_sizeX, m_posY* FONT_SIZE + m_sizeY - 50,
			m_resultproduce.c_str(),
			GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);

	}
	else
	{
		DrawStringToHandle(m_posX* FONT_SIZE + m_sizeX, m_posY* FONT_SIZE + m_sizeY - 50,
			m_resultproduce2.c_str(),
			GetColor(m_randomcolor.r, m_randomcolor.g, m_randomcolor.b),m_fonthandle);
		
	}
}
