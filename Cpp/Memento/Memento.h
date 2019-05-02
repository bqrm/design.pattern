/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __MEMENTO_H__
#define __MEMENTO_H__

#include <stdio.h>
#include <string>

class CMemento
{
public:
	CMemento(std::string strState)
	{
		m_strState = strState;
	}
	~CMemento() {}

	std::string GetState()
	{
		return m_strState;
	}
	void SetState(std::string strState)
	{
		m_strState = strState;
	}

private:
	std::string m_strState;
};

#endif