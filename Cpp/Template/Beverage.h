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
#ifndef __BEVERAGE_H__
#define __BEVERAGE_H__

#include <stdio.h>

class CBeverage
{
public:
	CBeverage()	{ m_bIsAddingCondiment = false; }
	~CBeverage() {}

	void PrepareRecipe()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddCondiment();
	}

protected:
	void BoilWater()
	{
		printf("boil the water\n");
	}
	void PourInCup()
	{
		printf("pour water into cup\n");
	}
	
	virtual void AddCondiment() = 0;
	virtual void Brew() = 0;

	bool m_bIsAddingCondiment;
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

#endif	// __BEVERAGE_H__