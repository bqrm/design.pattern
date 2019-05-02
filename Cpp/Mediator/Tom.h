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
#ifndef __TOM_H__
#define __TOM_H__

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
class CTom : public IPerson
{
public:
	CTom(IMediator *pMediator)
	{
		m_pMediator = pMediator;
	}
	~CTom()
	{
		m_pMediator = nullptr;
	}

	void SendMessage(std::string strName, std::string strMsg)
	{
		printf("Tom send message \"%s\" to %s\n", strMsg.c_str(), strName.c_str());
		m_pMediator->DeliverMessage("Tom", strName, strMsg);
	}

	void RecvMessage(std::string strName, std::string strMsg)
	{
		printf("Tom gets message \"%s\" from %s\n", strMsg.c_str(), strName.c_str());
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