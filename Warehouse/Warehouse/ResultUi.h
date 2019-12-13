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
	MenuUi* m_menuUi;
	menuOrder m_menuOrder;
	Steps* m_steps;
	ResultProduction* m_resultpro;
};

