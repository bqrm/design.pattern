/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __ABSTRACT_DRAWING_H__
#define __ABSTRACT_DRAWING_H__

#include <stdio.h>

class IDrawing
{
public:
	void virtual DrawLine() = 0;
	void virtual DrawCircle() = 0;
};

#endif