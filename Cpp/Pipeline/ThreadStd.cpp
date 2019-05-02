/***************************************************
 * @file		ThreadStd.cpp
 * @section		
 * @brief		basic definition of thread
 * @author		bqrmtao@gmail.com
 * @date		2017/01/09
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#include <windows.h>

#include "ThreadStd.h"

/*
 * @brief	default constructor
*/
IThreadStd::IThreadStd()
{
	m_isActive = false;
	m_isRunning = true;
	SetSleepSpanInWhileLoop(1000);
}

/*
 * @brief	default destructor
*/
IThreadStd::~IThreadStd()
{
}

/*
 * @brief	set the time to sleep in while loop when the main job is done.
				unSleepRound = unTotalSleepSpan / unSleepSpanPerRound
 * @param	unTotalSleepSpan: total time to sleep when waiting for next iteration, in millisecond
 * @param	unSleepSpanPerRound: sleep span of every round for quickly respond, set 500ms as default
*/
void IThreadStd::SetSleepSpanInWhileLoop(unsigned int unTotalSleepSpan, unsigned int unSleepSpanPerRound)
{
	m_unSleepSpanPerRound = unSleepSpanPerRound;
	m_unNumSleepRound = unTotalSleepSpan / m_unSleepSpanPerRound;
}

/*
 * @brief	start thread, call virtual function InitThread first
*/
void IThreadStd::StartThread()
{
	InitThread();
	m_oThread = std::thread(std::bind(&IThreadStd::RunThread, this));
}

/*
 * @brief	stop thread, call virtual function DestroyThread before stopped
*/
void IThreadStd::StopThread()
{
	m_isRunning = false;
	m_oThread.join();
	DestroyThread();
	m_oThread.swap(std::thread());
}

/*
 * @brief	virtual function, for sub-class to over-write
*/
void IThreadStd::DestroyThread()	
{
}

/*
 * @brief	virtual function, for sub-class to over-write
*/
void IThreadStd::InitThread()
{
}

/*
 * @brief	get name of current thread
 * @return	name of current thread in string
*/
//std::string IThreadStd::Name()
//{
//	return std::string("IThreadStd");
//}

/*
 * @brief	main job of the thread
*/
void IThreadStd::RunThread()
{
}

/*
 * @brief	sleep and wait for next iteration
*/
void IThreadStd::SleepThread()
{
	for (m_unSleepIdx = 0; m_unSleepIdx < m_unNumSleepRound; m_unSleepIdx++)
	{
		if (m_isRunning)
		{
			Sleep(m_unSleepSpanPerRound);
		}
		else
		{
			break;
		}
	}
}