#pragma once
//|*******|//
//|include|//
//|*******|//
#include"main.h"

//|*******|//
//|define |//
//|*******|//

class ReportMapNumber
{
public:
	ReportMapNumber(const ReportMapNumber&) = delete;
	ReportMapNumber& operator=(const ReportMapNumber&) = delete;
	ReportMapNumber(const ReportMapNumber&&) = delete;
	ReportMapNumber& operator=(const ReportMapNumber&&) = delete;

	static void InstanceCrearte();
	static void InstanceDelete();

	int GetNomber() { return m_nomber; };
	void SetNumber(int number) { m_nomber = number; };

	std::string GetMapInfo() { return m_mapinfo; };
	void SetMapInfo(std::string mapinfo) { m_mapinfo = mapinfo; };

	bool GetClearCheck(int nomber) { return m_clearcheck[nomber]; };
	void SetClearCheck(int nomber, bool check) { m_clearcheck[nomber] = check; };

	static ReportMapNumber* GetInstance() { return m_pInstance; };

private:
	static ReportMapNumber* m_pInstance;

	std::string m_mapinfo;
	int m_nomber;
	bool m_clearcheck[MAP_MAX];

	ReportMapNumber()
	{
		for (int i = 0; i < MAP_MAX; i++)
			m_clearcheck[i] = false;
	};
	~ReportMapNumber() = default;
};

