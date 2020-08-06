//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include "HitMove.h"
#include"ObjectManager.h"
#include"MapCreate.h"
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
#include "GameEndUi.h"
#include"UiManager.h"
#include"Scene.h"
#include"TitleScene.h"
#include "Manager.h"
#include"KyeInput.h"
#include"ReportMenuStatus.h"
#include"ReportMapNumber.h"
#include"main.h"

Manager* Manager::m_instance = nullptr;

Manager::Manager()
{
	UiManager::InstanceCreate();
	ObjectManager::InstanceCreate();
	m_scene = new TitleScene;
}

void Manager::InstanceCreate()
{
	if (m_instance == nullptr)
		m_instance = new Manager;
}

void Manager::InstanceDelete()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

void Manager::Init()
{
	ReportMenuStatus::InstanceCrearte();
	ReportMapNumber::InstanceCrearte();
	CheckPauseMode::InstanceCrearte();
	m_scene->Init(m_mapNomber);
}

void Manager::Uninit()
{
	m_scene->Uninit();	
	UiManager::InstanceDelete();
	ObjectManager::InstanceDelete();
	ReportMapNumber::InstanceDelete();
	CheckPauseMode::InstanceDelete();
	ReportScore::InstanceDelete();
	ReportMenuStatus::InstanceDelete();
}

void Manager::Update()
{
	CheckPauseMode::GetInstance()->Update();
	m_scene->Update();
}

void Manager::Draw()
{
	m_scene->Draw();
}

void Manager::SceneChange(Scene* nextScene)
{
	if (m_scene)
	{
		m_scene->Uninit();
		delete m_scene;
		m_scene = nullptr;
		m_scene = nextScene;
		m_scene->Init(m_mapNomber);
		ReportMapNumber::GetInstance()->SetNumber(m_mapNomber);
		
	}
}
