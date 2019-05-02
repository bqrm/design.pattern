/*********************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <stdio.h>

enum WeaponType
{
	Gun,
	Knife
};

class IWeapon
{
public:
	IWeapon(bool bIsLeftHanded)
	{
		m_bIsLeftHanded = bIsLeftHanded;
	}
	virtual ~IWeapon() {}

	void virtual UseWeapon(const unsigned short usTryTime) = 0;

protected:
	bool m_bIsLeftHanded;
};

#endif