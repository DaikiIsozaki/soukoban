#pragma once
//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include"ReportScore.h"

//|*******|//
//|define |//
//|*******|//
#define MAX_COLOR	(255)//�F�l�̏��
#define FONT_SIZE	(40)//�^�C�g�����̃t�H���g�T�C�Y

typedef struct
{
	int r = MAX_COLOR;
	int g = MAX_COLOR;
	int b = MAX_COLOR;
}RANDOMCOLOR;

////Ui�C���^�[�t�F�[�X//
class UI
{
public:
	/*UI() {};
	~UI() {};*/

	virtual void Update() {};
	virtual void Draw() {};

protected:
	

	int _X=0;////X���W//
	int _Y=0;////Y���W//
	int	_SizeX = 0;////X�ʒu�����p//
	int _SizeY = 0;////Y�ʒu�����p//

	RANDOMCOLOR m_randomcolor;

	int m_fonthandle = 0;
};

