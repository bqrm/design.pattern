/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __UNDO_CMD_H__
#define __UNDO_CMD_H__

#include "DocCmd.h"

class CUndoCmd : public IDocCmd
{
public:
	CUndoCmd(CDocRecv* pDoc)
	{
		m_pDocRecv = pDoc;
	}
	~CUndoCmd()
	{
		m_pDocRecv = nullptr;
	}

	void ExecuteCmd()
	{
		m_pDocRecv->Undo();
	}
};

#endif