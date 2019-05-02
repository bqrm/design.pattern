/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Shape.h"

class CRectangle : public IShape
{
public:
	CRectangle(IDrawing *pDraw)
	{
		m_pDraw = pDraw;
	}
	~CRectangle()
	{
		m_pDraw = nullptr;
	}

	void Draw()
	{
		m_pDraw->DrawLine();
		m_pDraw->DrawLine();
		m_pDraw->DrawLine();
		m_pDraw->DrawLine();
	}
};

#endif