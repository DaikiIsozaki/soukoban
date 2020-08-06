#pragma once

class Keyinput
{
public:
	Keyinput(){};
	~Keyinput() {};

	static void Update();
	static bool Press(int keyinput);
	static bool LongPress(int keyinput);
	static bool Release(int keyinput);

private:
	static BYTE m_buff[INPUT_SIZE];
	static BYTE m_oldBuff[INPUT_SIZE];
};

