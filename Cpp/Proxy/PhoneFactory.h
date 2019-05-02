/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __PHONE_FACTORY_H__
#define __PHONE_FACTORY_H__

#include <stdio.h>

#include "Factory.h"

class CPhoneFactory : public IFactory
{
public:
	CPhoneFactory() {}
	~CPhoneFactory() {}

	void MakeProduct()
	{
		printf("Phone Factory.\n");
	}
};

#endif