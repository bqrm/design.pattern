/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __SALES_TICKET_H__
#define __SALES_TICKET_H__

#include "Component.h"

class CSalesTicket : public IComponent
{
public:
	CSalesTicket() {}
	~CSalesTicket() {}

	void PrintTicket()
	{
		printf("SalesTicket.\n");
	}
};

#endif