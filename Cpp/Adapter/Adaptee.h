/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __ADAPTEE_H__
#define __ADAPTEE_H__

#include <stdio.h>

class CAdaptee
{
public:
	CAdaptee() {}
	~CAdaptee() {}

	void SpecificRequest()
	{
		printf("specific request in adaptee.\n");
	}
};

#endif