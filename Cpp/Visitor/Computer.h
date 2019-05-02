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
#ifndef __COMPUTER_H__
#define __COMPUTER_H__

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
class CComputer : public IVisitor
{
public:
	CComputer() {}
	~CComputer() {}

	void ViewBlog(IElement *pElement)
	{
		printf("view %s on computer\n", pElement->Name().c_str());
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