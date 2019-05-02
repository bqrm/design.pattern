/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __FATHER_H__
#define __FATHER_H__

#include "Guardian.h"

class CFather : public IGuardian
{
public:
	CFather() {}
	~CFather() {}

	void Update(IChild *pKid)
	{
		printf("father notices that %s %s.\n", pKid->Name().c_str(), pKid->GetState().c_str());
	}
};

#endif