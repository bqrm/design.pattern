/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "Drawing.h"

class IShape
{
public:
	virtual void Draw() = 0;

protected:
	IDrawing *m_pDraw;
};

#endif