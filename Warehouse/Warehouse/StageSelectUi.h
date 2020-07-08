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
	MenuUi* m_menuUi = nullptr;
	menuOrder m_menuOrder = { false };
	MapSelect* m_mapselect = nullptr;
};

