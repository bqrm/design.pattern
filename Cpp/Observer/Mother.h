/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __MOTHER_H__
#define __MOTHER_H__

#include "Guardian.h"

class CMother : public IGuardian
{
public:
	CMother() {}
	~CMother() {}

	void Update(IChild *pKid)
	{
		printf("mother notices that %s %s.\n", pKid->Name().c_str(), pKid->GetState().c_str());
	}
};

#endif