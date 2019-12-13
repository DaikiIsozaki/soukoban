//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include "HitMove.h"
#include"ObjectManager.h"
#include "StageSelectScene.h"
#include"Manager.h"
#include"TitleScene.h"
#include"MapCreate.h"
#include"GameScene.h"
#include"MapSelect.h"
#include"ReportScore.h"
#include"ReportMapNumber.h"

StageSelectScene::StageSelectScene()
{
	CheckPauseMode::GetInstance()->Reset();
}

StageSelectScene::~StageSelectScene()
{ 
}

void StageSelectScene::Init(int mapNo)
{
	UiManager::GetInstance()->SetSceneType(STAGESELECT);
	UiManager::GetInstance()->Init();
}

void StageSelectScene::Uninit()
{
	UiManager::GetInstance()->Uninit();
	
}

void StageSelectScene::Update()
{
	UiManager::GetInstance()->Update();

	if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::BACK)
	{
		Scene* nextScene = new TitleScene;
		Manager::GetInstance()->SetMapNomber(0);
		Manager::GetInstance()->SceneChange(nextScene);
	}

	else if (ReportMenuStatus::GetInstance()->GetMenuStatus() == (int)PARTSTYPE::EXIT)
	{
		Manager::GetInstance()->SetEndflag(true);
		ReportMenuStatus::GetInstance()->SetMenuStatus((int)PARTSTYPE::NO);
	}

	else if (Keyinput::Press(VK_RETURN))
	{
		Scene* nextscene = new GameScene;
		Manager::GetInstance()->SetMapNomber(ReportMapNumber::GetInstance()->GetNomber());
		Manager::GetInstance()->SceneChange(nextscene);
		CheckPauseMode::GetInstance()->Reset();
	}

}

void StageSelectScene::Draw()
{
	UiManager::GetInstance()->Draw();
}
