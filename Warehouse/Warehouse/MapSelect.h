#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

////Map�I���Ŏg�p//

class MapSelect
{
public:
	MapSelect() = default;
	~MapSelect() = default;

	void Update();////�I��//
	void Draw();
	void MapExplanation();////�}�b�v�̐���//
private:
	

	std::string m_mapselectnumber;

	int m_selectmapnum = 1;

	int m_x = 0;//�������W

	std::string explanation;
	std::string clear;
};

