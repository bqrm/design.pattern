/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __SYSTEM_ORIGINATOR_H__
#define __SYSTEM_ORIGINATOR_H__

#include "Memento.h"

class CRuntime
{
public:
	CRuntime() {}
	~CRuntime() {}

	CMemento* CreateMemento()
	{
		return new CMemento(m_strState);
	}
	void RestoreMemento(CMemento *pM)
	{
		m_strState = pM->GetState();
	}
	std::string GetState()
	{
		return m_strState;
	}
	void SetState(std::string strState)
	{
		m_strState = strState;
		printf("the system is run at %s.\n", m_strState.c_str());
	}

private:
	std::string m_strState;
};

#endif