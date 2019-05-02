/***************************************************
 * @file		ProcessingInterface.h
 * @section		
 * @class		IProcessingInterface
 * @brief		basic definition of processing
 * @author		bqrmtao@gmail.com
 * @date		2018/03/15
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef _PROCESSING_INTERFACE_H_
#define _PROCESSING_INTERFACE_H_

#include <list>

#include "ConcurrentQueue.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class IProcessingInterface
{
public:
	/*
	 * @brief	default constructor
	*/
	//IProcessingInterface();
	
	/*
	 * @brief	default destructor
	*/
	//~IProcessingInterface();

	virtual std::string inline Name() { return "ProcessInterface"; }

private:

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