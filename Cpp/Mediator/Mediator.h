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
#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

#include <map>
#include <string>

#include "Person.h"

class IPerson;

/*
 * @class	
 * @brief	
*/
class IMediator
{
public:
	virtual void AddClassmate(std::string strName, IPerson *pClassmate) = 0;
	virtual void DeliverMessage(std::string strFromName, std::string strToName, std::string strMsg) = 0;

protected:
	std::map<std::string, IPerson*> m_mapRoster;
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