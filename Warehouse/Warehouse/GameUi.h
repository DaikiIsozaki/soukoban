#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

class GameUi
{
public:
	GameUi();
	~GameUi() = default;

	void Uninit();
	void Update();
	void Draw();

private:
	MenuUi* m_menuUi;
	menuOrder m_menuOrder;
	Steps* m_steps;
	MapName* m_mapname;
	MapSelect* m_mapselect;
	bool m_bPause = false;	////É|Å[ÉYîªíË//
};

