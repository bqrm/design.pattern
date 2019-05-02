/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Runtime.h"
#include "UserTaker.h"

int main(int argc, char** argv)
{
	CRuntime *winSys = new CRuntime();
	CUserMemento* pCarer = new CUserMemento();

	winSys->SetState("good");
	pCarer->SaveMemento(winSys->CreateMemento());

	winSys->SetState("bad");
	winSys->RestoreMemento(pCarer->RetrieveMemento());

	printf("state of winSys is %s.\n", winSys->GetState().c_str());

	delete pCarer;
	pCarer = nullptr;
	delete winSys;
	winSys = nullptr;

	printf("press any key to exit...\n");
	getchar();
}