/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <stdio.h>

class CCamera
{
public:
	CCamera() {}
	~CCamera() {}

	void TurnOn()
	{
		printf("Camera on.\n");
	}

	void TurnOff()
	{
		printf("Camera off.\n");
	}

	void Rotate(int nDegree)
	{
		printf("Rotate the camera by %d degree.\n", nDegree);
	}
};

#endif