/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CHILD_H__
#define __CHILD_H__

#include <stdio.h>
#include <string>
#include <set>

#include "Guardian.h"

/* important */
class IGuardian;

class IChild
{
public:
	virtual void Attach(IGuardian* pGuardian) = 0;
	virtual void Detach(IGuardian* pGuardian) = 0;
	virtual std::string GetState() = 0;
	virtual std::string Name() = 0;
	virtual void NotifyGuardians() = 0;
	virtual void SetState(std::string strState) = 0;

protected:
	std::set<IGuardian*> m_setGuardians;
	std::string m_strState;
};

#endif