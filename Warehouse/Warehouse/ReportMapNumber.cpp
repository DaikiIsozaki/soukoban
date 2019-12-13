//|*******|//
//|include|//
//|*******|//
#include "ReportMapNumber.h"

ReportMapNumber* ReportMapNumber::m_pInstance = nullptr;

void ReportMapNumber::InstanceCrearte()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new ReportMapNumber;
	}
}

void ReportMapNumber::InstanceDelete()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
