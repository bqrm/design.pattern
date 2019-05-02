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
#ifndef __BLOG_H__
#define __BLOG_H__

#include "Element.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CBlog : public IElement
{
public:
	CBlog(std::string strName)
	{
		m_strName = strName;
	}
	~CBlog() {}

	void Accept(IVisitor *pVisitor)
	{
		pVisitor->ViewBlog(this);
	}

	std::string Name()
	{
		return m_strName;
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