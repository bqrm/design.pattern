/***************************************************
 * @file		
 * @section		
 * @class		
 * @brief		
 * @author		bqrmtao@gmail.com
 * @date		
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

/* __DEF_MACRO_H__ */
#ifndef __STATE_H__
#define __STATE_H__

#include <stdio.h>

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class IState
{
public:
	virtual void Board() = 0;
	virtual void Deplane() = 0;
	virtual void TakeOff() = 0;
	virtual void Land() = 0;
	virtual void Climb() = 0;
	virtual void Descend() = 0;
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

#endif	// 