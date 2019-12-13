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
#include "Manager.h"
#include"KyeInput.h"
#include "GameLoop.h"
#include"main.h"


//WinMain//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(SCREEN_X,SCREEN_Y,COLOR_DEPTH);//画面サイズ
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように
	if (DxLib_Init() == 1)return -1;//初期化失敗時

	//画像・音読み込み//

	GameLoop::Create();

	GameLoop::Get_Instance()->Loop();

	GameLoop::Delete();


	DxLib_End();

	return 0;
}