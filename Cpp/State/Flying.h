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
#ifndef __FLYING_H__
#define __FLYING_H__

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
class CFlying : public IState
{
public:
	CFlying() {}
	~CFlying() {}

	void Board()
	{
		printf("unable to get on board\n");
	}
	void Deplane()
	{
		printf("unable to get off the plane\n");
	}
	void TakeOff()
	{
		printf("the plane is in the air\n");
	}
	void Land()
	{
		printf("landing\n");
	}
	void Climb()
	{
		printf("climbing\n");
	}
	void Descend()
	{
		printf("descend\n");
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

#endif	// 