/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __MOBILE_FACTORY_H__
#define __MOBILE_FACTORY_H__

#include "MobilePhone.h"

class IMobileFactory
{
public:
	virtual IMobilePhone* ProduceMobile() = 0;
};

#endif