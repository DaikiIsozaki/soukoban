#include"ReportMenuStatus.h"

ReportMenuStatus* ReportMenuStatus::m_pInstance = nullptr;

void ReportMenuStatus::InstanceCrearte()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new ReportMenuStatus;
	}
}

void ReportMenuStatus::InstanceDelete()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
