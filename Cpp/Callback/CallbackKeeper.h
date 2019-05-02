/***************************************************
 * @file		CallbackKeeper.h
 * @section		
 * @class		CCallbackKeeper
 * @brief		keeper of callback object pointer
 * @author		bqrmtao@gmail.com
 * @date		2018/07/12
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef __CALLBACK_KEEPER_H__
#define __CALLBACK_KEEPER_H__

#include <mutex>

#include "CallbackImp.h"

std::mutex m_oCallbackKeeperLocker;

/*
 * @class	CCallbackKeeper
 * @brief	keep the pointer of callback
*/
class CCallbackKeeper
{
public:
	/*
	 * @brief	pointer of callback keeper, static method
	 * @return	CCallbackKeeper*
	*/
	static CCallbackKeeper* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_oCallbackKeeperLocker.lock();
			if (nullptr	== m_pInstance)
			{
				m_pInstance = new CCallbackKeeper();
			}
			m_oCallbackKeeperLocker.unlock();
		}

		return m_pInstance;
	}
	
	/*
	 * @brief	get callback pointer
	 * @return	ICallback*
	*/
	ICallback* GetCallbackPtr()
	{
		return m_pCallback;
	}
	
	/*
	 * @brief	set callback pointer
	 * @param	pCallback (ICallback*)
	 * @return	void
	*/
	void SetCallbackPtr(ICallback *pCallback)
	{
		m_pCallback = pCallback;
	}

private:
	/*
	 * @brief	constructor
	*/
	CCallbackKeeper() {}
	/*
	 * @brief	destructor
	*/
	~CCallbackKeeper() {}

	// to destruct singleton
	class Garbo
	{
	public:
		~Garbo()
		{
			if (nullptr != m_pInstance)
			{
				delete m_pInstance;
				m_pInstance = nullptr;
			}
		}
	};

	// static member, to destruct singleton
	static Garbo oGarbo;

	static CCallbackKeeper* m_pInstance;

	ICallback *m_pCallback;
};

CCallbackKeeper* CCallbackKeeper::m_pInstance = nullptr;

/*
 * @brief	
 * @param	
 * @return	
*/

//#ifdef __cplusplus
//extern "C"
//{
//#endif // __cplusplus
//
//
//#ifdef __cplusplus
//};
//#endif // __cplusplus

#endif	// __CALLBACK_KEEPER_H__