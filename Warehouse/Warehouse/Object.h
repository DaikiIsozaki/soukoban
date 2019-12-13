#pragma once
//|*******|//
//|include|//
//|*******|//
#include"main.h"

//|*******|//
//|define |//
//|*******|//




////Object�C���^�[�t�F�[�X//
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
	virtual void Create(int x,int y,int sizeX,int sizeY)=0;//�����ʒu�����߂�
	virtual void Destroy()=0;

	virtual int Get_PosX() = 0;
	virtual int Get_PosY() = 0;
	virtual int Get_OldPosX() { return _OldPosX; };
	virtual int Get_OldPosY() { return _OldPosY; };

	virtual bool GetHitbool() { return _bHit; };

	virtual OBJTYPE Get_Type() = 0;

protected:
	int _PositionX=0;//���W
	int _PositionY=0;//���W
	int _OldPosX = 0;//1�t���[���O�̍��W
	int _OldPosY = 0;//1�t���[���O�̍��W
	int _SizeX = 0;
	int _SizeY = 0;
	int _Speed=0;//���x
	int m_steps=0;//�ړ������Ƃ��ɃJ�E���g
	bool _bHit=false;



	
};
