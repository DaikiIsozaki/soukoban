#pragma once
//|*******|//
//|include|//
//|*******|//
#include"Scene.h"
//|*******|//
//|define |//
//|*******|//

class GameScene :public Scene
{
public:
	GameScene() ;
	~GameScene();

	void Init(int mapNo);
	void Uninit();
	void Update();
	void Draw();
	SCENETYPE Get_Type()const { return GAME; };

private:
	MapCreate* _Map;

	int m_wait = 1;////�N���A���̃X�g�b�v�Ɏg��//

	int m_mapnumber;
	int m_mapclear[MAP_MAX];


};

