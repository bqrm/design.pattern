/***************************************************
 * @file		FloatProcessingThread.cpp
 * @section		
 * @class		IFloatProcessingThread
 * @brief		interface of float queue manager
 * @author		bqrmtao@gmail.com
 * @date		2019/02/21
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#include "FloatProcessingThread.h"

using namespace std;

/*
 * @brief	default constructor
*/
IFloatProcessingThread::IFloatProcessingThread(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut, size_t ullDataLen)
{
	m_pX = nullptr;

	m_pQueueManager = pQueueManager;

	m_pQueueIn = pQueueIn;
	m_pQueueOut = pQueueOut;

	m_ullDataLen = ullDataLen;

	SetSleepSpanInWhileLoop(10, 2);
}

/*
 * @brief	default destructor
*/
IFloatProcessingThread::~IFloatProcessingThread()
{
	m_pX = nullptr;

	m_pQueueManager = nullptr;

	m_pQueueIn = nullptr;
	m_pQueueOut = nullptr;
}