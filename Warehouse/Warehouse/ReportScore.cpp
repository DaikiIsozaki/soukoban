#include"ReportScore.h"

ReportScore* ReportScore::m_pInstance = nullptr;

void ReportScore::InstanceCrearte()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new ReportScore;
	}
}

void ReportScore::InstanceDelete()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
