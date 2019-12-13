//|*******|//
//|include|//
//|*******|//
#include "Player.h"
#include"HitMove.h"
#include"KyeInput.h"
#include"main.h"
#include"ReportScore.h"

Player::Player()
{
	m_ghandle  = LoadGraph("asset/P.png");
	m_ghandle2 = LoadGraph("asset/P1.png");
	m_ghandle3 = LoadGraph("asset/P2.png");
}

Player::~Player()
{
	DeleteGraph(m_ghandle);
	DeleteGraph(m_ghandle2);
	DeleteGraph(m_ghandle3);
}

void Player::Init()
{
	
	m_steps = 0;
	ReportScore::GetInstance()->SetLife(LIFE);
}

void Player::Uninit()
{
	
}

void Player::Update()
{	
	//�ړ�����//
	if (Keyinput::Press('W')|| Keyinput::Press(VK_UP) /*&& _Frame%FRAME == 0*/)
	{
		HitMove::Get_Instance()->MoveThis(this, 0, -1);
	}

	if (Keyinput::Press('S') || Keyinput::Press(VK_DOWN))
	{
		
		HitMove::Get_Instance()->MoveThis(this, 0, 1);
	}

	if (Keyinput::Press('A') || Keyinput::Press(VK_LEFT))
	{
		HitMove::Get_Instance()->MoveThis(this, -1, 0);
	}

	if (Keyinput::Press('D') || Keyinput::Press(VK_RIGHT))
	{
		HitMove::Get_Instance()->MoveThis(this, 1, 0);
	}

	_OldPosX=_PositionX;
	_OldPosY=_PositionY;

}

void Player::Draw()
{
	if(ReportScore::GetInstance()->GetLife()==LIFE)
	DrawGraph(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, m_ghandle,TRUE);

	if (ReportScore::GetInstance()->GetLife() == 2)
		DrawGraph(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, m_ghandle2, TRUE);

	if (ReportScore::GetInstance()->GetLife() == 1)
		DrawGraph(_PositionX* OBJ_SIZE + _SizeX, _PositionY* OBJ_SIZE + _SizeY, m_ghandle3, TRUE);
}

void Player::Move(int move_x, int move_y)
{
	_PositionX += move_x;
	_PositionY += move_y;
	m_steps++;

	ReportScore::GetInstance()->SetPlayerSteps(m_steps);
}

void Player::Create(int x, int y, int sizeX, int sizeY)
{
	_PositionX = x;
	_PositionY = y;
	_SizeX = sizeX;
	_SizeY = sizeY;
}

void Player::Destroy()
{
}
