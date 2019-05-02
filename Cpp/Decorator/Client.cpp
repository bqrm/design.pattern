/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Footer.h"
#include "Header.h"
#include "SalesTicket.h"

int main(int argc, char** argv)
{
	IComponent *pTicketInfo = new CSalesTicket();
	IComponent *pTicketFooter = new CTicketFooter(pTicketInfo);
	IComponent *pTicketHeader = new CTicketHeader(pTicketFooter);

	pTicketHeader->PrintTicket();

	delete pTicketHeader;
	pTicketHeader = nullptr;
	delete pTicketFooter;
	pTicketFooter = nullptr;
	delete pTicketInfo;
	pTicketInfo = nullptr;

	printf("press any key to exit...\n");
	getchar();
}