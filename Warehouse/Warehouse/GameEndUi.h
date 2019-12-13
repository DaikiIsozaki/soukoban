#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

class GameEndUi
{
public:
	GameEndUi();
	~GameEndUi() = default;

	void Uninit();
	void Update();
	void Draw();

private:
	MenuUi* m_menuUi;
	menuOrder m_menuOrder;
	EndName* m_endName;
};

