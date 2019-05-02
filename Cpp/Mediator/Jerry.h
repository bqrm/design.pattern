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
#ifndef __JERRY_H__
#define __JERRY_H__

#include "Person.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CJerry : public IPerson
{
public:
	CJerry(IMediator *pMediator)
	{
		m_pMediator = pMediator;
	}
	~CJerry()
	{
		m_pMediator = nullptr;
	}

	void SendMessage(std::string strName, std::string strMsg)
	{
		printf("Jerry send message \"%s\" to %s\n", strMsg.c_str(), strName.c_str());
		m_pMediator->DeliverMessage("Jerry", strName, strMsg);
	}

	void RecvMessage(std::string strName, std::string strMsg)
	{
		printf("Jerry gets message \"%s\" from %s\n", strMsg.c_str(), strName.c_str());
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