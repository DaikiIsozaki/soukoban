#pragma once
//|*******|//
//|include|//
//|*******|//
#include "Object.h"

//|*******|//
//|define |//
//|*******|//
#define LIFE	(3)////リセットするたびにライフが1減る


class Player :public Object
{
public:
	Player();
	~Player();

	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Move(int move_x, int move_y);
	void Create(int x, int y, int sizeX, int sizeY);
	void Destroy();
	
	int Get_Life() const { return m_life; };
	int Get_Step() const { return m_steps; };


	int Get_PosX(){ return _PositionX; };
	int Get_PosY(){ return _PositionY; };
	int Get_OldPosX(){return _OldPosX;};
	int Get_OldPosY(){return _OldPosY;};



	OBJTYPE Get_Type() { return PLAYER; };

private:
	int m_life = 0;
	int m_ghandle = 0;
	int m_ghandle2 = 0;
	int m_ghandle3 = 0;
	
};										 

