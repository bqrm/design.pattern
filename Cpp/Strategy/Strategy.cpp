/*********************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Gun.h"
#include "Knife.h"
#include "Solider.h"

int main(int argc, char** argv)
{
	CSolider *pSolider = new CSolider(Gun, true);

	pSolider->Fight(45);
	pSolider->Fight(9);
	pSolider->Fight(100);

	delete pSolider;

	pSolider = new CSolider(Knife, false);
	pSolider->Fight(30);

	delete pSolider;
	pSolider = nullptr;

	printf("press any key to exit...\n");
	getchar();
}