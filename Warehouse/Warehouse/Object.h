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
	virtual int Get_OldPosX() { return m_oldPosX; };
	virtual int Get_OldPosY() { return m_oldPosY; };

	virtual bool GetHitbool() { return m_bHit; };

	virtual OBJTYPE Get_Type() = 0;

protected:
	int m_positionX=0;//���W
	int m_positionY=0;//���W
	int m_oldPosX = 0;//1�t���[���O�̍��W
	int m_oldPosY = 0;//1�t���[���O�̍��W
	int m_sizeX = 0;
	int m_sizeY = 0;
	int m_speed=0;//���x
	int m_steps=0;//�ړ������Ƃ��ɃJ�E���g
	bool m_bHit=false;



	
};
