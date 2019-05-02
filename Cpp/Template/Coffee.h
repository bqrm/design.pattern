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
#ifndef __COFFEE_H__
#define __COFFEE_H__

#include "Beverage.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CCoffee : public CBeverage
{
public:
	CCoffee(bool bIsAddingCondiment = true) { m_bIsAddingCondiment = bIsAddingCondiment; }
	~CCoffee() {}

private:
	void AddCondiment()
	{
		printf("add milk and sugar\n");
	}
	void Brew()
	{
		printf("brew coffee pounder with water\n");
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

#endif	// __COFFEE_H__