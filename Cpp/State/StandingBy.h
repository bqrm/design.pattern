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
#ifndef __STANDING_BY_H__
#define __STANDING_BY_H__

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
class CStandingBy : public IState
{
public:
	CStandingBy() {}
	~CStandingBy() {}

	void Board()
	{
		printf("passengers getting board\n");
	}
	void Deplane()
	{
		printf("passengers getting off the plane\n");
	}
	void TakeOff()
	{
		printf("prepare to take off\n");
	}
	void Land()
	{
		printf("the plane has already been on the land\n");
	}
	void Climb()
	{
		printf("unable to climb, the plane is on the land\n");
	}
	void Descend()
	{
		printf("unable to descend, the plane is on the land\n");
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