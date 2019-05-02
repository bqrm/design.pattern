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
#ifndef __VISITOR_H__
#define __VISITOR_H__

#include <stdio.h>

#include "Element.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

class IElement;

/*
 * @class	
 * @brief	
*/
class IVisitor
{
public:
	virtual void ViewBlog(IElement *pElement) = 0;
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