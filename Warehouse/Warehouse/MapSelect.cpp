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
		explanation = "■始まりのステージ";

	if (mapnom == 2)
		explanation = "■2のステージ";

	if (mapnom == 3)
		explanation = "■何かいる？3のステージ";

	if (mapnom == 4)
		explanation = "■4コメのステージ";

	if (mapnom == 5)
		explanation = "■5コメのステージ";

	if (mapnom == 6)
		explanation = "■6コメのステージ";

	if (mapnom == MAP_MAX)
		explanation = "■最後のステージ";

	

	if (ReportMapNumber::GetInstance()->GetClearCheck(ReportMapNumber::GetInstance()->GetNomber() - 1))
	{
		clear = " CLEAR済";
		b = g = 0;
	}
	else
	{
		clear = "";
		b = g = 255;
	}

	ReportMapNumber::GetInstance()->SetMapInfo((explanation+clear));
	DrawString(m_x, OBJ_SIZE+(SCREEN_Y / 2), (explanation+clear).c_str(), GetColor(255, g, b));
	

}

