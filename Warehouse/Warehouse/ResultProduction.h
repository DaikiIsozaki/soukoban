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
	

	std::string m_resultproduce = "Å°Å°Å°Å°Å°\nÅ°CLEAR!Å°\nÅ°Å°Å°Å°Å°";
	std::string m_resultproduce2 = "Å°Å°Å°Å°Å°\nÅ°é∏  îsÅ°\nÅ°Å°Å°Å°Å°";
	bool m_crearcheck=true;
	int frame = 0;
};

