/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Department.h"

class CEmployee : public IDepartment
{
public:
	CEmployee() {}
	~CEmployee() {}

	virtual void JobDescription()
	{
		printf("CEmployee::JobDescription.\n");
	}
};

#endif