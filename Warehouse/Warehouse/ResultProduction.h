#pragma once
//|*******|//
//|include|//
//|*******|//
#include "UI.h"

//|*******|//
//|define |//
//|*******|//

class ResultProduction:public UI
{
public:
	ResultProduction();
	~ResultProduction() { DeleteFontToHandle(m_fonthandle); };

	bool LifeCheck();
	void Update();
	void Draw();

private:
	

	std::string m_resultproduce = "����������\n��CLEAR!��\n����������";
	std::string m_resultproduce2 = "����������\n����  �s��\n����������";
	bool m_crearcheck=true;
	int frame = 0;
};

