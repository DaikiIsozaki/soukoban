#pragma once
//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include"ReportScore.h"

//|*******|//
//|define |//
//|*******|//
#define MAX_COLOR	(255)//色値の上限
#define FONT_SIZE	(40)//タイトル名のフォントサイズ

typedef struct
{
	int r = MAX_COLOR;
	int g = MAX_COLOR;
	int b = MAX_COLOR;
}RANDOMCOLOR;

////Uiインターフェース//
class UI
{
public:
	/*UI() {};
	~UI() {};*/

	virtual void Update() {};
	virtual void Draw() {};

protected:
	

	int m_posX=0;////X座標//
	int m_posY=0;////Y座標//
	int	m_sizeX = 0;////X位置調整用//
	int m_sizeY = 0;////Y位置調整用//

	RANDOMCOLOR m_randomcolor = { 0 };

	int m_fonthandle = 0;
};

