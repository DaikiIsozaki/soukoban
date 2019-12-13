//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include "KyeInput.h"

BYTE Keyinput::Buff[INPUT_SIZE] = {};
BYTE Keyinput::Old_Buff[INPUT_SIZE] = {};

void Keyinput::Update()
{
	memcpy(Old_Buff, Buff, sizeof(BYTE)*INPUT_SIZE);
	GetKeyboardState(Buff);
}

bool Keyinput::Press(int keyinput)
{
	if (!(Old_Buff[keyinput]&0x80)&&Buff[keyinput]&0x80)
		return true;
	else
		return false;
}

bool Keyinput::LongPress(int keyinput)
{
	if ((Old_Buff[keyinput] & 0x80) && Buff[keyinput] & 0x80)
		return true;
	else
	return false;
}

bool Keyinput::Release(int keyinput)
{
	if ((Old_Buff[keyinput] & 0x80) &&!( Buff[keyinput] & 0x80))
		return true;
	else
	return false;
}
