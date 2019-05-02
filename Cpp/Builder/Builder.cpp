/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include <stdlib.h>

#include "Director.h"

int main(int argc, char** argv)
{
	IAbstractBuilder *pBuilder = new CConcreteBuilder();

	CDirector *pDirector = new CDirector(pBuilder);

	pDirector->Construct();
	pBuilder->GetProduct()->Show();
	pDirector->GetBuilder()->GetProduct()->Show();

	delete pDirector;
	pDirector = nullptr;
	delete pBuilder;
	pBuilder = nullptr;

	printf("press any key to exit...\n");
	getchar();
}