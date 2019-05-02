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
#ifndef __ABSTRACT_ITERATOR_H__
#define __ABSTRACT_ITERATOR_H__

#include <string>

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class IAbstractIterator
{
public:
	virtual std::string First() = 0;
	virtual std::string Next() = 0;
	virtual std::string	Current() = 0;	
	virtual bool IsEnd() = 0;
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