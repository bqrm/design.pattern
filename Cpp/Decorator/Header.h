/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __HEADER_H__
#define __HEADER_H__

#include "TicketDecorator.h"

class CTicketHeader : public ITicketDecorator
{
public:
	CTicketHeader(IComponent *pDecorateComponent)
	{
		m_pDecorateComponent = pDecorateComponent;
	}
	~CTicketHeader()
	{
		m_pDecorateComponent = nullptr;
	}

	void PrintTicket()
	{
		printf("Header.\n");
		m_pDecorateComponent->PrintTicket();
	}
};

#endif