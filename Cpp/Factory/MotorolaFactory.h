/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __MOTOROLA_FACTORY_H__
#define __MOTOROLA_FACTORY_H__

#include "MobileFactory.h"
#include "MotorolaPhone.h"

class CMotorolaFactory : public IMobileFactory
{
public:
	CMotorolaFactory() {}
	~CMotorolaFactory() {}

	IMobilePhone* ProduceMobile()
	{
		printf("motorola's factory produces ");
		return new CMotorolaPhone();
	}
};

#endif