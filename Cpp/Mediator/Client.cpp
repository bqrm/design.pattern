/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "InstantMessager.h"
#include "Monitor.h"
#include "Jerry.h"
#include "Tom.h"

int main(int argc, char** argv)
{
	CInstantMessager *pIM = new CInstantMessager();
	CJerry *pJerry = new CJerry(pIM);
	CTom *pTom = new CTom(pIM);
	CMonitor *pMonitor = new CMonitor(pIM);

	pIM->AddClassmate("Jerry", pJerry);
	pIM->AddClassmate("Tom", pTom);
	pIM->AddClassmate("Monitor", pMonitor);

	pTom->SendMessage("Jerry", "I want to eat you");
	pJerry->SendMessage("Tom", "stop joking");
	pMonitor->SendMessage("All", "be quiet");
	pTom->SendMessage("Monitor", "OK");
	pJerry->SendMessage("Monitor", "OK");

	delete pMonitor;
	pMonitor = nullptr;
	delete pTom;
	pTom = nullptr;
	delete pJerry;
	pJerry = nullptr;
	delete pIM;
	pIM = nullptr;

	printf("press any key to exit...\n");
	getchar();
}