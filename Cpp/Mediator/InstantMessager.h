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
#ifndef __INSTANT_MESSAGE_H__
#define __INSTANT_MESSAGE_H__

#include "Mediator.h"
#include "Monitor.h"
#include "Jerry.h"
#include "Tom.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CInstantMessager : public IMediator
{
public:
	CInstantMessager() {}
	~CInstantMessager() {}

	void AddClassmate(std::string strName, IPerson *pClassmate)
	{
		if (m_mapRoster.find(strName) == m_mapRoster.end())
		{
			m_mapRoster.insert(std::make_pair(strName, pClassmate));
		}
	}

	void DeliverMessage(std::string strFromName, std::string strToName, std::string strMsg)
	{
		if (strToName == "All")
		{
			for (auto mapIter = m_mapRoster.begin(); mapIter != m_mapRoster.end(); mapIter++)
			{
				((*mapIter).second)->RecvMessage(strFromName, strMsg);
			}
		}
		else
		{
			m_mapRoster[strToName]->RecvMessage(strFromName, strMsg);
		}
	}
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