/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __TICKET_DECORATOR_H__
#define __TICKET_DECORATOR_H__

#include "Component.h"

class ITicketDecorator : public IComponent
{
public:
	ITicketDecorator()
	{
		m_pDecorateComponent = nullptr;
	}
	ITicketDecorator(IComponent *pDecorateComponent)
	{
		m_pDecorateComponent = pDecorateComponent;
	}
	~ITicketDecorator()
	{
		m_pDecorateComponent = nullptr;
	}

	virtual void PrintTicket()
	{
		printf("PrintTicket called in ITicketDecorator\n");
		m_pDecorateComponent->PrintTicket();
	}

protected:
	IComponent *m_pDecorateComponent;
};

#endif