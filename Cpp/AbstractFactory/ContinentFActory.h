/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CONTINENT_FACTORY_H__
#define __CONTINENT_FACTORY_H__

#include "Herbivore.h"
#include "Carnivore.h"

class IContinentFactory
{
public:
	virtual IHerbivore* CreateHerbivore() = 0;
	virtual ICarnivore* CreateCarnivore() = 0;
};

#endif