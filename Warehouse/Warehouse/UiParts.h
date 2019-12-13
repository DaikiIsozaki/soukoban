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
	virtual PARTSTYPE GetType()= 0;
	virtual void Create(int PosX, int PosY) = 0;
	virtual int GetPosX() = 0;
	virtual int GetPosY() = 0;

protected:
	int _X;////X座標//
	int _Y;////Y座標//
	int	_SizeX;////X位置調整用//
	int _SizeY;////Y位置調整用//

	int m_texhandle = 0;
};