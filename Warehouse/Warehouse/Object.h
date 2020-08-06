#pragma once
//|*******|//
//|include|//
//|*******|//
#include"main.h"

//|*******|//
//|define |//
//|*******|//




////Objectインターフェース//
class Object
{
public:
	/*Object():_bHit(false) {};
	~Object() {};*/

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() {};
	virtual void Move(int move_x,int move_y) = 0;
	virtual void Create(int x,int y,int sizeX,int sizeY)=0;//生成位置を決める
	virtual void Destroy()=0;

	virtual int Get_PosX() = 0;
	virtual int Get_PosY() = 0;
	virtual int Get_OldPosX() { return m_oldPosX; };
	virtual int Get_OldPosY() { return m_oldPosY; };

	virtual bool GetHitbool() { return m_bHit; };

	virtual OBJTYPE Get_Type() = 0;

protected:
	int m_positionX=0;//座標
	int m_positionY=0;//座標
	int m_oldPosX = 0;//1フレーム前の座標
	int m_oldPosY = 0;//1フレーム前の座標
	int m_sizeX = 0;
	int m_sizeY = 0;
	int m_speed=0;//速度
	int m_steps=0;//移動したときにカウント
	bool m_bHit=false;



	
};
