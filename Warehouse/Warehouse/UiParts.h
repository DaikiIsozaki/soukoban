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
	virtual PARTSTYPE GetType()= 0;					//タイプのゲッター
	virtual void Create(int PosX, int PosY) = 0;	
	virtual int GetPosX() = 0;
	virtual int GetPosY() = 0;

protected:
	int m_posX = 0;////X座標//
	int m_posY = 0;////Y座標//
	int	m_sizeX = 0;////X位置調整用//
	int m_sizeY = 0;////Y位置調整用//

	int m_texhandle = 0;
};