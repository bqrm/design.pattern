/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __NOKIA_PHONE_H__
#define __NOKIA_PHONE_H__

#include "MobilePhone.h"

class CNokiaPhone : public IMobilePhone
{
public:
	CNokiaPhone() {}
	~CNokiaPhone() {}

	void MakeCall()
	{
		printf("nokia cellphone.\n");
	}
};

#endif