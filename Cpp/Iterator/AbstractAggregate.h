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
#ifndef __ABSTRACT_AGGREGATE_H__
#define __ABSTRACT_AGGREGATE_H__

#include "AbstractIterator.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class IAbstractAggregate
{
public:
	virtual unsigned int Count() = 0;
	virtual void Push(const std::string& strValue) = 0;
	virtual std::string Pop(const unsigned int nIdx) = 0;
	virtual IAbstractIterator* CreateIterator() = 0;
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