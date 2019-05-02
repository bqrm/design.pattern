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
#ifndef __ADMINISTRATOR_H__
#define __ADMINISTRATOR_H__

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
class IAdministrator
{
public:
	virtual void SanctionVacation(int nDays) = 0;
	virtual void SetSuperior(IAdministrator *pSuperiorPtr) = 0;

protected:
	IAdministrator *m_pSuperiorPtr;
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