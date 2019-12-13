//|*******|//
//|include|//
//|*******|//
#include"UI.h"
#include"TitleName.h"
#include"Steps.h"
#include"UiParts.h"
#include"MenuUi.h"
#include"ResultProduction.h"
#include "ResultUi.h"


ResultUi::ResultUi()
{
	m_resultpro = new ResultProduction;

	m_steps = new Steps;
	
	if (m_resultpro->LifeCheck())
	{
		m_menuOrder.Next = true;
		m_menuOrder.NextPosX = 0;
		m_menuOrder.NextPosY = 5;

		m_menuOrder.Back = true;
		m_menuOrder.BackPosX = 0;
		m_menuOrder.BackPosY = 7;

		m_steps->Create(0, 1,true);
	}
	else
	{
		m_menuOrder.Retry = true;
		m_menuOrder.RetryPosX = 0;
		m_menuOrder.RetryPosY = 1;

		m_menuOrder.Back = true;
		m_menuOrder.BackPosX = 0;
		m_menuOrder.BackPosY = 3;
	}
	
	m_menuUi = new MenuUi(&m_menuOrder);
	
}

void ResultUi::Uninit()
{
	m_menuUi->Uninit();

	delete m_menuUi;
	m_menuUi = nullptr;

	delete m_steps;
	m_steps = nullptr;

	delete m_resultpro;
	m_resultpro = nullptr;
}

void ResultUi::Update()
{
	m_steps->Update();
	m_menuUi->Update();
	m_resultpro->Update();
}

void ResultUi::Draw()
{
	if(m_resultpro->LifeCheck())
	m_steps->Draw();

	m_menuUi->Draw();
	m_resultpro->Draw();

	SetFontSize(FONT_SIZE/2);

	DrawString(0, SCREEN_Y - 100, "¡WS,ª«:‘I‘ð@¡ENTER:Œˆ’è", GetColor(255, 255, 255));
	SetFontSize(FONT_DEFAULT_SIZE);

}

