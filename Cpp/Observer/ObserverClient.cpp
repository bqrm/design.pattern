/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Father.h"
#include "Mother.h"
#include "Son.h"

int main(int argc, char** argv)
{
	IChild *pKid = new CSon();
	IGuardian *pFather = new CFather();
	IGuardian *pMother = new CMother();

	pKid->Attach(pFather);
	pKid->Attach(pMother);

	pKid->SetState("fought with others");
	pKid->NotifyGuardians();

	printf("\n");
	pKid->Detach(pMother);
	delete pMother;
	pMother = nullptr;

	pKid->SetState("got a scholarship");
	pKid->NotifyGuardians();

	printf("\n");
	pKid->Detach(pFather);
	delete pFather;
	pFather = nullptr;

	delete pKid;
	pKid = nullptr;

	printf("press any key to exit...\n");
	getchar();
}