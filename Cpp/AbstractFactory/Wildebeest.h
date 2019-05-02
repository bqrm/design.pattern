/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __WILDEBEEST_H__
#define __WILDEBEEST_H__

#include "Herbivore.h"

class CWildebeest : public IHerbivore
{
public:
	CWildebeest() {}
	~CWildebeest() {}

	std::string Name()
	{
		return "WildeBeest";
	}
};

#endif