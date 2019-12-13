#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

////Map選択で使用//

class MapSelect
{
public:
	MapSelect() = default;
	~MapSelect() = default;

	void Update();////選択//
	void Draw();
	void MapExplanation();////マップの説明//
private:
	

	std::string m_mapselectnumber;

	int m_selectmapnum = 1;

	int m_x = 0;//文字座標

	std::string explanation;
	std::string clear;
};

