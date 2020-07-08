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

	int GetMenuStatus() { return m_menuStatus; };////�����j���[��Ԃ��擾//
	void SetMenuStatus(int nextmenustatus) { m_menuStatus = nextmenustatus; };////���j���[��Ԃ��X�V//

	static ReportMenuStatus* GetInstance() { return m_pInstance; };

private:
	static ReportMenuStatus* m_pInstance;
	int m_menuStatus = 0;

	ReportMenuStatus() = default;
	~ReportMenuStatus() = default;
	
};
