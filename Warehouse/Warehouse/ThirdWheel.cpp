//|*******|//
//|include|//
//|*******|//
#include "ThirdWheel.h"
#include"HitMove.h"
#include"main.h"


ThirdWheel::ThirdWheel()
{
	m_ghandle = LoadGraph("asset/Box.png");
}

void ThirdWheel::Init()
{
	std::srand(std::time(nullptr));//ãNìÆéûñàâÒÉâÉìÉ_ÉÄÇ…Ç»ÇÈÇÊÇ§Ç…
}

void ThirdWheel::Uninit()
{
}

void ThirdWheel::Update()
{
	m_fidgeting_frame++;

	if (m_fidgeting_frame % 111== 0)
	{
		std::random_device seed_gen;
		std::default_random_engine engine(seed_gen());

		std::uniform_int_distribution<> dist(-4, 4);

		m_fidgetingX = dist(engine);
		m_fidgetingY = dist(engine);
	}
	
	if (m_fidgeting_frame % 117 == 0)
	{
		m_fidgetingX = m_fidgetingY = 0;
		m_fidgeting_frame = 0;


	}
}

void ThirdWheel::Draw()
{
	DrawGraph((_PositionX* OBJ_SIZE + _SizeX)+m_fidgetingX, (_PositionY* OBJ_SIZE + _SizeY)+m_fidgetingY, m_ghandle, FALSE);
}

void ThirdWheel::Move(int move_x, int move_y)
{
	//óêêîÇŸÇºÇÒÇÊÇ§
	int x = 0;
	int y = 0;
	_OldPosX = _PositionX;
	_OldPosY = _PositionY;
	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());
	std::uniform_int_distribution<> dist(-1, 1);

	if (HitMove::Get_Instance()->MoveOther(this, move_x, move_y))
	{
		_PositionX += move_x;
		_PositionY += move_y;

		if (HitMove::Get_Instance()->Hit(this))
		{
			x = dist(engine);
			y = dist(engine);
			if (HitMove::Get_Instance()->MoveOther(this, x, y))
			{
				_PositionX += x;
				_PositionY += y;
			}
			else
			{
				_PositionX -= x;
				_PositionY -= y;
			}
		}
	}

	if (HitMove::Get_Instance()->Hit(this))
	{
		_PositionX = _OldPosX;
		_PositionY = _OldPosY;
	}
}

void ThirdWheel::Create(int x, int y, int sizeX, int sizeY)
{
	_PositionX = x;
	_PositionY = y;
	_SizeX = sizeX;
	_SizeY = sizeY;
}

void ThirdWheel::Destroy()
{
}
