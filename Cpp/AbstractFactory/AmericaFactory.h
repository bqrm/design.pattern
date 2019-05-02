/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __AMERICAFACTORY_H__
#define __AMERICAFACTORY_H__

#include "ContinentFactory.h"
#include "Bision.h"
#include "Wolf.h"

class CAmericaFactory : public IContinentFactory
{
public:
	CAmericaFactory() {}
	~CAmericaFactory() {}

	IHerbivore* CreateHerbivore()
	{
		return new CBision();
	}

	ICarnivore* CreateCarnivore()
	{
		return new CWolf();
	}
};

#endif