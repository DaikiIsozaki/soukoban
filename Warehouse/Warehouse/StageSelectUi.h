#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

class StageSelectUi
{
public:
	StageSelectUi();
	~StageSelectUi() {};

	void Uninit();
	void Update();
	void Draw();

private:
	MenuUi* m_menuUi;
	menuOrder m_menuOrder;
	MapSelect* m_mapselect;
};

