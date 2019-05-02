/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __AFRICAFACTORY_H__
#define __AFRICAFACTORY_H__

#include "ContinentFactory.h"
#include "Lion.h"
#include "Wildebeest.h"

class CAfricaFactory : public IContinentFactory
{
public:
	CAfricaFactory() {}
	~CAfricaFactory() {}

	IHerbivore* CreateHerbivore()
	{
		return new CWildebeest();
	}

	ICarnivore* CreateCarnivore()
	{
		return new CLion();
	}
};

#endif