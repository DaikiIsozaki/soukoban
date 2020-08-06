#pragma once
//|*******|//
//|include|//
//|*******|//
#include"Scene.h"
//|*******|//
//|define |//
//|*******|//


class StageSelectScene :public Scene
{
public:
	StageSelectScene();
	~StageSelectScene();

	void Init(int mapNo);
	void Uninit();
	void Update();
	void Draw();

	SCENETYPE Get_Type()const { return SCENETYPE::STAGESELECT; };

private:
	
};

