#pragma once
//|*******|//
//|include|//
//|*******|//
#include"Scene.h"
//|*******|//
//|define |//
//|*******|//

class TitleScene :public Scene
{
public:
	TitleScene() ;
	~TitleScene() {};

	void Init(int mapNo);
	void Uninit();
	void Update();
	void Draw();
	SCENETYPE Get_Type()const { return SCENETYPE::TITLE; };

private:

};

