//|*******|//
//|include|//
//|*******|//
#include"UI.h"
#include"TitleName.h"
#include"Steps.h"
#include"EndName.h"
#include "MapName.h"
#include"UiParts.h"
#include"MenuUi.h"
#include"TitleUi.h"
#include"MapSelect.h"
#include "StageSelectUi.h"
#include"GameUi.h"
#include"ResultProduction.h"
#include"ResultUi.h"
#include"GameEndUi.h"
#include "UiManager.h"
#include"Scene.h"
#include"main.h"


UiManager* UiManager::m_instance = nullptr;

void UiManager::InstanceCreate()
{
	if (m_instance == nullptr)
	{
		m_instance = new UiManager;
	}
}

void UiManager::InstanceDelete()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

void UiManager::Init()
{
	switch (m_sceneType)
	{
	case TITLE:
		m_titleUi = new TitleUi;
		break;

	case STAGESELECT:
		m_stageSelectUi = new StageSelectUi;
		break;

	case GAME:
		m_gameUi = new GameUi;
		break;

	case RESULT:
		m_resultUi = new ResultUi;
		break;

	case  END:
		m_gameendUi = new GameEndUi;
		break;
	}
}

void UiManager::Uninit()
{
	switch (m_sceneType)
	{
	case TITLE:
		m_titleUi->Uninit();
		break;

	case STAGESELECT:
		m_stageSelectUi->Uninit();
		break;

	case GAME:
		m_gameUi->Uninit();
		break;

	case RESULT:
		m_resultUi->Uninit();
		break;

	case END:
		m_gameendUi->Uninit();
		break;
	}
}

void UiManager::Update()
{
	switch (m_sceneType)
	{
	case TITLE:
		m_titleUi->Update();
		break;

	case STAGESELECT:
		m_stageSelectUi->Update();
		break;

	case GAME:
		m_gameUi->Update();
		break;

	case RESULT:
		m_resultUi->Update();
		break;

	case END:
		m_gameendUi->Update();
		break;

	}
}

void UiManager::Draw()
{
	switch (m_sceneType)
	{
	case TITLE:
		m_titleUi->Draw();
		break;

	case STAGESELECT:
		m_stageSelectUi->Draw();
		break;

	case GAME:
		m_gameUi->Draw();
		break;

	case RESULT:
		m_resultUi->Draw();
		break;
	
	case END:
		m_gameendUi->Draw();
		break;
	}
}