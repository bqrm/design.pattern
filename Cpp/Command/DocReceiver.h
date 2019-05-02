/*********************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __DOC_RECEIVER_H__
#define __DOC_RECEIVER_H__

#include <stdio.h>

class CDocRecv
{
public:
	CDocRecv() {}
	~CDocRecv() {}

	void Display()
	{
		printf("show the context of the doc.\n");
	}
	void Undo()
	{
		printf("cancel the context of the doc.\n");
	}
	void Redo()
	{
		printf("redo the context of the doc.\n");
	}
};

#endif