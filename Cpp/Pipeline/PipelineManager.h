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

#ifndef _PIPELINE_MANAGER_H_
#define _PIPELINE_MANAGER_H_

#include <vector>

#include "AddThread.h"
#include "MulThread.h"

#include "ConcurrentQueue.h"
#include "QueueManager.h"
#include "ThreadStd.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	CPipelineManager
 * @brief	manager of the pipeline, initializing and stopping the pipeline
*/
class CPipelineManager
{
public:
	/*
	 * @brief	default constructor
	 * @param	pQueueManager
	 * @param	pQueueIn
	 * @param	pQueueOut
	*/
	CPipelineManager(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut);
		
	/*
	 * @brief	default destructor
	*/
	~CPipelineManager();
		
	/*
	 * @brief	initialize the pipeline
	 * @param	ullDataLen: length of an array
	 * @return	
	*/
	int InitPipeline(size_t ullDataLen);
		
	/*
	 * @brief	check if the pipeline is working
	 * @return	activeness of pipeline
	*/
	bool IsPipelineActive() const { return m_isPipelineAlive; }
	
	/*
	 * @brief	get name of the Class
	 * @return	name of the class
	*/
	std::string Name() const { return std::string("PipelineManager"); }
		
	/*
	 * @brief	statistic of consumption of pipeline
	 * @return	result of statisticians of the pipeline
	*/
	int StatisticConsumption();
		
	/*
	 * @brief	stop pipeline
	 * @return	result of stopping the pipeline
	*/
	int StopPipeline();

protected:
	bool m_isPipelineAlive;

	FloatBufferPointer m_pQueueIn;
	FloatBufferPointer m_pQueueOut;

	CQueueManager *m_pQueueManager;

	CAddThread *m_pAddThread;
	CMulThread *m_pMulThread;
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