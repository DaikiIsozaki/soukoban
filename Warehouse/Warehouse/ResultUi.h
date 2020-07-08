#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

class ResultUi
{
public:
	ResultUi();
	~ResultUi() = default;

	void Uninit();
	void Update();
	void Draw();

private:
	MenuUi* m_menuUi=nullptr;
	menuOrder m_menuOrder = { false };
	Steps* m_steps = nullptr;
	ResultProduction* m_resultpro = nullptr;
};

