/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "AfricaFactory.h"
#include "AmericaFactory.h"
#include "AnimalWorld.h"

int main(int argc, char** argv)
{
	IContinentFactory *pAfrica = new CAfricaFactory();

	CAnimalWorld *pAanimalWorld = new CAnimalWorld(pAfrica);
	pAanimalWorld->RunFoodChain();
	delete pAanimalWorld;
	pAanimalWorld = nullptr;
	delete pAfrica;
	pAfrica = nullptr;

	IContinentFactory *pAmerica = new CAmericaFactory();

	pAanimalWorld = new CAnimalWorld(pAmerica);
	pAanimalWorld->RunFoodChain();
	delete pAanimalWorld;
	pAanimalWorld = nullptr;
	delete pAmerica;
	pAmerica = nullptr;
	
	printf("press any key to exit...\n");
	getchar();
}