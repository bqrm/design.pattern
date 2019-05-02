/***************************************************
 * @file		MulThread.h
 * @section		
 * @class		CMulThread
 * @brief		thread of multiply
 * @author		bqrmtao@gmail.com
 * @date		2018/03/15
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef _MUL_THREAD_H_
#define _MUL_THREAD_H_

#include "FloatProcessingThread.h"

/*
 * @class	
 * @brief	
*/
class CMulThread : public IFloatProcessingThread
{
public:
	/*
	 * @brief	default constructor
	*/
	CMulThread(CQueueManager *pQueueManager, FloatBufferPointer pQueueIn, FloatBufferPointer pQueueOut, size_t ullDataLen);
	
	/*
	 * @brief	default destructor
	*/
	~CMulThread();
	
	/*
	 * @brief	get name of current class
	*/
	virtual std::string Name() { return std::string("MulThread"); }

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