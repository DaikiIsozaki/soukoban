#pragma once
//|*******|//
//|include|//
//|*******|//
#include "UI.h"

//|*******|//
//|define |//
//|*******|//


////ステップ数に加えてライフも一緒に表示する//
class Steps :public UI
{
public:
	Steps();
	~Steps() { DeleteFontToHandle(m_fonthandle); };

	void Update()override;
	void Draw()override;
	void Create(int x, int y,bool result);

private:
	
	////歩数表示//
	std::string m_steps_player	= "ステップ数:";
	std::string m_stepsnum_player;
	////残気表示//
	std::string m_life_player	= "ライフ　:";
	std::string m_lifenum_player;

	
};

