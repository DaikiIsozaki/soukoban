//|*******|//
//|include|//
//|*******|//
#include"UI.h"
#include"TitleName.h"
#include"Steps.h"
#include"UiParts.h"
#include"MenuUi.h"
#include"MapSelect.h"
#include "StageSelectUi.h"
#include"CheckPauseMode.h"


StageSelectUi::StageSelectUi()
{
	m_menuOrder.Back = true;
	m_menuOrder.BackPosX = 0;
	m_menuOrder.BackPosY = 1;

	m_menuUi = new MenuUi(&m_menuOrder);

	m_mapselect = new MapSelect;
}

void StageSelectUi::Uninit()
{
	m_menuUi->Uninit();

	delete m_menuUi;
	m_menuUi = nullptr;
}

void StageSelectUi::Update()
{
	if(CheckPauseMode::GetInstance()->CheckPause())
		m_menuUi->Update();
	else
	m_mapselect->Update();

}

void StageSelectUi::Draw()
{
	m_mapselect->Draw();

	if (CheckPauseMode::GetInstance()->CheckPause())
		m_menuUi->Draw();

	SetFontSize(FONT_SIZE / 2);
	DrawString(0, SCREEN_Y - 100, "■WS,↑↓:選択　■ENTER:決定　■ESC:メニュー", GetColor(255, 255, 255));
	SetFontSize(FONT_DEFAULT_SIZE);
}
