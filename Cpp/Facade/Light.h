/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <stdio.h>

class CLight
{
public:
	CLight() {}
	~CLight() {}

	void TrunOn()
	{
		printf("Lights on.\n");
	}

	void TrunOff()
	{
		printf("Lights off.\n");
	}
};

#endif