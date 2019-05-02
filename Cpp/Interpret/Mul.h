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
#ifndef __MUL_H__
#define __MUL_H__

#include "Formula.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CMul : public IFormula
{
public:
	CMul(IFormula *pExp1, IFormula *pExp2)
	{
		m_pExp1 = pExp1;
		m_pExp2 = pExp2;
	}
	~CMul()
	{
		m_pExp1 = nullptr;
		m_pExp2 = nullptr;
	}

	double Calculate()
	{
		return m_pExp1->Calculate() * m_pExp2->Calculate();
	}

private:
	IFormula *m_pExp1;
	IFormula *m_pExp2;
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