/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CURVELINE_H__
#define __CURVELINE_H__

#include <string>

#include "AbstractLine.h"

class CCurveLine : public IAbstractLine
{
public:
	CCurveLine()
	{
		m_strLineType.reserve(10);
	}
	~CCurveLine() {}

	IAbstractLine* Clone()
	{
		printf("Curve line clone a curve.\n");
		return new CCurveLine(*this);
	}

	void SetType(const std::string &strLineType)
	{
		m_strLineType = strLineType;
	}

	void Show()
	{
		printf("line type = %s.\n", m_strLineType.c_str());
	}
	
protected:
	std::string m_strLineType;
};

#endif