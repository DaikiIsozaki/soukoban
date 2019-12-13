#pragma once

#define _CRT_SECURE_NO_WARNINGS

//|*******|//
//|include|//
//|*******|//
#include "DxLib.h"
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include <algorithm>
#include <ctime>




//|*******|//
//|define |//
//|*******|//
#define	SCREEN_X			(1000)	//スクリーンX
#define SCREEN_Y			(600)	//スクリーンY 
#define COLOR_DEPTH			(32)	//色深度
#define INPUT_SIZE			(256)	
#define FONT_DEFAULT_SIZE	(17)	//フォントのデフォルトサイズ
#define OBJ_SIZE			(35)	//オブジェクト(フォント)の幅
#define MAP_MAX				(7)		//マップ数

enum OBJTYPE
{
	NON				= 0x00,
	PLAYER			= 0x01,//プレイヤー
	BOX				= 0x02,//箱
	WALL			= 0x03,//壁
	DESTINATION		= 0x04,//目的地
	THIRDWHEEL		= 0x05,//お邪魔虫
	MAX_OBJTY
};

