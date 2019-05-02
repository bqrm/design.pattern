/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <stdio.h>

class CProduct
{
public:
	CProduct() {}
	~CProduct() {}

	void SetPartA(int nParam)
	{
		m_nPartA = nParam;
	}

	void SetPartB(int nParam)
	{
		m_nPartB = nParam;
	}

	void Show()
	{
		printf("partA = %d, partB = %d.\n", m_nPartA, m_nPartB);
	}

private:
	int m_nPartA;
	int m_nPartB;
};

#endif