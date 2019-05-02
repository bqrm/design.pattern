/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __GUARDIAN_H__
#define __GUARDIAN_H__

#include "Child.h"

/* important */
class IChild;

class IGuardian
{
public:
	virtual void Update(IChild *pKid) = 0;
};

#endif