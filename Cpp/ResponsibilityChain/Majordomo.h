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
#ifndef __MAJORDOMO_H__
#define __MAJORDOMO_H__

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
class CMajordomo : public IAdministrator
{
public:
	CMajordomo()
	{
		m_pSuperiorPtr = nullptr;
	}
	~CMajordomo()
	{
		m_pSuperiorPtr = nullptr;
	}

	void SanctionVacation(int nDays)
	{
		if (nDays <= 10)
		{
			printf("%d days vacation approved\n", nDays);
		}
		else
		{
			printf("%d days vacation denied\n", nDays);
		}
	}

	void SetSuperior(IAdministrator *pSuperiorPtr) {}
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