/***************************************************
 * @file		AddThread.h
 * @section		
 * @class		CAddThread
 * @brief		thread of adding
 * @author		bqrmtao@gmail.com
 * @date		2018/03/15
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef _ADD_THREAD_H_
#define _ADD_THREAD_H_

#include "FloatProcessingThread.h"

/*
 * @class	
 * @brief	
*/
class CAddThread : public IFloatProcessingThread
{
public:
	/*
	 * @brief	default constructor
	*/
	CAddThread(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut, size_t ullDataLen);
	
	/*
	 * @brief	default destructor
	*/
	~CAddThread();
	
	/*
	 * @brief	get name of current class
	*/
	virtual std::string Name() { return std::string("AddThread"); }

private:
	/*
	 * @brief	main job of the thread
	*/
	virtual void RunThread();
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