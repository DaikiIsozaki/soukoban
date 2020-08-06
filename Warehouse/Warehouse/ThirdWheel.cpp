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
	DrawGraph((m_positionX* OBJ_SIZE + m_sizeX)+m_fidgetingX, (m_positionY* OBJ_SIZE + m_sizeY)+m_fidgetingY, m_ghandle, FALSE);
}

void ThirdWheel::Move(int move_x, int move_y)
{
	//óêêîÇŸÇºÇÒÇÊÇ§
	int x = 0;
	int y = 0;
	m_oldPosX = m_positionX;
	m_oldPosY = m_positionY;
	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());
	std::uniform_int_distribution<> dist(-1, 1);

	if (HitMove::Get_Instance()->MoveOther(this, move_x, move_y))
	{
		m_positionX += move_x;
		m_positionY += move_y;

		if (HitMove::Get_Instance()->Hit(this))
		{
			x = dist(engine);
			y = dist(engine);
			if (HitMove::Get_Instance()->MoveOther(this, x, y))
			{
				m_positionX += x;
				m_positionY += y;
			}
			else
			{
				m_positionX -= x;
				m_positionY -= y;
			}
		}
	}

	if (HitMove::Get_Instance()->Hit(this))
	{
		m_positionX = m_oldPosX;
		m_positionY = m_oldPosY;
	}
}

void ThirdWheel::Create(int x, int y, int sizeX, int sizeY)
{
	m_positionX = x;
	m_positionY = y;
	m_sizeX = sizeX;
	m_sizeY = sizeY;
}

void ThirdWheel::Destroy()
{
}
