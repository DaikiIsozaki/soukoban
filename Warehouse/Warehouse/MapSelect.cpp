//|*******|//
//|include|//
//|*******|//
#include"main.h"
#include "MapSelect.h"
#include"KyeInput.h"
#include"ReportMapNumber.h"

void MapSelect::Update()
{
	if (Keyinput::Press('W') || Keyinput::Press(VK_UP))
	{
		m_selectmapnum++;
		if (m_selectmapnum > MAP_MAX)
			m_selectmapnum = MAP_MAX;
	}

	if (Keyinput::Press('S') || Keyinput::Press(VK_DOWN))
	{
		m_selectmapnum--;
		if (m_selectmapnum <= 0)
			m_selectmapnum = 1;

	}
	m_mapselectnumber = std::to_string(m_selectmapnum);

	ReportMapNumber::GetInstance()->SetNumber(m_selectmapnum);
}

void MapSelect::Draw()
{
	std::string mapnumber = "�}�b�v�i���o�[:";
	m_x = ((SCREEN_X - (int)mapnumber.length()) / 2)-50;
	DrawString(m_x, (SCREEN_Y/2),(mapnumber+m_mapselectnumber).c_str(),GetColor(255, 255, 255) );
	MapExplanation();
}

void MapSelect::MapExplanation()
{
	int mapnom = 0;
	int b = 0;//�u���[
	int g = 0;//�O���[��

	mapnom = ReportMapNumber::GetInstance()->GetNomber();

	if (mapnom == 1)
		m_explanation = "���n�܂�̃X�e�[�W";

	if (mapnom == 2)
		m_explanation = "��2�̃X�e�[�W";

	if (mapnom == 3)
		m_explanation = "����������H3�̃X�e�[�W";

	if (mapnom == 4)
		m_explanation = "��4�R���̃X�e�[�W";

	if (mapnom == 5)
		m_explanation = "��5�R���̃X�e�[�W";

	if (mapnom == 6)
		m_explanation = "��6�R���̃X�e�[�W";

	if (mapnom == MAP_MAX)
		m_explanation = "���Ō�̃X�e�[�W";

	

	if (ReportMapNumber::GetInstance()->GetClearCheck(ReportMapNumber::GetInstance()->GetNomber() - 1))
	{
		m_clear = " CLEAR��";
		b = g = 0;
	}
	else
	{
		m_clear = "";
		b = g = 255;
	}

	ReportMapNumber::GetInstance()->SetMapInfo((m_explanation+m_clear));
	DrawString(m_x, OBJ_SIZE+(SCREEN_Y / 2), (m_explanation+m_clear).c_str(), GetColor(255, g, b));
	

}

