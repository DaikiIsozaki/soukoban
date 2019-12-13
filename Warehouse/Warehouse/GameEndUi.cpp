//|*******|//
//|include|//
//|*******|//
#include"UI.h"
#include"EndName.h"
#include"UiParts.h"
#include"MenuUi.h"
#include "GameEndUi.h"


GameEndUi::GameEndUi()
{
	m_menuOrder.Back = true;
	m_menuOrder.BackPosX = 0;
	m_menuOrder.BackPosY = 1;
	m_menuUi = new MenuUi(&m_menuOrder);
	m_endName = new EndName;
}

void GameEndUi::Uninit()
{
	m_menuUi->Uninit();

	delete m_menuUi;
	m_menuUi = nullptr;

	delete m_endName;
	m_endName = nullptr;
}

void GameEndUi::Update()
{
	m_menuUi->Update();
}

void GameEndUi::Draw()
{
	m_menuUi->Draw();
	m_endName->Draw();

	DrawString(0, SCREEN_Y - 100, "¡ENTER:Œˆ’è", GetColor(255, 255, 255));
}