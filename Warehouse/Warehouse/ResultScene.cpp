//|*******|//
//|include|//
//|*******|//

#include"Object.h"
#include "HitMove.h"
#include"ObjectManager.h"
#include "ResultScene.h"
#include"TitleScene.h"
#include"MapCreate.h"
#include"GameScene.h"
#include"Manager.h"
#include"ReportScore.h"

ResultScene::ResultScene()
{
	CheckPauseMode::GetInstance()->Reset();
}

void ResultScene::Init(int mapNo)
{
	

	UiManager::GetInstance()->SetSceneType(RESULT);
	UiManager::GetInstance()->Init();
}

void ResultScene::Uninit()
{
	UiManager::GetInstance()->Uninit();
	
	ReportScore::GetInstance()->SetPlayerSteps(0);
}

void ResultScene::Update()
{
	UiManager::GetInstance()->Update();

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::EXIT)
	{
		Manager::GetInstance()->SetEndflag(true);
		ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);
	}

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::NEXT)
	{
		Scene* nextScene = new GameScene;
		Manager::GetInstance()->NextMapSelect();
		Manager::GetInstance()->SceneChange(nextScene);
	}

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::BACK)
	{
		Scene* nextScene = new TitleScene;
		Manager::GetInstance()->SetMapNomber(0);
		Manager::GetInstance()->SceneChange(nextScene);
		return;
	}

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::RETRY)
	{
		Scene* nextScene = new GameScene;
		Manager::GetInstance()->SceneChange(nextScene);
		return;
	}

}

void ResultScene::Draw()
{
	UiManager::GetInstance()->Draw();
}
