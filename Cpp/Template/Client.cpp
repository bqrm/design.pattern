/***************************************************
 * @file		
 * @section		
 * @class		
 * @brief		
 * @author		bqrmtao@gmail.com
 * @date		
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#include "Coffee.h"
#include "Tee.h"

int main(int argc, char** argv)
{
	CCoffee *pCoffee = new CCoffee();
	pCoffee->PrepareRecipe();
	delete pCoffee;
	pCoffee = nullptr;

	printf("\n");

	CTee *pTee = new CTee();
	pTee->PrepareRecipe();
	delete pTee;
	pTee = nullptr;

	printf("press any key to exit...\n");
	getchar();
}