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
#ifndef __CELLPHONE_H__
#define __CELLPHONE_H__

#include "Visitor.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CCellphone : public IVisitor
{
public:
	CCellphone() {}
	~CCellphone() {}

	void ViewBlog(IElement *pElement)
	{
		printf("view %s on cellphone\n", pElement->Name().c_str());
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

#endif	// 