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
		ClearDrawScreen();//����ʂ�����
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		//�X�V
		Update();

		//�`��
		Draw();

		ScreenFlip();//����ʂ�\��ʂɃR�s�[

		if (Manager::GetInstance()->GetEndflag())
		{
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
