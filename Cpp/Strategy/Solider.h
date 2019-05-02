/*********************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CHARACTOR_H__
#define __CHARACTOR_H__

#include "Knife.h"
#include "Gun.h"

class CSolider
{
public:
	CSolider(WeaponType eWeapon, bool bIsLeftHanded)
	{
		switch (eWeapon)
		{
		case Gun:
			m_pWeapon = new CGun(bIsLeftHanded, 10);
			break;
		case Knife:
			m_pWeapon = new CKnife(bIsLeftHanded);
			break;
		default:
			printf("this branch should never be hit\n");
			m_pWeapon = nullptr;
			break;
		}
	}
	~CSolider()
	{
		if (nullptr != m_pWeapon)
		{
			delete m_pWeapon;
			m_pWeapon = nullptr;
		}
	}

	void Fight(unsigned short usTimes)
	{
		if (nullptr == m_pWeapon)
		{
			printf("no weapon loaded\n");
		}
		else
		{
			m_pWeapon->UseWeapon(usTimes);
		}
	}
	
protected:
	IWeapon *m_pWeapon;
};

#endif