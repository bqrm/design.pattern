/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CONCRETE_DRAWING2_H__
#define __CONCRETE_DRAWING2_H__

#include "Drawing.h"

class CConcreteDrawing2 : public IDrawing
{
public:
	CConcreteDrawing2() {}
	~CConcreteDrawing2() {}

	void DrawLine()
	{
		printf("draw a line called in Drawing2.\n");
	}

	void DrawCircle()
	{
		printf("draw a circle called in Drawing2.\n");
	}
};

#endif