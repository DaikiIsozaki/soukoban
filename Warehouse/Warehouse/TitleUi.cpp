//|*******|//
//|include|//
//|*******|//
#include"UI.h"
#include"TitleName.h"
#include"Steps.h"
#include"UiParts.h"
#include"MenuUi.h"
#include "TitleUi.h"

TitleUi::TitleUi()
{
	m_pName = new TitleName;
	
	m_menuOrder.Start = true;
	m_menuOrder.StartPosX = 0;
	m_menuOrder.StartPosY = 1;

	m_menuOrder.Exit = true;
	m_menuOrder.ExitPosX = 0;
	m_menuOrder.ExitPosY = 3;
	
	m_menuUi = new MenuUi(&m_menuOrder);
}

void TitleUi::Uninit()
{
	delete m_pName;
	m_pName = nullptr;

	m_menuUi->Uninit();

	delete m_menuUi;
	m_menuUi = nullptr;
}

void TitleUi::Update()
{
	m_pName->Update();
	m_menuUi->Update();
}

void TitleUi::Draw()
{
	m_pName->Draw();
	m_menuUi->Draw();

	SetFontSize(FONT_SIZE/2);
	DrawString(0, SCREEN_Y - 100, "¡WS,ª«:‘I‘ð@¡ENTER:Œˆ’è", GetColor(255, 255, 255));
	SetFontSize(FONT_DEFAULT_SIZE);
}

