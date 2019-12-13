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
#define	SCREEN_X			(1000)	//�X�N���[��X
#define SCREEN_Y			(600)	//�X�N���[��Y 
#define COLOR_DEPTH			(32)	//�F�[�x
#define INPUT_SIZE			(256)	
#define FONT_DEFAULT_SIZE	(17)	//�t�H���g�̃f�t�H���g�T�C�Y
#define OBJ_SIZE			(35)	//�I�u�W�F�N�g(�t�H���g)�̕�
#define MAP_MAX				(7)		//�}�b�v��

enum OBJTYPE
{
	NON				= 0x00,
	PLAYER			= 0x01,//�v���C���[
	BOX				= 0x02,//��
	WALL			= 0x03,//��
	DESTINATION		= 0x04,//�ړI�n
	THIRDWHEEL		= 0x05,//���ז���
	MAX_OBJTY
};

