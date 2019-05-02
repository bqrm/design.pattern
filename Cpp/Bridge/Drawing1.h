/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CONCRETE_DRAWING1_H__
#define __CONCRETE_DRAWING1_H__

#include "Drawing.h"

class CConcreteDrawing1 : public IDrawing
{
public:
	CConcreteDrawing1() {}
	~CConcreteDrawing1() {}

	void DrawLine()
	{
		printf("draw a line called in Drawing1.\n");
	}

	void DrawCircle()
	{
		printf("draw a circle called in Drawing1.\n");
	}
};

#endif