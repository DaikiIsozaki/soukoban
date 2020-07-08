//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include "HitMove.h"
#include"ObjectManager.h"
#include "TitleScene.h"
#include"StageSelectScene.h"
#include"Manager.h"



TitleScene::TitleScene()
{
}

void TitleScene::Init(int mapNo)
{
	ReportMenuStatus::InstanceCrearte();
	CheckPauseMode::GetInstance()->Reset();

	UiManager::GetInstance()->SetSceneType(TITLE);
	UiManager::GetInstance()->Init();	
}

void TitleScene::Uninit()
{
	UiManager::GetInstance()->Uninit();
}

void TitleScene::Update()
{
	UiManager::GetInstance()->Update();

	//‚±‚±‚©‚ç‰ºƒV[ƒ“Ø‚è‘Ö‚¦//
	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::START)
	{
		Scene* nextScene = new StageSelectScene;
		Manager::GetInstance()->SetMapNomber(0);
		Manager::GetInstance()->SceneChange(nextScene);
	}

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::EXIT)
	{
		Manager::GetInstance()->SetEndflag(true);
		ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);
	}
}

void TitleScene::Draw()
{
	UiManager::GetInstance()->Draw();
}
