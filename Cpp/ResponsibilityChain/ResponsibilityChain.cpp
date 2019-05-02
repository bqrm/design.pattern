/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Majordomo.h"
#include "Manager.h"

int main(int argc, char **argv)
{
	CMajordomo *pMajordomo = new CMajordomo();
	CManager *pManager = new CManager();
	pManager->SetSuperior(pMajordomo);

	pManager->SanctionVacation(2);
	pManager->SanctionVacation(8);
	pManager->SanctionVacation(25);

	delete pManager;
	pManager = nullptr;
	delete pMajordomo;
	pMajordomo = nullptr;

	printf("press any key to exit...\n");
	getchar();
}