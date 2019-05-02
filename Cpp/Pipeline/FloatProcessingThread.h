/***************************************************
 * @file		FloatProcessingThread.h
 * @section		
 * @class		IFloatProcessingThread
 * @brief		interface of float queue manager
 * @author		bqrmtao@gmail.com
 * @date		2019/02/21
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

/* __DEF_MACRO_H__ */
#ifndef __FLOAT_PROCESSING_H__
#define __FLOAT_PROCESSING_H__

#include "ProcessingInterface.h"
#include "QueueManager.h"
#include "ThreadStd.h"

/*
 * @class	
 * @brief	
*/
class IFloatProcessingThread : public IThreadStd, public IProcessingInterface
{
public:
	/*
	 * @brief	default constructor
	*/
	IFloatProcessingThread(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut, size_t ullDataLen);
	/*
	 * @brief	default destructor
	*/
	~IFloatProcessingThread();
	
	/*
	 * @brief	get name of current class
	*/
	virtual std::string Name() { return std::string("AddThread"); }
	
	/*
	 * @brief	set the flag of the state of the pipeline
	 * @param	isActive
	*/
	void SetPipelineActive(bool isActive) { m_isPipelineActive = isActive; }

protected:

	bool m_isPipelineActive;

	float *m_pX;
	float m_fY;

	size_t m_ullDataIdx;
	size_t m_ullDataLen;

	FloatBufferPointer m_pQueueIn;
	FloatBufferPointer m_pQueueOut;

	CQueueManager *m_pQueueManager;
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

#endif	// __FLOAT_PROCESSING_H__