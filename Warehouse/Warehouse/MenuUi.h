#pragma once
//|*******|//
//|include|//
//|*******|//

//|*******|//
//|define |//
//|*******|//

//�\�����郁�j���[�ꗗ true�Œ���
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

////���j���[//
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

	int m_choiceMenu=0;//���I�����Ă��郁�j���[
	std::vector<UiParts*> m_uipartsContainer;

	UiParts* m_parts;////���j���[�p�[�c�����p

	int m_cursorX = 0;////�J�[�\���pX//
	int m_cursorY = 0;////�J�[�\���pY//
	int m_sizeX   = 0;////X�ʒu�����p//
	int m_sizeY   = 0;////Y�ʒu�����p//

	int m_selectMenu = 0;
	int m_texhandle_cursor = 0;
};

