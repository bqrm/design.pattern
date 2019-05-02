/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CLASSADAPTER_H__
#define __CLASSADAPTER_H__

#include "Adaptee.h"
#include "Target.h"

class CInheritedAdapter : public ITarget, public CAdaptee
{
public:
	CInheritedAdapter() {}
	~CInheritedAdapter() {}

	void Request()
	{
		printf("inherited adapter calls ");
		SpecificRequest();
	}
};

#endif