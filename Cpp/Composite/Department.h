/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__

#include <stdio.h>

class IDepartment
{
public:
	// pure virtual function, all inherited nodes should implement this function
	virtual void JobDescription() = 0;

	//virtual function, leaf nodes does not override these functions
	virtual void AddSubGroup(IDepartment*) {}
	virtual void RemoveSubGroup(IDepartment*) {}
	virtual IDepartment* GetSubGroup(int nChildIdx) { return nullptr; }
};

#endif