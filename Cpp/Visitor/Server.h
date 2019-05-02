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
#ifndef __SERVER_H__
#define __SERVER_H__

#include <map>

#include "Blog.h"
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
class CServer
{
public:
	CServer()
	{
		InitBlogs();
	}
	~CServer()
	{
		RemoveBlogs();
	}

	void Accept(IVisitor *pVisitor)
	{
		for (auto iterElement : m_mapBlogs)
		{
			iterElement.second->Accept(pVisitor);
		}
	}

private:
	void InitBlogs()
	{
		m_mapBlogs.insert(std::make_pair("art", new CBlog("art")));
		m_mapBlogs.insert(std::make_pair("physics", new CBlog("physics")));
		m_mapBlogs.insert(std::make_pair("mathematics", new CBlog("mathematics")));
	}
	void RemoveBlogs()
	{
		for (auto iterElement : m_mapBlogs)
		{
			delete iterElement.second;
		}

		m_mapBlogs.clear();
	}

	std::map<std::string, IElement*> m_mapBlogs;
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