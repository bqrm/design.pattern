/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __REDO_CMD_H__
#define __REDO_CMD_H__

#include "DocCmd.h"

class CRedoCmd : public IDocCmd
{
public:
	CRedoCmd(CDocRecv* pDoc)
	{
		m_pDocRecv = pDoc;
	}
	~CRedoCmd()
	{
		m_pDocRecv = nullptr;
	}

	void ExecuteCmd()
	{
		m_pDocRecv->Redo();
	}
};

#endif