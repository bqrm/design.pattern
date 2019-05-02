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
#ifndef __CASH_NORMAL_H__
#define __CASH_NORMAL_H__

#include "CashSuper.h"

/*
 * @class	
 * @brief	
*/
class CCashNormal : public ICashSuper
{
public:
	CCashNormal() {}
	~CCashNormal() {}

	double AcceptCash()
	{
		return 0;
	}
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

#endif	// __CASH_NORMAL_H__
