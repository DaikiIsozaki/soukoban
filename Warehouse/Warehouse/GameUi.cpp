//|*******|//
//|include|//
//|*******|//
#include"UI.h"
#include"TitleName.h"
#include"Steps.h"
#include "MapName.h"
#include"UiParts.h"
#include"MenuUi.h"
#include"MapSelect.h"
#include "GameUi.h"
#include"KyeInput.h"
#include"CheckPauseMode.h"

GameUi::GameUi()
{	
	m_menuOrder.Reset = true;
	m_menuOrder.ResetPosX = 0;
	m_menuOrder.ResetPosY = 0;

	m_menuOrder.Back = true;
	m_menuOrder.BackPosX = 0;
	m_menuOrder.BackPosY = 2;

	m_menuUi = new MenuUi(&m_menuOrder);
	m_steps = new Steps;
	m_steps->Create(0, 0,false);

	m_mapname = new MapName;

	m_mapselect = new MapSelect;
	m_mapselect->MapExplanation();

}

void GameUi::Uninit()
{
	m_menuUi->Uninit();

	delete m_menuUi;
	m_menuUi = nullptr;

	delete m_steps;
	m_steps = nullptr;

	delete m_mapname;
	m_mapname = nullptr;

	delete m_mapselect;
	m_mapselect = nullptr;
}

void GameUi::Update()
{
	if(CheckPauseMode::GetInstance()->CheckPause())
		m_menuUi->Update();

	m_steps->Update();
}

void GameUi::Draw()
{
	if (CheckPauseMode::GetInstance()->CheckPause())
		m_menuUi->Draw();


	m_steps->Draw();
	m_mapname->Draw();

	SetFontSize(FONT_SIZE/2);
	DrawString(0, SCREEN_Y - 100, "¡ENTER:Œˆ’è@¡ESC:ƒƒjƒ…[\n¡WASD,ª©«¨:ˆÚ“®", GetColor(255, 255, 255));
	SetFontSize(FONT_DEFAULT_SIZE);
}
