/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>

class CScreen
{
public:
	CScreen() {}
	~CScreen() {}

	void TrunOn()
	{
		printf("Screens on.\n");
	}

	void TrunOff()
	{
		printf("Screens off.\n");
	}
};

#endif