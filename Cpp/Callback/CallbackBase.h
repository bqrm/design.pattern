/***************************************************
 * @file		CallbackBase.h
 * @section		
 * @class		ICallback
 * @brief		interface of callback
 * @author		bqrmtao@gmail.com
 * @date		2018/07/12
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef __CALLBACK_BASE_H__
#define __CALLBACK_BASE_H__

#include <stdio.h>

struct CallbackParam
{
	float fOprd1;
	float fOprd2;
};

/*
 * @class	ICallback
 * @brief	interface of callback
*/
class ICallback
{
public:
	/*
	 * @brief	main method of callback, should be overridden in derived class
	 * @param	unEventID
	 * @param	pEventParam (CallbackParam*)
	 * @return	void
	*/
	virtual void ProcessCallback(unsigned int unEventID, CallbackParam *pEventParam) = 0;
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

#endif	// __CALLBACK_BASE_H__