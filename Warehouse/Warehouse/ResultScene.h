#pragma once
//|*******|//
//|include|//
//|*******|//
#include"Scene.h"
//|*******|//
//|define |//
//|*******|//

class ResultScene :public Scene
{
public:
	ResultScene() ;
	~ResultScene() {};

	void Init(int mapNo);
	void Uninit();
	void Update();
	void Draw();
	SCENETYPE Get_Type()const { return RESULT; };

};

