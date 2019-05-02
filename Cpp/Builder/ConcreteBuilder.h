/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CONCRETEBUILDER_H__
#define __CONCRETEBUILDER_H__

#include "AbstractBuilder.h"

class CConcreteBuilder : public IAbstractBuilder
{
public:
	CConcreteBuilder() {}
	~CConcreteBuilder()
	{
		delete m_pCurProduct;
		m_pCurProduct = nullptr;
	}

	void BuildPartA(int nParam)
	{
		printf("constructing part A.\n");
		m_pCurProduct->SetPartA(nParam);
	}

	void BuildPartB(int nParam)
	{
		printf("constructing part B.\n");
		m_pCurProduct->SetPartB(nParam);
	}

	void CreateProduct()
	{
		printf("constructing an empty product.\n");
		m_pCurProduct = new CProduct();
	}

	CProduct* GetProduct()
	{
		return m_pCurProduct;
	}

private:
	CProduct *m_pCurProduct;
};

#endif