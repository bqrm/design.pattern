/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __LION_H__
#define __LION_H__

#include "Carnivore.h"

class CLion : public ICarnivore
{
public:
	CLion() {}
	~CLion() {}

	void Eat(IHerbivore *pHerb)
	{
		printf("%s eats %s\n", Name().c_str(), pHerb->Name().c_str());
	}

	std::string Name()
	{
		return "Lion";
	}
};

#endif