/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/


#ifndef __FAXCONN_PROXY__
#define __FAXCONN_PROXY__

#include "Factory.h"

class CFoxconnProxy : public IFactory
{
public:
	CFoxconnProxy()
	{
		m_pFactory = nullptr;
	}
	CFoxconnProxy(IFactory *pFactory)
	{
		m_pFactory = pFactory;
	}
	~CFoxconnProxy()
	{
		m_pFactory = nullptr;
	}

	void MakeProduct()
	{
		m_pFactory->MakeProduct();
	}

private:
	IFactory *m_pFactory;
};

#endif