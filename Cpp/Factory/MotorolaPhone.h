/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __MOTOROLA_PHONE_H__
#define __MOTOROLA_PHONE_H__

#include "MobilePhone.h"

class CMotorolaPhone : public IMobilePhone
{
public:
	CMotorolaPhone() {}
	~CMotorolaPhone() {}

	void MakeCall()
	{
		printf("motorola cellphone.\n");
	}
};

#endif