/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/


#ifndef __WORK_GROUP_H__
#define __WORK_GROUP_H__

#include <vector>

#include "Department.h"

class CWorkGroup : public IDepartment
{
public:
	CWorkGroup() {}
	~CWorkGroup() {}

	void JobDescription()
	{
		printf("WorkGroup::JobDescription.\n");

		for (auto iterIdx = m_vecDepartment.begin(); iterIdx != m_vecDepartment.end(); iterIdx++)
		{
			(*iterIdx)->JobDescription();
		}
	}
	void AddSubGroup(IDepartment* pDepartment)
	{
		std::vector<IDepartment*>::iterator iter = find(m_vecDepartment.begin(), m_vecDepartment.end(), pDepartment);
		if (m_vecDepartment.end() == iter)
		{
			m_vecDepartment.push_back(pDepartment);
		}
	}
	void RemoveSubGroup(IDepartment* pDepartment)
	{
		std::vector<IDepartment*>::iterator iter = find(m_vecDepartment.begin(), m_vecDepartment.end(), pDepartment);
		if (m_vecDepartment.end() != iter)
		{
			m_vecDepartment.erase(iter);
		}
	}
	IDepartment* GetSubGroup(int nChildIdx)
	{
		if (nChildIdx < 0 || nChildIdx > m_vecDepartment.size())
		{
			return nullptr;
		}

		return m_vecDepartment[nChildIdx];
	}

private:
	std::vector<IDepartment*> m_vecDepartment;
};

#endif