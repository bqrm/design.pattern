/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "ConcreteBuilder.h"

class CDirector
{
public:
	CDirector(IAbstractBuilder *pBuilder)
	{
		m_pCurBuilder = pBuilder;
	}

	~CDirector()
	{
		m_pCurBuilder = nullptr;
	}

	void Construct()
	{
		if (nullptr == m_pCurBuilder)
		{
			printf("no builder in director.\n");
			return;
		}

		m_pCurBuilder->CreateProduct();
		m_pCurBuilder->BuildPartA(1);
		m_pCurBuilder->BuildPartB(2);
	}

	IAbstractBuilder* GetBuilder()
	{
		return m_pCurBuilder;
	}

private:
	IAbstractBuilder *m_pCurBuilder;
};

#endif