/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __BEELINE_H__
#define __BEELINE_H__

#include "AbstractLine.h"

class CBeeLine : public IAbstractLine
{
public:
	CBeeLine() {}
	~CBeeLine() {}

	IAbstractLine* Clone()
	{
		printf("Bee line clone a line.\n");
		return new CBeeLine(*this);
	}

	void SetWeight(const int nWeight)
	{
		m_nWeight = nWeight;
	}

	void Show()
	{
		printf("beeline weight = %d.\n", m_nWeight);
	}

protected:
	int m_nWeight;
};

#endif