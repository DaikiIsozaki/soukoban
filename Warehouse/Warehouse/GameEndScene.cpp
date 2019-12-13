//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include "HitMove.h"
#include"ObjectManager.h"
#include "GameEndScene.h"
#include"Manager.h"
#include"TitleScene.h"

GameEndScene::GameEndScene()
{
}

void GameEndScene::Init(int mapNo)
{

	UiManager::GetInstance()->SetSceneType(END);
	UiManager::GetInstance()->Init();
}

void GameEndScene::Uninit()
{
	UiManager::GetInstance()->Uninit();
	
}

void GameEndScene::Update()
{
	UiManager::GetInstance()->Update();

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::BACK)
	{
		Scene* nextScene = new TitleScene;
		Manager::GetInstance()->SetMapNomber(0);
		Manager::GetInstance()->SceneChange(nextScene);
		return;
	}
}

void GameEndScene::Draw()
{
	UiManager::GetInstance()->Draw();
}
