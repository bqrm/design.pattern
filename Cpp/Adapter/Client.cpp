/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "InheritedAdapter.h"
#include "ObjectAdapter.h"

int main(int argc, char** argv)
{
	ITarget *pTargetFunc = new CObjectAdapter();
	pTargetFunc->Request();
	delete pTargetFunc;
	pTargetFunc = nullptr;

	pTargetFunc = new CInheritedAdapter();
	pTargetFunc->Request();
	delete pTargetFunc;
	pTargetFunc = nullptr;

	printf("press any key to exit...\n");
	getchar();
}