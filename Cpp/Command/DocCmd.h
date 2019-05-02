/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __DOC_CMD_H__
#define __DOC_CMD_H__

#include "DocReceiver.h"

class IDocCmd
{
public:
	virtual void ExecuteCmd() = 0;

protected:
	CDocRecv* m_pDocRecv;
};

#endif