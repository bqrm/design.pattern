/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __FOOTER_H__
#define __FOOTER_H__

#include "TicketDecorator.h"

class CTicketFooter : public ITicketDecorator
{
public:
	CTicketFooter(IComponent *pDecorateComponent)
	{
		m_pDecorateComponent = pDecorateComponent;
	}
	~CTicketFooter()
	{
		m_pDecorateComponent = nullptr;
	}

	void PrintTicket()
	{
		m_pDecorateComponent->PrintTicket();
		printf("Footer.\n");
	}
};

#endif