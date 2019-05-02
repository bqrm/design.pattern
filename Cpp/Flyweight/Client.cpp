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

#include "CoffeeShop.h"
#include "Flavor.h"

using namespace std;

int main(int argc, char** argv)
{
	CCoffeeShop *pShop = new CCoffeeShop;

	COrder *pOrder = pShop->TakeOrder("BlackCoffee");
	pOrder->Serve(1);

	pOrder = pShop->TakeOrder("Capucino");
	pOrder->Serve(5);

	delete pShop;
	pShop = nullptr;

	printf("press any key to exit...\n");
	getchar();
}