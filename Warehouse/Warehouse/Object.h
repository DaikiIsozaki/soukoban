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
	virtual int Get_OldPosX() { return _OldPosX; };
	virtual int Get_OldPosY() { return _OldPosY; };

	virtual bool GetHitbool() { return _bHit; };

	virtual OBJTYPE Get_Type() = 0;

protected:
	int _PositionX=0;//座標
	int _PositionY=0;//座標
	int _OldPosX = 0;//1フレーム前の座標
	int _OldPosY = 0;//1フレーム前の座標
	int _SizeX = 0;
	int _SizeY = 0;
	int _Speed=0;//速度
	int m_steps=0;//移動したときにカウント
	bool _bHit=false;



	
};
