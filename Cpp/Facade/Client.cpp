/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Facade.h"

int main(int argc, char** argv)
{
	CFacade *pFacade = new CFacade();

	pFacade->Activate();

	printf("\nlive show.\n\n");

	pFacade->Deactivate();

	printf("press any key to exit...\n");
	getchar();
}