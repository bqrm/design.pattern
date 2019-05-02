/***************************************************
 * @file		ThreadStd.h
 * @section		
 * @brief		basic definition of thread
 * @author		bqrmtao@gmail.com
 * @date		2017/01/09
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef __THREAD_STD_H__
#define __THREAD_STD_H__

#include <thread>
#include <windows.h>

/*
 * @class	
 * @brief	
*/
class IThreadStd
{
public:
	/*
	 * @brief	default constructor
	*/
	IThreadStd()
	{
		m_isActive = false;
		m_isRunning = true;
		SetSleepSpanInWhileLoop(1000);
	}

	/*
	 * @brief	default destructor
	*/
	virtual ~IThreadStd() {}
	
	/*
	 * @brief	get name of current thread
	 * @return	name of current thread in string
	*/
	virtual std::string Name() = 0;
	/*
	 * @brief	set the time to sleep in while loop when the main job is done.
					unSleepRound = unTotalSleepSpan / unSleepSpanPerRound
	 * @param	unTotalSleepSpan: total time to sleep when waiting for next iteration, in millisecond
	 * @param	unSleepSpanPerRound: sleep span of every round for quickly respond, set 500ms as default
	*/
	void SetSleepSpanInWhileLoop(unsigned int unTotalSleepSpan, unsigned int unSleepSpanPerRound = 500)
	{
		m_unSleepSpanPerRound = unSleepSpanPerRound;
		m_unNumSleepRound = unTotalSleepSpan / m_unSleepSpanPerRound;
	}
	/*
	 * @brief	set flag to control this thread to be active or not
	*/
	void SetThreadActive(bool isActive) { m_isActive = isActive; }
	/*
	 * @brief	start thread, call virtual function InitThread first
	*/
	void StartThread()
	{
		InitThread();
		m_oThread = std::thread(std::bind(&IThreadStd::RunThread, this));
	}
	/*
	 * @brief	stop thread, call virtual function DestroyThread before stopped
	*/
	void StopThread()
	{
		m_isRunning = false;
		m_oThread.join();
		DestroyThread();
		m_oThread.swap(std::thread());
	}

protected:
	/*
	 * @brief	virtual function, for sub-class to over-write
	*/
	virtual void DestroyThread() {}
	/*
	 * @brief	virtual function, for sub-class to over-write
	*/
	virtual void InitThread() {}
	/*
	 * @brief	main job of the thread
	*/
	virtual void RunThread() {}
	/*
	 * @brief	sleep and wait for next iteration
	*/
	void SleepThread()
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

	/*
	 * @brief	used to control whether to execute the main work of this thread or not
	*/
	bool m_isActive;
	/*
	 * @brief	used to break from while loop when StopThread called
	*/
	bool m_isRunning;
	/*
	 * @brief	time to sleep when main job of the thread is done in loop while
	 */
	unsigned int m_unSleepIdx;
	unsigned int m_unNumSleepRound;
	unsigned int m_unSleepSpanPerRound;

private:
	std::thread m_oThread;
};

#endif	// __THREAD_STD_H__