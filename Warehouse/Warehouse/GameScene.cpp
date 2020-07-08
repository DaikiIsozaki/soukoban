//|*******|//
//|include|//
//|*******|//

#include"Object.h"
#include "HitMove.h"
#include"ObjectManager.h"
#include"MapCreate.h"
#include "GameScene.h"
#include"TitleScene.h"
#include"ResultScene.h"
#include "StageSelectScene.h"
#include"GameEndScene.h"
#include"Manager.h"
#include"ReportScore.h"
#include"ReportMapNumber.h"

GameScene::GameScene()
{
	HitMove::Get_Instance()->InstanceCreate();
	CheckPauseMode::GetInstance()->Reset();
	m_mapnumber = 0;

	for (int i = 0; i < MAP_MAX; i++)
		m_mapclear[i] = false;
	
}

GameScene::~GameScene()
{
	HitMove::Get_Instance()->InstanceDelete();
}

void GameScene::Init(int mapNo)
{
	m_wait = 1;

	_Map = new MapCreate;
	_Map->FileLoad(mapNo);

	m_mapnumber = mapNo;
	ReportMapNumber::GetInstance()->SetNumber(mapNo);

	ReportScore::InstanceCrearte();
	
	ObjectManager::Get_Instance()->Init();

	UiManager::GetInstance()->SetSceneType(GAME);
	UiManager::GetInstance()->Init();

	for (int i = 0; i < MAP_MAX; i++)
		if (!ReportMapNumber::GetInstance()->GetClearCheck(i)) return;
	
	for (int reset = 0; reset < MAP_MAX; reset++)
		ReportMapNumber::GetInstance()->SetClearCheck(reset,false);

	GameEndScene* nextscene = new GameEndScene;
	Manager::GetInstance()->SceneChange(nextscene);
}

void GameScene::Uninit()
{
	UiManager::GetInstance()->Uninit();
	ObjectManager::Get_Instance()->Uninit();

	delete _Map;
	_Map = nullptr;
}

void GameScene::Update()
{
	if (ReportMapNumber::GetInstance()->GetNomber() > MAP_MAX)
	{
		StageSelectScene* nextscene = new StageSelectScene;
		Manager::GetInstance()->SceneChange(nextscene);
	}

	UiManager::GetInstance()->Update();

	//‚±‚±‚©‚ç‰ºƒV[ƒ“Ø‚è‘Ö‚¦//
	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::RESET)
	{
		ReportScore::GetInstance()->SetPlayerSteps(0);
		CheckPauseMode::GetInstance()->Reset();
		ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);
		ReportScore::GetInstance()->Damage();
		ObjectManager::Get_Instance()->Reset();
		_Map->FileLoad(m_mapnumber);
	}

	else if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::BACK)
	{
		Scene* nextScene = new TitleScene;
		Manager::GetInstance()->SetMapNomber(0);
		Manager::GetInstance()->SceneChange(nextScene);
		return;
	}

	else if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::EXIT)
	{
		Manager::GetInstance()->SetEndflag(true);
		ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);
	}

	if (ReportScore::GetInstance()->GetLife() <= 0)
	{
		if (m_wait % 3 == 0)
		{
			ResultScene* nextScene = new ResultScene;
			Manager::GetInstance()->SceneChange(nextScene);
		}
		m_wait++;
	}

	if (ObjectManager::Get_Instance()->ClearCheck())
	{
		if (m_wait % 31 == 0)
		{	
			ReportMapNumber::GetInstance()->SetClearCheck(m_mapnumber - 1, true);
			ResultScene* nextScene = new ResultScene;
			Manager::GetInstance()->SceneChange(nextScene);
		}
		m_wait++;
	}

	if (!CheckPauseMode::GetInstance()->CheckPause())
		ObjectManager::Get_Instance()->Update();

}

void GameScene::Draw()
{
	ObjectManager::Get_Instance()->Draw();

	UiManager::GetInstance()->Draw();
}
