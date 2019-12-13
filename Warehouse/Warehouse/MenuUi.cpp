//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include"UI.h"
#include"TitleName.h"
#include"UiParts.h"
#include "Start.h"
#include "Exit.h"
#include "Reset.h"
#include"Next.h"
#include "Back.h"
#include"Retry.h"
#include "MenuUi.h"
#include"KyeInput.h"
#include"ReportMenuStatus.h"


MenuUi::MenuUi(menuOrder* addparts)
{
	if (addparts->Start)
	{
		m_parts = new Start;
		m_parts->Create(addparts->StartPosX, addparts->StartPosY);
		AddParts(m_parts);
	}

	if (addparts->Reset)
	{
		m_parts = new Reset;
		m_parts->Create(addparts->ResetPosX, addparts->ResetPosY);
		AddParts(m_parts);
	}

	if (addparts->Tutorial)
	{

	}

	if (addparts->Retry)
	{
		m_parts = new Retry;
		m_parts->Create(addparts->RetryPosX, addparts->RetryPosY);
		AddParts(m_parts);
	}

	if (addparts->Next)
	{
		m_parts = new Next;
		m_parts->Create(addparts->NextPosX, addparts->NextPosY);
		AddParts(m_parts);
	}

	if (addparts->Back)
	{
		m_parts = new Back;
		m_parts->Create(addparts->BackPosX, addparts->BackPosY);
		AddParts(m_parts);
	}

	if (addparts->Exit)
	{
		m_parts = new Exit;
		m_parts->Create(addparts->ExitPosX, addparts->ExitPosY);
		AddParts(m_parts);
	}

	m_texhandle_cursor = LoadGraph("asset/Cursor.png");
	SetCursorPos(m_uipartsContainer[0]->GetPosX()-1, 1);
}

void MenuUi::Uninit()
{
	ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);

	for (auto ui : m_uipartsContainer)
	{
		delete ui;
		ui = nullptr;
	}
	m_parts = nullptr;
	m_uipartsContainer.clear();
	
}

void MenuUi::Update()
{
	if ((Keyinput::Press('W') || Keyinput::Press(VK_UP))&&m_cursorY>m_uipartsContainer[0]->GetPosY())
	{
		m_choiceMenu--;
	}

	if ((Keyinput::Press('S') || Keyinput::Press(VK_DOWN)) && m_cursorY < m_uipartsContainer.back()->GetPosY())
	{
		m_choiceMenu++;
	}
	m_cursorX = m_uipartsContainer[m_choiceMenu]->GetPosX()-1;
	m_cursorY = m_uipartsContainer[m_choiceMenu]->GetPosY();

	if (Keyinput::Press(VK_RETURN))
	{
		switch (m_uipartsContainer[m_choiceMenu]->GetType())
		{
		case PARTSTYPE::START:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::START);
			break;

		case PARTSTYPE::EXIT:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::EXIT);
			break;

		case PARTSTYPE::RESET:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::RESET);
			break;

		case PARTSTYPE::NEXT:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NEXT);
			break;

		case PARTSTYPE::BACK:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::BACK);
			break;

		case PARTSTYPE::RETRY:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::RETRY);
			break;

		default:
			ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);
			break;

		};
	}
}

void MenuUi::Draw()
{
	for (auto parts : m_uipartsContainer)
	{
		parts->Draw();
	}


	DrawGraph((m_cursorX* OBJ_SIZE + m_sizeX)-90, (m_cursorY* OBJ_SIZE + m_sizeY) - 10, m_texhandle_cursor, TRUE);
}

void MenuUi::AddParts(UiParts * parts)
{
	m_uipartsContainer.push_back(parts);
}

void MenuUi::SetCursorPos(int x, int y)
{
	m_cursorX = x;
	m_cursorY = y;
	m_sizeX = (SCREEN_X - 64) / 2;
	m_sizeY = (SCREEN_Y - 32) / 2;
}

