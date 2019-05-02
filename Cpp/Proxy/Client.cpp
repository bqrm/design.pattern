/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "FaxconnProxy.h"
#include "PhoneFactory.h"

int main(int argc, char** argv)
{
	IFactory *pFactory = new CPhoneFactory();
	CFoxconnProxy *pProxy = new CFoxconnProxy(pFactory);
	pProxy->MakeProduct();

	printf("press any key to exit...\n");
	getchar();
}