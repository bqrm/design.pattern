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
#ifndef __CONCRETE_AGGREGATE_H__	
#define __CONCRETE_AGGREGATE_H__	

#include <vector>

#include "AbstractAggregate.h"
#include "ConcreteIterator.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CConcreteAggregate : public IAbstractAggregate
{
public:
	CConcreteAggregate()
	{
		m_vecItems.clear();
		m_pIterator = nullptr;
	}
	~CConcreteAggregate()
	{
		if (nullptr != m_pIterator)
		{
			delete m_pIterator;
			m_pIterator = nullptr;
		}
	}

	IAbstractIterator* CreateIterator()
	{
		if (nullptr == m_pIterator)
		{
			m_pIterator = new CConcreteIterator(this);
		}
		return m_pIterator;
	}

	unsigned int Count()
	{
		return m_vecItems.size();
	}
	void Push(const std::string& strValue)
	{
		m_vecItems.push_back(strValue);
	}
	std::string Pop(const unsigned int nIdx)
	{
		if (nIdx < m_vecItems.size())
		{
			//std::string strRet = m_vecItems[nIdx];
			//m_vecItems.erase(find(m_vecItems.begin(), m_vecItems.end(), strRet));
			return m_vecItems[nIdx];
		}
		return "";
	}

private:
	std::vector<std::string> m_vecItems;
	IAbstractIterator *m_pIterator;
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