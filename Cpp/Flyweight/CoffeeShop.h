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
#ifndef __COFFEE_SHOP_H__
#define __COFFEE_SHOP_H__

#include <map>

#include "Flavor.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CCoffeeShop
{
public:
	CCoffeeShop() { m_setOrder.clear(); }
	~CCoffeeShop()
	{
		for (auto iter : m_setOrder)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		m_setOrder.clear();
	}

	COrder* TakeOrder(std::string strFlavor)
	{
		if (m_setOrder.find(strFlavor) == m_setOrder.end())
		{
			m_setOrder.insert(std::make_pair(strFlavor, new CFlavor(strFlavor)));
		}

		return m_setOrder[strFlavor];
	}

private:
	std::map<std::string, COrder*> m_setOrder;
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