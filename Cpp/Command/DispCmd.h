/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __DISPLAY_CMD_H__
#define __DISPLAY_CMD_H__

#include "DocCmd.h"

class CDispCmd : public IDocCmd
{
public:
	CDispCmd(CDocRecv* pDoc)
	{
		m_pDocRecv = pDoc;
	}
	~CDispCmd()
	{
		m_pDocRecv = nullptr;
	}

	void ExecuteCmd()
	{
		m_pDocRecv->Display();
	}
};

#endif