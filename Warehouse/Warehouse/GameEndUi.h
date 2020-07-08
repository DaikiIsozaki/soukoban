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
	MenuUi* m_menuUi = nullptr;
	menuOrder m_menuOrder = { false };
	EndName* m_endName = nullptr;
};

