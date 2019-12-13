#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//


class CheckPauseMode
{
public:
	CheckPauseMode(const CheckPauseMode&) = delete;
	CheckPauseMode& operator=(const CheckPauseMode&) = delete;
	CheckPauseMode(const CheckPauseMode&&) = delete;
	CheckPauseMode& operator=(const CheckPauseMode&&) = delete;

	static void InstanceCrearte();
	static void InstanceDelete();

	void Update();
	bool CheckPause();
	void Reset() { m_bCheck = false; };

	static CheckPauseMode* GetInstance() { return m_pInstance; };

private:
	static CheckPauseMode* m_pInstance;

	CheckPauseMode() {};
	~CheckPauseMode()=default;
	bool m_bCheck=false;
};

