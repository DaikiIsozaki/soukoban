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
#include"ResultScene.h"
#include "Manager.h"
#include"KyeInput.h"
#include "GameLoop.h"
#include"main.h"

GameLoop* GameLoop::instance = nullptr;

HWND hWnd;

void GameLoop::Create()
{
	if (instance == nullptr)
	{
		instance =new GameLoop;
	}
}

void GameLoop::Delete()
{
	
	if (instance != nullptr)
	{
		delete instance;
	}
}

void GameLoop::Loop()
{
	Manager::InstanceCreate();
	Init();

	do
	{
		ClearDrawScreen();//裏画面を消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		//更新
		Update();

		//描画
		Draw();

		ScreenFlip();//裏画面を表画面にコピー

		if (Manager::GetInstance()->GetEndflag())
		{
			/*if (MessageBox(hWnd, "終了しますか？", "Exit", MB_YESNO) == IDYES)
				break;
			else
				Manager::GetInstance()->SetEndflag(false);
				continue;*/
			break;
		}
	}while (ProcessMessage() == 0);

	Uninit();
	Manager::InstanceDelete();

	
}

void GameLoop::Init()
{
	hWnd = GetMainWindowHandle();
	Manager::GetInstance()->Init();
}

void GameLoop::Uninit()
{
	Manager::GetInstance()->Uninit();

}

void GameLoop::Update()
{
	Keyinput::Update();
	Manager::GetInstance()->Update();
}

void GameLoop::Draw()
{
	Manager::GetInstance()->Draw();
}
