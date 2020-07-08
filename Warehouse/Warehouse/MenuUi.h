#pragma once
//|*******|//
//|include|//
//|*******|//

//|*******|//
//|define |//
//|*******|//

//表示するメニュー一覧 trueで注文
struct menuOrder
{
	bool Start = false;
	int StartPosX, StartPosY;

	bool Exit = false;
	int ExitPosX, ExitPosY;

	bool Back = false;
	int BackPosX, BackPosY;

	bool Reset = false;
	int ResetPosX, ResetPosY;

	bool Tutorial = false;
	int TutorialPosX, TutorialPosY;

	bool Next = false;
	int NextPosX, NextPosY;

	bool Retry = false;
	int RetryPosX, RetryPosY;

};

////メニュー//
class MenuUi
{
public:
	MenuUi(menuOrder* addparts);
	~MenuUi() {};

	void Uninit();
	void Update();
	void Draw();

	

private:
	void AddParts(UiParts* parts);
	void SetCursorPos(int x, int y);

	int m_choiceMenu=0;//今選択しているメニュー
	std::vector<UiParts*> m_uipartsContainer;

	UiParts* m_parts = nullptr;////メニューパーツ生成用

	int m_cursorX = 0;////カーソル用X//
	int m_cursorY = 0;////カーソル用Y//
	int m_sizeX   = 0;////X位置調整用//
	int m_sizeY   = 0;////Y位置調整用//

	int m_selectMenu = 0;
	int m_texhandle_cursor = 0;
};

