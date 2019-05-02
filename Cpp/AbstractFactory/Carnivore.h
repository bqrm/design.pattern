/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CARNIVORE_H__
#define __CARNIVORE_H__

#include "Herbivore.h"

class ICarnivore
{
public:
	virtual void Eat(IHerbivore *pHerb) = 0;
	virtual std::string Name() = 0;
};

#endif