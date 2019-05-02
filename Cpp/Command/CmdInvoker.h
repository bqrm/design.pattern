/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CMD_INVOKER_H__
#define __CMD_INVOKER_H__

#include <set>

#include "DocCmd.h"

class CCmdInvoker
{
public:
	CCmdInvoker() {}
	~CCmdInvoker() {}

	void AddCmd(IDocCmd *pDocCmd)
	{
		if (m_setCmd.find(pDocCmd) == m_setCmd.end())
		{
			m_setCmd.insert(pDocCmd);
		}
	}
	void RemoveCmd(IDocCmd *pDocCmd)
	{
		if (m_setCmd.find(pDocCmd) != m_setCmd.end())
		{
			m_setCmd.erase(pDocCmd);
		}
	}
	void ExecuteCmd()
	{
		for (auto pCmd : m_setCmd)
		{
			pCmd->ExecuteCmd();
		}
	}

private:
	std::set<IDocCmd*> m_setCmd;
};

#endif