//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include "CheckPauseMode.h"
#include"KyeInput.h"

CheckPauseMode* CheckPauseMode::m_pInstance = nullptr;

void CheckPauseMode::InstanceCrearte()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new CheckPauseMode;
	}
}

void CheckPauseMode::InstanceDelete()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CheckPauseMode::Update()
{
	if (Keyinput::Press(VK_ESCAPE))
	{
		if (m_bCheck)
			m_bCheck = false;
		else
		m_bCheck = true;
	}
}

bool CheckPauseMode::CheckPause()
{
	return m_bCheck;
}
