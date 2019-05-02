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
#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

#include "Mediator.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

class IMediator;

/*
 * @class	
 * @brief	
*/
class IPerson
{
public:
	virtual void SendMessage(std::string strName, std::string strMsg) = 0;
	virtual void RecvMessage(std::string strName, std::string strMsg) = 0;

protected:
	IMediator *m_pMediator;
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