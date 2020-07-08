#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//



class TitleUi
{
public:
	TitleUi();
	~TitleUi()=default;

	void Uninit();
	void Update();
	void Draw();

private:
	TitleName* m_pName=nullptr;
	MenuUi* m_menuUi=nullptr;
	menuOrder m_menuOrder = { false };
};

