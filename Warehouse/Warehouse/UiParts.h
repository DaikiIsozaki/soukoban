#pragma once
//|*******|//
//|include|//
//|*******|//
#include"main.h"

//|*******|//
//|define |//
//|*******|//
#define PARTS_POS_X		(6)
#define TEX_X			(192)
#define TEX_Y			(52)

enum struct PARTSTYPE
{
	NO,
	START,
	EXIT,
	RESET,
	NEXT,
	BACK,
	RETRY,
	MAX
};

class UiParts
{
public:

	virtual void Draw()=0;
	virtual PARTSTYPE GetType()= 0;					//�^�C�v�̃Q�b�^�[
	virtual void Create(int PosX, int PosY) = 0;	
	virtual int GetPosX() = 0;
	virtual int GetPosY() = 0;

protected:
	int _X = 0;////X���W//
	int _Y = 0;////Y���W//
	int	_SizeX = 0;////X�ʒu�����p//
	int _SizeY = 0;////Y�ʒu�����p//

	int m_texhandle = 0;
};