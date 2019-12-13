#pragma once
//|*******|//
//|include|//
//|*******|//
#include"Scene.h"
//|*******|//
//|define |//
//|*******|//

class GameEndScene :public Scene
{
public:
	GameEndScene();
	~GameEndScene() {};

	void Init(int mapNo);
	void Uninit();
	void Update();
	void Draw();
	SCENETYPE Get_Type()const { return END; };
};

