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
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "Administrator.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CManager : public IAdministrator
{
public:
	CManager()
	{
		m_pSuperiorPtr = nullptr;
	}
	~CManager()
	{
		m_pSuperiorPtr = nullptr;
	}

	void SanctionVacation(int nDays)
	{
		if (nDays <= 3)
		{
			printf("manager sanction %d day(s) vacation\n", nDays);
		}
		else
		{
			printf("%d days vacation is beyond manager's pay grade, ask for majordomo's approval\n", nDays);
			m_pSuperiorPtr->SanctionVacation(nDays);
		}
	}

	void SetSuperior(IAdministrator *pSuperiorPtr)
	{
		m_pSuperiorPtr = pSuperiorPtr;
	}
};

/*
 * @brief		
 * @param		
 * @exception	
 * @warning		
 * @pre			
 * @post		
 * @since		
 * @todo		
 * @bug			
 * @return		
 * @ref			
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