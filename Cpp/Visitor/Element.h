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
#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <stdio.h>
#include <string>

#include "Visitor.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

class IVisitor;

/*
 * @class	
 * @brief	
*/
class IElement
{
public:
	virtual void Accept(IVisitor *pVisitor) = 0;
	virtual std::string Name() = 0;

protected:
	std::string m_strName;
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