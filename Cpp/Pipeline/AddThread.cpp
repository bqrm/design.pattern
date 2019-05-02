/***************************************************
 * @file		AddThread.cpp
 * @section		
 * @class		CAddThread
 * @brief		thread of adding
 * @author		bqrmtao@gmail.com
 * @date		2018/03/15
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#include "AddThread.h"
//#include "Logger.h"
//#include "MacroDefination.h"

using namespace std;

/*
 * @brief	default constructor
*/
CAddThread::CAddThread(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut, size_t ullDataLen)
	: IFloatProcessingThread(pQueueManager, pQueueIn, pQueueOut, ullDataLen)
{
	m_fY = 1;

	//__LOG_INFO__(Name() + " created");
}

/*
 * @brief	default destructor
*/
CAddThread::~CAddThread()
{
	StopThread();

	//__LOG_INFO__(Name() + " destroyed");
}

/*
 * @brief	main job of the thread
*/
void CAddThread::RunThread()
{
	while (m_isRunning)
	{
		if (m_isActive)
		{
			// try to pop a buffer
			if (m_pQueueIn->TryPop(m_pX))
			{
				// check if the pipeline is working
				if (m_isPipelineActive)
				{
					for (m_ullDataIdx = 0; m_ullDataIdx < m_ullDataLen; m_ullDataIdx++)
					{
						*(m_pX + m_ullDataIdx) += m_fY++;
					}

					// push the buffer into output queue
					m_pQueueOut->PushIn(m_pX);
				}
				else
				{
					// if not, return the queue to queue manager
					m_pQueueManager->PushArrayIntoQueue<float>(m_pX, m_ullDataLen);
				}
			}
		}

		SleepThread();
	}
}