/***************************************************
 * @file		PipelineManager.h
 * @section		
 * @class		CPipelineManager
 * @brief		manager of thread(s) of pipeline
 * @author		bqrmtao@gmail.com
 * @date		2018/03/14
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

//#include <mutex>

//#include "ErrorMsg.h"
#include "PipelineManager.h"

using namespace std;

mutex m_oMutexPipelineManager;

/*
 * @brief	default constructor
 * @param	pQueueManager
 * @param	pQueueIn
 * @param	pQueueOut
*/
CPipelineManager::CPipelineManager(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut)
{
	m_isPipelineAlive = false;

	m_pQueueIn = pQueueIn;
	m_pQueueOut = pQueueOut;

	m_pAddThread = nullptr;
	m_pMulThread = nullptr;

	//__LOG_INFO__(Name() + " created");
}

/*
 * @brief	default destructor
*/
CPipelineManager::~CPipelineManager()
{
	m_pQueueManager = nullptr;

	m_pQueueIn = nullptr;
	m_pQueueOut = nullptr;

	//__LOG_INFO__(Name() + " destroyed");
}

/*
 * @brief	initialize the pipeline
 * @param	ullDataLen: length of an array
 * @return	
*/
int CPipelineManager::InitPipeline(size_t ullDataLen)
{
	std::unique_lock<std::mutex> oQueueLock(m_oMutexPipelineManager);

	// allocate the intermediate queue between neighbor threads of the queue
	FloatBufferPointer pQueueAddOut = make_shared<CConcurrentQueue<float>>();

	// threads of the pipeline
	m_pAddThread = new CAddThread(m_pQueueManager, m_pQueueIn, pQueueAddOut, ullDataLen);
	m_pAddThread->StartThread();
	m_pAddThread->SetThreadActive(true);

	m_pMulThread = new CMulThread(m_pQueueManager, pQueueAddOut, m_pQueueOut, ullDataLen);
	m_pMulThread->StartThread();
	m_pMulThread->SetThreadActive(true);

	m_isPipelineAlive = true;

	return 0;
}

/*
 * @brief	statistic of consumption of pipeline
 * @return	result of statisticians of the pipeline
*/
int CPipelineManager::StatisticConsumption()
{
	std::unique_lock<std::mutex> oQueueLock(m_oMutexPipelineManager);
	return 0;
}

/*
 * @brief	stop pipeline
 * @return	result of stopping the pipeline
*/
int CPipelineManager::StopPipeline()
{
	std::unique_lock<std::mutex> oQueueLock(m_oMutexPipelineManager);

	// delete the threads of pipeline
	if (nullptr != m_pAddThread)
	{
		delete m_pAddThread;
		m_pAddThread = nullptr;
	}
	if (nullptr != m_pMulThread)
	{
		delete m_pMulThread;
		m_pMulThread = nullptr;
	}

	// delete the middle queue of the pipeline
	//{
	//}

	m_isPipelineAlive = false;

	return 0;
}