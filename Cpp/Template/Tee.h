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
#ifndef _TEE_H__
#define _TEE_H__

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
class CTee : public CBeverage
{
public:
	CTee(bool bIsAddingCondiment = true) { m_bIsAddingCondiment = bIsAddingCondiment; }
	~CTee() {}

private:
	void AddCondiment()
	{
		printf("add lemon\n");
	}
	void Brew()
	{
		printf("brew tea leaves with water\n");
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

#endif	// 