/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"

class CCircle : public IShape
{
public:
	CCircle(IDrawing *pDraw)
	{
		m_pDraw = pDraw;
	}
	~CCircle()
	{
		m_pDraw = nullptr;
	}

	void Draw()
	{
		m_pDraw->DrawCircle();
	}
};

#endif