/*********************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef _KNIFE_H_
#define _KNIFE_H_

#include "Weapon.h"

class CKnife : public IWeapon
{
public:
	CKnife(bool bIsLeftHanded) : IWeapon(bIsLeftHanded) {}
	~CKnife() {}
	
	void UseWeapon(unsigned short usTryTime)
	{
		if (m_bIsLeftHanded)
		{
			printf("use knife for %u times with left hand.\n", usTryTime);
		}
		else
		{
			printf("use knife for %u times with right hand.\n", usTryTime);
		}
	}
};

#endif