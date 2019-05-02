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
#ifndef __CONCRETE_ITERATOR_H__
#define __CONCRETE_ITERATOR_H__

#include "AbstractAggregate.h"
#include "AbstractIterator.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CConcreteIterator : public IAbstractIterator
{
public:
	CConcreteIterator(IAbstractAggregate *pAggregate)
	{
		m_unCurrentIdx = 0;
		m_pAggregate = pAggregate;
	}
	~CConcreteIterator();

	std::string First()
	{
		//m_unCurrentIdx = 0;
		return m_pAggregate->Pop(m_unCurrentIdx);
	}
	std::string Current()
	{
		return m_pAggregate->Pop(m_unCurrentIdx);
	}
	std::string Next()
	{
		if (m_unCurrentIdx++ < m_pAggregate->Count())
		{
			return m_pAggregate->Pop(m_unCurrentIdx);
		}

		return "";
	}
	bool IsEnd()
	{
		return m_unCurrentIdx >= m_pAggregate->Count() ? true : false;
	}

private:
	unsigned int m_unCurrentIdx;

	IAbstractAggregate *m_pAggregate;
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