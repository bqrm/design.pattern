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

#ifndef __SON_H__
#define __SON_H__

#include "Child.h"

class CSon : public IChild
{
public:
	CSon() {}
	~CSon() {}

	void Attach(IGuardian* pGuardian)
	{
		if (m_setGuardians.find(pGuardian) == m_setGuardians.end())
		{
			m_setGuardians.insert(pGuardian);
		}
	}

	void Detach(IGuardian* pGuardian)
	{
		if (m_setGuardians.find(pGuardian) != m_setGuardians.end())
		{
			m_setGuardians.erase(pGuardian);
		}
	}

	std::string GetState()
	{
		return m_strState;
	}

	std::string Name(){ return "Tom"; }

	void NotifyGuardians()
	{
		for (auto iter = m_setGuardians.begin(); iter != m_setGuardians.end(); iter++)
		{
			(*iter)->Update((IChild*)this);
		}
	}

	void SetState(std::string strState)
	{
		m_strState = strState;
	}
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

#endif
