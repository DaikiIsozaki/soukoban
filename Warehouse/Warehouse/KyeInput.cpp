//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include "KyeInput.h"

BYTE Keyinput::m_buff[INPUT_SIZE] = {};
BYTE Keyinput::m_oldBuff[INPUT_SIZE] = {};

void Keyinput::Update()
{
	memcpy(m_oldBuff, m_buff, sizeof(BYTE)*INPUT_SIZE);
	GetKeyboardState(m_buff);
}

bool Keyinput::Press(int keyinput)
{
	if (!(m_oldBuff[keyinput]&0x80)&&m_buff[keyinput]&0x80)
		return true;
	else
		return false;
}

bool Keyinput::LongPress(int keyinput)
{
	if ((m_oldBuff[keyinput] & 0x80) && m_buff[keyinput] & 0x80)
		return true;
	else
	return false;
}

bool Keyinput::Release(int keyinput)
{
	if ((m_oldBuff[keyinput] & 0x80) &&!( m_buff[keyinput] & 0x80))
		return true;
	else
	return false;
}
