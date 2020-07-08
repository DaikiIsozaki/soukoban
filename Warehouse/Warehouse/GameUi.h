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
	MenuUi* m_menuUi = nullptr;
	menuOrder m_menuOrder = {false};
	Steps* m_steps = nullptr;
	MapName* m_mapname = nullptr;
	MapSelect* m_mapselect = nullptr;
	bool m_bPause = false;	////É|Å[ÉYîªíË//
};

