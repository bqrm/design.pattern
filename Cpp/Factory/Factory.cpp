/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "NokiaFactory.h"
#include "MotorolaFactory.h"

using namespace std;

int main(int argc, char**argv)
{
	IMobileFactory *pMobileFactory;
	IMobilePhone *pMobilePhone;

	pMobileFactory = new CMotorolaFactory();
	pMobilePhone = pMobileFactory->ProduceMobile();
	pMobilePhone->MakeCall();
	delete pMobilePhone;
	pMobilePhone = nullptr;
	delete pMobileFactory;
	pMobileFactory = nullptr;
	
	pMobileFactory = new CNokiaFactory();
	pMobilePhone = pMobileFactory->ProduceMobile();
	pMobilePhone->MakeCall();
	delete pMobilePhone;
	pMobilePhone = nullptr;
	delete pMobileFactory;
	pMobileFactory = nullptr;

	printf("press any key to exit...\n");
	getchar();
}