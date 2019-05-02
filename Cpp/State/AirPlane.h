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
#ifndef __AIR_PLANE_H__
#define __AIR_PLANE_H__

#include "State.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

/*
 * @class	
 * @brief	
*/
class CAirPlane
{
public:
	CAirPlane()
	{
		m_pState = nullptr;
	}
	~CAirPlane()
	{
		m_pState = nullptr;
	}

	void SetState(IState *pState)
	{
		m_pState = pState;
	}
	void Board()
	{
		if (nullptr != m_pState)
		{
			m_pState->Board();
		}
	}
	void Deplane()
	{
		if (nullptr != m_pState)
		{
			m_pState->Deplane();
		}
	}
	void TakeOff()
	{
		if (nullptr != m_pState)
		{
			m_pState->TakeOff();
		}
	}
	void Land()
	{
		if (nullptr != m_pState)
		{
			m_pState->Land();
		}
	}
	void Climb()
	{
		if (nullptr != m_pState)
		{
			m_pState->Climb();
		}
	}
	void Descend()
	{
		if (nullptr != m_pState)
		{
			m_pState->Descend();
		}
	}

private:
	IState *m_pState;
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

#endif	// 