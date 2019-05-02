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
#ifndef __CASH_SUPER_H__
#define __CASH_SUPER_H__

#include <stdio.h>

/* enum */
enum CashAcceptMethod
{
	Normal,   ///< 
	Rebate,
	Return
};

/*
 * @class	
 * @brief	
*/
class ICashSuper
{
public:
	virtual double AcceptCash() = 0;
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

#endif	// __CASH_SUPER_H__
