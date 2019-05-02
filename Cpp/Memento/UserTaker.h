/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __USER_TAKER_H__
#define __USER_TAKER_H__

#include "Memento.h"

class CUserMemento
{
public:
	CUserMemento()
	{
		m_pM = nullptr;
	}
	~CUserMemento()
	{
		m_pM = nullptr;
	}

	CMemento* RetrieveMemento()
	{
		return m_pM;
	}
	void SaveMemento(CMemento *pM)
	{
		m_pM = pM;
	}

private:
	CMemento *m_pM;
};

#endif