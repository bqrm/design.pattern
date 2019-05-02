/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __OBJECTADAPTER_H__
#define __OBJECTADAPTER_H__

#include "Target.h"
#include "Adaptee.h"

class CObjectAdapter : public ITarget
{
public:
	CObjectAdapter()
	{
		m_pAdapter = new CAdaptee();
	}
	~CObjectAdapter()
	{
		delete m_pAdapter;
		m_pAdapter = nullptr;
	}

	void Request()
	{
		printf("object adapter calls ");
		m_pAdapter->SpecificRequest();
	}

private:
	CAdaptee *m_pAdapter;
};

#endif