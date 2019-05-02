/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <mutex>
#include <stdio.h>
#include <string>

using namespace std;

mutex m_oSingletonLock;

class CSingleton
{
public:
	static CSingleton* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_oSingletonLock.lock();
			if (nullptr == m_pInstance)
			{
				m_pInstance = new CSingleton();
			}
			m_oSingletonLock.unlock();
		}

		return m_pInstance;
	}

	void Show()
	{
		printf("show %2u times.\n", ++m_unRoundId);
	}

private:
	// private constructor, unable to instantiated outside the class
	CSingleton()
	{
		printf("singleton....\n");
		m_unRoundId = 0;
	}

	~CSingleton() {}

	// to destruct singleton
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (nullptr != m_pInstance)
			{
				delete m_pInstance;
				m_pInstance = nullptr;
				printf("press any key to destroy Singleton\n");
				getchar();
			}
		}
	};

	// static member, the only instance of the class
	static CSingleton* m_pInstance;

	// static member, to destruct singleton
	static CGarbo oGarbo;

	unsigned m_unRoundId;
};

CSingleton *CSingleton::m_pInstance = nullptr;
CSingleton::CGarbo CSingleton::oGarbo;

#endif