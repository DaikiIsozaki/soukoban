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
	std::string mapnumber = "マップナンバー:";
	m_x = ((SCREEN_X - (int)mapnumber.length()) / 2)-50;
	DrawString(m_x, (SCREEN_Y/2),(mapnumber+m_mapselectnumber).c_str(),GetColor(255, 255, 255) );
	MapExplanation();
}

void MapSelect::MapExplanation()
{
	int mapnom = 0;
	int b = 0;//ブルー
	int g = 0;//グリーン

	mapnom = ReportMapNumber::GetInstance()->GetNomber();

	if (mapnom == 1)
		m_explanation = "■始まりのステージ";

	if (mapnom == 2)
		m_explanation = "■2のステージ";

	if (mapnom == 3)
		m_explanation = "■何かいる？3のステージ";

	if (mapnom == 4)
		m_explanation = "■4コメのステージ";

	if (mapnom == 5)
		m_explanation = "■5コメのステージ";

	if (mapnom == 6)
		m_explanation = "■6コメのステージ";

	if (mapnom == MAP_MAX)
		m_explanation = "■最後のステージ";

	

	if (ReportMapNumber::GetInstance()->GetClearCheck(ReportMapNumber::GetInstance()->GetNomber() - 1))
	{
		m_clear = " CLEAR済";
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

