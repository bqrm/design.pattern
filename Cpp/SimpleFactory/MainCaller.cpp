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

#include "CashFactory.h"

using namespace std;

int main(int argc, char **argv)
{
	CCashFactory *pCashFactory = new CCashFactory();

	ICashSuper *pCashNormalAccepter = pCashFactory->CreateCashAccept(Normal);
	pCashNormalAccepter->AcceptCash();
	delete pCashNormalAccepter;
	pCashNormalAccepter = nullptr;

	ICashSuper *pCashRebateAccepter = pCashFactory->CreateCashAccept(Rebate);
	pCashRebateAccepter->AcceptCash();
	delete pCashRebateAccepter;
	pCashRebateAccepter = nullptr;

	ICashSuper *pCashReturnAccepter = pCashFactory->CreateCashAccept(Return);
	pCashReturnAccepter->AcceptCash();
	delete pCashReturnAccepter;
	pCashReturnAccepter = nullptr;

	delete pCashFactory;
	pCashFactory = nullptr;

	printf("press any key to continue...\n");
	getchar();
}