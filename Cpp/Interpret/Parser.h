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
#ifndef __PARSER_H__
#define __PARSER_H__

#include <list>
#include <string>

#include "Add.h"
#include "Mul.h"
#include "Sub.h"
#include "Value.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CParser
{
public:
	CParser() {}
	~CParser() {}

	IFormula* ParseNext(std::list<std::string>& listFormulaElement)
	{
		try
		{
			m_dValue = stof(listFormulaElement.front(), nullptr);
			listFormulaElement.pop_front();
			return new CValue(m_dValue);
		}
		catch (...)
		{
			return ParseSymbol(listFormulaElement);
		}
	}

	IFormula* ParseSymbol(std::list<std::string>& listFormulaElement)
	{
		std::string strSymbol = listFormulaElement.front();
		listFormulaElement.pop_front();

		IFormula *pVal1 = ParseNext(listFormulaElement);
		IFormula *pVal2 = ParseNext(listFormulaElement);

		switch (strSymbol[0])
		{
		case '+':
			return new CAdd(pVal1, pVal2);
		case '-':
			return new CSub(pVal1, pVal2);
		case '*':
			return new CMul(pVal1, pVal2);
		default:
			return nullptr;
		}
	}

private:
	double m_dValue;
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