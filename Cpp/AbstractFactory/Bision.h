/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __BISION_H__
#define __BISION_H__

#include "Herbivore.h"

class CBision : public IHerbivore
{
public:
	CBision() {}
	~CBision() {}

	std::string Name()
	{
		return "Bison";
	}
};

#endif