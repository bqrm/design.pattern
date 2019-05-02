/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __ABSTRACTBUILDER_H__
#define __ABSTRACTBUILDER_H__

#include "Product.h"

class IAbstractBuilder
{
public:
	virtual void BuildPartA(int nParam) = 0;
	virtual void BuildPartB(int nParam) = 0;

	virtual void CreateProduct() = 0;

	virtual CProduct* GetProduct() = 0;
};

#endif