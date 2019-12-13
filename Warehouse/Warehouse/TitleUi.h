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
	TitleName* m_pName;
	MenuUi* m_menuUi;
	menuOrder m_menuOrder;
};

