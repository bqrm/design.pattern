/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __WOLF_H__
#define __WOLF_H__

#include "Carnivore.h"

class CWolf : public ICarnivore
{
public:
	CWolf() {}
	~CWolf() {}

	void Eat(IHerbivore *pHerb)
	{
		printf("%s eats %s.\n", Name().c_str(), pHerb->Name().c_str());
	}

	std::string Name()
	{
		return "Wolf";
	}
};

#endif