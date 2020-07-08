#pragma once
//|*******|//
//|include|//
//|*******|//

//|*******|//
//|define |//
//|*******|//


class ReportMenuStatus
{
public:
	ReportMenuStatus(const ReportMenuStatus&) = delete;
	ReportMenuStatus& operator=(const ReportMenuStatus&) = delete;
	ReportMenuStatus(const ReportMenuStatus&&) = delete;
	ReportMenuStatus& operator=(const ReportMenuStatus&&) = delete;

	static void InstanceCrearte();
	static void InstanceDelete();

	int GetMenuStatus() { return m_menuStatus; };////現メニュー状態を取得//
	void SetMenuStatus(int nextmenustatus) { m_menuStatus = nextmenustatus; };////メニュー状態を更新//

	static ReportMenuStatus* GetInstance() { return m_pInstance; };

private:
	static ReportMenuStatus* m_pInstance;
	int m_menuStatus = 0;

	ReportMenuStatus() = default;
	~ReportMenuStatus() = default;
	
};
