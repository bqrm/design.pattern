/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __NOKIA_FACTORY_H__
#define __NOKIA_FACTORY_H__

#include "MobileFactory.h"
#include "NokiaPhone.h"

class CNokiaFactory : public IMobileFactory
{
public:
	CNokiaFactory() {}
	~CNokiaFactory() {}

	IMobilePhone* ProduceMobile()
	{
		printf("nokia's factory produces ");
		return new CNokiaPhone();
	}
};

#endif