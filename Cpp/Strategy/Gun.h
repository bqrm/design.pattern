/*********************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __GUNS_H__
#define __GUNS_H__

#include "Weapon.h"

class CGun : public IWeapon
{
public:
	CGun(bool bIsLeftHanded, unsigned short usInitClips) : IWeapon(bIsLeftHanded)
	{
		m_usNumClip = usInitClips;

		m_unBulletInClip = 0;

		m_bIsLeftHanded = false;

		Reload();
	}
	~CGun() {}

	// override the virtual function in base class.
	void UseWeapon(unsigned short usBulletsShot)
	{
		m_usShootRemain = usBulletsShot;

		while (m_usShootRemain > 0)
		{
			if (m_unBulletInClip > m_usShootRemain)
			{
				if (m_bIsLeftHanded)
				{
					printf("shoot %u times with left hand.\n", m_usShootRemain);
				}
				else
				{
					printf("shoot %u times with right hand.\n", m_usShootRemain);
				}

				m_unBulletInClip -= m_usShootRemain;
				m_usShootRemain = 0;
			}
			else
			{
				if (m_bIsLeftHanded)
				{
					printf("shoot %u times with left hand.\n", m_unBulletInClip);
				}
				else
				{
					printf("shoot %u times with right hand.\n", m_unBulletInClip);
				}

				m_usShootRemain -= m_unBulletInClip;

				if (!Reload())
				{
					return;
				}
			}
		}
	}

private:
	bool Reload()
	{
		if (m_usNumClip > 0)
		{
			printf("bullets reload.\n");
			m_unBulletInClip = 20;
			m_usNumClip--;

			return true;
		}
		else
		{
			printf("out of ammunition\n");
			return false;
		}
	}

	unsigned short m_unBulletInClip;
	unsigned short m_usNumClip;
	unsigned short m_usShootRemain;
};

#endif