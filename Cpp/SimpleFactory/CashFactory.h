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
#ifndef __CASH_FACTORY_H__
#define __CASH_FACTORY_H__

#include "CashNormal.h"
#include "CashRebate.h"
#include "CashReturn.h"

/*
 * @class	
 * @brief	
*/
class CCashFactory
{
public:
	CCashFactory() {}
	~CCashFactory() {}

	ICashSuper* CreateCashAccept(CashAcceptMethod eAcceptMethod)
	{
		switch (eAcceptMethod)
		{
		case Normal:
			return new CCashNormal();
		case Rebate:
			return new CCashRebate();
		case Return:
			return new CCashReturn();
		default:
			printf("this branch should never be hit!\n");
			return nullptr;
		}
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

#endif
