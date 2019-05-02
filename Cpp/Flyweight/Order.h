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
#ifndef __ORDER_H__
#define __ORDER_H__

#include <stdio.h>
#include <string>

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class COrder
{
public:
	COrder() {}
	virtual ~COrder() {}

	void Serve(int nTable)
	{
		printf("Serve table %d a cup of %s\n", nTable, GetFlavor().c_str());
	}

	virtual std::string GetFlavor() = 0;

protected:
	std::string m_strFlavor;
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