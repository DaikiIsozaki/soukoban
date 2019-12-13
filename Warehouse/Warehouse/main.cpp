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
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_X,SCREEN_Y,COLOR_DEPTH);//��ʃT�C�Y
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤��
	if (DxLib_Init() == 1)return -1;//���������s��

	//�摜�E���ǂݍ���//

	GameLoop::Create();

	GameLoop::Get_Instance()->Loop();

	GameLoop::Delete();


	DxLib_End();

	return 0;
}