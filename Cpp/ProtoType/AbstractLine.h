/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __ABSTRACTLINE_H__
#define __ABSTRACTLINE_H__

#include <stdio.h>

class IAbstractLine
{
public:
	virtual IAbstractLine* Clone() = 0;
};

//IAbstractLine* Clone(IAbstractLine* pAbstractLine)
//{
//	return pAbstractLine->Clone();
//}

#endif