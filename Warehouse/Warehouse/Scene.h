#pragma once
//|*******|//
//|include|//
//|*******|//
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
#include"KyeInput.h"
#include"ReportMenuStatus.h"
#include"CheckPauseMode.h"

//|*******|//
//|define |//
//|*******|//


enum SCENETYPE
{
	TITLE,
	STAGESELECT,
	GAME,
	RESULT,
	END,
	MAX_SCENE
};

//Sceneインターフェース
class Scene
{
public:
	//Scene() {};
	//~Scene() {};

	virtual void Init(int mapNo) = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw()=0;
	virtual SCENETYPE Get_Type()const = 0;

protected:
	
	
};
