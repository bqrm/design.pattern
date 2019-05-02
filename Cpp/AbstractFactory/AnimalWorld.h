/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __ANIMALWORLD_H__
#define __ANIMALWORLD_H__

#include "Carnivore.h"
#include "Herbivore.h"
#include "ContinentFactory.h"

class CAnimalWorld
{
public:
	CAnimalWorld(IContinentFactory *pFactory)
	{
		m_pHerb = pFactory->CreateHerbivore();
		m_pCarn = pFactory->CreateCarnivore();
	}

	~CAnimalWorld()
	{
		delete m_pHerb;
		m_pHerb = nullptr;

		delete m_pCarn;
		m_pCarn = nullptr;
	}

	void RunFoodChain()
	{
		m_pCarn->Eat(m_pHerb);
	}

private:
	IHerbivore *m_pHerb;
	ICarnivore *m_pCarn;
};

#endif