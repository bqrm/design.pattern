/***************************************************
 * @file		ConcurrentQueue.h
 * @section		
 * @class		CConcurrentQueue
 * @brief		concurrent queue
 * @author		bqrmtao@gmail.com
 * @date		2018/03/15
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef _CONCURRENT_QUEUE_H_
#define _CONCURRENT_QUEUE_H_

#include <condition_variable>
#include <mutex>
#include <queue>

//#include "Logger.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	CConcurrentQueue
 * @brief	concurrent queue
*/
template <typename DataType>
class CConcurrentQueue
{
public:
	/*
	 * @brief	default constructor
	*/
	CConcurrentQueue()
	{
		//__LOG_INFO__(Name() + " created");
	}

	/*
	 * @brief	default destructor
	*/
	~CConcurrentQueue()
	{
		//__LOG_INFO__(Name() + " destroyed");
	}
	
	/*
	 * @brief	clear the queue
	 * @return	void
	*/
	void ClearQueue()
	{
		// lock up
		std::unique_lock<std::mutex> oQueueLock(m_oMutexConcurrentQueue);

		std::queue<DataType> queueEmpty;
		m_queueData.swap(queueEmpty);
	}
	
	/*
	 * @brief	check if the queue is empty
	 * @return	true if the queue is empty
	*/
	bool IsQueueEmpty() const
	{
		// lock up
		std::unique_lock<std::mutex> oQueueLock(m_oMutexConcurrentQueue);
		return m_queueData.empty();
	}
	
	/*
	 * @brief	get name of the Class
	 * @return	name of the class
	*/
	virtual std::string inline Name()
	{
		return "ConcurrentQueue";
	}
	
	/*
	 * @brief	push data into the queue
	 * @param	pData: DataType
	 * @return	void
	*/
	void PushIn(DataType*& pData)
	{
		// lock up
		std::unique_lock<std::mutex> oQueueLock(m_oMutexConcurrentQueue);

		m_queueData.push(pData);

		// why this function should unlock the mutex?
		oQueueLock.unlock();
		m_oCondition.notify_one();
	}
	
	/*
	 * @brief	current size of the queue
	 * @return	current size of the queue
	*/
	size_t QueueSize()
	{
		// lock up
		std::unique_lock<std::mutex> oQueueLock(m_oMutexConcurrentQueue);
		return m_queueData.size();
	}
	
	/*
	 * @brief	try to pop front of the queue to input buffer
	 * @param	pData
	 * @return	false if the queue is empty, otherwise true
	*/
	bool TryPop(DataType*& pData)
	{
		// lock up
		std::unique_lock<std::mutex> oQueueLock(m_oMutexConcurrentQueue);

		if (m_queueData.empty())
		{
			//__LOG_DEBUG__("empty queue");
			return false;
		}

		pData = m_queueData.front();
		m_queueData.pop();
		return true;
	}
	
	/*
	 * @brief	pop front of the queue to input buffer when the queue is not empty 
	 * @param	pData
	 * @return	void
	*/
	void WaitPop(DataType*& pData)
	{
		// lock up
		std::unique_lock<std::mutex> oQueueLock(m_oMutexConcurrentQueue);

		m_oCondition.wait(oQueueLock, std::bind(&CConcurrentQueue<DataType>::QueueNotEmpty, this));

		pData = m_queueData.front();
		m_queueData.pop();
	}

private:
	/*
	 * @brief	check if the queue is empty
	 * @return	true if the queue is not empty
	*/
	bool QueueNotEmpty()
	{
		return !m_queueData.empty();
	}

	// conditional variable
	std::condition_variable m_oCondition;

	// mutex lock
	std::mutex m_oMutexConcurrentQueue;

	// 
	std::queue<DataType*> m_queueData;
};

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

#endif